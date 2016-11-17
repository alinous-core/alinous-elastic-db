#ifndef ALINOUS_DB_TRX_SCAN_SCANNEDOIDS_H_
#define ALINOUS_DB_TRX_SCAN_SCANNEDOIDS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::db::table::IDatabaseRecord;



class ScannedOids final : public virtual IObject {
public:
	class Oids;
	class OidsArray;
	ScannedOids(const ScannedOids& base) = default;
public:
	ScannedOids(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ScannedOids() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int numHash;
	int numHashMask;
	IArrayObject<OidsArray>* hasheddArray;
public:
	void dispose(ThreadContext* ctx) throw() ;
	void addOid(ScanResultRecord* record, ThreadContext* ctx) throw() ;
	bool contains(ScanResultRecord* record, ThreadContext* ctx) throw() ;
private:
	ScannedOids::OidsArray* getHashedArray(ScannedOids::Oids* oid, ThreadContext* ctx) throw() ;
public:



	class Oids final : public virtual IObject {
	public:
		Oids(const Oids& base) = default;
	public:
		Oids(ScanResultRecord* record, ThreadContext* ctx) throw() ;
		void __construct_impl(ScanResultRecord* record, ThreadContext* ctx) throw() ;
		virtual ~Oids() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		IArrayObjectPrimitive<long long>* oids;
	public:
		bool equals(IObject* other, ThreadContext* ctx) throw() ;
		long long getHash(ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class OidsArray final : public virtual IObject {
	public:
		OidsArray(const OidsArray& base) = default;
	public:
		OidsArray(ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<ScannedOids::Oids> >::ins(this, (new(ctx) ArrayList<ScannedOids::Oids>(ctx)), ctx, __FILEW__, __LINE__, L""))
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~OidsArray() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		ArrayList<ScannedOids::Oids>* list;
	public:
		void addOid(ScannedOids::Oids* oid, ThreadContext* ctx) throw() ;
		bool contains(ScannedOids::Oids* oid, ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_SCANNEDOIDS_H_ */
