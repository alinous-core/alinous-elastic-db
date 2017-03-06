#ifndef JAVA_HARMONEY_FLOATINGPOINTPARSER_H_
#define JAVA_HARMONEY_FLOATINGPOINTPARSER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace harmoney {
class HexStringParser;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace java {namespace lang {
class Double;}}

namespace java {namespace lang {
class Integer;}}

namespace java {namespace lang {
class Math;}}

namespace com {namespace google {namespace re2j {
class PatternSyntaxException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace harmoney {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::com::google::re2j::PatternSyntaxException;



class FloatingPointParser final : public virtual IObject {
public:
	class StringExponentPair;
	FloatingPointParser(const FloatingPointParser& base) = default;
public:
	FloatingPointParser(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FloatingPointParser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int FLOAT_MIN_EXP{-46};
	constexpr static const int FLOAT_MAX_EXP{38};
	constexpr static const int DOUBLE_MIN_EXP{-324};
	constexpr static const int DOUBLE_MAX_EXP{308};
public:
	static void includes(HexStringParser* arg0, ThreadContext* ctx) throw() ;
	static double doparseDouble(String* s, ThreadContext* ctx);
private:
	static double parseDblImpl(String* s, int e, ThreadContext* ctx) throw() ;
	static bool parseAsHex(String* s, ThreadContext* ctx) throw() ;
	static double parseDblName(String* namedDouble, int length, ThreadContext* ctx) throw() ;
	static FloatingPointParser::StringExponentPair* initialParse(String* s, int length, ThreadContext* ctx) throw() ;
public:



	class StringExponentPair final : public virtual IObject {
	public:
		StringExponentPair(const StringExponentPair& base) = default;
	public:
		StringExponentPair(String* s, int e, bool negative, ThreadContext* ctx) throw() ;
		void __construct_impl(String* s, int e, bool negative, ThreadContext* ctx) throw() ;
		virtual ~StringExponentPair() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		String* s;
		int e;
		bool negative;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_HARMONEY_FLOATINGPOINTPARSER_H_ */
