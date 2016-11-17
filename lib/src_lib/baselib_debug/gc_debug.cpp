/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

#ifdef __TRACE_NEW
#include <bfd.h>
#include <libgen.h>

bfd *abfd;
asymbol **symbols;
int nsymbols = -1;
int dotrace = -1;
#endif


namespace alinous {


#ifdef __DEBUG__
BinEngine* BinEngine::instance = 0;
#endif


#ifdef __DEBUG__

void showDebugIObject(IObject * ptr, bool stackTrace){
	BinEngine::getInstance()->objectInfo(ptr, stackTrace);
}

#endif

}


