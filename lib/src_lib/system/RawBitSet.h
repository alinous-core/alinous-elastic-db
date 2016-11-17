/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_RAWBITSET_H_
#define SYSTEM_RAWBITSET_H_


namespace alinous {

class RawBitSet {
public:
    void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }
    void* operator new(size_t size, MemoryInterface* ctx) throw() {
    	return ctx->alloc->allocate(size);
    }
    void operator delete(void* p, size_t size) throw() {
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }

	constexpr static const uint32_t OFFSET{6};
	constexpr static const uint32_t ELM_SIZE{1 << OFFSET};
	constexpr static const uint32_t RIGHT_BITS{ELM_SIZE - 1};
	constexpr static const u_int64_t TWO_N_ARRAY[64]
		{0x1L, 0x2L, 0x4L, 0x8L, 0x10L, 0x20L, 0x40L, 0x80L, 0x100L, 0x200L, 0x400L, 0x800L, 0x1000L, 0x2000L, 0x4000L, 0x8000L, 0x10000L, 0x20000L, 0x40000L, 0x80000L, 0x100000L, 0x200000L, 0x400000L, 0x800000L, 0x1000000L, 0x2000000L, 0x4000000L, 0x8000000L, 0x10000000L, 0x20000000L, 0x40000000L, 0x80000000L, 0x100000000L, 0x200000000L, 0x400000000L, 0x800000000L, 0x1000000000L, 0x2000000000L, 0x4000000000L, 0x8000000000L, 0x10000000000L, 0x20000000000L, 0x40000000000L, 0x80000000000L, 0x100000000000L, 0x200000000000L, 0x400000000000L, 0x800000000000L, 0x1000000000000L, 0x2000000000000L, 0x4000000000000L, 0x8000000000000L, 0x10000000000000L, 0x20000000000000L, 0x40000000000000L, 0x80000000000000L, 0x100000000000000L, 0x200000000000000L, 0x400000000000000L, 0x800000000000000L, 0x1000000000000000L, 0x2000000000000000L, 0x4000000000000000L, 0x8000000000000000L};

	class BitsetArray {
	public:
	    void* operator new(size_t size) throw() {
	      	return SysThread::getMalloc()->allocate(size);
	    }
	    void* operator new(size_t size, MemoryInterface* ctx) throw() {
	    	return ctx->alloc->allocate(size);
	    }
	    void operator delete(void* p, size_t size) throw() {
	    	SysThread::getMalloc()->freeMemory((char*)p, size);
	    }


		int length;
		u_int64_t* buff;
		BitsetArray(int numBits) throw() : length(numBits), buff(new u_int64_t[numBits]{}) {
		}
		~BitsetArray() throw() {
			delete [] buff;
		}

		void set(u_int64_t value, int index) throw() {
			this->buff[index] = value;
		}

		void growLength(u_int32_t len) throw() ;

		u_int64_t operator[](const int pos) const throw() {
			return buff[pos];
		}
		u_int64_t operator[](const u_int32_t pos) const throw() {
			return buff[pos];
		}
	};

	RawBitSet(uint32_t nbits) throw() ;
	~RawBitSet() throw() {
	}

	bool get(uint32_t pos) throw() ;
	void set(u_int32_t pos) throw() ;
	void clear(u_int32_t pos) throw() ;
	void needClear() throw() ;
	int nextSetBit(const u_int32_t pos) const throw() ;
	void clear() throw() ;
private:
	BitsetArray bits;
	bool _needClear;
	uint32_t actualArrayLength;
	bool isLengthActual;
};

} /* namespace alinous */

#endif /* SYSTEM_RAWBITSET_H_ */
