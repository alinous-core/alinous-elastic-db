#ifndef JAVA_IO_BYTEARRAYOUTPUTSTREAM_H_
#define JAVA_IO_BYTEARRAYOUTPUTSTREAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace io {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class ByteArrayOutputStream final : public OutputStream {
public:
	ByteArrayOutputStream(const ByteArrayOutputStream& base) = default;
public:
	ByteArrayOutputStream(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	ByteArrayOutputStream(int size, ThreadContext* ctx) throw() ;
	void __construct_impl(int size, ThreadContext* ctx) throw() ;
	virtual ~ByteArrayOutputStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IArrayObjectPrimitive<char>* buf;
	int count;
public:
	void close(ThreadContext* ctx) final;
	void reset(ThreadContext* ctx) throw() ;
	int size(ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<char>* toByteArray(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	String* toString(int hibyte, ThreadContext* ctx) throw() ;
	String* toString(String* enc, ThreadContext* ctx);
	void write(IArrayObjectPrimitive<char>* buffer, int offset, int len, ThreadContext* ctx) throw() ;
	void write(int oneByte, ThreadContext* ctx) throw()  final;
	void writeTo(OutputStream* out, ThreadContext* ctx);
	void flush(ThreadContext* ctx) throw()  final;
private:
	void expand(int i, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_IO_BYTEARRAYOUTPUTSTREAM_H_ */
