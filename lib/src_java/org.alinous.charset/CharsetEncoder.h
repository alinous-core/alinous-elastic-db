#ifndef ORG_ALINOUS_CHARSET_CHARSETENCODER_H_
#define ORG_ALINOUS_CHARSET_CHARSETENCODER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace nio {namespace charset {
class CoderResult;}}}

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

namespace org {namespace alinous {namespace charset {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::nio::ByteBuffer;
using ::java::nio::CharBuffer;
using ::java::nio::charset::CoderResult;



class CharsetEncoder : public virtual IObject {
public:
	CharsetEncoder(const CharsetEncoder& base) = default;
public:
	CharsetEncoder(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~CharsetEncoder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual CoderResult* encodeLoop(CharBuffer* cb, ByteBuffer* bb, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ORG_ALINOUS_CHARSET_CHARSETENCODER_H_ */
