#ifndef ALINOUS_COMPILE_ABSTRACTSRCELEMENT_H_
#define ALINOUS_COMPILE_ABSTRACTSRCELEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {
class Token;}}

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
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::ClassMethodFunction;
using ::alinous::compile::declare::function::AlinousFunction;



class AbstractSrcElement : public virtual IObject {
public:
	AbstractSrcElement(const AbstractSrcElement& base) = default;
public:
	AbstractSrcElement(ThreadContext* ctx) throw()  : IObject(ctx), parent(nullptr), filePath(nullptr), debugFilePath(nullptr), line(0), _startPosition(0), endLine(0), _endPosition(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractSrcElement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AbstractSrcElement* parent;
	String* filePath;
	String* debugFilePath;
private:
	int line;
	int _startPosition;
	int endLine;
	int _endPosition;
public:
	virtual AbstractSrcElement* getParent(ThreadContext* ctx) throw() ;
	virtual void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() ;
	virtual AlinousClass* getAlinousClass(ThreadContext* ctx) throw() ;
	AlinousFunction* getAlinousFunction(ThreadContext* ctx) throw() ;
	ClassMethodFunction* getClassMethodFunction(ThreadContext* ctx) throw() ;
	virtual void position(Token* start, Token* end, ThreadContext* ctx) throw() ;
	void position(AbstractSrcElement* start, AbstractSrcElement* end, ThreadContext* ctx) throw() ;
	virtual void position(Token* start, AbstractSrcElement* end, ThreadContext* ctx) throw() ;
	void position(AbstractSrcElement* start, Token* end, ThreadContext* ctx) throw() ;
	void startPosition(Token* start, ThreadContext* ctx) throw() ;
	void startPosition(AbstractSrcElement* start, ThreadContext* ctx) throw() ;
	void endPosition(Token* end, ThreadContext* ctx) throw() ;
	void endPosition(AbstractSrcElement* end, ThreadContext* ctx) throw() ;
	virtual int getLine(ThreadContext* ctx) throw() ;
	void setLine(int line, ThreadContext* ctx) throw() ;
	virtual int getStartPosition(ThreadContext* ctx) throw() ;
	void setStartPosition(int startPosition, ThreadContext* ctx) throw() ;
	virtual int getEndLine(ThreadContext* ctx) throw() ;
	void setEndLine(int endLine, ThreadContext* ctx) throw() ;
	virtual int getEndPosition(ThreadContext* ctx) throw() ;
	void setEndPosition(int endPosition, ThreadContext* ctx) throw() ;
	virtual String* getFilePath(ThreadContext* ctx) throw() ;
	virtual void setFilePath(String* filePath, ThreadContext* ctx) throw() ;
	virtual String* getDebugFilePath(ThreadContext* ctx) throw() ;
	virtual void setDebugFilePath(String* debugFilePath, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_ABSTRACTSRCELEMENT_H_ */
