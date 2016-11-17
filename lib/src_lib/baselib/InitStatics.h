/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */



namespace alinous {


bool IJava2CppSystem::isEnd = false;

MemoryAllocDestructor::~MemoryAllocDestructor(){
	SysThread::exits();

	bool result = Java2CppSystem::memManager->isEmpty();
	if(!result){
		wprintf(L"Not empty\n");
	}

	delete Java2CppSystem::memManager;
	
	// release all
	MemoryReleaserManager::shutdown();
	
	
}


IJava2CppSystem* IJava2CppSystem::getSelf()
{
	static Java2CppSystem inst;


	return &inst;
}



}




