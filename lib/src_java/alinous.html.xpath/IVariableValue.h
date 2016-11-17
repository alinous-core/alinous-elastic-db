#ifndef ALINOUS_HTML_XPATH_IVARIABLEVALUE_H_
#define ALINOUS_HTML_XPATH_IVARIABLEVALUE_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IVariableValue : public virtual IObject {
public:
	IVariableValue(const IVariableValue& base) = default;
public:
	IVariableValue(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IVariableValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual String* toString(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_IVARIABLEVALUE_H_ */
