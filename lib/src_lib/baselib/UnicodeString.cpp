/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"

#include "org.alinous.charset/CharsetManager.h"
#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"

#include "java.lang/Boolean.h"
#include "java.lang/Comparable.h"
#include "java.lang/Number.h"
#include "java.lang/Double.h"
#include "java.lang/Integer.h"
#include "java.lang/Byte.h"
#include "java.lang/Long.h"
#include "java.lang/Float.h"
#include "java.lang/Short.h"

#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"

#ifndef BASELIB_UNICODESTRING_CPP_
#define BASELIB_UNICODESTRING_CPP_

namespace alinous {

UnicodeStringEncodeCache* UnicodeStringEncodeCache::instance = UnicodeStringEncodeCache::getInstance(nullptr);
bool UnicodeStringEncodeCache::pg_end = false;
}

namespace java { namespace lang {

CharsetConverter* UnicodeString::utfConverter = nullptr;


void UnicodeString::initBuffer(const wchar_t* str, ThreadContext* ctx){
	if(this->buff == nullptr){
		this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(32, ctx);

		const wchar_t* ptr = str;
		while(*ptr != 0){
			wchar_t ch = *ptr;
			this->append(ch, ctx);
			ptr++;
		}

	}
}

UnicodeString* UnicodeString::clone(ThreadContext* ctx) {
	UnicodeString* cloned =  new(ctx) UnicodeString(this, ctx);
	return cloned;
}

UnicodeString* UnicodeString::clone() {
	UnicodeString* cloned =  new UnicodeString(this, nullptr);
	return cloned;
}

UnicodeString::UnicodeString(int cap, ThreadContext* ctx) : CharSequence(ctx){
	if(cap == 0){
		cap = 8;
	}
	this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(cap, ctx);
}

UnicodeString::UnicodeString(ThreadContext* ctx) : CharSequence(ctx){
	this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(32, ctx);
}

UnicodeString::UnicodeString(const wchar_t* str, ThreadContext* ctx) : CharSequence(ctx)
{
	this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(32, ctx);

	const wchar_t* ptr = str;
	while(*ptr != 0){
		wchar_t ch = *ptr;
		this->append(ch, ctx);
		ptr++;
	}
}

UnicodeString::UnicodeString(const wchar_t* str) : CharSequence(nullptr)
{
	this->buff =  new RawArrayPrimitive<wchar_t>(32);

	const wchar_t* ptr = str;
	while(*ptr != 0){
		wchar_t ch = *ptr;
		this->append(ch, nullptr);
		ptr++;
	}
}


UnicodeString::UnicodeString(IArrayObjectPrimitive<wchar_t>* buffer, int offset, int count, ThreadContext* ctx) : CharSequence(ctx)
{
	this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(32, ctx);

	const int max = count;
	for(int i = 0; i != max; ++i){
		append(buffer->get(i + offset), ctx);
	}
}

UnicodeString::UnicodeString(const wchar_t* str, int offset, int count, ThreadContext* ctx) : CharSequence(ctx)
{
	this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(32, ctx);
	const int max = count;
	for(int i = 0; i != max; ++i){
		append(str[i + offset], ctx);
	}
}

UnicodeString::UnicodeString(IArrayObjectPrimitive<wchar_t>* buffer, ThreadContext* ctx) : CharSequence(ctx)
{
	this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(32, ctx);

	const int length = buffer->length;
	for(int i = 0; i != length; i++){
		append(buffer->get(i), ctx);
	}
}

UnicodeString::UnicodeString(const char* str, ThreadContext* ctx) : CharSequence(ctx)
{
	int len = strlen(str);
	importCStr(str, 0, len, ctx);
}

UnicodeString::UnicodeString(const char* str, int start, int count, ThreadContext* ctx) : CharSequence(ctx)
{
	importCStr(str, start, count, ctx);
}

UnicodeString::UnicodeString(IArrayObjectPrimitive<char>* str, int start, int count, ThreadContext* ctx)
{
	const char* ptr = str->raw->root;
	importCStr(ptr, start, count, ctx);
}

UnicodeString::UnicodeString(const char* str) : CharSequence(0) {
	int len = strlen(str);
	importCStr(str, 0, len, nullptr);
}


UnicodeString::UnicodeString(IArrayObjectPrimitive<char>* buffer, UnicodeString* encode, ThreadContext* ctx) : CharSequence(ctx) {
	org::alinous::charset::CharsetManager* mgr = org::alinous::charset::CharsetManager::getInstance(ctx);
	CharsetConverter* cnv = mgr->getConverter(encode, ctx);

	int len = buffer->length;

	ByteBuffer* in = new(ctx) ByteBuffer(buffer->raw->root, len, ctx);
	CharBuffer* out = new(ctx) CharBuffer(len, ctx);

	CharsetDecoder* decoder = cnv->newDecoder(ctx);
	decoder->decodeLoop(in ,out, ctx);

	this->buff = out->move(ctx);

}

UnicodeString::UnicodeString(IArrayObjectPrimitive<char>* buffer, int offset, int count, UnicodeString* encode, ThreadContext* ctx) : CharSequence(ctx) {
	org::alinous::charset::CharsetManager* mgr = org::alinous::charset::CharsetManager::getInstance(ctx);
	CharsetConverter* cnv = mgr->getConverter(encode, ctx);

	int len = count;

	ByteBuffer* in = new(ctx) ByteBuffer(buffer->raw->root + offset, len, ctx);
	CharBuffer* out = new(ctx) CharBuffer(len, ctx);

	CharsetDecoder* decoder = cnv->newDecoder(ctx);
	decoder->decodeLoop(in ,out, ctx);

	this->buff = out->move(ctx);
}


UnicodeString::UnicodeString(const UnicodeString *ptr, ThreadContext* ctx) : CharSequence(ctx)
{
	int cap = ptr->length(ctx);
	cap = cap < 8 ? 8 : cap;

	this->buff =  new(ctx) RawArrayPrimitive<wchar_t>(cap, ctx);

	const int maxLoop = ptr->buff->size();
	const RawArrayPrimitive<wchar_t>* _buff = ptr->buff;
	for(int i = 0; i != maxLoop; ++i){
		wchar_t ch = _buff->get(i);
		this->append(ch, ctx);
	}
}


void UnicodeString::importCStr(const char* str, int start, int len, ThreadContext* ctx)
{
	clearCache(ctx);


	//int len = strlen(str);

	const char* ptr = str + start;

	ByteBuffer* in = new(ctx) ByteBuffer(ptr, len, ctx);
	CharBuffer* out = new(ctx) CharBuffer(len, ctx);

	if(utfConverter == nullptr){
		org::alinous::charset::CharsetManager* mgr = org::alinous::charset::CharsetManager::getInstance(ctx);
		utfConverter = __GC_INS(nullptr, mgr->getConverter(new String(L"utf-8", ctx), ctx), CharsetConverter);
	}

	CharsetDecoder* decoder = utfConverter->newDecoder(ctx);
	decoder->decodeLoop(in ,out, ctx);

	this->buff = out->move(ctx);
}

UnicodeString::~UnicodeString(){
	ThreadContext* ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}



void UnicodeString::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->buff != nullptr){
		delete this->buff;
		this->buff = nullptr;
	}

}

