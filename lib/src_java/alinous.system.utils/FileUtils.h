#ifndef ALINOUS_SYSTEM_UTILS_FILEUTILS_H_
#define ALINOUS_SYSTEM_UTILS_FILEUTILS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
template <typename  T> class Stack;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace io {
class File;}}

namespace java {namespace io {
class FileInputStream;}}

namespace java {namespace io {
class InputStreamReader;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace utils {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::FileInputStream;
using ::java::io::IOException;
using ::java::io::InputStreamReader;
using ::java::util::Iterator;
using ::java::util::Stack;



class FileUtils final : public virtual IObject {
public:
	FileUtils(const FileUtils& base) = default;
public:
	FileUtils(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FileUtils() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* removeLastSegments(String* formattedpath, int count, ThreadContext* ctx) throw() ;
	static String* formatAfterAbsolutePath(String* path, ThreadContext* ctx) throw() ;
	static void removeAll(File* file, ThreadContext* ctx) throw() ;
	static String* readAllText(String* srcPath, String* encode, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SYSTEM_UTILS_FILEUTILS_H_ */
