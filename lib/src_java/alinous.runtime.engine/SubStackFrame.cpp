#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





String* SubStackFrame::TAG_SUB_STACKFRAME = ConstStr::getCNST_STR_1170();
String* SubStackFrame::ATTR_LINE = ConstStr::getCNST_STR_1161();
String* SubStackFrame::ATTR_FILENAME = ConstStr::getCNST_STR_1162();
bool SubStackFrame::__init_done = __init_static_variables();
bool SubStackFrame::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SubStackFrame", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SubStackFrame::SubStackFrame(AbstractSrcElement* sourceElement, DomVariableContainer* container, ThreadContext* ctx) throw()  : IObject(ctx), AbstractStackFrame(ctx)
{
	__GC_MV(this, &(this->sourceElement), sourceElement, AbstractSrcElement);
	__GC_MV(this, &(this->container), container, DomVariableContainer);
	__GC_MV(this, &(this->typedContainer), (new(ctx) TypedVariableContainer(ctx)), TypedVariableContainer);
}
void SubStackFrame::__construct_impl(AbstractSrcElement* sourceElement, DomVariableContainer* container, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sourceElement), sourceElement, AbstractSrcElement);
	__GC_MV(this, &(this->container), container, DomVariableContainer);
	__GC_MV(this, &(this->typedContainer), (new(ctx) TypedVariableContainer(ctx)), TypedVariableContainer);
}
 SubStackFrame::~SubStackFrame() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SubStackFrame::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractStackFrame::__releaseRegerences(true, ctx);
}
void SubStackFrame::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_SUB_STACKFRAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(ATTR_LINE, Integer::toString(this->sourceElement->getLine(ctx), ctx), node, ctx));
	node->addAttribute(attr, ctx);
	attr = (new(ctx) Attribute(ATTR_FILENAME, this->sourceElement->getDebugFilePath(ctx), node, ctx));
	node->addAttribute(attr, ctx);
	if(this->container != nullptr)
	{
		this->container->outDebugXml(node, ctx);
	}
	if(this->typedContainer != nullptr)
	{
		this->typedContainer->outDebugXml(node, ctx);
	}
	outSubframeDebugXml(node, ctx);
}
ITypedVariable* SubStackFrame::getTypedVariable(String* name, ThreadContext* ctx) throw() 
{
	return this->typedContainer->get(name, ctx);
}
void SubStackFrame::putTypedVariable(String* name, ITypedVariable* variable, ThreadContext* ctx) throw() 
{
	this->typedContainer->put(name, variable, ctx);
}
void SubStackFrame::putVariable(ScriptMachine* machine, DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx)
{
	ArrayList<IDomSegment>* segs = desc->getSegments(ctx);
	IDomVariableContainer* container = this->container;
	IDomVariableContainer* lastcontainer = container;
	int maxLoop = segs->size(ctx) - 1;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomSegment* seg = segs->get(i, ctx);
		lastcontainer = container;
		switch(seg->getDomSegmentType(ctx)) {
		case IDomSegment::TYPE_NORMAL:
			container = container->getProperty(seg->getName(ctx), ctx);
			if(container == nullptr)
			{
				int newType = seg->getSegmentVariableType(ctx);
				container = addBrankDom(lastcontainer, seg->getName(ctx), newType, ctx);
			}
			break ;
		default:
			container = container->get(seg->getIndex(ctx)->resolveExpression(machine, debug, ctx)->getIntValue(ctx), ctx);
			if(container == nullptr)
			{
				int newType = seg->getSegmentVariableType(ctx);
				container = addBrankDom(lastcontainer, seg->getIndex(ctx)->resolveExpression(machine, debug, ctx)->getIntValue(ctx), newType, ctx);
			}
			break ;
		}
	}
	IDomSegment* seg = segs->get(segs->size(ctx) - 1, ctx);
	switch(seg->getDomSegmentType(ctx)) {
	case IDomSegment::TYPE_NORMAL:
		container->setProperty(seg->getName(ctx), variable, ctx);
		break ;
	default:
		container->set(variable, seg->getIndex(ctx)->resolveExpression(machine, debug, ctx)->getIntValue(ctx), ctx);
		break ;
	}
}
IDomVariable* SubStackFrame::addBrankDom(IDomVariableContainer* lastcontainer, String* property, int newType, ThreadContext* ctx)
{
	IDomVariable* newVariable = nullptr;
	if(newType == IDomVariable::TYPE_DOM)
	{
		newVariable = (new(ctx) DomVariable(ctx));
	}
		else 
	{
		newVariable = (new(ctx) DomArray(ctx));
	}
	lastcontainer->setProperty(property, newVariable, ctx);
	return newVariable;
}
IDomVariable* SubStackFrame::addBrankDom(IDomVariableContainer* lastcontainer, int index, int newType, ThreadContext* ctx) throw() 
{
	IDomVariable* newVariable = nullptr;
	if(newType == IDomVariable::TYPE_DOM)
	{
		newVariable = (new(ctx) DomVariable(ctx));
	}
		else 
	{
		newVariable = (new(ctx) DomArray(ctx));
	}
	lastcontainer->set(newVariable, index, ctx);
	return newVariable;
}
SubStackFrame* SubStackFrame::importFromDebugXml(DomNode* node, DomVariableContainer* domContainer, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(SubStackFrame::TAG_SUB_STACKFRAME, ctx))
	{
		return nullptr;
	}
	DebugMainFrameSrcElement* src = (new(ctx) DebugMainFrameSrcElement(ctx));
	IVariableValue* v = node->getAttributeValue(ATTR_LINE, ctx);
	src->line = Integer::parseInt(v->toString(ctx), ctx);
	v = node->getAttributeValue(ATTR_FILENAME, ctx);
	__GC_MV(src, &(src->debugFilePath), v->toString(ctx), String);
	SubStackFrame* frame = (new(ctx) SubStackFrame(src, domContainer, ctx));
	AbstractStackFrame::importInnerFromXml(node, frame, ctx);
	return frame;
}
}}}

