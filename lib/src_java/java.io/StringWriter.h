#ifndef JAVA_IO_STRINGWRITER_H_
#define JAVA_IO_STRINGWRITER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace io {
class StringWriter;}}

namespace java {namespace lang {
class CharSequence;}}

namespace java {namespace io {
class Writer;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace io {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class StringWriter final : public Writer {
public:
	StringWriter(const StringWriter& base) = default;
public:
	StringWriter(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	StringWriter(int initialSize, ThreadContext* ctx) throw() ;
	void __construct_impl(int initialSize, ThreadContext* ctx) throw() ;
	virtual ~StringWriter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	StringBuffer* buf;
public:
	static String* TOKEN_NULL;
public:
	void close(ThreadContext* ctx) final;
	void flush(ThreadContext* ctx) throw()  final;
	StringBuffer* getBuffer(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	void write(IArrayObjectPrimitive<wchar_t>* cbuf, int offset, int count, ThreadContext* ctx) throw() ;
	void write(int oneChar, ThreadContext* ctx) throw()  final;
	void write(String* str, ThreadContext* ctx) throw()  final;
	void write(String* str, int offset, int count, ThreadContext* ctx) throw()  final;
	StringWriter* append(wchar_t c, ThreadContext* ctx) throw()  final;
	StringWriter* append(CharSequence* csq, ThreadContext* ctx) throw()  final;
	StringWriter* append(CharSequence* csq, int start, int end, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_IO_STRINGWRITER_H_ */
