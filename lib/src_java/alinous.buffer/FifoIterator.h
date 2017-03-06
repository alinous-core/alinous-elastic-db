#ifndef ALINOUS_BUFFER_FIFOITERATOR_T__H_
#define ALINOUS_BUFFER_FIFOITERATOR_T__H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {
template <typename  T> class FifoList;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace util {
class Builtin;}}

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
using ::alinous::util::Builtin;



template <typename T>
class FifoIterator final : public virtual IObject {
public:
	FifoIterator(const FifoIterator& base) = default;
public:
	FifoIterator(FifoList<T>* list, ThreadContext* ctx) throw()  : IObject(ctx), current(nullptr)
	{
		GCUtils<FifoElement<T> >::mv(this, &(this->current), list->root, ctx);
	}
	void __construct_impl(FifoList<T>* list, ThreadContext* ctx) throw() 
	{
		GCUtils<FifoElement<T> >::mv(this, &(this->current), list->root, ctx);
	}
	virtual ~FifoIterator() throw() 
	{
		ThreadContext *ctx = ThreadContext::getCurentContext();
		if(ctx != nullptr){ctx->incGcDenial();}
		__releaseRegerences(false, ctx);
		if(ctx != nullptr){ctx->decGcDenial();}
	}
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
	{
		ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FifoIterator", L"~FifoIterator");
		__e_obj1.add(this->current, this);
		current = nullptr;
		if(!prepare){
			return;
		}
	}
private:
	FifoElement<T>* current;
public:
	bool hasNext(ThreadContext* ctx) throw() 
	{
		return current != nullptr;
	}
	T* next(ThreadContext* ctx) throw() 
	{
		FifoElement<T>* prevCurent = current;
		GCUtils<FifoElement<T> >::mv(this, &(current), current->next, ctx);
		if(current != nullptr)
		{
			__builtin_prefetch(current);
			__builtin_prefetch(current->data);
		}
		return prevCurent->data;
	}
	FifoElement<T>* nextElement(ThreadContext* ctx) throw() 
	{
		FifoElement<T>* prevCurent = current;
		GCUtils<FifoElement<T> >::mv(this, &(current), current->next, ctx);
		if(current != nullptr)
		{
			__builtin_prefetch(current);
			__builtin_prefetch(current->data);
		}
		return prevCurent;
	}
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BUFFER_FIFOITERATOR_T__H_ */
