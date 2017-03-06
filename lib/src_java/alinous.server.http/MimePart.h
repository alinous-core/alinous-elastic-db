#ifndef ALINOUS_SERVER_HTTP_MIMEPART_H_
#define ALINOUS_SERVER_HTTP_MIMEPART_H_
namespace alinous {namespace server {namespace http {
class MimeHeader;}}}

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
using ::java::util::ArrayList;



class MimePart final : public virtual IObject {
public:
	MimePart(const MimePart& base) = default;
public:
	MimePart(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~MimePart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* rawData;
private:
	ArrayList<MimeHeader>* headers;
	MimeHeader* descHeader;
	MimeHeader* contentType;
public:
	void addHeader(MimeHeader* header, ThreadContext* ctx) throw() ;
	bool isFormText(ThreadContext* ctx) throw() ;
	MimeHeader* getDescHeader(ThreadContext* ctx) throw() ;
	MimeHeader* getContentType(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_MIMEPART_H_ */
