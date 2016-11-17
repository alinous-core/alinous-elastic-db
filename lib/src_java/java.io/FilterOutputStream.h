#ifndef JAVA_IO_FILTEROUTPUTSTREAM_H_
#define JAVA_IO_FILTEROUTPUTSTREAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class OutputStream;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace io {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class FilterOutputStream : public OutputStream {
public:
	FilterOutputStream(const FilterOutputStream& base) = default;
public:
	FilterOutputStream(OutputStream* out, ThreadContext* ctx) throw() ;
	void __construct_impl(OutputStream* out, ThreadContext* ctx) throw() ;
	virtual ~FilterOutputStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	OutputStream* out;
public:
	virtual void close(ThreadContext* ctx);
	virtual void flush(ThreadContext* ctx);
	void write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, int offset, int length, ThreadContext* ctx);
	virtual void write(int oneByte, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_IO_FILTEROUTPUTSTREAM_H_ */
