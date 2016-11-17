#ifndef ALINOUS_COMPILE_SQL_FUNCTIONS_SQLFUNCTIONMANAGER_H_
#define ALINOUS_COMPILE_SQL_FUNCTIONS_SQLFUNCTIONMANAGER_H_
namespace alinous {namespace compile {namespace sql {namespace functions {
class Count;}}}}

namespace alinous {namespace compile {namespace sql {namespace functions {
class Coalesce;}}}}

namespace alinous {namespace compile {namespace sql {namespace functions {
class ToNumber;}}}}

namespace alinous {namespace compile {namespace sql {namespace functions {
class ISQLFunctionBody;}}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace functions {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;



class SQLFunctionManager final : public virtual IObject {
public:
	SQLFunctionManager(const SQLFunctionManager& base) = default;
public:
	SQLFunctionManager(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~SQLFunctionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,ISQLFunctionBody>* functions;
public:
	ISQLFunctionBody* getFunction(String* name, ThreadContext* ctx) throw() ;
private:
	void registerFunction(ISQLFunctionBody* func, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_FUNCTIONS_SQLFUNCTIONMANAGER_H_ */
