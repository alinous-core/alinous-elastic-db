/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_HASHMAPKEYSET_H_
#define BASELIB_HASHMAPKEYSET_H_

namespace alinous {
class ThreadContext;
}

namespace java { namespace util {
template <typename T>
class Set;




template <typename T, typename V>
class HashMapKeySet final : public Set<T> {
public:

	HashMapKeySet() throw() : IObject(nullptr), Set<T>(nullptr) {
		this->list = new HashMapRawArray<T, V>();
		this->nullElement = nullptr;
	}

	HashMapKeySet(ThreadContext* ctx) throw() : IObject(ctx), Set<T>(ctx) {
		this->list = new(ctx) HashMapRawArray<T, V>();
		this->nullElement = nullptr;
	}

	virtual ~HashMapKeySet() throw() {
		ThreadContext* ctx = ThreadContext::getCurentContext();

		if(ctx != nullptr){ctx->incGcDenial();}
		__releaseRegerences(false, ctx);
		if(ctx != nullptr){ctx->decGcDenial();}
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(this->list != nullptr){
			clear(ctx);
			delete this->list;

			this->list = nullptr;
		}
		if(this->nullElement != nullptr){
			__GC_DEC(this, this->nullElement->value, V);
			delete this->nullElement;
			this->nullElement = nullptr;
		}
	}

	virtual void add(T* e, ThreadContext* ctx) throw() {
		if(e == nullptr){
			this->nullElement = new(ctx) HashMapInternalElement<T, V>(nullptr, nullptr);
			return;
		}

		HashMapInternalElement<T, V> tmp(e, nullptr);
		HashMapInternalElement<T,V>* obj = this->list->search(&tmp);
		if(obj != nullptr){
			__GC_DEC(this, obj->value, V);

			obj->value = nullptr;

			return;
		}

		HashMapInternalElement<T, V>* element = new(ctx) HashMapInternalElement<T, V>(e, nullptr);
		__GC_INS(this, e, T);

		this->list->addElement(element);
	}

	void addElement(const HashMapInternalElement<T, V>* e, ThreadContext* ctx) throw() {
		if(e->key == nullptr){
			if(this->nullElement != nullptr){
				__GC_DEC(this, this->nullElement->value, V);
				__GC_INS(this, e->value, V);

				this->nullElement->value = e->value;
				return;
			}

			this->nullElement = new(ctx) HashMapInternalElement<T,V>(e->key, e->value);
			__GC_INS(this, e->value, V);

			return;
		}


		HashMapInternalElement<T,V>* obj = this->list->search(e);

		if(obj != nullptr){
			__GC_DEC(this, obj->value, V);
			__GC_INS(this, e->value, V);

			obj->value = e->value;

			return;
		}
		if(ctx != nullptr){
			obj = new(ctx) HashMapInternalElement<T,V>(e->key, e->value);
		}else{
			obj = new HashMapInternalElement<T,V>(e->key, e->value);
		}
		__GC_INS(this, e->key, T);
		__GC_INS(this, e->value, V);
		this->list->addElement(obj);
	}

	V* getValue(T* key, ThreadContext* ctx) throw() {
		if(key == nullptr){
			V* val = this->nullElement == nullptr ? nullptr : this->nullElement->value;
			return val;
		}

		HashMapInternalElement<T,V> tmp(key, nullptr);
		HashMapInternalElement<T,V>* obj = this->list->search(&tmp);
		if(obj == nullptr){
			return nullptr;
		}

		return obj->value;
	}

	virtual void clear(ThreadContext* ctx) throw() {
		if(this->nullElement != nullptr){
			__GC_DEC(this, this->nullElement->value, V);
			delete this->nullElement;
			this->nullElement = nullptr;
		}

		auto it = this->list->iterator();
		while(it.hasNext()){
			HashMapInternalElement<T,V>* obj = it.next();

			if(ctx != nullptr){
				__GC_DEC(this, obj->key, T);
				__GC_DEC(this, obj->value, V);
			}

			delete obj;
		}

		this->list->reset();
	}


