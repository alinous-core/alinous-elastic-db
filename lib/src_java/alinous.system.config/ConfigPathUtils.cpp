#include "includes.h"


namespace alinous {namespace system {namespace config {





bool ConfigPathUtils::__init_done = __init_static_variables();
bool ConfigPathUtils::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConfigPathUtils", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConfigPathUtils::~ConfigPathUtils() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConfigPathUtils::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* ConfigPathUtils::getAbsDirPath(String* base, String* path, ThreadContext* ctx) throw() 
{
	if(path->startsWith(ConstStr::getCNST_STR_1007(), ctx))
	{
		return path;
	}
	bool baseAbsolute = base->startsWith(ConstStr::getCNST_STR_1007(), ctx);
	Stack<String>* baseList = toList(base, ctx);
	Stack<String>* ref = toList(path, ctx);
	if(!base->endsWith(ConstStr::getCNST_STR_1007(), ctx))
	{
		baseList->pop(ctx);
	}
	Iterator<String>* it = ref->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* pa = it->next(ctx);
		if(pa->equals(ConstStr::getCNST_STR_1237(), ctx))
		{
			baseList->pop(ctx);
		}
				else 
		{
			if(pa->equals(ConstStr::getCNST_STR_950(), ctx))
			{
				continue;
			}
						else 
			{
				baseList->push(pa, ctx);
			}
		}
	}
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	if(baseAbsolute)
	{
		buffer->append(ConstStr::getCNST_STR_1007(), ctx);
	}
	it = baseList->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* pa = it->next(ctx);
		buffer->append(pa, ctx);
		buffer->append(ConstStr::getCNST_STR_1007(), ctx);
	}
	return buffer->toString(ctx);
}
Stack<String>* ConfigPathUtils::toList(String* path, ThreadContext* ctx) throw() 
{
	IArrayObject<String>* elements = path->split(ConstStr::getCNST_STR_1007(), ctx);
	Stack<String>* baseList = (new(ctx) Stack<String>(ctx));
	for(int i = 0; i < elements->length; i ++ )
	{
		if(!elements->get(i)->equals(ConstStr::getCNST_STR_4(), ctx))
		{
			baseList->push(elements->get(i), ctx);
		}
	}
	return baseList;
}
}}}

