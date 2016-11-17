#ifndef JAVA_UTIL_RANDOM_H_
#define JAVA_UTIL_RANDOM_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class IllegalArgumentException;}}

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



class Random final : public virtual IObject {
public:
	Random(const Random& base) = default;
public:
	Random(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	Random(long long seed, ThreadContext* ctx) throw() ;
	void __construct_impl(long long seed, ThreadContext* ctx) throw() ;
	virtual ~Random() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool haveNextNextGaussian;
	long long seed;
	double nextNextGaussian;
private:
	constexpr static const long long multiplier{0x5deece66dL};
public:
	bool nextBoolean(ThreadContext* ctx) throw() ;
	void nextBytes(IArrayObjectPrimitive<char>* buf, ThreadContext* ctx) throw() ;
	double nextDouble(ThreadContext* ctx) throw() ;
	float nextFloat(ThreadContext* ctx) throw() ;
	double nextGaussian(ThreadContext* ctx) throw() ;
	int nextInt(ThreadContext* ctx) throw() ;
	int nextInt(int n, ThreadContext* ctx) throw() ;
	long long nextLong(ThreadContext* ctx) throw() ;
	void setSeed(long long seed, ThreadContext* ctx) throw() ;
	int next(int bits, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_UTIL_RANDOM_H_ */
