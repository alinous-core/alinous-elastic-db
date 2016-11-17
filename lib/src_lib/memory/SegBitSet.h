/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_SEG_RAWBITSET_H_
#define SYSTEM_SEG_RAWBITSET_H_


namespace alinous {

class BgBitSetAllocThread;

class SegBitSet {
public:
	constexpr static const u_int32_t OFFSET{6};
	constexpr static const u_int32_t ELM_SIZE{1 << OFFSET};
	constexpr static const u_int32_t RIGHT_BITS{ELM_SIZE - 1};
	constexpr static const u_int64_t TWO_N_ARRAY[64]
		{0x1L, 0x2L, 0x4L, 0x8L, 0x10L, 0x20L, 0x40L, 0x80L, 0x100L, 0x200L, 0x400L, 0x800L, 0x1000L, 0x2000L, 0x4000L, 0x8000L, 0x10000L, 0x20000L, 0x40000L, 0x80000L, 0x100000L, 0x200000L, 0x400000L, 0x800000L, 0x1000000L, 0x2000000L, 0x4000000L, 0x8000000L, 0x10000000L, 0x20000000L, 0x40000000L, 0x80000000L, 0x100000000L, 0x200000000L, 0x400000000L, 0x800000000L, 0x1000000000L, 0x2000000000L, 0x4000000000L, 0x8000000000L, 0x10000000000L, 0x20000000000L, 0x40000000000L, 0x80000000000L, 0x100000000000L, 0x200000000000L, 0x400000000000L, 0x800000000000L, 0x1000000000000L, 0x2000000000000L, 0x4000000000000L, 0x8000000000000L, 0x10000000000000L, 0x20000000000000L, 0x40000000000000L, 0x80000000000000L, 0x100000000000000L, 0x200000000000000L, 0x400000000000000L, 0x800000000000000L, 0x1000000000000000L, 0x2000000000000000L, 0x4000000000000000L, 0x8000000000000000L};

	
	class SegBitsetArray {
	public:

		u_int64_t operator[](const int pos) throw() {
			return *(buff + pos);
		}
		u_int64_t operator[](const u_int32_t pos) throw() {
			return *(buff + pos);
		}
		u_int64_t operator[](const u_int64_t pos) throw() {
			return *(buff + pos);
		}

		u_int64_t length;
		u_int64_t* buff;
		SegBitsetArray(const int numBits) throw() ;
		~SegBitsetArray();
		void set(const u_int64_t value, const int index) throw() ;
		void growLength(const u_int32_t len) throw() ;

	};

	SegBitSet(u_int64_t nbits) throw();
	~SegBitSet() throw() {}

	bool get(const u_int64_t pos) throw();
	void set(const u_int64_t pos) throw();

    void set(const u_int64_t pos1, const u_int64_t pos2) throw();

	void clear(const u_int32_t pos) throw();
	inline void needClear() throw()
	{
		this->_needClear = true;
	}

	int nextSetBit(const u_int64_t pos) throw();
	int nextClearBit(const int pos) throw();

	void clear() throw();
private:
	SegBitsetArray bits;
	bool _needClear;
	u_int32_t actualArrayLength;
	bool isLengthActual;
};



class SegBitSetFactory{
public:
	SegBitSetFactory(u_int64_t nbits, BgBitSetAllocThread* thread) throw();
	~SegBitSetFactory() throw();

	SegBitSet* newBitSet() throw();
private:
	void wait4requestDone() throw();
	void backGroundAllocate() throw();

public:
	void doMalloc() throw();
private:
	u_int64_t nbits;
	SegRawArray<SegBitSet> array;
	BgBitSetAllocThread* thread;
	pthread_spinlock_t spinlock;

	volatile bool requesting;
};

class BgBitSetAllocThread {
public:
	BgBitSetAllocThread() throw();
	~BgBitSetAllocThread() throw();

	void request(SegBitSetFactory* element) throw();
	static void* extendOperationLoop(void* param) throw();
	void doJob(SegBitSetFactory* element) throw();
private:
	pthread_t threadId;
	volatile bool run;
	volatile bool ready;

	pthread_mutex_t mutex;
	pthread_cond_t cond;
	SegRawLinkedList<SegBitSetFactory> tasks;
};


} /* namespace alinous */

#endif /* SYSTEM_SEG_RAWBITSET_H_ */