UnicodeString* UnicodeString::toLowerCase(ThreadContext* ctx)
{
	UnicodeString*  newStr =  new(ctx) UnicodeString(ctx);

	const int size = this->buff->size();
	for(int i = 0; i != size; ++i){
		wchar_t newCh = towlower(this->buff->get(i));

		newStr->append(newCh, ctx);
	}

	return newStr;
}

UnicodeString* UnicodeString::toUpperCase(ThreadContext* ctx)
{
	UnicodeString* newStr =  new(ctx) UnicodeString(ctx);

	const int size = this->buff->size();
	for(int i = 0; i < size; i++){
		wchar_t newCh = towupper(this->buff->get(i));

		newStr->append(newCh, ctx);
	}

	return newStr;
}

UnicodeString* UnicodeString::substring(int begin, ThreadContext* ctx)
{
	return substring(begin, length(ctx), ctx);
}
UnicodeString* UnicodeString::substring(int begin, int end, ThreadContext* ctx)
{
	UnicodeString* newStr =  new(ctx) UnicodeString(ctx);

	const wchar_t *str = towString();

	const int max = end;
	for(int i = begin; i != max; i++){
		newStr->append(str[i], ctx);
	}

	return newStr;
}
int UnicodeString::indexOf(UnicodeString* str, ThreadContext* ctx){
	return indexOf(str, 0, ctx);
}
int UnicodeString::indexOf(UnicodeString* str, int lastIndex, ThreadContext* ctx){
	wchar_t ch =str->charAt(0, ctx);
	int index = indexOf(ch, lastIndex, ctx);
	while(index >= 0){
		if(this->startsWith(str, index, ctx)){
			return index;
		}

		index++;
		if(this->length(ctx) <= index){
			return -1;
		}

		index = indexOf(ch, index, ctx);
	}

	return -1;
}
int UnicodeString::indexOf(wchar_t ch, ThreadContext* ctx){
	return indexOf(ch, 0, ctx);
}
int UnicodeString::indexOf(wchar_t ch, int lastIndex, ThreadContext* ctx){
	const int length = this->length(ctx);
	for(int i = lastIndex; i < length; i++){
		if(this->charAt(i, ctx) == ch){
			return i;
		}
	}

	return -1;
}
int UnicodeString::lastIndexOf(wchar_t ch, ThreadContext* ctx){
	return lastIndexOf(ch, length(ctx) - 1, ctx);
}
int UnicodeString::lastIndexOf(wchar_t ch, int lastIndex, ThreadContext* ctx){
	for (int i = lastIndex; i >= 0; i--) {
		if(this->charAt(i, ctx) == ch){
			return i;
		}
	}

	return -1;
}
int UnicodeString::lastIndexOf(UnicodeString* str, ThreadContext* ctx){
	return lastIndexOf(str, length(ctx), ctx);
}
int UnicodeString::lastIndexOf(UnicodeString* str, int lastIndex, ThreadContext* ctx){
	if(lastIndex > this->length(ctx)){
		lastIndex = this->length(ctx);
	}
	wchar_t ch = str->charAt(0, ctx);
	int index = lastIndexOf(ch, lastIndex, ctx);
	while(index >= 0){
		if(this->startsWith(str, index, ctx)){
			return index;
		}

		index--;
		if(index < 0){
			return -1;
		}

		index = indexOf(ch, index, ctx);
	}

	return -1;
}

