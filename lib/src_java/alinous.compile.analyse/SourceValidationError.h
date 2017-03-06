#ifndef ALINOUS_COMPILE_ANALYSE_SOURCEVALIDATIONERROR_H_
#define ALINOUS_COMPILE_ANALYSE_SOURCEVALIDATIONERROR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElement;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::IAlinousElement;



class SourceValidationError final : public virtual IObject {
public:
	SourceValidationError(const SourceValidationError& base) = default;
public:
	SourceValidationError(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~SourceValidationError() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int type;
	String* message;
	IAlinousElement* src;
public:
	constexpr static const int ERROR{1};
	constexpr static const int WARNING{2};
	constexpr static const int INFO{3};
public:
	int getType(ThreadContext* ctx) throw() ;
	void setType(int type, ThreadContext* ctx) throw() ;
	String* getMessage(ThreadContext* ctx) throw() ;
	void setMessage(String* message, ThreadContext* ctx) throw() ;
	IAlinousElement* getSrc(ThreadContext* ctx) throw() ;
	void setSrc(IAlinousElement* src, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_SOURCEVALIDATIONERROR_H_ */
