#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.system/AlinousException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.runtime.dbif/DataSourceManager.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.server.webmodule/WebModuleManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.system/AlinousCoreLogger.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/HttpUploadParameter.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.engine/DebugMainFrameSrcElement.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.runtime.engine/HttpParamHandler.h"

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
	AlinousSrc* src = module->getModuleSource(ctx);
	MainStackFrame* topFrame = (new(ctx) MainStackFrame(src, this->stackIdSerial++, ctx));
	this->stackFrames->push(topFrame, ctx);
	topFrame->subFrame(module->getModuleSource(ctx), ctx);
	__GC_MV(this, &(this->core), core, AlinousCore);
	SystemInfo* sysinfo = this->core->getConfig(ctx)->getSystem(ctx);
	String* defaultSrc = sysinfo->getDefaultDatastore(ctx);
	IDatabaseDriver* driver = this->core->getDatabaseManager(ctx)->get(defaultSrc, ctx);
	if(driver == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1172()->clone(ctx)->append(defaultSrc, ctx)->append(ConstStr::getCNST_STR_1173(), ctx), ctx));
	}
	IDatabaseConnection* con = driver->connect(ctx);
	__GC_MV(this, &(this->currentDbHandle), (new(ctx) DatabaseHandle(driver, con, ctx)), DatabaseHandle);
	this->dbHandles->add(this->currentDbHandle, ctx);
}
void ScriptMachine::__construct_impl(AlinousModule* module, AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	AlinousSrc* src = module->getModuleSource(ctx);
	MainStackFrame* topFrame = (new(ctx) MainStackFrame(src, this->stackIdSerial++, ctx));
	this->stackFrames->push(topFrame, ctx);
	topFrame->subFrame(module->getModuleSource(ctx), ctx);
	__GC_MV(this, &(this->core), core, AlinousCore);
	SystemInfo* sysinfo = this->core->getConfig(ctx)->getSystem(ctx);
	String* defaultSrc = sysinfo->getDefaultDatastore(ctx);
	IDatabaseDriver* driver = this->core->getDatabaseManager(ctx)->get(defaultSrc, ctx);
	if(driver == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1172()->clone(ctx)->append(defaultSrc, ctx)->append(ConstStr::getCNST_STR_1173(), ctx), ctx));
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
void ScriptMachine::__cleanUp(ThreadContext* ctx){
}
}}}