UnicodeString* UnicodeString::insert(int position, wchar_t ch, ThreadContext* ctx) {
	clearCache(ctx);

	buff->addElement(ch ,position);
	return this;
}

UnicodeString* UnicodeString::insert(int dstOffset, CharSequence* str, ThreadContext* ctx){
	const int count = str->length(ctx);
	int position = dstOffset;
	for(int i = 0; i != count; ++i){
		insert(position++, str->charAt(i, ctx), ctx);
	}

	return this;
}

UnicodeString* UnicodeString::insert(int dstOffset, IArrayObjectPrimitive<wchar_t>* str, int offset, int count, ThreadContext* ctx){
	int position = dstOffset;
	for(int i = 0; i != count; ++i){
		insert(position++, str->get(i), ctx);
	}
	return this;
}

bool UnicodeString::regionMatches(bool ignoreCase, int toffset, UnicodeString* other, int ooffset, int len, ThreadContext* ctx)
{
	const int myMax = toffset + len;
	const int oMAx = ooffset + len;
	if(this->length(ctx) < myMax){
		return false;
	}
	if(other->length(ctx) < oMAx){
		return false;
	}

	if(ignoreCase){
		const int max = len;
		for(int i = 0; i < max; ++i){
			int mypos = i + toffset;
			int otherpos =i + ooffset;
			wchar_t my = this->charAt(mypos, ctx);
			wchar_t oth = other->charAt(otherpos, ctx);

			my = icu::u_tolower(my);
			oth = icu::u_tolower(oth);

			if(my != oth){
				return false;
			}
		}
	}
	else{
		for(int i = 0; i < len; i++){
			int mypos = i + toffset;
			int otherpos =i + ooffset;
			wchar_t my = this->charAt(mypos, ctx);
			wchar_t oth = other->charAt(otherpos, ctx);

			if(my != oth){
				return false;
			}
		}
	}

	return true;
}

