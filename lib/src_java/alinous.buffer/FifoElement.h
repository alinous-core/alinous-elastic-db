#ifndef ALINOUS_BUFFER_FIFOELEMENT_T__H_
#define ALINOUS_BUFFER_FIFOELEMENT_T__H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
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
class FifoElement final : public virtual IObject {
public:
	FifoElement(const FifoElement& base) = default;
public:
	FifoElement(ThreadContext* ctx) throw()  : IObject(ctx), data(nullptr), next(nullptr), prev(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	FifoElement(T* data, ThreadContext* ctx) throw()  : IObject(ctx), data(nullptr), next(nullptr), prev(nullptr)
	{
		__GC_MV(this, &(this->data), data, T);
	}
	void __construct_impl(T* data, ThreadContext* ctx) throw() 
	{
		__GC_MV(this, &(this->data), data, T);
	}
	FifoElement(T* data, FifoElement<T>* prev, FifoElement<T>* next, ThreadContext* ctx) throw()  : IObject(ctx), data(nullptr), next(nullptr), prev(nullptr)
	{
		__GC_MV(this, &(this->data), data, T);
		GCUtils<FifoElement<T> >::mv(this, &(this->prev), prev, ctx);
		GCUtils<FifoElement<T> >::mv(this, &(this->next), next, ctx);
	}
	void __construct_impl(T* data, FifoElement<T>* prev, FifoElement<T>* next, ThreadContext* ctx) throw() 
	{
		__GC_MV(this, &(this->data), data, T);
		GCUtils<FifoElement<T> >::mv(this, &(this->prev), prev, ctx);
		GCUtils<FifoElement<T> >::mv(this, &(this->next), next, ctx);
	}
	virtual ~FifoElement() throw() 
	{
		ThreadContext *ctx = ThreadContext::getCurentContext();
		if(ctx != nullptr){ctx->incGcDenial();}
		__releaseRegerences(false, ctx);
		if(ctx != nullptr){ctx->decGcDenial();}
	}
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
	{
		ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FifoElement", L"~FifoElement");
		__e_obj1.add(this->data, this);
		data = nullptr;
		__e_obj1.add(this->next, this);
		next = nullptr;
		__e_obj1.add(this->prev, this);
		prev = nullptr;
		if(!prepare){
			return;
		}
	}
public:
	T* data;
	FifoElement<T>* next;
	FifoElement<T>* prev;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BUFFER_FIFOELEMENT_T__H_ */
