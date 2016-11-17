#ifndef ALINOUS_SERVER_WEBMODULE_DIRECTMODULESTREAM_H_
#define ALINOUS_SERVER_WEBMODULE_DIRECTMODULESTREAM_H_
namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::io::IOException;
using ::java::io::OutputStream;
using ::java::io::UnsupportedEncodingException;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::AlinousModule;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class DirectModuleStream final : public IContentByteStream, public virtual IObject {
public:
	DirectModuleStream(const DirectModuleStream& base) = default;
public:
	DirectModuleStream(HttpHeaderProcessor* httpRequest, AlinousModule* alnsModule, ThreadContext* ctx) throw()  : IObject(ctx), IContentByteStream(ctx), alnsModule(nullptr), buffer(nullptr)
	{
	}
	void __construct_impl(HttpHeaderProcessor* httpRequest, AlinousModule* alnsModule, ThreadContext* ctx) throw() 
	{
	}
	virtual ~DirectModuleStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousModule* alnsModule;
	IArrayObjectPrimitive<char>* buffer;
public:
	int length(ThreadContext* ctx) throw()  final;
	void output(OutputStream* outStream, ThreadContext* ctx) final;
	void prepare(AlinousCore* core, bool debug, ThreadContext* ctx) final;
	String* getContentType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_DIRECTMODULESTREAM_H_ */
