#ifndef ORG_ALINOUS_CHARSET_CHARSETCONVERTER_H_
#define ORG_ALINOUS_CHARSET_CHARSETCONVERTER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace org {namespace alinous {namespace charset {
class CharsetDecoder;}}}

namespace org {namespace alinous {namespace charset {
class CharsetEncoder;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace org {namespace alinous {namespace charset {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class CharsetConverter : public virtual IObject {
public:
	CharsetConverter(const CharsetConverter& base) = default;
public:
	CharsetConverter(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~CharsetConverter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual CharsetDecoder* newDecoder(ThreadContext* ctx) throw()  = 0;
	virtual CharsetEncoder* newEncoder(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ORG_ALINOUS_CHARSET_CHARSETCONVERTER_H_ */
