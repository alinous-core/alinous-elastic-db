/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"


namespace alinous {

SysMutex ThreadContext::newLock;

ThreadContext::ThreadContext(SysThread *thread) throw()
{
	this->system = 0;
	this->pThread = thread;

	this->lostExt = false;

	this->denyGCCount = 0;

	this->notifiers = new RawArray<GCNotifier>(32);

	this->pLogger = nullptr;

	this->protectLockObjects = new RawArray<GCObject>(256);

	this->alloc = nullptr;
}

ThreadContext::~ThreadContext() throw()
{
	if(this->system != 0){ // temporary (used in newContext and getCurrentContext) variable do not have system
		localGC(true);
		newLock.lock();
		this->system->endThread(this);
		newLock.unlock();
	}

	delete this->notifiers;

	if(this->pLogger != nullptr){
		delete this->pLogger;
		this->pLogger = nullptr;
	}

	delete this->protectLockObjects;
}

void ThreadContext::init(IJava2CppSystem* ps) throw() {
	this->system = ps;
	this->pLogger = new GCLogCollector(ps->getGC());

	this->alloc = SysThread::getMalloc();
}

ThreadContext* ThreadContext::newThreadContext() throw()
{
	ThreadContext::newLock.lock();
	SysThread *pthread = SysThread::getCurrentThread();
	ThreadContext* pContext = new ThreadContext(pthread);

	ThreadContext* ctx = IJava2CppSystem::getSelf()->searchThreadContext(pContext);

	delete pContext;
	if(ctx != nullptr){
		ThreadContext::newLock.unlock();
		return ctx;
	}

	pthread = SysThread::getCurrentThread();
	ThreadContext* current = new ThreadContext(pthread);
	current->init(IJava2CppSystem::getSelf());

	IJava2CppSystem::getSelf()->addThreadContext(current);

	ThreadContext::newLock.unlock();

	return current;
}

ThreadContext* ThreadContext::getCurentContext() throw()
{
	if(IJava2CppSystem::isEnd){
		return nullptr;
	}
	SysThread *pthread = SysThread::getCurrentThread();
	ThreadContext* pContext = new ThreadContext(pthread);

	ThreadContext::newLock.lock();
	ThreadContext* current = IJava2CppSystem::getSelf()->searchThreadContext(pContext);
	ThreadContext::newLock.unlock();

	delete pContext;
	return current;
}
void ThreadContext::asyncGC() throw() {
	this->system->asyncGC(this);
}

void ThreadContext::localGC() throw()
{
	localGC(false);
}
void ThreadContext::localGC(bool force) throw()
{
	while(this->pLogger->logSize() != 0){
		this->pLogger->syncLog(this);
	}
}

void ThreadContext::gc(bool isFinal) throw()
{
	this->system->gc(isFinal, this);
}

int ThreadContext::getCurrentVariableSize() throw() {
	return this->pLogger->logSize();
}


ThreadContext* ThreadContext::traceStack(const char* fileName, int line)  throw() {
	return this;
}

bool ThreadContext::setLostExt(bool lost) throw() {
	bool lastValue = this->lostExt;
	this->lostExt = lost;

	return lastValue;
}


void ThreadContext::incGcDenial() throw() {
	++denyGCCount;
}
void ThreadContext::decGcDenial() throw() {
	--denyGCCount;
}
bool ThreadContext::isGcDenial() throw() {
	return this->denyGCCount != 0;
}


void ThreadContext::memLeakCheck() throw() {
	this->system->getGC()->printGcStat();
}

GCLogCollector* ThreadContext::switchCollector() throw() {
	GCLogCollector* col = this->pLogger;

	this->pLogger = new GCLogCollector(this->system->getGC());

	return col;
}

void ThreadContext::importCollector(GCLogCollector* col) throw(){
	delete this->pLogger;
	this->pLogger = col;
}

void ThreadContext::pushGCNotifier(GCNotifier* notifier) throw(){
	this->notifiers->addElement(notifier);
}
GCNotifier* ThreadContext::popGCNotifier() throw(){
	return this->notifiers->pop();
}

GCNotifier* ThreadContext::peekGCNotifier() throw(){
	return this->notifiers->peek();
}


void ThreadContext::registerObject(GCObject* obj, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw()
{
	GCNotifier* peek = this->notifiers->peek();

	peek->registerObject(obj, ctx);

	pLogger->registerObject(obj);
}

void ThreadContext::releaseUndeletable(GCObject* obj) throw(){
	this->pLogger->unlock(obj);
}

void ThreadContext::returnProtect(GCObject* obj) throw(){
	this->protectLockObjects->addElement(obj);
	int pos = this->notifiers->size() - 2;
	if(pos < 0){
		return;
	}

	this->pLogger->protectByLock(obj);

	GCNotifier* peek = this->notifiers->get(pos);
	//GCNotifierRegisterRecord *notifyRecord = new GCNotifierRegisterRecord(obj, L"", 0, L"protect return value");
	peek->moveInto(obj);
}


void ThreadContext::protectRootObject(GCObject* obj) throw(){
	this->pLogger->protectByLock(obj);

	GCNotifier* peek = peekGCNotifier();
	//GCNotifierRegisterRecord *notifyRecord = new GCNotifierRegisterRecord(obj, L"", 0, L"protect return value");
	peek->moveInto(obj);
}

int ThreadContext::ValueCompare::operator() (const ThreadContext* const a, const ThreadContext* const b, const ThreadContext* const ctx) const throw() {
	if(a->getThread()->getId() == b->getThread()->getId()){
		return 0;
	}else if(a->getThread()->getId() > b->getThread()->getId()){
		return 1;
	}

	return -1;
}

}
