#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool DomNameSegment::__init_done = __init_static_variables();
bool DomNameSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomNameSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomNameSegment::DomNameSegment(String* name, ThreadContext* ctx) throw()  : IObject(ctx), IDomSegment(ctx), name(nullptr), segmentVariableType(IDomVariable::TYPE_DOM)
{
	__GC_MV(this, &(this->name), name, String);
}
void DomNameSegment::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
 DomNameSegment::~DomNameSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomNameSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomNameSegment", L"~DomNameSegment");
	__e_obj1.add(this->name, this);
	name = nullptr;
	if(!prepare){
		return;
	}
	IDomSegment::__releaseRegerences(true, ctx);
}
String* DomNameSegment::toString(ThreadContext* ctx) throw() 
{
	return this->name;
}
String* DomNameSegment::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void DomNameSegment::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
int DomNameSegment::getDomSegmentType(ThreadContext* ctx) throw() 
{
	return IDomSegment::TYPE_NORMAL;
}
IExpression* DomNameSegment::getIndex(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomNameSegment::getSegmentVariableType(ThreadContext* ctx) throw() 
{
	return segmentVariableType;
}
void DomNameSegment::setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw() 
{
	this->segmentVariableType = segmentVariableType;
}
bool DomNameSegment::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
int DomNameSegment::getLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getLine(ctx);
}
int DomNameSegment::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getStartPosition(ctx);
}
int DomNameSegment::getEndLine(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndLine(ctx);
}
int DomNameSegment::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDomSegment::getEndPosition(ctx);
}
AbstractSrcElement* DomNameSegment::getParent(ThreadContext* ctx) throw() 
{
	return IDomSegment::getParent(ctx);
}
void DomNameSegment::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDomSegment::setParent(parent, ctx);
}
void DomNameSegment::position(Token* t2, AbstractSrcElement* segment, ThreadContext* ctx) throw() 
{
	IDomSegment::position(t2, segment, ctx);
}
void DomNameSegment::position(Token* start, Token* end, ThreadContext* ctx) throw() 
{
	IDomSegment::position(start, end, ctx);
}
}}}

