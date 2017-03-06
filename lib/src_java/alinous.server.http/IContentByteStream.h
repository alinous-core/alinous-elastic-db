#ifndef ALINOUS_SERVER_HTTP_ICONTENTBYTESTREAM_H_
#define ALINOUS_SERVER_HTTP_ICONTENTBYTESTREAM_H_
namespace alinous {namespace system {
class AlinousCore;}}

namespace java {namespace io {
class OutputStream;}}

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

namespace alinous {namespace server {namespace http {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::OutputStream;
using ::alinous::db::table::DatabaseException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class IContentByteStream : public virtual IObject {
public:
	IContentByteStream(const IContentByteStream& base) = default;
public:
	IContentByteStream(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IContentByteStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void prepare(AlinousCore* core, bool debug, ThreadContext* ctx) = 0;
	virtual int length(ThreadContext* ctx) throw()  = 0;
	virtual void output(OutputStream* outStream, ThreadContext* ctx) = 0;
	virtual String* getContentType(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_ICONTENTBYTESTREAM_H_ */
