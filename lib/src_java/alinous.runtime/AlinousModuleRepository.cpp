#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/ParseException.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/AlinousPlusParserConstants.h"
#include "alinous.compile/AlinousPlusParserTokenManager.h"
#include "alinous.compile/AlinousPlusParser.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.system.config/DataSourceInfo.h"
#include "alinous.system.config/MailInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.runtime/ModuleNotFoundException.h"
#include "alinous.runtime/CompileErrorException.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.runtime/AlinousModule.h"

namespace alinous {namespace runtime {





String* AlinousModuleRepository::encode = ConstStr::getCNST_STR_1106();
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
	AlinousConfig* config = this->core->getConfig(ctx);
	SystemInfo* system = config->getSystem(ctx);
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
	AlinousConfig* config = this->core->getConfig(ctx);
	SystemInfo* system = config->getSystem(ctx);
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
			throw (new(ctx) CompileErrorException(ConstStr::getCNST_STR_1105(), e, ctx));
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
void AlinousModuleRepository::__cleanUp(ThreadContext* ctx){
}
}}

