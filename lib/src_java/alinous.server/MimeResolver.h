#ifndef ALINOUS_SERVER_MIMERESOLVER_H_
#define ALINOUS_SERVER_MIMERESOLVER_H_
namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::HashMap;



class MimeResolver final : public virtual IObject {
public:
	MimeResolver(const MimeResolver& base) = default;
public:
	MimeResolver(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~MimeResolver() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,String>* map;
public:
	String* getContentType(String* ext, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_SERVER_MIMERESOLVER_H_ */
