#ifndef ALINOUS_DB_TABLE_IBTREETABLEINDEX_H_
#define ALINOUS_DB_TABLE_IBTREETABLEINDEX_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class IBtreeTableIndex : public virtual IObject {
public:
	IBtreeTableIndex(const IBtreeTableIndex& base) = default;
public:
	IBtreeTableIndex(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IBtreeTableIndex() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual ArrayList<TableColumnMetadata>* getColumns(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_IBTREETABLEINDEX_H_ */
