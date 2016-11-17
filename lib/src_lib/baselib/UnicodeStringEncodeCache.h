/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_UNICODESTRINGENCODECACHE_H_
#define BASELIB_UNICODESTRINGENCODECACHE_H_

namespace java { namespace lang {
class UnicodeString;
}}

namespace alinous {

using namespace java::lang;

class UnicodeStringEncodeCacheElement {
public:
	RawHashMap<UnicodeString, ArrayObjectPrimitive<char>> cache;
	UnicodeString* theKey;
	int count;
	UnicodeStringEncodeCacheElement(UnicodeString* key);
	virtual ~UnicodeStringEncodeCacheElement();
	ArrayObjectPrimitive<char>* get(UnicodeString* charset);
	void put(UnicodeString* charset, ArrayObjectPrimitive<char>* result);

	bool equals(UnicodeStringEncodeCacheElement* value, ThreadContext* ctx){return value == this;}
};

class UnicodeStringEncodeCache {
	RawHashMap<UnicodeString, UnicodeStringEncodeCacheElement>* cacheElements;

public:
	UnicodeStringEncodeCache();
	virtual ~UnicodeStringEncodeCache();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() ;
	void registerResult(UnicodeString* _this, UnicodeString* charset, ArrayObjectPrimitive<char>* result, ThreadContext* ctx);
	 ArrayObjectPrimitive<char>* getDecodedBytes(UnicodeString* _this, UnicodeString* charset, ThreadContext* ctx);
	 void release(UnicodeString* _this, ThreadContext* ctx);
public:

private:
	static UnicodeStringEncodeCache *instance;
	static bool pg_end;

public:
	static UnicodeStringEncodeCache* getInstance(ThreadContext* ctx);
	static void __cleanUp(ThreadContext* ctx);
};



}

#endif /* BASELIB_UNICODESTRINGENCODECACHE_H_ */
