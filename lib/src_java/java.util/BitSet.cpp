#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/TimeZone.h"
#include "java.util/SimpleTimeZone.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZones.h"
#include "java.sql/Date.h"
#include "java.util/BitSet.h"
#include "java.util/Random.h"
#include "java.util/Arrays.h"

namespace java {namespace util {





constexpr const int BitSet::OFFSET;
constexpr const int BitSet::ELM_SIZE;
constexpr const int BitSet::RIGHT_BITS;
const StaticArrayObjectPrimitive<long long> BitSet::__TWO_N_ARRAY = {0x1L, 0x2L, 0x4L, 0x8L, 0x10L, 0x20L, 0x40L, 0x80L, 0x100L, 0x200L, 0x400L, 0x800L, 0x1000L, 0x2000L, 0x4000L, 0x8000L, 0x10000L, 0x20000L, 0x40000L, 0x80000L, 0x100000L, 0x200000L, 0x400000L, 0x800000L, 0x1000000L, 0x2000000L, 0x4000000L, 0x8000000L, 0x10000000L, 0x20000000L, 0x40000000L, 0x80000000L, 0x100000000L, 0x200000000L, 0x400000000L, 0x800000000L, 0x1000000000L, 0x2000000000L, 0x4000000000L, 0x8000000000L, 0x10000000000L, 0x20000000000L, 0x40000000000L, 0x80000000000L, 0x100000000000L, 0x200000000000L, 0x400000000000L, 0x800000000000L, 0x1000000000000L, 0x2000000000000L, 0x4000000000000L, 0x8000000000000L, 0x10000000000000L, 0x20000000000000L, 0x40000000000000L, 0x80000000000000L, 0x100000000000000L, 0x200000000000000L, 0x400000000000000L, 0x800000000000000L, 0x1000000000000000L, 0x2000000000000000L, 0x4000000000000000L, ((long long)0x8000000000000000L)};
IArrayObjectPrimitive<long long>* BitSet::TWO_N_ARRAY = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__TWO_N_ARRAY);
bool BitSet::__init_done = __init_static_variables();
bool BitSet::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BitSet", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BitSet::BitSet(ThreadContext* ctx) throw()  : IObject(ctx), Cloneable(ctx), bits(nullptr), _needClear(0), actualArrayLength(0), isLengthActual(0)
{
	__GC_MV(this, &(bits), ArrayAllocatorPrimitive<long long>::allocatep(ctx, 1), IArrayObjectPrimitive<long long>);
	actualArrayLength = 0;
	isLengthActual = true;
}
void BitSet::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(bits), ArrayAllocatorPrimitive<long long>::allocatep(ctx, 1), IArrayObjectPrimitive<long long>);
	actualArrayLength = 0;
	isLengthActual = true;
}
 BitSet::BitSet(int nbits, ThreadContext* ctx) throw()  : IObject(ctx), Cloneable(ctx), bits(nullptr), _needClear(0), actualArrayLength(0), isLengthActual(0)
{
	if(nbits < 0)
	{
		throw (new(ctx) NegativeArraySizeException(ctx));
	}
	__GC_MV(this, &(bits), ArrayAllocatorPrimitive<long long>::allocatep(ctx, (nbits >> OFFSET) + ((nbits & RIGHT_BITS) > 0 ? 1 : 0)), IArrayObjectPrimitive<long long>);
	actualArrayLength = 0;
	isLengthActual = true;
}
void BitSet::__construct_impl(int nbits, ThreadContext* ctx) throw() 
{
	if(nbits < 0)
	{
		throw (new(ctx) NegativeArraySizeException(ctx));
	}
	__GC_MV(this, &(bits), ArrayAllocatorPrimitive<long long>::allocatep(ctx, (nbits >> OFFSET) + ((nbits & RIGHT_BITS) > 0 ? 1 : 0)), IArrayObjectPrimitive<long long>);
	actualArrayLength = 0;
	isLengthActual = true;
}
 BitSet::BitSet(IArrayObjectPrimitive<long long>* bits, bool needClear, int actualArrayLength, bool isLengthActual, ThreadContext* ctx) throw()  : IObject(ctx), Cloneable(ctx), bits(nullptr), _needClear(0), actualArrayLength(0), isLengthActual(0)
{
	__GC_MV(this, &(this->bits), bits, IArrayObjectPrimitive<long long>);
	this->_needClear = needClear;
	this->actualArrayLength = actualArrayLength;
	this->isLengthActual = isLengthActual;
}
void BitSet::__construct_impl(IArrayObjectPrimitive<long long>* bits, bool needClear, int actualArrayLength, bool isLengthActual, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->bits), bits, IArrayObjectPrimitive<long long>);
	this->_needClear = needClear;
	this->actualArrayLength = actualArrayLength;
	this->isLengthActual = isLengthActual;
}
 BitSet::~BitSet() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BitSet::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BitSet", L"~BitSet");
	__e_obj1.add(this->bits, this);
	bits = nullptr;
	if(!prepare){
		return;
	}
}
IObject* BitSet::clone(ThreadContext* ctx)
{
	throw (new(ctx) CloneNotSupportedException(ctx));
}
bool BitSet::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if(this == dynamic_cast<BitSet*>(obj))
	{
		return true;
	}
	if((dynamic_cast<BitSet*>(obj) != 0))
	{
		IArrayObjectPrimitive<long long>* bsBits = (dynamic_cast<BitSet*>(obj))->bits;
		int length1 = this->actualArrayLength;int length2 = (dynamic_cast<BitSet*>(obj))->actualArrayLength;
		if(this->isLengthActual && (dynamic_cast<BitSet*>(obj))->isLengthActual && length1 != length2)
		{
			return false;
		}
		if(length1 <= length2)
		{
			for(int i = 0; i < length1; i ++ )
			{
				if(bits->get(i) != bsBits->get(i))
				{
					return false;
				}
			}
			for(int i = length1; i < length2; i ++ )
			{
				if(bsBits->get(i) != (long long)0)
				{
					return false;
				}
			}
		}
				else 
		{
			for(int i = 0; i < length2; i ++ )
			{
				if(bits->get(i) != bsBits->get(i))
				{
					return false;
				}
			}
			for(int i = length2; i < length1; i ++ )
			{
				if(bits->get(i) != (long long)0)
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
int BitSet::_hashCode(ThreadContext* ctx) throw() 
{
	long long x = 1234;
	for(int i = 0,  length = actualArrayLength; i < length; i ++ )
	{
		x = x ^ (bits->get(i) * (i + 1));
	}
	return ((int)((x >> 32) ^ x));
}
bool BitSet::get(int pos, ThreadContext* ctx) throw() 
{
	if(pos < 0)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	int arrayPos = pos >> OFFSET;
	if(arrayPos < actualArrayLength)
	{
		return (bits->get(arrayPos) & TWO_N_ARRAY->get(pos & RIGHT_BITS)) != (long long)0;
	}
	return false;
}
BitSet* BitSet::get(int pos1, int pos2, ThreadContext* ctx) throw() 
{
	if(pos1 < 0 || pos2 < 0 || pos2 < pos1)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	int last = actualArrayLength << OFFSET;
	if(pos1 >= last || pos1 == pos2)
	{
		return (new(ctx) BitSet(0, ctx));
	}
	if(pos2 > last)
	{
		pos2 = last;
	}
	int idx1 = pos1 >> OFFSET;
	int idx2 = (pos2 - 1) >> OFFSET;
	long long factor1 = (~0L) << (pos1 & RIGHT_BITS);
	long long factor2 = ((unsigned int)(~0L))>> (ELM_SIZE - (pos2 & RIGHT_BITS));
	if(idx1 == idx2)
	{
		long long result = ((unsigned long long)(bits->get(idx1) & (factor1 & factor2)))>> (pos1 % ELM_SIZE);
		if(result == (long long)0)
		{
			return (new(ctx) BitSet(0, ctx));
		}
		return (new(ctx) BitSet(((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({result}, ctx)), _needClear, 1, true, ctx));
	}
	IArrayObjectPrimitive<long long>* newbits = ArrayAllocatorPrimitive<long long>::allocatep(ctx, idx2 - idx1 + 1);
	newbits->set(bits->get(idx1) & factor1,0, ctx);
	newbits->set(bits->get(idx2) & factor2,newbits->length - 1, ctx);
	for(int i = 1; i < idx2 - idx1; i ++ )
	{
		newbits->set(bits->get(idx1 + i),i, ctx);
	}
	int numBitsToShift = pos1 & RIGHT_BITS;
	int actualLen = newbits->length;
	if(numBitsToShift != 0)
	{
		for(int i = 0; i < newbits->length; i ++ )
		{
			newbits->set(((unsigned long long)newbits->get(i))>> (numBitsToShift),i, ctx);
			if(i != newbits->length - 1)
			{
				newbits->set(newbits->get(i) | (newbits->get(i + 1) << (ELM_SIZE - (numBitsToShift))),i, ctx);
			}
			if(newbits->get(i) != (long long)0)
			{
				actualLen = i + 1;
			}
		}
	}
	return (new(ctx) BitSet(newbits, _needClear, actualLen, newbits->get(actualLen - 1) != (long long)0, ctx));
}
void BitSet::set(int pos, ThreadContext* ctx) throw() 
{
	if(pos < 0)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	int len = (pos >> OFFSET) + 1;
	if(len > bits->length)
	{
		growLength(len, ctx);
	}
	bits->set(bits->get(len - 1) | (TWO_N_ARRAY->get(pos & RIGHT_BITS)),len - 1, ctx);
	if(len > actualArrayLength)
	{
		actualArrayLength = len;
		isLengthActual = true;
	}
	needClear(ctx);
}
void BitSet::set(int pos, bool val, ThreadContext* ctx) throw() 
{
	if(val)
	{
		set(pos, ctx);
	}
		else 
	{
		clear(pos, ctx);
	}
}
void BitSet::set(int pos1, int pos2, ThreadContext* ctx) throw() 
{
	if(pos1 < 0 || pos2 < 0 || pos2 < pos1)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	if(pos1 == pos2)
	{
		return;
	}
	int len2 = ((pos2 - 1) >> OFFSET) + 1;
	if(len2 > bits->length)
	{
		growLength(len2, ctx);
	}
	int idx1 = pos1 >> OFFSET;
	int idx2 = (pos2 - 1) >> OFFSET;
	long long factor1 = (~0L) << (pos1 & RIGHT_BITS);
	long long factor2 = ((unsigned int)(~0L))>> (ELM_SIZE - (pos2 & RIGHT_BITS));
	if(idx1 == idx2)
	{
		bits->set(bits->get(idx1) | ((factor1 & factor2)),idx1, ctx);
	}
		else 
	{
		bits->set(bits->get(idx1) | (factor1),idx1, ctx);
		bits->set(bits->get(idx2) | (factor2),idx2, ctx);
		for(int i = idx1 + 1; i < idx2; i ++ )
		{
			bits->set(bits->get(i) | ((~0L)),i, ctx);
		}
	}
	if(idx2 + 1 > actualArrayLength)
	{
		actualArrayLength = idx2 + 1;
		isLengthActual = true;
	}
	needClear(ctx);
}
void BitSet::set(int pos1, int pos2, bool val, ThreadContext* ctx) throw() 
{
	if(val)
	{
		set(pos1, pos2, ctx);
	}
		else 
	{
		clear(pos1, pos2, ctx);
	}
}
void BitSet::clear(ThreadContext* ctx) throw() 
{
	if(_needClear)
	{
		for(int i = 0; i < bits->length; i ++ )
		{
			bits->set(0L,i, ctx);
		}
		actualArrayLength = 0;
		isLengthActual = true;
		_needClear = false;
	}
}
void BitSet::clear(int pos, ThreadContext* ctx) throw() 
{
	if(pos < 0)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	if(!_needClear)
	{
		return;
	}
	int arrayPos = pos >> OFFSET;
	if(arrayPos < actualArrayLength)
	{
		bits->set(bits->get(arrayPos) & (~(TWO_N_ARRAY->get(pos & RIGHT_BITS))),arrayPos, ctx);
		if(bits->get(actualArrayLength - 1) == (long long)0)
		{
			isLengthActual = false;
		}
	}
}
void BitSet::clear(int pos1, int pos2, ThreadContext* ctx) throw() 
{
	if(pos1 < 0 || pos2 < 0 || pos2 < pos1)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	if(!_needClear)
	{
		return;
	}
	int last = (actualArrayLength << OFFSET);
	if(pos1 >= last || pos1 == pos2)
	{
		return;
	}
	if(pos2 > last)
	{
		pos2 = last;
	}
	int idx1 = pos1 >> OFFSET;
	int idx2 = (pos2 - 1) >> OFFSET;
	long long factor1 = (~0L) << (pos1 & RIGHT_BITS);
	long long factor2 = ((unsigned int)(~0L))>> (ELM_SIZE - (pos2 & RIGHT_BITS));
	if(idx1 == idx2)
	{
		bits->set(bits->get(idx1) & (~(factor1 & factor2)),idx1, ctx);
	}
		else 
	{
		bits->set(bits->get(idx1) & (~factor1),idx1, ctx);
		bits->set(bits->get(idx2) & (~factor2),idx2, ctx);
		for(int i = idx1 + 1; i < idx2; i ++ )
		{
			bits->set(0L,i, ctx);
		}
	}
	if((actualArrayLength > 0) && (bits->get(actualArrayLength - 1) == (long long)0))
	{
		isLengthActual = false;
	}
}
void BitSet::flip(int pos, ThreadContext* ctx) throw() 
{
	if(pos < 0)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	int len = (pos >> OFFSET) + 1;
	if(len > bits->length)
	{
		growLength(len, ctx);
	}
	bits->set(bits->get(len - 1) ^ (TWO_N_ARRAY->get(pos & RIGHT_BITS)),len - 1, ctx);
	if(len > actualArrayLength)
	{
		actualArrayLength = len;
	}
	isLengthActual = !((actualArrayLength > 0) && (bits->get(actualArrayLength - 1) == (long long)0));
	needClear(ctx);
}
void BitSet::flip(int pos1, int pos2, ThreadContext* ctx) throw() 
{
	if(pos1 < 0 || pos2 < 0 || pos2 < pos1)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	if(pos1 == pos2)
	{
		return;
	}
	int len2 = ((pos2 - 1) >> OFFSET) + 1;
	if(len2 > bits->length)
	{
		growLength(len2, ctx);
	}
	int idx1 = pos1 >> OFFSET;
	int idx2 = (pos2 - 1) >> OFFSET;
	long long factor1 = (~0L) << (pos1 & RIGHT_BITS);
	long long factor2 = ((unsigned int)(~0L))>> (ELM_SIZE - (pos2 & RIGHT_BITS));
	if(idx1 == idx2)
	{
		bits->set(bits->get(idx1) ^ ((factor1 & factor2)),idx1, ctx);
	}
		else 
	{
		bits->set(bits->get(idx1) ^ (factor1),idx1, ctx);
		bits->set(bits->get(idx2) ^ (factor2),idx2, ctx);
		for(int i = idx1 + 1; i < idx2; i ++ )
		{
			bits->set(bits->get(i) ^ ((~0L)),i, ctx);
		}
	}
	if(len2 > actualArrayLength)
	{
		actualArrayLength = len2;
	}
	isLengthActual = !((actualArrayLength > 0) && (bits->get(actualArrayLength - 1) == (long long)0));
	needClear(ctx);
}
bool BitSet::intersects(BitSet* bs, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<long long>* bsBits = bs->bits;
	int length1 = actualArrayLength;int length2 = bs->actualArrayLength;
	if(length1 <= length2)
	{
		for(int i = 0; i < length1; i ++ )
		{
			if((bits->get(i) & bsBits->get(i)) != (long long)0L)
			{
				return true;
			}
		}
	}
		else 
	{
		for(int i = 0; i < length2; i ++ )
		{
			if((bits->get(i) & bsBits->get(i)) != (long long)0L)
			{
				return true;
			}
		}
	}
	return false;
}
void BitSet::_and(BitSet* bs, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<long long>* bsBits = bs->bits;
	if(!_needClear)
	{
		return;
	}
	int length1 = actualArrayLength;int length2 = bs->actualArrayLength;
	if(length1 <= length2)
	{
		for(int i = 0; i < length1; i ++ )
		{
			bits->set(bits->get(i) & (bsBits->get(i)),i, ctx);
		}
	}
		else 
	{
		for(int i = 0; i < length2; i ++ )
		{
			bits->set(bits->get(i) & (bsBits->get(i)),i, ctx);
		}
		for(int i = length2; i < length1; i ++ )
		{
			bits->set(0,i, ctx);
		}
		actualArrayLength = length2;
	}
	isLengthActual = !((actualArrayLength > 0) && (bits->get(actualArrayLength - 1) == (long long)0));
}
void BitSet::andNot(BitSet* bs, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<long long>* bsBits = bs->bits;
	if(!_needClear)
	{
		return;
	}
	int range = actualArrayLength < bs->actualArrayLength ? actualArrayLength : bs->actualArrayLength;
	for(int i = 0; i < range; i ++ )
	{
		bits->set(bits->get(i) & (~bsBits->get(i)),i, ctx);
	}
	if(actualArrayLength < range)
	{
		actualArrayLength = range;
	}
	isLengthActual = !((actualArrayLength > 0) && (bits->get(actualArrayLength - 1) == (long long)0));
}
void BitSet::_or(BitSet* bs, ThreadContext* ctx) throw() 
{
	int bsActualLen = bs->getActualArrayLength(ctx);
	if(bsActualLen > bits->length)
	{
		IArrayObjectPrimitive<long long>* tempBits = ArrayAllocatorPrimitive<long long>::allocatep(ctx, bsActualLen);
		System::arraycopy(bs->bits, 0, tempBits, 0, bs->actualArrayLength, ctx);
		for(int i = 0; i < actualArrayLength; i ++ )
		{
			tempBits->set(tempBits->get(i) | (bits->get(i)),i, ctx);
		}
		__GC_MV(this, &(bits), tempBits, IArrayObjectPrimitive<long long>);
		actualArrayLength = bsActualLen;
		isLengthActual = true;
	}
		else 
	{
		IArrayObjectPrimitive<long long>* bsBits = bs->bits;
		for(int i = 0; i < bsActualLen; i ++ )
		{
			bits->set(bits->get(i) | (bsBits->get(i)),i, ctx);
		}
		if(bsActualLen > actualArrayLength)
		{
			actualArrayLength = bsActualLen;
			isLengthActual = true;
		}
	}
	needClear(ctx);
}
void BitSet::_xor(BitSet* bs, ThreadContext* ctx) throw() 
{
	int bsActualLen = bs->getActualArrayLength(ctx);
	if(bsActualLen > bits->length)
	{
		IArrayObjectPrimitive<long long>* tempBits = ArrayAllocatorPrimitive<long long>::allocatep(ctx, bsActualLen);
		System::arraycopy(bs->bits, 0, tempBits, 0, bs->actualArrayLength, ctx);
		for(int i = 0; i < actualArrayLength; i ++ )
		{
			tempBits->set(tempBits->get(i) ^ (bits->get(i)),i, ctx);
		}
		__GC_MV(this, &(bits), tempBits, IArrayObjectPrimitive<long long>);
		actualArrayLength = bsActualLen;
		isLengthActual = !((actualArrayLength > 0) && (bits->get(actualArrayLength - 1) == (long long)0));
	}
		else 
	{
		IArrayObjectPrimitive<long long>* bsBits = bs->bits;
		for(int i = 0; i < bsActualLen; i ++ )
		{
			bits->set(bits->get(i) ^ (bsBits->get(i)),i, ctx);
		}
		if(bsActualLen > actualArrayLength)
		{
			actualArrayLength = bsActualLen;
			isLengthActual = true;
		}
	}
	needClear(ctx);
}
int BitSet::size(ThreadContext* ctx) throw() 
{
	return bits->length << OFFSET;
}
int BitSet::length(ThreadContext* ctx) throw() 
{
	int idx = actualArrayLength - 1;
	while(idx >= 0 && bits->get(idx) == (long long)0)
	{
		--idx;
	}
	actualArrayLength = idx + 1;
	if(idx == -1)
	{
		return 0;
	}
	int i = ELM_SIZE - 1;
	long long val = bits->get(idx);
	while((val & (TWO_N_ARRAY->get(i))) == (long long)0 && i > 0)
	{
		i -- ;
	}
	return (idx << OFFSET) + i + 1;
}
String* BitSet::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* sb = (new(ctx) StringBuilder(bits->length / 2, ctx));
	int bitCount = 0;
	sb->append(L'{', ctx);
	bool comma = false;
	for(int i = 0; i < bits->length; i ++ )
	{
		if(bits->get(i) == (long long)0)
		{
			bitCount += ELM_SIZE;
			continue;
		}
		for(int j = 0; j < ELM_SIZE; j ++ )
		{
			if(((bits->get(i) & (TWO_N_ARRAY->get(j))) != (long long)0))
			{
				if(comma)
				{
					sb->append(ConstStr::getCNST_STR_73(), ctx);
				}
				sb->append(bitCount, ctx);
				comma = true;
			}
			bitCount ++ ;
		}
	}
	sb->append(L'}', ctx);
	return sb->toString(ctx);
}
int BitSet::nextSetBit(int pos, ThreadContext* ctx) throw() 
{
	if(pos < 0)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	if(pos >= actualArrayLength << OFFSET)
	{
		return -1;
	}
	int idx = pos >> OFFSET;
	if(bits->get(idx) != (long long)0L)
	{
		for(int j = pos & RIGHT_BITS; j < ELM_SIZE; j ++ )
		{
			if(((bits->get(idx) & (TWO_N_ARRAY->get(j))) != (long long)0))
			{
				return (idx << OFFSET) + j;
			}
		}
	}
	idx ++ ;
	while(idx < actualArrayLength && bits->get(idx) == (long long)0L)
	{
		idx ++ ;
	}
	if(idx == actualArrayLength)
	{
		return -1;
	}
	for(int j = 0; j < ELM_SIZE; j ++ )
	{
		if(((bits->get(idx) & (TWO_N_ARRAY->get(j))) != (long long)0))
		{
			return (idx << OFFSET) + j;
		}
	}
	return -1;
}
int BitSet::nextClearBit(int pos, ThreadContext* ctx) throw() 
{
	if(pos < 0)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	int length = actualArrayLength;
	int bssize = length << OFFSET;
	if(pos >= bssize)
	{
		return pos;
	}
	int idx = pos >> OFFSET;
	if(bits->get(idx) != (long long)(~0L))
	{
		for(int j = pos % ELM_SIZE; j < ELM_SIZE; j ++ )
		{
			if(((bits->get(idx) & (TWO_N_ARRAY->get(j))) == (long long)0))
			{
				return idx * ELM_SIZE + j;
			}
		}
	}
	idx ++ ;
	while(idx < length && bits->get(idx) == (long long)(~0L))
	{
		idx ++ ;
	}
	if(idx == length)
	{
		return bssize;
	}
	for(int j = 0; j < ELM_SIZE; j ++ )
	{
		if(((bits->get(idx) & (TWO_N_ARRAY->get(j))) == (long long)0))
		{
			return (idx << OFFSET) + j;
		}
	}
	return bssize;
}
bool BitSet::isEmpty(ThreadContext* ctx) throw() 
{
	if(!_needClear)
	{
		return true;
	}
	int length = bits->length;
	for(int idx = 0; idx < length; idx ++ )
	{
		if(bits->get(idx) != (long long)0L)
		{
			return false;
		}
	}
	return true;
}
int BitSet::cardinality(ThreadContext* ctx) throw() 
{
	if(!_needClear)
	{
		return 0;
	}
	int count = 0;
	int length = bits->length;
	for(int idx = 0; idx < length; idx ++ )
	{
		count += pop(bits->get(idx) & 0xffffffffL, ctx);
		count += pop(((unsigned long long)bits->get(idx))>> 32, ctx);
	}
	return count;
}
void BitSet::growLength(int len, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<long long>* tempBits = ArrayAllocatorPrimitive<long long>::allocatep(ctx, MathUnsigned::max((uint32_t)len, (uint32_t)bits->length * 2, ctx));
	System::arraycopy(bits, 0, tempBits, 0, this->actualArrayLength, ctx);
	__GC_MV(this, &(bits), tempBits, IArrayObjectPrimitive<long long>);
}
void BitSet::needClear(ThreadContext* ctx) throw() 
{
	this->_needClear = true;
}
int BitSet::getActualArrayLength(ThreadContext* ctx) throw() 
{
	if(isLengthActual)
	{
		return actualArrayLength;
	}
	int idx = actualArrayLength - 1;
	while(idx >= 0 && bits->get(idx) == (long long)0)
	{
		--idx;
	}
	actualArrayLength = idx + 1;
	isLengthActual = true;
	return actualArrayLength;
}
int BitSet::pop(long long x, ThreadContext* ctx) throw() 
{
	x = x - ((((unsigned long long)x)>> 1) & 0x55555555);
	x = (x & 0x33333333) + ((((unsigned long long)x)>> 2) & 0x33333333);
	x = (x + (((unsigned long long)x)>> 4)) & 0x0f0f0f0f;
	x = x + (((unsigned long long)x)>> 8);
	x = x + (((unsigned long long)x)>> 16);
	return ((int)x) & 0x0000003f;
}
void BitSet::__cleanUp(ThreadContext* ctx){
}
}}

