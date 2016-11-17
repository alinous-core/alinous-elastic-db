/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef JNILIB_JNITHREAD_H_
#define JNILIB_JNITHREAD_H_

namespace alinous{ namespace jdk{ namespace functions{

class JNICallBack{
public:
	virtual void execute() = 0;
};

class JNIThread {
public:
	JNIThread() : run(true), exec(nullptr) {
		::pthread_mutex_init(&mutex, NULL);
		::pthread_cond_init(&cond, NULL);

		::pthread_mutex_init(&mutex_request_block, NULL);


		::pthread_barrier_init(&barrier, 0, 2);

		this->thread = SysThread::createThread(JNIThread::__entryPoint, this);

		::pthread_barrier_wait(&barrier);
		::pthread_barrier_destroy(&barrier);
	}

	~JNIThread(){
		::pthread_mutex_lock(&mutex);
		this->run = false;
		::pthread_cond_signal(&cond);
		::pthread_mutex_unlock(&mutex);

		this->thread->join();
		delete this->thread;
		this->thread = nullptr;

		// mutex
		::pthread_cond_destroy(&cond);
		::pthread_mutex_destroy(&mutex);
		::pthread_mutex_destroy(&mutex_request_block);
	}

	void request(JNICallBack* exec){
		::pthread_mutex_lock(&mutex_request_block);

		{
			::pthread_mutex_lock(&mutex);

			::pthread_barrier_init(&barrier, 0, 2);

			this->exec = exec;
			::pthread_cond_signal(&cond);

			::pthread_mutex_unlock(&mutex);

			::pthread_barrier_wait(&barrier);
			::pthread_barrier_destroy(&barrier);
		}

		::pthread_mutex_unlock(&mutex_request_block);
	}

	void executionLoop(ThreadContext *ctx){
		::pthread_mutex_lock(&mutex);

		::pthread_barrier_wait(&barrier);

		while(this->run){
			{
				GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JNIThread", L"executionLoop");

				if(exec == nullptr){
					::pthread_cond_wait(&cond, &mutex);
				}

				if(exec != nullptr){
					((JNICallBack*)exec)->execute();
					::pthread_barrier_wait(&barrier);

					exec = nullptr;
				}
			}

			ctx->localGC();
		}

		::pthread_mutex_unlock(&mutex);
	}

	static void* __entryPoint(void* param){
		ThreadParams *tp = (ThreadParams*)param;
		SysThread::init(tp->thread);

		JNIThread* _this = (JNIThread*)tp->param;
		ThreadContext *ctx = ThreadContext::newThreadContext();

		_this->executionLoop(ctx);

		delete ctx;

		ThreadInfo* pinfo = (ThreadInfo*)::pthread_getspecific(SysThread::key);
		pinfo->thread = nullptr;
		delete pinfo->alloc;
		delete pinfo;

		delete tp;

		::pthread_setspecific(SysThread::key, nullptr);

		::pthread_exit(nullptr);
		return nullptr;
	}

private:
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	pthread_barrier_t barrier;

	pthread_mutex_t mutex_request_block;

	SysThread* thread;
	volatile bool run;

	volatile JNICallBack* exec;


};


}}}




#endif /* JNILIB_JNITHREAD_H_ */
