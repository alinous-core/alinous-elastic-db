#ifndef ALINOUS_COMPILE_SQL_ANALYZE_JOINMATCHEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_JOINMATCHEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLEqualityExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

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
using ::alinous::compile::sql::expression::blexp::SQLEqualityExpression;



class JoinMatchExpression final : public virtual IObject {
public:
	JoinMatchExpression(const JoinMatchExpression& base) = default;
public:
	JoinMatchExpression(SQLEqualityExpression* exp, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw() ;
	void __construct_impl(SQLEqualityExpression* exp, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw() ;
	virtual ~JoinMatchExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	SQLEqualityExpression* exp;
	ScanTableMetadata* leftMetadata;
	ScanTableMetadata* rightMetadata;
	ScanTableColumnIdentifier* leftColumn;
	ScanTableColumnIdentifier* rightColumn;
	ScanTableIndexMetadata* leftIndex;
	ScanTableIndexMetadata* rightIndex;
	int indexStatus;
public:
	constexpr static const int NO_INDEX{0};
	constexpr static const int LEFT_INDEX{1};
	constexpr static const int RIGHT_INDEX{2};
	constexpr static const int BOTH_INDEX{3};
public:
	bool validate(ThreadContext* ctx) throw() ;
	SQLEqualityExpression* getExp(ThreadContext* ctx) throw() ;
	void setExp(SQLEqualityExpression* exp, ThreadContext* ctx) throw() ;
	ScanTableMetadata* getLeftMetadata(ThreadContext* ctx) throw() ;
	void setLeftMetadata(ScanTableMetadata* leftMetadata, ThreadContext* ctx) throw() ;
	ScanTableMetadata* getRightMetadata(ThreadContext* ctx) throw() ;
	void setRightMetadata(ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw() ;
	int getIndexStatus(ThreadContext* ctx) throw() ;
	ScanTableIndexMetadata* getLeftIndex(ThreadContext* ctx) throw() ;
	ScanTableIndexMetadata* getRightIndex(ThreadContext* ctx) throw() ;
	void setLeftIndex(ScanTableIndexMetadata* leftIndex, ThreadContext* ctx) throw() ;
	void setRightIndex(ScanTableIndexMetadata* rightIndex, ThreadContext* ctx) throw() ;
	ScanTableColumnIdentifier* getLeftColumn(ThreadContext* ctx) throw() ;
	ScanTableColumnIdentifier* getRightColumn(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_JOINMATCHEXPRESSION_H_ */
