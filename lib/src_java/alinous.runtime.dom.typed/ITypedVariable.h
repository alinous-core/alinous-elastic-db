#ifndef ALINOUS_RUNTIME_DOM_TYPED_ITYPEDVARIABLE_H_
#define ALINOUS_RUNTIME_DOM_TYPED_ITYPEDVARIABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {namespace typed {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dom::IAlinousVariable;



class ITypedVariable : public virtual IObject, public IAlinousVariable {
public:
	ITypedVariable(const ITypedVariable& base) = default;
public:
	ITypedVariable(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ITypedVariable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_BOOL{0};
	constexpr static const int TYPE_BYTE{1};
	constexpr static const int TYPE_CHAR{2};
	constexpr static const int TYPE_DOUBLE{3};
	constexpr static const int TYPE_FLOAT{4};
	constexpr static const int TYPE_INT{5};
	constexpr static const int TYPE_LONG{6};
	constexpr static const int TYPE_SHORT{7};
	constexpr static const int TYPE_STRING{8};
	constexpr static const int TYPE_BIGDECIMAL{9};
	constexpr static const int TYPE_TIME{10};
	constexpr static const int TYPE_TIMESTAMP{11};
	constexpr static const int TYPE_ARRAY{12};
	constexpr static const int TYPE_CLASS_OBJECT{13};
	static String* TYPED_VARIABLE;
public:
	virtual int getTypedType(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_DOM_TYPED_ITYPEDVARIABLE_H_ */
