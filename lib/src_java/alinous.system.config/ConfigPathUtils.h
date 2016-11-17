#ifndef ALINOUS_SYSTEM_CONFIG_CONFIGPATHUTILS_H_
#define ALINOUS_SYSTEM_CONFIG_CONFIGPATHUTILS_H_
namespace java {namespace util {
template <typename  T> class Stack;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Iterator;
using ::java::util::Stack;



class ConfigPathUtils final : public virtual IObject {
public:
	ConfigPathUtils(const ConfigPathUtils& base) = default;
public:
	ConfigPathUtils(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ConfigPathUtils() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* getAbsDirPath(String* base, String* path, ThreadContext* ctx) throw() ;
private:
	static Stack<String>* toList(String* path, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_CONFIGPATHUTILS_H_ */
