#ifndef ALINOUS_COMPILE_TOKEN_H_
#define ALINOUS_COMPILE_TOKEN_H_
namespace alinous {namespace compile {
class Token;}}

namespace java {namespace io {
class Serializable;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class Token final : public java::io::Serializable, public virtual IObject {
public:
	Token(const Token& base) = default;
public:
	Token(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	Token(int kind, ThreadContext* ctx) throw() ;
	void __construct_impl(int kind, ThreadContext* ctx) throw() ;
	Token(int kind, String* image, ThreadContext* ctx) throw() ;
	void __construct_impl(int kind, String* image, ThreadContext* ctx) throw() ;
	virtual ~Token() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int kind;
	int beginLine;
	int beginColumn;
	int endLine;
	int endColumn;
	String* image;
	Token* next;
	Token* specialToken;
private:
	constexpr static const long long serialVersionUID{1L};
public:
	IObject* getValue(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static Token* newToken(int ofKind, String* image, ThreadContext* ctx) throw() ;
	static Token* newToken(int ofKind, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_COMPILE_TOKEN_H_ */
