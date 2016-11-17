#ifndef ALINOUS_DB_CONNECTINFO_H_
#define ALINOUS_DB_CONNECTINFO_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class ConnectInfo final : public virtual IObject {
public:
	ConnectInfo(const ConnectInfo& base) = default;
public:
	ConnectInfo(ThreadContext* ctx) throw()  : IObject(ctx), user(nullptr), pass(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ConnectInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* user;
	String* pass;
public:
	String* getUser(ThreadContext* ctx) throw() ;
	void setUser(String* user, ThreadContext* ctx) throw() ;
	String* getPass(ThreadContext* ctx) throw() ;
	void setPass(String* pass, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_CONNECTINFO_H_ */
