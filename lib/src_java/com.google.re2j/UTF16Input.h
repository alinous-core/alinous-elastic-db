#ifndef COM_GOOGLE_RE2J_UTF16INPUT_H_
#define COM_GOOGLE_RE2J_UTF16INPUT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class CharSequence;}}

namespace com {namespace google {namespace re2j {
class RE2;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace com {namespace google {namespace re2j {
class MachineInput;}}}

namespace alinous {
class ThreadContext;
}

namespace com {namespace google {namespace re2j {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class UTF16Input final : public MachineInput {
public:
	UTF16Input(const UTF16Input& base) = default;
public:
	UTF16Input(CharSequence* str, int start, int end, ThreadContext* ctx) throw() ;
	void __construct_impl(CharSequence* str, int start, int end, ThreadContext* ctx) throw() ;
	virtual ~UTF16Input() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	CharSequence* str;
	int start;
	int end;
public:
	int step(int pos, ThreadContext* ctx) throw()  final;
	bool canCheckPrefix(ThreadContext* ctx) throw()  final;
	int index(RE2* re2, int pos, ThreadContext* ctx) throw()  final;
	int context(int pos, ThreadContext* ctx) throw()  final;
	int endPos(ThreadContext* ctx) throw()  final;
private:
	int indexOf(CharSequence* hayStack, String* needle, int pos, ThreadContext* ctx) throw() ;
	int indexOfFallback(CharSequence* hayStack, String* needle, int fromIndex, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_UTF16INPUT_H_ */
