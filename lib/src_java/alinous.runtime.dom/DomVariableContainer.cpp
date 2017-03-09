#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom/IVariableClassOperationCaller.h"
#include "alinous.runtime.dom/VariableOperationCaller.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.runtime.dom/DomVariableDebugXmlFactory.h"
#include "alinous.runtime.dom/DomVariableContainer.h"

namespace alinous {namespace runtime {namespace dom {





String* DomVariableContainer::TAG_DOM_VARIABLE_CONTAINER = ConstStr::getCNST_STR_1188();
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
 DomVariableContainer::DomVariableContainer(ThreadContext* ctx) throw()  : IObject(ctx), IDomVariableContainer(ctx), variables(GCUtils<HashMap<String,IDomVariable> >::ins(this, (new(ctx) HashMap<String,IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void DomVariableContainer::__construct_impl(ThreadContext* ctx) throw() 
{
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
void DomVariableContainer::__cleanUp(ThreadContext* ctx){
}
}}}

