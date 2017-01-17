#ifndef ALINOUS_COMPILE_EXPRESSION_NULLLITERAL_H_
#define ALINOUS_COMPILE_EXPRESSION_NULLLITERAL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class NullLiteral final : public Literal {
public:
	NullLiteral(const NullLiteral& base) = default;
public:
	NullLiteral(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~NullLiteral() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_NULLLITERAL_H_ */
