/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

#include "alinous.lock/LockObject.h"

#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"

#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom/DomArray.h"


#include "java.lang/Boolean.h"
#include "java.lang/Comparable.h"
#include "java.lang/Number.h"
#include "java.lang/Double.h"
#include "java.lang/Integer.h"
#include "java.lang/Byte.h"
#include "java.lang/Long.h"
#include "java.lang/Float.h"
#include "java.lang/Short.h"

#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "alinous.numeric/BigDecimal.h"
#include "java.sql/Timestamp.h"



namespace alinous{ namespace jdk{ namespace functions{

IDomVariable* DomJDomConverter::j2n(JNIEnv *env, jobject jdom, ThreadContext* ctx) throw() {
	jint domType = env->CallIntMethod(jdom, this->domGetDomType);

	if(domType == IDomVariable::TYPE_DOM){
		return jdom2dom(env, jdom, ctx);
	}

	return jdomArray2domArray(env, jdom, ctx);
}

DomVariable* DomJDomConverter::jdom2dom(JNIEnv *env, jobject jdom, ThreadContext* ctx) throw() {
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomJDomConverter", L"jdom2dom");

	DomVariable* returnedValue = nullptr;

	jint valueType = env->CallIntMethod(jdom, this->domGetValueType);
	switch(valueType){
	case VariantValue::TYPE_BYTE:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		char value = Byte::valueOf(vstr, ctx)->byteValue(ctx);

		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);
		break;
	}
	case VariantValue::TYPE_SHORT:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		short value = Short::valueOf(vstr, ctx)->shortValue(ctx);

		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);
		break;
	}
	case VariantValue::TYPE_CHAR:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		wchar_t value = (wchar_t)Short::valueOf(vstr, ctx)->shortValue(ctx);

		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);
		break;
	}
	case VariantValue::TYPE_INT:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		int value = Integer::valueOf(vstr, ctx)->intValue(ctx);

		returnedValue = new DomVariable(value, ctx);


		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);
		break;
	}
	case VariantValue::TYPE_LONG:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);


		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		long long value = Long::valueOf(vstr, ctx)->longValue(ctx);

		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);

		break;
	}
	case VariantValue::TYPE_FLOAT:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		float value = Float::valueOf(vstr, ctx)->floatValue(ctx);

		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);

		break;
	};
	case VariantValue::TYPE_DOUBLE:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		double value = Double::valueOf(vstr, ctx)->doubleValue(ctx);

		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);

		break;
	}
	case VariantValue::TYPE_STRING:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		returnedValue = new DomVariable(vstr, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);

		break;
	}
	case VariantValue::TYPE_TIME:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		TimeOnlyTimestamp* value = TimeOnlyTimestamp::valueOf(vstr, ctx);
		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);

		break;
	}
	case VariantValue::TYPE_TIMESTAMP:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);

		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		Timestamp* value = Timestamp::valueOf(vstr, ctx);
		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);

		break;
	}
	case VariantValue::TYPE_BIG_DECIMAL:
	{
		jstring jstr = (jstring)env->CallObjectMethod(jdom, this->domGetStringValue);
		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jstr, &isCopy);


		UnicodeString* vstr = new UnicodeString(c_str, ctx);
		BigDecimal* value = new BigDecimal(vstr, ctx);
		returnedValue = new DomVariable(value, ctx);

		env->ReleaseStringUTFChars(jstr, c_str);
		env->DeleteLocalRef(jstr);
		break;
	}
	default: // null
		returnedValue = new DomVariable(ctx);
		break;
	}

	jobject jit = env->CallObjectMethod(jdom, this->domGetPropertiesIterator);
	while(env->CallBooleanMethod(jit, this->itHasNext) == JNI_TRUE){
		jstring jkey = (jstring)env->CallObjectMethod(jit, this->itHasNext);
		jobject jprop = env->CallObjectMethod(jdom, this->domGetProperty, jkey);

		jboolean isCopy;
		const char* c_str = env->GetStringUTFChars(jkey, &isCopy);

		UnicodeString* key = new UnicodeString(c_str, ctx);
		IDomVariable* prop = j2n(env, jprop, ctx);

		returnedValue->setProperty(key, prop, ctx);

		env->ReleaseStringUTFChars(jkey, c_str);
		env->DeleteLocalRef(jkey);
		env->DeleteLocalRef(jprop);
	}

	env->DeleteLocalRef(jit);

	return returnedValue;
}
DomArray* DomJDomConverter::jdomArray2domArray(JNIEnv *env, jobject jdomarray, ThreadContext* ctx) throw() {
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomJDomConverter", L"jdomArray2domArray");

	jint jsize = env->CallIntMethod(jdomarray, this->arSize);

	int maxLoop = (int)jsize;
	DomArray* ar = new DomArray(ctx);
	for(int i = 0; i != maxLoop; ++i){
		jobject jelement = env->CallObjectMethod(jdomarray, this->arGut, i);

		IDomVariable* element = j2n(env, jelement, ctx);
		ar->put(element, ctx);

		env->DeleteLocalRef(jelement);
	}

	return ar;
}


