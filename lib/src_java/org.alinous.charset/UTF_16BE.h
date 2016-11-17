#ifndef ORG_ALINOUS_CHARSET_UTF_16BE_H_
#define ORG_ALINOUS_CHARSET_UTF_16BE_H_
namespace org {namespace alinous {namespace charset {
class UTF_16;}}}

namespace alinous {
class ThreadContext;
}

namespace org {namespace alinous {namespace charset {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class UTF_16BE final : public UTF_16 {
public:
	UTF_16BE(const UTF_16BE& base) = default;
public:
	UTF_16BE(ThreadContext* ctx) throw()  : IObject(ctx), UTF_16(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~UTF_16BE() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int getDefaultEndian(ThreadContext* ctx) throw() ;
	int getDetectedEndian(int b1, int b2, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ORG_ALINOUS_CHARSET_UTF_16BE_H_ */
