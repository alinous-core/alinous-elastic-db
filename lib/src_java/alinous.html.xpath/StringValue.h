#ifndef ALINOUS_HTML_XPATH_STRINGVALUE_H_
#define ALINOUS_HTML_XPATH_STRINGVALUE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

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



class StringValue final : public IVariableValue, public virtual IObject {
public:
	StringValue(const StringValue& base) = default;
public:
	StringValue(String* v, ThreadContext* ctx) throw() ;
	void __construct_impl(String* v, ThreadContext* ctx) throw() ;
	virtual ~StringValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* value;
public:
	String* getValue(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_STRINGVALUE_H_ */
