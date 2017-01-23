#include "includes.h"


namespace alinous {namespace runtime {





bool AlinousModule::__init_done = __init_static_variables();
bool AlinousModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::AlinousModule(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx) : IObject(ctx), IAlinousElement(ctx), packageName(nullptr), path(nullptr), debugPath(nullptr), file(nullptr), compiledTime(0), moduleSource(nullptr), setupper(nullptr), core(nullptr), parent(nullptr), includedModules(GCUtils<ArrayList<AlinousModule> >::ins(this, (new(ctx) ArrayList<AlinousModule>(ctx)), ctx, __FILEW__, __LINE__, L"")), functionMap(GCUtils<HashMap<String,AlinousFunction> >::ins(this, (new(ctx) HashMap<String,AlinousFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->debugPath), file->getAbsolutePath(ctx), String);
	__GC_MV(this, &(this->debugPath), FileUtils::formatAfterAbsolutePath(this->debugPath, ctx), String);
	DebugConfigLoader* loader = (new(ctx) DebugConfigLoader(core->getConfig(ctx), ctx));
	__GC_MV(this, &(this->debugPath), loader->getDebugFilePath(this->debugPath, ctx), String);
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->file), file, File);
	this->compiledTime = System::currentTimeMillis(ctx);
	__GC_MV(this, &(this->moduleSource), moduleSource, AlinousSrc);
	__GC_MV(this, &(this->setupper), (new(ctx) AlinousModule::SetUpper(this->path, this->debugPath, ctx)), AlinousModule::SetUpper);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
void AlinousModule::__construct_impl(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->debugPath), file->getAbsolutePath(ctx), String);
	__GC_MV(this, &(this->debugPath), FileUtils::formatAfterAbsolutePath(this->debugPath, ctx), String);
	DebugConfigLoader* loader = (new(ctx) DebugConfigLoader(core->getConfig(ctx), ctx));
	__GC_MV(this, &(this->debugPath), loader->getDebugFilePath(this->debugPath, ctx), String);
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->file), file, File);
	this->compiledTime = System::currentTimeMillis(ctx);
	__GC_MV(this, &(this->moduleSource), moduleSource, AlinousSrc);
	__GC_MV(this, &(this->setupper), (new(ctx) AlinousModule::SetUpper(this->path, this->debugPath, ctx)), AlinousModule::SetUpper);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
 AlinousModule::~AlinousModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousModule", L"~AlinousModule");
	__e_obj1.add(this->packageName, this);
	packageName = nullptr;
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->debugPath, this);
	debugPath = nullptr;
	__e_obj1.add(this->file, this);
	file = nullptr;
	__e_obj1.add(this->moduleSource, this);
	moduleSource = nullptr;
	__e_obj1.add(this->setupper, this);
	setupper = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	__e_obj1.add(this->includedModules, this);
	includedModules = nullptr;
	__e_obj1.add(this->functionMap, this);
	functionMap = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
