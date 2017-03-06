#ifndef COM_GOOGLE_RE2J_PROG_H_
#define COM_GOOGLE_RE2J_PROG_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class Inst;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace com {namespace google {namespace re2j {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;



class Prog final : public virtual IObject {
public:
	Prog(const Prog& base) = default;
public:
	Prog(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Prog() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int start;
	int numCap;
private:
	List<Inst>* inst;
public:
	String* toString(ThreadContext* ctx) throw() ;
	Inst* getInst(int pc, ThreadContext* ctx) throw() ;
	int numInst(ThreadContext* ctx) throw() ;
	void addInst(Inst::Op op, ThreadContext* ctx) throw() ;
	Inst* skipNop(int pc, ThreadContext* ctx) throw() ;
	bool prefix(StringBuilder* prefix, ThreadContext* ctx) throw() ;
	int startCond(ThreadContext* ctx) throw() ;
	int next(int l, ThreadContext* ctx) throw() ;
	void patch(int l, int val, ThreadContext* ctx) throw() ;
	int append(int l1, int l2, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_PROG_H_ */
