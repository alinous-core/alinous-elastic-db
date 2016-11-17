#ifndef ALINOUS_COMPILE_ANALYSE_CLASSDECLAREHOLDER_H_
#define ALINOUS_COMPILE_ANALYSE_CLASSDECLAREHOLDER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace runtime {
class AlinousModulePackage;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::AlinousName;
using ::alinous::runtime::AlinousModulePackage;



class ClassDeclareHolder final : public virtual IObject {
public:
	class ClassDeclares;
	ClassDeclareHolder(const ClassDeclareHolder& base) = default;
public:
	ClassDeclareHolder(ThreadContext* ctx) throw()  : IObject(ctx), declares(GCUtils<HashMap<String,ClassDeclareHolder::ClassDeclares> >::ins(this, (new(ctx) HashMap<String,ClassDeclareHolder::ClassDeclares>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ClassDeclareHolder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,ClassDeclareHolder::ClassDeclares>* declares;
public:
	AlinousClass* fincClassDeclare(AlinousName* name, AlinousModulePackage* packageName, ThreadContext* ctx) throw() ;
	void addClassDeclare(AlinousClass* clazz, ThreadContext* ctx) throw() ;
	HashMap<String,ClassDeclareHolder::ClassDeclares>* getDeclares(ThreadContext* ctx) throw() ;
private:
	AlinousClass* findClassDeclareByName(String* name, ThreadContext* ctx) throw() ;
	AlinousClass* findClassDeclareInPackage(String* name, String* packageName, ThreadContext* ctx) throw() ;
public:



	class ClassDeclares final : public virtual IObject {
	public:
		ClassDeclares(const ClassDeclares& base) = default;
	public:
		ClassDeclares(ThreadContext* ctx) throw()  : IObject(ctx), declares(GCUtils<HashMap<String,AlinousClass> >::ins(this, (new(ctx) HashMap<String,AlinousClass>(ctx)), ctx, __FILEW__, __LINE__, L""))
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~ClassDeclares() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		HashMap<String,AlinousClass>* declares;
	public:
		void addClassDeclare(AlinousClass* clazz, ThreadContext* ctx) throw() ;
		AlinousClass* get(String* name, ThreadContext* ctx) throw() ;
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
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_CLASSDECLAREHOLDER_H_ */
