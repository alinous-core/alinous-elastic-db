#ifndef ALINOUS_COMPILE_DECLARE_ICLASSMEMBER_H_
#define ALINOUS_COMPILE_DECLARE_ICLASSMEMBER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IClassMember : public IDeclare {
public:
	IClassMember(const IClassMember& base) = default;
public:
	IClassMember(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IClassMember() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int CLASS_METHOD{1};
	constexpr static const int CLASS_VARIABLE{2};
	constexpr static const int STATIC_CLASS_METHOD{3};
	constexpr static const int STATIC_CLASS_VARIABLE{4};
public:
	virtual int getMemberType(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_ICLASSMEMBER_H_ */
