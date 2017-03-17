#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_PREPARESTORAGEMANAGER_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_PREPARESTORAGEMANAGER_H_
namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class PrepareStorageManager final : public virtual IObject {
public:
	PrepareStorageManager(const PrepareStorageManager& base) = default;
public:
	PrepareStorageManager(String* tmpDir, long long strxId, ThreadContext* ctx) throw() ;
	void __construct_impl(String* tmpDir, long long strxId, ThreadContext* ctx) throw() ;
	virtual ~PrepareStorageManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* tmpDir;
	long long strxId;
	String* filePath;
public:
	String* getFilePath(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_PREPARESTORAGEMANAGER_H_ */
