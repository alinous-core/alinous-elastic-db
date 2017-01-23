#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace ddl {





constexpr const int ColumnTypeDescriptor::INT;
constexpr const int ColumnTypeDescriptor::VARCHAR;
constexpr const int ColumnTypeDescriptor::TEXT;
constexpr const int ColumnTypeDescriptor::DOUBLE;
constexpr const int ColumnTypeDescriptor::DATE;
constexpr const int ColumnTypeDescriptor::TIMESTAMP;
constexpr const int ColumnTypeDescriptor::BLOB;
bool ColumnTypeDescriptor::__init_done = __init_static_variables();
bool ColumnTypeDescriptor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ColumnTypeDescriptor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ColumnTypeDescriptor::~ColumnTypeDescriptor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ColumnTypeDescriptor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ColumnTypeDescriptor", L"~ColumnTypeDescriptor");
	__e_obj1.add(this->length, this);
	length = nullptr;
	__e_obj1.add(this->typeName, this);
	typeName = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
bool ColumnTypeDescriptor::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->length != nullptr && !this->length->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
ISQLExpression* ColumnTypeDescriptor::getLength(ThreadContext* ctx) throw() 
{
	return length;
}
void ColumnTypeDescriptor::setLength(ISQLExpression* length, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->length), length, ISQLExpression);
}
String* ColumnTypeDescriptor::getTypeName(ThreadContext* ctx) throw() 
{
	return typeName;
}
void ColumnTypeDescriptor::setTypeName(String* typeName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->typeName), typeName, String);
	this->typeNum = toTypeNum(typeName, ctx);
}
int ColumnTypeDescriptor::getTypeNum(ThreadContext* ctx) throw() 
{
	if(this->typeNum < 0)
	{
		this->typeNum = toTypeNum(typeName, ctx);
	}
	return typeNum;
}
bool ColumnTypeDescriptor::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->length != nullptr)
	{
		this->length->analyse(context, leftValue, ctx);
	}
	return true;
}
int ColumnTypeDescriptor::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int ColumnTypeDescriptor::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int ColumnTypeDescriptor::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int ColumnTypeDescriptor::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* ColumnTypeDescriptor::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void ColumnTypeDescriptor::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void ColumnTypeDescriptor::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->length), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->typeName), buff->getString(ctx), String);
	}
	this->typeNum = buff->getInt(ctx);
}
void ColumnTypeDescriptor::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__Unique, ctx);
	bool isnull = (this->length == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->length->writeData(buff, ctx);
	}
	isnull = (this->typeName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->typeName, ctx);
	}
	buff->putInt(this->typeNum, ctx);
}
int ColumnTypeDescriptor::toTypeNum(String* str, ThreadContext* ctx) throw() 
{
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1054(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1055(), ctx))
	{
		return INT;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1056(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1057(), ctx))
	{
		return VARCHAR;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1058(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1059(), ctx))
	{
		return TEXT;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1060(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1061(), ctx))
	{
		return DOUBLE;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1062(), ctx))
	{
		return DOUBLE;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1063(), ctx))
	{
		return TIMESTAMP;
	}
	return -1;
}
}}}}

