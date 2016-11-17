/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "includes.h"

namespace java{ namespace lang {
PrintStream* System::out = nullptr;
PrintStream* System::err = nullptr;

bool System::__init_done = __init_static_variables();
bool System::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();

	System::out = getOut();
	System::err = getError();

	ctx->localGC();
	delete ctx;
	return true;
}

void System::__cleanUp(ThreadContext* ctx){

}

void System::SysPrintWriter::println(const UnicodeString *str, const ThreadContext* ctx) {
	const wchar_t* cs = str->towString();
	//wprintf(L"%S\n", cs);
	wprintf(cs);
	wprintf(L"\n");
}
void System::SysPrintWriter::println(const int v, const ThreadContext* ctx) const {
	wprintf(L"%d", v);
	wprintf(L"\n");
}


void System::SysPrintWriter::print(UnicodeString *str, ThreadContext* ctx){
	const wchar_t* cs = str->towString();
	wprintf(L"%S", cs);

}
void System::SysPrintWriter::flush(ThreadContext* ctx) {
	std::fflush(stdout);
}

PrintStream* System::getOut(){
	static StdOutputStream stdOutStream{STDOUT_FILENO};
	static PrintStream stream{&stdOutStream, (ThreadContext*)nullptr};

	return &stream;
}
PrintStream* System::getError(){
	static StdOutputStream stdErrorStream{STDERR_FILENO};
	static PrintStream stream{&stdErrorStream, nullptr};

	return &stream;
}

long long System::nanoTime(ThreadContext* ctx){
	timespec tp;
	clock_gettime(CLOCK_MONOTONIC, &tp);

	return tp.tv_sec * 1000 * 1000 * 1000 + tp.tv_nsec;
}

UnicodeString* System::getProperty(UnicodeString *prop, UnicodeString *defaultValue, ThreadContext* ctx){
	return defaultValue;
}


long long System::currentTimeMillis(ThreadContext* ctx){
	clock_t clk = clock() / (CLOCKS_PER_SEC / 1000);

	return (long long)clk;
}

void System::exit(int status, ThreadContext* ctx){
	std::exit(status);
}


}}

