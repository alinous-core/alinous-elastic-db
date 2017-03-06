#ifndef JAVA_LANG_COMPARABLE_T__H_
#define JAVA_LANG_COMPARABLE_T__H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace lang {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



template <typename T>
class Comparable : public virtual IObject {
public:
	Comparable(const Comparable& base) = default;
public:
	Comparable(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Comparable() throw() 
	{
		ThreadContext *ctx = ThreadContext::getCurentContext();
		if(ctx != nullptr){ctx->incGcDenial();}
		__releaseRegerences(false, ctx);
		if(ctx != nullptr){ctx->decGcDenial();}
	}
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
	{
		if(!prepare){
			return;
		}
	}
public:
	virtual int compareTo(T* another, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_LANG_COMPARABLE_T__H_ */
