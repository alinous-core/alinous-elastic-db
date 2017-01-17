#ifndef ALINOUS_COMPILE_EXPRESSION_IDOMSEGMENT_H_
#define ALINOUS_COMPILE_EXPRESSION_IDOMSEGMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomIndexSegment;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::IAlinousElement;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class IDomSegment : public IAlinousElement {
public:
	IDomSegment(const IDomSegment& base) = default;
public:
	IDomSegment(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDomSegment() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_NORMAL{0};
	constexpr static const int TYPE_INDEX{1};
public:
	virtual int getDomSegmentType(ThreadContext* ctx) throw()  = 0;
	virtual IExpression* getIndex(ThreadContext* ctx) = 0;
	virtual String* getName(ThreadContext* ctx) = 0;
	virtual int getSegmentVariableType(ThreadContext* ctx) throw()  = 0;
	virtual void setSegmentVariableType(int segmentVariableType, ThreadContext* ctx) throw()  = 0;
	virtual void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) = 0;
	virtual void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) = 0;
	virtual int fileSize(ThreadContext* ctx) = 0;
public:
	static IDomSegment* fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_IDOMSEGMENT_H_ */
