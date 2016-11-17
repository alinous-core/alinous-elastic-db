#ifndef JAVA_IO_FILTERINPUTSTREAM_H_
#define JAVA_IO_FILTERINPUTSTREAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class InputStream;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace io {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class FilterInputStream : public InputStream {
public:
	FilterInputStream(const FilterInputStream& base) = default;
public:
	FilterInputStream(InputStream* in, ThreadContext* ctx) throw() ;
	void __construct_impl(InputStream* in, ThreadContext* ctx) throw() ;
	virtual ~FilterInputStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	InputStream* in;
public:
	virtual int available(ThreadContext* ctx);
	virtual void close(ThreadContext* ctx);
	virtual void mark(int readlimit, ThreadContext* ctx) throw() ;
	virtual bool markSupported(ThreadContext* ctx) throw() ;
	virtual int read(ThreadContext* ctx);
	int read(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx);
	virtual int read(IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx);
	virtual void reset(ThreadContext* ctx);
	virtual long long skip(long long count, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_IO_FILTERINPUTSTREAM_H_ */