	class HashMapKeySetIterator : public Iterator<T> {
	public:
		HashMapKeySetIterator(HashMapRawArray<T, V>* list, HashMapInternalElement<T, V>* nullelement, ThreadContext* ctx)throw() : IObject(ctx), Iterator<T>(ctx),
			internalIt(list->iterator()), outputNull(false), nullElement(nullelement)
		{
		}
		virtual ~HashMapKeySetIterator() throw() {
			ThreadContext* ctx = ThreadContext::getCurentContext();

			if(ctx != nullptr){ctx->incGcDenial();}
			__releaseRegerences(false, ctx);
			if(ctx != nullptr){ctx->decGcDenial();}
		}

		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		}

		virtual bool hasNext(ThreadContext* ctx) throw() {
			if(this->outputNull == false && this->nullElement != nullptr){
				return true;
			}
			return this->internalIt.hasNext();
		}
		virtual T* next(ThreadContext* ctx) throw() {
			if(this->outputNull == false){
				this->outputNull = true;

				if(this->nullElement != nullptr){
					return this->nullElement->key;
				}
			}

			HashMapInternalElement<T, V>* obj = this->internalIt.next();
			if(obj == nullptr){
				return nullptr;
			}
			return obj->key;
		}
		virtual void remove(ThreadContext* ctx) throw() {

		}

	private:
		typename HashMapRawArray<T, V>::Iterator internalIt;
		bool outputNull;
		HashMapInternalElement<T, V>* nullElement;
	};


	virtual Iterator<T>* iterator(ThreadContext* ctx) throw() {
		HashMapKeySetIterator* iterator = new(ctx) HashMapKeySetIterator(this->list, this->nullElement, ctx);

		return iterator;
	}

	virtual void remove(T* o, ThreadContext* ctx) throw() {
		if(o == nullptr){
			if(this->nullElement != nullptr){
				__GC_DEC(this, this->nullElement->value, V);
				delete this->nullElement;
				this->nullElement = nullptr;
			}

			return;
		}


		HashMapInternalElement<T,V> tmp(o, nullptr);
		HashMapInternalElement<T,V>* removObj = this->list->search(&tmp);

		this->list->removeByObj(removObj);

		__GC_DEC(this, removObj->key, T);
		__GC_DEC(this, removObj->value, V);

		delete removObj;

		return;
	}

	bool containsKey(T* key, ThreadContext* ctx) throw() {
		if(key == nullptr){
			if(this->nullElement != nullptr){
				return true;
			}else{
				return false;
			}
		}

		HashMapInternalElement<T,V> tmp(key, nullptr);
		HashMapInternalElement<T,V>* obj = this->list->search(&tmp);

		return obj != nullptr;
	}

	bool containsValue(V* value, ThreadContext* ctx) throw() {
		auto it = this->list->iterator();
		while(it.hasNext()){
			HashMapInternalElement<T,V>* obj = it.next();
			if((value != nullptr && obj->value != nullptr && obj->value->equals(value, ctx)) ||
					(value == nullptr && obj->value == nullptr)){
				return true;
			}
		}

		if(this->nullElement != nullptr){
			if((value != nullptr && this->nullElement->value != nullptr && this->nullElement->value->equals(value, ctx)) ||
					(value == nullptr && this->nullElement->value == nullptr)){
				return true;
			}
		}

		return false;
	}

	virtual int size(ThreadContext* ctx) throw() {
		int count = this->nullElement == nullptr ? this->list->size() : this->list->size() + 1;
		return count;
	}

	virtual bool isEmpty(ThreadContext* ctx) throw() {
		return this->list->isEmpty() && this->nullElement == nullptr;
	}

	virtual bool equals(Set<T>* o, ThreadContext* ctx) throw() {
		return IObject::equals(o, ctx);
	}

	HashMapRawArray<T, V>* list;
	HashMapInternalElement<T, V>* nullElement;
};

}} /* namespace alinous */

#endif /* BASELIB_HASHMAPKEYSET_H_ */
