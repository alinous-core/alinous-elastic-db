/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef JNILIB_JAVAFUNCTIONMANAGER_H_
#define JNILIB_JAVAFUNCTIONMANAGER_H_

namespace alinous {namespace system {
class AlinousCore;
}}

namespace java { namespace util{
template <typename T>
class ArrayList;
}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;
}}}
namespace alinous {namespace runtime {namespace dom {
class IDomVariable;
}}}

namespace alinous { namespace compile { namespace analyse {
class AlinousType;
}}}

namespace alinous{ namespace jdk{ namespace functions{

using namespace alinous::system;
using ::java::util::ArrayList;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::compile::analyse::AlinousType;

class JavaFunctionManager : public IObject {
public:
	JavaFunctionManager(AlinousCore* core, ThreadContext* ctx);
	virtual ~JavaFunctionManager() {
		ThreadContext *ctx = ThreadContext::getCurentContext();
		if(ctx != nullptr){ctx->incGcDenial();}
		__releaseRegerences(false, ctx);
		if(ctx != nullptr){ctx->decGcDenial();}
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	IAlinousVariable* invoke(UnicodeString* prefix, UnicodeString* name, ArrayList<IDomVariable>* arguments, ThreadContext* ctx);

	void init(ThreadContext* ctx);
	void dispose(ThreadContext* ctx);

	AlinousType* getFunctionReturnType(UnicodeString* prefix, UnicodeString* name, ThreadContext* ctx);
	bool isFunctionPrefix(UnicodeString* prefix, ThreadContext* ctx);
	bool isJavaFunction(UnicodeString* prefix, UnicodeString* funcName, ThreadContext* ctx);

	class ThLogParam{
	public:
		JavaFunctionManager* _this;
		jobject obj;
		jstring jstr;
		jobject jthrowable;
		const char* msg;
		JNIEnv* env;
	};

	static jstring AlinousSystemWrappergetHome(JNIEnv* env, jobject obj);
	static void LoggerWrapperlogError(JNIEnv* env, jobject obj, jobject jthrowable);
	static void LoggerWrapperlogWarning(JNIEnv* env, jobject obj, jstring jstr);
	static void LoggerWrapperlogInfo(JNIEnv* env, jobject obj, jstring jstr);

	static jobject CallbackWrappercallback(JNIEnv* env, jstring jstr, jobjectArray params, jobject clazz);

	// strong ref
	static jclass alinousCoreClass;
	static jclass javaConnectorClass;
	static jclass loggerWrapperClass;
	static jclass callbackWrapperClass;

	static jclass functionModelClass;
	static jclass iDomVariableClass;
	static jclass domVariable;
	static jclass domArray;

	static jclass timeSpecClass;
	static jclass timestampClass;
	static jclass bigDecimalClass;

	static jclass iteratorClass;
private:
	AlinousCore* core;
	JavaVM *jvm;
	JNIEnv jni;
	JavaVM vmi;
	JavaVMInitArgs vm_args;
	JavaVMOption options[4];
	bool enabled;

	jobject javaConnector;

	JNIThread* jniThread;

	void registerNatives(JNIEnv *env);

	bool initEnv(JNIEnv **env);

};


}}}


#endif /* JNILIB_JAVAFUNCTIONMANAGER_H_ */
