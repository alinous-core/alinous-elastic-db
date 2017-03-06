#ifndef JAVA_IO_BUFFEREDINPUTSTREAM_H_
#define JAVA_IO_BUFFEREDINPUTSTREAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class InputStream;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace io {
class FilterInputStream;}}

namespace alinous {namespace util {
class Builtin;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace io {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::util::Builtin;



class BufferedInputStream final : public FilterInputStream {
public:
	BufferedInputStream(const BufferedInputStream& base) = default;
public:
	BufferedInputStream(InputStream* in, ThreadContext* ctx) throw() ;
	void __construct_impl(InputStream* in, ThreadContext* ctx) throw() ;
	BufferedInputStream(InputStream* in, int size, ThreadContext* ctx) throw() ;
	void __construct_impl(InputStream* in, int size, ThreadContext* ctx) throw() ;
	virtual ~BufferedInputStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IArrayObjectPrimitive<char>* buf;
	int count;
	int marklimit;
	int markpos;
	int pos;
public:
	int available(ThreadContext* ctx) final;
	void close(ThreadContext* ctx) final;
	void mark(int readlimit, ThreadContext* ctx) throw()  final;
	bool markSupported(ThreadContext* ctx) throw()  final;
	int read(ThreadContext* ctx) final;
	int read(IArrayObjectPrimitive<char>* buffer, int offset, int length, ThreadContext* ctx) final;
	void reset(ThreadContext* ctx) final;
	long long skip(long long amount, ThreadContext* ctx) final;
private:
	int fillbuf(InputStream* localIn, IArrayObjectPrimitive<char>* localBuf, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_IO_BUFFEREDINPUTSTREAM_H_ */
