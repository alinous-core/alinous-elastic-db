#ifndef JAVA_IO_STRINGREADER_H_
#define JAVA_IO_STRINGREADER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace io {
class Reader;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace io {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::lock::LockObject;



class StringReader final : public Reader {
public:
	StringReader(const StringReader& base) = default;
public:
	StringReader(String* str, ThreadContext* ctx) throw() ;
	void __construct_impl(String* str, ThreadContext* ctx) throw() ;
	virtual ~StringReader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* str;
	int markpos;
	int pos;
	int count;
	LockObject* lock;
public:
	void close(ThreadContext* ctx) throw()  final;
	void mark(int readLimit, ThreadContext* ctx) final;
	bool markSupported(ThreadContext* ctx) throw()  final;
	int read(ThreadContext* ctx) final;
	int read(IArrayObjectPrimitive<wchar_t>* buf, int offset, int len, ThreadContext* ctx) final;
	bool ready(ThreadContext* ctx) final;
	void reset(ThreadContext* ctx) final;
	long long skip(long long ns, ThreadContext* ctx) final;
private:
	bool isClosed(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_IO_STRINGREADER_H_ */
