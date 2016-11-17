/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "includes.h"


namespace alinous {

// null strings
constexpr StaticUnicodeString UnicodeStringWrapper::__NULL_STR;

UnicodeStringWrapper::UnicodeStringWrapper(const wchar_t* str, const int length) : UnicodeString(), str(str, length){}
UnicodeStringWrapper::UnicodeStringWrapper(const StaticUnicodeString& str) : /*UnicodeString(), */UnicodeString(str.buff), str(str) {}




}
