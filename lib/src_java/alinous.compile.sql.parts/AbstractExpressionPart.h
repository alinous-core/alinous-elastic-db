#ifndef ALINOUS_COMPILE_SQL_PARTS_ABSTRACTEXPRESSIONPART_H_
#define ALINOUS_COMPILE_SQL_PARTS_ABSTRACTEXPRESSIONPART_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class ISQLExpressionPart;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace parts {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;



class AbstractExpressionPart : public ISQLExpressionPart {
public:
	AbstractExpressionPart(const AbstractExpressionPart& base) = default;
public:
	AbstractExpressionPart(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractExpressionPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_PARTS_ABSTRACTEXPRESSIONPART_H_ */