jobject DomJDomConverter::n2j(JNIEnv *env, IDomVariable* dom, ThreadContext* ctx) throw(){
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomJDomConverter", L"n2j");

	int domType = dom->getDomType(ctx);
	if(domType == IDomVariable::TYPE_DOM){
		return ndomy2j(env, (DomVariable*)dom, ctx);
	}

	return narray2j(env, (DomArray*)dom, ctx);
}

jobject DomJDomConverter::ndomy2j(JNIEnv *env, DomVariable* dom, ThreadContext* ctx) throw() {
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomJDomConverter", L"ndomy2j");

	jobject returnValue = nullptr;

	int valueType = dom->getValueType(ctx);
	switch(valueType){
	case VariantValue::TYPE_BYTE:
	{
		jbyte value = dom->getValue(ctx)->getByte(ctx);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domByteInit, value);
		break;
	}
	case VariantValue::TYPE_SHORT:
	{
		jshort value = dom->getValue(ctx)->getShort(ctx);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domShortInit, value);
		break;
	}
	case VariantValue::TYPE_CHAR:
	{
		jchar value = dom->getValue(ctx)->getChar(ctx);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domCharInit, value);
		break;
	}
	case VariantValue::TYPE_INT:
	{
		jint value = dom->getValue(ctx)->getInt(ctx);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domIntInit, value);
		break;
	}
	case VariantValue::TYPE_LONG:
	{
		jlong value = dom->getValue(ctx)->getLong(ctx);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domLongInit, value);
		break;
	}
	case VariantValue::TYPE_FLOAT:
	{
		jfloat value = dom->getValue(ctx)->getFloat(ctx);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domFloatInit, value);
		break;
	};
	case VariantValue::TYPE_DOUBLE:
	{
		jdouble value = dom->getValue(ctx)->getDouble(ctx);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domDoubleInit, value);
		break;
	}
	case VariantValue::TYPE_STRING:
	{
		char* utfStr = dom->getStringValue(ctx)->toCString(ctx);
		jstring value = env->NewStringUTF(utfStr);
		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domStringInit, value);

		env->DeleteLocalRef(value);

		delete [] utfStr;
		break;
	}
	case VariantValue::TYPE_TIME:
	{
		jlong mills = dom->getLongValue(ctx);
		jobject param = env->NewObject(JavaFunctionManager::timestampClass, this->timeSpecInit, mills);

		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domTimeSpecInit, param);

		env->DeleteLocalRef(param);

		break;
	}
	case VariantValue::TYPE_TIMESTAMP:
	{
		jlong mills = dom->getLongValue(ctx);
		jobject param = env->NewObject(JavaFunctionManager::timestampClass, this->timestampInit, mills);

		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domTimestampInit, param);

		env->DeleteLocalRef(param);

		break;
	}
	case VariantValue::TYPE_BIG_DECIMAL:
	{
		char* utfStr = dom->getStringValue(ctx)->toCString(ctx);
		jstring value = env->NewStringUTF(utfStr);

		jobject param = env->NewObject(JavaFunctionManager::bigDecimalClass, this->bigDecimalInit, value);

		returnValue = env->NewObject(JavaFunctionManager::domVariable, this->domBigDecimalInit, param);

		env->DeleteLocalRef(value);
		delete [] utfStr;

		env->DeleteLocalRef(param);

		break;
	}
	default:
		returnValue = nullptr;
		break;
	}

	Iterator<String>* it = dom->getPropertiesIterator(ctx);
	while(it->hasNext(ctx)){
		UnicodeString* key = it->next(ctx);
		IDomVariable* propDom = dom->getProperty(key, ctx);

		char* utfStr = dom->getStringValue(ctx)->toCString(ctx);
		jstring jkey = env->NewStringUTF(utfStr);

		jobject jprop = n2j(env, propDom, ctx);
		env->CallVoidMethod(returnValue, this->domSetProperty, jkey, jprop);

		env->DeleteLocalRef(jkey);
		env->DeleteLocalRef(jprop);
		delete [] utfStr;
	}

	return returnValue;
}
jobject DomJDomConverter::narray2j(JNIEnv *env, DomArray* domArray, ThreadContext* ctx) throw() {
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomJDomConverter", L"narray2j");

	jobject retArray = env->NewObject(JavaFunctionManager::domArray, this->arInit);

	int maxLoop = domArray->size(ctx);
	for(int i = 0; i != maxLoop; ++i){
		IDomVariable* element = domArray->get(i, ctx);

		jobject jelement = n2j(env, element, ctx);
		env->CallVoidMethod(retArray, this->arPut, jelement);

		env->DeleteLocalRef(jelement);
	}

	return retArray;
}


