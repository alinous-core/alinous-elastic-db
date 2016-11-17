/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_UNICODESTRINGWRAPPER_H_
#define BASELIB_UNICODESTRINGWRAPPER_H_

namespace alinous {

class UnicodeStringWrapper : public UnicodeString {
public:
	const StaticUnicodeString str;

	UnicodeStringWrapper() : UnicodeString(), str() {}
	UnicodeStringWrapper(const wchar_t* str, const int length);
	UnicodeStringWrapper(const StaticUnicodeString& str);

	//UnicodeStringWrapper(const UnicodeStringWrapper* ptr) : UnicodeString(ptr->str.buff, nullptr), str(ptr->str) {}
	//UnicodeStringWrapper(const wchar_t* str, int length): UnicodeString(str, nullptr), str(str, length) {}


	virtual ~UnicodeStringWrapper(){
		__releaseRegerences(false, nullptr);
	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw(){}


	virtual UnicodeString* clone(ThreadContext* ctx){
		UnicodeString* cloned = new(ctx) UnicodeString(str.buff, ctx);
		return cloned;
	}

	virtual int length(ThreadContext* ctx) const { return str.length(); }
	virtual wchar_t get(int i, ThreadContext* ctx) const { return str.charAt(i, ctx); };
	virtual wchar_t charAt(int index, ThreadContext* ctx) const {
		return get(index, ctx);
	};
	virtual const wchar_t* towString() const {
		return str.towString();
	}
	virtual CharSequence* subSequence(int start, int end, ThreadContext* ctx){
		UnicodeString* str = new(ctx) UnicodeString(end - start, ctx);

		for(int i = start; i < end; i++){
			str->append(get(i, ctx), ctx);
		}
		return str;
	}
	virtual UnicodeString* toString(ThreadContext* ctx){
		return new(ctx) UnicodeString(str.buff, ctx);
	}
	virtual ArrayObjectPrimitive<wchar_t>* toCharArray(ThreadContext* ctx){
		wchar_t *tmp = new wchar_t [str.length() + 1]{};

		FastCopy::copy(tmp, str.buff, str.length() * sizeof(wchar_t));

		ArrayObjectPrimitive<wchar_t>* array = new(ctx) ArrayObjectPrimitive<wchar_t>(tmp, str.length(), ctx);

		return array;
	}

	virtual bool equals(UnicodeString* str, ThreadContext* ctx){
		int size = str->length(ctx);
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
	virtual bool equalsIgnoreCase(UnicodeString* str, ThreadContext* ctx){
		int size = str->length(ctx);
		if(size != this->length(ctx)){
			return false;
		}

		for(int i = 0; i < size; i++){
			wchar_t src = towlower(str->get(i, ctx));
			wchar_t dest = towlower(this->get(i, ctx));

			if(src != dest){
				return false;
			}
		}

		return true;
	}
	virtual UnicodeString* substring(int begin, ThreadContext* ctx){
		initBuffer(this->str.buff, ctx);
		return substring(begin, length(ctx), ctx);
	}
	virtual UnicodeString* substring(int begin, int end, ThreadContext* ctx){
		initBuffer(this->str.buff, ctx);

		UnicodeString* cloned = clone(ctx);
		return cloned->substring(begin, end, ctx);
	}
	virtual bool startsWith(UnicodeString* str, ThreadContext* ctx){
		initBuffer(this->str.buff, ctx);

		return startsWith(str, 0, ctx);
	}
	virtual bool startsWith(UnicodeString* str, int start, ThreadContext* ctx){
		initBuffer(this->str.buff, ctx);

		int length = this->length(ctx);

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
	virtual UnicodeString* trim(ThreadContext* ctx){
		initBuffer(this->str.buff, ctx);

		UnicodeString *retStr = new(ctx) UnicodeString(ctx);

		bool start = false;
		int length = this->length(ctx);
		for(int i = 0; i < length; i++){
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

		length = retStr->length(ctx) - 1;
		for(int i = length; i >= 0; i--){
			wchar_t ch = retStr->charAt(i, ctx);
			if(ch <= 0x0020){
				retStr->deleteCharAt(i, ctx);
			}else{
				break;
			}
		}

		return retStr;
	}
	virtual UnicodeString* toLowerCase(ThreadContext* ctx){
		initBuffer(this->str.buff, ctx);

		UnicodeString* newStr = new(ctx) UnicodeString(ctx);

		int size = str.length();
		for(int i = 0; i < size; i++){
			wchar_t newCh = towlower(str.charAt(i, ctx));

			newStr->append(newCh, ctx);
		}

		return newStr;
	}
	virtual UnicodeString* toUpperCase(ThreadContext* ctx){
		initBuffer(this->str.buff, ctx);

		UnicodeString* newStr = new(ctx) UnicodeString(ctx);

		int size = str.length();
		for(int i = 0; i < size; i++){
			wchar_t newCh = towupper(str.charAt(i, ctx));

			newStr->append(newCh, ctx);
		}

		return newStr;
	}


	constexpr const static StaticUnicodeString __NULL_STR{L"", 0};

	static UnicodeStringWrapper* getNullStr(){
		static UnicodeStringWrapper  NULL_STR{__NULL_STR};
		return &NULL_STR;
	}

public:
	//constexpr static UnicodeStringWrapper* NULL_STR{&_NULL_STR};
};


} /* namespace alinous */

#endif /* BASELIB_UNICODESTRINGWRAPPER_H_ */
