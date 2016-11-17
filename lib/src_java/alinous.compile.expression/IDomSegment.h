#ifndef ALINOUS_COMPILE_EXPRESSION_IDOMSEGMENT_H_
#define ALINOUS_COMPILE_EXPRESSION_IDOMSEGMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::IAlinousElement;
using ::alinous::runtime::dom::VariableException;



class IDomSegment : public IAlinousElement {
public:
	IDomSegment(const IDomSegment& base) = default;
public:
	IDomSegment(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDomSegment() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_NORMAL{0};
	constexpr static const int TYPE_INDEX{1};
public:
	virtual int getDomSegmentType(ThreadContext* ctx) throw()  = 0;
	virtual IExpression* getIndex(ThreadContext* ctx) = 0;
	virtual String* getName(ThreadContext* ctx) = 0;
	virtual int getSegmentVariableType(ThreadContext* ctx) throw()  = 0;
	virtual void setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_IDOMSEGMENT_H_ */
