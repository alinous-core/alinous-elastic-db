#ifndef ALINOUS_RUNTIME_DOM_IDOMVARIABLE_H_
#define ALINOUS_RUNTIME_DOM_IDOMVARIABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariableContainer;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IDomVariable : public virtual IObject, public IDomVariableContainer, public IAlinousVariable {
public:
	IDomVariable(const IDomVariable& base) = default;
public:
	IDomVariable(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IDomVariable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_DOM{0};
	constexpr static const int TYPE_ARRAY{1};
public:
	virtual int getDomType(ThreadContext* ctx) throw()  = 0;
	virtual IDomVariable* toDom(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_IDOMVARIABLE_H_ */