IAlinousVariable* AlinousModule::execute(ScriptMachine* machine, bool degug, ThreadContext* ctx)
{
	return executeAsScript(machine, degug, ctx);
}
IAlinousVariable* AlinousModule::execute(bool degug, ThreadContext* ctx)
{
	ScriptMachine* machine = (new(ctx) ScriptMachine(this, this->core, ctx));
	return executeAsScript(machine, degug, ctx);
}
AlinousType* AlinousModule::getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(prefix != nullptr)
	{
		buff->append(prefix, ctx)->append(ConstStr::getCNST_STR_950(), ctx);
	}
	buff->append(name, ctx);
	AlinousFunction* func = this->functionMap->get(buff->toString(ctx), ctx);
	if(func != nullptr)
	{
		AlinousType* type = func->getAnalysedReturnType(ctx);
		return type;
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		AlinousType* type = mod->getFunctionReturnType(prefix, name, ctx);
		if(type != nullptr)
		{
			return type;
		}
	}
	return nullptr;
}
bool AlinousModule::isfunctionPrefix(String* name, ThreadContext* ctx) throw() 
{
	String* prefix = name->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx);
	Iterator<String>* it = functionMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* funcName = it->next(ctx);
		if(funcName->startsWith(prefix, ctx))
		{
			return true;
		}
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		if(mod->isfunctionPrefix(name, ctx))
		{
			return true;
		}
	}
	return false;
}
AlinousFunction* AlinousModule::findFunction(String* name, ThreadContext* ctx) throw() 
{
	AlinousFunction* func = this->functionMap->get(name, ctx);
	if(func != nullptr)
	{
		return func;
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		func = mod->findFunction(name, ctx);
	}
	return nullptr;
}
void AlinousModule::init(AlinousModuleRepository* moduleRepository, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx)
{
	ArrayList<IncludePreprocessor>* inclist = moduleSource->getIncludes(ctx);
	int maxLoop = inclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IncludePreprocessor* inc = inclist->get(i, ctx);
		if(inc->getPath(ctx) == nullptr)
		{
			throw (new(ctx) AlinousNullPointerException(ctx));
		}
		AlinousModule* modinc = static_cast<AlinousModule*>(moduleRepository->getModule(inc->getPath(ctx), once, true, debug, ctx));
		if(modinc == nullptr || alreadyIncluded(static_cast<AlinousModule*>(modinc), ctx))
		{
			continue;
		}
		inc->setModule(modinc, ctx);
		(static_cast<AlinousModule*>(modinc))->setParent(this, ctx);
		this->includedModules->add(modinc, ctx);
	}
	ArrayList<AlinousFunction>* funclist = this->moduleSource->getFunctionDeclares(ctx);
	maxLoop = funclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousFunction* func = funclist->get(i, ctx);
		this->functionMap->put(func->getFunctionName(ctx), func, ctx);
	}
	this->moduleSource->setFilePath(this->setupper->getPath(ctx), ctx);
	this->moduleSource->setDebugFilePath(this->setupper->getDebugPath(ctx), ctx);
	this->moduleSource->visit(this->setupper, nullptr, ctx);
	__GC_MV(this, &(this->packageName), (new(ctx) AlinousModulePackage(this->path, ctx)), AlinousModulePackage);
	if(isInclude)
	{
		return;
	}
	SrcAnalyseContext* context = (new(ctx) SrcAnalyseContext(this, this->core->getFunctionManager(ctx), this->core->sqlFunctionManager, ctx));
	analyseClassDeclare(context, ctx);
	context->newStack(ctx);
	analyzeClassDependency(context, ctx);
	analyzeVirtualMethods(context, ctx);
	this->moduleSource->analyse(context, false, ctx);
	context->endStack(ctx);
	ScriptRunner* runner = this->core->getRunner(ctx);
	ScriptMachine* machine = (new(ctx) ScriptMachine(this, this->core, ctx));
	AlinousModule::ClassCollector* visitor = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(visitor, nullptr, ctx);
	Iterator<AlinousClass>* it = visitor->list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		AlinousClass* clazz = it->next(ctx);
		runner->initStatic(clazz, machine, debug, ctx);
	}
	machine->dispose(ctx);
}
AlinousModulePackage* AlinousModule::getPackageName(ThreadContext* ctx) throw() 
{
	return this->packageName;
}
bool AlinousModule::isDirty(ThreadContext* ctx) throw() 
{
	return this->file->lastModified(ctx) > this->compiledTime;
}
File* AlinousModule::getFile(ThreadContext* ctx) throw() 
{
	return file;
}
String* AlinousModule::getPath(ThreadContext* ctx) throw() 
{
	return path;
}
AlinousSrc* AlinousModule::getModuleSource(ThreadContext* ctx) throw() 
{
	return moduleSource;
}
AlinousModule* AlinousModule::getParent(ThreadContext* ctx) throw() 
{
	return parent;
}
void AlinousModule::setParent(AlinousModule* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, AlinousModule);
}
void AlinousModule::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		String* str = buff->getString(ctx);
		__GC_MV(this, &(this->packageName), (new(ctx) AlinousModulePackage(str, ctx)), AlinousModulePackage);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousSrc*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1099(), ctx));
		}
		__GC_MV(this, &(this->moduleSource), static_cast<AlinousSrc*>(el), AlinousSrc);
	}
}
void AlinousModule::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__AlinousModule, ctx);
	bool isnull = (this->packageName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		String* str = this->packageName->toString(ctx);
		buff->putString(str, ctx);
	}
	isnull = (this->moduleSource == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->moduleSource->writeData(buff, ctx);
	}
}
bool AlinousModule::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->moduleSource != nullptr)
	{
		this->moduleSource->analyse(context, false, ctx);
	}
	return true;
}
IAlinousVariable* AlinousModule::executeAsScript(ScriptMachine* machine, bool degug, ThreadContext* ctx)
{
	ScriptRunner* runner = this->core->getRunner(ctx);
	runner->run(this, machine, degug, ctx);
	return machine->getReturnedValue(ctx);
}
void AlinousModule::analyzeVirtualMethods(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->analyzeVirtualMethods(context, ctx);
	}
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->analyseVirtualMethods(context, ctx);
	}
}
void AlinousModule::analyzeClassDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->analyzeClassDependency(context, ctx);
	}
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->analyseDependency(context, ctx);
	}
}
void AlinousModule::analyseClassDeclare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->setPackageName(this->packageName, ctx);
		context->addClassDeclare(clazz, ctx);
	}
	ArrayList<String>* once = (new(ctx) ArrayList<String>(ctx));
	once->add(this->path, ctx);
	maxLoop = includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->exportClasses(context, once, ctx);
	}
}
void AlinousModule::exportClasses(SrcAnalyseContext* context, ArrayList<String>* once, ThreadContext* ctx) throw() 
{
	if(once->contains(path, ctx))
	{
		return;
	}
	once->add(this->path, ctx);
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->setPackageName(this->packageName, ctx);
		context->addClassDeclare(clazz, ctx);
	}
	maxLoop = includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->exportClasses(context, once, ctx);
	}
}
bool AlinousModule::alreadyIncluded(AlinousModule* modinc, ThreadContext* ctx) throw() 
{
	AlinousModule* parendMod = this->parent;
	while(parendMod != nullptr)
	{
		if(parendMod == modinc)
		{
			return true;
		}
		parendMod = parendMod->getParent(ctx);
	}
	return false;
}
}}

