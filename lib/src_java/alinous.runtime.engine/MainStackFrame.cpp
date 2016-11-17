#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





String* MainStackFrame::TAG_STACKFRAME = ConstStr::getCNST_STR_1103();
String* MainStackFrame::ATTR_LINE = ConstStr::getCNST_STR_1104();
String* MainStackFrame::ATTR_FILENAME = ConstStr::getCNST_STR_1105();
String* MainStackFrame::ATTR_PEEK = ConstStr::getCNST_STR_1106();
String* MainStackFrame::ATTR_NAME = ConstStr::getCNST_STR_1061();
String* MainStackFrame::ATTR_STACKID = ConstStr::getCNST_STR_1107();
String* MainStackFrame::ATTR_STEPIN_CANDIDATES = ConstStr::getCNST_STR_1108();
String* MainStackFrame::ATTR_STEPIN_EXECUTED = ConstStr::getCNST_STR_1109();
bool MainStackFrame::__init_done = __init_static_variables();
bool MainStackFrame::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MainStackFrame", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MainStackFrame::MainStackFrame(AbstractSrcElement* sourceElement, long long stackId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractStackFrame(ctx), thisPtr(nullptr), stackId(0), currentLine(0)
{
	__GC_MV(this, &(this->sourceElement), sourceElement, AbstractSrcElement);
	__GC_MV(this, &(this->container), (new(ctx) DomVariableContainer(ctx)), DomVariableContainer);
	this->stackId = stackId;
	this->currentLine = sourceElement->getLine(ctx);
}
void MainStackFrame::__construct_impl(AbstractSrcElement* sourceElement, long long stackId, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sourceElement), sourceElement, AbstractSrcElement);
	__GC_MV(this, &(this->container), (new(ctx) DomVariableContainer(ctx)), DomVariableContainer);
	this->stackId = stackId;
	this->currentLine = sourceElement->getLine(ctx);
}
 MainStackFrame::~MainStackFrame() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MainStackFrame::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MainStackFrame", L"~MainStackFrame");
	__e_obj1.add(this->thisPtr, this);
	thisPtr = nullptr;
	if(!prepare){
		return;
	}
	AbstractStackFrame::__releaseRegerences(true, ctx);
}
void MainStackFrame::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_STACKFRAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(ATTR_LINE, Integer::toString(this->currentLine, ctx), node, ctx));
	node->addAttribute(attr, ctx);
	attr = (new(ctx) Attribute(ATTR_FILENAME, this->sourceElement->getDebugFilePath(ctx), node, ctx));
	node->addAttribute(attr, ctx);
	String* strStackId = Long::toString(this->stackId, ctx);
	attr = (new(ctx) Attribute(ATTR_STACKID, strStackId, node, ctx));
	node->addAttribute(attr, ctx);
	outSubframeDebugXml(node, ctx);
}
void MainStackFrame::putTypedVariable(String* name, ITypedVariable* variable, ThreadContext* ctx)
{
	int maxLoop = this->stackFrames->size(ctx) - 1;
	for(int i = maxLoop; i != -1; --i)
	{
		SubStackFrame* subframe = this->stackFrames->get(i, ctx);
		ITypedVariable* val = subframe->getTypedVariable(name, ctx);
		if(val != nullptr)
		{
			val->substitute(variable, ctx);
			return;
		}
	}
	SubStackFrame* subframe = this->stackFrames->peek(ctx);
	subframe->putTypedVariable(name, variable, ctx);
}
ITypedVariable* MainStackFrame::getTypedVariable(String* name, ThreadContext* ctx) throw() 
{
	int maxLoop = this->stackFrames->size(ctx) - 1;
	for(int i = maxLoop; i != -1; --i)
	{
		SubStackFrame* subframe = this->stackFrames->get(i, ctx);
		ITypedVariable* val = subframe->getTypedVariable(name, ctx);
		if(val != nullptr)
		{
			return val;
		}
	}
	return nullptr;
}
IDomVariable* MainStackFrame::getDomVariable(ScriptMachine* machine, DomVariableDescriptor* desc, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->stackFrames->size(ctx) - 1;
	for(int i = maxLoop; i != -1; --i)
	{
		SubStackFrame* subframe = this->stackFrames->get(i, ctx);
		IDomVariable* domVariable = findInSubFrame(machine, subframe, desc, 0, debug, ctx);
		if(domVariable != nullptr)
		{
			return domVariable;
		}
	}
	return nullptr;
}
void MainStackFrame::putVariable(ScriptMachine* machine, DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx)
{
	SubStackFrame* subframe = this->stackFrames->get(0, ctx);
	subframe->putVariable(machine, desc, variable, debug, ctx);
}
AlinousClassVariable* MainStackFrame::getThisPtr(ThreadContext* ctx) throw() 
{
	return thisPtr;
}
void MainStackFrame::setThisPtr(AlinousClassVariable* thisPtr, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->thisPtr), thisPtr, AlinousClassVariable);
}
long long MainStackFrame::getStackId(ThreadContext* ctx) throw() 
{
	return stackId;
}
int MainStackFrame::getCurrentLine(ThreadContext* ctx) throw() 
{
	return currentLine;
}
void MainStackFrame::setCurrentLine(int currentLine, ThreadContext* ctx) throw() 
{
	this->currentLine = currentLine;
}
IDomVariable* MainStackFrame::findInSubFrame(ScriptMachine* machine, SubStackFrame* subframe, DomVariableDescriptor* desc, int offset, bool debug, ThreadContext* ctx)
{
	ArrayList<IDomSegment>* segs = desc->getSegments(ctx);
	IDomVariableContainer* container = this->container;
	int maxLoop = segs->size(ctx) - offset;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomSegment* seg = segs->get(i, ctx);
		switch(seg->getDomSegmentType(ctx)) {
		case IDomSegment::TYPE_NORMAL:
			container = container->getProperty(seg->getName(ctx), ctx);
			break ;
		default:
			container = container->get(seg->getIndex(ctx)->resolveExpression(machine, debug, ctx)->getIntValue(ctx), ctx);
			break ;
		}
		if(container == nullptr)
		{
			return nullptr;
		}
	}
	if(container == this->container)
	{
		return nullptr;
	}
	return static_cast<IDomVariable*>(container);
}
MainStackFrame* MainStackFrame::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(MainStackFrame::TAG_STACKFRAME, ctx))
	{
		return nullptr;
	}
	DebugMainFrameSrcElement* src = (new(ctx) DebugMainFrameSrcElement(ctx));
	IVariableValue* v = node->getAttributeValue(ATTR_STACKID, ctx);
	long long stackId = Long::parseLong(v->toString(ctx), ctx);
	MainStackFrame* frame = (new(ctx) MainStackFrame(src, stackId, ctx));
	v = node->getAttributeValue(ATTR_LINE, ctx);
	src->line = Integer::parseInt(v->toString(ctx), ctx);
	v = node->getAttributeValue(ATTR_FILENAME, ctx);
	__GC_MV(src, &(src->filePath), v->toString(ctx), String);
	AbstractStackFrame::importInnerFromXml(node, frame, ctx);
	return frame;
}
}}}

