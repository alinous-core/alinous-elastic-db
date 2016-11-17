#ifndef ALINOUS_COMPILE_INCLUDEPREPROCESSOR_H_
#define ALINOUS_COMPILE_INCLUDEPREPROCESSOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AlinousSrc;}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::Literal;
using ::alinous::runtime::AlinousModule;



class IncludePreprocessor final : public IAlinousElement {
public:
	IncludePreprocessor(const IncludePreprocessor& base) = default;
public:
	IncludePreprocessor(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), path(nullptr), module(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IncludePreprocessor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Literal* path;
	AlinousModule* module;
public:
	void setPath(Literal* path, ThreadContext* ctx) throw() ;
	String* getPath(ThreadContext* ctx) throw() ;
	bool analyseDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	AlinousModule* getModule(ThreadContext* ctx) throw() ;
	void setModule(AlinousModule* module, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AlinousSrc* alinousSrc, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_INCLUDEPREPROCESSOR_H_ */
