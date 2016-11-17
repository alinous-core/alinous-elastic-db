#ifndef ALINOUS_BUFFER_STORAGE_IFILESTORAGE_H_
#define ALINOUS_BUFFER_STORAGE_IFILESTORAGE_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageBlock;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace io {
class ConcurrentFileAccess;}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

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
using ::alinous::io::ConcurrentFileAccess;
using ::alinous::lock::ConcurrentGate;



class IFileStorage : public virtual IObject {
public:
	IFileStorage(const IFileStorage& base) = default;
public:
	IFileStorage(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IFileStorage() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int SIZE_LONG{8};
	constexpr static const int SIZE_INT{4};
	constexpr static const int SIZE_SHORT{2};
	constexpr static const int SIZE_BYTE{1};
public:
	virtual long long getBLOCK_SIZE(ThreadContext* ctx) throw()  = 0;
	virtual long long newOid(ThreadContext* ctx) throw()  = 0;
	virtual long long alloc(long long totalBytes, FileStorageBlock* block, FileStorageBlock* block2, ThreadContext* ctx) = 0;
	virtual void updateEntry(FileStorageEntry* entry, FileStorageBlock* block, FileStorageBlock* block2, FileStorageBlock* block3, ThreadContext* ctx) = 0;
	virtual void getFirstEntry(FileStorageEntry* entry, FileStorageBlock* workBlock, ThreadContext* ctx) = 0;
	virtual void loadBlocks(long long position, FileStorageEntry* entry, FileStorageBlock* workBlock, ThreadContext* ctx) = 0;
	virtual void open(ThreadContext* ctx) = 0;
	virtual void close(ThreadContext* ctx) throw()  = 0;
	virtual bool isOpened(ThreadContext* ctx) throw()  = 0;
	virtual void flush(IArrayObjectPrimitive<char>* data, int len, long long startFilePosition, ThreadContext* ctx) throw()  = 0;
	virtual ConcurrentFileAccess* getFileAccess(ThreadContext* ctx) throw()  = 0;
	virtual ConcurrentGate* getGate(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_IFILESTORAGE_H_ */
