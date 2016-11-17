#ifndef ALINOUS_BTREE_BTREEEXCEPTION_H_
#define ALINOUS_BTREE_BTREEEXCEPTION_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class BTreeException final : public Throwable {
public:
	BTreeException(const BTreeException& base) = default;
public:
	BTreeException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	BTreeException(String* string, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* string, Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~BTreeException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{5543015445678120518L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREEEXCEPTION_H_ */
