#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.analyse.tools/FunctionCallCollector.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse.tools/ClassMethodArgumentMatcher.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.analyse.tools/MatchingMethodCandidate.h"

namespace alinous {namespace compile {namespace analyse {namespace tools {





constexpr const int ClassMethodArgumentMatcher::DOM_MATCH;
constexpr const int ClassMethodArgumentMatcher::NULL_MATCH;
constexpr const int ClassMethodArgumentMatcher::WIDE_MATCH;
constexpr const int ClassMethodArgumentMatcher::EXT_CLASS_MATCH;
constexpr const int ClassMethodArgumentMatcher::STRICT_MATCH;
constexpr const int ClassMethodArgumentMatcher::NOT_MATCH;
bool ClassMethodArgumentMatcher::__init_done = __init_static_variables();
bool ClassMethodArgumentMatcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassMethodArgumentMatcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassMethodArgumentMatcher::ClassMethodArgumentMatcher(FunctionArguments* arguments, ArrayList<ClassMethodFunction>* methods, ThreadContext* ctx) throw()  : IObject(ctx), arguments(nullptr), methods(nullptr)
{
	__GC_MV(this, &(this->arguments), arguments, FunctionArguments);
	GCUtils<ArrayList<ClassMethodFunction> >::mv(this, &(this->methods), methods, ctx);
}
void ClassMethodArgumentMatcher::__construct_impl(FunctionArguments* arguments, ArrayList<ClassMethodFunction>* methods, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->arguments), arguments, FunctionArguments);
	GCUtils<ArrayList<ClassMethodFunction> >::mv(this, &(this->methods), methods, ctx);
}
 ClassMethodArgumentMatcher::~ClassMethodArgumentMatcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassMethodArgumentMatcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassMethodArgumentMatcher", L"~ClassMethodArgumentMatcher");
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	__e_obj1.add(this->methods, this);
	methods = nullptr;
	if(!prepare){
		return;
	}
}
MatchingMethodCandidate* ClassMethodArgumentMatcher::match(ThreadContext* ctx) throw() 
{
	if(this->methods->isEmpty(ctx))
	{
		return nullptr;
	}
	MatchingMethodCandidate* returnMethod = nullptr;
	int numArguments = this->arguments->getArgumentSize(ctx);
	int maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* method = this->methods->get(i, ctx);
		ArrayList<FunctionArgumentDefine>* argdefs = method->getArgumentsDefine(ctx);
		if(argdefs->size(ctx) != numArguments)
		{
			continue;
		}
		int score = matchArguments(argdefs, ctx);
		if(score < 0)
		{
			continue;
		}
		if(returnMethod == nullptr)
		{
			returnMethod = (new(ctx) MatchingMethodCandidate(method, score, ctx));
		}
				else 
		{
			if(score == returnMethod->getScore(ctx))
			{
				returnMethod->addSameScore(method, ctx);
			}
						else 
			{
				if(score > returnMethod->getScore(ctx))
				{
					returnMethod = (new(ctx) MatchingMethodCandidate(method, score, ctx));
				}
			}
		}
	}
	return returnMethod;
}
int ClassMethodArgumentMatcher::matchArguments(ArrayList<FunctionArgumentDefine>* argdefs, ThreadContext* ctx) throw() 
{
	ArrayList<IExpression>* list = this->arguments->arguments;
	int total = 0;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FunctionArgumentDefine* defarg = argdefs->get(i, ctx);
		AlinousType* actualType = list->get(i, ctx)->getSourceId(ctx)->getType(ctx);
		int sc = scoring(defarg, actualType, ctx);
		if(sc < 0)
		{
			return -1;
		}
		total += sc;
	}
	return total;
}
int ClassMethodArgumentMatcher::scoring(FunctionArgumentDefine* defarg, AlinousType* actualType, ThreadContext* ctx) throw() 
{
	AlinousType* defType = defarg->getAnalysedType(ctx);
	switch(defType->getTypeClass(ctx)) {
	case AlinousType::TYPE_PRIMITIVE:
		if(actualType->getTypeClass(ctx) != AlinousType::TYPE_PRIMITIVE)
		{
			return NOT_MATCH;
		}
		return scorePrmitive(defType, actualType, ctx);
	case AlinousType::TYPE_STANDARD_OBJ:
		if(actualType->getTypeClass(ctx) != AlinousType::TYPE_STANDARD_OBJ)
		{
			return NOT_MATCH;
		}
		if(actualType->getType(ctx) == defType->getType(ctx))
		{
			return STRICT_MATCH;
		}
		break ;
	case AlinousType::TYPE_CLASS_OBJ:
		if(actualType->getTypeClass(ctx) != AlinousType::TYPE_CLASS_OBJ)
		{
			return NOT_MATCH;
		}
		return scoreObjects(defType->getClazz(ctx), actualType->getClazz(ctx), ctx);
	case AlinousType::TYPE_DOM:
	default:
		return DOM_MATCH;
		break;
	}
	return NOT_MATCH;
}
int ClassMethodArgumentMatcher::scoreObjects(AlinousClass* defType, AlinousClass* actualType, ThreadContext* ctx) throw() 
{
	if(actualType->equals(defType, ctx))
	{
		return STRICT_MATCH;
	}
	if(actualType->hasBaseClass(defType, ctx))
	{
		return EXT_CLASS_MATCH;
	}
	return NOT_MATCH;
}
int ClassMethodArgumentMatcher::scorePrmitive(AlinousType* defType, AlinousType* actualType, ThreadContext* ctx) throw() 
{
	switch(defType->getType(ctx)) {
	case AlinousType::NULL_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
		case AlinousType::BYTE_TYPE:
		case AlinousType::SHORT_TYPE:
		case AlinousType::CHAR_TYPE:
		case AlinousType::INT_TYPE:
		case AlinousType::LONG_TYPE:
		case AlinousType::FLOAT_TYPE:
		case AlinousType::DOUBLE_TYPE:
		default:
			break ;
		}
		break ;
	case AlinousType::BOOL_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::BOOL_TYPE:
			return STRICT_MATCH;
		case AlinousType::BYTE_TYPE:
		case AlinousType::SHORT_TYPE:
		case AlinousType::CHAR_TYPE:
		case AlinousType::INT_TYPE:
		case AlinousType::LONG_TYPE:
		case AlinousType::FLOAT_TYPE:
		case AlinousType::DOUBLE_TYPE:
		case AlinousType::NULL_TYPE:
		default:
			break ;
		}
		break ;
	case AlinousType::BYTE_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
			break ;
		case AlinousType::BYTE_TYPE:
			return STRICT_MATCH;
		case AlinousType::SHORT_TYPE:
		case AlinousType::CHAR_TYPE:
		case AlinousType::INT_TYPE:
		case AlinousType::LONG_TYPE:
		case AlinousType::FLOAT_TYPE:
		case AlinousType::DOUBLE_TYPE:
		default:
			break ;
		}
	case AlinousType::SHORT_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
			break ;
		case AlinousType::BYTE_TYPE:
			return WIDE_MATCH;
		case AlinousType::SHORT_TYPE:
			return STRICT_MATCH;
		case AlinousType::CHAR_TYPE:
		case AlinousType::INT_TYPE:
		case AlinousType::LONG_TYPE:
		case AlinousType::FLOAT_TYPE:
		case AlinousType::DOUBLE_TYPE:
		default:
			break ;
		}
	case AlinousType::CHAR_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
			break ;
		case AlinousType::BYTE_TYPE:
		case AlinousType::SHORT_TYPE:
			return WIDE_MATCH;
		case AlinousType::CHAR_TYPE:
			return STRICT_MATCH;
		case AlinousType::INT_TYPE:
			return WIDE_MATCH;
		case AlinousType::LONG_TYPE:
		case AlinousType::FLOAT_TYPE:
		case AlinousType::DOUBLE_TYPE:
		default:
			break ;
		}
	case AlinousType::INT_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
			break ;
		case AlinousType::BYTE_TYPE:
		case AlinousType::SHORT_TYPE:
		case AlinousType::CHAR_TYPE:
			return WIDE_MATCH;
		case AlinousType::INT_TYPE:
			return STRICT_MATCH;
		case AlinousType::LONG_TYPE:
		case AlinousType::FLOAT_TYPE:
		case AlinousType::DOUBLE_TYPE:
		default:
			break ;
		}
	case AlinousType::LONG_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
			break ;
		case AlinousType::BYTE_TYPE:
		case AlinousType::SHORT_TYPE:
		case AlinousType::CHAR_TYPE:
		case AlinousType::INT_TYPE:
			return WIDE_MATCH;
		case AlinousType::LONG_TYPE:
			return STRICT_MATCH;
		case AlinousType::FLOAT_TYPE:
		case AlinousType::DOUBLE_TYPE:
		default:
			break ;
		}
	case AlinousType::FLOAT_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
			break ;
		case AlinousType::BYTE_TYPE:
		case AlinousType::SHORT_TYPE:
		case AlinousType::CHAR_TYPE:
		case AlinousType::INT_TYPE:
		case AlinousType::LONG_TYPE:
			return WIDE_MATCH;
		case AlinousType::FLOAT_TYPE:
			return STRICT_MATCH;
		case AlinousType::DOUBLE_TYPE:
		default:
			break ;
		}
	case AlinousType::DOUBLE_TYPE:
		switch(actualType->getType(ctx)) {
		case AlinousType::NULL_TYPE:
			break ;
		case AlinousType::BOOL_TYPE:
			break ;
		case AlinousType::BYTE_TYPE:
		case AlinousType::SHORT_TYPE:
		case AlinousType::CHAR_TYPE:
		case AlinousType::INT_TYPE:
		case AlinousType::LONG_TYPE:
		case AlinousType::FLOAT_TYPE:
			return WIDE_MATCH;
		case AlinousType::DOUBLE_TYPE:
			return STRICT_MATCH;
		default:
			break ;
		}
	default:
		break ;
	}
	return NOT_MATCH;
}
void ClassMethodArgumentMatcher::__cleanUp(ThreadContext* ctx){
}
}}}}

