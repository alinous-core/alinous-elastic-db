#ifndef JAVA_UTIL_LOCALE_H_
#define JAVA_UTIL_LOCALE_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace util {
class Locale;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace util {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class Locale final : public virtual IObject {
public:
	Locale(const Locale& base) = default;
public:
	Locale(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	Locale(String* language, ThreadContext* ctx) throw() ;
	void __construct_impl(String* language, ThreadContext* ctx) throw() ;
	Locale(String* language, String* country, ThreadContext* ctx) throw() ;
	void __construct_impl(String* language, String* country, ThreadContext* ctx) throw() ;
	Locale(String* language, String* country, String* variant, ThreadContext* ctx) throw() ;
	void __construct_impl(String* language, String* country, String* variant, ThreadContext* ctx) throw() ;
	virtual ~Locale() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* countryCode;
	String* languageCode;
	String* variantCode;
public:
	const static Locale __CANADA;
	constexpr static Locale* CANADA{const_cast<Locale*>(&__CANADA)};
	const static Locale __CANADA_FRENCH;
	constexpr static Locale* CANADA_FRENCH{const_cast<Locale*>(&__CANADA_FRENCH)};
	const static Locale __CHINA;
	constexpr static Locale* CHINA{const_cast<Locale*>(&__CHINA)};
	const static Locale __CHINESE;
	constexpr static Locale* CHINESE{const_cast<Locale*>(&__CHINESE)};
	const static Locale __ENGLISH;
	constexpr static Locale* ENGLISH{const_cast<Locale*>(&__ENGLISH)};
	const static Locale __FRANCE;
	constexpr static Locale* FRANCE{const_cast<Locale*>(&__FRANCE)};
	const static Locale __FRENCH;
	constexpr static Locale* FRENCH{const_cast<Locale*>(&__FRENCH)};
	const static Locale __GERMAN;
	constexpr static Locale* GERMAN{const_cast<Locale*>(&__GERMAN)};
	const static Locale __GERMANY;
	constexpr static Locale* GERMANY{const_cast<Locale*>(&__GERMANY)};
	const static Locale __ITALIAN;
	constexpr static Locale* ITALIAN{const_cast<Locale*>(&__ITALIAN)};
	const static Locale __ITALY;
	constexpr static Locale* ITALY{const_cast<Locale*>(&__ITALY)};
	const static Locale __JAPAN;
	constexpr static Locale* JAPAN{const_cast<Locale*>(&__JAPAN)};
	const static Locale __JAPANESE;
	constexpr static Locale* JAPANESE{const_cast<Locale*>(&__JAPANESE)};
	const static Locale __KOREA;
	constexpr static Locale* KOREA{const_cast<Locale*>(&__KOREA)};
	const static Locale __KOREAN;
	constexpr static Locale* KOREAN{const_cast<Locale*>(&__KOREAN)};
	const static Locale __PRC;
	constexpr static Locale* PRC{const_cast<Locale*>(&__PRC)};
	const static Locale __SIMPLIFIED_CHINESE;
	constexpr static Locale* SIMPLIFIED_CHINESE{const_cast<Locale*>(&__SIMPLIFIED_CHINESE)};
	const static Locale __TAIWAN;
	constexpr static Locale* TAIWAN{const_cast<Locale*>(&__TAIWAN)};
	const static Locale __TRADITIONAL_CHINESE;
	constexpr static Locale* TRADITIONAL_CHINESE{const_cast<Locale*>(&__TRADITIONAL_CHINESE)};
	const static Locale __UK;
	constexpr static Locale* UK{const_cast<Locale*>(&__UK)};
	const static Locale __US;
	constexpr static Locale* US{const_cast<Locale*>(&__US)};
private:
	static Locale* defaultLocale;
public:
	bool equals(IObject* object, ThreadContext* ctx) throw() ;
	String* getCountry(ThreadContext* ctx) throw() ;
	String* getDisplayCountry(ThreadContext* ctx) throw() ;
	String* getDisplayCountry(Locale* locale, ThreadContext* ctx) throw() ;
	String* getDisplayLanguage(ThreadContext* ctx) throw() ;
	String* getDisplayLanguage(Locale* locale, ThreadContext* ctx) throw() ;
	String* getDisplayName(ThreadContext* ctx) throw() ;
	String* getDisplayName(Locale* locale, ThreadContext* ctx) throw() ;
	String* getDisplayVariant(ThreadContext* ctx) throw() ;
	String* getDisplayVariant(Locale* locale, ThreadContext* ctx) throw() ;
	String* getISO3Country(ThreadContext* ctx);
	String* getISO3Language(ThreadContext* ctx);
	String* getLanguage(ThreadContext* ctx) throw() ;
	String* getVariant(ThreadContext* ctx) throw() ;
	int hashCode(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static IArrayObject<Locale>* getAvailableLocales(ThreadContext* ctx) throw() ;
	static Locale* getDefault(ThreadContext* ctx) throw() ;
	static IArrayObject<String>* getISOCountries(ThreadContext* ctx) throw() ;
	static IArrayObject<String>* getISOLanguages(ThreadContext* ctx) throw() ;
	static void setDefault(Locale* locale, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<Locale>::dec(nullptr, Locale::defaultLocale, ctx, __FILEW__, __LINE__, L"Locale");
	}
};

}}

#endif /* end of JAVA_UTIL_LOCALE_H_ */
