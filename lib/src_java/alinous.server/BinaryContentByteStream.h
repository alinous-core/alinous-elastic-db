#ifndef ALINOUS_SERVER_BINARYCONTENTBYTESTREAM_H_
#define ALINOUS_SERVER_BINARYCONTENTBYTESTREAM_H_
namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::OutputStream;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;



class BinaryContentByteStream final : public IContentByteStream, public virtual IObject {
public:
	BinaryContentByteStream(const BinaryContentByteStream& base) = default;
public:
	BinaryContentByteStream(IArrayObjectPrimitive<char>* bytes, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<char>* bytes, ThreadContext* ctx) throw() ;
	virtual ~BinaryContentByteStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IArrayObjectPrimitive<char>* bytes;
public:
	int length(ThreadContext* ctx) throw()  final;
	void output(OutputStream* outStream, ThreadContext* ctx) final;
	void prepare(AlinousCore* core, bool debug, ThreadContext* ctx) throw()  final;
	String* getContentType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_SERVER_BINARYCONTENTBYTESTREAM_H_ */
