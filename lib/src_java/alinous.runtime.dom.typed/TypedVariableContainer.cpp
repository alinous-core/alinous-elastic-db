#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableDomFactory.h"
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
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"

namespace alinous {namespace runtime {namespace dom {namespace typed {





String* TypedVariableContainer::TAG_TYPED_VARIABLE_CONTAINER = ConstStr::getCNST_STR_1152();
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
 TypedVariableContainer::TypedVariableContainer(ThreadContext* ctx) throw()  : IObject(ctx), variables(GCUtils<HashMap<String,ITypedVariable> >::ins(this, (new(ctx) HashMap<String,ITypedVariable>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TypedVariableContainer::__construct_impl(ThreadContext* ctx) throw() 
{
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
void TypedVariableContainer::includes(TypedVariableDomFactory* arg0, ThreadContext* ctx) throw() 
{
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
void TypedVariableContainer::__cleanUp(ThreadContext* ctx){
}
}}}}

