#ifndef ORG_ALINOUS_CHARSET_CHARSETDECODER_H_
#define ORG_ALINOUS_CHARSET_CHARSETDECODER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
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



class CharsetDecoder : public virtual IObject {
public:
	CharsetDecoder(const CharsetDecoder& base) = default;
public:
	CharsetDecoder(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~CharsetDecoder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual CoderResult* decodeLoop(ByteBuffer* bb, CharBuffer* cb, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ORG_ALINOUS_CHARSET_CHARSETDECODER_H_ */
