#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {





String* AlinousServerDebugHttpResponse::TAG_ROOT = ConstStr::getCNST_STR_1123();
String* AlinousServerDebugHttpResponse::TAG_HOT_THREAD = ConstStr::getCNST_STR_1124();
String* AlinousServerDebugHttpResponse::ATTR_THREAD_ID = ConstStr::getCNST_STR_1125();
bool AlinousServerDebugHttpResponse::__init_done = __init_static_variables();
bool AlinousServerDebugHttpResponse::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousServerDebugHttpResponse", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousServerDebugHttpResponse::AlinousServerDebugHttpResponse(int result, ThreadContext* ctx) throw()  : IObject(ctx), result(0), threadList(GCUtils<List<DebugThread> >::ins(this, (new(ctx) ArrayList<DebugThread>(ctx)), ctx, __FILEW__, __LINE__, L"")), shutdown(0), hotThread(0)
{
	this->shutdown = false;
	this->result = result;
	this->hotThread = -1;
}
void AlinousServerDebugHttpResponse::__construct_impl(int result, ThreadContext* ctx) throw() 
{
	this->shutdown = false;
	this->result = result;
	this->hotThread = -1;
}
 AlinousServerDebugHttpResponse::~AlinousServerDebugHttpResponse() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousServerDebugHttpResponse::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousServerDebugHttpResponse", L"~AlinousServerDebugHttpResponse");
	__e_obj1.add(this->threadList, this);
	threadList = nullptr;
	if(!prepare){
		return;
	}
}
int AlinousServerDebugHttpResponse::getResult(ThreadContext* ctx) throw() 
{
	return result;
}
List<DebugThread>* AlinousServerDebugHttpResponse::getThreadList(ThreadContext* ctx) throw() 
{
	return threadList;
}
void AlinousServerDebugHttpResponse::addThread(DebugThread* thread, ThreadContext* ctx) throw() 
{
	threadList->add(thread, ctx);
}
String* AlinousServerDebugHttpResponse::exportAsXml(ThreadContext* ctx) throw() 
{
	DomNode* rootnode = (new(ctx) DomNode(TAG_ROOT, ctx));
	DomNode* hotThread = (new(ctx) DomNode(TAG_HOT_THREAD, ctx));
	Attribute* threadIdattr = (new(ctx) Attribute(ATTR_THREAD_ID, Long::toString(this->hotThread, ctx), hotThread, ctx));
	hotThread->addAttribute(threadIdattr, ctx);
	rootnode->addChild(hotThread, ctx);
	int maxLoop = this->threadList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DebugThread* dthread = this->threadList->get(i, ctx);
		dthread->outDebugXml(rootnode, ctx);
	}
	return rootnode->toString(ctx);
}
void AlinousServerDebugHttpResponse::importFromXmlString(InputStream* inStream, ThreadContext* ctx)
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	IArrayObjectPrimitive<char>* b = ArrayAllocatorPrimitive<char>::allocatep(ctx, 1024);
	int n = 0;
	do
	{
		n = inStream->read(b, ctx);
		String* str = (new(ctx) String(b, 0, n, ConstStr::getCNST_STR_1047(), ctx));
		buff->append(str, ctx);
	}
	while(n == b->length);
	String* sourceHtml = buff->toString(ctx);
	AlinousDomReplacer* replacer = (new(ctx) AlinousDomReplacer(ctx));
	DomConverter* converter = (new(ctx) DomConverter(sourceHtml, replacer, ctx));
	converter->parse(ctx);
	DomDocument* document = replacer->getDocument(ctx);
	if(document->getNumChildern(ctx) == 0)
	{
		throw (new(ctx) IOException(ConstStr::getCNST_STR_1122(), ctx));
	}
	DomNode* rootnode = document->getChildNodeAt(0, ctx);
	int maxLoop = rootnode->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* node = rootnode->getChildNodeAt(i, ctx);
		String* tagName = node->getName(ctx);
		if(tagName->equals(TAG_HOT_THREAD, ctx))
		{
			IVariableValue* attr = node->getAttributeValue(ATTR_THREAD_ID, ctx);
			{
				try
				{
					String* strvalue = attr->toString(ctx);
					this->hotThread = Long::parseLong(strvalue, ctx);
				}
				catch(Throwable* e)
				{
					e->printStackTrace(ctx);
				}
			}
		}
				else 
		{
			if(tagName->equals(DebugThread::TAG_THREAD, ctx))
			{
				DebugThread* dthread = DebugThread::importFromDebugXml(node, ctx);
				if(dthread != nullptr)
				{
					addThread(dthread, ctx);
				}
			}
		}
	}
}
bool AlinousServerDebugHttpResponse::isShutdown(ThreadContext* ctx) throw() 
{
	return shutdown;
}
void AlinousServerDebugHttpResponse::setShutdown(bool shutdown, ThreadContext* ctx) throw() 
{
	this->shutdown = shutdown;
}
long long AlinousServerDebugHttpResponse::getHotThread(ThreadContext* ctx) throw() 
{
	return hotThread;
}
void AlinousServerDebugHttpResponse::setHotThread(long long hotThread, ThreadContext* ctx) throw() 
{
	this->hotThread = hotThread;
}
bool AlinousServerDebugHttpResponse::containsThread(long long threadId, ThreadContext* ctx) throw() 
{
	Iterator<DebugThread>* it = this->threadList->iterator(ctx);
	while(it->hasNext(ctx))
	{
		DebugThread* th = it->next(ctx);
		if(th->getThreadId(ctx) == threadId)
		{
			return true;
		}
	}
	return false;
}
}}}}

