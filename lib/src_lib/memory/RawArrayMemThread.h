/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */



#ifndef RAWARRAYMEMTHREAD_H_
#define RAWARRAYMEMTHREAD_H_

namespace alinous {

class RawMemAllocElement;

class ExtendThread{
public:
	ExtendThread() throw() ;
	~ExtendThread() throw() ;

	void request(RawMemAllocElement* element) throw() ;

	static void* extendOperationLoop(void* param) throw() ;
	void doJob(RawMemAllocElement* element) throw() ;
private:
	pthread_t threadId;
	volatile bool run;
	volatile bool ready;

	pthread_mutex_t mutex;
	pthread_cond_t cond;
	SegRawLinkedList<RawMemAllocElement> tasks;
};

}

#endif /* RAWARRAYMEMTHREAD_H_ */
