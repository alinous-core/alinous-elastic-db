/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"


namespace alinous {

ObjectEraser::ObjectEraser(ThreadContext* ctx, const wchar_t* file, int line, const wchar_t* clsstr, const wchar_t* funcstr) throw(){
	setup(ctx, file, line, clsstr, funcstr);
}

void ObjectEraser::setup(ThreadContext* ctx, const wchar_t* file, int line, const wchar_t* clsstr, const wchar_t* funcstr) throw() {
	this->ctx = ctx;
	this->list = new RawArrayPrimitive<const RemovalPair*>(16);

	this->file = file;
	this->line = line;
	this->clsstr = clsstr;
	this->funcstr = funcstr;
}

ObjectEraser::~ObjectEraser() throw(){
	releaseAll();

	delete this->list;
	this->list = 0;
	this->ctx = 0;
}

void ObjectEraser::releaseAll() throw(){
	const int size = this->list->size();
	for(int i = 0; i < size; ++i){
		const RemovalPair* pair = this->list->get(i);
		GCUtils<IObject>::dec(pair->owner, pair->obj, ctx, this->file, this->line, this->clsstr);

		delete pair;
	}
}

void ObjectEraser::add(IObject* obj, IObject* owner) const throw(){
	if(obj != nullptr && !obj->staticInst){
		RemovalPair* pair = new RemovalPair(obj, owner);

		this->list->addElement(pair);
	}
}

}

