#ifndef ALINOUS_RUNTIME_VARIANT_IVARIANTDATA_H_
#define ALINOUS_RUNTIME_VARIANT_IVARIANTDATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace numeric {
class BigDecimal;}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace variant {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::sql::Timestamp;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::html::DomNode;
using ::alinous::numeric::BigDecimal;
using ::alinous::numeric::TimeOnlyTimestamp;
using ::alinous::runtime::dom::VariableException;



class IVariantData : public virtual IObject {
public:
	IVariantData(const IVariantData& base) = default;
public:
	IVariantData(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IVariantData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_STRING{1};
	constexpr static const int TYPE_LONG{2};
	constexpr static const int TYPE_INT{3};
	constexpr static const int TYPE_SHORT{4};
	constexpr static const int TYPE_CHAR{5};
	constexpr static const int TYPE_BYTE{6};
	constexpr static const int TYPE_FLOAT{7};
	constexpr static const int TYPE_DOUBLE{8};
	constexpr static const int TYPE_BOOL{9};
	constexpr static const int TYPE_BIG_DECIMAL{10};
	constexpr static const int TYPE_TIME{11};
	constexpr static const int TYPE_TIMESTAMP{12};
	constexpr static const int TYPE_NULL{13};
	static String* ATTR_VALUE;
public:
	virtual int getType(ThreadContext* ctx) throw()  = 0;
	virtual void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw()  = 0;
	virtual String* getString(ThreadContext* ctx) throw()  = 0;
	virtual long long getLong(ThreadContext* ctx) throw()  = 0;
	virtual int getInt(ThreadContext* ctx) throw()  = 0;
	virtual short getShort(ThreadContext* ctx) throw()  = 0;
	virtual wchar_t getChar(ThreadContext* ctx) throw()  = 0;
	virtual char getByte(ThreadContext* ctx) throw()  = 0;
	virtual float getFloat(ThreadContext* ctx) throw()  = 0;
	virtual double getDouble(ThreadContext* ctx) throw()  = 0;
	virtual bool getBoolean(ThreadContext* ctx) throw()  = 0;
	virtual BigDecimal* getBigDecimal(ThreadContext* ctx) throw()  = 0;
	virtual TimeOnlyTimestamp* getTime(ThreadContext* ctx) throw()  = 0;
	virtual Timestamp* getTimestamp(ThreadContext* ctx) throw()  = 0;
	virtual bool isNull(ThreadContext* ctx) throw()  = 0;
	virtual int compareTo(VariantValue* variant, ThreadContext* ctx) throw()  = 0;
	virtual int bufferSize(ThreadContext* ctx) throw()  = 0;
	virtual void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw();
	};
};

}}}

#endif /* end of ALINOUS_RUNTIME_VARIANT_IVARIANTDATA_H_ */
