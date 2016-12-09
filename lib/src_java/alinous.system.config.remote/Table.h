#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_TABLE_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_TABLE_H_
namespace alinous {namespace system {namespace config {namespace remote {
class Table;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace system {namespace config {namespace remote {
class NodeRef;}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace alinous {namespace parser {namespace xpath {
class ParseException;}}}

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
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::java::util::List;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::MatchCandidatesCollection;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;
using ::alinous::parser::xpath::ParseException;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::IAlinousConfigElement;



class Table final : public IAlinousConfigElement, public virtual IObject {
public:
	Table(const Table& base) = default;
public:
	Table(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), name(nullptr), keys(GCUtils<List<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), nodeRefs(GCUtils<List<NodeRef> >::ins(this, (new(ctx) ArrayList<NodeRef>(ctx)), ctx, __FILEW__, __LINE__, L"")), max(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Table() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	List<String>* keys;
	List<NodeRef>* nodeRefs;
	String* max;
public:
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	List<String>* getKeys(ThreadContext* ctx) throw() ;
	void addKey(String* key, ThreadContext* ctx) throw() ;
	void addNodeRef(NodeRef* node, ThreadContext* ctx) throw() ;
	List<NodeRef>* getNodeRefs(ThreadContext* ctx) throw() ;
	String* getMax(ThreadContext* ctx) throw() ;
	void setMax(String* max, ThreadContext* ctx) throw() ;
public:
	static Table* parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_TABLE_H_ */
