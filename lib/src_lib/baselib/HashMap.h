/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_HASHMAP_H_
#define BASELIB_HASHMAP_H_


namespace alinous {
template <typename T, typename C> class RawArray;
class ThreadContext;
}

namespace java { namespace lang{
class IObject;
}}


namespace java { namespace util {

using namespace alinous;
using namespace java::lang;

template <typename T> class Set;
template <typename T, typename V> class HashMapKeySet;

template <typename T, typename V>
class Map : public virtual IObject {
public:
	Map(ThreadContext* ctx): IObject(ctx) {
	}
	virtual ~Map(){}
	virtual void put(T* key, V* value, ThreadContext* ctx) = 0;
	virtual V* get(T* key, ThreadContext* ctx) = 0;
	virtual Set<T>* keySet(ThreadContext* ctx) = 0;
	virtual bool containsKey(T* key, ThreadContext* ctx) = 0;
	virtual bool containsValue(V* value, ThreadContext* ctx) = 0;
	virtual void clear(ThreadContext* ctx) = 0;

	virtual int size(ThreadContext* ctx) = 0;
	virtual void remove(T* key, ThreadContext* ctx) = 0;
	virtual bool isEmpty(ThreadContext* ctx) = 0;

	static void __cleanUp(ThreadContext* ctx){
	}
};


template <typename T, typename V>
class HashMap : public Map<T, V> {
public:
	// for static map
	HashMap() throw() : IObject(nullptr), Map<T, V>(nullptr) {
		hashMapKeySet = new HashMapKeySet<T, V>();
	}
	HashMap(ThreadContext* ctx) throw() : IObject(ctx), Map<T, V>(ctx) {
		hashMapKeySet = new(ctx) HashMapKeySet<T, V>(ctx);

		GCUtils<HashMapKeySet<T, V> >::ins(this, hashMapKeySet, ctx, __FILEW__, __LINE__, GC_CLS_STR((HashMapKeySet<T, V>)));

	}
	HashMap(int cap, ThreadContext* ctx) throw() : IObject(ctx), Map<T, V>(ctx) {
		if(ctx != nullptr){
			hashMapKeySet = new(ctx) HashMapKeySet<T, V>(ctx);
			GCUtils<HashMapKeySet<T, V> >::ins(this, hashMapKeySet, ctx, __FILEW__, __LINE__, GC_CLS_STR((HashMapKeySet<T, V>)));
		}
		else{
			hashMapKeySet = new(ctx) HashMapKeySet<T, V>(ctx);
		}
	}
	virtual ~HashMap() throw() {
		ThreadContext* ctx = ThreadContext::getCurentContext();
		if(ctx != nullptr){ctx->incGcDenial();}
		__releaseRegerences(false, ctx);
		if(ctx != nullptr){ctx->decGcDenial();}
	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(this->hashMapKeySet != nullptr && ctx != nullptr){
			GCUtils<HashMapKeySet<T, V> >::dec(this, hashMapKeySet, ctx, __FILEW__, __LINE__, GC_CLS_STR((HashMapKeySet<T, V>)));
			this->hashMapKeySet = nullptr;
		}
		if(this->hashMapKeySet != nullptr && ctx == nullptr){
			delete this->hashMapKeySet;
		}
	}
	void put(T* key, V* value, ThreadContext* ctx) throw() final  {
		HashMapInternalElement<T, V> newValue(key, value);
		this->hashMapKeySet->addElement(&newValue, ctx);
	}
	V* get(T* key, ThreadContext* ctx) throw() final{
		return __GC_RT(this->hashMapKeySet->getValue(key, ctx), V);
	}
	Set<T>* keySet(ThreadContext* ctx) throw() final {
		return __GC_RT(hashMapKeySet, Set<T>);
	}
	bool containsKey(T* key, ThreadContext* ctx) throw() final{
		return this->hashMapKeySet->containsKey(key, ctx);
	}
	bool containsValue(V* value, ThreadContext* ctx) throw() final {
		return this->hashMapKeySet->containsValue(value, ctx);
	}
	void clear(ThreadContext* ctx) throw() final{
		this->hashMapKeySet->clear(ctx);
	}

	int size(ThreadContext* ctx) {
		return this->hashMapKeySet->size(ctx);
	}
	bool isEmpty(ThreadContext* ctx){
		return this->hashMapKeySet->size(ctx) == 0;
	}

	virtual void remove(T* key, ThreadContext* ctx) {
		this->hashMapKeySet->remove(key, ctx);
	}

	static void __cleanUp(ThreadContext* ctx) throw() {}
protected:
	HashMapKeySet<T, V>* hashMapKeySet;
};

}} /* namespace java::util */

