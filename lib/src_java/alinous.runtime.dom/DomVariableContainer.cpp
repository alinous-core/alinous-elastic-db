#include "includes.h"


namespace alinous {namespace runtime {namespace dom {





String* DomVariableContainer::TAG_DOM_VARIABLE_CONTAINER = ConstStr::getCNST_STR_1110();
bool DomVariableContainer::__init_done = __init_static_variables();
bool DomVariableContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariableContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariableContainer::~DomVariableContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariableContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomVariableContainer", L"~DomVariableContainer");
	__e_obj1.add(this->variables, this);
	variables = nullptr;
	if(!prepare){
		return;
	}
}
IDomVariable* DomVariableContainer::get(String* key, ThreadContext* ctx) throw() 
{
	return this->variables->get(key, ctx);
}
void DomVariableContainer::addVariablesToList(Map<String,IDomVariable>* list, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->variables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		IDomVariable* variable = this->variables->get(key, ctx);
		list->put(key, variable, ctx);
	}
}
void DomVariableContainer::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(DomVariableContainer::TAG_DOM_VARIABLE_CONTAINER, ctx));
	parentNode->addChild(node, ctx);
	Iterator<String>* it = this->variables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		IDomVariable* variable = this->variables->get(key, ctx);
		variable->outDebugXml(node, key, ctx);
	}
}
void DomVariableContainer::putVariable(DomVariableDescriptor* desc, IDomVariable* variable, ThreadContext* ctx) throw() 
{
}
IDomVariable* DomVariableContainer::getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DomVariableContainer::setProperty(String* key, IDomVariable* value, ThreadContext* ctx) throw() 
{
	this->variables->put(key, value, ctx);
}
IDomVariableContainer* DomVariableContainer::getProperty(String* key, ThreadContext* ctx) throw() 
{
	return this->variables->get(key, ctx);
}
IDomVariableContainer* DomVariableContainer::get(int index, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DomVariableContainer::set(IDomVariable* val, int index, ThreadContext* ctx) throw() 
{
}
DomVariableContainer* DomVariableContainer::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(DomVariableContainer::TAG_DOM_VARIABLE_CONTAINER, ctx))
	{
		return nullptr;
	}
	DomVariableContainer* container = (new(ctx) DomVariableContainer(ctx));
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		IDomVariable* val = DomVariableDebugXmlFactory::getDom(n, ctx);
		if(val != nullptr)
		{
			IVariableValue* nameattr = n->getAttributeValue(IAlinousVariable::ATTR_NAME, ctx);
			if(nameattr == nullptr)
			{
				continue;
			}
			String* key = nameattr->toString(ctx);
			container->setProperty(key, val, ctx);
		}
	}
	return container;
}
}}}

