#ifndef ALINOUS_SERVER_HTTP_MIMEHEADER_H_
#define ALINOUS_SERVER_HTTP_MIMEHEADER_H_
namespace alinous {namespace server {namespace http {
class MimeHeader;}}}

namespace java {namespace io {
class IOException;}}

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
using ::java::util::ArrayList;



class MimeHeader final : public virtual IObject {
public:
	MimeHeader(const MimeHeader& base) = default;
public:
	MimeHeader(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~MimeHeader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int headerType;
	String* headerName;
	String* name;
	String* filename;
	String* contentType;
public:
	constexpr static const int TYPE_CONTENT_DESCRIPTION{0};
	constexpr static const int TYPE_CONTENT_TYPE{1};
	static String* CONTENT_DESCRIPTION;
	static String* CONTENT_TYPE;
public:
	MimeHeader* init(String* line, ThreadContext* ctx);
	int getHeaderType(ThreadContext* ctx) throw() ;
	String* getHeaderName(ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	String* getFilename(ThreadContext* ctx) throw() ;
	String* getContentType(ThreadContext* ctx) throw() ;
private:
	void parseContentDescription(String* value, ThreadContext* ctx);
	String* stripQuate(String* value, ThreadContext* ctx) throw() ;
	String* afterEq(String* value, ThreadContext* ctx);
	ArrayList<String>* split(String* str, wchar_t ch, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_MIMEHEADER_H_ */
