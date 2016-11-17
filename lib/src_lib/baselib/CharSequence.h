/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_CHARSEQUENCE_H_
#define BASELIB_CHARSEQUENCE_H_

namespace alinous {
class ThreadContext;
}

namespace java { namespace lang {

class IObject;

class CharSequence : public IObject {
public:
	CharSequence() throw();
	CharSequence(const CharSequence& base) = default;
	CharSequence(ThreadContext* ctx) throw() ;

	virtual wchar_t charAt(int index, ThreadContext* ctx) const = 0;
	virtual int length(ThreadContext* ctx) const = 0;
	virtual CharSequence* subSequence(int start, int end, ThreadContext* ctx) = 0;
	virtual UnicodeString* toString(ThreadContext* ctx) = 0;
	virtual const wchar_t* towString() const = 0;

	virtual int hashCode(ThreadContext* ctx){
	    if (this->__hashCode == 0) {
	    	const int count = length(ctx);
	        if (count == 0) {
	            return 0;
	        }
	        int hash = 0;
	        for (int i = 0; i < count; i++) {
	            hash = charAt(i, ctx) + ((hash << 5) - hash);
	        }
	        this->__hashCode = hash;
	    }
	    return this->__hashCode;
	}

protected:
	int __hashCode;

};


}} /* namespace alinous */



#endif /* BASELIB_CHARSEQUENCE_H_ */
