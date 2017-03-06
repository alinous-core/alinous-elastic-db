#ifndef COM_GOOGLE_RE2J_UTF8INPUT_H_
#define COM_GOOGLE_RE2J_UTF8INPUT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class RE2;}}}

namespace com {namespace google {namespace re2j {
class MachineInput;}}}

namespace alinous {
class ThreadContext;
}

namespace com {namespace google {namespace re2j {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class UTF8Input final : public MachineInput {
public:
	UTF8Input(const UTF8Input& base) = default;
public:
	UTF8Input(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	UTF8Input(IArrayObjectPrimitive<char>* b, int start, int end, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<char>* b, int start, int end, ThreadContext* ctx) throw() ;
	virtual ~UTF8Input() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IArrayObjectPrimitive<char>* b;
	int start;
	int end;
public:
	int step(int i, ThreadContext* ctx) throw()  final;
	bool canCheckPrefix(ThreadContext* ctx) throw()  final;
	int index(RE2* re2, int pos, ThreadContext* ctx) throw()  final;
	int context(int pos, ThreadContext* ctx) throw()  final;
	int endPos(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_UTF8INPUT_H_ */
