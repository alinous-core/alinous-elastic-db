#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* TypedVariableContainer::TAG_TYPED_VARIABLE_CONTAINER = ConstStr::getCNST_STR_1147();
bool TypedVariableContainer::__init_done = __init_static_variables();
bool TypedVariableContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TypedVariableContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TypedVariableContainer::~TypedVariableContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TypedVariableContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TypedVariableContainer", L"~TypedVariableContainer");
	__e_obj1.add(this->variables, this);
	variables = nullptr;
	if(!prepare){
		return;
	}
}
void TypedVariableContainer::addVariablesToList(Map<String,ITypedVariable>* list, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->variables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		ITypedVariable* variable = this->variables->get(key, ctx);
		list->put(key, variable, ctx);
	}
}
void TypedVariableContainer::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TypedVariableContainer::TAG_TYPED_VARIABLE_CONTAINER, ctx));
	parentNode->addChild(node, ctx);
	Iterator<String>* it = this->variables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		ITypedVariable* variable = this->variables->get(key, ctx);
		variable->outDebugXml(node, key, ctx);
	}
}
ITypedVariable* TypedVariableContainer::get(String* name, ThreadContext* ctx) throw() 
{
	return this->variables->get(name, ctx);
}
void TypedVariableContainer::put(String* name, ITypedVariable* variable, ThreadContext* ctx) throw() 
{
	this->variables->put(name, variable, ctx);
}
TypedVariableContainer* TypedVariableContainer::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(TypedVariableContainer::TAG_TYPED_VARIABLE_CONTAINER, ctx))
	{
		return nullptr;
	}
	TypedVariableContainer* container = (new(ctx) TypedVariableContainer(ctx));
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		AbstractTypedVariable* variable = TypedVariableDomFactory::importFromDomNode(node, ctx);
		if(variable != nullptr)
		{
			IVariableValue* nameattr = n->getAttributeValue(IAlinousVariable::ATTR_NAME, ctx);
			if(nameattr == nullptr)
			{
				continue;
			}
			String* key = nameattr->toString(ctx);
			container->put(key, variable, ctx);
		}
	}
	return container;
}
}}}}

