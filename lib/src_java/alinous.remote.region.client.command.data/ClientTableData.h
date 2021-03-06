#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTTABLEDATA_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTTABLEDATA_H_
namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class ClientTableData final : public ICommandData, public virtual IObject {
public:
	ClientTableData(const ClientTableData& base) = default;
public:
	ClientTableData(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	ClientTableData(String* name, TableMetadata* metadata, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, TableMetadata* metadata, ThreadContext* ctx) throw() ;
	virtual ~ClientTableData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	TableMetadata* metadata;
public:
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	TableMetadata* getMetadata(ThreadContext* ctx) throw() ;
	void setMetadata(TableMetadata* metadata, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTTABLEDATA_H_ */
