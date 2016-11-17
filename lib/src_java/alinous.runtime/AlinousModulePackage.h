#ifndef ALINOUS_RUNTIME_ALINOUSMODULEPACKAGE_H_
#define ALINOUS_RUNTIME_ALINOUSMODULEPACKAGE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {
class AlinousModulePackage;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class AlinousModulePackage final : public virtual IObject {
public:
	AlinousModulePackage(const AlinousModulePackage& base) = default;
public:
	AlinousModulePackage(String* path, ThreadContext* ctx) throw() ;
	void __construct_impl(String* path, ThreadContext* ctx) throw() ;
	virtual ~AlinousModulePackage() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<String>* segments;
public:
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_RUNTIME_ALINOUSMODULEPACKAGE_H_ */
