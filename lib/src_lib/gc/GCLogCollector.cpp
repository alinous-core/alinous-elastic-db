/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {

GCLogCollector::GCLogCollector(GCEngine* gcEngine) throw() : gcEngine(gcEngine)
{
	this->decLog = new RawArray<GCObject>(LOG_DEFAULT);
	this->decOwnerLog = new RawArray<GCObject>(LOG_DEFAULT);
	this->unlockLog = new RawArray<GCObject>(LOG_DEFAULT);
}

GCLogCollector::~GCLogCollector() throw() {
	delete this->decLog;
	delete this->decOwnerLog;
	delete this->unlockLog;
}

RawArray<GCObject>* GCLogCollector::swichDecLog() throw() {
	RawArray<GCObject>* ret = this->decLog;
	this->decLog = new RawArray<GCObject>(LOG_DEFAULT);
	return ret;
}
RawArray<GCObject>* GCLogCollector::swichDecOwnerLog() throw() {
	RawArray<GCObject>* ret = this->decOwnerLog;
	this->decOwnerLog = new RawArray<GCObject>(LOG_DEFAULT);
	return ret;
}
RawArray<GCObject>* GCLogCollector::swichUnlockLog() throw() {
	RawArray<GCObject>* ret = this->unlockLog;
	this->unlockLog = new RawArray<GCObject>(LOG_DEFAULT);
	return ret;
}

}

