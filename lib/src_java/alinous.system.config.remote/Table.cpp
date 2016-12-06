#include "includes.h"


namespace alinous {namespace system {namespace config {namespace remote {





bool Table::__init_done = __init_static_variables();
bool Table::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Table", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Table::~Table() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Table::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Table", L"~Table");
	__e_obj1.add(this->scheme, this);
	scheme = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->keys, this);
	keys = nullptr;
	__e_obj1.add(this->nodeRefs, this);
	nodeRefs = nullptr;
	__e_obj1.add(this->max, this);
	max = nullptr;
	if(!prepare){
		return;
	}
}
String* Table::getScheme(ThreadContext* ctx) throw() 
{
	return scheme;
}
void Table::setScheme(String* scheme, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->scheme), scheme, String);
}
String* Table::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void Table::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
List<String>* Table::getKeys(ThreadContext* ctx) throw() 
{
	return keys;
}
void Table::addKey(String* key, ThreadContext* ctx) throw() 
{
	this->keys->add(key, ctx);
}
void Table::addNodeRef(NodeRef* node, ThreadContext* ctx) throw() 
{
	this->nodeRefs->add(node, ctx);
}
List<NodeRef>* Table::getNodeRefs(ThreadContext* ctx) throw() 
{
	return nodeRefs;
}
String* Table::getMax(ThreadContext* ctx) throw() 
{
	return max;
}
void Table::setMax(String* max, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->max), max, String);
}
}}}}

