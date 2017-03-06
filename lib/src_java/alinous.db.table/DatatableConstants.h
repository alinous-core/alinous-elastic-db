#ifndef ALINOUS_DB_TABLE_DATATABLECONSTANTS_H_
#define ALINOUS_DB_TABLE_DATATABLECONSTANTS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
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



class DatatableConstants : public virtual IObject {
public:
	DatatableConstants(const DatatableConstants& base) = default;
public:
	DatatableConstants(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DatatableConstants() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int capacity{1024};
	constexpr static const int BLOCK_SIZE{128};
	constexpr static const int maxCache{256};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATATABLECONSTANTS_H_ */
