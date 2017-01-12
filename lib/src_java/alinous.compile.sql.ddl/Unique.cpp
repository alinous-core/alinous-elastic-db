#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace ddl {





bool Unique::__init_done = __init_static_variables();
bool Unique::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Unique", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Unique::~Unique() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Unique::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Unique", L"~Unique");
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
bool Unique::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
void Unique::addKey(String* key, ThreadContext* ctx) throw() 
{
	this->columns->add(key, ctx);
}
ArrayList<String>* Unique::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
bool Unique::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
int Unique::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int Unique::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int Unique::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int Unique::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* Unique::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void Unique::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void Unique::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = buff->getString(ctx);
		this->columns->add(s, ctx);
	}
}
void Unique::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__Unique, ctx);
	int maxLoop = this->columns->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = this->columns->get(i, ctx);
		buff->putString(s, ctx);
	}
}
}}}}

