/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_UNICODESTRING_H_
#define BASELIB_UNICODESTRING_H_

namespace org {namespace alinous {namespace charset {
class CharsetConverter;
}}}

namespace alinous {
template <typename T> class ArrayObject;
template <typename T, typename C> class RawArray;
class ThreadContext;
}

namespace java { namespace lang {

using namespace alinous;
using namespace org::alinous::charset;

class IObject;

class UnicodeString : public CharSequence {
public:
	UnicodeString() : CharSequence(), buff(nullptr)  {
	}
protected:
	void initBuffer(const wchar_t* str, ThreadContext* ctx);

public:
	UnicodeString(int cap, ThreadContext* ctx);
	UnicodeString(ThreadContext* ctx);
	UnicodeString(const UnicodeString *ptr, ThreadContext* ctx);
	UnicodeString* clone(ThreadContext* ctx);
	UnicodeString* clone();
	UnicodeString(const wchar_t* str, ThreadContext* ctx);
	UnicodeString(const wchar_t* str);
	void importCStr(const char* str, int start, int len, ThreadContext* ctx);

	UnicodeString(IArrayObjectPrimitive<wchar_t>* buffer, int offset, int count, ThreadContext* ctx);
	UnicodeString(const wchar_t* str, int offset, int count, ThreadContext* ctx);
	UnicodeString(IArrayObjectPrimitive<wchar_t>* buffer, ThreadContext* ctx);

	UnicodeString(const char* str, ThreadContext* ctx);
	UnicodeString(const char* str, int start, int count, ThreadContext* ctx);
	UnicodeString(IArrayObjectPrimitive<char>* str, int start, int count, ThreadContext* ctx);
	//UnicodeString(char* str, ThreadContext* ctx);
	UnicodeString(const char* str);

	UnicodeString(IArrayObjectPrimitive<char>* buffer, UnicodeString* encode, ThreadContext* ctx);
	UnicodeString(IArrayObjectPrimitive<char>* buffer, int offset, int count, UnicodeString* encode, ThreadContext* ctx);

	virtual ~UnicodeString();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() ;

public:
	UnicodeString* toLowerCase(ThreadContext* ctx);
	UnicodeString* toUpperCase(ThreadContext* ctx);
	UnicodeString* substring(int begin, ThreadContext* ctx);
	UnicodeString* substring(int begin, int end, ThreadContext* ctx);
	int indexOf(UnicodeString* str, ThreadContext* ctx);
	int indexOf(UnicodeString* str, int lastIndex, ThreadContext* ctx);
	int indexOf(wchar_t ch, ThreadContext* ctx);
	int indexOf(wchar_t ch, int lastIndex, ThreadContext* ctx);
	int lastIndexOf(wchar_t ch, ThreadContext* ctx);
	int lastIndexOf(wchar_t ch, int lastIndex, ThreadContext* ctx);
	int lastIndexOf(UnicodeString* str, ThreadContext* ctx);
	int lastIndexOf(UnicodeString* str, int lastIndex, ThreadContext* ctx);
	UnicodeString* insert(int position, wchar_t ch, ThreadContext* ctx);
	UnicodeString* insert(int dstOffset, CharSequence* str, ThreadContext* ctx);
	UnicodeString* insert(int dstOffset, IArrayObjectPrimitive<wchar_t>* str, int offset, int count, ThreadContext* ctx);
	bool regionMatches(bool ignoreCase, int toffset, UnicodeString* other, int ooffset, int len, ThreadContext* ctx);
	UnicodeString* trim(ThreadContext* ctx);
	bool startsWith(UnicodeString* str, ThreadContext* ctx);
	bool startsWith(UnicodeString* str, int start, ThreadContext* ctx);
	bool endsWith(UnicodeString* str, ThreadContext* ctx);
	int getNextMatch(int pos, UnicodeString* str, wchar_t* next, ThreadContext* ctx);
	UnicodeString* replace(wchar_t last, wchar_t next, ThreadContext* ctx);
	UnicodeString* replaceFirst(UnicodeString* regex, UnicodeString* replacement, ThreadContext* ctx);
	UnicodeString* replaceAll(UnicodeString* expr, UnicodeString* replacement, ThreadContext* ctx);

	IArrayObject<UnicodeString>* split(UnicodeString* regex, ThreadContext* ctx);
	IArrayObject<UnicodeString>* split(UnicodeString* regex, int max, ThreadContext* ctx);

