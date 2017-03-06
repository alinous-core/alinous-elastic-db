#ifndef JAVA_IO_BUFFEREDOUTPUTSTREAM_H_
#define JAVA_IO_BUFFEREDOUTPUTSTREAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class OutputStream;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace io {
class FilterOutputStream;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace io {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class BufferedOutputStream final : public FilterOutputStream {
public:
	BufferedOutputStream(const BufferedOutputStream& base) = default;
public:
	BufferedOutputStream(OutputStream* out, ThreadContext* ctx) throw() ;
	void __construct_impl(OutputStream* out, ThreadContext* ctx) throw() ;
	BufferedOutputStream(OutputStream* out, int size, ThreadContext* ctx) throw() ;
	void __construct_impl(OutputStream* out, int size, ThreadContext* ctx) throw() ;
	virtual ~BufferedOutputStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IArrayObjectPrimitive<char>* buf;
	int count;
public:
	void flush(ThreadContext* ctx) final;
	void write(IArrayObjectPrimitive<char>* buffer, int offset, int length, ThreadContext* ctx) final;
	void close(ThreadContext* ctx) final;
	void write(int oneByte, ThreadContext* ctx) final;
private:
	void flushInternal(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_IO_BUFFEREDOUTPUTSTREAM_H_ */
