#ifndef ALINOUS_SERVER_WEBMODULE_WEBMODULEHASHLIST_H_
#define ALINOUS_SERVER_WEBMODULE_WEBMODULEHASHLIST_H_
namespace alinous {namespace server {namespace webmodule {
class WebModuleHashList;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace server {namespace webmodule {
class WebModuleList;}}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace server {namespace webmodule {
class AbstractWebModule;}}}

namespace java {namespace util {
class BitSet;}}

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
using ::java::util::BitSet;
using ::alinous::buffer::FifoElement;
using ::alinous::system::AlinousException;



class WebModuleHashList final : public virtual IObject {
public:
	WebModuleHashList(const WebModuleHashList& base) = default;
public:
	WebModuleHashList(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~WebModuleHashList() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int MAX_HASH;
	int MAX_HASH_MASK;
private:
	IArrayObject<WebModuleList>* arrays;
	BitSet* bitset;
	int numElements;
public:
	WebModuleHashList* init(int MAX_HASH, ThreadContext* ctx);
	int size(ThreadContext* ctx) throw() ;
	void add(FifoElement<AbstractWebModule>* module, ThreadContext* ctx) throw() ;
	FifoElement<AbstractWebModule>* find(String* path, ThreadContext* ctx) throw() ;
	void remove(String* path, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_WEBMODULEHASHLIST_H_ */
