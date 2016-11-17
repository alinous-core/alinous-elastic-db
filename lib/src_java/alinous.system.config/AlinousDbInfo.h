#ifndef ALINOUS_SYSTEM_CONFIG_ALINOUSDBINFO_H_
#define ALINOUS_SYSTEM_CONFIG_ALINOUSDBINFO_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {namespace config {
class AlinousDbInstanceInfo;}}}

namespace java {namespace util {
template <typename  T> class Set;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::HashMap;
using ::java::util::Set;



class AlinousDbInfo final : public virtual IObject {
public:
	AlinousDbInfo(const AlinousDbInfo& base) = default;
public:
	AlinousDbInfo(String* alinousHome, ThreadContext* ctx) throw() ;
	void __construct_impl(String* alinousHome, ThreadContext* ctx) throw() ;
	virtual ~AlinousDbInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,AlinousDbInstanceInfo>* instances;
	String* alinousHome;
public:
	void addInstance(String* id, String* dataDir, ThreadContext* ctx) throw() ;
	AlinousDbInstanceInfo* getInstance(String* id, ThreadContext* ctx) throw() ;
	Set<String>* idSet(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_ALINOUSDBINFO_H_ */
