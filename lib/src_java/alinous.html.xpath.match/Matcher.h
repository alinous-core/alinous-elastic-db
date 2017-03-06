#ifndef ALINOUS_HTML_XPATH_MATCH_MATCHER_H_
#define ALINOUS_HTML_XPATH_MATCH_MATCHER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class Xpath;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace alinous {namespace html {namespace xpath {
class XpathContext;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCursor;}}}}

namespace alinous {namespace html {namespace xpath {
class XpathFilter;}}}

namespace java {namespace io {
class StringReader;}}

namespace alinous {namespace parser {namespace xpath {
class AlinousXpathParser;}}}

namespace alinous {namespace parser {namespace xpath {
class ParseException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {namespace match {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::StringReader;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IXpathStatement;
using ::alinous::html::xpath::Xpath;
using ::alinous::html::xpath::XpathContext;
using ::alinous::html::xpath::XpathFilter;
using ::alinous::parser::xpath::AlinousXpathParser;
using ::alinous::parser::xpath::ParseException;



class Matcher final : public virtual IObject {
public:
	Matcher(const Matcher& base) = default;
public:
	Matcher(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Matcher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	MatchCandidatesCollection* match(DomDocument* document, DomNode* start, Xpath* path, ThreadContext* ctx);
	MatchCandidatesCollection* match(DomDocument* document, DomNode* start, String* xpath, ThreadContext* ctx);
private:
	MatchCandidatesCollection* applyContext(DomDocument* document, MatchCandidatesCollection* collection, XpathContext* context, ThreadContext* ctx);
	void applyContext4Candidate(DomDocument* document, MatchCandidate* candidate, XpathContext* context, MatchCandidatesCollection* destCollection, ThreadContext* ctx);
	bool checkNodeNameOrAttribute(DomNode* node, XpathContext* context, ThreadContext* ctx) throw() ;
	bool checkFilter(DomDocument* document, DomNode* node, XpathContext* context, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_HTML_XPATH_MATCH_MATCHER_H_ */
