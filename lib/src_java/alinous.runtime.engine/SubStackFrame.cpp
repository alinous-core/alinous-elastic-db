#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/HttpUploadParameter.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.engine/DebugMainFrameSrcElement.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.engine/HttpParamHandler.h"

namespace alinous {namespace runtime {namespace engine {





String* SubStackFrame::TAG_SUB_STACKFRAME = ConstStr::getCNST_STR_1175();
String* SubStackFrame::ATTR_LINE = ConstStr::getCNST_STR_1166();
String* SubStackFrame::ATTR_FILENAME = ConstStr::getCNST_STR_1167();
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
void SubStackFrame::__cleanUp(ThreadContext* ctx){
}
}}}

