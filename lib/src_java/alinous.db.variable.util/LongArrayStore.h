#ifndef ALINOUS_DB_VARIABLE_UTIL_LONGARRAYSTORE_H_
#define ALINOUS_DB_VARIABLE_UTIL_LONGARRAYSTORE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace io {
class DiskCacheManager;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace btree {
class LongKey;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace variable {namespace util {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::IOException;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::LongKey;
using ::alinous::db::AlinousDatabase;
using ::alinous::io::DiskCacheManager;
using ::alinous::system::AlinousException;



class LongArrayStore final : public virtual IObject {
public:
	LongArrayStore(const LongArrayStore& base) = default;
public:
	LongArrayStore(DiskCacheManager* diskCache, File* file, int storageCapacity, AlinousDatabase* database, ThreadContext* ctx);
	void __construct_impl(DiskCacheManager* diskCache, File* file, int storageCapacity, AlinousDatabase* database, ThreadContext* ctx);
	virtual ~LongArrayStore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* tree;
public:
	void addLong(long long value, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_VARIABLE_UTIL_LONGARRAYSTORE_H_ */
