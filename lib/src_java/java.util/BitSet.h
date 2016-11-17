#ifndef JAVA_UTIL_BITSET_H_
#define JAVA_UTIL_BITSET_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class NegativeArraySizeException;}}

namespace java {namespace lang {
class CloneNotSupportedException;}}

namespace java {namespace util {
class BitSet;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace util {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class BitSet final : public Cloneable, public virtual IObject {
public:
	BitSet(const BitSet& base) = default;
public:
	BitSet(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	BitSet(int nbits, ThreadContext* ctx) throw() ;
	void __construct_impl(int nbits, ThreadContext* ctx) throw() ;
	BitSet(IArrayObjectPrimitive<long long>* bits, bool needClear, int actualArrayLength, bool isLengthActual, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<long long>* bits, bool needClear, int actualArrayLength, bool isLengthActual, ThreadContext* ctx) throw() ;
	virtual ~BitSet() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IArrayObjectPrimitive<long long>* bits;
	bool _needClear;
	int actualArrayLength;
	bool isLengthActual;
private:
	constexpr static const int OFFSET{6};
	constexpr static const int ELM_SIZE{1 << OFFSET};
	constexpr static const int RIGHT_BITS{ELM_SIZE - 1};
	static const StaticArrayObjectPrimitive<long long> __TWO_N_ARRAY;
	static IArrayObjectPrimitive<long long>* TWO_N_ARRAY;
public:
	IObject* clone(ThreadContext* ctx);
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	int _hashCode(ThreadContext* ctx) throw() ;
	bool get(int pos, ThreadContext* ctx) throw() ;
	BitSet* get(int pos1, int pos2, ThreadContext* ctx) throw() ;
	void set(int pos, ThreadContext* ctx) throw() ;
	void set(int pos, bool val, ThreadContext* ctx) throw() ;
	void set(int pos1, int pos2, ThreadContext* ctx) throw() ;
	void set(int pos1, int pos2, bool val, ThreadContext* ctx) throw() ;
	void clear(ThreadContext* ctx) throw() ;
	void clear(int pos, ThreadContext* ctx) throw() ;
	void clear(int pos1, int pos2, ThreadContext* ctx) throw() ;
	void flip(int pos, ThreadContext* ctx) throw() ;
	void flip(int pos1, int pos2, ThreadContext* ctx) throw() ;
	bool intersects(BitSet* bs, ThreadContext* ctx) throw() ;
	void _and(BitSet* bs, ThreadContext* ctx) throw() ;
	void andNot(BitSet* bs, ThreadContext* ctx) throw() ;
	void _or(BitSet* bs, ThreadContext* ctx) throw() ;
	void _xor(BitSet* bs, ThreadContext* ctx) throw() ;
	int size(ThreadContext* ctx) throw() ;
	int length(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	int nextSetBit(int pos, ThreadContext* ctx) throw() ;
	int nextClearBit(int pos, ThreadContext* ctx) throw() ;
	bool isEmpty(ThreadContext* ctx) throw() ;
	int cardinality(ThreadContext* ctx) throw() ;
private:
	void growLength(int len, ThreadContext* ctx) throw() ;
	void needClear(ThreadContext* ctx) throw() ;
	int getActualArrayLength(ThreadContext* ctx) throw() ;
	int pop(long long x, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_UTIL_BITSET_H_ */
