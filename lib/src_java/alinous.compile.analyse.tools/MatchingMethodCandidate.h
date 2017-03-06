#ifndef ALINOUS_COMPILE_ANALYSE_TOOLS_MATCHINGMETHODCANDIDATE_H_
#define ALINOUS_COMPILE_ANALYSE_TOOLS_MATCHINGMETHODCANDIDATE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {namespace tools {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::declare::ClassMethodFunction;



class MatchingMethodCandidate final : public virtual IObject {
public:
	MatchingMethodCandidate(const MatchingMethodCandidate& base) = default;
public:
	MatchingMethodCandidate(ClassMethodFunction* method, int score, ThreadContext* ctx) throw() ;
	void __construct_impl(ClassMethodFunction* method, int score, ThreadContext* ctx) throw() ;
	virtual ~MatchingMethodCandidate() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ClassMethodFunction* method;
	int score;
	ArrayList<ClassMethodFunction>* sameScores;
public:
	ClassMethodFunction* getMethod(ThreadContext* ctx) throw() ;
	void setMethod(ClassMethodFunction* method, ThreadContext* ctx) throw() ;
	int getScore(ThreadContext* ctx) throw() ;
	void setScore(int score, ThreadContext* ctx) throw() ;
	ArrayList<ClassMethodFunction>* getSameScores(ThreadContext* ctx) throw() ;
	void addSameScore(ClassMethodFunction* method, ThreadContext* ctx) throw() ;
	bool isAmbitious(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_TOOLS_MATCHINGMETHODCANDIDATE_H_ */
