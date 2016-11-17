#ifndef ALINOUS_LOCK_CRITICALSECTIONMARKER_H_
#define ALINOUS_LOCK_CRITICALSECTIONMARKER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace lock {
class CriticalSectionMarkerException;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class CriticalSectionMarker final : public virtual IObject {
public:
	CriticalSectionMarker(const CriticalSectionMarker& base) = default;
public:
	CriticalSectionMarker(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CriticalSectionMarker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool critical;
	LockObject* lock;
public:
	void enter(ThreadContext* ctx);
	void exit(ThreadContext* ctx);
	void checkCritical(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_LOCK_CRITICALSECTIONMARKER_H_ */
