/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef INCLUDE_GLOBAL_H_
#define INCLUDE_GLOBAL_H_


#ifdef __clang__
#pragma clang diagnostic ignored "-Woverloaded-virtual"
#pragma clang diagnostic ignored "-Wparentheses"
#pragma clang diagnostic ignored "-Wabstract-final-class"
#pragma clang diagnostic ignored "-Wself-assign-field"
#pragma clang diagnostic ignored "-Wtautological-compare"
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wgnu-array-member-paren-init"
#pragma clang diagnostic ignored "-Wunused-private-field"
#endif




#include <initializer_list>
#include <functional>
#include <stdarg.h>


#include <assert.h>
#include <cxxabi.h>


//#include <iostream>
#include <wchar.h>
#include <wctype.h>

#include <signal.h>
#include <pthread.h>
#include <setjmp.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef EOF
#undef EOF
#endif
const int EOF = -1;

#include <unistd.h>
//#include <sys/mman.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <math.h>
#undef DOMAIN
#undef SING
#undef OVERFLOW
#undef UNDERFLOW
#undef TLOSS
#undef PLOSS


const int DOMAIN = 1;
const int SING = 2;
const int OVERFLOW = 3;
const int UNDERFLOW = 4;
const int TLOSS = 5;
const int PLOSS = 6;

#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "macro_defs.h"

#include "system/FastCopy.h"

#include "unicode/uchar.h"

#include "memory/SegRawArray.h"
#include "memory/SegLinkedList.h"

#include "memory/SegBitSet.h"
#include "memory/MemoryManager.h"
#include "memory/RawArrayMemThread.h"
#include "memory/MemoryReleaser.h"

#include "memory/RawArrayMemAlloc.h"

#include "gc/MemoryInterface.h"

#include "baselib/Releaser.h"
#include "baselib/EnumBase.h"

#include "system/systemcalls.h"
#include "system/SysThread.h"

#include "system/RawBitSet.h"

#include "system/RawCompare.h"
#include "system/RawArray.h"
#include "system/RawArrayIterator.h"
#include "system/RawLinkedList.h"
#include "system/Mutex.h"


#include "system/FNVHash.h"
#include "system/HashedRawArray.h"
#include "system/RawArrayPrimitiveIterator.h"
#include "system/RawArrayPrimitive.h"

#include "system/RawHashMap.h"

#include "baselib_thread/TaskSynchronizer.h"
#include "baselib_thread/ConcurrentTaskQueue.h"
#include "baselib_thread/ConcurrentTaskExexutor.h"

#include "baselib_debug/debug_macro.h"

#include "baselib_debug/gc_debug.h"


#include "gc/GCObject.h"
#include "gc/IOblectStatus.h"


#include "gc/GCEngine.h"
#include "gc/GCLogCollector.h"


#include "gc/GCNotifier.h"


#include "baselib/IJava2CppSystem.h"
#include "baselib/ThreadContext.h"

#include "gc/IObjectUtils.h"
#include "baselib/IObject.h"

#include "gc/BackGroundGcExecutor.h"

#include "gc/gc_macros.h"

#include "baselib/Cloneable.h"
#include "baselib_io/Serializable.h"


#include "baselib/Java2CppSystem.h"

#include "gc/StaticInitializer.h"
#include "gc/ObjectEraser.h"

#include "baselib/IArrayObject.h"

#include "baselib/ArrayObject.h"
#include "baselib/ArrayObjectPrimitive.h"
#include "baselib/StaticArrayObjectPrimitive.h"
#include "baselib/StaticArrayObject.h"
#include "baselib/ArrayAllocator.h"
#include "baselib/ArrayAllocatorPrimitive.h"

#include "baselib/CharSequence.h"
#include "baselib/UnicodeString.h"
#include "baselib/StaticUnicodeString.h"

#include "baselib/UnicodeStringEncodeCache.h"

#include "baselib/UnicodeStringWrapper.h"

#include "baselib/StaticConst.h"

#include "baselib/Throwable.h"
#include "baselib_exceptions/exceptions.h"

#include "baselib_io_charset/CoderResult.h"

#include "baselib/Character.h"

#include "baselib/Math.h"


#include "baselib_io/CharBuffer.h"
#include "baselib_io/ByteBuffer.h"


#include "baselib_thread/InterruptedException.h"

#include "baselib/List.h"
#include "baselib/Iterator.h"
#include "baselib/ArrayList.h"
#include "baselib/ArrayListIterator.h"
#include "baselib/LinkedList.h"

#include "system/HashMapRawArray.h"
#include "baselib/HashMapKeySet.h"
#include "baselib/HashMap.h"

#include "baselib/Stack.h"
#include "baselib/Set.h"


#include "baselib_io/File.h"

#include "baselib_io/Reader.h"
#include "baselib_io/Writer.h"
#include "baselib_io/InputStream.h"
#include "baselib_io/OutputStream.h"


#include "baselib_io/OutputStreamWriter.h"
#include "baselib_io/InputStreamReader.h"

#include "baselib_io/FileInputStream.h"
#include "baselib_io/FileOutputStream.h"
#include "baselib_io/PrintWriter.h"
#include "baselib_io/FileReader.h"

#include "baselib_io/PrintStream.h"

#include "baselib_io/MMapSegments.h"
#include "baselib_io/RandomAccessFile.h"

#include "baselib_thread/ThreadMonitor.h"
#include "baselib_thread/SynchronizedBlockObj.h"

#include "baselib/Console.h"
#include "baselib/StdOutputStream.h"
#include "baselib/System.h"


#include "baselib_thread/Thread.h"
#include "baselib_thread/Semaphore.h"
#include "baselib_thread/ThreadMonitor.h"

#include "baselib_thread/Mutex.h"
#include "baselib_thread/TaskSync.h"

#include "baselib_io/Socket.h"
#include "baselib_io/ServerSocket.h"
#include "baselib_io/AlinousServerSocket.h"
#include "baselib_io/SSLSocketFactory.h"
#include "baselib_io/AlinousSocket.h"
#include "baselib_io/AlinousSSLSocketFactory.h"

#include "baselib/AlinousDebug.h"

#include <jni.h>

#include "jnilib/JNIThread.h"
#include "jnilib/DomConverter.h"
#include "jnilib/JavaFunctionManager.h"

#include "java.lang/Comparable.h"
#include "java.lang/Boolean.h"
#include "java.lang/Comparable.h"
#include "java.lang/Number.h"
#include "java.lang/Double.h"
#include "java.lang/Integer.h"
#include "java.lang/Byte.h"
#include "java.lang/Long.h"
#include "java.lang/Float.h"
#include "java.lang/Short.h"

#include "ConstStr.h"

#endif /* INCLUDE_GLOBAL_H_ */



