#ifndef ALINOUS_REMOTE_SOCKET_NETWORKBINARYBUFFER_H_
#define ALINOUS_REMOTE_SOCKET_NETWORKBINARYBUFFER_H_
namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace socket {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::nio::ByteBuffer;



class NetworkBinaryBuffer final : public virtual IObject {
public:
	NetworkBinaryBuffer(const NetworkBinaryBuffer& base) = default;
public:
	NetworkBinaryBuffer(int capacity, ThreadContext* ctx) throw() ;
	void __construct_impl(int capacity, ThreadContext* ctx) throw() ;
	NetworkBinaryBuffer(IArrayObjectPrimitive<char>* src, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<char>* src, ThreadContext* ctx) throw() ;
	virtual ~NetworkBinaryBuffer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ByteBuffer* buff;
	int lastPos;
public:
	IArrayObjectPrimitive<char>* toBinary(ThreadContext* ctx) throw() ;
	int getPutSize(ThreadContext* ctx) throw() ;
	void putBoolean(bool value, ThreadContext* ctx) throw() ;
	bool getBoolean(ThreadContext* ctx) throw() ;
	void putByte(char b, ThreadContext* ctx) throw() ;
	char getByte(ThreadContext* ctx) throw() ;
	void putBytes(IArrayObjectPrimitive<char>* src, int start, int count, ThreadContext* ctx) throw() ;
	void putBytes(IArrayObjectPrimitive<char>* src, ThreadContext* ctx) throw() ;
	IArrayObjectPrimitive<char>* getBytes(int count, ThreadContext* ctx) throw() ;
	void putChar(wchar_t value, ThreadContext* ctx) throw() ;
	wchar_t getChar(ThreadContext* ctx) throw() ;
	void putShort(short value, ThreadContext* ctx) throw() ;
	short getShort(ThreadContext* ctx) throw() ;
	void putInt(int value, ThreadContext* ctx) throw() ;
	int getInt(ThreadContext* ctx) throw() ;
	void putLong(long long value, ThreadContext* ctx) throw() ;
	long long getLong(ThreadContext* ctx) throw() ;
	void putFloat(float value, ThreadContext* ctx) throw() ;
	float getFloat(ThreadContext* ctx) throw() ;
	void putDouble(double value, ThreadContext* ctx) throw() ;
	double getDouble(ThreadContext* ctx) throw() ;
	void putString(String* str, ThreadContext* ctx) throw() ;
	String* getString(ThreadContext* ctx) throw() ;
	void clear(ThreadContext* ctx) throw() ;
private:
	void extend(int length, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_NETWORKBINARYBUFFER_H_ */
