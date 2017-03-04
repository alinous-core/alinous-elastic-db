/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"

namespace alinous {

UnicodeStringEncodeCacheElement::UnicodeStringEncodeCacheElement(UnicodeString* key) : cache() {
	count = 0;
	theKey = key;
}
UnicodeStringEncodeCacheElement::~UnicodeStringEncodeCacheElement() {
	cache.clear();
}

ArrayObjectPrimitive<char>* UnicodeStringEncodeCacheElement::get(UnicodeString* charset) {
	return cache.get(charset, nullptr);
}
void UnicodeStringEncodeCacheElement::put(UnicodeString* charset, ArrayObjectPrimitive<char>* result) {
	cache.put(charset, result);
}



UnicodeStringEncodeCache::UnicodeStringEncodeCache() {
	this->cacheElements = new RawHashMap<UnicodeString, UnicodeStringEncodeCacheElement>();
}

UnicodeStringEncodeCache::~UnicodeStringEncodeCache() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void UnicodeStringEncodeCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->cacheElements != nullptr){
		auto it = this->cacheElements->iterator();
		while(it.hasNext()){
			auto pair = it.next();

			UnicodeString* _this = pair->key;
			this->release(_this, ctx);
		}

		delete this->cacheElements;
		this->cacheElements = nullptr;
	}
}

void UnicodeStringEncodeCache::registerResult(UnicodeString* _this, UnicodeString* charset, ArrayObjectPrimitive<char>* result, ThreadContext* ctx){
	UnicodeStringEncodeCacheElement* element = this->cacheElements->get(_this, ctx);

	if(element == nullptr){
		element = new UnicodeStringEncodeCacheElement(_this);
		this->cacheElements->put(_this, element);

		__GC_INS(nullptr, _this, UnicodeString);

	}

	element->count++;

	auto pair = element->get(charset);
	if(pair == nullptr){
		__GC_INS(nullptr, charset, UnicodeString);
		__GC_INS(nullptr, result, ArrayObjectPrimitive<char>);

		element->put(charset, result);
	}
}

 ArrayObjectPrimitive<char>* UnicodeStringEncodeCache::getDecodedBytes(UnicodeString* _this, UnicodeString* charset, ThreadContext* ctx) {
	 UnicodeStringEncodeCacheElement* element = this->cacheElements->get(_this, ctx);

	 return element != nullptr ? element->get(charset) : nullptr;
 }

 void UnicodeStringEncodeCache::release(UnicodeString* _this, ThreadContext* ctx){
	 UnicodeStringEncodeCacheElement* element = this->cacheElements->get(_this, ctx);

	 if(element == nullptr){
		 return;
	 }

	 element->count--;
	 if(element->count > 0){
		 return;
	 }

	 auto it = element->cache.iterator();
	 while(it.hasNext()){
		 auto pair = it.next();

		 __GC_DEC(nullptr, pair->key, UnicodeString);
		 __GC_DEC(nullptr, pair->value, ArrayObjectPrimitive<char>);
	 }

	 this->cacheElements->remove(element->theKey);
	 __GC_DEC(nullptr, element->theKey, UnicodeString);

	 delete element;
 }


UnicodeStringEncodeCache* UnicodeStringEncodeCache::getInstance(ThreadContext* ctx){
	if(ctx == nullptr){
		ctx = ThreadContext::getCurentContext();
	}

	if(instance == nullptr && pg_end == false){
		instance = new UnicodeStringEncodeCache();
	}
	return instance;
}


void UnicodeStringEncodeCache::__cleanUp(ThreadContext* ctx){
	if(instance != nullptr){
		delete instance;
		instance = nullptr;
		pg_end = true;
	}

}

}

