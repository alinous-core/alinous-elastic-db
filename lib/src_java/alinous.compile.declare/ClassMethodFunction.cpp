#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool ClassMethodFunction::__init_done = __init_static_variables();
bool ClassMethodFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassMethodFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassMethodFunction::~ClassMethodFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassMethodFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassMethodFunction", L"~ClassMethodFunction");
	__e_obj1.add(this->func, this);
	func = nullptr;
	__e_obj1.add(this->vtable, this);
	vtable = nullptr;
	__e_obj1.add(this->superConstructor, this);
	superConstructor = nullptr;
	if(!prepare){
		return;
	}
	AbstractClassMember::__releaseRegerences(true, ctx);
}
bool ClassMethodFunction::sameSig(ClassMethodFunction* other, ThreadContext* ctx) throw() 
{
	return this->func->sameSig(other->func, ctx);
}
bool ClassMethodFunction::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->modifier != nullptr && !this->modifier->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->func != nullptr && !this->func->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
int ClassMethodFunction::getMemberType(ThreadContext* ctx) throw() 
{
	if(isStatic(ctx))
	{
		return IClassMember::STATIC_CLASS_METHOD;
	}
	return IClassMember::CLASS_METHOD;
}
int ClassMethodFunction::getArgumentsSize(ThreadContext* ctx) throw() 
{
	FunctionArgumentsListDefine* argdef = this->func->getArguments(ctx);
	return argdef->getList(ctx)->size(ctx);
}
ArrayList<FunctionArgumentDefine>* ClassMethodFunction::getArgumentsDefine(ThreadContext* ctx) throw() 
{
	FunctionArgumentsListDefine* argdef = this->func->getArguments(ctx);
	return argdef->getList(ctx);
}
AlinousFunction* ClassMethodFunction::getFunc(ThreadContext* ctx) throw() 
{
	return func;
}
void ClassMethodFunction::setFunc(AlinousFunction* func, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->func), func, AlinousFunction);
}
bool ClassMethodFunction::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->constructorMethod)
	{
		bool result = analyseConstructorMethod(context, ctx);
		if(!result)
		{
			return false;
		}
	}
	this->func->analyse(context, false, ctx);
	return true;
}
ClassMethodFunction* ClassMethodFunction::getConstructorCall(ThreadContext* ctx) throw() 
{
	return this->superConstructor;
}
String* ClassMethodFunction::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->modifier->toString(ctx), ctx)->append(ConstStr::getCNST_STR_380(), ctx);
	if(this->func != nullptr)
	{
		buff->append(this->func->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
AlinousClass* ClassMethodFunction::getAlinousClass(ThreadContext* ctx) throw() 
{
	return static_cast<AlinousClass*>(this->parent);
}
bool ClassMethodFunction::isConstructorMethod(ThreadContext* ctx) throw() 
{
	return constructorMethod;
}
void ClassMethodFunction::setConstructorMethod(bool constructorMethod, ThreadContext* ctx) throw() 
{
	this->constructorMethod = constructorMethod;
}
ClassMethodFunction* ClassMethodFunction::getSuperConstructor(ThreadContext* ctx) throw() 
{
	return superConstructor;
}
bool ClassMethodFunction::isVirtualMethod(ThreadContext* ctx) throw() 
{
	return virtualMethod;
}
void ClassMethodFunction::setVirtualMethod(bool virtualMethod, ThreadContext* ctx) throw() 
{
	this->virtualMethod = virtualMethod;
}
ClassMethodFunction* ClassMethodFunction::resolveVirtual(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	if(!this->virtualMethod)
	{
		return this;
	}
	return this->vtable->getMethod(clazz, ctx);
}
VirtualTable* ClassMethodFunction::getVtable(ThreadContext* ctx) throw() 
{
	return vtable;
}
void ClassMethodFunction::setVtable(VirtualTable* vtable, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vtable), vtable, VirtualTable);
}
void ClassMethodFunction::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousFunction*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_977(), ctx));
		}
		__GC_MV(this, &(this->func), static_cast<AlinousFunction*>(el), AlinousFunction);
	}
	this->constructorMethod = buff->getBoolean(ctx);
	this->virtualMethod = buff->getBoolean(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<VirtualTable*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_978(), ctx));
		}
		__GC_MV(this, &(this->vtable), static_cast<VirtualTable*>(el), VirtualTable);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassMethodFunction*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_971(), ctx));
		}
		__GC_MV(this, &(this->superConstructor), static_cast<ClassMethodFunction*>(el), ClassMethodFunction);
	}
}
void ClassMethodFunction::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ClassMethodFunction, ctx);
	bool isnull = (this->func == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->func->writeData(buff, ctx);
	}
	buff->putBoolean(this->constructorMethod, ctx);
	buff->putBoolean(this->virtualMethod, ctx);
	isnull = (this->vtable == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vtable->writeData(buff, ctx);
	}
	isnull = (this->superConstructor == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->superConstructor->writeData(buff, ctx);
	}
}
bool ClassMethodFunction::analyseConstructorMethod(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->superConstructor), nullptr, ClassMethodFunction);
	FunctionCallExpression* exp = this->func->callSuperConstructor(ctx);
	if(exp != nullptr)
	{
		return true;
	}
	AlinousClass* clazz = getAlinousClass(ctx);
	while(clazz->getExtendsClasses(ctx) != nullptr)
	{
		AlinousClass* superClazz = clazz->getExtendsClasses(ctx)->getAnalysedClazz(ctx);
		FunctionArguments* blankArg = (new(ctx) FunctionArguments(ctx));
		__GC_MV(this, &(this->superConstructor), superClazz->getConstructorFunction(blankArg, ctx), ClassMethodFunction);
		if(this->superConstructor != nullptr)
		{
			return true;
		}
		clazz = superClazz;
	}
	return true;
}
}}}

