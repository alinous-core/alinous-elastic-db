#ifndef COM_GOOGLE_RE2J_RE2_H_
#define COM_GOOGLE_RE2J_RE2_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class RE2;}}}

namespace com {namespace google {namespace re2j {
class Prog;}}}

namespace com {namespace google {namespace re2j {
class Regexp;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class IllegalStateException;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace com {namespace google {namespace re2j {
class Machine;}}}

namespace com {namespace google {namespace re2j {
class MachineInput;}}}

namespace java {namespace lang {
class CharSequence;}}

namespace java {namespace util {
template <typename  T> class List;}}

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
using ::java::io::UnsupportedEncodingException;
using ::java::util::ArrayList;
using ::java::util::Arrays;
using ::java::util::List;



class RE2 final : public virtual IObject {
public:
	class ReplaceFunc;
	class DeliverFunc;
	RE2(const RE2& base) = default;
public:
	RE2(String* expr, ThreadContext* ctx);
	void __construct_impl(String* expr, ThreadContext* ctx);
	RE2(String* expr, Prog* prog, int numSubexp, bool longest, ThreadContext* ctx) throw() ;
	void __construct_impl(String* expr, Prog* prog, int numSubexp, bool longest, ThreadContext* ctx) throw() ;
	virtual ~RE2() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* expr;
	Prog* prog;
	int cond;
	int numSubexp;
	bool longest;
	String* prefix;
	IArrayObjectPrimitive<char>* prefixUTF8;
	bool prefixComplete;
	int prefixRune;
private:
	List<Machine>* machine;
public:
	constexpr static const int FOLD_CASE{0x01};
	constexpr static const int LITERAL{0x02};
	constexpr static const int CLASS_NL{0x04};
	constexpr static const int DOT_NL{0x08};
	constexpr static const int ONE_LINE{0x10};
	constexpr static const int NON_GREEDY{0x20};
	constexpr static const int PERL_X{0x40};
	constexpr static const int UNICODE_GROUPS{0x80};
	constexpr static const int WAS_DOLLAR{0x100};
	constexpr static const int MATCH_NL{CLASS_NL | DOT_NL};
	constexpr static const int PERL{CLASS_NL | ONE_LINE | PERL_X | UNICODE_GROUPS};
	constexpr static const int POSIX{0};
	constexpr static const int UNANCHORED{0};
	constexpr static const int ANCHOR_START{1};
	constexpr static const int ANCHOR_BOTH{2};
public:
	String* toString(ThreadContext* ctx) throw() ;
	int numberOfCapturingGroups(ThreadContext* ctx) throw() ;
	Machine* get(ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	void put(Machine* m, ThreadContext* ctx) throw() ;
	bool match(CharSequence* s, ThreadContext* ctx) throw() ;
	bool match(CharSequence* input, int start, int end, int anchor, IArrayObjectPrimitive<int>* group, int ngroup, ThreadContext* ctx) throw() ;
	bool matchUTF8(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	String* replaceAll(String* src, String* repl, ThreadContext* ctx) throw() ;
	String* replaceFirst(String* src, String* repl, ThreadContext* ctx) throw() ;
	String* replaceAllFunc(String* src, RE2::ReplaceFunc* repl, int maxReplaces, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<char>* findUTF8(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<int>* findUTF8Index(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	String* find(String* s, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<int>* findIndex(String* s, ThreadContext* ctx) throw() ;
	IArrayObject<IArrayObjectPrimitive<char>>* findUTF8Submatch(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<int>* findUTF8SubmatchIndex(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	IArrayObject<String>* findSubmatch(String* s, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<int>* findSubmatchIndex(String* s, ThreadContext* ctx) throw() ;
	List<IArrayObjectPrimitive<char>>* findAllUTF8(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() ;
	List<IArrayObjectPrimitive<int>>* findAllUTF8Index(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() ;
	List<String>* findAll(String* s, int n, ThreadContext* ctx) throw() ;
	List<IArrayObjectPrimitive<int>>* findAllIndex(String* s, int n, ThreadContext* ctx) throw() ;
	List<IArrayObject<IArrayObjectPrimitive<char>>>* findAllUTF8Submatch(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() ;
	List<IArrayObjectPrimitive<int>>* findAllUTF8SubmatchIndex(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() ;
	List<IArrayObject<String>>* findAllSubmatch(String* s, int n, ThreadContext* ctx) throw() ;
	List<IArrayObjectPrimitive<int>>* findAllSubmatchIndex(String* s, int n, ThreadContext* ctx) throw() ;
private:
	IArrayObjectPrimitive<int>* doExecute(MachineInput* in, int pos, int anchor, int ncap, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<int>* pad(IArrayObjectPrimitive<int>* a, ThreadContext* ctx) throw() ;
	void allMatches(MachineInput* input, int n, RE2::DeliverFunc* deliver, ThreadContext* ctx) throw() ;
public:
	static RE2* compile(String* expr, ThreadContext* ctx);
	static RE2* compilePOSIX(String* expr, ThreadContext* ctx);
	static RE2* compileImpl(String* expr, int mode, bool longest, ThreadContext* ctx);
	static bool match(String* pattern, CharSequence* s, ThreadContext* ctx);
	static String* quoteMeta(String* s, ThreadContext* ctx) throw() ;
public:



	class ReplaceFunc : public virtual IObject {
	public:
		ReplaceFunc(const ReplaceFunc& base) = default;
	public:
		ReplaceFunc(ThreadContext* ctx) throw()  : IObject(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~ReplaceFunc() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		virtual String* replace(String* orig, ThreadContext* ctx) throw()  = 0;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class DeliverFunc : public virtual IObject {
	public:
		DeliverFunc(const DeliverFunc& base) = default;
	public:
		DeliverFunc(ThreadContext* ctx) throw()  : IObject(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~DeliverFunc() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		virtual void deliver(IArrayObjectPrimitive<int>* x, ThreadContext* ctx) throw()  = 0;
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

class RE2Anonimous0 : public RE2::ReplaceFunc {
public:
	RE2Anonimous0(String* repl, ThreadContext* ctx);
	virtual ~RE2Anonimous0() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	String* repl;
	void __init(ThreadContext* ctx) throw();
	String* replace(String* orig, ThreadContext* ctx) throw();
};
class RE2Anonimous1 : public RE2::ReplaceFunc {
public:
	RE2Anonimous1(String* repl, ThreadContext* ctx);
	virtual ~RE2Anonimous1() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	String* repl;
	void __init(ThreadContext* ctx) throw();
	String* replace(String* orig, ThreadContext* ctx) throw();
};
class RE2Anonimous2 : public RE2::DeliverFunc {
public:
	RE2Anonimous2(List<IArrayObjectPrimitive<char>>* result, IArrayObjectPrimitive<char>* b, ThreadContext* ctx);
	virtual ~RE2Anonimous2() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<IArrayObjectPrimitive<char>>* result;
	IArrayObjectPrimitive<char>* b;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
class RE2Anonimous3 : public RE2::DeliverFunc {
public:
	RE2Anonimous3(List<IArrayObjectPrimitive<int>>* result, IArrayObjectPrimitive<char>* b, ThreadContext* ctx);
	virtual ~RE2Anonimous3() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<IArrayObjectPrimitive<int>>* result;
	IArrayObjectPrimitive<char>* b;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
class RE2Anonimous4 : public RE2::DeliverFunc {
public:
	RE2Anonimous4(List<String>* result, String* s, ThreadContext* ctx);
	virtual ~RE2Anonimous4() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<String>* result;
	String* s;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
class RE2Anonimous5 : public RE2::DeliverFunc {
public:
	RE2Anonimous5(List<IArrayObjectPrimitive<int>>* result, ThreadContext* ctx);
	virtual ~RE2Anonimous5() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<IArrayObjectPrimitive<int>>* result;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
class RE2Anonimous6 : public RE2::DeliverFunc {
public:
	RE2Anonimous6(List<IArrayObject<IArrayObjectPrimitive<char>>>* result, IArrayObjectPrimitive<char>* b, ThreadContext* ctx);
	virtual ~RE2Anonimous6() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<IArrayObject<IArrayObjectPrimitive<char>>>* result;
	IArrayObjectPrimitive<char>* b;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
class RE2Anonimous7 : public RE2::DeliverFunc {
public:
	RE2Anonimous7(List<IArrayObjectPrimitive<int>>* result, ThreadContext* ctx);
	virtual ~RE2Anonimous7() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<IArrayObjectPrimitive<int>>* result;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
class RE2Anonimous8 : public RE2::DeliverFunc {
public:
	RE2Anonimous8(List<IArrayObject<String>>* result, String* s, ThreadContext* ctx);
	virtual ~RE2Anonimous8() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<IArrayObject<String>>* result;
	String* s;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
class RE2Anonimous9 : public RE2::DeliverFunc {
public:
	RE2Anonimous9(List<IArrayObjectPrimitive<int>>* result, ThreadContext* ctx);
	virtual ~RE2Anonimous9() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	List<IArrayObjectPrimitive<int>>* result;
	void __init(ThreadContext* ctx) throw();
	void deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw();
};
}}}

#endif /* end of COM_GOOGLE_RE2J_RE2_H_ */
