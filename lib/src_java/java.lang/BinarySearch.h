#ifndef JAVA_LANG_BINARYSEARCH_H_
#define JAVA_LANG_BINARYSEARCH_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace lang {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class BinarySearch final : public virtual IObject {
public:
	BinarySearch(const BinarySearch& base) = default;
public:
	BinarySearch(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~BinarySearch() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static int binarySearchRange(String* data, wchar_t c, ThreadContext* ctx) throw() ;
	static int binarySearch(String* data, wchar_t value, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_LANG_BINARYSEARCH_H_ */
