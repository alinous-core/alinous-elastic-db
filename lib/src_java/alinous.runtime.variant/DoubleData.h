#ifndef ALINOUS_RUNTIME_VARIANT_DOUBLEDATA_H_
#define ALINOUS_RUNTIME_VARIANT_DOUBLEDATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace variant {
class DoubleData;}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace numeric {
class BigDecimal;}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace variant {
class IVariantData;}}}

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
using ::alinous::html::Attribute;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::numeric::BigDecimal;
using ::alinous::numeric::TimeOnlyTimestamp;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class DoubleData final : public IVariantData, public virtual IObject {
public:
	DoubleData(const DoubleData& base) = default;
public:
	DoubleData(double data, ThreadContext* ctx) throw() ;
	void __construct_impl(double data, ThreadContext* ctx) throw() ;
	DoubleData(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DoubleData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	double data;
public:
	static String* TAG_NAME;
public:
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw()  final;
	int getType(ThreadContext* ctx) throw()  final;
	String* getString(ThreadContext* ctx) throw()  final;
	long long getLong(ThreadContext* ctx) throw()  final;
	int getInt(ThreadContext* ctx) throw()  final;
	short getShort(ThreadContext* ctx) throw()  final;
	wchar_t getChar(ThreadContext* ctx) throw()  final;
	char getByte(ThreadContext* ctx) throw()  final;
	float getFloat(ThreadContext* ctx) throw()  final;
	double getDouble(ThreadContext* ctx) throw()  final;
	bool getBoolean(ThreadContext* ctx) throw()  final;
	BigDecimal* getBigDecimal(ThreadContext* ctx) throw()  final;
	TimeOnlyTimestamp* getTime(ThreadContext* ctx) throw()  final;
	Timestamp* getTimestamp(ThreadContext* ctx) throw()  final;
	int bufferSize(ThreadContext* ctx) throw()  final;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	bool isNull(ThreadContext* ctx) throw()  final;
	int compareTo(VariantValue* variant, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static DoubleData* importFromXml(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw();
	};
};

}}}

#endif /* end of ALINOUS_RUNTIME_VARIANT_DOUBLEDATA_H_ */