UnicodeString* UnicodeString::trim(ThreadContext* ctx)
{
	UnicodeString *retStr =  new(ctx) UnicodeString(ctx);

	bool start = false;
	const int length = this->length(ctx);
	for(int i = 0; i != length; ++i){
		wchar_t ch = this->charAt(i, ctx);
		if(start){
			retStr->append(ch, ctx);
		}
		else{
			if(!icu::u_isWhitespace(ch)){
				retStr->append(ch, ctx);
				start = true;
			}
		}
	}

	int length2 = retStr->length(ctx) - 1;
	for(int i = length2; i >= 0; i--){
		wchar_t ch = retStr->charAt(i, ctx);
		if(ch <= 0x0020){
			retStr->deleteCharAt(i, ctx);
		}else{
			break;
		}
	}

	return retStr;
}

bool UnicodeString::startsWith(UnicodeString* str, ThreadContext* ctx)
{
	return startsWith(str, 0, ctx);
}
bool UnicodeString::startsWith(UnicodeString* str, int start, ThreadContext* ctx) {
	const int length = this->length(ctx);

	int pos = 0;
	wchar_t match;
	for(int i = start; i < length; i++){
		wchar_t ch = this->charAt(i, ctx);
		pos = getNextMatch(pos, str, &match, ctx);
		if(pos < 0){
			return true;
		}

		if(match != ch){
			return false;
		}
	}

	pos = getNextMatch(pos, str, &match, ctx);
	if(pos < 0){
		return true;
	}

	return false;

}

bool UnicodeString::endsWith(UnicodeString* str, ThreadContext* ctx){
	const int length = str->length(ctx);
	int pos = this->length(ctx) - 1;
	int posTarget = length - 1;

	for(int i = 0; i != length; ++i){
		if(this->charAt(pos--, ctx) != str->charAt(posTarget--, ctx)){
			return false;
		}
	}

	return true;
}

int UnicodeString::getNextMatch(int pos, UnicodeString* str, wchar_t* next, ThreadContext* ctx){
	if(str->length(ctx) <= pos){
		return -1;
	}

	*next = str->charAt(pos++, ctx);

	return pos;
}

UnicodeString* UnicodeString::replace(wchar_t last, wchar_t next, ThreadContext* ctx){
	UnicodeString *retStr =  new(ctx) UnicodeString(ctx);

	const int maxLoop = this->buff->numArray;
	for(int i = 0; i != maxLoop; ++i){
		wchar_t ch = this->buff->get(i);
		if(ch == last){
			retStr->append(next, ctx);
		}else{
			retStr->append(ch, ctx);
		}
	}

	return retStr;
}

UnicodeString* UnicodeString::valueOf(wchar_t ch, ThreadContext* ctx){
	wchar_t ar[2]{};
	ar[0] = ch;
	ar[1] = 0x0;
	return  new(ctx) UnicodeString(ar, ctx);
}

