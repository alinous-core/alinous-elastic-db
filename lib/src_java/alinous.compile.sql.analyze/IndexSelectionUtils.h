#ifndef ALINOUS_COMPILE_SQL_ANALYZE_INDEXSELECTIONUTILS_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_INDEXSELECTIONUTILS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

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
using ::java::util::ArrayList;



class IndexSelectionUtils final : public virtual IObject {
public:
	IndexSelectionUtils(const IndexSelectionUtils& base) = default;
public:
	IndexSelectionUtils(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IndexSelectionUtils() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static ScanTableIndexMetadata* getMinimumColumnIndexMetadata(ArrayList<ScanTableIndexMetadata>* abindexes, ThreadContext* ctx) throw() ;
	static ScanTableIndexMetadata* selectIndex(ArrayList<ScanTableColumnIdentifier>* columnIdentifiers, ArrayList<ScanTableIndexMetadata>* abindexes, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_INDEXSELECTIONUTILS_H_ */
