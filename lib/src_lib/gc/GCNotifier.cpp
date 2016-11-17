/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"




namespace alinous {


GCNotifier::GCNotifier(ThreadContext* ctx, const wchar_t* file, int line, const wchar_t* clsstr, const wchar_t* funcstr) throw()
	:  notified(false), ctx(ctx), file(file), clsstr(clsstr), funcstr(funcstr), line(line), list(1024)
{
	if(ctx != nullptr){
		this->ctx->pushGCNotifier(this);
	}
}

GCNotifier::~GCNotifier() throw() {
	if(ctx != nullptr) {
		if(!notified){
			notifyResigter();
		}

		this->ctx->popGCNotifier();
	}
}

void GCNotifier::notifyResigter() throw() {
	#ifdef __DEBUG__
	assert(ctx != nullptr);
	#endif

	notified = true;

	const int size = this->list.size();
	for(int i = 0; i != size; ++i){
		GCObject* record = this->list.get(i);

		ctx->releaseUndeletable(record);

		//delete record;
	}
}

void GCNotifier::protectMoveDecreased(GCObject* obj, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw(){
	#ifdef __DEBUG__
	assert(ctx != nullptr);
	#endif

	//GCNotifierRegisterRecord* record = new(ctx) GCNotifierRegisterRecord(obj, filePath, line, classOrFunc);
	this->list.addElement(obj);
}

bool GCNotifier::hasObject(GCObject* obj)throw(){
	GCObject *rec = this->list.search(obj);

	return rec != nullptr;
}

}

