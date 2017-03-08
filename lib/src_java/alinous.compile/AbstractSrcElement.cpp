#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"

namespace alinous {namespace compile {





bool AbstractSrcElement::__init_done = __init_static_variables();
bool AbstractSrcElement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSrcElement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSrcElement::AbstractSrcElement(ThreadContext* ctx) throw()  : IObject(ctx), parent(nullptr), filePath(nullptr), debugFilePath(nullptr), line(0), _startPosition(0), endLine(0), _endPosition(0)
{
}
void AbstractSrcElement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractSrcElement::~AbstractSrcElement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSrcElement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSrcElement", L"~AbstractSrcElement");
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->debugFilePath, this);
	debugFilePath = nullptr;
	if(!prepare){
		return;
	}
}
AbstractSrcElement* AbstractSrcElement::getParent(ThreadContext* ctx) throw() 
{
	return parent;
}
void AbstractSrcElement::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, AbstractSrcElement);
}
AlinousClass* AbstractSrcElement::getAlinousClass(ThreadContext* ctx) throw() 
{
	AbstractSrcElement* elm = getParent(ctx);
	while(elm != nullptr)
	{
		if((dynamic_cast<AlinousClass*>(elm) != 0))
		{
			return static_cast<AlinousClass*>(elm);
		}
		elm = elm->getParent(ctx);
	}
	return nullptr;
}
AlinousFunction* AbstractSrcElement::getAlinousFunction(ThreadContext* ctx) throw() 
{
	AbstractSrcElement* elm = getParent(ctx);
	while(elm != nullptr)
	{
		if((dynamic_cast<AlinousFunction*>(elm) != 0))
		{
			return static_cast<AlinousFunction*>(elm);
		}
		elm = elm->getParent(ctx);
	}
	return nullptr;
}
ClassMethodFunction* AbstractSrcElement::getClassMethodFunction(ThreadContext* ctx) throw() 
{
	AbstractSrcElement* elm = getParent(ctx);
	while(elm != nullptr)
	{
		if((dynamic_cast<ClassMethodFunction*>(elm) != 0))
		{
			return static_cast<ClassMethodFunction*>(elm);
		}
		elm = elm->getParent(ctx);
	}
	return nullptr;
}
void AbstractSrcElement::position(Token* start, Token* end, ThreadContext* ctx) throw() 
{
	this->line = start->beginLine;
	this->_startPosition = start->beginColumn;
	this->endLine = end->endLine;
	this->_endPosition = end->endColumn;
}
void AbstractSrcElement::position(AbstractSrcElement* start, AbstractSrcElement* end, ThreadContext* ctx) throw() 
{
	this->line = start->getLine(ctx);
	this->_startPosition = start->getStartPosition(ctx);
	this->endLine = end->getEndLine(ctx);
	this->_endPosition = end->getEndPosition(ctx);
}
void AbstractSrcElement::position(Token* start, AbstractSrcElement* end, ThreadContext* ctx) throw() 
{
	this->line = start->beginLine;
	this->_startPosition = start->beginColumn;
	this->endLine = end->getEndLine(ctx);
	this->_endPosition = end->getEndPosition(ctx);
}
void AbstractSrcElement::position(AbstractSrcElement* start, Token* end, ThreadContext* ctx) throw() 
{
	this->line = start->getLine(ctx);
	this->_startPosition = start->getStartPosition(ctx);
	this->endLine = end->endLine;
	this->_endPosition = end->endColumn;
}
void AbstractSrcElement::startPosition(Token* start, ThreadContext* ctx) throw() 
{
	this->line = start->beginLine;
	this->_startPosition = start->beginColumn;
}
void AbstractSrcElement::startPosition(AbstractSrcElement* start, ThreadContext* ctx) throw() 
{
	this->line = start->getLine(ctx);
	this->_startPosition = start->getStartPosition(ctx);
}
void AbstractSrcElement::endPosition(Token* end, ThreadContext* ctx) throw() 
{
	this->endLine = end->endLine;
	this->_endPosition = end->endColumn;
}
void AbstractSrcElement::endPosition(AbstractSrcElement* end, ThreadContext* ctx) throw() 
{
	this->endLine = end->getEndLine(ctx);
	this->_endPosition = end->getEndPosition(ctx);
}
int AbstractSrcElement::getLine(ThreadContext* ctx) throw() 
{
	return line;
}
void AbstractSrcElement::setLine(int line, ThreadContext* ctx) throw() 
{
	this->line = line;
}
int AbstractSrcElement::getStartPosition(ThreadContext* ctx) throw() 
{
	return _startPosition;
}
void AbstractSrcElement::setStartPosition(int startPosition, ThreadContext* ctx) throw() 
{
	this->_startPosition = startPosition;
}
int AbstractSrcElement::getEndLine(ThreadContext* ctx) throw() 
{
	return endLine;
}
void AbstractSrcElement::setEndLine(int endLine, ThreadContext* ctx) throw() 
{
	this->endLine = endLine;
}
int AbstractSrcElement::getEndPosition(ThreadContext* ctx) throw() 
{
	return _endPosition;
}
void AbstractSrcElement::setEndPosition(int endPosition, ThreadContext* ctx) throw() 
{
	this->_endPosition = endPosition;
}
String* AbstractSrcElement::getFilePath(ThreadContext* ctx) throw() 
{
	return filePath;
}
void AbstractSrcElement::setFilePath(String* filePath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->filePath), filePath, String);
}
String* AbstractSrcElement::getDebugFilePath(ThreadContext* ctx) throw() 
{
	return debugFilePath;
}
void AbstractSrcElement::setDebugFilePath(String* debugFilePath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->debugFilePath), debugFilePath, String);
}
void AbstractSrcElement::__cleanUp(ThreadContext* ctx){
}
}}

