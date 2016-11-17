#ifndef JAVA_LANG_NUMBER_H_
#define JAVA_LANG_NUMBER_H_
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



class Number : public virtual IObject {
public:
	Number(const Number& base) = default;
public:
	Number(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Number() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual char byteValue(ThreadContext* ctx) throw() ;
	virtual double doubleValue(ThreadContext* ctx) throw()  = 0;
	virtual float floatValue(ThreadContext* ctx) throw()  = 0;
	virtual int intValue(ThreadContext* ctx) throw()  = 0;
	virtual long long longValue(ThreadContext* ctx) throw()  = 0;
	virtual short shortValue(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_LANG_NUMBER_H_ */
