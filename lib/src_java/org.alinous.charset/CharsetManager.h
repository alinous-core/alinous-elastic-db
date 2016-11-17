#ifndef ORG_ALINOUS_CHARSET_CHARSETMANAGER_H_
#define ORG_ALINOUS_CHARSET_CHARSETMANAGER_H_
namespace java{namespace nio{namespace charset{
class UnsupportedCharsetException;
}}}
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace org {namespace alinous {namespace charset {
class CharsetDecoder;}}}

namespace org {namespace alinous {namespace charset {
class CharsetConverter;}}}

namespace org {namespace alinous {namespace charset {
class CharsetEncoder;}}}

namespace org {namespace alinous {namespace charset {
class CP_1250;}}}

namespace org {namespace alinous {namespace charset {
class CP_1251;}}}

namespace org {namespace alinous {namespace charset {
class CP_1252;}}}

namespace org {namespace alinous {namespace charset {
class CP_1253;}}}

namespace org {namespace alinous {namespace charset {
class CP_1254;}}}

namespace org {namespace alinous {namespace charset {
class CP_1257;}}}

namespace org {namespace alinous {namespace charset {
class IBM866;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_1;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_2;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_4;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_5;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_7;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_9;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_13;}}}

namespace org {namespace alinous {namespace charset {
class ISO_8859_15;}}}

namespace org {namespace alinous {namespace charset {
class KOI8_R;}}}

namespace org {namespace alinous {namespace charset {
class US_ASCII;}}}

namespace org {namespace alinous {namespace charset {
class UTF_16;}}}

namespace org {namespace alinous {namespace charset {
class UTF_16BE;}}}

namespace org {namespace alinous {namespace charset {
class UTF_16LE;}}}

namespace org {namespace alinous {namespace charset {
class UTF_8;}}}

namespace org {namespace alinous {namespace charset {
class CharsetManager;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace org {namespace alinous {namespace charset {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::nio::charset::UnsupportedCharsetException;
using ::java::util::HashMap;



class CharsetManager final : public virtual IObject {
public:
	CharsetManager(const CharsetManager& base) = default;
public:
	CharsetManager(ThreadContext* ctx) throw()  : IObject(ctx), charConverters(GCUtils<HashMap<String,CharsetConverter> >::ins(this, (new(ctx) HashMap<String,CharsetConverter>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~CharsetManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,CharsetConverter>* charConverters;
private:
	static CharsetManager* instance;
public:
	CharsetDecoder* getDecoder(String* charset, ThreadContext* ctx) throw() ;
	CharsetEncoder* getEncoder(String* charset, ThreadContext* ctx) throw() ;
	CharsetConverter* getConverter(String* charset, ThreadContext* ctx) throw() ;
public:
	static CharsetManager* getInstance(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<CharsetManager>::dec(nullptr, CharsetManager::instance, ctx, __FILEW__, __LINE__, L"CharsetManager");
	}
};

}}}

#endif /* end of ORG_ALINOUS_CHARSET_CHARSETMANAGER_H_ */
