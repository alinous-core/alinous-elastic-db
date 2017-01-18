#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





bool ScriptMachine::__init_done = __init_static_variables();
bool ScriptMachine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScriptMachine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScriptMachine::ScriptMachine(AlinousModule* module, AlinousCore* core, ThreadContext* ctx) : IObject(ctx), core(nullptr), stackFrames(GCUtils<Stack<MainStackFrame> >::ins(this, (new(ctx) Stack<MainStackFrame>(ctx)), ctx, __FILEW__, __LINE__, L"")), module(nullptr), dbHandles(GCUtils<ArrayList<DatabaseHandle> >::ins(this, (new(ctx) ArrayList<DatabaseHandle>(ctx)), ctx, __FILEW__, __LINE__, L"")), currentDbHandle(nullptr), alinousStmtRunner(nullptr), sqlRunner(nullptr), stackIdSerial(0), returnedValue(nullptr), expStreamStack(GCUtils<Stack<ExpressionStreamBuffer> >::ins(this, (new(ctx) Stack<ExpressionStreamBuffer>(ctx)), ctx, __FILEW__, __LINE__, L"")), leftValue(0)
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	MainStackFrame* topFrame = (new(ctx) MainStackFrame(module->getModuleSource(ctx), this->stackIdSerial++, ctx));
	this->stackFrames->push(topFrame, ctx);
	topFrame->subFrame(module->getModuleSource(ctx), ctx);
	__GC_MV(this, &(this->core), core, AlinousCore);
	String* defaultSrc = this->core->getConfig(ctx)->getSystem(ctx)->getDefaultDatastore(ctx);
	IDatabaseDriver* driver = this->core->getDatabaseManager(ctx)->get(defaultSrc, ctx);
	if(driver == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1164()->clone(ctx)->append(defaultSrc, ctx)->append(ConstStr::getCNST_STR_1165(), ctx), ctx));
	}
	IDatabaseConnection* con = driver->connect(ctx);
	__GC_MV(this, &(this->currentDbHandle), (new(ctx) DatabaseHandle(driver, con, ctx)), DatabaseHandle);
	this->dbHandles->add(this->currentDbHandle, ctx);
}
void ScriptMachine::__construct_impl(AlinousModule* module, AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	MainStackFrame* topFrame = (new(ctx) MainStackFrame(module->getModuleSource(ctx), this->stackIdSerial++, ctx));
	this->stackFrames->push(topFrame, ctx);
	topFrame->subFrame(module->getModuleSource(ctx), ctx);
	__GC_MV(this, &(this->core), core, AlinousCore);
	String* defaultSrc = this->core->getConfig(ctx)->getSystem(ctx)->getDefaultDatastore(ctx);
	IDatabaseDriver* driver = this->core->getDatabaseManager(ctx)->get(defaultSrc, ctx);
	if(driver == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1164()->clone(ctx)->append(defaultSrc, ctx)->append(ConstStr::getCNST_STR_1165(), ctx), ctx));
	}
	IDatabaseConnection* con = driver->connect(ctx);
	__GC_MV(this, &(this->currentDbHandle), (new(ctx) DatabaseHandle(driver, con, ctx)), DatabaseHandle);
	this->dbHandles->add(this->currentDbHandle, ctx);
}
 ScriptMachine::~ScriptMachine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScriptMachine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScriptMachine", L"~ScriptMachine");
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->stackFrames, this);
	stackFrames = nullptr;
	__e_obj1.add(this->module, this);
	module = nullptr;
	__e_obj1.add(this->dbHandles, this);
	dbHandles = nullptr;
	__e_obj1.add(this->currentDbHandle, this);
	currentDbHandle = nullptr;
	__e_obj1.add(this->alinousStmtRunner, this);
	alinousStmtRunner = nullptr;
	__e_obj1.add(this->sqlRunner, this);
	sqlRunner = nullptr;
	__e_obj1.add(this->returnedValue, this);
	returnedValue = nullptr;
	__e_obj1.add(this->expStreamStack, this);
	expStreamStack = nullptr;
	if(!prepare){
		return;
	}
}
void ScriptMachine::importParams(HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx)
{
	MainStackFrame* topFrame = this->getFrame(ctx);
	DomVariable* inDom = (new(ctx) DomVariable(ctx));
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	desc->addSegment((new(ctx) DomNameSegment(ConstStr::getCNST_STR_488(), ctx)), ctx);
	topFrame->putVariable(this, desc, inDom, false, ctx);
	Iterator<String>* it = params->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		AbstractHttpParameter* param = params->get(key, ctx);
		switch(param->paramType) {
		case AbstractHttpParameter::TYPE_NORMAL_PARAM:
			HttpParamHandler::handleNormalParam(this, static_cast<HttpParameter*>(param), topFrame, params, ctx);
			break ;
		case AbstractHttpParameter::TYPE_ARRAY_PARAM:
			HttpParamHandler::handleArrayParam(this, static_cast<HttpArrayParameter*>(param), topFrame, params, ctx);
			break ;
		case AbstractHttpParameter::TYPE_FILE_PARAM:
			HttpParamHandler::handleFileParam(this, static_cast<HttpUploadParameter*>(param), topFrame, params, ctx);
			break ;
		default:
			break ;
		}
	}
}
void ScriptMachine::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	int maxLoop = this->stackFrames->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		MainStackFrame* frame = this->stackFrames->get(i, ctx);
		frame->outDebugXml(parentNode, ctx);
	}
}
IAlinousVariable* ScriptMachine::resolveExpression(IExpression* exp, bool debug, ThreadContext* ctx)
{
	return exp->resolveExpression(this, debug, ctx);
}
AlinousFunction* ScriptMachine::findSourceFunction(String* name, ThreadContext* ctx) throw() 
{
	return this->module->findFunction(name, ctx);
}
void ScriptMachine::newStackFrame(AlinousFunction* func, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = (new(ctx) MainStackFrame(func, this->stackIdSerial++, ctx));
	this->stackFrames->push(frame, ctx);
}
void ScriptMachine::newStackFrame(StatementBlock* block, ThreadContext* ctx) throw() 
{
	IStackFrame* frame = peek(ctx);
	frame->subFrame(block, ctx);
}
void ScriptMachine::popStackFrame(ThreadContext* ctx) throw() 
{
	this->stackFrames->pop(ctx);
}
IStackFrame* ScriptMachine::peek(ThreadContext* ctx) throw() 
{
	return this->stackFrames->peek(ctx)->peek(ctx);
}
MainStackFrame* ScriptMachine::getFrame(ThreadContext* ctx) throw() 
{
	return this->stackFrames->peek(ctx);
}
MainStackFrame* ScriptMachine::getLastFrame(ThreadContext* ctx) throw() 
{
	return this->stackFrames->get(this->stackFrames->size(ctx) - 2, ctx);
}
Stack<MainStackFrame>* ScriptMachine::getStackFrames(ThreadContext* ctx) throw() 
{
	return stackFrames;
}
AlinousCore* ScriptMachine::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
ArrayList<DatabaseHandle>* ScriptMachine::getDbHandles(ThreadContext* ctx) throw() 
{
	return dbHandles;
}
DatabaseHandle* ScriptMachine::getCurrentDbHandle(ThreadContext* ctx) throw() 
{
	return currentDbHandle;
}
void ScriptMachine::dispose(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->currentDbHandle), nullptr, DatabaseHandle);
	int maxdb = this->dbHandles->size(ctx);
	for(int i = 0; i != maxdb; ++i)
	{
		DatabaseHandle* handle = this->dbHandles->get(i, ctx);
		handle->getCon(ctx)->close(ctx);
	}
}
AlinousStatementRunner* ScriptMachine::getAlinousStmtRunner(ThreadContext* ctx) throw() 
{
	return alinousStmtRunner;
}
void ScriptMachine::setAlinousStmtRunner(AlinousStatementRunner* alinousStmtRunner, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousStmtRunner), alinousStmtRunner, AlinousStatementRunner);
}
SQLStatementRunner* ScriptMachine::getSqlRunner(ThreadContext* ctx) throw() 
{
	return sqlRunner;
}
void ScriptMachine::setSqlRunner(SQLStatementRunner* sqlRunner, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sqlRunner), sqlRunner, SQLStatementRunner);
}
void ScriptMachine::putVariable(DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx)
{
	MainStackFrame* frame = getFrame(ctx);
	frame->putVariable(this, desc, variable, debug, ctx);
}
IDomVariable* ScriptMachine::getByDescriptor(DomVariableDescriptor* domVariableDescriptor, bool debug, ThreadContext* ctx)
{
	MainStackFrame* frame = getFrame(ctx);
	return frame->getDomVariable(this, domVariableDescriptor, debug, ctx);
}
ITypedVariable* ScriptMachine::getTypedVariable(String* name, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = getFrame(ctx);
	ITypedVariable* tv = frame->getTypedVariable(name, ctx);
	return tv;
}
void ScriptMachine::putTypedVariable(String* name, ITypedVariable* variable, ThreadContext* ctx)
{
	MainStackFrame* frame = getFrame(ctx);
	frame->putTypedVariable(name, variable, ctx);
}
IAlinousVariable* ScriptMachine::getReturnedValue(ThreadContext* ctx) throw() 
{
	return returnedValue;
}
void ScriptMachine::setReturnedValue(IAlinousVariable* returnedValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->returnedValue), returnedValue, IAlinousVariable);
}
void ScriptMachine::newExpressionStream(ThreadContext* ctx) throw() 
{
	ExpressionStreamBuffer* buff = (new(ctx) ExpressionStreamBuffer(ctx));
	this->expStreamStack->push(buff, ctx);
}
void ScriptMachine::endExpressionStream(ThreadContext* ctx) throw() 
{
	this->expStreamStack->pop(ctx);
}
IAlinousVariable* ScriptMachine::getStreamLastValue(ThreadContext* ctx) throw() 
{
	ExpressionStreamBuffer* buff = this->expStreamStack->peek(ctx);
	return buff->getStreamLastValue(ctx);
}
void ScriptMachine::setStreamLastValue(IAlinousVariable* streamLastValue, ThreadContext* ctx) throw() 
{
	ExpressionStreamBuffer* buff = this->expStreamStack->peek(ctx);
	buff->setStreamLastValue(streamLastValue, ctx);
}
bool ScriptMachine::isLeftValue(ThreadContext* ctx) throw() 
{
	return leftValue;
}
void ScriptMachine::setLeftValue(bool leftValue, ThreadContext* ctx) throw() 
{
	this->leftValue = leftValue;
}
AlinousClassVariable* ScriptMachine::getThisPtr(ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = getFrame(ctx);
	return frame->getThisPtr(ctx);
}
void ScriptMachine::setThisPtr(AlinousClassVariable* thisPtr, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = getFrame(ctx);
	frame->setThisPtr(thisPtr, ctx);
}
}}}

