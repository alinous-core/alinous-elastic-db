#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/DomTokenizer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html/DocType.h"
#include "alinous.html/DomComment.h"
#include "alinous.html/DomText.h"
#include "alinous.html/AlinousDomEventHandler.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/Test.h"

namespace alinous {namespace html {





bool Attribute::__init_done = __init_static_variables();
bool Attribute::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Attribute", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Attribute::Attribute(String* name, String* value, DomNode* parent, ThreadContext* ctx) throw()  : IObject(ctx), IDomObject(ctx), name(nullptr), value(nullptr), parent(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->value), value, String);
	__GC_MV(this, &(this->parent), parent, DomNode);
}
void Attribute::__construct_impl(String* name, String* value, DomNode* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->value), value, String);
	__GC_MV(this, &(this->parent), parent, DomNode);
}
 Attribute::Attribute(ThreadContext* ctx) throw()  : IObject(ctx), IDomObject(ctx), name(nullptr), value(nullptr), parent(nullptr)
{
}
void Attribute::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Attribute::~Attribute() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Attribute::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Attribute", L"~Attribute");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->value, this);
	value = nullptr;
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	if(!prepare){
		return;
	}
}
DomNode* Attribute::getParent(ThreadContext* ctx) throw() 
{
	return parent;
}
void Attribute::setParent(DomNode* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, DomNode);
}
String* Attribute::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void Attribute::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
String* Attribute::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void Attribute::setValue(String* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, String);
}
String* Attribute::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->name != nullptr && this->value != nullptr)
	{
		buff->append(this->name, ctx);
		buff->append(ConstStr::getCNST_STR_1798(), ctx);
		buff->append(this->value, ctx);
		buff->append(ConstStr::getCNST_STR_1321(), ctx);
	}
		else 
	{
		if(this->name != nullptr && this->value == nullptr)
		{
			buff->append(this->name, ctx);
		}
				else 
		{
			if(this->name == nullptr && this->value != nullptr)
			{
				buff->append(ConstStr::getCNST_STR_1321(), ctx);
				buff->append(this->value, ctx);
				buff->append(ConstStr::getCNST_STR_1321(), ctx);
			}
		}
	}
	return buff->toString(ctx);
}
IDomObject* Attribute::getNextElement(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IDomObject* Attribute::getNextSibilingElement(ThreadContext* ctx) throw() 
{
	return nullptr;
}
int Attribute::getType(ThreadContext* ctx) throw() 
{
	return IDomObject::TYPE_ATTRIBUTE;
}
void Attribute::__cleanUp(ThreadContext* ctx){
}
}}

