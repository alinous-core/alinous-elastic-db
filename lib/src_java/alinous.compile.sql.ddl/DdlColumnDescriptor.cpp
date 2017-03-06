#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"

namespace alinous {namespace compile {namespace sql {namespace ddl {





bool DdlColumnDescriptor::__init_done = __init_static_variables();
bool DdlColumnDescriptor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DdlColumnDescriptor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DdlColumnDescriptor::DdlColumnDescriptor(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), name(nullptr), typeDescriptor(nullptr), defaultValue(nullptr), notnull(0), unique(0), check(nullptr)
{
}
void DdlColumnDescriptor::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DdlColumnDescriptor::~DdlColumnDescriptor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DdlColumnDescriptor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DdlColumnDescriptor", L"~DdlColumnDescriptor");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->typeDescriptor, this);
	typeDescriptor = nullptr;
	__e_obj1.add(this->defaultValue, this);
	defaultValue = nullptr;
	__e_obj1.add(this->check, this);
	check = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
TableColumnMetadata* DdlColumnDescriptor::toMetadata(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	int colType = typeDescriptor->getTypeNum(ctx);
	int length = 0;
	if(typeDescriptor->getLength(ctx) != nullptr)
	{
		IAlinousVariable* lenVariable = machine->resolveExpression(typeDescriptor->getLength(ctx), debug, ctx);
		length = lenVariable->getIntValue(ctx);
	}
	TableColumnMetadata* col = (new(ctx) TableColumnMetadata(this->name, colType, length, ctx));
	col->setCheck(this->check, ctx);
	col->notnull = this->notnull;
	col->unique = this->unique;
	return col;
}
void DdlColumnDescriptor::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool DdlColumnDescriptor::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->typeDescriptor != nullptr && !this->typeDescriptor->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->defaultValue != nullptr && !this->defaultValue->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->check != nullptr && !this->check->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool DdlColumnDescriptor::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->typeDescriptor != nullptr)
	{
		this->typeDescriptor->analyse(context, leftValue, ctx);
	}
	if(this->defaultValue != nullptr)
	{
		this->defaultValue->analyse(context, leftValue, ctx);
	}
	if(this->check != nullptr)
	{
		this->check->analyse(context, leftValue, ctx);
	}
	return true;
}
String* DdlColumnDescriptor::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void DdlColumnDescriptor::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
ColumnTypeDescriptor* DdlColumnDescriptor::getTypeDescriptor(ThreadContext* ctx) throw() 
{
	return typeDescriptor;
}
void DdlColumnDescriptor::setTypeDescriptor(ColumnTypeDescriptor* typeDescriptor, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->typeDescriptor), typeDescriptor, ColumnTypeDescriptor);
}
ISQLExpression* DdlColumnDescriptor::getDefaultValue(ThreadContext* ctx) throw() 
{
	return defaultValue;
}
void DdlColumnDescriptor::setDefaultValue(ISQLExpression* defaultValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->defaultValue), defaultValue, ISQLExpression);
}
bool DdlColumnDescriptor::isNotnull(ThreadContext* ctx) throw() 
{
	return notnull;
}
void DdlColumnDescriptor::setNotnull(bool notnull, ThreadContext* ctx) throw() 
{
	this->notnull = notnull;
}
bool DdlColumnDescriptor::isUnique(ThreadContext* ctx) throw() 
{
	return unique;
}
void DdlColumnDescriptor::setUnique(bool unique, ThreadContext* ctx) throw() 
{
	this->unique = unique;
}
CheckDefinition* DdlColumnDescriptor::getCheck(ThreadContext* ctx) throw() 
{
	return check;
}
void DdlColumnDescriptor::setCheck(CheckDefinition* check, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->check), check, CheckDefinition);
}
int DdlColumnDescriptor::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int DdlColumnDescriptor::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int DdlColumnDescriptor::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int DdlColumnDescriptor::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* DdlColumnDescriptor::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void DdlColumnDescriptor::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void DdlColumnDescriptor::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->name), buff->getString(ctx), String);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ColumnTypeDescriptor*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1070(), ctx));
		}
		__GC_MV(this, &(this->typeDescriptor), static_cast<ColumnTypeDescriptor*>(el), ColumnTypeDescriptor);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->defaultValue), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	this->notnull = buff->getBoolean(ctx);
	this->unique = buff->getBoolean(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<CheckDefinition*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1034(), ctx));
		}
		__GC_MV(this, &(this->check), static_cast<CheckDefinition*>(el), CheckDefinition);
	}
}
void DdlColumnDescriptor::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DdlColumnDescriptor, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->name, ctx);
	}
	isnull = (this->typeDescriptor == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->typeDescriptor->writeData(buff, ctx);
	}
	buff->putBoolean(this->notnull, ctx);
	buff->putBoolean(this->unique, ctx);
	isnull = (this->check == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->check->writeData(buff, ctx);
	}
}
void DdlColumnDescriptor::__cleanUp(ThreadContext* ctx){
}
}}}}

