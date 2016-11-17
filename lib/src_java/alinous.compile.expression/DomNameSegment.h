#ifndef ALINOUS_COMPILE_EXPRESSION_DOMNAMESEGMENT_H_
#define ALINOUS_COMPILE_EXPRESSION_DOMNAMESEGMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {
class Token;}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::Token;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;



class DomNameSegment final : public IDomSegment {
public:
	DomNameSegment(const DomNameSegment& base) = default;
public:
	DomNameSegment(ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), name(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	DomNameSegment(String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ThreadContext* ctx) throw() ;
	virtual ~DomNameSegment() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	int segmentVariableType;
public:
	String* toString(ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw()  final;
	void setName(String* name, ThreadContext* ctx) throw() ;
	int getDomSegmentType(ThreadContext* ctx) throw()  final;
	IExpression* getIndex(ThreadContext* ctx) final;
	int getSegmentVariableType(ThreadContext* ctx) throw()  final;
	void setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void position(Token* t2, AbstractSrcElement* segment, ThreadContext* ctx) throw()  final;
	void position(Token* start, Token* end, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_DOMNAMESEGMENT_H_ */
