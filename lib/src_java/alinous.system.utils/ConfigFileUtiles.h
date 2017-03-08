#ifndef ALINOUS_SYSTEM_UTILS_CONFIGFILEUTILES_H_
#define ALINOUS_SYSTEM_UTILS_CONFIGFILEUTILES_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

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

namespace alinous {namespace system {namespace utils {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::MatchCandidatesCollection;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;
using ::alinous::parser::xpath::ParseException;



class ConfigFileUtiles final : public virtual IObject {
public:
	ConfigFileUtiles(const ConfigFileUtiles& base) = default;
public:
	ConfigFileUtiles(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ConfigFileUtiles() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* getAttribute(DomDocument* document, DomNode* start, Matcher* matcher, String* xpath, String* name, ThreadContext* ctx);
	static String* getText(DomDocument* document, DomNode* start, Matcher* matcher, String* xpath, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SYSTEM_UTILS_CONFIGFILEUTILES_H_ */
