#ifndef ALINOUS_BUFFER_FIFOLIST_T__H_
#define ALINOUS_BUFFER_FIFOLIST_T__H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {
template <typename  T> class FifoIterator;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace buffer {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



template <typename T>
class FifoList final : public virtual IObject {
public:
	FifoList(const FifoList& base) = default;
public:
	FifoList(ThreadContext* ctx) throw()  : IObject(ctx), root(nullptr), last(nullptr), length(0)
	{
		GCUtils<FifoElement<T> >::mv(this, &(this->root), nullptr, ctx);
		GCUtils<FifoElement<T> >::mv(this, &(this->last), nullptr, ctx);
		this->length = 0;
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
		GCUtils<FifoElement<T> >::mv(this, &(this->root), nullptr, ctx);
		GCUtils<FifoElement<T> >::mv(this, &(this->last), nullptr, ctx);
		this->length = 0;
	}
	virtual ~FifoList() throw() 
	{
		ThreadContext *ctx = ThreadContext::getCurentContext();
		if(ctx != nullptr){ctx->incGcDenial();}
		__releaseRegerences(false, ctx);
		if(ctx != nullptr){ctx->decGcDenial();}
	}
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
	{
		ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FifoList", L"~FifoList");
		__e_obj1.add(this->root, this);
		root = nullptr;
		__e_obj1.add(this->last, this);
		last = nullptr;
		if(!prepare){
			return;
		}
	}
public:
	FifoElement<T>* root;
	FifoElement<T>* last;
	int length;
public:
	FifoIterator<T>* iterator(ThreadContext* ctx) throw() 
	{
		FifoIterator<T>* iter = (new(ctx) FifoIterator<T>(this, ctx));
		return iter;
	}
	void add(T* data, ThreadContext* ctx) throw() 
	{
		addLast(data, ctx);
	}
	void addElement(FifoElement<T>* fifoElement, ThreadContext* ctx) throw() 
	{
		doAddElement(fifoElement, ctx);
	}
	void add(int index, T* element, ThreadContext* ctx) throw() 
	{
		if(index == this->length)
		{
			addLast(element, ctx);
		}
				else 
		{
			FifoElement<T>* e = getElement(index, ctx);
			FifoElement<T>* newElement = (new(ctx) FifoElement<T>(element, ctx));
			addBefore(e, newElement, ctx);
		}
	}
	void clear(ThreadContext* ctx) throw() 
	{
		int max = this->length;
		for(int i = 0; i != max; ++i)
		{
			removeElement(this->root, ctx);
		}
		this->length = 0;
	}
	bool contains(T* o, ThreadContext* ctx) throw() 
	{
		FifoIterator<T>* it = iterator(ctx);
		while(it->hasNext(ctx))
		{
			T* d = it->next(ctx);
			if(o->equals(d, ctx))
			{
				return true;
			}
		}
		return false;
	}
	T* get(int index, ThreadContext* ctx) throw() 
	{
		int i = 0;
		FifoIterator<T>* it = iterator(ctx);
		while(it->hasNext(ctx))
		{
			T* d = it->next(ctx);
			if(i == index)
			{
				return d;
			}
			++i;
		}
		return nullptr;
	}
	int indexOf(T* obj, ThreadContext* ctx) throw() 
	{
		int index = 0;
		FifoIterator<T>* it = iterator(ctx);
		while(it->hasNext(ctx))
		{
			T* d = it->next(ctx);
			if(obj->equals(d, ctx))
			{
				return index;
			}
			++index;
		}
		return -1;
	}
	bool isEmpty(ThreadContext* ctx) throw() 
	{
		return this->length == 0;
	}
	T* remove(int index, ThreadContext* ctx) throw() 
	{
		FifoElement<T>* del = getElement(index, ctx);
		T* ret = del->data;
		removeElement(del, ctx);
		return ret;
	}
	bool remove(T* data, ThreadContext* ctx) throw() 
	{
		int index = indexOf(data, ctx);
		if(index < 0)
		{
			return false;
		}
		FifoElement<T>* del = getElement(index, ctx);
		removeElement(del, ctx);
		return true;
	}
	int size(ThreadContext* ctx) throw() 
	{
		return this->length;
	}
	FifoElement<T>* getElement(int index, ThreadContext* ctx) throw() 
	{
		int i = 0;
		FifoIterator<T>* it = iterator(ctx);
		while(it->hasNext(ctx))
		{
			FifoElement<T>* e = it->nextElement(ctx);
			if(i == index)
			{
				return e;
			}
			++i;
		}
		return nullptr;
	}
	void removeElement(FifoElement<T>* element, ThreadContext* ctx) throw() 
	{
		if(element == this->root)
		{
			if(element->next != nullptr)
			{
				GCUtils<FifoElement<T> >::mv(element->next, &(element->next->prev), nullptr, ctx);
			}
			GCUtils<FifoElement<T> >::mv(this, &(this->root), element->next, ctx);
			if(element == this->last)
			{
				GCUtils<FifoElement<T> >::mv(this, &(this->last), nullptr, ctx);
			}
			this->length -- ;
			GCUtils<FifoElement<T> >::mv(element, &(element->prev), nullptr, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->next), nullptr, ctx);
			return;
		}
				else 
		{
			if(element == this->last)
			{
				GCUtils<FifoElement<T> >::mv(element->prev, &(element->prev->next), nullptr, ctx);
				GCUtils<FifoElement<T> >::mv(this, &(this->last), element->prev, ctx);
				this->length -- ;
				GCUtils<FifoElement<T> >::mv(element, &(element->prev), nullptr, ctx);
				GCUtils<FifoElement<T> >::mv(element, &(element->next), nullptr, ctx);
				return;
			}
		}
		if(element->next != nullptr)
		{
			GCUtils<FifoElement<T> >::mv(element->next, &(element->next->prev), element->prev, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->next), nullptr, ctx);
		}
		if(element->prev != nullptr)
		{
			GCUtils<FifoElement<T> >::mv(element->prev, &(element->prev->next), element->next, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->prev), nullptr, ctx);
		}
		this->length -- ;
	}
	void addBefore(FifoElement<T>* lastElement, FifoElement<T>* element, ThreadContext* ctx) throw() 
	{
		if(lastElement->prev == nullptr)
		{
			GCUtils<FifoElement<T> >::mv(lastElement, &(lastElement->prev), element, ctx);
			GCUtils<FifoElement<T> >::mv(this, &(this->root), element, ctx);
			GCUtils<FifoElement<T> >::mv(root, &(this->root->next), lastElement, ctx);
			this->length ++ ;
			return;
		}
		FifoElement<T>* parentOfLast = lastElement->prev;
		GCUtils<FifoElement<T> >::mv(parentOfLast, &(parentOfLast->next), element, ctx);
		GCUtils<FifoElement<T> >::mv(lastElement, &(lastElement->prev), element, ctx);
		GCUtils<FifoElement<T> >::mv(element, &(element->prev), parentOfLast, ctx);
		GCUtils<FifoElement<T> >::mv(element, &(element->next), lastElement, ctx);
		this->length ++ ;
	}
	FifoElement<T>* addLast(T* data, ThreadContext* ctx) throw() 
	{
		FifoElement<T>* element = (new(ctx) FifoElement<T>(data, ctx));
		return doAddElement(element, ctx);
	}
	void moveElementToLast(FifoElement<T>* element, ThreadContext* ctx) throw() 
	{
		if(element == last)
		{
			return;
		}
		if(element->prev == nullptr)
		{
			GCUtils<FifoElement<T> >::mv(this, &(this->root), element->next, ctx);
			GCUtils<FifoElement<T> >::mv(element->next, &(element->next->prev), nullptr, ctx);
		}
				else 
		{
			GCUtils<FifoElement<T> >::mv(element->prev, &(element->prev->next), element->next, ctx);
			GCUtils<FifoElement<T> >::mv(element->next, &(element->next->prev), element->prev, ctx);
		}
		GCUtils<FifoElement<T> >::mv(last, &(this->last->next), element, ctx);
		GCUtils<FifoElement<T> >::mv(element, &(element->prev), this->last, ctx);
		GCUtils<FifoElement<T> >::mv(element, &(element->next), nullptr, ctx);
		GCUtils<FifoElement<T> >::mv(this, &(this->last), element, ctx);
	}
	void moveElementToTop(FifoElement<T>* element, ThreadContext* ctx) throw() 
	{
		if(element == root)
		{
			return;
		}
		FifoElement<T>* prev = element->prev;
		if(prev != nullptr)
		{
			GCUtils<FifoElement<T> >::mv(prev, &(prev->next), element->next, ctx);
		}
		FifoElement<T>* next = element->next;
		if(next != nullptr)
		{
			GCUtils<FifoElement<T> >::mv(next, &(next->prev), prev, ctx);
		}
		if(this->root != nullptr)
		{
			next = this->root;
			GCUtils<FifoElement<T> >::mv(next, &(next->prev), element, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->next), next, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->prev), nullptr, ctx);
		}
				else 
		{
			GCUtils<FifoElement<T> >::mv(element, &(element->next), nullptr, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->prev), nullptr, ctx);
		}
		GCUtils<FifoElement<T> >::mv(this, &(this->root), element, ctx);
	}
private:
	FifoElement<T>* doAddElement(FifoElement<T>* element, ThreadContext* ctx) throw() 
	{
		if(this->root == nullptr)
		{
			GCUtils<FifoElement<T> >::mv(this, &(this->root), element, ctx);
			GCUtils<FifoElement<T> >::mv(this, &(this->last), element, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->prev), nullptr, ctx);
			GCUtils<FifoElement<T> >::mv(element, &(element->next), nullptr, ctx);
			this->length ++ ;
			return element;
		}
		GCUtils<FifoElement<T> >::mv(last, &(this->last->next), element, ctx);
		GCUtils<FifoElement<T> >::mv(element, &(element->prev), this->last, ctx);
		GCUtils<FifoElement<T> >::mv(element, &(element->next), nullptr, ctx);
		GCUtils<FifoElement<T> >::mv(this, &(this->last), element, ctx);
		this->length ++ ;
		return element;
	}
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BUFFER_FIFOLIST_T__H_ */
