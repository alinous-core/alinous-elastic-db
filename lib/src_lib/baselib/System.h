/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_SYSTEM_H_
#define BASELIB_SYSTEM_H_

namespace alinous {
class ThreadContext;
}

namespace java{ namespace lang {

class IObject;

using namespace alinous;

class System {
public:
	class SysPrintWriter : public IObject {
	public:
		SysPrintWriter() : IObject(0){

		}
		virtual ~SysPrintWriter(){}
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {}

		void println(const UnicodeString *str, const ThreadContext* ctx);
		void println(const int v, const ThreadContext* ctx) const;
		void print(UnicodeString *str, ThreadContext* ctx);
		void flush(ThreadContext* ctx);
	};

	static PrintStream* getOut();
	static PrintStream* getError();

	static PrintStream* out;
	static PrintStream* err;

	static long long nanoTime(ThreadContext* ctx);
	static void gc(ThreadContext* ctx){

	}

	static UnicodeString* getProperty(UnicodeString *prop, UnicodeString *defaultValue, ThreadContext* ctx);
	static long long currentTimeMillis(ThreadContext* ctx);
	static void exit(int status, ThreadContext* ctx);
	static void arraycopy(IArrayObjectBase* src, int srcPos, IArrayObjectBase* dest, int destPos, int length, ThreadContext* ctx){
		src->arraycopy(srcPos, dest, destPos, length, ctx);
	}

	static bool __init_done;
	static bool __init_static_variables();
	static void __cleanUp(ThreadContext* ctx);
};

}} /* namespace alinous */

#endif /* BASELIB_SYSTEM_H_ */
