#ifndef ALINOUS_BUFFER_STORAGE_FILESTORAGEBLOCK_H_
#define ALINOUS_BUFFER_STORAGE_FILESTORAGEBLOCK_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace io {
class ConcurrentFileAccess;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace buffer {namespace storage {
class FileAccessWrapper;}}}

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



class FileStorageBlock final : public virtual IObject {
public:
	FileStorageBlock(const FileStorageBlock& base) = default;
public:
	FileStorageBlock(ConcurrentFileAccess* access, long long BLOCK_SIZE, ThreadContext* ctx) throw() ;
	void __construct_impl(ConcurrentFileAccess* access, long long BLOCK_SIZE, ThreadContext* ctx) throw() ;
	virtual ~FileStorageBlock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long BLOCK_SIZE;
	long long BLOCK_HEADER_OFFSET;
	long long BLOCK_DATA_SIZE;
	short usedBytes;
	long long next;
private:
	ConcurrentFileAccess* access;
	FileAccessWrapper* wraapper;
	long long currentPosition;
public:
	void loadBlock(FileStorage* storage, long long position, ThreadContext* ctx);
	void closeWrapper(ThreadContext* ctx) throw() ;
	void write2Disk(ThreadContext* ctx);
	void close(ThreadContext* ctx) throw() ;
	void resetSize(ThreadContext* ctx) throw() ;
	void syncBlockHeader(FileStorage* storage, ThreadContext* ctx);
	void writeData(FileStorage* storage, long long positionOffset, IArrayObjectPrimitive<char>* data, int offset, int count, ThreadContext* ctx);
	void writeLongData(FileStorage* storage, int offset, long long value, ThreadContext* ctx);
	void writeShortData(FileStorage* storage, int offset, short value, ThreadContext* ctx);
	long long readLong(FileStorage* storage, long long positionOffset, ThreadContext* ctx);
	short readShort(FileStorage* storage, long long positionOffset, ThreadContext* ctx);
	long long read(FileStorage* storage, long long positionOffset, ByteBuffer* bbuff, long long arrayOffset, ThreadContext* ctx);
	bool isFree(ThreadContext* ctx) throw() ;
	bool hasNext(ThreadContext* ctx) throw() ;
	void loadChildNextBlock(FileStorage* storage, ThreadContext* ctx);
	void loadNextBlock(FileStorage* storage, ThreadContext* ctx);
	long long nextBlockPosition(ThreadContext* ctx) throw() ;
	long long getCurrentPosition(ThreadContext* ctx) throw() ;
	void setCurrentPosition(long long currentPosition, ThreadContext* ctx) throw() ;
public:
	static int necessaryBlocks(long long bytes, long long BLOCK_SIZE, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILESTORAGEBLOCK_H_ */
