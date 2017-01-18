#include "includes.h"


namespace alinous {namespace runtime {





String* AlinousModuleRepository::encode = ConstStr::getCNST_STR_1100();
bool AlinousModuleRepository::__init_done = __init_static_variables();
bool AlinousModuleRepository::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModuleRepository", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModuleRepository::AlinousModuleRepository(AlinousCore* core, ThreadContext* ctx) throw()  : IObject(ctx), modules(GCUtils<HashMap<String,AlinousModule> >::ins(this, (new(ctx) HashMap<String,AlinousModule>(ctx)), ctx, __FILEW__, __LINE__, L"")), core(nullptr), searchPath(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	SystemInfo* system = this->core->getConfig(ctx)->getSystem(ctx);
	String* moduleDir = system->getModuleDir(ctx);
	this->searchPath->add(moduleDir, ctx);
	this->searchPath->add(this->core->getAlinousHome(ctx), ctx);
	WebHandlerInfo* webinfo = this->core->getConfig(ctx)->getWebHandler(ctx);
	if(webinfo != nullptr && webinfo->getDocumentRoot(ctx) != nullptr)
	{
		this->searchPath->add(webinfo->getDocumentRoot(ctx), ctx);
	}
}
void AlinousModuleRepository::__construct_impl(AlinousCore* core, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	SystemInfo* system = this->core->getConfig(ctx)->getSystem(ctx);
	String* moduleDir = system->getModuleDir(ctx);
	this->searchPath->add(moduleDir, ctx);
	this->searchPath->add(this->core->getAlinousHome(ctx), ctx);
	WebHandlerInfo* webinfo = this->core->getConfig(ctx)->getWebHandler(ctx);
	if(webinfo != nullptr && webinfo->getDocumentRoot(ctx) != nullptr)
	{
		this->searchPath->add(webinfo->getDocumentRoot(ctx), ctx);
	}
}
 AlinousModuleRepository::~AlinousModuleRepository() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModuleRepository::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousModuleRepository", L"~AlinousModuleRepository");
	__e_obj1.add(this->modules, this);
	modules = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->searchPath, this);
	searchPath = nullptr;
	if(!prepare){
		return;
	}
}
AlinousModule* AlinousModuleRepository::getModule(String* path, bool debug, ThreadContext* ctx)
{
	ArrayList<String>* once = (new(ctx) ArrayList<String>(ctx));
	return getModule(path, once, false, debug, ctx);
}
AlinousModule* AlinousModuleRepository::getModule(String* path, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx)
{
	if(once->contains(path, ctx))
	{
		return nullptr;
	}
	once->add(path, ctx);
	AlinousModule* module = this->modules->get(path, ctx);
	if(module != nullptr && !module->isDirty(ctx))
	{
		return module;
	}
	return loadModule(path, once, isInclude, debug, ctx);
}
AlinousModule* AlinousModuleRepository::loadModule(String* path, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx)
{
	File* file = findModuleFile(path, ctx);
	if(file == nullptr)
	{
		throw (new(ctx) ModuleNotFoundException(ctx));
	}
	FileInputStream* stream = nullptr;
	AlinousSrc* moduleSource = nullptr;
	{
		try
		{
			stream = (new(ctx) FileInputStream(file, ctx));
			AlinousPlusParser* parser = (new(ctx) AlinousPlusParser(stream, encode, ctx));
			moduleSource = parser->parse(ctx);
		}
		catch(Throwable* e)
		{
			if(stream != nullptr)
			{
				{
					try
					{
						stream->close(ctx);
					}
					catch(IOException* e2)
					{
						e2->printStackTrace(ctx);
					}
				}
			}
			throw (new(ctx) CompileErrorException(ConstStr::getCNST_STR_1099(), e, ctx));
		}
	}
	if(stream != nullptr)
	{
		{
			try
			{
				stream->close(ctx);
			}
			catch(IOException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	AlinousModule* module = (new(ctx) AlinousModule(path, file, moduleSource, this->core, ctx));
	module->init(this, once, isInclude, debug, ctx);
	return module;
}
File* AlinousModuleRepository::findModuleFile(String* path, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->searchPath->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* basepath = this->searchPath->get(i, ctx);
		buff->setLength(0, ctx);
		buff->append(basepath, ctx);
		buff->append(path, ctx);
		File* file = (new(ctx) File(buff->toString(ctx), ctx));
		if(file->exists(ctx))
		{
			return file;
		}
	}
	return nullptr;
}
}}

