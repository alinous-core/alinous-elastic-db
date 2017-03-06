#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
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
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
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
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression/IExpressionFactory.h"

namespace alinous {namespace compile {namespace expression {





bool DomVariableDescriptor::__init_done = __init_static_variables();
bool DomVariableDescriptor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariableDescriptor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariableDescriptor::DomVariableDescriptor(ThreadContext* ctx) throw()  : IObject(ctx), IExpression(ctx), segments(GCUtils<ArrayList<IDomSegment> >::ins(this, (new(ctx) ArrayList<IDomSegment>(ctx)), ctx, __FILEW__, __LINE__, L"")), prefix(nullptr), domDeclare(nullptr)
{
}
void DomVariableDescriptor::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DomVariableDescriptor::~DomVariableDescriptor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariableDescriptor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomVariableDescriptor", L"~DomVariableDescriptor");
	__e_obj1.add(this->segments, this);
	segments = nullptr;
	__e_obj1.add(this->prefix, this);
	prefix = nullptr;
	__e_obj1.add(this->domDeclare, this);
	domDeclare = nullptr;
	if(!prepare){
		return;
	}
	IExpression::__releaseRegerences(true, ctx);
}
void DomVariableDescriptor::addSegment(IDomSegment* seg, ThreadContext* ctx) throw() 
{
	if(IDomSegment::TYPE_INDEX == seg->getDomSegmentType(ctx))
	{
		IDomSegment* peekSeg = this->segments->get(this->segments->size(ctx) - 1, ctx);
		peekSeg->setSegmentVariableType(IDomSegment::TYPE_INDEX, ctx);
	}
	this->segments->add(seg, ctx);
}
String* DomVariableDescriptor::getLastName(ThreadContext* ctx) throw() 
{
	IDomSegment* seg = this->segments->get(this->segments->size(ctx) - 1, ctx);
	if(seg->getDomSegmentType(ctx) == IDomSegment::TYPE_INDEX)
	{
		return nullptr;
	}
	return (static_cast<DomNameSegment*>(seg))->getName(ctx);
}
int DomVariableDescriptor::getLastIndex(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IDomSegment* seg = this->segments->get(this->segments->size(ctx) - 1, ctx);
	if(seg->getDomSegmentType(ctx) == IDomSegment::TYPE_INDEX)
	{
		return -1;
	}
	return machine->resolveExpression((static_cast<DomIndexSegment*>(seg))->getIndex(ctx), debug, ctx)->toIntVariable(ctx)->getIntValue(ctx);
}
IAlinousVariable* DomVariableDescriptor::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return machine->getByDescriptor(this, debug, ctx);
}
bool DomVariableDescriptor::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool DomVariableDescriptor::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
void DomVariableDescriptor::markLastSegmentAsArray(ThreadContext* ctx) throw() 
{
	int index = this->segments->size(ctx) - 1;
	this->segments->get(index, ctx)->setSegmentVariableType(IDomVariable::TYPE_ARRAY, ctx);
}
String* DomVariableDescriptor::getPrefix(ThreadContext* ctx) throw() 
{
	return prefix;
}
void DomVariableDescriptor::setPrefix(String* prefix, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->prefix), prefix, String);
}
ArrayList<IDomSegment>* DomVariableDescriptor::getSegments(ThreadContext* ctx) throw() 
{
	return segments;
}
bool DomVariableDescriptor::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* holder = context->getCurrentStack(ctx);
	String* id = getSourceId(ctx)->getId(ctx);
	__GC_MV(this, &(this->domDeclare), holder->getDomDeclare(ctx)->get(id, ctx), DomVariableDeclareSource);
	if(this->domDeclare == nullptr)
	{
		DomVariableDeclareSource* decsrc = (new(ctx) DomVariableDeclareSource(id, this, ctx));
		holder->getDomDeclare(ctx)->put(id, decsrc, ctx);
	}
	return true;
}
String* DomVariableDescriptor::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->prefix != nullptr)
	{
		buff->append(this->prefix, ctx)->append(ConstStr::getCNST_STR_380(), ctx);
	}
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomSegment* seg = this->segments->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(seg->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
ExpressionSourceId* DomVariableDescriptor::getSourceId(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomSegment* seg = this->segments->get(i, ctx);
		int segType = seg->getDomSegmentType(ctx);
		switch(segType) {
		case IDomSegment::TYPE_NORMAL:
			if(i != 0)
			{
				buff->append(ConstStr::getCNST_STR_950(), ctx);
			}
			buff->append(seg->toString(ctx), ctx);
			break ;
		default:
			buff->append(seg->toString(ctx), ctx);
			break ;
		}
	}
	return (new(ctx) ExpressionSourceId(buff->toString(ctx), this, (new(ctx) AlinousType(ctx)), ctx));
}
DomVariableDeclareSource* DomVariableDescriptor::getDomDeclare(ThreadContext* ctx) throw() 
{
	return domDeclare;
}
int DomVariableDescriptor::getLine(ThreadContext* ctx) throw() 
{
	return IExpression::getLine(ctx);
}
int DomVariableDescriptor::getStartPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getStartPosition(ctx);
}
int DomVariableDescriptor::getEndLine(ThreadContext* ctx) throw() 
{
	return IExpression::getEndLine(ctx);
}
int DomVariableDescriptor::getEndPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getEndPosition(ctx);
}
AbstractSrcElement* DomVariableDescriptor::getParent(ThreadContext* ctx) throw() 
{
	return IExpression::getParent(ctx);
}
void DomVariableDescriptor::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IExpression::setParent(parent, ctx);
}
bool DomVariableDescriptor::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int DomVariableDescriptor::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::domVariableDescriptor;
}
void DomVariableDescriptor::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IDomSegment*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_993(), ctx));
		}
		this->segments->add(static_cast<IDomSegment*>(el), ctx);
	}
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->prefix), buff->getString(ctx), String);
	}
}
void DomVariableDescriptor::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DomVariableDescriptor, ctx);
	int maxLoop = this->segments->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IDomSegment* exp = this->segments->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	bool isnull = (this->prefix == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->prefix, ctx);
	}
}
int DomVariableDescriptor::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->segments->size(ctx);
	total += 4;
	for(int i = 0; i < maxLoop; ++i)
	{
		IDomSegment* exp = this->segments->get(i, ctx);
		total += exp->fileSize(ctx);
	}
	bool isnull = (this->prefix == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->prefix->length(ctx) * 2 + 4;
	}
	return total;
}
void DomVariableDescriptor::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__DomVariableDescriptor, ctx);
	int maxLoop = this->segments->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IDomSegment* exp = this->segments->get(i, ctx);
		exp->toFileEntry(builder, ctx);
	}
	bool isnull = (this->prefix == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->prefix, ctx);
	}
}
void DomVariableDescriptor::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IDomSegment* el = IDomSegment::fromFetcher(fetcher, ctx);
		if(el == nullptr)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_993(), ctx));
		}
		this->segments->add(el, ctx);
	}
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->prefix), fetcher->fetchString(ctx), String);
	}
}
void DomVariableDescriptor::__cleanUp(ThreadContext* ctx){
}
}}}

