#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
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
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/DomNameSegment.h"

namespace alinous {namespace compile {namespace expression {





bool DomNameSegment::__init_done = __init_static_variables();
bool DomNameSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomNameSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomNameSegment::DomNameSegment(ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), name(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
{
}
void DomNameSegment::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DomNameSegment::DomNameSegment(String* name, ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), name(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
{
	__GC_MV(this, &(this->name), name, String);
}
void DomNameSegment::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
 DomNameSegment::~DomNameSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomNameSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomNameSegment", L"~DomNameSegment");
	__e_obj1.add(this->name, this);
	name = nullptr;
	if(!prepare){
		return;
	}
	IDomSegment::__releaseRegerences(true, ctx);
}
String* DomNameSegment::toString(ThreadContext* ctx) throw() 
{
	return this->name;
}
String* DomNameSegment::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void DomNameSegment::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
int DomNameSegment::getDomSegmentType(ThreadContext* ctx) throw() 
{
	return IDomSegment::TYPE_NORMAL;
}
IExpression* DomNameSegment::getIndex(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomNameSegment::getSegmentVariableType(ThreadContext* ctx) throw() 
{
	return segmentVariableType;
}
void DomNameSegment::setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw() 
{
	this->segmentVariableType = segmentVariableType;
}
bool DomNameSegment::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
int DomNameSegment::getLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getLine(ctx);
}
int DomNameSegment::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getStartPosition(ctx);
}
int DomNameSegment::getEndLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndLine(ctx);
}
int DomNameSegment::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndPosition(ctx);
}
AbstractSrcElement* DomNameSegment::getParent(ThreadContext* ctx) throw() 
{
	return IDomSegment::getParent(ctx);
}
void DomNameSegment::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDomSegment::setParent(parent, ctx);
}
void DomNameSegment::position(Token* t2, AbstractSrcElement* segment, ThreadContext* ctx) throw() 
{
	IDomSegment::position(t2, segment, ctx);
}
void DomNameSegment::position(Token* start, Token* end, ThreadContext* ctx) throw() 
{
	IDomSegment::position(start, end, ctx);
}
void DomNameSegment::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->name), buff->getString(ctx), String);
	}
	this->segmentVariableType = buff->getInt(ctx);
}
void DomNameSegment::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__DomNameSegment, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->name, ctx);
	}
	buff->putInt(this->segmentVariableType, ctx);
}
void DomNameSegment::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IDomSegment::TYPE_NORMAL, ctx);
	bool isnull = (this->name == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->name, ctx);
	}
	builder->putInt(this->segmentVariableType, ctx);
}
void DomNameSegment::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->name), fetcher->fetchString(ctx), String);
	}
	this->segmentVariableType = fetcher->fetchInt(ctx);
}
int DomNameSegment::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->name == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->name->length(ctx) * 2 + 4;
	}
	total += 4;
	return total;
}
void DomNameSegment::__cleanUp(ThreadContext* ctx){
}
}}}

