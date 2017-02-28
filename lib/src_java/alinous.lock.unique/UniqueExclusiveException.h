#ifndef ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVEEXCEPTION_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVEEXCEPTION_H_
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {namespace unique {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDbException;



class UniqueExclusiveException final : public AlinousDbException {
public:
	UniqueExclusiveException(const UniqueExclusiveException& base) = default;
public:
	UniqueExclusiveException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	UniqueExclusiveException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	virtual ~UniqueExclusiveException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{3865788543780367926L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVEEXCEPTION_H_ */
