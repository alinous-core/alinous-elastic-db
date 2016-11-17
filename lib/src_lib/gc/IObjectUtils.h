/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_IOBJECTUTILS_H_
#define GC_IOBJECTUTILS_H_

namespace java {
namespace lang {
class IObject;
}}


namespace alinous {


class TheradContext;

using namespace java::lang;


class IObjectUtils {
public:
	void static resigter(GCObject *ptr, ThreadContext* ctx) throw();
	void static forceReleaseRefs(GCObject *ptr, ThreadContext* ctx,  bool lostExt) throw();
	void static deleteIObject(GCObject *ptr) throw();
};

} /* namespace alinous */

#endif /* GC_IOBJECTUTILS_H_ */
