#ifndef ALINOUS_LOCK_CRITICALSECTIONMARKEREXCEPTION_H_
#define ALINOUS_LOCK_CRITICALSECTIONMARKEREXCEPTION_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class CriticalSectionMarkerException final : public Throwable {
public:
	CriticalSectionMarkerException(const CriticalSectionMarkerException& base) = default;
public:
	CriticalSectionMarkerException(String* string, ThreadContext* ctx) throw() ;
	void __construct_impl(String* string, ThreadContext* ctx) throw() ;
	virtual ~CriticalSectionMarkerException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{1L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_LOCK_CRITICALSECTIONMARKEREXCEPTION_H_ */
