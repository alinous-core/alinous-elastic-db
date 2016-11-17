/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {
BackGroundGcAction::BackGroundGcAction(ThreadContext* ctx) throw() {
	this->logCollector = ctx->switchCollector();
}

void BackGroundGcAction::exec(ThreadContext* ctx, IJava2CppSystem* system) throw() {
	ctx->importCollector(this->logCollector);
	ctx->localGC();
}


BackGroundGcExecutor::BackGroundGcExecutor(IJava2CppSystem* system) throw() {
	this->system = system;
	this->run = true;
	this->executing = false;
	this->thread = SysThread::createThread(BackGroundGcExecutor::threadFunc, this);
}
BackGroundGcExecutor::~BackGroundGcExecutor() throw() {
	this->run = false;

	actionLock.lock();
	actionLock.notify();
	actionLock.unlock();

	this->thread->join();
}

bool BackGroundGcExecutor::isEmpty() throw() {
	actionLock.lock();
	bool ret = this->actions.isEmpty();
	ret = ret && !this->executing;
	actionLock.unlock();

	return ret;
}

void BackGroundGcExecutor::asyncGc(ThreadContext* ctx) throw() {
	BackGroundGcAction* action = new BackGroundGcAction(ctx);

	actionLock.lock();

	this->actions.add(action);

	actionLock.notify();
	actionLock.unlock();
}

void BackGroundGcExecutor::execLoop(ThreadContext* ctx) throw() {
	while(true){
		actionLock.lock();

		this->executing = false;

		if(this->actions.isEmpty()){
			if(!this->run){
				break;
			}
			actionLock.wait();
		}

		BackGroundGcAction* action = nullptr;
		if(!this->actions.isEmpty()){
			action = this->actions.remove(0);
		}

		this->executing = true;

		actionLock.unlock();

		if(action != nullptr){
			action->exec(ctx, system);
			delete action;
		}

		if(system->getGC()->readtToDeleteSize() > 800000){
			system->getGC()->vacuum(ctx);
		}
	}
}

void* BackGroundGcExecutor::threadFunc(void* param) throw() {
	ThreadParams* tp = (ThreadParams*)param;
	SysThread::init(tp->thread);

	BackGroundGcExecutor* _this = (BackGroundGcExecutor*)tp->param;

	ThreadContext* ctx = ThreadContext::newThreadContext();

	_this->execLoop(ctx);

	delete tp;
	delete ctx;

	return nullptr;
}

}
