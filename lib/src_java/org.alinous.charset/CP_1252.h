#ifndef ORG_ALINOUS_CHARSET_CP_1252_H_
#define ORG_ALINOUS_CHARSET_CP_1252_H_
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



class CP_1252 final : public CharsetConverter, public virtual IObject {
public:
	class Decoder;
	class Encoder;
	CP_1252(const CP_1252& base) = default;
public:
	CP_1252(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CP_1252() throw();
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
		Decoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetDecoder(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~Decoder() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		static const StaticArrayObjectPrimitive<wchar_t> __arr;
		static IArrayObjectPrimitive<wchar_t>* arr;
	public:
		CoderResult* decodeLoop(ByteBuffer* bb, CharBuffer* cb, ThreadContext* ctx) throw()  final;
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
		Encoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetEncoder(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~Encoder() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		static const StaticArrayObjectPrimitive<wchar_t> __arr;
		static IArrayObjectPrimitive<wchar_t>* arr;
		static const StaticArrayObjectPrimitive<int> __encodeIndex;
		static IArrayObjectPrimitive<int>* encodeIndex;
	public:
		CoderResult* encodeLoop(CharBuffer* cb, ByteBuffer* bb, ThreadContext* ctx) throw()  final;
	private:
		void nEncode(long long outAddr, int absolutePos, IArrayObjectPrimitive<wchar_t>* array, int arrPosition, IArrayObjectPrimitive<int>* res, ThreadContext* ctx) throw() ;
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

#endif /* end of ORG_ALINOUS_CHARSET_CP_1252_H_ */
