/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace alinous {

constexpr const u_int64_t RawBitSet::TWO_N_ARRAY[64];

void RawBitSet::BitsetArray::growLength(u_int32_t len) throw() {
	u_int64_t* tmp = new u_int64_t[len]{};

	FastCopy::copy(tmp, buff, length * sizeof(u_int64_t));
	this->length = len;
	delete [] buff;
	buff = tmp;
}

RawBitSet::RawBitSet(uint32_t nbits) throw() : bits( (nbits >> OFFSET) + ((nbits & RIGHT_BITS) > 0) ? 1 : 0 )
			, _needClear(false), actualArrayLength(0), isLengthActual(true)
{
}

void RawBitSet::set(u_int32_t pos) throw()
{
#ifdef __DEBUG__
	assert(pos >= (u_int32_t)0);
#endif
	int len = (pos >> OFFSET) + 1;
	if(len > bits.length)
	{
		bits.growLength(len);
	}
	bits.set(bits[len - 1] | (TWO_N_ARRAY[pos & RIGHT_BITS]), len - 1);
	if(len > (int)actualArrayLength)
	{
		actualArrayLength = len;
		isLengthActual = true;
	}
	needClear();
}

void RawBitSet::clear(u_int32_t pos) throw()
{
#ifdef __DEBUG__
	assert(pos >= (u_int32_t)0);
#endif
	if(!_needClear)
	{
		return ;
	}
	u_int32_t arrayPos = pos >> OFFSET;
	if(arrayPos < actualArrayLength)
	{
		bits.set(bits[arrayPos] & (~(TWO_N_ARRAY[pos & RIGHT_BITS])),arrayPos);
		if(bits[actualArrayLength - 1] == (u_int64_t)0)
		{
			isLengthActual = false;
		}
	}
}

void RawBitSet::needClear() throw()
{
	this->_needClear = true;
}

int RawBitSet::nextSetBit(const u_int32_t pos) const throw()
{
	if(pos >= actualArrayLength << OFFSET)
	{
		return -1;
	}
	u_int32_t idx = pos >> OFFSET;
	if(bits[idx] != (uint64_t)0L)
	{
		for(u_int32_t j = pos & RIGHT_BITS; j < ELM_SIZE; j ++ )
		{
			if(((bits[idx] & (TWO_N_ARRAY[j])) != (uint64_t)0))
			{
				return (idx << OFFSET) + j;
			}
		}
	}
	idx ++ ;
	while(idx < actualArrayLength && bits[idx] == (u_int64_t)0L)
	{
		idx ++ ;
	}
	if(idx == actualArrayLength)
	{
		return -1;
	}
	for(u_int32_t j = 0; j < ELM_SIZE; j ++ )
	{
		if(((bits[idx] & (TWO_N_ARRAY[j])) != 0))
		{
			return (idx << OFFSET) + j;
		}
	}
	return -1;
}

void RawBitSet::clear() throw()
{
	if(_needClear)
	{

		for(u_int32_t i = 0; i < (u_int32_t)bits.length; i ++ )
		{
			bits.set(0L, i);
		}
		actualArrayLength = 0;
		isLengthActual = true;
		_needClear = false;
	}
}


}


