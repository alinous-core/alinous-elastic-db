#ifndef ALINOUS_COMPILE_DECLARE_ABSTRACTCLASSMEMBER_H_
#define ALINOUS_COMPILE_DECLARE_ABSTRACTCLASSMEMBER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class ClassMemberModifiers;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace declare {
class IClassMember;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;



class AbstractClassMember : public IClassMember {
public:
	AbstractClassMember(const AbstractClassMember& base) = default;
public:
	AbstractClassMember(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractClassMember() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ClassMemberModifiers* modifier;
public:
	ClassMemberModifiers* getModifier(ThreadContext* ctx) throw() ;
	void setModifier(ClassMemberModifiers* modifier, ThreadContext* ctx) throw() ;
	bool isStatic(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_ABSTRACTCLASSMEMBER_H_ */
