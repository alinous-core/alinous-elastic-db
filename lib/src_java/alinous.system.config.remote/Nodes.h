#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_NODES_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_NODES_H_
namespace alinous {namespace system {namespace config {namespace remote {
class Nodes;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace system {namespace config {namespace remote {
class Node;}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace alinous {namespace parser {namespace xpath {
class ParseException;}}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

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
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::MatchCandidatesCollection;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;
using ::alinous::parser::xpath::ParseException;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::IAlinousConfigElement;



class Nodes final : public IAlinousConfigElement, public virtual IObject {
public:
	Nodes(const Nodes& base) = default;
public:
	Nodes(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), list(GCUtils<List<Node> >::ins(this, (new(ctx) ArrayList<Node>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Nodes() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<Node>* list;
public:
	void addNode(Node* node, ThreadContext* ctx) throw() ;
	List<Node>* getList(ThreadContext* ctx) throw() ;
public:
	static Nodes* parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, String* alinousHome, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_NODES_H_ */
