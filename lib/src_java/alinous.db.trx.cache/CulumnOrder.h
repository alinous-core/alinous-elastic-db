#ifndef ALINOUS_DB_TRX_CACHE_CULUMNORDER_H_
#define ALINOUS_DB_TRX_CACHE_CULUMNORDER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace cache {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class CulumnOrder final : public virtual IObject {
public:
	CulumnOrder(const CulumnOrder& base) = default;
public:
	CulumnOrder(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CulumnOrder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int valuesOrder;
	int columnOrder;
	String* columnName;
public:
	String* getColumnName(ThreadContext* ctx) throw() ;
	void setColumnName(String* columnName, ThreadContext* ctx) throw() ;
	void setValuesOrder(int valuesOrder, ThreadContext* ctx) throw() ;
	void setColumnOrder(int columnOrder, ThreadContext* ctx) throw() ;
	int getValuesOrder(ThreadContext* ctx) throw() ;
	int getColumnOrder(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_CULUMNORDER_H_ */
