#ifndef ALINOUS_RUNTIME_ALINOUSMODULEPACKAGE_H_
#define ALINOUS_RUNTIME_ALINOUSMODULEPACKAGE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {
class AlinousModulePackage;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class AlinousModulePackage final : public IAlinousElement {
public:
	AlinousModulePackage(const AlinousModulePackage& base) = default;
public:
	AlinousModulePackage(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), segments(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	AlinousModulePackage(String* path, ThreadContext* ctx) throw() ;
	void __construct_impl(String* path, ThreadContext* ctx) throw() ;
	virtual ~AlinousModulePackage() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<String>* segments;
public:
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_RUNTIME_ALINOUSMODULEPACKAGE_H_ */
