/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

#include <sys/types.h>

namespace alinous{ namespace jdk{ namespace functions{

jclass JavaFunctionManager::alinousCoreClass = nullptr;
jclass JavaFunctionManager::javaConnectorClass = nullptr;
jclass JavaFunctionManager::loggerWrapperClass = nullptr;
jclass JavaFunctionManager::callbackWrapperClass = nullptr;
jclass JavaFunctionManager::functionModelClass = nullptr;
jclass JavaFunctionManager::iDomVariableClass = nullptr;
jclass JavaFunctionManager::domVariable = nullptr;
jclass JavaFunctionManager::domArray = nullptr;
jclass JavaFunctionManager::timeSpecClass = nullptr;
jclass JavaFunctionManager::timestampClass = nullptr;
jclass JavaFunctionManager::bigDecimalClass = nullptr;
jclass JavaFunctionManager::iteratorClass = nullptr;



JavaFunctionManager::JavaFunctionManager(AlinousCore* core, ThreadContext* ctx) : IObject(ctx), core(core), enabled(false) {
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JavaFunctionManager", L"JavaFunctionManager");

	this->core =__GC_INS(this, core, AlinousCore);

	this->jniThread = new JNIThread();

	UnicodeString* classPath =new UnicodeString(L"-Djava.class.path=.:${JAVA_HOME}/jre/lib/rt.jar:", ctx);
	classPath->append(core->getAlinousHome(ctx), ctx);
	classPath->append(new UnicodeString(L"runtime/alinous.jar", ctx), ctx);

	char* cstr_class_path = classPath->toCString(ctx);

	options[0].optionString = cstr_class_path;
	options[1].optionString = (char *)  "-Djava.compiler=NONE";
	vm_args.version = JNI_VERSION_1_6;
	vm_args.options = options;
	vm_args.nOptions = 2;
	vm_args.ignoreUnrecognized = JNI_FALSE;

	JNIEnv *env;
	jint res = JNI_CreateJavaVM(&jvm,(void **)&env,&vm_args);
	if(res < 0){
		return;
	}
	jni = *env;
	vmi = *jvm;
	this->enabled = true;

	delete [] cstr_class_path;

}

void JavaFunctionManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->core != nullptr){
		//dispose(ctx);

		__GC_DEC(this, this->core, AlinousCore);
		this->core = nullptr;

		delete this->jniThread;
		this->jniThread = nullptr;
	}


}

IAlinousVariable* JavaFunctionManager::invoke(UnicodeString* prefix, UnicodeString* name, ArrayList<IDomVariable>* arguments, ThreadContext* ctx){
	JNIEnv *env;
	bool attached = initEnv(&env);

	jmethodID findFunctionId = env->GetMethodID(javaConnectorClass, "findFunction", "(Ljava/lang/String;Ljava/lang/String;)Lorg/alinous/jdk/model/FunctionModel;");

	char* name_cstr = name->toCString(ctx);
	jstring name_jstr = env->NewStringUTF(name_cstr);
	char* prefix_cstr = prefix->toCString(ctx);
	jstring prefix_jstr = env->NewStringUTF(prefix_cstr);

	delete [] name_cstr;
	delete [] prefix_cstr;

	jobject model = env->CallObjectMethod(this->javaConnector, findFunctionId, prefix_jstr, name_jstr);
	if(model == nullptr){
		if(!attached){
			this->jvm->DetachCurrentThread();
		}
		return nullptr;
	}

	DomJDomConverter cnv(env);
	int maxLoop = arguments->size(ctx);
	jobjectArray arrayObject = env->NewObjectArray(maxLoop, iDomVariableClass, nullptr);

	for(int i = 0; i != maxLoop; ++i){
		IDomVariable* dom = arguments->get(i, ctx);
		jobject jobj = cnv.n2j(env, dom, ctx);

		env->SetObjectArrayElement(arrayObject, i, jobj);
	}

	jmethodID invoke = env->GetMethodID(functionModelClass, "invoke", "([Lalinous/runtime/dom/IDomVariable;)Lalinous/runtime/dom/IDomVariable;");
	jobject retValue = env->CallObjectMethod(model, invoke, arrayObject);

	IDomVariable* returnedValue = cnv.j2n(env, retValue, ctx);

	env->DeleteLocalRef(model);
	if(!attached){
		this->jvm->DetachCurrentThread();
	}

	return returnedValue;
}

bool JavaFunctionManager::initEnv(JNIEnv **env){
	jint result = this->jvm->GetEnv((void **)env, vm_args.version);
	if (result == JNI_EDETACHED) {
		result = this->jvm->AttachCurrentThread((void **)&env, NULL);
		return false;
	}

	return true;
}

AlinousType* JavaFunctionManager::getFunctionReturnType(UnicodeString* prefix, UnicodeString* name, ThreadContext* ctx) {
	return new AlinousType(ctx);
}


bool JavaFunctionManager::isFunctionPrefix(UnicodeString* prefix, ThreadContext* ctx) {
	JNIEnv *env;
	bool attached = initEnv(&env);

	char* name_cstr = prefix->toCString(ctx);
	jstring name_jstr = env->NewStringUTF(name_cstr);

	delete [] name_cstr;

	jmethodID invokeGetContainer = env->GetMethodID(javaConnectorClass, "getContainer", "(Ljava/lang/String;)Lorg/alinous/jdk/FunctionConitainer;");
	jobject ret = env->CallObjectMethod(this->javaConnector, invokeGetContainer, name_jstr);

	bool bl = ret != nullptr;

	if(!attached){
		this->jvm->DetachCurrentThread();
	}

	return bl;
}

bool JavaFunctionManager::isJavaFunction(UnicodeString* prefix, UnicodeString* funcName, ThreadContext* ctx){
	JNIEnv *env;
	bool attached = initEnv(&env);

	char* prefix_cstr = prefix->toCString(ctx);
	jstring prefix_jstr = env->NewStringUTF(prefix_cstr);
	char* name_cstr = funcName->toCString(ctx);
	jstring name_jstr = env->NewStringUTF(name_cstr);

	delete [] prefix_cstr;
	delete [] name_jstr;



	jmethodID invokeGetContainer = env->GetMethodID(javaConnectorClass, "findFunction", "(Ljava/lang/String;Ljava/lang/String;)Z");
	jboolean ret = env->CallBooleanMethod(this->javaConnector, invokeGetContainer, prefix_jstr, name_jstr);

	// jboolean bl = env->CallBooleanMethod(this->javaConnector, invokeGetContainer, name_jstr);

	bool bl = ret;

	if(!attached){
		this->jvm->DetachCurrentThread();
	}

	return bl;
}


void JavaFunctionManager::init(ThreadContext* ctx) {
	JNIEnv *env;
	bool attached = initEnv(&env);

	//init classes
	jclass _timeOnly = env->FindClass("alinous/numeric/TimeOnlyTimestamp");
	JavaFunctionManager::timeSpecClass = (jclass)env->NewGlobalRef(_timeOnly);
	env->DeleteLocalRef(_timeOnly);

	jclass _alinousCoreClass = env->FindClass("alinous/jdk/functions/AlinousSystemWrapper");
	JavaFunctionManager::alinousCoreClass = (jclass)env->NewGlobalRef(_alinousCoreClass);
	env->DeleteLocalRef(_alinousCoreClass);

	jclass _javaConnectorClass = env->FindClass("org/alinous/jdk/JavaConnectorFunctionManager");
	JavaFunctionManager::javaConnectorClass = (jclass)env->NewGlobalRef(_javaConnectorClass);
	env->DeleteLocalRef(_javaConnectorClass);

	jclass _loggerWrapperClass = env->FindClass("alinous/jdk/functions/LoggerWrapper");
	JavaFunctionManager::loggerWrapperClass = (jclass)env->NewGlobalRef(_loggerWrapperClass);
	env->DeleteLocalRef(_loggerWrapperClass);

	jclass _callbackWrapperClass = env->FindClass("alinous/jdk/functions/CallbackWrapper");
	JavaFunctionManager::callbackWrapperClass = (jclass)env->NewGlobalRef(_callbackWrapperClass);
	env->DeleteLocalRef(_callbackWrapperClass);

	jclass _functionModelClass = env->FindClass("org/alinous/jdk/model/FunctionModel");
	JavaFunctionManager::functionModelClass = (jclass)env->NewGlobalRef(_functionModelClass);
	env->DeleteLocalRef(_functionModelClass);

	jclass _iDomVariableClass = env->FindClass("alinous/runtime/dom/IDomVariable");
	JavaFunctionManager::iDomVariableClass = (jclass)env->NewGlobalRef(_iDomVariableClass);
	env->DeleteLocalRef(_iDomVariableClass);

	jclass _domVariable = env->FindClass("alinous/runtime/dom/DomVariable");
	JavaFunctionManager::domVariable = (jclass)env->NewGlobalRef(_domVariable);
	env->DeleteLocalRef(_domVariable);

	jclass _domArray = env->FindClass("alinous/runtime/dom/DomArray");
	JavaFunctionManager::domArray = (jclass)env->NewGlobalRef(_domArray);
	env->DeleteLocalRef(_domArray);



	jclass _timestampClass = env->FindClass("java/sql/Timestamp");
	JavaFunctionManager::timestampClass = (jclass)env->NewGlobalRef(_timestampClass);
	env->DeleteLocalRef(_timestampClass);

	jclass _bigDecimalClass = env->FindClass("alinous/numeric/BigDecimal");
	JavaFunctionManager::bigDecimalClass = (jclass)env->NewGlobalRef(_bigDecimalClass);
	env->DeleteLocalRef(_bigDecimalClass);

	jclass _iteratorClass = env->FindClass("java/util/Iterator");
	JavaFunctionManager::iteratorClass = (jclass)env->NewGlobalRef(_iteratorClass);
	env->DeleteLocalRef(_iteratorClass);



	registerNatives(env);

	long long ptr = (long long)this;
	jlong jptr = (jlong)ptr;

	jmethodID init_method = env->GetMethodID(alinousCoreClass,
				"<init>", "(J)V");
	jobject alinous_sys_obj = env->NewObject(alinousCoreClass, init_method, jptr);



	init_method = env->GetMethodID(javaConnectorClass,
			"<init>", "(Ljava/lang/String;Lalinous/system/functions/IAlinousSystem;ZZ)V");

	char* uniHome = this->core->getAlinousHome(ctx)->toCString(ctx);
	jstring jalinousHome = env->NewStringUTF(uniHome);

	this->javaConnector = env->NewObject(javaConnectorClass, init_method, jalinousHome, alinous_sys_obj, JNI_TRUE, JNI_TRUE);
	this->javaConnector = env->NewGlobalRef(this->javaConnector);

	jmethodID jconMethodId = env->GetMethodID(javaConnectorClass, "init", "()V");
	env->CallVoidMethod(this->javaConnector, jconMethodId);

	jmethodID startScan = env->GetMethodID(javaConnectorClass,	"startScan", "()V");
	env->CallVoidMethod(this->javaConnector, startScan);

	env->DeleteLocalRef(jalinousHome);
	env->DeleteLocalRef(alinous_sys_obj);
	delete [] uniHome;

	if(!attached){
		this->jvm->DetachCurrentThread();
	}

}

void JavaFunctionManager::dispose(ThreadContext* ctx) {
	if(this->enabled){
		JNIEnv *env;
		initEnv(&env);

		jmethodID endScanId = env->GetMethodID(javaConnectorClass, "endScan", "()V");
		env->CallVoidMethod(this->javaConnector, endScanId);

		jmethodID disposeId = env->GetMethodID(javaConnectorClass, "dispose", "()V");
		env->CallVoidMethod(this->javaConnector, disposeId);


		env->DeleteGlobalRef(this->javaConnector);
		this->javaConnector = nullptr;


		env->DeleteGlobalRef(this->javaConnector);

		env->DeleteGlobalRef(alinousCoreClass);
		env->DeleteGlobalRef(javaConnectorClass);
		env->DeleteGlobalRef(loggerWrapperClass);
		env->DeleteGlobalRef(callbackWrapperClass);
		env->DeleteGlobalRef(functionModelClass);
		env->DeleteGlobalRef(iDomVariableClass);
		env->DeleteGlobalRef(domVariable);
		env->DeleteGlobalRef(domArray);
		env->DeleteGlobalRef(timeSpecClass);
		env->DeleteGlobalRef(timestampClass);
		env->DeleteGlobalRef(bigDecimalClass);
		env->DeleteGlobalRef(iteratorClass);

		//jvm->DetachCurrentThread();

		jvm->DestroyJavaVM();


		//vmi.DestroyJavaVM();
		this->enabled = false;
	}
}


void JavaFunctionManager::registerNatives(JNIEnv *env){
	JNINativeMethod native_method = {(char*)"getHome", (char*)"()Ljava/lang/String;", (void*)JavaFunctionManager::AlinousSystemWrappergetHome};
	env->RegisterNatives(alinousCoreClass, &native_method, 1);


	native_method = {(char*)"logError", (char*)"(Ljava/lang/Throwable;)V", (void*)(JavaFunctionManager::LoggerWrapperlogError)};
	env->RegisterNatives(loggerWrapperClass, &native_method, 1);

	native_method = {(char*)"logWarning", (char*)"(Ljava/lang/String;)V", (void*)(JavaFunctionManager::LoggerWrapperlogWarning)};
	env->RegisterNatives(loggerWrapperClass, &native_method, 1);

	native_method = {(char*)"logInfo", (char*)"(Ljava/lang/String;)V", (void*)(JavaFunctionManager::LoggerWrapperlogInfo)};
	env->RegisterNatives(loggerWrapperClass, &native_method, 1);


	native_method = {(char*)"callback", (char*)"(Ljava/lang/String;[Ljava/lang/Object;Ljava/lang/Class;)Ljava/lang/Object;", (void*)(JavaFunctionManager::CallbackWrappercallback)};
	env->RegisterNatives(callbackWrapperClass, &native_method, 1);
}

jobject JavaFunctionManager::CallbackWrappercallback(JNIEnv* env, jstring jstr, jobjectArray params, jobject clazz){
	return nullptr;
}


void JavaFunctionManager::LoggerWrapperlogError(JNIEnv* env, jobject obj, jobject jthrowable){
	jmethodID setptr_method = env->GetMethodID(JavaFunctionManager::loggerWrapperClass, "getPtr", "()J");
	jlong jptr = env->CallLongMethod(obj, setptr_method);

	JavaFunctionManager* _this = (JavaFunctionManager*)jptr;

	ThLogParam param;
	param._this = _this;
	param.obj = obj;
	param.jstr = nullptr;
	param.jthrowable = jthrowable;
	param.env = env;

	class LoggerWrapperlogErrorReq :public JNICallBack {
	public:
		LoggerWrapperlogErrorReq(ThLogParam* param) : param(param) {
		}

		virtual void execute(){
			ThreadContext *ctx = ThreadContext::newThreadContext();

			JNIEnv *env = param->env;
			{
				GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JavaFunctionManager", L"LoggerWrapperlogInfo");
				AlinousCore* core = param->_this->core;

				jclass throableCls = env->FindClass("java/lang/Throwable");
				jmethodID getMessageId = env->GetMethodID(throableCls, "getMessage","()Ljava/lang/String;");
				jstring jstr = (jstring)env->CallObjectMethod(param->jthrowable, getMessageId);
				jboolean isCopy;

				const char* msg = env->GetStringUTFChars(jstr, &isCopy);

				UnicodeString* errorMessage = new UnicodeString(msg, ctx);
				Throwable* e = new Throwable(errorMessage, ctx);
				core->getLogger(ctx)->logError(e, ctx);

				env->ReleaseStringUTFChars(param->jstr, msg);
				//env->DeleteLocalRef(param->jstr);
				//env->DeleteLocalRef(throableCls);
			}
		}

		ThLogParam* param;
	};


	LoggerWrapperlogErrorReq req(&param);
	_this->jniThread->request(&req);
}


void JavaFunctionManager:: LoggerWrapperlogWarning(JNIEnv* env, jobject obj, jstring jstr){
	jmethodID setptr_method = env->GetMethodID(JavaFunctionManager::loggerWrapperClass, "getPtr", "()J");
	jlong jptr = env->CallLongMethod(obj, setptr_method);

	JavaFunctionManager* _this = (JavaFunctionManager*)jptr;

	ThLogParam param;
	param._this = _this;
	param.obj = obj;
	param.jstr = jstr;
	param.jthrowable = nullptr;
	param.env = env;


	class LoggerWrapperlogWarningReq :public JNICallBack {
	public:
		LoggerWrapperlogWarningReq(ThLogParam* param) : param(param) {
		}

		virtual void execute(){
			ThreadContext *ctx = ThreadContext::newThreadContext();

			JNIEnv *env = param->env;
			{
				GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JavaFunctionManager", L"LoggerWrapperlogInfo");
				AlinousCore* core = param->_this->core;

				jboolean b = false;
				const char* msg = env->GetStringUTFChars(param->jstr, &b);
				UnicodeString* unimsg =new UnicodeString(msg, ctx);

				env->ReleaseStringUTFChars(param->jstr, msg);
				//env->DeleteLocalRef(param->jstr);

				core->getLogger(ctx)->logWarning(unimsg, ctx);
			}
		}

		ThLogParam* param;
	};

	LoggerWrapperlogWarningReq req(&param);
	_this->jniThread->request(&req);
}


void JavaFunctionManager::LoggerWrapperlogInfo(JNIEnv* env, jobject obj, jstring jstr){
	jmethodID setptr_method = env->GetMethodID(JavaFunctionManager::loggerWrapperClass, "getPtr", "()J");
	jlong jptr = env->CallLongMethod(obj, setptr_method);


	JavaFunctionManager* _this = (JavaFunctionManager*)jptr;

	ThLogParam param;
	param._this = _this;
	param.obj = obj;
	param.jstr = jstr;
	param.jthrowable = nullptr;
	param.env = env;

	class LoggerWrapperlogInfoReq :public JNICallBack {
	public:
		LoggerWrapperlogInfoReq(ThLogParam* param) : param(param) {
		}

		virtual void execute(){
			ThreadContext *ctx = ThreadContext::newThreadContext();

			JNIEnv *env = param->env;
			{
				GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JavaFunctionManager", L"__LoggerWrapperlogWarning");

				AlinousCore* core = param->_this->core;

				jboolean b = false;
				const char* msg = env->GetStringUTFChars(param->jstr, &b);
				UnicodeString* unimsg =new UnicodeString(msg, ctx);
				//env->DeleteLocalRef(param->jstr);
				env->ReleaseStringUTFChars(param->jstr, msg);


				core->getLogger(ctx)->logInfo(unimsg, ctx);
			}
		}

		ThLogParam* param;
	};

	LoggerWrapperlogInfoReq req(&param);
	_this->jniThread->request(&req);
}



jstring JavaFunctionManager::AlinousSystemWrappergetHome(JNIEnv* env, jobject obj){
	jmethodID setptr_method = env->GetMethodID(JavaFunctionManager::alinousCoreClass, "getPtr", "()J");
	jlong jptr = env->CallLongMethod(obj, setptr_method);

	JavaFunctionManager* _this = (JavaFunctionManager*)jptr;

	ThLogParam param;
	param._this = _this;
	param.obj = nullptr;
	param.jstr = nullptr;
	param.jthrowable = nullptr;
	param.env = env;


	class AlinousSystemWrappergetHomeReq :public JNICallBack {
	public:
		AlinousSystemWrappergetHomeReq(ThLogParam* param) : param(param) {
		}

		virtual void execute(){
			ThreadContext *ctx = ThreadContext::newThreadContext();

			JNIEnv *env = param->env;
			{
				GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LoggerWrapperlogWarningReq", L"execute");

				AlinousCore* core = param->_this->core;

				char* homestr = core->getAlinousHome(ctx)->toCString(ctx);
				param->jstr = env->NewStringUTF(homestr);
				delete [] homestr;
			}
		}

		ThLogParam* param;
	};


	AlinousSystemWrappergetHomeReq req(&param);
	_this->jniThread->request(&req);

	return param.jstr;
}


}}}