UnicodeString* UnicodeString::valueOf(IArrayObjectPrimitive<wchar_t>* buffer, int offset, int count, ThreadContext* ctx){
	UnicodeString* str =  new(ctx) UnicodeString(buffer, offset, count, ctx);
	return str;
}

UnicodeString* UnicodeString::valueOf(double value, ThreadContext* ctx){
	return Double::toString(value, ctx);
}
UnicodeString* UnicodeString::valueOf(float value, ThreadContext* ctx){
	return Float::toString(value, ctx);
}
UnicodeString* UnicodeString::valueOf(int value, ThreadContext* ctx){
	return Integer::toString(value, ctx);
}
UnicodeString* UnicodeString::valueOf(long long value, ThreadContext* ctx){
	return Long::toString(value, ctx);
}
UnicodeString* UnicodeString::valueOf(IObject* value, ThreadContext* ctx){
	if(value == nullptr){
		return new(ctx) UnicodeString(L"null", ctx);
	}
	return value->toString(ctx);
}


ArrayObjectPrimitive<wchar_t>* UnicodeString::toCharArray(ThreadContext* ctx){
	wchar_t *tmp = new wchar_t [buff->numArray + 1]{};

	FastCopy::copy(tmp, buff->root, buff->numArray * sizeof(wchar_t));

	ArrayObjectPrimitive<wchar_t>* array = new(ctx) ArrayObjectPrimitive<wchar_t>(tmp, buff->numArray, ctx);

	return array;
}

void UnicodeString::deleteCharAt(int pos, ThreadContext* ctx) {
	clearCache(ctx);
	_delete(pos, pos + 1, ctx);
	this->__hashCode = 0;
}

void UnicodeString::_delete(int pos, int end, ThreadContext* ctx) {
	this->buff->remove(pos, end - pos);
	this->__hashCode = 0;
}

int UnicodeString::length(ThreadContext* ctx) const { return this->buff->size(); }

int UnicodeString::isEmpty(ThreadContext* ctx) const {
	return this->buff->size() == 0;
}

wchar_t UnicodeString::get(int i, ThreadContext* ctx) const { return this->buff->get(i); };
bool UnicodeString::equals(UnicodeString* str, ThreadContext* ctx)
{
	int hash = str->hashCode(ctx);
	if(hash != this->hashCode(ctx)){
		return false;
	}

	const int size = str->length(ctx);
	if(size != this->length(ctx)){
		return false;
	}
	for(int i = 0; i < size; i++){
		wchar_t src = str->get(i, ctx);
		wchar_t dest = this->get(i, ctx);

		if(src != dest){
			return false;
		}
	}

	return true;
}

bool UnicodeString::equalsIgnoreCase(UnicodeString* str, ThreadContext* ctx){
	const int size = str->length(ctx);
	if(size != this->length(ctx)){
		return false;
	}

	for(int i = 0; i < size; i++){
		wchar_t src = icu::u_tolower(str->get(i, ctx));
		wchar_t dest = icu::u_tolower(this->get(i, ctx));

		if(src != dest){
			return false;
		}
	}

	return true;
}

bool UnicodeString::equals(IObject* obj, ThreadContext* ctx)
{
	UnicodeString* str = static_cast<UnicodeString*>(obj);
	if(str == nullptr){
		return false;
	}
	const wchar_t *string1 = towString();
	const wchar_t *string2 = str->towString();

	int result = wcscmp(string1, string2);

	return result == 0;
}


wchar_t UnicodeString::charAt(int index, ThreadContext* ctx) const
{
	return this->buff->get(index);
};

CharSequence* UnicodeString::subSequence(int start, int end, ThreadContext* ctx) {
	UnicodeString* str =  new(ctx) UnicodeString(end - start, ctx);

	const int max = end;
	for(int i = start; i != max; ++i){
		str->append(this->buff->get(i), ctx);
	}
	return str;
}

