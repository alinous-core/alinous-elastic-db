#ifndef ALINOUS_RUNTIME_DOM_TYPED_ABSTRACTTYPEDVARIABLE_H_
#define ALINOUS_RUNTIME_DOM_TYPED_ABSTRACTTYPEDVARIABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedCaller;}}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BoolVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ByteVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class CharVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class DoubleVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class FloatVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class IntegerVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class LongVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ShortVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class StringVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BigDecimalVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimeVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimestampVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableOperationCaller;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {namespace typed {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableOperationCaller;
using ::alinous::system::AlinousException;



class AbstractTypedVariable : public ITypedVariable, public virtual IObject {
public:
	class CallerBool;
	class CallerByte;
	class CallerChar;
	class CallerDouble;
	class CallerFloat;
	class CallerInt;
	class CallerLong;
	class CallerShort;
	class CallerString;
	class CallerBigDecimal;
	class CallerTime;
	class CallerTimestamp;
	class CallerArrayObject;
	AbstractTypedVariable(const AbstractTypedVariable& base) = default;
public:
	AbstractTypedVariable(ThreadContext* ctx) throw()  : IObject(ctx), ITypedVariable(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractTypedVariable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* VALUE;
	static IArrayObject<ITypedCaller>* typedCallers;
public:
	virtual IAlinousVariable* add(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* minus(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* multiply(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* div(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* shiftLeft(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* shiftRight(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* modulo(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* substitute(IAlinousVariable* variable, ThreadContext* ctx);
	virtual int compareTo(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* bitOr(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* bitAnd(IAlinousVariable* variable, ThreadContext* ctx);
	virtual IAlinousVariable* bitExor(IAlinousVariable* variable, ThreadContext* ctx);
public:
	static IArrayObject<ITypedCaller>* createCaller(ThreadContext* ctx) throw() ;
public:



	class CallerBool final : public ITypedCaller, public virtual IObject {
	public:
		CallerBool(const CallerBool& base) = default;
	public:
		CallerBool(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerBool() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerByte final : public ITypedCaller, public virtual IObject {
	public:
		CallerByte(const CallerByte& base) = default;
	public:
		CallerByte(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerByte() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerChar final : public ITypedCaller, public virtual IObject {
	public:
		CallerChar(const CallerChar& base) = default;
	public:
		CallerChar(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerChar() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerDouble final : public ITypedCaller, public virtual IObject {
	public:
		CallerDouble(const CallerDouble& base) = default;
	public:
		CallerDouble(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerDouble() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerFloat final : public ITypedCaller, public virtual IObject {
	public:
		CallerFloat(const CallerFloat& base) = default;
	public:
		CallerFloat(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerFloat() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerInt final : public ITypedCaller, public virtual IObject {
	public:
		CallerInt(const CallerInt& base) = default;
	public:
		CallerInt(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerInt() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerLong final : public ITypedCaller, public virtual IObject {
	public:
		CallerLong(const CallerLong& base) = default;
	public:
		CallerLong(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerLong() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerShort final : public ITypedCaller, public virtual IObject {
	public:
		CallerShort(const CallerShort& base) = default;
	public:
		CallerShort(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerShort() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerString final : public ITypedCaller, public virtual IObject {
	public:
		CallerString(const CallerString& base) = default;
	public:
		CallerString(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerString() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerBigDecimal final : public ITypedCaller, public virtual IObject {
	public:
		CallerBigDecimal(const CallerBigDecimal& base) = default;
	public:
		CallerBigDecimal(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerBigDecimal() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerTime final : public ITypedCaller, public virtual IObject {
	public:
		CallerTime(const CallerTime& base) = default;
	public:
		CallerTime(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerTime() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerTimestamp final : public ITypedCaller, public virtual IObject {
	public:
		CallerTimestamp(const CallerTimestamp& base) = default;
	public:
		CallerTimestamp(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerTimestamp() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class CallerArrayObject final : public ITypedCaller, public virtual IObject {
	public:
		CallerArrayObject(const CallerArrayObject& base) = default;
	public:
		CallerArrayObject(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~CallerArrayObject() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<IArrayObject<ITypedCaller>>::dec(nullptr, AbstractTypedVariable::typedCallers, ctx, __FILEW__, __LINE__, L"IArrayObject<ITypedCaller>");
	}
	class ValueCompare {
	public:
		int operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw();
	};
};

}}}}

#endif /* end of ALINOUS_RUNTIME_DOM_TYPED_ABSTRACTTYPEDVARIABLE_H_ */
