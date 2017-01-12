#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





constexpr const int HttpParamHandler::STRING_VALUE;
constexpr const int HttpParamHandler::BYTE_VALUE;
constexpr const int HttpParamHandler::SHORT_VALUE;
constexpr const int HttpParamHandler::CHAR_VALUE;
constexpr const int HttpParamHandler::INT_VALUE;
constexpr const int HttpParamHandler::LONG_VALUE;
constexpr const int HttpParamHandler::FLOAT_VALUE;
constexpr const int HttpParamHandler::DOUBLE_VALUE;
bool HttpParamHandler::__init_done = __init_static_variables();
bool HttpParamHandler::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpParamHandler", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpParamHandler::~HttpParamHandler() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpParamHandler::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void HttpParamHandler::handleNormalParam(ScriptMachine* machine, HttpParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx)
{
	String* strValue = param->value;
	HttpParamHandler::ParamResult* typeResult = getStringType(strValue, params, ctx);
	String* name = param->getName(ctx);
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	desc->addSegment((new(ctx) DomNameSegment(ConstStr::getCNST_STR_488(), ctx)), ctx);
	desc->addSegment((new(ctx) DomNameSegment(name, ctx)), ctx);
	switch(typeResult->type) {
	case HttpParamHandler::BYTE_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->byteValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::SHORT_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->shortValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::CHAR_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->charValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::INT_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::LONG_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::FLOAT_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::DOUBLE_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::STRING_VALUE:
	default:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(strValue, ctx)), false, ctx);
		break ;
	}
}
void HttpParamHandler::handleArrayParam(ScriptMachine* machine, HttpArrayParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx)
{
	ArrayList<String>* strValues = param->values;
	int alnsType = -1;
	Iterator<String>* it = params->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* name = it->next(ctx);
		AbstractHttpParameter* p = params->get(name, ctx);
		if(name->equals(AlinousAttrs::ALINOUS_TYPE, ctx) && p->paramType == AbstractHttpParameter::TYPE_NORMAL_PARAM && (static_cast<HttpParameter*>(p))->value != nullptr)
		{
			String* typeValue = (static_cast<HttpParameter*>(p))->value;
			alnsType = handleAlinousTypeOnly(typeValue, ctx);
		}
	}
	String* name = param->getName(ctx);
	DomArray* domarray = (new(ctx) DomArray(ctx));
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	desc->addSegment((new(ctx) DomNameSegment(ConstStr::getCNST_STR_488(), ctx)), ctx);
	desc->addSegment((new(ctx) DomNameSegment(name, ctx)), ctx);
	topFrame->putVariable(machine, desc, domarray, false, ctx);
	int maxLoop = 0;
	if(alnsType > 0)
	{
		maxLoop = strValues->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* valStr = strValues->get(i, ctx);
			IDomVariable* element = toVariable(alnsType, valStr, ctx);
			domarray->add(element, ctx);
		}
		return;
	}
	maxLoop = strValues->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* valStr = strValues->get(i, ctx);
		{
			try
			{
				int intValue = Integer::parseInt(valStr, ctx);
				IDomVariable* element = (new(ctx) DomVariable(intValue, ctx));
				domarray->put(element, ctx);
				continue;
			}
			catch(Throwable* e)
			{
			}
		}
		{
			try
			{
				double dblValue = Double::parseDouble(valStr, ctx);
				IDomVariable* element = (new(ctx) DomVariable(dblValue, ctx));
				domarray->put(element, ctx);
				continue;
			}
			catch(Throwable* e)
			{
			}
		}
		IDomVariable* element = (new(ctx) DomVariable(valStr, ctx));
		domarray->put(element, ctx);
	}
}
void HttpParamHandler::handleFileParam(ScriptMachine* machine, HttpUploadParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx) throw() 
{
}
HttpParamHandler::ParamResult* HttpParamHandler::getStringType(String* strValue, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = params->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* name = it->next(ctx);
		AbstractHttpParameter* p = params->get(name, ctx);
		if(name->equals(AlinousAttrs::ALINOUS_TYPE, ctx) && p->paramType == AbstractHttpParameter::TYPE_NORMAL_PARAM && (static_cast<HttpParameter*>(p))->value != nullptr)
		{
			String* typeValue = (static_cast<HttpParameter*>(p))->value;
			return handleAlinousType(strValue, typeValue, ctx);
		}
	}
	HttpParamHandler::ParamResult* result = (new(ctx) HttpParamHandler::ParamResult(ctx));
	result->type = HttpParamHandler::STRING_VALUE;
	__GC_MV(result, &(result->str), strValue, String);
	{
		try
		{
			int intValue = Integer::parseInt(strValue, ctx);
			result->type = HttpParamHandler::INT_VALUE;
			result->intValue = intValue;
			return result;
		}
		catch(Throwable* e)
		{
		}
	}
	{
		try
		{
			double value = Double::parseDouble(strValue, ctx);
			result->type = HttpParamHandler::DOUBLE_VALUE;
			result->doubleValue = value;
			return result;
		}
		catch(Throwable* e)
		{
		}
	}
	return result;
}
HttpParamHandler::ParamResult* HttpParamHandler::handleAlinousType(String* strValue, String* typeValue, ThreadContext* ctx) throw() 
{
	HttpParamHandler::ParamResult* result = (new(ctx) HttpParamHandler::ParamResult(ctx));
	result->type = HttpParamHandler::STRING_VALUE;
	__GC_MV(result, &(result->str), strValue, String);
	if(typeValue->equals(ConstStr::getCNST_STR_1162(), ctx))
	{
		return result;
	}
	if(typeValue->equals(ConstStr::getCNST_STR_958(), ctx))
	{
		char value = 0;
		{
			try
			{
				value = Byte::parseByte(strValue, ctx);
			}
			catch(Throwable* e)
			{
				return result;
			}
		}
		result->type = HttpParamHandler::BYTE_VALUE;
		result->byteValue = value;
		return result;
	}
		else 
	{
		if(typeValue->equals(ConstStr::getCNST_STR_959(), ctx))
		{
			short value = 0;
			{
				try
				{
					value = Short::parseShort(strValue, ctx);
				}
				catch(Throwable* e)
				{
					return result;
				}
			}
			result->type = HttpParamHandler::SHORT_VALUE;
			result->shortValue = value;
			return result;
		}
				else 
		{
			if(typeValue->equals(ConstStr::getCNST_STR_960(), ctx))
			{
				short value = 0;
				{
					try
					{
						value = Short::parseShort(strValue, ctx);
					}
					catch(Throwable* e)
					{
						return result;
					}
				}
				result->type = HttpParamHandler::CHAR_VALUE;
				result->charValue = ((wchar_t)value);
				return result;
			}
						else 
			{
				if(typeValue->equals(ConstStr::getCNST_STR_961(), ctx))
				{
					int value = 0;
					{
						try
						{
							value = Integer::parseInt(strValue, ctx);
						}
						catch(Throwable* e)
						{
							return result;
						}
					}
					result->type = HttpParamHandler::INT_VALUE;
					result->intValue = value;
					return result;
				}
								else 
				{
					if(typeValue->equals(ConstStr::getCNST_STR_962(), ctx))
					{
						long long value = 0;
						{
							try
							{
								value = Long::parseLong(strValue, ctx);
							}
							catch(Throwable* e)
							{
								return result;
							}
						}
						result->type = HttpParamHandler::LONG_VALUE;
						result->longValue = value;
						return result;
					}
										else 
					{
						if(typeValue->equals(ConstStr::getCNST_STR_964(), ctx))
						{
							float value = 0;
							{
								try
								{
									value = Float::parseFloat(strValue, ctx);
								}
								catch(Throwable* e)
								{
									return result;
								}
							}
							result->type = HttpParamHandler::FLOAT_VALUE;
							result->floatValue = value;
							return result;
						}
												else 
						{
							if(typeValue->equals(ConstStr::getCNST_STR_963(), ctx))
							{
								double value = 0;
								{
									try
									{
										value = Double::parseDouble(strValue, ctx);
									}
									catch(Throwable* e)
									{
										return result;
									}
								}
								result->type = HttpParamHandler::DOUBLE_VALUE;
								result->doubleValue = value;
								return result;
							}
						}
					}
				}
			}
		}
	}
	return result;
}
IDomVariable* HttpParamHandler::toVariable(int alnsType, String* valStr, ThreadContext* ctx) throw() 
{
	switch(alnsType) {
	case HttpParamHandler::BYTE_VALUE:
		{
			char value = 0;
			{
				try
				{
					value = Byte::parseByte(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::SHORT_VALUE:
		{
			short value = 0;
			{
				try
				{
					value = Short::parseShort(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::CHAR_VALUE:
		{
			wchar_t value = 0;
			{
				try
				{
					value = ((wchar_t)Short::parseShort(valStr, ctx));
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::INT_VALUE:
		{
			int value = 0;
			{
				try
				{
					value = Integer::parseInt(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::LONG_VALUE:
		{
			long long value = 0;
			{
				try
				{
					value = Long::parseLong(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::FLOAT_VALUE:
		{
			float value = 0;
			{
				try
				{
					value = Float::parseFloat(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::DOUBLE_VALUE:
		{
			double value = 0;
			{
				try
				{
					value = Double::parseDouble(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::STRING_VALUE:
	default:
		break ;
	}
	return (new(ctx) DomVariable(valStr, ctx));
}
int HttpParamHandler::handleAlinousTypeOnly(String* typeValue, ThreadContext* ctx) throw() 
{
	if(typeValue->equals(ConstStr::getCNST_STR_1162(), ctx))
	{
		return HttpParamHandler::STRING_VALUE;
	}
	if(typeValue->equals(ConstStr::getCNST_STR_958(), ctx))
	{
		return HttpParamHandler::BYTE_VALUE;
	}
		else 
	{
		if(typeValue->equals(ConstStr::getCNST_STR_959(), ctx))
		{
			return HttpParamHandler::SHORT_VALUE;
		}
				else 
		{
			if(typeValue->equals(ConstStr::getCNST_STR_960(), ctx))
			{
				return HttpParamHandler::CHAR_VALUE;
			}
						else 
			{
				if(typeValue->equals(ConstStr::getCNST_STR_961(), ctx))
				{
					return HttpParamHandler::INT_VALUE;
				}
								else 
				{
					if(typeValue->equals(ConstStr::getCNST_STR_962(), ctx))
					{
						return HttpParamHandler::LONG_VALUE;
					}
										else 
					{
						if(typeValue->equals(ConstStr::getCNST_STR_964(), ctx))
						{
							return HttpParamHandler::FLOAT_VALUE;
						}
												else 
						{
							if(typeValue->equals(ConstStr::getCNST_STR_963(), ctx))
							{
								return HttpParamHandler::DOUBLE_VALUE;
							}
						}
					}
				}
			}
		}
	}
	return HttpParamHandler::STRING_VALUE;
}
}}}

namespace alinous {namespace runtime {namespace engine {





bool HttpParamHandler::ParamResult::__init_done = __init_static_variables();
bool HttpParamHandler::ParamResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpParamHandler::ParamResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpParamHandler::ParamResult::~ParamResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpParamHandler::ParamResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ParamResult", L"~ParamResult");
	__e_obj1.add(this->str, this);
	str = nullptr;
	if(!prepare){
		return;
	}
}
}}}

