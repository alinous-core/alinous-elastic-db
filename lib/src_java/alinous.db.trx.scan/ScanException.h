#ifndef ALINOUS_DB_TRX_SCAN_SCANEXCEPTION_H_
#define ALINOUS_DB_TRX_SCAN_SCANEXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::DatabaseException;



class ScanException final : public DatabaseException {
public:
	ScanException(const ScanException& base) = default;
public:
	ScanException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	ScanException(String* msg, Throwable* cause, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* cause, ThreadContext* ctx) throw() ;
	ScanException(Throwable* cause, ThreadContext* ctx) throw() ;
	void __construct_impl(Throwable* cause, ThreadContext* ctx) throw() ;
	virtual ~ScanException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{1L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_SCANEXCEPTION_H_ */