UnicodeString* UnicodeString::toString(ThreadContext* ctx){
	UnicodeString* str =  new(ctx) UnicodeString(this, ctx);
	return str;
}


const wchar_t* UnicodeString::towString() const
{
	if(this->buff->currentSize == this->buff->numArray){
		this->buff->addElement(0);
		this->buff->remove(this->buff->numArray - 1);
	}else{
		//wchar_t lastCh = this->buff->get(this->buff->numArray);
		//if(lastCh != 0x0){
		//	this->buff->addElement(0);
		//	this->buff->remove(this->buff->numArray - 1);
		//}
		this->buff->addElement(0);
		this->buff->remove(this->buff->numArray - 1);
	}
	this->buff->root[this->buff->numArray] = L'\0';

	return this->buff->root;

/*
	wchar_t* ret = this->buff->root;

	int last = this->buff->numArray; //
	wchar_t lastCh = this->buff->get(last);
	if(lastCh != L'\0'){
		this->buff->addElement(L'\0');
		this->buff->remove(this->buff->numArray - 1);
	}

	return ret;*/

}


int UnicodeString::codePointAt(int index, ThreadContext* ctx) {
	return Character::codePointAt(this, index, ctx);
}

int UnicodeString::codePointCount(int beginIndex, int endIndex, ThreadContext* ctx) {
	return Character::codePointCount(this, beginIndex, endIndex, ctx);
}

UnicodeString* UnicodeString::appendCodePoint(int codePoint, ThreadContext* ctx){
	clearCache(ctx);

	ArrayObjectPrimitive<wchar_t>* chars = Character::toChars(codePoint, ctx);

	const int max = chars->length;
	for(int i = 0; i < max; i++){
		this->append(chars->get(i), ctx);
	}
	return this;
}

IArrayObject<UnicodeString>* UnicodeString::split(UnicodeString* regex, ThreadContext* ctx)
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UnicodeString", L"split");
	com::google::re2j::Pattern* p = __GC_INS(nullptr, com::google::re2j::Pattern::compile(regex, ctx), com::google::re2j::Pattern);
	__e_obj1.add(p,nullptr);

	IArrayObject<UnicodeString>* result = __GC_INS(nullptr, p->split(this, ctx), IArrayObject<UnicodeString>);
	__e_obj1.add(result,nullptr);

	return result;
}
IArrayObject<UnicodeString>* UnicodeString::split(UnicodeString* regex, int max, ThreadContext* ctx)
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UnicodeString", L"split");
	com::google::re2j::Pattern* p = __GC_INS(nullptr, com::google::re2j::Pattern::compile(regex, ctx), com::google::re2j::Pattern);

	IArrayObject<UnicodeString>* result = __GC_INS(nullptr, p->split(this, max, ctx), IArrayObject<UnicodeString>);
	__e_obj1.add(result,nullptr);

	return result;
}

UnicodeString* UnicodeString::replaceFirst(UnicodeString* regex, UnicodeString* replacement, ThreadContext* ctx){
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UnicodeString", L"split");
	com::google::re2j::Pattern* p = __GC_INS(nullptr, com::google::re2j::Pattern::compile(regex, ctx), com::google::re2j::Pattern);

	return p->matcher(this, ctx)->replaceFirst(replacement, ctx);
}

UnicodeString* UnicodeString::replaceAll(UnicodeString* regex, UnicodeString* replacement, ThreadContext* ctx)
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UnicodeString", L"split");
	com::google::re2j::Pattern* p = __GC_INS(nullptr, com::google::re2j::Pattern::compile(regex, ctx), com::google::re2j::Pattern);

	return p->matcher(this, ctx)->replaceAll(replacement, ctx);
}


