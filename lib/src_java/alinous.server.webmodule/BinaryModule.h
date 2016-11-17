#ifndef ALINOUS_SERVER_WEBMODULE_BINARYMODULE_H_
#define ALINOUS_SERVER_WEBMODULE_BINARYMODULE_H_
namespace java {namespace io {
class File;}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace server {namespace webmodule {
class BinaryModuleStream;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {namespace webmodule {
class AbstractWebModule;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace webmodule {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;



class BinaryModule final : public AbstractWebModule {
public:
	BinaryModule(const BinaryModule& base) = default;
public:
	BinaryModule(String* path, File* file, ThreadContext* ctx) throw() ;
	void __construct_impl(String* path, File* file, ThreadContext* ctx) throw() ;
	virtual ~BinaryModule() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	File* file;
public:
	IContentByteStream* getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw()  final;
	void prepare(AlinousCore* core, ThreadContext* ctx) throw()  final;
	bool isDirty(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_BINARYMODULE_H_ */
