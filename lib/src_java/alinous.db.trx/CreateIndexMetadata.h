#ifndef ALINOUS_DB_TRX_CREATEINDEXMETADATA_H_
#define ALINOUS_DB_TRX_CREATEINDEXMETADATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::sql::TableAndSchema;



class CreateIndexMetadata final : public virtual IObject {
public:
	CreateIndexMetadata(const CreateIndexMetadata& base) = default;
public:
	CreateIndexMetadata(String* indexName, TableAndSchema* tas, ArrayList<String>* columns, ThreadContext* ctx) throw() ;
	void __construct_impl(String* indexName, TableAndSchema* tas, ArrayList<String>* columns, ThreadContext* ctx) throw() ;
	virtual ~CreateIndexMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* indexName;
	TableAndSchema* tas;
	ArrayList<String>* columns;
public:
	String* getindexName(ThreadContext* ctx) throw() ;
	TableAndSchema* getTas(ThreadContext* ctx) throw() ;
	ArrayList<String>* getColumns(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TRX_CREATEINDEXMETADATA_H_ */
