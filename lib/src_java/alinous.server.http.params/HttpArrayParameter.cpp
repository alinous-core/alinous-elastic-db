#include "include/global.h"


#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpArrayParameter.h"

namespace alinous {namespace server {namespace http {namespace params {





bool HttpArrayParameter::__init_done = __init_static_variables();
bool HttpArrayParameter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpArrayParameter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpArrayParameter::HttpArrayParameter(String* name, ArrayList<String>* values, ThreadContext* ctx) throw()  : IObject(ctx), AbstractHttpParameter(ctx), name(nullptr), values(nullptr)
{
	this->paramType = AbstractHttpParameter::TYPE_ARRAY_PARAM;
	int index = name->indexOf(ConstStr::getCNST_STR_564(), ctx);
	if(index < 0)
	{
		__GC_MV(this, &(this->name), name, String);
	}
		else 
	{
		__GC_MV(this, &(this->name), name->substring(0, index, ctx), String);
	}
	GCUtils<ArrayList<String> >::mv(this, &(this->values), values, ctx);
}
void HttpArrayParameter::__construct_impl(String* name, ArrayList<String>* values, ThreadContext* ctx) throw() 
{
	this->paramType = AbstractHttpParameter::TYPE_ARRAY_PARAM;
	int index = name->indexOf(ConstStr::getCNST_STR_564(), ctx);
	if(index < 0)
	{
		__GC_MV(this, &(this->name), name, String);
	}
		else 
	{
		__GC_MV(this, &(this->name), name->substring(0, index, ctx), String);
	}
	GCUtils<ArrayList<String> >::mv(this, &(this->values), values, ctx);
}
 HttpArrayParameter::~HttpArrayParameter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpArrayParameter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HttpArrayParameter", L"~HttpArrayParameter");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
	AbstractHttpParameter::__releaseRegerences(true, ctx);
}
void HttpArrayParameter::addValues(String* value, ThreadContext* ctx) throw() 
{
	this->values->add(value, ctx);
}
void HttpArrayParameter::addParam(AbstractHttpParameter* newParam, ThreadContext* ctx) throw() 
{
	switch(newParam->paramType) {
	case AbstractHttpParameter::TYPE_ARRAY_PARAM:
		{
			HttpArrayParameter* newArray = static_cast<HttpArrayParameter*>(newParam);
			this->values->addAll(newArray->values, ctx);
			break ;
		}
	case AbstractHttpParameter::TYPE_NORMAL_PARAM:
	case AbstractHttpParameter::TYPE_FILE_PARAM:
	default:
		{
		String* str = newParam->getStringValue(ctx);
		this->values->add(str, ctx);
		break ;
		}
	}
}
String* HttpArrayParameter::getName(ThreadContext* ctx) throw() 
{
	return name;
}
String* HttpArrayParameter::getStringValue(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* str = this->values->get(i, ctx);
		if(i > 0)
		{
			buff->append(ConstStr::getCNST_STR_888(), ctx);
		}
		buff->append(str, ctx);
	}
	return buff->toString(ctx);
}
void HttpArrayParameter::__cleanUp(ThreadContext* ctx){
}
}}}}

