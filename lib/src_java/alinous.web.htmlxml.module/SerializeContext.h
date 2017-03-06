#ifndef ALINOUS_WEB_HTMLXML_MODULE_SERIALIZECONTEXT_H_
#define ALINOUS_WEB_HTMLXML_MODULE_SERIALIZECONTEXT_H_
namespace alinous {namespace web {namespace htmlxml {
class XMLTagBase;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class DynamicTag;}}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class StaticHtmlPart;}}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class DynamicBodyPart;}}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AbstractSerializedHtmlPart;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {namespace module {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::Stack;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::XMLTagBase;
using ::alinous::web::htmlxml::inner::IHtmlStringPart;



class SerializeContext final : public virtual IObject {
public:
	SerializeContext(const SerializeContext& base) = default;
public:
	SerializeContext(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~SerializeContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Stack<AbstractSerializedHtmlPart>* stack;
public:
	void addDynamicTag(XMLTagBase* tagbase, ThreadContext* ctx);
	void addParts(ArrayList<IHtmlStringPart>* parts, ThreadContext* ctx);
	void addStaticString(String* str, ThreadContext* ctx) throw() ;
	void addProgramBodyPart(String* htmlCode, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_MODULE_SERIALIZECONTEXT_H_ */
