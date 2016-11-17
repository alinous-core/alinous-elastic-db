#ifndef ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYWRITER_H_
#define ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYWRITER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryWriter;}}}

namespace alinous {namespace buffer {namespace storage {
class IFileStorage;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageBlock;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace java {namespace lang {
class Throwable;}}

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



class FileStorageEntryWriter final : public virtual IObject {
public:
	FileStorageEntryWriter(const FileStorageEntryWriter& base) = default;
public:
	FileStorageEntryWriter(ThreadContext* ctx) throw()  : IObject(ctx), storage(nullptr), block(nullptr), block2(nullptr), block3(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~FileStorageEntryWriter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IFileStorage* storage;
private:
	FileStorageBlock* block;
	FileStorageBlock* block2;
	FileStorageBlock* block3;
public:
	FileStorageEntryWriter* init(IFileStorage* storage, ThreadContext* ctx);
	void write(FileStorageEntry* entry, ThreadContext* ctx);
	void end(ThreadContext* ctx) throw() ;
private:
	void insertNewEntry(FileStorageEntry* entry, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYWRITER_H_ */
