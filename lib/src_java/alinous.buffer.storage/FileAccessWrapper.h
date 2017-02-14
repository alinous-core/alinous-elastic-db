#ifndef ALINOUS_BUFFER_STORAGE_FILEACCESSWRAPPER_H_
#define ALINOUS_BUFFER_STORAGE_FILEACCESSWRAPPER_H_
namespace alinous {namespace buffer {namespace storage {
class FileAccessWrapper;}}}

namespace alinous {namespace io {
class ConcurrentFileAccess;}}

namespace alinous {namespace io {
class MMapSegment;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace buffer {namespace storage {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::nio::ByteBuffer;
using ::alinous::io::ConcurrentFileAccess;
using ::alinous::io::MMapSegment;



class FileAccessWrapper final : public virtual IObject {
public:
	FileAccessWrapper(const FileAccessWrapper& base) = default;
public:
	FileAccessWrapper(ThreadContext* ctx) throw()  : IObject(ctx), segs(nullptr), fileSize(0), basePosition(0), position(0), buffer(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~FileAccessWrapper() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IArrayObject<MMapSegment>* segs;
	long long fileSize;
	long long basePosition;
	long long position;
	ByteBuffer* buffer;
public:
	FileAccessWrapper* init(ConcurrentFileAccess* access, long long currentPosition, long long blockSize, ThreadContext* ctx);
	void close(ThreadContext* ctx) throw() ;
	long long read(long long position, IArrayObjectPrimitive<char>* buffer, long long offset, int count, ThreadContext* ctx);
	long long write(long long position, IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx);
	void setPosition(int i, ThreadContext* ctx) throw() ;
	void putShort(short value, ThreadContext* ctx);
	void putLong(long long value, ThreadContext* ctx);
	void put(IArrayObjectPrimitive<char>* data, int offset, int count, ThreadContext* ctx);
	short getShort(ThreadContext* ctx);
	long long getLong(ThreadContext* ctx);
	int read(IArrayObjectPrimitive<char>* buffer, long long offset, int count, ThreadContext* ctx);
private:
	MMapSegment* getSegment(long long position, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILEACCESSWRAPPER_H_ */
