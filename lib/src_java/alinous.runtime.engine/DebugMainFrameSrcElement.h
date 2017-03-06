#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGMAINFRAMESRCELEMENT_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGMAINFRAMESRCELEMENT_H_
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::analyse::SrcAnalyseContext;



class DebugMainFrameSrcElement final : public AbstractSrcElement {
public:
	DebugMainFrameSrcElement(const DebugMainFrameSrcElement& base) = default;
public:
	DebugMainFrameSrcElement(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DebugMainFrameSrcElement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* filePath;
	String* debugFilePath;
	int line;
public:
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	String* getFilePath(ThreadContext* ctx) throw()  final;
	void setFilePath(String* path, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() ;
	String* getDebugFilePath(ThreadContext* ctx) throw()  final;
	void setDebugFilePath(String* debugFilePath, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGMAINFRAMESRCELEMENT_H_ */
