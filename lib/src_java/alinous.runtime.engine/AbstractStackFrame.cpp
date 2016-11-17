#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





bool AbstractStackFrame::__init_done = __init_static_variables();
bool AbstractStackFrame::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractStackFrame", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractStackFrame::~AbstractStackFrame() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractStackFrame::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractStackFrame", L"~AbstractStackFrame");
	__e_obj1.add(this->sourceElement, this);
	sourceElement = nullptr;
	__e_obj1.add(this->container, this);
	container = nullptr;
	__e_obj1.add(this->typedContainer, this);
	typedContainer = nullptr;
	__e_obj1.add(this->stackFrames, this);
	stackFrames = nullptr;
	if(!prepare){
		return;
	}
	AbstractSrcElement::__releaseRegerences(true, ctx);
}
IStackFrame* AbstractStackFrame::subFrame(AbstractSrcElement* sourceElement, ThreadContext* ctx) throw() 
{
	SubStackFrame* newFrame = (new(ctx) SubStackFrame(sourceElement, this->container, ctx));
	this->stackFrames->push(newFrame, ctx);
	return newFrame;
}
Map<String,IDomVariable>* AbstractStackFrame::getDebugSideDomvariables(ThreadContext* ctx) throw() 
{
	Map<String,IDomVariable>* valmap = (new(ctx) HashMap<String,IDomVariable>(ctx));
	int maxLoop = this->stackFrames->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubStackFrame* subFrame = this->stackFrames->get(i, ctx);
		DomVariableContainer* container = subFrame->getVariableContainer(ctx);
		container->addVariablesToList(valmap, ctx);
	}
	return valmap;
}
Map<String,ITypedVariable>* AbstractStackFrame::getDebugSideTypedVariables(ThreadContext* ctx) throw() 
{
	Map<String,ITypedVariable>* valmap = (new(ctx) HashMap<String,ITypedVariable>(ctx));
	int maxLoop = this->stackFrames->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubStackFrame* subFrame = this->stackFrames->get(i, ctx);
		TypedVariableContainer* container = subFrame->getTypedContainer(ctx);
		container->addVariablesToList(valmap, ctx);
	}
	return valmap;
}
bool AbstractStackFrame::hasSubStack(ThreadContext* ctx) throw() 
{
	return !stackFrames->isEmpty(ctx);
}
IStackFrame* AbstractStackFrame::pop(ThreadContext* ctx) throw() 
{
	SubStackFrame* frame = this->stackFrames->peek(ctx);
	if(frame->hasSubStack(ctx))
	{
		return frame->pop(ctx);
	}
	return this->stackFrames->pop(ctx);
}
IStackFrame* AbstractStackFrame::peek(ThreadContext* ctx) throw() 
{
	if(this->stackFrames->isEmpty(ctx))
	{
		return this;
	}
	return this->stackFrames->peek(ctx);
}
DomVariableContainer* AbstractStackFrame::getVariableContainer(ThreadContext* ctx) throw() 
{
	return container;
}
TypedVariableContainer* AbstractStackFrame::getTypedContainer(ThreadContext* ctx) throw() 
{
	return typedContainer;
}
void AbstractStackFrame::outSubframeDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	int maxLoop = this->stackFrames->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubStackFrame* subFrame = this->stackFrames->get(i, ctx);
		subFrame->outDebugXml(parentNode, ctx);
	}
}
void AbstractStackFrame::importInnerFromXml(DomNode* node, AbstractStackFrame* frame, ThreadContext* ctx) throw() 
{
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		String* nodeName = n->getName(ctx);
		if(nodeName->equals(DomVariableContainer::TAG_DOM_VARIABLE_CONTAINER, ctx))
		{
			__GC_MV(frame, &(frame->container), DomVariableContainer::importFromDebugXml(n, ctx), DomVariableContainer);
		}
				else 
		{
			if(nodeName->equals(TypedVariableContainer::TAG_TYPED_VARIABLE_CONTAINER, ctx))
			{
				__GC_MV(frame, &(frame->typedContainer), TypedVariableContainer::importFromDebugXml(n, ctx), TypedVariableContainer);
			}
						else 
			{
				if(nodeName->equals(SubStackFrame::TAG_SUB_STACKFRAME, ctx))
				{
					SubStackFrame* sub = SubStackFrame::importFromDebugXml(n, frame->container, ctx);
					frame->stackFrames->push(sub, ctx);
				}
			}
		}
	}
}
}}}

