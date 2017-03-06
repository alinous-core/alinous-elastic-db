#ifndef ALINOUS_COMPILE_DECLARE_VIRTUALTABLE_H_
#define ALINOUS_COMPILE_DECLARE_VIRTUALTABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class VirtualTable final : public IAlinousElement {
public:
	class MethodPair;
	VirtualTable(const VirtualTable& base) = default;
public:
	VirtualTable(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~VirtualTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<VirtualTable::MethodPair>* list;
public:
	void addVirtualFunction(AlinousClass* clazz, ClassMethodFunction* method, ThreadContext* ctx) throw() ;
	ClassMethodFunction* getMethod(AlinousClass* clazz, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
public:



	class MethodPair final : public virtual IObject {
	public:
		MethodPair(const MethodPair& base) = default;
	public:
		MethodPair(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw() ;
		void __construct_impl(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw() ;
		virtual ~MethodPair() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		AlinousClass* clazz;
		ClassMethodFunction* func;
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

#endif /* end of ALINOUS_COMPILE_DECLARE_VIRTUALTABLE_H_ */
