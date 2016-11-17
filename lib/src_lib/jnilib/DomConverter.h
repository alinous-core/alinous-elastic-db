/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef JNILIB_DOMCONVERTER_H_
#define JNILIB_DOMCONVERTER_H_


namespace alinous{ namespace jdk{ namespace functions{
class JavaFunctionManager;
}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;
}}}
namespace alinous {namespace runtime {namespace dom {
class DomVariable;
}}}
namespace alinous {namespace runtime {namespace dom {
class DomArray;
}}}
namespace alinous {namespace runtime {namespace variant {
class VariantValue;
}}}
namespace alinous {namespace numeric {
class TimeOnlyTimestamp;
}}
namespace java {namespace sql {
class Timestamp;
}}
namespace alinous {namespace numeric {
class BigDecimal;
}}

namespace alinous{ namespace jdk{ namespace functions{

using ::alinous::jdk::functions::JavaFunctionManager;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::DomArray;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::numeric::TimeOnlyTimestamp;
using ::java::sql::Timestamp;
using ::alinous::numeric::BigDecimal;

class DomJDomConverter {
public:
    inline void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }
    inline void* operator new(size_t size, MemoryInterface* ctx) throw() {
    	return ctx->alloc->allocate(size);
    }
    inline void operator delete(void* p, size_t size) throw() {
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }

	IDomVariable* j2n(JNIEnv *env, jobject jdom, ThreadContext* ctx) throw() ;
	DomVariable* jdom2dom(JNIEnv *env, jobject jdom, ThreadContext* ctx) throw() ;
	DomArray* jdomArray2domArray(JNIEnv *env, jobject jdomarray, ThreadContext* ctx) throw() ;

	jobject n2j(JNIEnv *env, IDomVariable* dom, ThreadContext* ctx) throw() ;
	jobject ndomy2j(JNIEnv *env, DomVariable* dom, ThreadContext* ctx) throw() ;
	jobject narray2j(JNIEnv *env, DomArray* domArray, ThreadContext* ctx) throw() ;

	DomJDomConverter(JNIEnv *env) throw() ;
	~DomJDomConverter() throw() {
	}
private:
	jmethodID domStringInit;
	jmethodID domByteInit;
	jmethodID domShortInit;
	jmethodID domCharInit;
	jmethodID domIntInit;
	jmethodID domLongInit;
	jmethodID domDoubleInit;
	jmethodID domFloatInit;
	jmethodID domTimestampInit;
	jmethodID domTimeSpecInit;
	jmethodID domBigDecimalInit;

	jmethodID domGetDomType;
	jmethodID domGetValueType;

	jmethodID domGetStringValue;

	jmethodID domGetProperty;
	jmethodID domSetProperty;
	jmethodID domGetPropertiesIterator;

	jmethodID arInit;
	jmethodID arSize;
	jmethodID arPut;
	jmethodID arGut;

	jmethodID bigDecimalInit;

	jmethodID timeSpecInit;
	jmethodID timestampInit;

	jmethodID itHasNext;
	jmethodID itNext;
};

}}}


#endif /* JNILIB_DOMCONVERTER_H_ */
