#ifndef ALINOUS_SERVER_WEBMODULE_BINARYMODULESTREAM_H_
#define ALINOUS_SERVER_WEBMODULE_BINARYMODULESTREAM_H_
namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace java {namespace io {
class File;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class FileInputStream;}}

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

namespace alinous {namespace server {namespace webmodule {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::FileInputStream;
using ::java::io::IOException;
using ::java::io::OutputStream;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;



class BinaryModuleStream final : public IContentByteStream, public virtual IObject {
public:
	BinaryModuleStream(const BinaryModuleStream& base) = default;
public:
	BinaryModuleStream(HttpHeaderProcessor* httpRequest, File* file, ThreadContext* ctx) throw() ;
	void __construct_impl(HttpHeaderProcessor* httpRequest, File* file, ThreadContext* ctx) throw() ;
	virtual ~BinaryModuleStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long filesize;
	File* file;
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

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_BINARYMODULESTREAM_H_ */
