#ifndef ALINOUS_RUNTIME_ENGINE_DATABASEHANDLE_H_
#define ALINOUS_RUNTIME_ENGINE_DATABASEHANDLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseConnection;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dbif::IDatabaseConnection;
using ::alinous::runtime::dbif::IDatabaseDriver;



class DatabaseHandle final : public virtual IObject {
public:
	DatabaseHandle(const DatabaseHandle& base) = default;
public:
	DatabaseHandle(IDatabaseDriver* dbdriver, IDatabaseConnection* con, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseDriver* dbdriver, IDatabaseConnection* con, ThreadContext* ctx) throw() ;
	virtual ~DatabaseHandle() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IDatabaseDriver* dbdriver;
	IDatabaseConnection* con;
public:
	IDatabaseDriver* getDbdriver(ThreadContext* ctx) throw() ;
	void setDbdriver(IDatabaseDriver* dbdriver, ThreadContext* ctx) throw() ;
	IDatabaseConnection* getCon(ThreadContext* ctx) throw() ;
	void setCon(IDatabaseConnection* con, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DATABASEHANDLE_H_ */
