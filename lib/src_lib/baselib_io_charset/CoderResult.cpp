/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java {
namespace nio {
namespace charset {

CoderResult CoderResult::__UNDERFLOW(CoderResult::CR_UNDERFLOW, 0);
CoderResult CoderResult::__OVERFLOW(CoderResult::CR_OVERFLOW, 0);
constexpr CoderResult* CoderResult::UNDERFLOW;
constexpr CoderResult* CoderResult::OVERFLOW;


}}}

