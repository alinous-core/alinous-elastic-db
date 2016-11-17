#ifndef ALINOUS_HTML_XPATH_FUNCTION_LAST_H_
#define ALINOUS_HTML_XPATH_FUNCTION_LAST_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class XpathFunctionArgument;}}}

namespace alinous {namespace html {namespace xpath {
class NumberValue;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathFunction;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {namespace function {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::IXpathFunction;
using ::alinous::html::xpath::NumberValue;
using ::alinous::html::xpath::XpathFunctionArgument;



class Last final : public IXpathFunction, public virtual IObject {
public:
	Last(const Last& base) = default;
public:
	Last(ThreadContext* ctx) throw()  : IObject(ctx), IXpathFunction(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Last() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ArrayList<XpathFunctionArgument>* arguments, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_HTML_XPATH_FUNCTION_LAST_H_ */
