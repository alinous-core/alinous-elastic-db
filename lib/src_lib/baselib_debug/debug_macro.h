/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */



#include <execinfo.h>

#ifndef DEBUG_TRACE_MACROS_H_
#define DEBUG_TRACE_MACROS_H_


#define __STR2WSTR(str)    L##str
#define _STR2WSTR(str)     __STR2WSTR(str)

#define __FILEW__          _STR2WSTR(__FILE__)
//#define __FUNCTIONW__      _STR2WSTR(__func__)




#endif




