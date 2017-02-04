#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace ddl {





bool ShardKeys::__init_done = __init_static_variables();
bool ShardKeys::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ShardKeys", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ShardKeys::~ShardKeys() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ShardKeys::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ShardKeys", L"~ShardKeys");
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void ShardKeys::addKey(String* key, ThreadContext* ctx) throw() 
{
	this->columns->add(key, ctx);
}
ArrayList<String>* ShardKeys::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void ShardKeys::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = buff->getString(ctx);
		this->columns->add(s, ctx);
	}
}
void ShardKeys::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ShardKeys, ctx);
	int maxLoop = this->columns->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = this->columns->get(i, ctx);
		buff->putString(s, ctx);
	}
}
bool ShardKeys::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool ShardKeys::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
}}}}