namespace alinous {namespace runtime {





bool AlinousModule::SetUpper::__init_done = __init_static_variables();
bool AlinousModule::SetUpper::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule::SetUpper", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::SetUpper::SetUpper(String* path, String* debugPath, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElementVisitor(ctx), path(nullptr), debugPath(nullptr)
{
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->debugPath), debugPath, String);
}
void AlinousModule::SetUpper::__construct_impl(String* path, String* debugPath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->debugPath), debugPath, String);
}
 AlinousModule::SetUpper::~SetUpper() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::SetUpper::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SetUpper", L"~SetUpper");
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->debugPath, this);
	debugPath = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousModule::SetUpper::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	element->setParent(parent, ctx);
	element->setFilePath(this->path, ctx);
	element->setDebugFilePath(this->debugPath, ctx);
	return true;
}
String* AlinousModule::SetUpper::getPath(ThreadContext* ctx) throw() 
{
	return path;
}
String* AlinousModule::SetUpper::getDebugPath(ThreadContext* ctx) throw() 
{
	return debugPath;
}
}}

namespace alinous {namespace runtime {





bool AlinousModule::ClassCollector::__init_done = __init_static_variables();
bool AlinousModule::ClassCollector::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule::ClassCollector", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::ClassCollector::~ClassCollector() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::ClassCollector::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassCollector", L"~ClassCollector");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousModule::ClassCollector::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<AlinousClass*>(element) != 0))
	{
		this->list->add(static_cast<AlinousClass*>(element), ctx);
	}
	return true;
}
ArrayList<AlinousClass>* AlinousModule::ClassCollector::getClasses(ThreadContext* ctx) throw() 
{
	return this->list;
}
}}

