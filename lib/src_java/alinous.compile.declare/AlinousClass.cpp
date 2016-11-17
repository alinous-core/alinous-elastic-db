#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool AlinousClass::__init_done = __init_static_variables();
bool AlinousClass::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousClass", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousClass::~AlinousClass() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousClass::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousClass", L"~AlinousClass");
	__e_obj1.add(this->packageName, this);
	packageName = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->extendsClasses, this);
	extendsClasses = nullptr;
	__e_obj1.add(this->implementsClass, this);
	implementsClass = nullptr;
	__e_obj1.add(this->constructors, this);
	constructors = nullptr;
	__e_obj1.add(this->members, this);
	members = nullptr;
	__e_obj1.add(this->methods, this);
	methods = nullptr;
	__e_obj1.add(this->staticMembers, this);
	staticMembers = nullptr;
	__e_obj1.add(this->staticMethods, this);
	staticMethods = nullptr;
	__e_obj1.add(this->delivedClasses, this);
	delivedClasses = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
void AlinousClass::initStatic(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMemberVariable* val = this->staticMembers->get(i, ctx);
		val->initStatic(machine, debug, ctx);
	}
}
bool AlinousClass::hasBaseClass(AlinousClass* other, ThreadContext* ctx) throw() 
{
	if(equals(other, ctx))
	{
		return true;
	}
	AlinousClass* clazz = this->extendsClasses->getAnalysedClazz(ctx);
	return clazz->hasBaseClass(other, ctx);
}
bool AlinousClass::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<AlinousClass*>(obj) != 0)))
	{
		return false;
	}
	AlinousClass* other = dynamic_cast<AlinousClass*>(obj);
	return this->packageName->equals(other->packageName, ctx) && this->name->equals(other->name, ctx);
}
ClassMemberVariable* AlinousClass::getStaticMemberVariable(String* name, ThreadContext* ctx) throw() 
{
	int maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMemberVariable* val = this->staticMembers->get(i, ctx);
		if(val->getName(ctx)->equals(name, ctx))
		{
			return val;
		}
	}
	return nullptr;
}
ClassMethodFunction* AlinousClass::getMemberMethod(String* functionName, FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	ArrayList<ClassMethodFunction>* candidates = (new(ctx) ArrayList<ClassMethodFunction>(ctx));
	int maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* m = this->methods->get(i, ctx);
		if(m->getFunc(ctx)->getName(ctx)->equals(functionName, ctx))
		{
			candidates->add(m, ctx);
		}
	}
	ClassMethodArgumentMatcher* matcher = (new(ctx) ClassMethodArgumentMatcher(arguments, candidates, ctx));
	MatchingMethodCandidate* constructorDeclare = matcher->match(ctx);
	if(constructorDeclare != nullptr)
	{
		return constructorDeclare->getMethod(ctx);
	}
	if(this->getExtendsClasses(ctx) != nullptr)
	{
		AlinousClass* superClazz = this->getExtendsClasses(ctx)->getAnalysedClazz(ctx);
		return superClazz->getMemberMethod(functionName, arguments, ctx);
	}
	return nullptr;
}
ClassMethodFunction* AlinousClass::getStaticMemberMethod(String* functionName, FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	ArrayList<ClassMethodFunction>* candidates = (new(ctx) ArrayList<ClassMethodFunction>(ctx));
	int maxLoop = this->staticMethods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* m = this->staticMethods->get(i, ctx);
		if(m->getFunc(ctx)->getName(ctx)->equals(functionName, ctx))
		{
			candidates->add(m, ctx);
		}
	}
	ClassMethodArgumentMatcher* matcher = (new(ctx) ClassMethodArgumentMatcher(arguments, candidates, ctx));
	MatchingMethodCandidate* constructorDeclare = matcher->match(ctx);
	if(constructorDeclare != nullptr)
	{
		return constructorDeclare->getMethod(ctx);
	}
	return nullptr;
}
ClassMethodFunction* AlinousClass::getConstructorFunction(FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	ClassMethodArgumentMatcher* matcher = (new(ctx) ClassMethodArgumentMatcher(arguments, this->constructors, ctx));
	MatchingMethodCandidate* constructorDeclare = matcher->match(ctx);
	if(constructorDeclare != nullptr)
	{
		return constructorDeclare->getMethod(ctx);
	}
	return nullptr;
}
void AlinousClass::invokeStaticMemberMethod(ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	{
		try
		{
			AlinousFunction* func = method->getFunc(ctx);
			machine->newStackFrame(func, ctx);
			MainStackFrame* frame = machine->getFrame(ctx);
			frame->subFrame(func->getBlock(ctx), ctx);
			ArrayList<IAlinousVariable>* args = (new(ctx) ArrayList<IAlinousVariable>(ctx));
			ArrayList<FunctionArgumentDefine>* definelist = func->getArguments(ctx)->getList(ctx);
			ArrayList<IExpression>* actualArgs = arguments->arguments;
			int maxLoop = definelist->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* value = actualArgs->get(i, ctx);
				IAlinousVariable* variable = machine->resolveExpression(value, debug, ctx);
				args->add(variable, ctx);
			}
			for(int i = 0; i != maxLoop; ++i)
			{
				FunctionArgumentDefine* def = definelist->get(i, ctx);
				IAlinousVariable* variable = args->get(i, ctx);
				def->putArgument(machine, frame, variable, debug, ctx);
			}
			StatementList* stmtList = func->getBlock(ctx)->getList(ctx);
			if(stmtList != nullptr)
			{
				ScriptRunner::executeStatementList(stmtList, machine, debug, ctx);
			}
		}
		catch(Throwable* e)
		{
			machine->popStackFrame(ctx);
			throw e;
		}
	}
	machine->popStackFrame(ctx);
}
void AlinousClass::invokeMemberMethod(AlinousClassVariable* obj, ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	{
		try
		{
			AlinousFunction* func = method->getFunc(ctx);
			machine->newStackFrame(func, ctx);
			MainStackFrame* frame = machine->getFrame(ctx);
			machine->setThisPtr(obj, ctx);
			frame->subFrame(func->getBlock(ctx), ctx);
			ArrayList<IAlinousVariable>* args = (new(ctx) ArrayList<IAlinousVariable>(ctx));
			ArrayList<FunctionArgumentDefine>* definelist = func->getArguments(ctx)->getList(ctx);
			ArrayList<IExpression>* actualArgs = arguments->arguments;
			int maxLoop = definelist->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* value = actualArgs->get(i, ctx);
				IAlinousVariable* variable = machine->resolveExpression(value, debug, ctx);
				args->add(variable, ctx);
			}
			for(int i = 0; i != maxLoop; ++i)
			{
				FunctionArgumentDefine* def = definelist->get(i, ctx);
				IAlinousVariable* variable = args->get(i, ctx);
				def->putArgument(machine, frame, variable, debug, ctx);
			}
			StatementList* stmtList = func->getBlock(ctx)->getList(ctx);
			if(stmtList != nullptr)
			{
				ScriptRunner::executeStatementList(stmtList, machine, debug, ctx);
			}
		}
		catch(Throwable* e)
		{
			machine->popStackFrame(ctx);
			throw e;
		}
	}
	machine->popStackFrame(ctx);
}
void AlinousClass::invokeConstructorMethod(AlinousClassVariable* obj, ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	{
		try
		{
			AlinousFunction* func = method->getFunc(ctx);
			machine->newStackFrame(func, ctx);
			MainStackFrame* frame = machine->getFrame(ctx);
			machine->setThisPtr(obj, ctx);
			frame->subFrame(func->getBlock(ctx), ctx);
			initMembers(obj, machine, debug, ctx);
			ArrayList<IAlinousVariable>* args = (new(ctx) ArrayList<IAlinousVariable>(ctx));
			ArrayList<FunctionArgumentDefine>* definelist = func->getArguments(ctx)->getList(ctx);
			ArrayList<IExpression>* actualArgs = arguments->arguments;
			int maxLoop = definelist->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* value = actualArgs->get(i, ctx);
				IAlinousVariable* variable = machine->resolveExpression(value, debug, ctx);
				args->add(variable, ctx);
			}
			for(int i = 0; i != maxLoop; ++i)
			{
				FunctionArgumentDefine* def = definelist->get(i, ctx);
				IAlinousVariable* variable = args->get(i, ctx);
				def->putArgument(machine, frame, variable, debug, ctx);
			}
			if(method->getSuperConstructor(ctx) != nullptr)
			{
				ClassMethodFunction* superConst = method->getSuperConstructor(ctx);
				AlinousClass* superClazz = superConst->getAlinousClass(ctx);
				superClazz->invokeConstructorMethod(obj, superConst, arguments, machine, debug, ctx);
			}
			StatementList* stmtList = func->getBlock(ctx)->getList(ctx);
			if(stmtList != nullptr)
			{
				ScriptRunner::executeStatementList(stmtList, machine, debug, ctx);
			}
		}
		catch(Throwable* e)
		{
			machine->popStackFrame(ctx);
			throw e;
		}
	}
	machine->popStackFrame(ctx);
}
bool AlinousClass::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->extendsClasses != nullptr && !this->extendsClasses->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->implementsClass == nullptr ? 0 : this->implementsClass->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->implementsClass->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->constructors->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->constructors->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->members->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->members->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->methods->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->staticMembers->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->staticMethods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->staticMethods->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
void AlinousClass::analyseVirtualMethods(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* method = this->methods->get(i, ctx);
		analyzeMethodVirtual(context, method, ctx);
	}
}
ClassMethodFunction* AlinousClass::getOverrodeMethod(ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	int maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* m = this->methods->get(i, ctx);
		if(method->sameSig(m, ctx))
		{
			return m;
		}
	}
	return nullptr;
}
void AlinousClass::analyseDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	if(this->extendsClasses != nullptr)
	{
		this->extendsClasses->analyse(context, false, ctx);
		AlinousClass* baseClass = this->extendsClasses->getAnalysedClazz(ctx);
		if(baseClass == nullptr)
		{
			AlinousName* className = this->extendsClasses->getClassName(ctx);
			context->getSourceValidator(ctx)->addError(className->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_966(), ctx), this, ctx);
			return;
		}
		baseClass->delivedClasses->add(this, ctx);
	}
	if(this->implementsClass != nullptr)
	{
		Iterator<ClassImplements>* it = this->implementsClass->iterator(ctx);
		while(it->hasNext(ctx))
		{
			ClassImplements* impl = it->next(ctx);
			impl->analyse(context, false, ctx);
			AlinousClass* baseClass = impl->getAnalysedClazz(ctx);
			if(baseClass == nullptr)
			{
				AlinousName* className = impl->getClassName(ctx);
				context->getSourceValidator(ctx)->addError(className->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_966(), ctx), this, ctx);
				return;
			}
			baseClass->delivedClasses->add(this, ctx);
		}
	}
}
bool AlinousClass::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->name != nullptr)
	{
		this->name->analyse(context, leftValue, ctx);
	}
	if(this->extendsClasses != nullptr)
	{
		this->extendsClasses->analyse(context, leftValue, ctx);
	}
	int maxLoop = this->implementsClass == nullptr ? 0 : this->implementsClass->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->implementsClass->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->members->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->members->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->constructors->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->constructors->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->methods->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->staticMembers->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->staticMethods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->staticMethods->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
