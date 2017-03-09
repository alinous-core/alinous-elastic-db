#include "include/global.h"


#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/MailInfo.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/ConfigPathUtils.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.system.config/DataSourceInfo.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system.utils/ConfigFileUtiles.h"
#include "alinous.system.utils/FileUtils.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.system.config/AlinousConfig.h"

namespace alinous {namespace system {namespace config {





bool AlinousConfig::__init_done = __init_static_variables();
bool AlinousConfig::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousConfig", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousConfig::AlinousConfig(String* home, ThreadContext* ctx) throw()  : IObject(ctx), alinousHome(__GC_INS(this, (new(ctx) StringBuffer(ctx)), StringBuffer)), system(nullptr), database(nullptr), mail(nullptr), alinousDb(nullptr), webHandler(nullptr), regions(GCUtils<List<RegionsServer> >::ins(this, (new(ctx) ArrayList<RegionsServer>(ctx)), ctx, __FILEW__, __LINE__, L"")), nodes(nullptr), monitor(nullptr), alinousConfigPath(nullptr), fileTimestamp(0)
{
	this->alinousHome->append(home, ctx);
	if(!home->endsWith(ConstStr::getCNST_STR_949(), ctx))
	{
		this->alinousHome->append(ConstStr::getCNST_STR_949(), ctx);
	}
}
void AlinousConfig::__construct_impl(String* home, ThreadContext* ctx) throw() 
{
	this->alinousHome->append(home, ctx);
	if(!home->endsWith(ConstStr::getCNST_STR_949(), ctx))
	{
		this->alinousHome->append(ConstStr::getCNST_STR_949(), ctx);
	}
}
 AlinousConfig::~AlinousConfig() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousConfig::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousConfig", L"~AlinousConfig");
	__e_obj1.add(this->alinousHome, this);
	alinousHome = nullptr;
	__e_obj1.add(this->system, this);
	system = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->mail, this);
	mail = nullptr;
	__e_obj1.add(this->alinousDb, this);
	alinousDb = nullptr;
	__e_obj1.add(this->webHandler, this);
	webHandler = nullptr;
	__e_obj1.add(this->regions, this);
	regions = nullptr;
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	__e_obj1.add(this->monitor, this);
	monitor = nullptr;
	__e_obj1.add(this->alinousConfigPath, this);
	alinousConfigPath = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousConfig::parseInitFile(ThreadContext* ctx)
{
	__GC_MV(this, &(this->alinousConfigPath), this->alinousHome->clone(ctx)->append(ConstStr::getCNST_STR_954(), ctx), String);
	String* encode = ConstStr::getCNST_STR_955();
	File* confFile = (new(ctx) File(this->alinousConfigPath, ctx));
	this->fileTimestamp = confFile->lastModified(ctx);
	String* xmlSrc = FileUtils::readAllText(this->alinousConfigPath, encode, ctx);
	if(xmlSrc == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_956(), ctx));
	}
	AlinousDomReplacer* replacer = (new(ctx) AlinousDomReplacer(ctx));
	DomConverter* converter = (new(ctx) DomConverter(xmlSrc, replacer, ctx));
	converter->parse(ctx);
	DomDocument* document = replacer->getDocument(ctx);
	Matcher* matcher = (new(ctx) Matcher(ctx));
	MatchCandidatesCollection* result = nullptr;
	{
		try
		{
			result = matcher->match(document, document, ConstStr::getCNST_STR_957(), ctx);
			handleSystem(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_958(), ctx);
			handleAlinousDbSetting(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_959(), ctx);
			handleSourceSetting(result, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_960(), ctx);
			handleWebSetting(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_961(), ctx);
			handleMailSetting(result, ctx);
			handleDistributedDbParts(document, matcher, ctx);
		}
		catch(alinous::parser::xpath::ParseException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_962(), ctx));
		}
		catch(MatchingException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_962(), ctx));
		}
	}
}
StringBuffer* AlinousConfig::getAlinousHome(ThreadContext* ctx) throw() 
{
	return alinousHome;
}
void AlinousConfig::setAlinousHome(StringBuffer* alinousHome, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousHome), alinousHome, StringBuffer);
}
SystemInfo* AlinousConfig::getSystem(ThreadContext* ctx) throw() 
{
	return system;
}
DataSourceInfo* AlinousConfig::getDatabase(ThreadContext* ctx) throw() 
{
	return database;
}
MailInfo* AlinousConfig::getMail(ThreadContext* ctx) throw() 
{
	return mail;
}
AlinousDbInfo* AlinousConfig::getAlinousDb(ThreadContext* ctx) throw() 
{
	return alinousDb;
}
WebHandlerInfo* AlinousConfig::getWebHandler(ThreadContext* ctx) throw() 
{
	return webHandler;
}
String* AlinousConfig::getAlinousConfigPath(ThreadContext* ctx) throw() 
{
	return alinousConfigPath;
}
long long AlinousConfig::getFileTimestamp(ThreadContext* ctx) throw() 
{
	return fileTimestamp;
}
List<RegionsServer>* AlinousConfig::getRegions(ThreadContext* ctx) throw() 
{
	return regions;
}
Nodes* AlinousConfig::getNodes(ThreadContext* ctx) throw() 
{
	return nodes;
}
Monitor* AlinousConfig::getMonitor(ThreadContext* ctx) throw() 
{
	return monitor;
}
void AlinousConfig::handleSystem(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_963(), ctx));
	}
	if(list->size(ctx) > 1)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_964(), ctx));
	}
	__GC_MV(this, &(this->system), (new(ctx) SystemInfo(this->alinousHome->toString(ctx), ctx)), SystemInfo);
	MatchCandidate* candidate = list->get(0, ctx);
	String* moduleDir = ConfigFileUtiles::getText(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_965(), ctx);
	if(moduleDir != nullptr)
	{
		this->system->setModuleDir(moduleDir->trim(ctx), ctx);
	}
	String* systemDatastore = ConfigFileUtiles::getAttribute(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_966(), ConstStr::getCNST_STR_967(), ctx);
	if(systemDatastore != nullptr)
	{
		this->system->setSystemDatastore(systemDatastore->trim(ctx), ctx);
	}
	String* defaultDatastore = ConfigFileUtiles::getAttribute(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_968(), ConstStr::getCNST_STR_967(), ctx);
	if(defaultDatastore != nullptr)
	{
		this->system->setDefaultDatastore(defaultDatastore->trim(ctx), ctx);
	}
}
void AlinousConfig::handleDistributedDbParts(DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	MatchCandidatesCollection* result = nullptr;
	ArrayList<MatchCandidate>* list = nullptr;
	result = matcher->match(document, document, ConstStr::getCNST_STR_969(), ctx);
	list = result->getCandidatesList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		MatchCandidate* candidate = list->get(i, ctx);
		RegionsServer* regsrv = RegionsServer::parseInstance(candidate, document, matcher, ctx);
		this->regions->add(regsrv, ctx);
	}
	result = matcher->match(document, document, ConstStr::getCNST_STR_970(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		__GC_MV(this, &(this->nodes), Nodes::parseInstance(candidate, document, matcher, this->alinousHome->toString(ctx), ctx), Nodes);
	}
	result = matcher->match(document, document, ConstStr::getCNST_STR_971(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		__GC_MV(this, &(this->monitor), Monitor::parseInstance(candidate, document, matcher, ctx), Monitor);
	}
}
void AlinousConfig::handleAlinousDbSetting(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		return;
	}
	__GC_MV(this, &(this->alinousDb), (new(ctx) AlinousDbInfo(this->alinousHome->toString(ctx), ctx)), AlinousDbInfo);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* candidate = it->next(ctx);
		DomNode* node = candidate->getCandidateDom(ctx);
		IVariableValue* attr = node->getAttributeValue(ConstStr::getCNST_STR_967(), ctx);
		if(attr == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_972(), ctx));
		}
		String* id = attr->toString(ctx)->trim(ctx);
		String* dataDir = ConfigFileUtiles::getText(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_973(), ctx);
		if(dataDir == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_974(), ctx));
		}
		AlinousDbInstanceInfo* dbinfo = this->alinousDb->addInstance(id, dataDir->trim(ctx), ctx);
		handleRemoteRef(dbinfo, node, document, matcher, ctx);
	}
}
void AlinousConfig::handleRemoteRef(AlinousDbInstanceInfo* dbinfo, DomNode* alinousDb, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	MatchCandidatesCollection* result = nullptr;
	ArrayList<MatchCandidate>* list = nullptr;
	result = matcher->match(document, alinousDb, ConstStr::getCNST_STR_975(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		RegionsRef* regionsRef = RegionsRef::parseInstance(candidate, document, matcher, ctx);
		dbinfo->setRegionsRef(regionsRef, ctx);
	}
	result = matcher->match(document, alinousDb, ConstStr::getCNST_STR_976(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		MonitorRef* monitorRef = MonitorRef::parseInstance(candidate, document, matcher, ctx);
		dbinfo->setMonitorRef(monitorRef, ctx);
	}
}
void AlinousConfig::handleWebSetting(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		return;
	}
	__GC_MV(this, &(this->webHandler), (new(ctx) WebHandlerInfo(this->alinousHome->toString(ctx), ctx)), WebHandlerInfo);
	MatchCandidate* candidateWebHandler = list->get(0, ctx);
	DomNode* node = candidateWebHandler->getCandidateDom(ctx);
	IVariableValue* attr = node->getAttributeValue(ConstStr::getCNST_STR_977(), ctx);
	if(attr != nullptr)
	{
		String* portStr = attr->toString(ctx)->trim(ctx);
		{
			try
			{
				int port = Integer::parseInt(portStr, ctx);
				this->webHandler->setPort(port, ctx);
			}
			catch(NumberFormatException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	String* documentRoot = ConfigFileUtiles::getText(document, candidateWebHandler->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_978(), ctx);
	if(document != nullptr)
	{
		this->webHandler->setDocumentRoot(documentRoot, ctx);
	}
}
void AlinousConfig::handleSourceSetting(MatchCandidatesCollection* result, ThreadContext* ctx) throw() 
{
}
void AlinousConfig::handleMailSetting(MatchCandidatesCollection* result, ThreadContext* ctx) throw() 
{
}
void AlinousConfig::__cleanUp(ThreadContext* ctx){
}
}}}