namespace alinous { namespace util {

using namespace java::util;
using namespace java::lang;



template <typename T, typename V>
class StaticMapElement {
public:
	const T&& key;
	const V&& value;
	constexpr StaticMapElement() = default;
	constexpr StaticMapElement(const StaticMapElement &base) = default;
	constexpr StaticMapElement(const T& key, const V& value) : key(key), value(value) {
	}
};

template <typename T, typename V>
class StaticMapPtrRefElement {
public:
	T* key;
	V& value;
	StaticMapPtrRefElement() = default;
	StaticMapPtrRefElement(const StaticMapPtrRefElement &base) = default;
	StaticMapPtrRefElement(T* key, V&& value) : key(key), value(value) {
	}
	~StaticMapPtrRefElement(){

	}
};

template <typename T, typename V>
class StaticMapPtrPtrElement {
public:
	T* key;
	V* value;
	StaticMapPtrPtrElement() = default;
	StaticMapPtrPtrElement(StaticMapPtrPtrElement &base) = default;
	StaticMapPtrPtrElement(T* key, V* value) : key(key), value(value) {
	}
};


template <typename T, typename V>
class StaticMap : public HashMap<T, V> {
public:
	RawArray<IObject> objectRegistory{32};
	StaticMap() throw() : IObject(nullptr), HashMap<T, V>(),
			defInit(std::initializer_list<StaticMapElement<T, V> >{}),
			ptrRefInit(std::initializer_list<StaticMapPtrRefElement<T, V> >{}),
			ptrPtrInit(std::initializer_list<StaticMapPtrPtrElement<T, V> >{})
			{};
	StaticMap(const StaticMap &base) = default;

	std::initializer_list<StaticMapElement<T, V> > defInit;
	std::initializer_list<StaticMapPtrRefElement<T, V> > ptrRefInit;
	std::initializer_list<StaticMapPtrPtrElement<T, V> > ptrPtrInit;

	StaticMap(std::initializer_list<StaticMapElement<T, V> >&& init) throw() : IObject(nullptr), HashMap<T, V>(),
			defInit(static_cast<std::initializer_list<StaticMapElement<T, V> >&&>(init)),
			ptrRefInit(std::initializer_list<StaticMapPtrRefElement<T, V> >{}),
			ptrPtrInit(std::initializer_list<StaticMapPtrPtrElement<T, V> >{})
	{

		for ( auto iter = init.begin() ; iter != init.end() ; ++iter ){
			const StaticMapElement<T, V>* ptr =  iter;

			put(const_cast<T*>(&ptr->key), const_cast<V*>(&ptr->value));

		}
	}
	StaticMap(std::initializer_list<StaticMapPtrRefElement<T, V> >&& init) throw() :IObject(nullptr), HashMap<T, V>(),
			defInit(std::initializer_list<StaticMapElement<T, V> >{}),
			ptrRefInit(static_cast<std::initializer_list<StaticMapPtrRefElement<T, V> >&&>(init)),
			ptrPtrInit(std::initializer_list<StaticMapPtrPtrElement<T, V> >{})
	{
		for (auto iter = ptrRefInit.begin() ; iter != ptrRefInit.end() ; ++iter ){
			const StaticMapPtrRefElement<T,  V>* ptr =  iter;

			V* value = new V(ptr->value);
			objectRegistory.addElementWithSorted(value);

			put(ptr->key, value);

		}
	}


	StaticMap(std::initializer_list<StaticMapPtrPtrElement<T, V> >&& init) throw() : IObject(nullptr), HashMap<T, V>(),
			defInit(std::initializer_list<StaticMapElement<T, V> >{}),
			ptrRefInit(std::initializer_list<StaticMapPtrRefElement<T, V> >{}),
			ptrPtrInit(static_cast<std::initializer_list<StaticMapPtrPtrElement<T, V> >&&>(init))
	{
		for ( auto iter = init.begin() ; iter != init.end() ; ++iter ){
			const StaticMapPtrPtrElement<T, V>* ptr =  iter;

			put(ptr->key, ptr->value);
		}
	}
	StaticMap(std::initializer_list<StaticMapElement<T, V> >&& init, ThreadContext* ctx) throw(): HashMap<T, V>(ctx),
			defInit(static_cast<std::initializer_list<StaticMapElement<T, V> >&&>(init)),
			ptrRefInit(std::initializer_list<StaticMapPtrRefElement<T, V> >{}),
			ptrPtrInit(std::initializer_list<StaticMapPtrPtrElement<T, V> >{})
	{
		for ( auto iter = init.begin() ; iter != init.end() ; ++iter ){
			const StaticMapElement<T,  V>* ptr =  iter;

			put(const_cast<T*>(&ptr->key), const_cast<V*>(&ptr->value));
		}
	}

	virtual ~StaticMap() throw() {
		__releaseRegerences(false, nullptr);
	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		const int maxLoop = this->objectRegistory.size();
		for(int i = 0; i != maxLoop; ++i){
			IObject* pObj = this->objectRegistory.get(i);
			delete pObj;
		}

		this->objectRegistory.reset();

	}
	void put(T* key, V* value) throw() {
		HashMapInternalElement<T, V> newValue(key, value);
		this->hashMapKeySet->addElement(&newValue, nullptr);
	}

/*
	V* get(T* key, ThreadContext* ctx) {
		V* value = this->hashMapKeySet->getValue(key, ctx);
		return value;
	}*/
};


}
} /* namespace alinous::util */



#endif /* BASELIB_HASHMAP_H_ */
