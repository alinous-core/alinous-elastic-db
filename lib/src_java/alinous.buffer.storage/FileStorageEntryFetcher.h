#ifndef ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYFETCHER_H_
#define ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYFETCHER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace java {namespace lang {
class StringBuffer;}}

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



class FileStorageEntryFetcher final : public virtual IObject {
public:
	FileStorageEntryFetcher(const FileStorageEntryFetcher& base) = default;
public:
	FileStorageEntryFetcher(FileStorageEntry* entry, ThreadContext* ctx) throw() ;
	void __construct_impl(FileStorageEntry* entry, ThreadContext* ctx) throw() ;
	FileStorageEntryFetcher(IArrayObjectPrimitive<char>* array, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<char>* array, ThreadContext* ctx) throw() ;
	FileStorageEntryFetcher(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FileStorageEntryFetcher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ByteBuffer* buff;
private:
	long long position;
	long long oid;
public:
	void load(FileStorageEntry* entry, ThreadContext* ctx) throw() ;
	void close(ThreadContext* ctx) throw() ;
	long long fetchLong(ThreadContext* ctx) throw() ;
	int fetchInt(ThreadContext* ctx) throw() ;
	short fetchShort(ThreadContext* ctx) throw() ;
	wchar_t fetchChar(ThreadContext* ctx) throw() ;
	char fetchByte(ThreadContext* ctx) throw() ;
	float fetchFloat(ThreadContext* ctx) throw() ;
	double fetchDouble(ThreadContext* ctx) throw() ;
	String* fetchString(ThreadContext* ctx) throw() ;
	long long getPosition(ThreadContext* ctx) throw() ;
	long long getOid(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYFETCHER_H_ */