	ArrayObjectPrimitive<wchar_t>* toCharArray(ThreadContext* ctx);
	void deleteCharAt(int pos, ThreadContext* ctx);
	void _delete(int pos, int end, ThreadContext* ctx);
	int length(ThreadContext* ctx) const;
	int isEmpty(ThreadContext* ctx) const ;
	wchar_t get(int i, ThreadContext* ctx) const;
	bool equals(UnicodeString* str, ThreadContext* ctx);
	bool equalsIgnoreCase(UnicodeString* str, ThreadContext* ctx);
	bool equals(IObject* obj, ThreadContext* ctx);
	wchar_t charAt(int index, ThreadContext* ctx) const;
	int codePointAt(int index, ThreadContext* ctx);

    int codePointCount(int beginIndex, int endIndex, ThreadContext* ctx);

	CharSequence* subSequence(int start, int end, ThreadContext* ctx);
	IArrayObjectPrimitive<char>* getBytes(UnicodeString* charset, ThreadContext* ctx);

	virtual UnicodeString* toString(ThreadContext* ctx);
	const wchar_t* towString() const;
	char* toCString(ThreadContext* ctx);

public:

	static UnicodeString* valueOf(wchar_t ch, ThreadContext* ctx);
	static UnicodeString* valueOf(IArrayObjectPrimitive<wchar_t>* buffer, int offset, int count, ThreadContext* ctx);
	static UnicodeString* valueOf(double value, ThreadContext* ctx);
	static UnicodeString* valueOf(float value, ThreadContext* ctx);
	static UnicodeString* valueOf(int value, ThreadContext* ctx);
	static UnicodeString* valueOf(long long value, ThreadContext* ctx);
	static UnicodeString* valueOf(IObject* value, ThreadContext* ctx);
protected:
	RawArrayPrimitive<wchar_t>* buff;
	static CharsetConverter* utfConverter;

public:
	void clearCache(ThreadContext* ctx){
	}

public:
	UnicodeString* append(wchar_t ch, ThreadContext* ctx);
	UnicodeString* append(CharSequence* str, ThreadContext* ctx);
	UnicodeString* append(IObject* str, ThreadContext* ctx);
	UnicodeString* append(UnicodeString* str, ThreadContext* ctx);
	UnicodeString* append(IArrayObjectPrimitive<wchar_t>* str, ThreadContext* ctx);
	UnicodeString* append(IArrayObjectPrimitive<wchar_t>* str, int offset, int count, ThreadContext* ctx);
	UnicodeString* append(int value, ThreadContext* ctx);
	UnicodeString* append(long value, ThreadContext* ctx);
	UnicodeString* append(long long value, ThreadContext* ctx);
	UnicodeString* append(double value, ThreadContext* ctx);
	UnicodeString* append(float value, ThreadContext* ctx);
	static UnicodeString* valueOf(bool value, ThreadContext* ctx);
	UnicodeString* appendCodePoint(int codePoint, ThreadContext* ctx);
	void setLength(int newLength, ThreadContext* ctx);

public:
	static void __cleanUp(ThreadContext* ctx);
public:
	class ValueCompare {
	public:
		int operator () (const CharSequence* const a, const CharSequence* const b, const ThreadContext* const ctx) const;
	};

	int compareTo(const CharSequence* const b, const ThreadContext* const ctx);
    void getChars(int start, int end, IArrayObjectPrimitive<wchar_t>* buffer, int index, ThreadContext* ctx) const;
};

#define String UnicodeString


class StringBuilder final : public UnicodeString {
public:
	StringBuilder(ThreadContext* ctx) : UnicodeString(ctx){
	}
	StringBuilder(int cap, ThreadContext* ctx) : UnicodeString(cap, ctx){
	}
	StringBuilder(UnicodeString *ptr, ThreadContext* ctx) : UnicodeString(ptr, ctx)
	{
	}

	virtual ~StringBuilder();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	virtual UnicodeString* toString(ThreadContext* ctx);
};

class StringBuffer final : public UnicodeString {
public:
	StringBuffer(ThreadContext* ctx) : UnicodeString(ctx){
	}
	StringBuffer(int cap, ThreadContext* ctx) : UnicodeString(cap, ctx){
	}
	StringBuffer(UnicodeString *ptr, ThreadContext* ctx) : UnicodeString(ptr, ctx)
	{
	}

	virtual ~StringBuffer();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
};



}} /* namespace alinous */

#endif /* BASELIB_UNICODESTRING_H_ */
