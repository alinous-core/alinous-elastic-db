#include "includes.h"


namespace java {namespace util {





constexpr const long long Random::multiplier;
bool Random::__init_done = __init_static_variables();
bool Random::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Random", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Random::Random(ThreadContext* ctx) throw()  : IObject(ctx), haveNextNextGaussian(0), seed(0), nextNextGaussian(0)
{
	setSeed(System::currentTimeMillis(ctx) + hashCode(ctx), ctx);
}
void Random::__construct_impl(ThreadContext* ctx) throw() 
{
	setSeed(System::currentTimeMillis(ctx) + hashCode(ctx), ctx);
}
 Random::Random(long long seed, ThreadContext* ctx) throw()  : IObject(ctx), haveNextNextGaussian(0), seed(0), nextNextGaussian(0)
{
	setSeed(seed, ctx);
}
void Random::__construct_impl(long long seed, ThreadContext* ctx) throw() 
{
	setSeed(seed, ctx);
}
 Random::~Random() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Random::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Random", L"~Random");
	if(!prepare){
		return;
	}
}
bool Random::nextBoolean(ThreadContext* ctx) throw() 
{
	return next(1, ctx) != 0;
}
void Random::nextBytes(IArrayObjectPrimitive<char>* buf, ThreadContext* ctx) throw() 
{
	int rand = 0;int count = 0;int loop = 0;
	while(count < buf->length)
	{
		if(loop == 0)
		{
			rand = nextInt(ctx);
			loop = 3;
		}
				else 
		{
			loop -- ;
		}
		buf->set(((char)rand),count++, ctx);
		rand >>= 8;
	}
}
double Random::nextDouble(ThreadContext* ctx) throw() 
{
	return (((((long long)next(26, ctx)) << 27) + next(27, ctx)) / ((double)(1L << 53)));
}
float Random::nextFloat(ThreadContext* ctx) throw() 
{
	return (next(24, ctx) / 16777216.0f);
}
double Random::nextGaussian(ThreadContext* ctx) throw() 
{
	if(haveNextNextGaussian)
	{
		haveNextNextGaussian = false;
		return nextNextGaussian;
	}
	double v1 = 0;double v2 = 0;double s = 0;
	do
	{
		v1 = 2 * nextDouble(ctx) - 1;
		v2 = 2 * nextDouble(ctx) - 1;
		s = v1 * v1 + v2 * v2;
	}
	while(s >= (double)1);
	double norm = Math::sqrt((double)-2 * Math::log(s, ctx) / s, ctx);
	nextNextGaussian = v2 * norm;
	haveNextNextGaussian = true;
	return v1 * norm;
}
int Random::nextInt(ThreadContext* ctx) throw() 
{
	return next(32, ctx);
}
int Random::nextInt(int n, ThreadContext* ctx) throw() 
{
	if(n > 0)
	{
		if((n & -n) == n)
		{
			return ((int)((n * ((long long)next(31, ctx))) >> 31));
		}
		int bits = 0;int val = 0;
		do
		{
			bits = next(31, ctx);
			val = bits % n;
		}
		while(bits - val + (n - 1) < 0);
		return val;
	}
	throw (new(ctx) IllegalArgumentException(ctx));
}
long long Random::nextLong(ThreadContext* ctx) throw() 
{
	return (((long long)next(32, ctx)) << 32) + next(32, ctx);
}
void Random::setSeed(long long seed, ThreadContext* ctx) throw() 
{
	this->seed = (seed ^ multiplier) & ((1L << 48) - 1);
	haveNextNextGaussian = false;
}
int Random::next(int bits, ThreadContext* ctx) throw() 
{
	seed = (seed * multiplier + 0xbL) & ((1L << 48) - 1);
	return ((int)(((unsigned long long)seed)>> (48 - bits)));
}
}}

