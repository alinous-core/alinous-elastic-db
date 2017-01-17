#ifndef ALINOUS_COMPILE_DECLARE_ALINOUSNAME_H_
#define ALINOUS_COMPILE_DECLARE_ALINOUSNAME_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IAlinousVisitorContainer;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::DomNameSegment;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::expression::IDomSegment;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class AlinousName final : public IAlinousElement, public IAlinousVisitorContainer {
public:
	AlinousName(const AlinousName& base) = default;
public:
	AlinousName(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), segments(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousName() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<String>* segments;
public:
	DomVariableDescriptor* toDomVariableDescriptor(ThreadContext* ctx) throw() ;
	String* getClassName(ThreadContext* ctx) throw() ;
	String* getPackageName(ThreadContext* ctx) throw() ;
	bool isVoid(ThreadContext* ctx) throw() ;
	bool isPrimitive(ThreadContext* ctx) throw() ;
	bool isPrimitiveArray(ThreadContext* ctx) throw() ;
	bool isStandardType(ThreadContext* ctx) throw() ;
	bool isStandardTypeArray(ThreadContext* ctx) throw() ;
	AlinousType* toAlinousType(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	void addSegment(String* str, ThreadContext* ctx) throw() ;
	ArrayList<String>* getSegments(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	bool equals(String* obj, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	int fileSize(ThreadContext* ctx) throw() ;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() ;
public:
	static AlinousName* fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_ALINOUSNAME_H_ */
