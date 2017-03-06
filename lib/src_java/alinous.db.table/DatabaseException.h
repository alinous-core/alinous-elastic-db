#ifndef ALINOUS_DB_TABLE_DATABASEEXCEPTION_H_
#define ALINOUS_DB_TABLE_DATABASEEXCEPTION_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class DatabaseException : public Throwable {
public:
	DatabaseException(const DatabaseException& base) = default;
public:
	DatabaseException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	DatabaseException(String* msg, Throwable* cause, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* cause, ThreadContext* ctx) throw() ;
	DatabaseException(Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~DatabaseException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{1L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATABASEEXCEPTION_H_ */
