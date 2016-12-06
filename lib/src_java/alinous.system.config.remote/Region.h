#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_REGION_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_REGION_H_
namespace alinous {namespace system {namespace config {namespace remote {
class Region;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Tables;}}}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {namespace remote {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::system::config::IAlinousConfigElement;



class Region final : public IAlinousConfigElement, public virtual IObject {
public:
	Region(const Region& base) = default;
public:
	Region(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), name(nullptr), url(nullptr), tables(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Region() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	String* url;
	Tables* tables;
public:
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	String* getUrl(ThreadContext* ctx) throw() ;
	void setUrl(String* url, ThreadContext* ctx) throw() ;
	Tables* getTables(ThreadContext* ctx) throw() ;
	void setTables(Tables* tables, ThreadContext* ctx) throw() ;
public:
	static Region* parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_REGION_H_ */
