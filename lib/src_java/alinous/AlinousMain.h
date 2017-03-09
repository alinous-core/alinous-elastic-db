#ifndef ALINOUS_ALINOUSMAIN_H_
#define ALINOUS_ALINOUSMAIN_H_
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace server {
class AlinousCoreServer;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace util {
class AlinousDebug;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::server::AlinousCoreServer;
using ::alinous::system::AlinousException;
using ::alinous::util::AlinousDebug;

class __AlinousMain__ArgumentState : public EnumBase {
public:
	__AlinousMain__ArgumentState() = default;
	constexpr __AlinousMain__ArgumentState(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __AlinousMain__ArgumentState(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  NORMAL_ARG{1};
	static constexpr EnumBase  ALINOUS_HOME{2};
	static constexpr EnumBase  DEBUG_PORT{3};
};


class AlinousMain final : public virtual IObject {
public:
	class ArgumentState : public __AlinousMain__ArgumentState {
	public:
		ArgumentState() = default;constexpr ArgumentState(const EnumBase& base) :  __AlinousMain__ArgumentState(base) {};
	};
public:
	AlinousMain(const AlinousMain& base) = default;
public:
	AlinousMain(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AlinousMain() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* ARG_ALINOUS_HOME;
	static String* ARG_DEBUG_PORT;
public:
	static void main(IArrayObject<String>* args, ThreadContext* ctx) throw() ;
private:
	static void doMain(IArrayObject<String>* args, ThreadContext* ctx);
	static void launchAlinous(String* alinousHome, int debugPort, ThreadContext* ctx);
	static AlinousMain::ArgumentState getNextState(String* arg, AlinousMain::ArgumentState state, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}

#endif /* end of ALINOUS_ALINOUSMAIN_H_ */
