#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_TABLES_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_TABLES_H_
namespace alinous {namespace system {namespace config {namespace remote {
class Table;}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {namespace remote {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::system::config::IAlinousConfigElement;



class Tables final : public IAlinousConfigElement, public virtual IObject {
public:
	Tables(const Tables& base) = default;
public:
	Tables(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), list(GCUtils<List<Table> >::ins(this, (new(ctx) ArrayList<Table>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Tables() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<Table>* list;
public:
	void addTable(Table* table, ThreadContext* ctx) throw() ;
	List<Table>* getList(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_TABLES_H_ */
