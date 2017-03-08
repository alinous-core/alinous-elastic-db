#ifndef COM_GOOGLE_RE2J_CHARCLASS_H_
#define COM_GOOGLE_RE2J_CHARCLASS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class CharClass;}}}

namespace com {namespace google {namespace re2j {
class CharGroup;}}}

namespace java {namespace lang {
class StringBuilder;}}

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



class CharClass final : public virtual IObject {
public:
	CharClass(const CharClass& base) = default;
public:
	CharClass(IArrayObjectPrimitive<int>* r, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<int>* r, ThreadContext* ctx) throw() ;
	CharClass(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CharClass() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IArrayObjectPrimitive<int>* r;
	int len;
public:
	String* toString(ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<int>* toArray(ThreadContext* ctx) throw() ;
	CharClass* cleanClass(ThreadContext* ctx) throw() ;
	CharClass* appendLiteral(int x, int flags, ThreadContext* ctx) throw() ;
	CharClass* appendRange(int lo, int hi, ThreadContext* ctx) throw() ;
	CharClass* appendFoldedRange(int lo, int hi, ThreadContext* ctx) throw() ;
	CharClass* appendClass(IArrayObjectPrimitive<int>* x, ThreadContext* ctx) throw() ;
	CharClass* appendFoldedClass(IArrayObjectPrimitive<int>* x, ThreadContext* ctx) throw() ;
	CharClass* appendNegatedClass(IArrayObjectPrimitive<int>* x, ThreadContext* ctx) throw() ;
	CharClass* appendTable(IArrayObject<IArrayObjectPrimitive<int>>* table, ThreadContext* ctx) throw() ;
	CharClass* appendNegatedTable(IArrayObject<IArrayObjectPrimitive<int>>* table, ThreadContext* ctx) throw() ;
	CharClass* appendTableWithSign(IArrayObject<IArrayObjectPrimitive<int>>* table, int sign, ThreadContext* ctx) throw() ;
	CharClass* negateClass(ThreadContext* ctx) throw() ;
	CharClass* appendClassWithSign(IArrayObjectPrimitive<int>* x, int sign, ThreadContext* ctx) throw() ;
	CharClass* appendGroup(CharGroup* g, bool foldCase, ThreadContext* ctx) throw() ;
private:
	void ensureCapacity(int newLen, ThreadContext* ctx) throw() ;
public:
	static String* charClassToString(IArrayObjectPrimitive<int>* r, int len, ThreadContext* ctx) throw() ;
private:
	static int cmp(IArrayObjectPrimitive<int>* array, int i, int pivotFrom, int pivotTo, ThreadContext* ctx) throw() ;
	static void qsortIntPair(IArrayObjectPrimitive<int>* array, int left, int right, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_CHARCLASS_H_ */
