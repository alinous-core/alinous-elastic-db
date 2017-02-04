#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace ddl {





bool SubShardKeys::__init_done = __init_static_variables();
bool SubShardKeys::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SubShardKeys", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SubShardKeys::~SubShardKeys() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SubShardKeys::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SubShardKeys", L"~SubShardKeys");
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void SubShardKeys::addKey(String* key, ThreadContext* ctx) throw() 
{
	this->columns->add(key, ctx);
}
ArrayList<String>* SubShardKeys::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void SubShardKeys::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = buff->getString(ctx);
		this->columns->add(s, ctx);
	}
}
void SubShardKeys::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SubShardKeys, ctx);
	int maxLoop = this->columns->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = this->columns->get(i, ctx);
		buff->putString(s, ctx);
	}
}
bool SubShardKeys::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool SubShardKeys::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
}}}}

