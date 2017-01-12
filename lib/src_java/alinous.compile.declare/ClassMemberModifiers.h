#ifndef ALINOUS_COMPILE_DECLARE_CLASSMEMBERMODIFIERS_H_
#define ALINOUS_COMPILE_DECLARE_CLASSMEMBERMODIFIERS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

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
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class ClassMemberModifiers final : public IDeclare {
public:
	ClassMemberModifiers(const ClassMemberModifiers& base) = default;
public:
	ClassMemberModifiers(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), list(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), staticMod(false), privateMod(false), protectedMod(true), publicMod(false)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ClassMemberModifiers() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<String>* list;
	bool staticMod;
	bool privateMod;
	bool protectedMod;
	bool publicMod;
public:
	void addModifier(String* mod, ThreadContext* ctx) throw() ;
	ArrayList<String>* getList(ThreadContext* ctx) throw() ;
	bool isStatic(ThreadContext* ctx) throw() ;
	bool isPrivateMod(ThreadContext* ctx) throw() ;
	bool isProtectedMod(ThreadContext* ctx) throw() ;
	bool isPublicMod(ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_CLASSMEMBERMODIFIERS_H_ */
