#ifndef ALINOUS_BUFFER_STORAGE_FILESTORAGE_H_
#define ALINOUS_BUFFER_STORAGE_FILESTORAGE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace io {
class DiskCacheManager;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace concurrent {
class Mutex;}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryWriter;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryReader;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageBlock;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace io {
class ConcurrentFileAccess;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace buffer {namespace storage {
class IFileStorage;}}}

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
using ::java::io::File;
using ::java::io::IOException;
using ::java::nio::ByteBuffer;
using ::alinous::concurrent::Mutex;
using ::alinous::io::ConcurrentFileAccess;
using ::alinous::io::DiskCacheManager;
using ::alinous::lock::ConcurrentGate;



class FileStorage final : public IFileStorage, public virtual IObject {
public:
	FileStorage(const FileStorage& base) = default;
public:
	FileStorage(DiskCacheManager* diskCache, File* f, String* mode, ThreadContext* ctx) throw() ;
	void __construct_impl(DiskCacheManager* diskCache, File* f, String* mode, ThreadContext* ctx) throw() ;
	virtual ~FileStorage() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int hashCode;
private:
	DiskCacheManager* diskCache;
	ConcurrentFileAccess* rfile;
	File* file;
	String* mode;
	long long totalSize;
	long long currentPosition;
	long long serialOid;
	long long freeScanEntry;
	long long numBlocks;
	long long BLOCK_SIZE;
	bool opened;
	Mutex* allocationLock;
	ConcurrentGate* gate;
public:
	constexpr static const int DATA_BEGIN{128};
public:
	bool isCreated(ThreadContext* ctx) throw() ;
	FileStorageEntryWriter* getWriter(ThreadContext* ctx);
	FileStorageEntryReader* getReader(ThreadContext* ctx);
	void flush(IArrayObjectPrimitive<char>* data, int len, long long startFilePosition, ThreadContext* ctx) throw()  final;
	long long alloc(long long totalBytes, FileStorageBlock* block, FileStorageBlock* block2, ThreadContext* ctx) final;
	void updateEntry(FileStorageEntry* entry, FileStorageBlock* block, FileStorageBlock* block2, FileStorageBlock* block3, ThreadContext* ctx) final;
	void removeEntryBlocks(long long position, FileStorageBlock* workBlock, ThreadContext* ctx);
	void getFirstEntry(FileStorageEntry* entry, FileStorageBlock* workBlock, ThreadContext* ctx) final;
	void loadBlocks(long long position, FileStorageEntry* entry, FileStorageBlock* workBlock, ThreadContext* ctx) final;
	ConcurrentFileAccess* getFileAccess(ThreadContext* ctx) throw()  final;
	void syncStatus(ThreadContext* ctx);
	bool isOpened(ThreadContext* ctx) throw()  final;
	void open(ThreadContext* ctx) final;
	void createStorage(long long capacity, long long BLOCK_SIZE, ThreadContext* ctx);
	void close(ThreadContext* ctx) throw()  final;
	long long getTotalSize(ThreadContext* ctx) throw() ;
	long long getCurrentPosition(ThreadContext* ctx) throw() ;
	long long getlastOid(ThreadContext* ctx) throw() ;
	long long newOid(ThreadContext* ctx) throw()  final;
	long long getNextOid(ThreadContext* ctx) throw() ;
	long long getFreeScanEntry(ThreadContext* ctx) throw() ;
	long long getNumBlocks(ThreadContext* ctx) throw() ;
	long long getBLOCK_SIZE(ThreadContext* ctx) throw()  final;
	ConcurrentGate* getGate(ThreadContext* ctx) throw()  final;
	void writeLong(long long value, ThreadContext* ctx);
	void writeByte(char value, ThreadContext* ctx);
	void writeBytes(IArrayObjectPrimitive<char>* values, ThreadContext* ctx);
	IArrayObjectPrimitive<char>* readBytes(int len, ThreadContext* ctx);
	char readByte(ThreadContext* ctx);
	long long readLong(ThreadContext* ctx);
	void seek(long long position, ThreadContext* ctx);
private:
	long long allocSingleBlockEntry(long long totalBytes, FileStorageBlock* block, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILESTORAGE_H_ */