DomJDomConverter::DomJDomConverter(JNIEnv *env) throw() {
	domStringInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(Ljava/lang/String;)V");
	domByteInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(B)V");
	domShortInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(S)V");
	domCharInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(C)V");
	domIntInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(I)V");
	domLongInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(J)V");
	domDoubleInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(D)V");
	domFloatInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(F)V");
	domTimestampInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(Ljava/sql/Timestamp;)V");
	domTimeSpecInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(Ljava/sql/TimeSpec;)V");
	domBigDecimalInit = env->GetMethodID(JavaFunctionManager::domVariable, "<init>", "(Lalinous/numeric/BigDecimal;)V");

	domGetDomType = env->GetMethodID(JavaFunctionManager::iDomVariableClass, "getDomType", "()I");
	domGetValueType = env->GetMethodID(JavaFunctionManager::domVariable, "getValueType", "()I");

	domGetStringValue = env->GetMethodID(JavaFunctionManager::domVariable, "getStringValue", "()Ljava/lang/String;");

	domGetProperty = env->GetMethodID(JavaFunctionManager::domVariable, "getProperty", "(Ljava/lang/String;)Lalinous/runtime/dom/IDomVariable;");
	domSetProperty = env->GetMethodID(JavaFunctionManager::domVariable, "setProperty", "(Ljava/lang/String;Lalinous/runtime/dom/IDomVariable;)V");
	domGetPropertiesIterator = env->GetMethodID(JavaFunctionManager::domVariable, "getPropertiesIterator", "()Ljava/util/Iterator;");

	arInit = env->GetMethodID(JavaFunctionManager::domArray, "<init>", "()V");
	arSize = env->GetMethodID(JavaFunctionManager::domArray, "size", "()I");
	arPut = env->GetMethodID(JavaFunctionManager::domArray, "put", "(Lalinous/runtime/dom/IDomVariable;)V");
	arGut = env->GetMethodID(JavaFunctionManager::domArray, "get", "(I)Lalinous/runtime/dom/IDomVariable;");

	bigDecimalInit = env->GetMethodID(JavaFunctionManager::bigDecimalClass, "<init>", "(Ljava/lang/String;)V");

	timeSpecInit = env->GetMethodID(JavaFunctionManager::timeSpecClass, "<init>", "(J)V");
	timestampInit = env->GetMethodID(JavaFunctionManager::timestampClass, "<init>", "(J)V");

	itHasNext = env->GetMethodID(JavaFunctionManager::iteratorClass, "hasNext", "()Z");
	itNext = env->GetMethodID(JavaFunctionManager::iteratorClass, "next", "()Ljava/lang/Object;");
}


}}}

