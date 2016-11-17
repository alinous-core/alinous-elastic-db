#ifndef ORG_ALINOUS_CHARSET_UTF_16_H_
#define ORG_ALINOUS_CHARSET_UTF_16_H_
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
class Throwable;}}

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



class UTF_16 : public CharsetConverter, public virtual IObject {
public:
	class Decoder;
	class Encoder;
	UTF_16(const UTF_16& base) = default;
public:
	UTF_16(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~UTF_16() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	CharsetDecoder* decoder;
	CharsetEncoder* encoder;
public:
	constexpr static const int UNKNOWN{-1};
	constexpr static const int BIG{0};
	constexpr static const int LITTLE{1};
	constexpr static const int ANY{2};
	constexpr static const int NOT_DETECTED{3};
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
	private:
		int endian;
	public:
		constexpr static const int UNKNOWN{-1};
		constexpr static const int BIG{0};
		constexpr static const int LITTLE{1};
		constexpr static const int ANY{2};
		constexpr static const int NOT_DETECTED{3};
	public:
		CoderResult* decodeLoop(ByteBuffer* in, CharBuffer* out, ThreadContext* ctx) throw()  final;
		void implReset(ThreadContext* ctx) throw() ;
		int getDefaultEndian(ThreadContext* ctx) throw() ;
		int getDetectedEndian(int b1, int b2, ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class Encoder final : public CharsetEncoder, public virtual IObject {
	public:
		Encoder(const Encoder& base) = default;
	public:
		Encoder(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~Encoder() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		int endian;
	public:
		constexpr static const int UNKNOWN{-1};
		constexpr static const int BIG{0};
		constexpr static const int LITTLE{1};
		constexpr static const int ANY{2};
		constexpr static const int NOT_DETECTED{3};
	public:
		CoderResult* encodeLoop(CharBuffer* in, ByteBuffer* out, ThreadContext* ctx) throw()  final;
		void implReset(ThreadContext* ctx) throw() ;
		int getDefaultEndian(ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ORG_ALINOUS_CHARSET_UTF_16_H_ */
