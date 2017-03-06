#ifndef ALINOUS_SYSTEM_ALINOUSEXCEPTION_H_
#define ALINOUS_SYSTEM_ALINOUSEXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;



class AlinousException : public Throwable {
public:
	AlinousException(const AlinousException& base) = default;
public:
	AlinousException(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	AlinousException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	AlinousException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	AlinousException(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	AlinousException(Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~AlinousException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AbstractSrcElement* srcElement;
private:
	constexpr static const long long serialVersionUID{8252938056958734850L};
public:
	AbstractSrcElement* getSrcElement(ThreadContext* ctx) throw() ;
	void setSrcElement(AbstractSrcElement* srcElement, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_SYSTEM_ALINOUSEXCEPTION_H_ */
