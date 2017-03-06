#ifndef COM_GOOGLE_RE2J_MACHINEINPUT_H_
#define COM_GOOGLE_RE2J_MACHINEINPUT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class MachineInput;}}}

namespace com {namespace google {namespace re2j {
class UTF8Input;}}}

namespace java {namespace lang {
class CharSequence;}}

namespace com {namespace google {namespace re2j {
class UTF16Input;}}}

namespace com {namespace google {namespace re2j {
class RE2;}}}

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



class MachineInput : public virtual IObject {
public:
	MachineInput(const MachineInput& base) = default;
public:
	MachineInput(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~MachineInput() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int _EOF{-8};
public:
	virtual int step(int pos, ThreadContext* ctx) throw()  = 0;
	virtual bool canCheckPrefix(ThreadContext* ctx) throw()  = 0;
	virtual int index(RE2* re2, int pos, ThreadContext* ctx) throw()  = 0;
	virtual int context(int pos, ThreadContext* ctx) throw()  = 0;
	virtual int endPos(ThreadContext* ctx) throw()  = 0;
public:
	static MachineInput* fromUTF8(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() ;
	static MachineInput* fromUTF8(IArrayObjectPrimitive<char>* b, int start, int end, ThreadContext* ctx) throw() ;
	static MachineInput* fromUTF16(CharSequence* s, ThreadContext* ctx) throw() ;
	static MachineInput* fromUTF16(CharSequence* s, int start, int end, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_MACHINEINPUT_H_ */
