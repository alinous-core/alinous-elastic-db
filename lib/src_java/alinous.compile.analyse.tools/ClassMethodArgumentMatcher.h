#ifndef ALINOUS_COMPILE_ANALYSE_TOOLS_CLASSMETHODARGUMENTMATCHER_H_
#define ALINOUS_COMPILE_ANALYSE_TOOLS_CLASSMETHODARGUMENTMATCHER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace analyse {namespace tools {
class MatchingMethodCandidate;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {namespace tools {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::ClassMethodFunction;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::expression::FunctionArguments;
using ::alinous::compile::expression::IExpression;



class ClassMethodArgumentMatcher final : public virtual IObject {
public:
	ClassMethodArgumentMatcher(const ClassMethodArgumentMatcher& base) = default;
public:
	ClassMethodArgumentMatcher(FunctionArguments* arguments, ArrayList<ClassMethodFunction>* methods, ThreadContext* ctx) throw() ;
	void __construct_impl(FunctionArguments* arguments, ArrayList<ClassMethodFunction>* methods, ThreadContext* ctx) throw() ;
	virtual ~ClassMethodArgumentMatcher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	FunctionArguments* arguments;
	ArrayList<ClassMethodFunction>* methods;
public:
	constexpr static const int DOM_MATCH{1};
	constexpr static const int NULL_MATCH{1};
	constexpr static const int WIDE_MATCH{3};
	constexpr static const int EXT_CLASS_MATCH{5};
	constexpr static const int STRICT_MATCH{10};
	constexpr static const int NOT_MATCH{-999999};
public:
	MatchingMethodCandidate* match(ThreadContext* ctx) throw() ;
private:
	int matchArguments(ArrayList<FunctionArgumentDefine>* argdefs, ThreadContext* ctx) throw() ;
	int scoring(FunctionArgumentDefine* defarg, AlinousType* actualType, ThreadContext* ctx) throw() ;
	int scoreObjects(AlinousClass* defType, AlinousClass* actualType, ThreadContext* ctx) throw() ;
	int scorePrmitive(AlinousType* defType, AlinousType* actualType, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_TOOLS_CLASSMETHODARGUMENTMATCHER_H_ */
