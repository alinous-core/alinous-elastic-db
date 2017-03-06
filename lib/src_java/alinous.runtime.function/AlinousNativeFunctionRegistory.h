#ifndef ALINOUS_RUNTIME_FUNCTION_ALINOUSNATIVEFUNCTIONREGISTORY_H_
#define ALINOUS_RUNTIME_FUNCTION_ALINOUSNATIVEFUNCTIONREGISTORY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace function {namespace system {
class SystemPrintLn;}}}}

namespace alinous {namespace runtime {namespace function {
class IAlinousNativeFunction;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace function {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::alinous::runtime::function::system::SystemPrintLn;



class AlinousNativeFunctionRegistory final : public virtual IObject {
public:
	class FuncHolder;
	AlinousNativeFunctionRegistory(const AlinousNativeFunctionRegistory& base) = default;
public:
	AlinousNativeFunctionRegistory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AlinousNativeFunctionRegistory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,AlinousNativeFunctionRegistory::FuncHolder>* nativeFunctions;
public:
	bool isPrefix(String* prefix, ThreadContext* ctx) throw() ;
	IAlinousNativeFunction* get(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
private:
	void addFunction(IAlinousNativeFunction* func, ThreadContext* ctx) throw() ;
public:



	class FuncHolder final : public virtual IObject {
	public:
		FuncHolder(const FuncHolder& base) = default;
	public:
		FuncHolder(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~FuncHolder() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		HashMap<String,IAlinousNativeFunction>* nativeFunctions;
	public:
		void add(IAlinousNativeFunction* func, ThreadContext* ctx) throw() ;
		IAlinousNativeFunction* get(String* name, ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_FUNCTION_ALINOUSNATIVEFUNCTIONREGISTORY_H_ */
