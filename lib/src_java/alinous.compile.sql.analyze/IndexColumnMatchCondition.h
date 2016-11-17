#ifndef ALINOUS_COMPILE_SQL_ANALYZE_INDEXCOLUMNMATCHCONDITION_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_INDEXCOLUMNMATCHCONDITION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

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
using ::alinous::compile::sql::expression::ISQLExpression;



class IndexColumnMatchCondition final : public virtual IObject {
public:
	IndexColumnMatchCondition(const IndexColumnMatchCondition& base) = default;
public:
	IndexColumnMatchCondition(ScanTableColumnIdentifier* columnIdentifier, int matchMode, ISQLExpression* start, ISQLExpression* end, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableColumnIdentifier* columnIdentifier, int matchMode, ISQLExpression* start, ISQLExpression* end, ThreadContext* ctx) throw() ;
	IndexColumnMatchCondition(ScanTableColumnIdentifier* columnIdentifier, ArrayList<ISQLExpression>* explist, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableColumnIdentifier* columnIdentifier, ArrayList<ISQLExpression>* explist, ThreadContext* ctx) throw() ;
	virtual ~IndexColumnMatchCondition() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int indexType;
	int matchMode;
	ScanTableColumnIdentifier* columnIdentifier;
	ISQLExpression* start;
	bool startEq;
	ISQLExpression* end;
	bool endEq;
	ArrayList<ISQLExpression>* explist;
	ScanTableIndexMetadata* indexMetadata;
public:
	constexpr static const int INDEX_NONE{0};
	constexpr static const int INDEX_NORMAL{1};
	constexpr static const int INDEX_FULL_TEXT{2};
	constexpr static const int FULL_SCAN{0};
	constexpr static const int INDEX_EQUALS{1};
	constexpr static const int INDEX_BEFORE{2};
	constexpr static const int INDEX_AFTER{4};
	constexpr static const int INDEX_RANGE{6};
	constexpr static const int INDEX_IN{7};
public:
	int indexEficience(ThreadContext* ctx) throw() ;
	int getMatchMode(ThreadContext* ctx) throw() ;
	void setMatchMode(int matchMode, ThreadContext* ctx) throw() ;
	ISQLExpression* getStart(ThreadContext* ctx) throw() ;
	void setStart(ISQLExpression* start, ThreadContext* ctx) throw() ;
	bool isStartEq(ThreadContext* ctx) throw() ;
	void setStartEq(bool startEq, ThreadContext* ctx) throw() ;
	ISQLExpression* getEnd(ThreadContext* ctx) throw() ;
	void setEnd(ISQLExpression* end, ThreadContext* ctx) throw() ;
	bool isEndEq(ThreadContext* ctx) throw() ;
	void setEndEq(bool endEq, ThreadContext* ctx) throw() ;
	ArrayList<ISQLExpression>* getExplist(ThreadContext* ctx) throw() ;
	void setExplist(ArrayList<ISQLExpression>* explist, ThreadContext* ctx) throw() ;
	int getIndexType(ThreadContext* ctx) throw() ;
	ScanTableColumnIdentifier* getColumnIdentifier(ThreadContext* ctx) throw() ;
	bool validateStrategy(ScanTableMetadata* metadata, ThreadContext* ctx) throw() ;
	ScanTableIndexMetadata* getIndexMetadata(ThreadContext* ctx) throw() ;
	void setIndexMetadata(ScanTableIndexMetadata* indexMetadata, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_INDEXCOLUMNMATCHCONDITION_H_ */
