/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_STATICUNICODESTRING_H_
#define BASELIB_STATICUNICODESTRING_H_

namespace java { namespace lang {

class StaticUnicodeString  {
public:
	const wchar_t* buff;
	int _length;


	constexpr StaticUnicodeString() : buff(nullptr), _length(-1){};
	constexpr StaticUnicodeString(const wchar_t* str, int length) :  /*IObject(nullptr),CharSequence(),*/ buff(str), _length(length) {

	}
	constexpr StaticUnicodeString(const StaticUnicodeString& other)=default;

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx){
	}

	int length() const
	{
		return _length;
	}
	virtual wchar_t charAt(int index, ThreadContext* ctx) const {
		return buff[index];
	}

	virtual CharSequence* subSequence(int start, int end, ThreadContext* ctx);
	virtual UnicodeString* toString(ThreadContext* ctx){
		return new UnicodeString(this->buff, ctx);
	}

	const wchar_t* towString() const
	{
		return this->buff;
	}

public:

	class ValueCompare {
	public:
		int operator () (const CharSequence* const a, const CharSequence* const b, const ThreadContext* const ctx) const {
			const wchar_t* astr = a->towString();
			const wchar_t* bstr = b->towString();

			return wcscmp(astr, bstr);
		}
	};


};

}} /* namespace alinous */

#endif /* BASELIB_STATICUNICODESTRING_H_ */
