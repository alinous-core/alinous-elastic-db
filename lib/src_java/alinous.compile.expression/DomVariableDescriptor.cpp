#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool DomVariableDescriptor::__init_done = __init_static_variables();
bool DomVariableDescriptor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariableDescriptor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariableDescriptor::~DomVariableDescriptor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariableDescriptor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomVariableDescriptor", L"~DomVariableDescriptor");
	__e_obj1.add(this->segments, this);
	segments = nullptr;
	__e_obj1.add(this->prefix, this);
	prefix = nullptr;
	__e_obj1.add(this->domDeclare, this);
	domDeclare = nullptr;
	if(!prepare){
		return;
	}
	IExpression::__releaseRegerences(true, ctx);
}
void DomVariableDescriptor::addSegment(IDomSegment* seg, ThreadContext* ctx) throw() 
{
	if(IDomSegment::TYPE_INDEX == seg->getDomSegmentType(ctx))
	{
		IDomSegment* peekSeg = this->segments->get(this->segments->size(ctx) - 1, ctx);
		peekSeg->setSegmentVariableType(IDomSegment::TYPE_INDEX, ctx);
	}
	this->segments->add(seg, ctx);
}
String* DomVariableDescriptor::getLastName(ThreadContext* ctx) throw() 
{
	IDomSegment* seg = this->segments->get(this->segments->size(ctx) - 1, ctx);
	if(seg->getDomSegmentType(ctx) == IDomSegment::TYPE_INDEX)
	{
		return nullptr;
	}
	return (static_cast<DomNameSegment*>(seg))->getName(ctx);
}
int DomVariableDescriptor::getLastIndex(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IDomSegment* seg = this->segments->get(this->segments->size(ctx) - 1, ctx);
	if(seg->getDomSegmentType(ctx) == IDomSegment::TYPE_INDEX)
	{
		return -1;
	}
	return machine->resolveExpression((static_cast<DomIndexSegment*>(seg))->getIndex(ctx), debug, ctx)->toIntVariable(ctx)->getIntValue(ctx);
}
IAlinousVariable* DomVariableDescriptor::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return machine->getByDescriptor(this, debug, ctx);
}
bool DomVariableDescriptor::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool DomVariableDescriptor::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
void DomVariableDescriptor::markLastSegmentAsArray(ThreadContext* ctx) throw() 
{
	int index = this->segments->size(ctx) - 1;
	this->segments->get(index, ctx)->setSegmentVariableType(IDomVariable::TYPE_ARRAY, ctx);
}
String* DomVariableDescriptor::getPrefix(ThreadContext* ctx) throw() 
{
	return prefix;
}
void DomVariableDescriptor::setPrefix(String* prefix, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->prefix), prefix, String);
}
ArrayList<IDomSegment>* DomVariableDescriptor::getSegments(ThreadContext* ctx) throw() 
{
	return segments;
}
bool DomVariableDescriptor::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* holder = context->getCurrentStack(ctx);
	String* id = getSourceId(ctx)->getId(ctx);
	__GC_MV(this, &(this->domDeclare), holder->getDomDeclare(ctx)->get(id, ctx), DomVariableDeclareSource);
	if(this->domDeclare == nullptr)
	{
		DomVariableDeclareSource* decsrc = (new(ctx) DomVariableDeclareSource(id, this, ctx));
		holder->getDomDeclare(ctx)->put(id, decsrc, ctx);
	}
	return true;
}
String* DomVariableDescriptor::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->prefix != nullptr)
	{
		buff->append(this->prefix, ctx)->append(ConstStr::getCNST_STR_380(), ctx);
	}
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomSegment* seg = this->segments->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(seg->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
ExpressionSourceId* DomVariableDescriptor::getSourceId(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomSegment* seg = this->segments->get(i, ctx);
		int segType = seg->getDomSegmentType(ctx);
		switch(segType) {
		case IDomSegment::TYPE_NORMAL:
			if(i != 0)
			{
				buff->append(ConstStr::getCNST_STR_950(), ctx);
			}
			buff->append(seg->toString(ctx), ctx);
			break ;
		default:
			buff->append(seg->toString(ctx), ctx);
			break ;
		}
	}
	return (new(ctx) ExpressionSourceId(buff->toString(ctx), this, (new(ctx) AlinousType(ctx)), ctx));
}
DomVariableDeclareSource* DomVariableDescriptor::getDomDeclare(ThreadContext* ctx) throw() 
{
	return domDeclare;
}
int DomVariableDescriptor::getLine(ThreadContext* ctx) throw() 
{
	return IExpression::getLine(ctx);
}
int DomVariableDescriptor::getStartPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getStartPosition(ctx);
}
int DomVariableDescriptor::getEndLine(ThreadContext* ctx) throw() 
{
	return IExpression::getEndLine(ctx);
}
int DomVariableDescriptor::getEndPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getEndPosition(ctx);
}
AbstractSrcElement* DomVariableDescriptor::getParent(ThreadContext* ctx) throw() 
{
	return IExpression::getParent(ctx);
}
void DomVariableDescriptor::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IExpression::setParent(parent, ctx);
}
bool DomVariableDescriptor::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int DomVariableDescriptor::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::domVariableDescriptor;
}
void DomVariableDescriptor::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IDomSegment*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_993(), ctx));
		}
		this->segments->add(static_cast<IDomSegment*>(el), ctx);
	}
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->prefix), buff->getString(ctx), String);
	}
}
void DomVariableDescriptor::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__DomVariableDescriptor, ctx);
	int maxLoop = this->segments->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IDomSegment* exp = this->segments->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	bool isnull = (this->prefix == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->prefix, ctx);
	}
}
}}}