char* UnicodeString::toCString(ThreadContext* ctx)
{
	CharBuffer* in = new(ctx) CharBuffer(this->towString(), this->length(ctx), ctx);
	ByteBuffer* out = new(ctx) ByteBuffer(this->length(ctx) * 2 + 1, ctx);

	if(this->utfConverter == nullptr){
		org::alinous::charset::CharsetManager* mgr = org::alinous::charset::CharsetManager::getInstance(ctx);
		this->utfConverter = __GC_INS(nullptr, mgr->getConverter(new String(L"utf-8", ctx), ctx), CharsetConverter);
	}

	CharsetEncoder* encoder = this->utfConverter->newEncoder(ctx);
	encoder->encodeLoop(in ,out, ctx);

	int size = out->position(ctx) + 1;
	char* retBuff = new char[size];

	FastCopy::copy(retBuff, out->data->root, size);
	retBuff[size - 1] = '\0';

	return retBuff;
}

IArrayObjectPrimitive<char>* UnicodeString::getBytes(UnicodeString* charset, ThreadContext* ctx)
{
	ArrayObjectPrimitive<char>* bytes = nullptr;

	bytes = new(ctx) ArrayObjectPrimitive<char>(ctx);

	CharBuffer* in = new(ctx) CharBuffer(this->towString(), this->length(ctx), ctx);
	ByteBuffer* out = new(ctx) ByteBuffer(this->length(ctx) * 2 + 1, ctx);

	if(this->utfConverter == nullptr){
		org::alinous::charset::CharsetManager* mgr = org::alinous::charset::CharsetManager::getInstance(ctx);
		this->utfConverter = __GC_INS(nullptr, mgr->getConverter(new String(L"utf-8", ctx), ctx), CharsetConverter);
	}

	CharsetEncoder* encoder = this->utfConverter->newEncoder(ctx);
	encoder->encodeLoop(in ,out, ctx);


	const int max = out->position(ctx);
	out->position(0, ctx);
	for(int i = 0; i < max; i++){
		char ch = out->get(ctx);

		bytes->append(ch);
	}

	clearCache(ctx);


	return bytes;
}

int UnicodeString::compareTo(const CharSequence* const b, const ThreadContext* const ctx) {
	const wchar_t* astr = this->towString();
	const wchar_t* bstr = b->towString();

	int res = wcscmp(astr, bstr);

	return res;
}

void UnicodeString::getChars(int start, int end, IArrayObjectPrimitive<wchar_t>* buffer, int index, ThreadContext* ctx) const {
	const int maxLoop = end - start;
	for(int i = 0; i != maxLoop; ++i){
		wchar_t ch = this->buff->get(start + i);
		int pos = index + i;
		buffer->set(ch, pos, ctx);
	}
}

UnicodeString* UnicodeString::append(wchar_t ch, ThreadContext* ctx)
{
	clearCache(ctx);

	this->buff->addElement(ch);
	this->__hashCode = 0;

	return this;
}
UnicodeString* UnicodeString::append(CharSequence* str, ThreadContext* ctx)
{
	clearCache(ctx);

	int length = str->length(ctx);
	for(int i = 0; i < length; i++){
		wchar_t ch = str->charAt(i, ctx);
		this->buff->addElement(ch);
	}
	this->__hashCode = 0;
	return this;
}
UnicodeString* UnicodeString::append(IObject* str, ThreadContext* ctx)
{
	clearCache(ctx);

	this->__hashCode = 0;
	return append(str->toString(ctx), ctx);
}

UnicodeString* UnicodeString::append(UnicodeString* str, ThreadContext* ctx)
{
	clearCache(ctx);

	int length = str->length(ctx);
	for(int i = 0; i < length; i++){
		wchar_t ch = str->get(i ,ctx);
		this->buff->addElement(ch);
	}

	this->__hashCode = 0;
	return this;
}

UnicodeString* UnicodeString::append(IArrayObjectPrimitive<wchar_t>* str, ThreadContext* ctx)
{
	clearCache(ctx);

	append(str, 0, str->length, ctx);

	this->__hashCode = 0;
	return this;
}

