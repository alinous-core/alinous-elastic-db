#ifndef ORG_ALINOUS_CHARSET_ISO_8859_1_H_
#define ORG_ALINOUS_CHARSET_ISO_8859_1_H_
namespace org {namespace alinous {namespace charset {
class CharsetDecoder;}}}

namespace org {namespace alinous {namespace charset {
class CharsetEncoder;}}}

namespace org {namespace alinous {namespace charset {
class CharsetConverter;}}}

namespace java {namespace nio {namespace charset {
class CoderResult;}}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace nio {
class CharBuffer;}}

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
using ::java::nio::ByteBuffer;
using ::java::nio::CharBuffer;
using ::java::nio::charset::CoderResult;



class ISO_8859_1 final : public CharsetConverter, public virtual IObject {
public:
	class Decoder;
	class Encoder;
	ISO_8859_1(const ISO_8859_1& base) = default;
public:
	ISO_8859_1(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ISO_8859_1() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	CharsetDecoder* decoder;
	CharsetEncoder* encoder;
public:
	CharsetDecoder* newDecoder(ThreadContext* ctx) throw()  final;
	CharsetEncoder* newEncoder(ThreadContext* ctx) throw()  final;
public:
	static bool contains(String* cs, ThreadContext* ctx) throw() ;
public:



	class Decoder final : public CharsetDecoder, public virtual IObject {
	public:
		Decoder(const Decoder& base) = default;
	public:
		Decoder(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~Decoder() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		CoderResult* decodeLoop(ByteBuffer* bb, CharBuffer* cb, ThreadContext* ctx) throw()  final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};




	class Encoder final : public CharsetEncoder, public virtual IObject {
	public:
		Encoder(const Encoder& base) = default;
	public:
		Encoder(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~Encoder() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		CoderResult* encodeLoop(CharBuffer* cb, ByteBuffer* bb, ThreadContext* ctx) throw()  final;
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

}}}

#endif /* end of ORG_ALINOUS_CHARSET_ISO_8859_1_H_ */
