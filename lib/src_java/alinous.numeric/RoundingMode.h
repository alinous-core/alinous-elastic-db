#ifndef ALINOUS_NUMERIC_ROUNDINGMODE_H_
#define ALINOUS_NUMERIC_ROUNDINGMODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class RoundingMode;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace numeric {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class RoundingMode final : public virtual IObject {
public:
	RoundingMode(const RoundingMode& base) = default;
public:
	RoundingMode(int rm, ThreadContext* ctx) throw() ;
	void __construct_impl(int rm, ThreadContext* ctx) throw() ;
	virtual ~RoundingMode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int bigDecimalRM;
public:
	static int UP;
	static int DOWN;
	static int CEILING;
	static int FLOOR;
	static int HALF_UP;
	static int HALF_DOWN;
	static int HALF_EVEN;
	static int UNNECESSARY;
public:
	int getBigDecimalRM(ThreadContext* ctx) throw() ;
public:
	static RoundingMode* valueOf(int mode, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_NUMERIC_ROUNDINGMODE_H_ */
