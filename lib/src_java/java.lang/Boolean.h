#ifndef JAVA_LANG_BOOLEAN_H_
#define JAVA_LANG_BOOLEAN_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Boolean;}}

namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace lang {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class Boolean final : public virtual IObject {
public:
	Boolean(const Boolean& base) = default;
public:
	Boolean(String* string, ThreadContext* ctx) throw() ;
	void __construct_impl(String* string, ThreadContext* ctx) throw() ;
	Boolean(bool value, ThreadContext* ctx) throw() ;
	void __construct_impl(bool value, ThreadContext* ctx) throw() ;
	virtual ~Boolean() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool value;
public:
	const static Boolean __TRUE;
	constexpr static Boolean* TRUE{const_cast<Boolean*>(&__TRUE)};
	const static Boolean __FALSE;
	constexpr static Boolean* FALSE{const_cast<Boolean*>(&__FALSE)};
public:
	bool booleanValue(ThreadContext* ctx) throw() ;
	bool equals(IObject* o, ThreadContext* ctx) throw() ;
	int compareTo(Boolean* that, ThreadContext* ctx) throw() ;
	int hashCode(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool getBoolean(String* string, ThreadContext* ctx) throw() ;
	static bool parseBoolean(String* s, ThreadContext* ctx) throw() ;
	static String* toString(bool value, ThreadContext* ctx) throw() ;
	static Boolean* valueOf(String* string, ThreadContext* ctx) throw() ;
	static Boolean* valueOf(bool b, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (Boolean* _this, Boolean* that, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_LANG_BOOLEAN_H_ */
