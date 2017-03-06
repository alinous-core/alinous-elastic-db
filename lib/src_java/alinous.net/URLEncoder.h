#ifndef ALINOUS_NET_URLENCODER_H_
#define ALINOUS_NET_URLENCODER_H_
namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace net {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::UnsupportedEncodingException;



class URLEncoder final : public virtual IObject {
public:
	URLEncoder(const URLEncoder& base) = default;
public:
	URLEncoder(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~URLEncoder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* digits;
public:
	static String* encode(String* s, String* enc, ThreadContext* ctx);
private:
	static void convert(String* s, StringBuffer* buf, String* enc, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NET_URLENCODER_H_ */
