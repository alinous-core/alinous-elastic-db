#ifndef ALINOUS_PARSER_XPATH_JAVACHARSTREAM_H_
#define ALINOUS_PARSER_XPATH_JAVACHARSTREAM_H_
namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class Error;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace io {
class Reader;}}

namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class InputStreamReader;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace parser {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class JavaCharStream final : public virtual IObject {
public:
	JavaCharStream(const JavaCharStream& base) = default;
public:
	JavaCharStream(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() ;
	void __construct_impl(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() ;
	JavaCharStream(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() ;
	void __construct_impl(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() ;
	JavaCharStream(java::io::Reader* dstream, ThreadContext* ctx) throw() ;
	void __construct_impl(java::io::Reader* dstream, ThreadContext* ctx) throw() ;
	JavaCharStream(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx);
	JavaCharStream(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() ;
	void __construct_impl(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() ;
	JavaCharStream(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx);
	JavaCharStream(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() ;
	void __construct_impl(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() ;
	JavaCharStream(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx);
	JavaCharStream(java::io::InputStream* dstream, ThreadContext* ctx) throw() ;
	void __construct_impl(java::io::InputStream* dstream, ThreadContext* ctx) throw() ;
	virtual ~JavaCharStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int bufpos;
	int bufsize;
	int available;
	int tokenBegin;
	IArrayObjectPrimitive<int>* bufline;
	IArrayObjectPrimitive<int>* bufcolumn;
	int column;
	int line;
	bool prevCharIsCR;
	bool prevCharIsLF;
	java::io::Reader* inputStream;
	IArrayObjectPrimitive<wchar_t>* nextCharBuf;
	IArrayObjectPrimitive<wchar_t>* buffer;
	int maxNextCharInd;
	int nextCharInd;
	int inBuf;
	int tabSize;
	bool trackLineColumn;
public:
	constexpr static const bool staticFlag{false};
public:
	void setTabSize(int i, ThreadContext* ctx) throw() ;
	int getTabSize(ThreadContext* ctx) throw() ;
	wchar_t BeginToken(ThreadContext* ctx);
	wchar_t readChar(ThreadContext* ctx);
	int getColumn(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw() ;
	int getEndColumn(ThreadContext* ctx) throw() ;
	int getEndLine(ThreadContext* ctx) throw() ;
	int getBeginColumn(ThreadContext* ctx) throw() ;
	int getBeginLine(ThreadContext* ctx) throw() ;
	void backup(int amount, ThreadContext* ctx) throw() ;
	void ReInit(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() ;
	void ReInit(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() ;
	void ReInit(java::io::Reader* dstream, ThreadContext* ctx) throw() ;
	void ReInit(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx);
	void ReInit(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() ;
	void ReInit(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx);
	void ReInit(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() ;
	void ReInit(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx);
	void ReInit(java::io::InputStream* dstream, ThreadContext* ctx) throw() ;
	String* GetImage(ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<wchar_t>* GetSuffix(int len, ThreadContext* ctx) throw() ;
	void Done(ThreadContext* ctx) throw() ;
	void adjustBeginLineColumn(int newLine, int newCol, ThreadContext* ctx) throw() ;
	void ExpandBuff(bool wrapAround, ThreadContext* ctx) throw() ;
	void FillBuff(ThreadContext* ctx);
	wchar_t ReadByte(ThreadContext* ctx);
	void AdjustBuffSize(ThreadContext* ctx) throw() ;
	void UpdateLineColumn(wchar_t c, ThreadContext* ctx) throw() ;
	bool getTrackLineColumn(ThreadContext* ctx) throw() ;
	void setTrackLineColumn(bool tlc, ThreadContext* ctx) throw() ;
public:
	static int hexval(wchar_t c, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_PARSER_XPATH_JAVACHARSTREAM_H_ */
