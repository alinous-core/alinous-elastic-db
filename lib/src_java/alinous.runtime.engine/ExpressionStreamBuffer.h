#ifndef ALINOUS_RUNTIME_ENGINE_EXPRESSIONSTREAMBUFFER_H_
#define ALINOUS_RUNTIME_ENGINE_EXPRESSIONSTREAMBUFFER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dom::IAlinousVariable;



class ExpressionStreamBuffer final : public virtual IObject {
public:
	ExpressionStreamBuffer(const ExpressionStreamBuffer& base) = default;
public:
	ExpressionStreamBuffer(ThreadContext* ctx) throw()  : IObject(ctx), streamLastValue(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ExpressionStreamBuffer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IAlinousVariable* streamLastValue;
public:
	IAlinousVariable* getStreamLastValue(ThreadContext* ctx) throw() ;
	void setStreamLastValue(IAlinousVariable* streamLastValue, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_EXPRESSIONSTREAMBUFFER_H_ */
