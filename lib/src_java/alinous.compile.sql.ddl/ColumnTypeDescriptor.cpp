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
int ColumnTypeDescriptor::toTypeNum(String* str, ThreadContext* ctx) throw() 
{
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1016(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1017(), ctx))
	{
		return INT;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1018(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1019(), ctx))
	{
		return VARCHAR;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1020(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1021(), ctx))
	{
		return TEXT;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1022(), ctx) || str->equalsIgnoreCase(ConstStr::getCNST_STR_1023(), ctx))
	{
		return DOUBLE;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1024(), ctx))
	{
		return DOUBLE;
	}
	if(str->equalsIgnoreCase(ConstStr::getCNST_STR_1025(), ctx))
	{
		return TIMESTAMP;
	}
	return -1;
}
}}}}

