#ifndef ALINOUS_DB_TABLE_DATABASETABLEIDPUBLISHER_H_
#define ALINOUS_DB_TABLE_DATABASETABLEIDPUBLISHER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class DatabaseTableIdPublisher;}}}

namespace java {namespace lang {
class Integer;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;



class DatabaseTableIdPublisher final : public virtual IObject {
public:
	DatabaseTableIdPublisher(const DatabaseTableIdPublisher& base) = default;
public:
	DatabaseTableIdPublisher(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DatabaseTableIdPublisher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int tableIdSerial;
	HashMap<String,Integer>* ids;
private:
	static DatabaseTableIdPublisher* instance;
public:
	static int getId(String* name, ThreadContext* ctx) throw() ;
	static String* idToName(int id, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATABASETABLEIDPUBLISHER_H_ */
