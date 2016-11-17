

#include "includes.h"

using namespace std;
using namespace alinous;

int main(int argc, char **argv) {
	wprintf(L"PROGRAM starts\n");
  
    IJava2CppSystem* system = Java2CppSystem::getSelf();
    ThreadContext* ctx = ThreadContext::newThreadContext();
    
    ctx->localGC(); // once clear

    wprintf(L"Main PROGRAM starts thread : %lld\n", ctx->getThread()->getId());
    
	ctx->localGC();
	
	/*
	test::alinous::test::btree::BTreeMemoryTest::testAll(ctx);
	test::alinous::test::btree::BTreeMemoryTest::testAll(ctx);
	test::alinous::test::btree::BTreeMemoryTest::testAll(ctx);
	test::alinous::test::btree::BTreeMemoryTest::testAll(ctx);
	test::alinous::test::btree::BTreeMemoryTest::testAll(ctx);
	*/
	
	// test::alinous::test::alinous::SelectCrossJoin::testAll(ctx);
	
	__cleanUpStatics(ctx);


    while(!system->isBackgoundGCEmpty()){
		pthread_yield();
    }

    int deleted;
    do{
	    ctx->localGC();
	    deleted = system->getGC()->vacuum(ctx);
    }
    while(deleted != 0);

    ctx->memLeakCheck();
    
    delete ctx;
	
    return 0;
}
