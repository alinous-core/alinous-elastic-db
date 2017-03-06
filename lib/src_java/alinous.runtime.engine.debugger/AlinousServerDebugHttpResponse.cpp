#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger.server/FileBreakpointContainer.h"
#include "alinous.runtime.engine.debugger/DebugStackFrame.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEventNotifier.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html/AlinousDomEventHandler.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/DomTokenizer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger/IHttpAccessMethod.h"
#include "alinous.runtime.engine.debugger/AlinousDebugCommandSender.h"
#include "alinous.runtime.engine.debugger/DebuggerOut.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {





String* AlinousServerDebugHttpResponse::TAG_ROOT = ConstStr::getCNST_STR_1186();
String* AlinousServerDebugHttpResponse::TAG_HOT_THREAD = ConstStr::getCNST_STR_1187();
String* AlinousServerDebugHttpResponse::ATTR_THREAD_ID = ConstStr::getCNST_STR_1188();
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
		String* str = (new(ctx) String(b, 0, n, ConstStr::getCNST_STR_1106(), ctx));
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
		throw (new(ctx) IOException(ConstStr::getCNST_STR_1185(), ctx));
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
void AlinousServerDebugHttpResponse::__cleanUp(ThreadContext* ctx){
}
}}}}

