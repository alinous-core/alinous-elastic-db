#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.server.debug/DebugConfigLoader.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server/BinaryContentByteStream.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.server.debug/DebugProcessor.h"

namespace alinous {namespace server {namespace debug {





constexpr const int DebugConfigLoader::MOD_DIR;
constexpr const int DebugConfigLoader::WEB_DIR;
bool DebugConfigLoader::__init_done = __init_static_variables();
bool DebugConfigLoader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugConfigLoader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugConfigLoader::DebugConfigLoader(ThreadContext* ctx) throw()  : IObject(ctx), home(nullptr), lastUpdate(0), config(nullptr), moduleDir(nullptr), webDir(nullptr)
{
}
void DebugConfigLoader::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DebugConfigLoader::DebugConfigLoader(AlinousConfig* config, ThreadContext* ctx) throw()  : IObject(ctx), home(nullptr), lastUpdate(0), config(nullptr), moduleDir(nullptr), webDir(nullptr)
{
	__GC_MV(this, &(this->config), config, AlinousConfig);
	this->lastUpdate = config->getFileTimestamp(ctx);
	File* file = nullptr;
	SystemInfo* sysinfo = this->config->getSystem(ctx);
	String* tmpPath = sysinfo->getModuleDir(ctx);
	if(tmpPath != nullptr)
	{
		file = (new(ctx) File(tmpPath, ctx));
		if(file->isAbsolute(ctx))
		{
			tmpPath = file->getAbsolutePath(ctx);
		}
		if(tmpPath->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
		}
				else 
		{
			if(tmpPath->endsWith(ConstStr::getCNST_STR_1769(), ctx))
			{
				tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
			}
		}
		__GC_MV(this, &(this->moduleDir), tmpPath, String);
	}
	WebHandlerInfo* webInfo = this->config->getWebHandler(ctx);
	if(webInfo == nullptr)
	{
		return;
	}
	tmpPath = webInfo->getDocumentRoot(ctx);
	if(tmpPath != nullptr)
	{
		file = (new(ctx) File(tmpPath, ctx));
		if(file->isAbsolute(ctx))
		{
			tmpPath = file->getAbsolutePath(ctx);
		}
		if(tmpPath->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
		}
				else 
		{
			if(tmpPath->endsWith(ConstStr::getCNST_STR_1769(), ctx))
			{
				tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
			}
		}
		__GC_MV(this, &(this->webDir), tmpPath, String);
	}
}
void DebugConfigLoader::__construct_impl(AlinousConfig* config, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->config), config, AlinousConfig);
	this->lastUpdate = config->getFileTimestamp(ctx);
	File* file = nullptr;
	SystemInfo* sysinfo = this->config->getSystem(ctx);
	String* tmpPath = sysinfo->getModuleDir(ctx);
	if(tmpPath != nullptr)
	{
		file = (new(ctx) File(tmpPath, ctx));
		if(file->isAbsolute(ctx))
		{
			tmpPath = file->getAbsolutePath(ctx);
		}
		if(tmpPath->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
		}
				else 
		{
			if(tmpPath->endsWith(ConstStr::getCNST_STR_1769(), ctx))
			{
				tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
			}
		}
		__GC_MV(this, &(this->moduleDir), tmpPath, String);
	}
	WebHandlerInfo* webInfo = this->config->getWebHandler(ctx);
	if(webInfo == nullptr)
	{
		return;
	}
	tmpPath = webInfo->getDocumentRoot(ctx);
	if(tmpPath != nullptr)
	{
		file = (new(ctx) File(tmpPath, ctx));
		if(file->isAbsolute(ctx))
		{
			tmpPath = file->getAbsolutePath(ctx);
		}
		if(tmpPath->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
		}
				else 
		{
			if(tmpPath->endsWith(ConstStr::getCNST_STR_1769(), ctx))
			{
				tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
			}
		}
		__GC_MV(this, &(this->webDir), tmpPath, String);
	}
}
 DebugConfigLoader::~DebugConfigLoader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugConfigLoader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugConfigLoader", L"~DebugConfigLoader");
	__e_obj1.add(this->home, this);
	home = nullptr;
	__e_obj1.add(this->config, this);
	config = nullptr;
	__e_obj1.add(this->moduleDir, this);
	moduleDir = nullptr;
	__e_obj1.add(this->webDir, this);
	webDir = nullptr;
	if(!prepare){
		return;
	}
}
DebugConfigLoader* DebugConfigLoader::init(String* path, ThreadContext* ctx)
{
	__GC_MV(this, &(this->home), path, String);
	this->lastUpdate = 0;
	load(ctx);
	return this;
}
String* DebugConfigLoader::getAbsFromDebugPath(String* dpath, ThreadContext* ctx) throw() 
{
	String* path = dpath->substring(1, ctx);
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(dpath->startsWith(ConstStr::getCNST_STR_3535(), ctx))
	{
		buff->append(this->webDir, ctx);
	}
		else 
	{
		if(dpath->startsWith(ConstStr::getCNST_STR_165(), ctx))
		{
			buff->append(this->moduleDir, ctx);
		}
	}
	buff->append(path, ctx);
	return buff->toString(ctx);
}
String* DebugConfigLoader::getDebugFilePath(String* absPath, ThreadContext* ctx)
{
	load(ctx);
	int dirtype = getHeader(absPath, ctx);
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	String* tmpStr = nullptr;
	switch(dirtype) {
	case DebugConfigLoader::MOD_DIR:
		buff->append(ConstStr::getCNST_STR_165(), ctx);
		tmpStr = absPath->substring(this->moduleDir->length(ctx), ctx);
		buff->append(tmpStr, ctx);
		break ;
	case DebugConfigLoader::WEB_DIR:
		buff->append(ConstStr::getCNST_STR_3535(), ctx);
		tmpStr = absPath->substring(this->webDir->length(ctx), ctx);
		buff->append(tmpStr, ctx);
		break ;
	default:
		return nullptr;
		break;
	}
	return buff->toString(ctx);
}
void DebugConfigLoader::load(ThreadContext* ctx)
{
	File* file = nullptr;
	if(this->config != nullptr)
	{
		file = (new(ctx) File(this->config->getAlinousConfigPath(ctx), ctx));
		long long upd = file->lastModified(ctx);
		if(this->lastUpdate >= upd)
		{
			return;
		}
	}
	__GC_MV(this, &(this->config), (new(ctx) AlinousConfig(this->home, ctx)), AlinousConfig);
	this->config->parseInitFile(ctx);
	this->lastUpdate = this->config->getFileTimestamp(ctx);
	String* tmpPath = this->config->getSystem(ctx)->getModuleDir(ctx);
	if(tmpPath != nullptr)
	{
		file = (new(ctx) File(tmpPath, ctx));
		if(file->isAbsolute(ctx))
		{
			tmpPath = file->getAbsolutePath(ctx);
		}
		if(tmpPath->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
		}
				else 
		{
			if(tmpPath->endsWith(ConstStr::getCNST_STR_1769(), ctx))
			{
				tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
			}
		}
		__GC_MV(this, &(this->moduleDir), tmpPath, String);
	}
	WebHandlerInfo* webInfo = this->config->getWebHandler(ctx);
	if(webInfo == nullptr)
	{
		return;
	}
	tmpPath = webInfo->getDocumentRoot(ctx);
	if(tmpPath != nullptr)
	{
		file = (new(ctx) File(tmpPath, ctx));
		if(file->isAbsolute(ctx))
		{
			tmpPath = file->getAbsolutePath(ctx);
		}
		if(tmpPath->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
		}
				else 
		{
			if(tmpPath->endsWith(ConstStr::getCNST_STR_1769(), ctx))
			{
				tmpPath = tmpPath->substring(0, tmpPath->length(ctx) - 1, ctx);
			}
		}
		__GC_MV(this, &(this->webDir), tmpPath, String);
	}
}
int DebugConfigLoader::getHeader(String* absPath, ThreadContext* ctx) throw() 
{
	if(this->moduleDir != nullptr && absPath->startsWith(this->moduleDir, ctx))
	{
		return DebugConfigLoader::MOD_DIR;
	}
	if(this->webDir != nullptr && absPath->startsWith(this->webDir, ctx))
	{
		return DebugConfigLoader::WEB_DIR;
	}
	return -1;
}
void DebugConfigLoader::__cleanUp(ThreadContext* ctx){
}
}}}

