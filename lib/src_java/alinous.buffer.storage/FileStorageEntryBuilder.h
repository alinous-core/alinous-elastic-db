#ifndef ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYBUILDER_H_
#define ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYBUILDER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace nio {
class ByteBuffer;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

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



class FileStorageEntryBuilder final : public virtual IObject {
public:
	FileStorageEntryBuilder(const FileStorageEntryBuilder& base) = default;
public:
	FileStorageEntryBuilder(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	FileStorageEntryBuilder(int cap, ThreadContext* ctx) throw() ;
	void __construct_impl(int cap, ThreadContext* ctx) throw() ;
	virtual ~FileStorageEntryBuilder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ByteBuffer* buff;
public:
	void reset(ThreadContext* ctx) throw() ;
	void reloadBuffer(int cap, ThreadContext* ctx) throw() ;
	void putLong(long long value, ThreadContext* ctx) throw() ;
	void putInt(int value, ThreadContext* ctx) throw() ;
	void putShort(short value, ThreadContext* ctx) throw() ;
	void putChar(wchar_t value, ThreadContext* ctx) throw() ;
	void putFloat(float fl, ThreadContext* ctx) throw() ;
	void putDouble(double dbl, ThreadContext* ctx) throw() ;
	void putBoolean(bool value, ThreadContext* ctx) throw() ;
	void putByte(char value, ThreadContext* ctx) throw() ;
	void putString(String* value, ThreadContext* ctx) throw() ;
	FileStorageEntry* toEntry(ThreadContext* ctx) throw() ;
	FileStorageEntry* toEntry(long long position, ThreadContext* ctx) throw() ;
	FileStorageEntry* toEntry(FileStorageEntry* entry, long long position, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<char>* toBytes(ThreadContext* ctx) throw() ;
private:
	void realloc(int need, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_BUFFER_STORAGE_FILESTORAGEENTRYBUILDER_H_ */
