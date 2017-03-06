#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression/IExpressionFactory.h"

namespace alinous {namespace compile {namespace expression {





bool DomIndexSegment::__init_done = __init_static_variables();
bool DomIndexSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomIndexSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomIndexSegment::DomIndexSegment(ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), index(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
{
}
void DomIndexSegment::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DomIndexSegment::DomIndexSegment(IExpression* index, ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), index(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
{
	__GC_MV(this, &(this->index), index, IExpression);
}
void DomIndexSegment::__construct_impl(IExpression* index, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->index), index, IExpression);
}
 DomIndexSegment::~DomIndexSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomIndexSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomIndexSegment", L"~DomIndexSegment");
	__e_obj1.add(this->index, this);
	index = nullptr;
	if(!prepare){
		return;
	}
	IDomSegment::__releaseRegerences(true, ctx);
}
String* DomIndexSegment::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_1000(), ctx)->append(ConstStr::getCNST_STR_564(), ctx);
	return buff->toString(ctx);
}
IExpression* DomIndexSegment::getIndex(ThreadContext* ctx) throw() 
{
	return this->index;
}
void DomIndexSegment::setIndex(IExpression* index, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->index), index, IExpression);
}
int DomIndexSegment::getDomSegmentType(ThreadContext* ctx) throw() 
{
	return IDomSegment::TYPE_INDEX;
}
String* DomIndexSegment::getName(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomIndexSegment::getSegmentVariableType(ThreadContext* ctx) throw() 
{
	return this->segmentVariableType;
}
void DomIndexSegment::setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw() 
{
	this->segmentVariableType = segmentVariableType;
}
bool DomIndexSegment::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
int DomIndexSegment::getLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getLine(ctx);
}
int DomIndexSegment::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getStartPosition(ctx);
}
int DomIndexSegment::getEndLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndLine(ctx);
}
int DomIndexSegment::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndPosition(ctx);
}
AbstractSrcElement* DomIndexSegment::getParent(ThreadContext* ctx) throw() 
{
	return IDomSegment::getParent(ctx);
}
void DomIndexSegment::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDomSegment::setParent(parent, ctx);
}
void DomIndexSegment::position(Token* t2, AbstractSrcElement* segment, ThreadContext* ctx) throw() 
{
	IDomSegment::position(t2, segment, ctx);
}
void DomIndexSegment::position(Token* start, Token* end, ThreadContext* ctx) throw() 
{
	IDomSegment::position(start, end, ctx);
}
void DomIndexSegment::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->index), static_cast<IExpression*>(el), IExpression);
	}
	this->segmentVariableType = buff->getInt(ctx);
}
void DomIndexSegment::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DomIndexSegment, ctx);
	bool isnull = (this->index == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->index->writeData(buff, ctx);
	}
	buff->putInt(this->segmentVariableType, ctx);
}
void DomIndexSegment::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IDomSegment::TYPE_INDEX, ctx);
	bool isnull = (this->index == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->index->toFileEntry(builder, ctx);
	}
	builder->putInt(this->segmentVariableType, ctx);
}
int DomIndexSegment::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->index == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->index->fileSize(ctx);
	}
	total += 4;
	return total;
}
void DomIndexSegment::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->index), static_cast<IExpression*>(el), IExpression);
	}
	this->segmentVariableType = fetcher->fetchInt(ctx);
}
void DomIndexSegment::__cleanUp(ThreadContext* ctx){
}
}}}

