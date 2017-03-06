#ifndef ALINOUS_SERVER_CONTENTRESULT_H_
#define ALINOUS_SERVER_CONTENTRESULT_H_
namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace alinous {namespace server {
class MimeResolver;}}

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
using ::alinous::server::http::IContentByteStream;



class ContentResult final : public virtual IObject {
public:
	ContentResult(const ContentResult& base) = default;
public:
	ContentResult(IContentByteStream* byteData, String* ext, MimeResolver* mimeResolver, bool head, ThreadContext* ctx) throw() ;
	void __construct_impl(IContentByteStream* byteData, String* ext, MimeResolver* mimeResolver, bool head, ThreadContext* ctx) throw() ;
	virtual ~ContentResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IContentByteStream* byteDataStream;
	bool head;
private:
	String* contentType;
public:
	String* getContentType(ThreadContext* ctx) throw() ;
	IContentByteStream* getByteDataStream(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_SERVER_CONTENTRESULT_H_ */