UnicodeString* UnicodeString::append(IArrayObjectPrimitive<wchar_t>* str, int offset, int count, ThreadContext* ctx)
{
	clearCache(ctx);

	const int length = count;
	for(int i = 0; i != length; ++i){
		wchar_t ch = str->get(i + offset, ctx);
		this->buff->addElement(ch);
	}

	this->__hashCode = 0;
	return this;
}


UnicodeString* UnicodeString::append(int value, ThreadContext* ctx)
{
	clearCache(ctx);

	if(value < 0){
		value = value * -1;
		append(L'-', ctx);
	}

	wchar_t buf[64] = {};
	int offset = 0;
	while(value != 0){
		int d = value % 10;
		value /= 10;

		std::swprintf(&buf[offset], sizeof(buff), L"%lld", d);

		offset++;
	}

	for(int i = offset - 1; i >= 0; i--){
		append(buf[i], ctx);
	}

	this->__hashCode = 0;
	return this;
}
UnicodeString* UnicodeString::append(long value, ThreadContext* ctx)
{
	clearCache(ctx);

	if(value < 0){
		value = value * -1;
		append(L'-', ctx);
	}

	wchar_t buf[64] = {};
	int offset = 0;
	while(value != 0){
		int d = value % 10;
		value /= 10;

		std::swprintf(&buf[offset], sizeof(buff), L"%lld", d);

		offset++;
	}

	for(int i = offset - 1; i >= 0; i--){
		append(buf[i], ctx);
	}

	this->__hashCode = 0;
	return this;
}
UnicodeString* UnicodeString::append(long long value, ThreadContext* ctx)
{
	if(value < 0){
		value = value * -1;
		append(L'-', ctx);
	}

	wchar_t buf[64] = {};
	int offset = 0;
	while(value != 0){
		int d = value % 10;
		value /= 10;

		std::swprintf(&buf[offset], sizeof(buff), L"%lld", d);

		offset++;
	}

	for(int i = offset - 1; i >= 0; i--){
		append(buf[i], ctx);
	}

	this->__hashCode = 0;

	return this;
}

UnicodeString* UnicodeString::append(double value, ThreadContext* ctx) {
	UnicodeString* str = valueOf(value, ctx);
	append(str, ctx);

	this->__hashCode = 0;
	return this;
}

UnicodeString* UnicodeString::append(float value, ThreadContext* ctx) {
	UnicodeString* str = valueOf(value, ctx);
	append(str, ctx);

	this->__hashCode = 0;
	return this;
}

UnicodeString* UnicodeString::valueOf(bool value, ThreadContext* ctx){
	if(value){
		return  new(ctx) UnicodeString(L"true", ctx);
	}
	return  new(ctx) UnicodeString(L"false", ctx);

}

void UnicodeString::setLength(int newLength, ThreadContext* ctx){
	clearCache(ctx);

	this->__hashCode = 0;
	this->buff->numArray = newLength;
}

void UnicodeString::__cleanUp(ThreadContext* ctx){
	if(utfConverter != nullptr){
		__GC_DEC(nullptr, utfConverter, CharsetConverter);
	}
}

int UnicodeString::ValueCompare::operator () (const CharSequence* const a, const CharSequence* const b, const ThreadContext* const ctx) const {
	const wchar_t* astr = a->towString();
	const wchar_t* bstr = b->towString();

	int res = wcscmp(astr, bstr);

	return res;
}

StringBuilder::~StringBuilder(){
	ThreadContext* ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void StringBuilder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	UnicodeString::__releaseRegerences(prepare, ctx);
}

UnicodeString* StringBuilder::toString(ThreadContext* ctx){
	UnicodeString* str =  new(ctx) UnicodeString(this, ctx);
	return str;
}

StringBuffer::~StringBuffer(){
	ThreadContext* ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void StringBuffer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	UnicodeString::__releaseRegerences(prepare, ctx);
}

}}

#endif /* BASELIB_UNICODESTRING_CPP_ */
