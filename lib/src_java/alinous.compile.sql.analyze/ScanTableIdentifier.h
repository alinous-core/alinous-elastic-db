#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEIDENTIFIER_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEIDENTIFIER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::runtime::dom::VariableException;



class ScanTableIdentifier final : public virtual IObject {
public:
	ScanTableIdentifier(const ScanTableIdentifier& base) = default;
public:
	ScanTableIdentifier(TableAndSchema* table, String* asName, int numColmuns, ThreadContext* ctx) throw() ;
	void __construct_impl(TableAndSchema* table, String* asName, int numColmuns, ThreadContext* ctx) throw() ;
	virtual ~ScanTableIdentifier() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TableAndSchema* table;
	String* asName;
	int numColmuns;
public:
	ScanTableIdentifier* copy(ThreadContext* ctx) throw() ;
	bool equals(String* asName, ThreadContext* ctx) throw() ;
	bool equals(ScanTableIdentifier* other, ThreadContext* ctx) throw() ;
	int getArchiveSize(ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	String* toString(ThreadContext* ctx) throw() ;
	TableAndSchema* getTable(ThreadContext* ctx) throw() ;
	void setTable(TableAndSchema* table, ThreadContext* ctx) throw() ;
	String* getAsName(ThreadContext* ctx) throw() ;
	void setAsName(String* asName, ThreadContext* ctx) throw() ;
	int getNumColmuns(ThreadContext* ctx) throw() ;
public:
	static ScanTableIdentifier* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEIDENTIFIER_H_ */
