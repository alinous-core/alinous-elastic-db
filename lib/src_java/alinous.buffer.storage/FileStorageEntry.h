#ifndef ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRY_H_
#define ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRY_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace java {namespace nio {
class ByteBuffer;}}

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
using ::java::nio::ByteBuffer;



class FileStorageEntry final : public virtual IObject {
public:
	FileStorageEntry(const FileStorageEntry& base) = default;
public:
	FileStorageEntry(ThreadContext* ctx) throw()  : IObject(ctx), position(0), oid(0), used(0), data(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~FileStorageEntry() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long position;
	long long oid;
	long long used;
	ByteBuffer* data;
public:
	long long getEntrySize(ThreadContext* ctx) throw() ;
	long long getDataSize(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRY_H_ */
