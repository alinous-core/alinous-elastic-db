#ifndef COM_GOOGLE_RE2J_COMPILER_H_
#define COM_GOOGLE_RE2J_COMPILER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class Prog;}}}

namespace com {namespace google {namespace re2j {
class Regexp;}}}

namespace com {namespace google {namespace re2j {
class Compiler;}}}

namespace com {namespace google {namespace re2j {
class Inst;}}}

namespace java {namespace lang {
class IllegalStateException;}}

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



class Compiler final : public virtual IObject {
public:
	class Frag;
	Compiler(const Compiler& base) = default;
public:
	Compiler(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Compiler() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Prog* prog;
private:
	static const StaticArrayObjectPrimitive<int> __ANY_RUNE_NOT_NL;
	static IArrayObjectPrimitive<int>* ANY_RUNE_NOT_NL;
	static const StaticArrayObjectPrimitive<int> __ANY_RUNE;
	static IArrayObjectPrimitive<int>* ANY_RUNE;
private:
	Compiler::Frag* newInst(Inst::Op op, ThreadContext* ctx) throw() ;
	Compiler::Frag* nop(ThreadContext* ctx) throw() ;
	Compiler::Frag* fail(ThreadContext* ctx) throw() ;
	Compiler::Frag* cap(int arg, ThreadContext* ctx) throw() ;
	Compiler::Frag* cat(Compiler::Frag* f1, Compiler::Frag* f2, ThreadContext* ctx) throw() ;
	Compiler::Frag* alt(Compiler::Frag* f1, Compiler::Frag* f2, ThreadContext* ctx) throw() ;
	Compiler::Frag* quest(Compiler::Frag* f1, bool nongreedy, ThreadContext* ctx) throw() ;
	Compiler::Frag* star(Compiler::Frag* f1, bool nongreedy, ThreadContext* ctx) throw() ;
	Compiler::Frag* plus(Compiler::Frag* f1, bool nongreedy, ThreadContext* ctx) throw() ;
	Compiler::Frag* empty(int op, ThreadContext* ctx) throw() ;
	Compiler::Frag* rune(int _rune, int flags, ThreadContext* ctx) throw() ;
	Compiler::Frag* rune(IArrayObjectPrimitive<int>* runes, int flags, ThreadContext* ctx) throw() ;
	Compiler::Frag* compile(Regexp* re, ThreadContext* ctx) throw() ;
public:
	static Prog* compileRegexp(Regexp* re, ThreadContext* ctx) throw() ;
public:



	class Frag final : public virtual IObject {
	public:
		Frag(const Frag& base) = default;
	public:
		Frag(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		Frag(int i, ThreadContext* ctx) throw() ;
		void __construct_impl(int i, ThreadContext* ctx) throw() ;
		Frag(int i, int out, ThreadContext* ctx) throw() ;
		void __construct_impl(int i, int out, ThreadContext* ctx) throw() ;
		virtual ~Frag() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		int i;
		int out;
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

#endif /* end of COM_GOOGLE_RE2J_COMPILER_H_ */
