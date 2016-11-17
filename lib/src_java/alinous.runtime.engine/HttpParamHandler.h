#ifndef ALINOUS_RUNTIME_ENGINE_HTTPPARAMHANDLER_H_
#define ALINOUS_RUNTIME_ENGINE_HTTPPARAMHANDLER_H_
namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpParameter;}}}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpArrayParameter;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomArray;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpUploadParameter;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace web {namespace htmlxml {
class AlinousAttrs;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::alinous::compile::expression::DomNameSegment;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::DomArray;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::server::http::params::AbstractHttpParameter;
using ::alinous::server::http::params::HttpArrayParameter;
using ::alinous::server::http::params::HttpParameter;
using ::alinous::server::http::params::HttpUploadParameter;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::AlinousAttrs;



class HttpParamHandler final : public virtual IObject {
public:
	class ParamResult;
	HttpParamHandler(const HttpParamHandler& base) = default;
public:
	HttpParamHandler(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~HttpParamHandler() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int STRING_VALUE{0};
	constexpr static const int BYTE_VALUE{1};
	constexpr static const int SHORT_VALUE{2};
	constexpr static const int CHAR_VALUE{3};
	constexpr static const int INT_VALUE{4};
	constexpr static const int LONG_VALUE{5};
	constexpr static const int FLOAT_VALUE{6};
	constexpr static const int DOUBLE_VALUE{7};
public:
	static void handleNormalParam(ScriptMachine* machine, HttpParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx);
	static void handleArrayParam(ScriptMachine* machine, HttpArrayParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx);
	static void handleFileParam(ScriptMachine* machine, HttpUploadParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx) throw() ;
private:
	static HttpParamHandler::ParamResult* getStringType(String* strValue, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx) throw() ;
	static HttpParamHandler::ParamResult* handleAlinousType(String* strValue, String* typeValue, ThreadContext* ctx) throw() ;
	static IDomVariable* toVariable(int alnsType, String* valStr, ThreadContext* ctx) throw() ;
	static int handleAlinousTypeOnly(String* typeValue, ThreadContext* ctx) throw() ;
public:



	class ParamResult final : public virtual IObject {
	public:
		ParamResult(const ParamResult& base) = default;
	public:
		ParamResult(ThreadContext* ctx) throw()  : IObject(ctx), type(0), str(nullptr), byteValue(0), shortValue(0), charValue(0), intValue(0), longValue(0), floatValue(0), doubleValue(0)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~ParamResult() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		int type;
		String* str;
		char byteValue;
		short shortValue;
		wchar_t charValue;
		int intValue;
		long long longValue;
		float floatValue;
		double doubleValue;
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

#endif /* end of ALINOUS_RUNTIME_ENGINE_HTTPPARAMHANDLER_H_ */
