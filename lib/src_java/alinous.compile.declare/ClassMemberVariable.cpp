#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool ClassMemberVariable::__init_done = __init_static_variables();
bool ClassMemberVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassMemberVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassMemberVariable::~ClassMemberVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassMemberVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassMemberVariable", L"~ClassMemberVariable");
	__e_obj1.add(this->type, this);
	type = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->domDescriptor, this);
	domDescriptor = nullptr;
	__e_obj1.add(this->init, this);
	init = nullptr;
	__e_obj1.add(this->staticValue, this);
	staticValue = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	AbstractClassMember::__releaseRegerences(true, ctx);
}
void ClassMemberVariable::initStatic(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	__GC_MV(this, &(this->staticValue), machine->resolveExpression(this->init, debug, ctx), IAlinousVariable);
}
void ClassMemberVariable::initMember(AlinousClassVariable* obj, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->init != nullptr)
	{
		IAlinousVariable* val = this->init->resolveExpression(machine, debug, ctx);
		obj->setMemberVariable(getMemberName(ctx), val, ctx);
		return;
	}
	String* memberName = getMemberName(ctx);
	obj->setMemberVariable(memberName, this->analysedType->makeDefault(ctx), ctx);
}
String* ClassMemberVariable::getMemberName(ThreadContext* ctx) throw() 
{
	if(this->name != nullptr)
	{
		return this->name->toString(ctx);
	}
	return this->domDescriptor->getLastName(ctx);
}
bool ClassMemberVariable::isSame(String* name, ThreadContext* ctx) throw() 
{
	if(this->name != nullptr)
	{
		return this->name->toString(ctx)->equals(name, ctx);
	}
	return this->domDescriptor->getLastName(ctx)->equals(name, ctx);
}
bool ClassMemberVariable::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->modifier != nullptr && !this->modifier->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->type != nullptr && !this->type->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->domDescriptor != nullptr && !this->domDescriptor->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->init != nullptr && !this->init->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
int ClassMemberVariable::getMemberType(ThreadContext* ctx) throw() 
{
	if(isStatic(ctx))
	{
		return IClassMember::STATIC_CLASS_VARIABLE;
	}
	return IClassMember::CLASS_VARIABLE;
}
AlinousName* ClassMemberVariable::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void ClassMemberVariable::setType(AlinousName* type, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->type), type, AlinousName);
}
AlinousName* ClassMemberVariable::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void ClassMemberVariable::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
DomVariableDescriptor* ClassMemberVariable::getDomDescriptor(ThreadContext* ctx) throw() 
{
	return domDescriptor;
}
void ClassMemberVariable::setDomDescriptor(DomVariableDescriptor* domDescriptor, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domDescriptor), domDescriptor, DomVariableDescriptor);
}
IExpression* ClassMemberVariable::getInit(ThreadContext* ctx) throw() 
{
	return init;
}
void ClassMemberVariable::setInit(IExpression* init, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->init), init, IExpression);
}
bool ClassMemberVariable::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->type != nullptr)
	{
		__GC_MV(this, &(this->analysedType), this->type->toAlinousType(context, ctx), AlinousType);
		this->analysedType->setDimension(this->dimension, ctx);
	}
		else 
	{
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::NULL_TYPE, AlinousType::TYPE_DOM, ctx)), AlinousType);
	}
	if(this->init != nullptr)
	{
		this->init->analyse(context, leftValue, ctx);
	}
	return true;
}
AlinousType* ClassMemberVariable::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
IAlinousVariable* ClassMemberVariable::getStaticValue(ThreadContext* ctx) throw() 
{
	return staticValue;
}
int ClassMemberVariable::getDimension(ThreadContext* ctx) throw() 
{
	return dimension;
}
void ClassMemberVariable::setDimension(int dimension, ThreadContext* ctx) throw() 
{
	this->dimension = dimension;
}
}}}

