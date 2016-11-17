/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_IOBLECTSTATUS_H_
#define GC_IOBLECTSTATUS_H_

namespace alinous {

class IObjectStatus {
public:
	class Hash {
	public:
		u_int64_t operator() (const IObjectStatus* const a) const throw() {
			return (u_int64_t)a->ptr;
		}
	};
	struct RawCompare {
	public:
		RawCompare(){}
		int operator() (const IObjectStatus* const a, const IObjectStatus* const b, const ThreadContext* const ctx) const throw();
	};

	class OwnerStatus{
	public:
		OwnerStatus(IObjectStatus* ptr)throw() : ptr(ptr), count(0) {}
		IObjectStatus* ptr;

		struct ValueCompare {
			int operator() (const OwnerStatus* const a, const OwnerStatus* const b, const ThreadContext* const ctx) const throw();
		};
		struct Hash {
			u_int64_t operator() (const OwnerStatus* const a) const throw() {
				return (u_int64_t)a->ptr;
			}
		};

		void inc() throw();
		void dec() throw();
		int getCount() throw();
	private:
		int count;
	};

public:
	IObjectStatus(GCObject* ptr) throw();
	inline ~IObjectStatus() throw(){
		delete this->owners;
	}

	inline bool isLocked() throw(){
		return this->locked > 0;
	}

	inline void lock() throw(){
		this->locked++;
	}

	inline void unclock() throw(){
		this->locked--;
	}

	inline bool isDeletable() throw(){
		return this->refs == 0 && this->locked==0 && this->toCount == 0;
	}

	inline bool isReleasable() throw(){
		return this->refs == 0 && !this->locked == 0;
	}

	inline GCObject* getPtr(){
		return ptr;
	}

	void inc(IObjectStatus* owner) throw();
	void dec(IObjectStatus* owner) throw();
	bool checkCyclic(HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>* buffer) throw();

	inline int getRefs() throw(){
		return this->refs;
	}
private:
	OwnerStatus* findOwner(IObjectStatus* owner) throw();
public:
	inline int getNumOwners()throw(){
		return this->numFromOwners;
	}

	inline void incTo() throw() {
		this->toCount++;
	}
	inline void decTo() throw() {
		this->toCount--;
	}

private:
	GCObject* ptr;
	RawArray<OwnerStatus, typename OwnerStatus::ValueCompare>* owners;
	int refs;
	int numFromOwners;

	int toCount;

	int locked;
};

}  // namespace alinous




#endif /* GC_IOBLECTSTATUS_H_ */
