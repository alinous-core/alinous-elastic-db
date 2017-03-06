#ifndef ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYREADER_H_
#define ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYREADER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {namespace storage {
class IFileStorage;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageBlock;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace java {namespace lang {
class Throwable;}}

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
using ::alinous::lock::ConcurrentGate;



class FileStorageEntryReader final : public virtual IObject {
public:
	FileStorageEntryReader(const FileStorageEntryReader& base) = default;
public:
	FileStorageEntryReader(IFileStorage* storage, ThreadContext* ctx) throw() ;
	void __construct_impl(IFileStorage* storage, ThreadContext* ctx) throw() ;
	virtual ~FileStorageEntryReader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IFileStorage* storage;
private:
	FileStorageBlock* block;
public:
	FileStorageEntry* readFirstEntry(ThreadContext* ctx);
	FileStorageEntry* read(long long filePointer, ThreadContext* ctx);
	void end(ThreadContext* ctx) throw() ;
private:
	FileStorageEntry* read(long long filePointer, FileStorageEntry* entry, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYREADER_H_ */
