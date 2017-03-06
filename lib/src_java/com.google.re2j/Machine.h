#ifndef COM_GOOGLE_RE2J_MACHINE_H_
#define COM_GOOGLE_RE2J_MACHINE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class RE2;}}}

namespace com {namespace google {namespace re2j {
class Inst;}}}

namespace com {namespace google {namespace re2j {
class MachineInput;}}}

namespace java {namespace lang {
class IllegalStateException;}}

namespace com {namespace google {namespace re2j {
class Prog;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace util {
class Arrays;}}

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
using ::java::util::Arrays;
using ::java::util::List;



class Machine final : public virtual IObject {
public:
	class LogicalThread;
	class Entry;
	class Queue;
	Machine(const Machine& base) = default;
public:
	Machine(RE2* re2, ThreadContext* ctx) throw() ;
	void __construct_impl(RE2* re2, ThreadContext* ctx) throw() ;
	virtual ~Machine() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	RE2* re2;
	Prog* prog;
	Machine::Queue* q0; Machine::Queue* q1;
	List<Machine::LogicalThread>* pool;
	bool matched;
	IArrayObjectPrimitive<int>* matchcap;
public:
	void init(int ncap, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<int>* submatches(ThreadContext* ctx) throw() ;
	bool match(MachineInput* in, int pos, int anchor, ThreadContext* ctx) throw() ;
private:
	Machine::LogicalThread* alloc(Inst* inst, ThreadContext* ctx) throw() ;
	void step(Machine::Queue* runq, Machine::Queue* nextq, int pos, int nextPos, int c, int nextCond, int anchor, bool atEnd, ThreadContext* ctx) throw() ;
	Machine::LogicalThread* add(Machine::Queue* q, int pc, int pos, IArrayObjectPrimitive<int>* cap, int cond, Machine::LogicalThread* t, ThreadContext* ctx) throw() ;
public:



	class LogicalThread final : public virtual IObject {
	public:
		LogicalThread(const LogicalThread& base) = default;
	public:
		LogicalThread(int n, ThreadContext* ctx) throw() ;
		void __construct_impl(int n, ThreadContext* ctx) throw() ;
		virtual ~LogicalThread() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IArrayObjectPrimitive<int>* cap;
		Inst* inst;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};




	class Entry final : public virtual IObject {
	public:
		Entry(const Entry& base) = default;
	public:
		Entry(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~Entry() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		int pc;
		Machine::LogicalThread* thread;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};




	class Queue final : public virtual IObject {
	public:
		Queue(const Queue& base) = default;
	public:
		Queue(int n, ThreadContext* ctx) throw() ;
		void __construct_impl(int n, ThreadContext* ctx) throw() ;
		virtual ~Queue() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IArrayObject<Entry>* dense;
		IArrayObjectPrimitive<int>* sparse;
		int size;
	public:
		String* toString(ThreadContext* ctx) throw() ;
		bool contains(int pc, ThreadContext* ctx) throw() ;
		bool isEmpty(ThreadContext* ctx) throw() ;
		Machine::Entry* add(int pc, ThreadContext* ctx) throw() ;
		void clear(List<Machine::LogicalThread>* freePool, ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_MACHINE_H_ */
