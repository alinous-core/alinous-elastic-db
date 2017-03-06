#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DATABASELOCKEXCEPTION_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DATABASELOCKEXCEPTION_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace lockmonitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::DatabaseException;



class DatabaseLockException final : public DatabaseException {
public:
	DatabaseLockException(const DatabaseLockException& base) = default;
public:
	DatabaseLockException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	DatabaseLockException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~DatabaseLockException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{6351453564588530899L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DATABASELOCKEXCEPTION_H_ */