AlinousName* AlinousClass::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void AlinousClass::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
ClassExtends* AlinousClass::getExtendsClasses(ThreadContext* ctx) throw() 
{
	return extendsClasses;
}
void AlinousClass::setExtendsClasses(ClassExtends* extendsClasses, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->extendsClasses), extendsClasses, ClassExtends);
}
void AlinousClass::addVariable(ClassMemberVariable* val, ThreadContext* ctx) throw() 
{
	this->members->add(val, ctx);
}
void AlinousClass::addMethod(ClassMethodFunction* val, ThreadContext* ctx) throw() 
{
	String* funcName = val->getFunc(ctx)->getFunctionName(ctx);
	if(funcName->equals(this->name->toString(ctx), ctx))
	{
		this->constructors->add(val, ctx);
		val->setConstructorMethod(true, ctx);
		return;
	}
	this->methods->add(val, ctx);
}
void AlinousClass::addStaticVariable(ClassMemberVariable* val, ThreadContext* ctx) throw() 
{
	this->staticMembers->add(val, ctx);
}
void AlinousClass::addStaticMethod(ClassMethodFunction* val, ThreadContext* ctx) throw() 
{
	this->staticMethods->add(val, ctx);
}
ClassMemberVariable* AlinousClass::getMember(String* name, ThreadContext* ctx) throw() 
{
	Iterator<ClassMemberVariable>* it = this->members->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ClassMemberVariable* val = it->next(ctx);
		if(val->isSame(name, ctx))
		{
			return val;
		}
	}
	return nullptr;
}
ArrayList<ClassMemberVariable>* AlinousClass::getMembers(ThreadContext* ctx) throw() 
{
	return members;
}
ArrayList<ClassMethodFunction>* AlinousClass::getMethods(ThreadContext* ctx) throw() 
{
	return methods;
}
ArrayList<ClassMemberVariable>* AlinousClass::getStaticMembers(ThreadContext* ctx) throw() 
{
	return staticMembers;
}
ArrayList<ClassMethodFunction>* AlinousClass::getStaticMethods(ThreadContext* ctx) throw() 
{
	return staticMethods;
}
AlinousModulePackage* AlinousClass::getPackageName(ThreadContext* ctx) throw() 
{
	return packageName;
}
void AlinousClass::setPackageName(AlinousModulePackage* packageName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->packageName), packageName, AlinousModulePackage);
}
String* AlinousClass::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->packageName != nullptr)
	{
		buff->append(this->packageName->toString(ctx), ctx)->append(ConstStr::getCNST_STR_947(), ctx);
	}
	buff->append(this->name->toString(ctx), ctx);
	return buff->toString(ctx);
}
int AlinousClass::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int AlinousClass::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int AlinousClass::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int AlinousClass::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* AlinousClass::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void AlinousClass::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
bool AlinousClass::isInterfaceClass(ThreadContext* ctx) throw() 
{
	return interfaceClass;
}
void AlinousClass::setInterfaceClass(bool interfaceClass, ThreadContext* ctx) throw() 
{
	this->interfaceClass = interfaceClass;
}
ArrayList<ClassImplements>* AlinousClass::getImplementsClass(ThreadContext* ctx) throw() 
{
	return implementsClass;
}
void AlinousClass::setImplementsClass(ArrayList<ClassImplements>* implementsClass, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ClassImplements> >::mv(this, &(this->implementsClass), implementsClass, ctx);
}
void AlinousClass::initMembers(AlinousClassVariable* obj, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<ClassMemberVariable>* members = this->members;
	int maxLoop = members->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMemberVariable* variableDefine = members->get(i, ctx);
		variableDefine->initMember(obj, machine, debug, ctx);
	}
}
void AlinousClass::analyzeMethodVirtual(SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	bool isVirtual = false;
	Iterator<AlinousClass>* it = this->delivedClasses->iterator(ctx);
	while(it->hasNext(ctx))
	{
		AlinousClass* dclazz = it->next(ctx);
		ClassMethodFunction* m = dclazz->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			method->setVirtualMethod(true, ctx);
			isVirtual = true;
		}
	}
	ClassExtends* extClazz = this->extendsClasses;
	while(extClazz != nullptr)
	{
		AlinousClass* cl = context->findClassDeclare(extClazz->getClassName(ctx), ctx);
		ClassMethodFunction* m = cl->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			method->setVirtualMethod(true, ctx);
			isVirtual = true;
		}
		extClazz = cl->getExtendsClasses(ctx);
	}
	ArrayList<ClassImplements>* implementsClass = this->implementsClass;
	while(implementsClass != nullptr && !implementsClass->isEmpty(ctx))
	{
		Iterator<ClassImplements>* implIt = implementsClass->iterator(ctx);
		while(implIt->hasNext(ctx))
		{
			ClassImplements* impls = implIt->next(ctx);
			isVirtual = findInterfaces(impls, context, method, ctx);
		}
	}
	if(isVirtual)
	{
		createVirtualTable(context, method, ctx);
	}
}
bool AlinousClass::findInterfaces(ClassImplements* impls, SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	AlinousClass* clazz = impls->getAnalysedClazz(ctx);
	ClassExtends* extClazz = clazz->extendsClasses;
	while(extClazz != nullptr)
	{
		AlinousClass* cl = context->findClassDeclare(extClazz->getClassName(ctx), ctx);
		ClassMethodFunction* m = cl->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			method->setVirtualMethod(true, ctx);
			return true;
		}
		extClazz = cl->getExtendsClasses(ctx);
	}
	return false;
}
void AlinousClass::createVirtualTable(SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	VirtualTable* vt = (new(ctx) VirtualTable(ctx));
	method->setVtable(vt, ctx);
	vt->addVirtualFunction(this, method, ctx);
	ClassMethodFunction* currentMethod = method;
	Iterator<AlinousClass>* it = this->delivedClasses->iterator(ctx);
	while(it->hasNext(ctx))
	{
		AlinousClass* dclazz = it->next(ctx);
		ClassMethodFunction* m = dclazz->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			currentMethod = m;
		}
		vt->addVirtualFunction(dclazz, currentMethod, ctx);
	}
}
}}}

