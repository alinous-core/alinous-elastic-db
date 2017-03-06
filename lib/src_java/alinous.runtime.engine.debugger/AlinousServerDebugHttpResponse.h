#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSSERVERDEBUGHTTPRESPONSE_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSSERVERDEBUGHTTPRESPONSE_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {
class Attribute;}}

namespace java {namespace io {
class InputStream;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace html {
class AlinousDomReplacer;}}

namespace alinous {namespace html {
class DomConverter;}}

namespace alinous {namespace html {
class DomDocument;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::java::util::List;
using ::alinous::html::AlinousDomReplacer;
using ::alinous::html::Attribute;
using ::alinous::html::DomConverter;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;



class AlinousServerDebugHttpResponse final : public virtual IObject {
public:
	AlinousServerDebugHttpResponse(const AlinousServerDebugHttpResponse& base) = default;
public:
	AlinousServerDebugHttpResponse(int result, ThreadContext* ctx) throw() ;
	void __construct_impl(int result, ThreadContext* ctx) throw() ;
	virtual ~AlinousServerDebugHttpResponse() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int result;
	List<DebugThread>* threadList;
	bool shutdown;
	long long hotThread;
public:
	static String* TAG_ROOT;
	static String* TAG_HOT_THREAD;
	static String* ATTR_THREAD_ID;
public:
	int getResult(ThreadContext* ctx) throw() ;
	List<DebugThread>* getThreadList(ThreadContext* ctx) throw() ;
	void addThread(DebugThread* thread, ThreadContext* ctx) throw() ;
	String* exportAsXml(ThreadContext* ctx) throw() ;
	void importFromXmlString(InputStream* inStream, ThreadContext* ctx);
	bool isShutdown(ThreadContext* ctx) throw() ;
	void setShutdown(bool shutdown, ThreadContext* ctx) throw() ;
	long long getHotThread(ThreadContext* ctx) throw() ;
	void setHotThread(long long hotThread, ThreadContext* ctx) throw() ;
	bool containsThread(long long threadId, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSSERVERDEBUGHTTPRESPONSE_H_ */
