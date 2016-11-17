/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_STATICINITIALIZER_H_
#define GC_STATICINITIALIZER_H_

namespace java { namespace lang{
class IObject;
}}

namespace alinous {

using namespace java::lang;

class StaticInitializer {
public:
	static IObject* reg(IObject *ptr) throw();
	static IObject* inc(IObject *ptr) throw();
	static IObject* dec(IObject *ptr) throw();
};

} /* namespace alinous */

#endif /* GC_STATICINITIALIZER_H_ */
