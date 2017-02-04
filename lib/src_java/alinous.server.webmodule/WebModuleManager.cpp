#include "includes.h"


namespace alinous {namespace server {namespace webmodule {





bool WebModuleManager::__init_done = __init_static_variables();
bool WebModuleManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WebModuleManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WebModuleManager::WebModuleManager(AlinousCore* core, ThreadContext* ctx) : IObject(ctx), ThreadMonitor(ctx), list(GCUtils<FifoList<AbstractWebModule> >::ins(this, (new(ctx) FifoList<AbstractWebModule>(ctx)), ctx, __FILEW__, __LINE__, L"")), hashList(nullptr), webInfo(nullptr), webRoot(nullptr), moduleLoader(nullptr), core(nullptr)
{
	__GC_MV(this, &(this->hashList), (new(ctx) WebModuleHashList(ctx))->init(1024, ctx), WebModuleHashList);
	__GC_MV(this, &(this->webInfo), core->getConfig(ctx)->getWebHandler(ctx), WebHandlerInfo);
	if(this->webInfo == nullptr)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3543(), ctx));
	}
	__GC_MV(this, &(this->webRoot), this->webInfo->getDocumentRoot(ctx), String);
	__GC_MV(this, &(this->moduleLoader), core->getModulerepository(ctx), AlinousModuleRepository);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
void WebModuleManager::__construct_impl(AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->hashList), (new(ctx) WebModuleHashList(ctx))->init(1024, ctx), WebModuleHashList);
	__GC_MV(this, &(this->webInfo), core->getConfig(ctx)->getWebHandler(ctx), WebHandlerInfo);
	if(this->webInfo == nullptr)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3543(), ctx));
	}
	__GC_MV(this, &(this->webRoot), this->webInfo->getDocumentRoot(ctx), String);
	__GC_MV(this, &(this->moduleLoader), core->getModulerepository(ctx), AlinousModuleRepository);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
 WebModuleManager::~WebModuleManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WebModuleManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WebModuleManager", L"~WebModuleManager");
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->hashList, this);
	hashList = nullptr;
	__e_obj1.add(this->webInfo, this);
	webInfo = nullptr;
	__e_obj1.add(this->webRoot, this);
	webRoot = nullptr;
	__e_obj1.add(this->moduleLoader, this);
	moduleLoader = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	if(!prepare){
		return;
	}
}
AbstractWebModule* WebModuleManager::getModule(String* path, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		FifoElement<AbstractWebModule>* modElement = this->hashList->find(path, ctx);
		if(modElement != nullptr)
		{
			AbstractWebModule* data = modElement->data;
			bool dirty = data->isDirty(ctx);
			if(!dirty)
			{
				this->list->moveElementToLast(modElement, ctx);
				return modElement->data;
			}
						else 
			{
				if(dirty)
				{
					this->list->removeElement(modElement, ctx);
					this->hashList->remove(path, ctx);
				}
			}
		}
	}
	AbstractWebModule* mod = loadModule(path, debug, ctx);
	if(mod == nullptr)
	{
		return nullptr;
	}
	mod->prepare(this->core, ctx);
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		FifoElement<AbstractWebModule>* fifoElement = (new(ctx) FifoElement<AbstractWebModule>(mod, ctx));
		this->list->addElement(fifoElement, ctx);
		this->hashList->add(fifoElement, ctx);
	}
	return mod;
}
AbstractWebModule* WebModuleManager::loadModule(String* path, bool debug, ThreadContext* ctx)
{
	bool isDir = path->endsWith(ConstStr::getCNST_STR_1007(), ctx);
	if(path->endsWith(ConstStr::getCNST_STR_3544(), ctx) || isDir)
	{
		AbstractWebModule* mod = handleWebModule(path, debug, ctx);
		if(mod != nullptr)
		{
			return mod;
		}
	}
	if(path->endsWith(ConstStr::getCNST_STR_3545(), ctx) || isDir)
	{
		return handleDirectModule(path, debug, ctx);
	}
	if(path->endsWith(ConstStr::getCNST_STR_3546(), ctx))
	{
		AbstractWebModule* mod = handleWebXmlModule(path, debug, ctx);
		if(mod != nullptr)
		{
			return mod;
		}
	}
	StringBuilder* builder = (new(ctx) StringBuilder(ctx));
	builder->append(this->webRoot, ctx);
	builder->append(path, ctx);
	File* file = (new(ctx) File(builder->toString(ctx), ctx));
	if(!file->exists(ctx))
	{
		return nullptr;
	}
	return nullptr;
}
AbstractWebModule* WebModuleManager::handleDirectModule(String* path, bool debug, ThreadContext* ctx)
{
	AlinousModule* mod = loadAlinousModule(path, debug, ctx);
	if(mod == nullptr)
	{
		return nullptr;
	}
	return (new(ctx) DirectModule(mod, path, ctx));
}
AbstractWebModule* WebModuleManager::handleWebXmlModule(String* path, bool debug, ThreadContext* ctx)
{
	AlinousWebHtmlXmlModule* htmlModule = handleXmlModule(path, ctx);
	if(htmlModule == nullptr)
	{
		return nullptr;
	}
	{
		try
		{
			htmlModule->compile(ctx);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3547(), e, ctx));
		}
	}
	AlinousModule* alnsModule = loadAlinousModule(path, debug, ctx);
	if(alnsModule == nullptr)
	{
		return (new(ctx) StaticHtmlModule(htmlModule, path, ctx));
	}
	return (new(ctx) DynamicWebPageModule(htmlModule, alnsModule, path, ctx));
}
AlinousWebHtmlXmlModule* WebModuleManager::handleXmlModule(String* path, ThreadContext* ctx)
{
	StringBuilder* builder = (new(ctx) StringBuilder(ctx));
	builder->append(this->webRoot, ctx);
	builder->append(path, ctx);
	if(path->endsWith(ConstStr::getCNST_STR_1007(), ctx))
	{
		builder->append(ConstStr::getCNST_STR_3548(), ctx);
	}
	File* file = (new(ctx) File(builder->toString(ctx), ctx));
	if(!file->exists(ctx))
	{
		return nullptr;
	}
	AlinousWebHtmlXmlModule* module = nullptr;
	{
		try
		{
			module = (new(ctx) AlinousWebHtmlXmlModule(file, ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3549(), e, ctx));
		}
	}
	return module;
}
AbstractWebModule* WebModuleManager::handleWebModule(String* path, bool debug, ThreadContext* ctx)
{
	AlinousWebHtmlXmlModule* htmlModule = handleHtmlModule(path, ctx);
	if(htmlModule == nullptr)
	{
		return nullptr;
	}
	{
		try
		{
			htmlModule->compile(ctx);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3547(), e, ctx));
		}
	}
	String* modPath = nullptr;
	if(path->endsWith(ConstStr::getCNST_STR_3544(), ctx))
	{
		StringBuilder* sb = (new(ctx) StringBuilder(ctx));
		sb->append(path->substring(0, path->length(ctx) - 4, ctx), ctx)->append(ConstStr::getCNST_STR_3550(), ctx);
		modPath = sb->toString(ctx);
	}
		else 
	{
		modPath = path;
	}
	AlinousModule* alnsModule = loadAlinousModule(modPath, debug, ctx);
	if(alnsModule == nullptr)
	{
		return (new(ctx) StaticHtmlModule(htmlModule, path, ctx));
	}
	return (new(ctx) DynamicWebPageModule(htmlModule, alnsModule, path, ctx));
}
AlinousModule* WebModuleManager::loadAlinousModule(String* path, bool debug, ThreadContext* ctx)
{
	StringBuilder* builder = (new(ctx) StringBuilder(ctx));
	builder->append(path, ctx);
	if(path->endsWith(ConstStr::getCNST_STR_1007(), ctx))
	{
		builder->append(ConstStr::getCNST_STR_3551(), ctx);
	}
	AlinousModule* mod = nullptr;
	{
		try
		{
			mod = this->moduleLoader->getModule(builder->toString(ctx), debug, ctx);
		}
		catch(ModuleNotFoundException* e)
		{
			return nullptr;
		}
	}
	return mod;
}
AlinousWebHtmlXmlModule* WebModuleManager::handleHtmlModule(String* path, ThreadContext* ctx)
{
	StringBuilder* builder = (new(ctx) StringBuilder(ctx));
	builder->append(this->webRoot, ctx);
	builder->append(path, ctx);
	if(path->endsWith(ConstStr::getCNST_STR_1007(), ctx))
	{
		builder->append(ConstStr::getCNST_STR_3552(), ctx);
	}
	File* file = (new(ctx) File(builder->toString(ctx), ctx));
	if(!file->exists(ctx))
	{
		return nullptr;
	}
	AlinousWebHtmlXmlModule* module = nullptr;
	{
		try
		{
			module = (new(ctx) AlinousWebHtmlXmlModule(file, ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3549(), e, ctx));
		}
	}
	return module;
}
}}}

