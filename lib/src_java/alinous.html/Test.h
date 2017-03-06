#ifndef ALINOUS_HTML_TEST_H_
#define ALINOUS_HTML_TEST_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class AlinousDomReplacer;}}

namespace alinous {namespace html {
class DomConverter;}}

namespace alinous {namespace html {
class DomDocument;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace io {
class File;}}

namespace java {namespace io {
class FileInputStream;}}

namespace java {namespace io {
class InputStreamReader;}}

namespace java {namespace io {
class FileNotFoundException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::FileInputStream;
using ::java::io::FileNotFoundException;
using ::java::io::IOException;
using ::java::io::InputStreamReader;



class Test final : public virtual IObject {
public:
	Test(const Test& base) = default;
public:
	Test(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Test() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static void main(IArrayObject<String>* args, ThreadContext* ctx) throw() ;
private:
	static String* readAllText(String* srcPath, String* encode, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_HTML_TEST_H_ */
