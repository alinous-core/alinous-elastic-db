#ifndef ALINOUS_RUNTIME_ALINOUSMODULE_H_
#define ALINOUS_RUNTIME_ALINOUSMODULE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class File;}}

namespace alinous {namespace compile {
class AlinousSrc;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {namespace debug {
class DebugConfigLoader;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptRunner;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace runtime {
class AlinousModuleRepository;}}

namespace alinous {namespace compile {
class IncludePreprocessor;}}

namespace alinous {namespace runtime {namespace engine {
class AlinousNullPointerException;}}}

namespace alinous {namespace runtime {
class AlinousModulePackage;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace alinous {namespace system {namespace utils {
class FileUtils;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::AlinousSrc;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IncludePreprocessor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::AlinousNullPointerException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::ScriptRunner;
using ::alinous::server::debug::DebugConfigLoader;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::utils::FileUtils;



class AlinousModule final : public IAlinousElement {
public:
	class SetUpper;
	class ClassCollector;
	AlinousModule(const AlinousModule& base) = default;
public:
	AlinousModule(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx);
	void __construct_impl(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx);
	AlinousModule(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), packageName(nullptr), path(nullptr), debugPath(nullptr), file(nullptr), compiledTime(0), moduleSource(nullptr), setupper(nullptr), core(nullptr), parent(nullptr), includedModules(GCUtils<ArrayList<AlinousModule> >::ins(this, (new(ctx) ArrayList<AlinousModule>(ctx)), ctx, __FILEW__, __LINE__, L"")), functionMap(GCUtils<HashMap<String,AlinousFunction> >::ins(this, (new(ctx) HashMap<String,AlinousFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousModule() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousModulePackage* packageName;
	String* path;
	String* debugPath;
	File* file;
	long long compiledTime;
	AlinousSrc* moduleSource;
	AlinousModule::SetUpper* setupper;
	AlinousCore* core;
	AlinousModule* parent;
	ArrayList<AlinousModule>* includedModules;
	HashMap<String,AlinousFunction>* functionMap;
public:
	IAlinousVariable* execute(ScriptMachine* machine, bool degug, ThreadContext* ctx);
	IAlinousVariable* execute(bool degug, ThreadContext* ctx);
	AlinousType* getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() ;
	bool isfunctionPrefix(String* name, ThreadContext* ctx) throw() ;
	AlinousFunction* findFunction(String* name, ThreadContext* ctx) throw() ;
	void init(AlinousModuleRepository* moduleRepository, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx);
	AlinousModulePackage* getPackageName(ThreadContext* ctx) throw() ;
	bool isDirty(ThreadContext* ctx) throw() ;
	File* getFile(ThreadContext* ctx) throw() ;
	String* getPath(ThreadContext* ctx) throw() ;
	AlinousSrc* getModuleSource(ThreadContext* ctx) throw() ;
	AlinousModule* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AlinousModule* parent, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
private:
	IAlinousVariable* executeAsScript(ScriptMachine* machine, bool degug, ThreadContext* ctx);
	void analyzeVirtualMethods(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	void analyzeClassDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	void analyseClassDeclare(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	void exportClasses(SrcAnalyseContext* context, ArrayList<String>* once, ThreadContext* ctx) throw() ;
	bool alreadyIncluded(AlinousModule* modinc, ThreadContext* ctx) throw() ;
public:



	class SetUpper final : public IAlinousElementVisitor, public virtual IObject {
	public:
		SetUpper(const SetUpper& base) = default;
	public:
		SetUpper(String* path, String* debugPath, ThreadContext* ctx) throw() ;
		void __construct_impl(String* path, String* debugPath, ThreadContext* ctx) throw() ;
		virtual ~SetUpper() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		String* path;
		String* debugPath;
	public:
		bool visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
		String* getPath(ThreadContext* ctx) throw() ;
		String* getDebugPath(ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class ClassCollector final : public IAlinousElementVisitor, public virtual IObject {
	public:
		ClassCollector(const ClassCollector& base) = default;
	public:
		ClassCollector(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElementVisitor(ctx), list(GCUtils<ArrayList<AlinousClass> >::ins(this, (new(ctx) ArrayList<AlinousClass>(ctx)), ctx, __FILEW__, __LINE__, L""))
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~ClassCollector() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		ArrayList<AlinousClass>* list;
	public:
		bool visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
		ArrayList<AlinousClass>* getClasses(ThreadContext* ctx) throw() ;
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

}}

#endif /* end of ALINOUS_RUNTIME_ALINOUSMODULE_H_ */
