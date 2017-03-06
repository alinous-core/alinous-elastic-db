#ifndef ALINOUS_NET_URLDECODER_H_
#define ALINOUS_NET_URLDECODER_H_
namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace org {namespace alinous {namespace charset {
class CharsetManager;}}}

namespace org {namespace alinous {namespace charset {
class CharsetDecoder;}}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace nio {
class CharBuffer;}}

namespace java {namespace nio {
class ByteBuffer;}}

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
using ::java::nio::ByteBuffer;
using ::java::nio::CharBuffer;
using ::org::alinous::charset::CharsetDecoder;
using ::org::alinous::charset::CharsetManager;



class URLDecoder final : public virtual IObject {
public:
	URLDecoder(const URLDecoder& base) = default;
public:
	URLDecoder(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~URLDecoder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* decode(String* s, String* enc, ThreadContext* ctx);
	static CharBuffer* decode(ByteBuffer* in, CharsetDecoder* decoder, ThreadContext* ctx) throw() ;
private:
	static String* decode(String* s, CharsetDecoder* decoder, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NET_URLDECODER_H_ */
