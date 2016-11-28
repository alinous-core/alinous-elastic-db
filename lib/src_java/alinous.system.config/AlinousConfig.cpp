#include "includes.h"


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
 AlinousConfig::AlinousConfig(String* home, ThreadContext* ctx) throw()  : IObject(ctx), alinousHome(__GC_INS(this, (new(ctx) StringBuffer(ctx)), StringBuffer)), system(nullptr), database(nullptr), mail(nullptr), alinousDb(nullptr), webHandler(nullptr), alinousConfigPath(nullptr), fileTimestamp(0)
{
	this->alinousHome->append(home, ctx);
	if(!home->endsWith(ConstStr::getCNST_STR_984(), ctx))
	{
		this->alinousHome->append(ConstStr::getCNST_STR_984(), ctx);
	}
}
void AlinousConfig::__construct_impl(String* home, ThreadContext* ctx) throw() 
{
	this->alinousHome->append(home, ctx);
	if(!home->endsWith(ConstStr::getCNST_STR_984(), ctx))
	{
		this->alinousHome->append(ConstStr::getCNST_STR_984(), ctx);
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
	__e_obj1.add(this->alinousConfigPath, this);
	alinousConfigPath = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousConfig::parseInitFile(ThreadContext* ctx)
{
	__GC_MV(this, &(this->alinousConfigPath), this->alinousHome->clone(ctx)->append(ConstStr::getCNST_STR_1180(), ctx), String);
	String* encode = ConstStr::getCNST_STR_1047();
	File* confFile = (new(ctx) File(this->alinousConfigPath, ctx));
	this->fileTimestamp = confFile->lastModified(ctx);
	String* xmlSrc = FileUtils::readAllText(this->alinousConfigPath, encode, ctx);
	if(xmlSrc == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1181(), ctx));
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
			result = matcher->match(document, document, ConstStr::getCNST_STR_1182(), ctx);
			handleSystem(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1183(), ctx);
			handleAlinousDbSetting(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1184(), ctx);
			handleSourceSetting(result, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1185(), ctx);
			handleWebSetting(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1186(), ctx);
			handleMailSetting(result, ctx);
		}
		catch(alinous::parser::xpath::ParseException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1187(), ctx));
		}
		catch(MatchingException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1187(), ctx));
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
void AlinousConfig::handleSystem(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1188(), ctx));
	}
	if(list->size(ctx) > 1)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1189(), ctx));
	}
	__GC_MV(this, &(this->system), (new(ctx) SystemInfo(this->alinousHome->toString(ctx), ctx)), SystemInfo);
	MatchCandidate* candidate = list->get(0, ctx);
	String* moduleDir = ConfigFileUtiles::getText(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1190(), ctx);
	if(moduleDir != nullptr)
	{
		this->system->setModuleDir(moduleDir->trim(ctx), ctx);
	}
	String* systemDatastore = ConfigFileUtiles::getAttribute(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1191(), ConstStr::getCNST_STR_1192(), ctx);
	if(systemDatastore != nullptr)
	{
		this->system->setSystemDatastore(systemDatastore->trim(ctx), ctx);
	}
	String* defaultDatastore = ConfigFileUtiles::getAttribute(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1193(), ConstStr::getCNST_STR_1192(), ctx);
	if(defaultDatastore != nullptr)
	{
		this->system->setDefaultDatastore(defaultDatastore->trim(ctx), ctx);
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
		IVariableValue* attr = node->getAttributeValue(ConstStr::getCNST_STR_1192(), ctx);
		if(attr == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1194(), ctx));
		}
		String* id = attr->toString(ctx)->trim(ctx);
		String* dataDir = ConfigFileUtiles::getText(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1195(), ctx);
		if(dataDir == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1196(), ctx));
		}
		this->alinousDb->addInstance(id, dataDir->trim(ctx), ctx);
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
	String* documentRoot = ConfigFileUtiles::getText(document, candidateWebHandler->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1197(), ctx);
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
}}}

