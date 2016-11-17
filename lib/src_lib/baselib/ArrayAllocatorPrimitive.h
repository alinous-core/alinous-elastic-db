/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ARRAYALLOCATOR_PRIMITIVE_H_
#define BASELIB_ARRAYALLOCATOR_PRIMITIVE_H_

namespace alinous {

template <typename T>
class ArrayAllocatorPrimitive {
public:
	inline static IArrayObjectPrimitive<T>* allocatep(ThreadContext* ctx, int d1) throw() {
		//T* ar = new(ctx)  T[d1]{};

		IArrayObjectPrimitive<T>* array1d = new(ctx)  ArrayObjectPrimitive<T>(d1, d1, ctx);

		return array1d;
	}
	inline static IArrayObject<IArrayObjectPrimitive<T>>* allocatep(ThreadContext* ctx, int d1, int d2) throw() {
		//IArrayObjectPrimitive<T>** ar = new(ctx)  IArrayObjectPrimitive<T>*[d1]{};
		IArrayObject<IArrayObjectPrimitive<T>>* array1d = new(ctx)  ArrayObject<IArrayObjectPrimitive<T>>(d1, d1, ctx);

		for(int i = 0; i < d1; i++){
			IArrayObjectPrimitive<T>* array2d = allocatep(ctx, d2);
			array1d->set(array2d, i, ctx);

		}

		return array1d;
	}
	inline static IArrayObject<IArrayObject<IArrayObjectPrimitive<T>>>* allocatep(ThreadContext* ctx, int d1, int d2, int d3) throw() {
		//IArrayObject<IArrayObjectPrimitive<T>>** ar = new(ctx)  IArrayObject<ArrayObjectPrimitive<T>>*[d1]{};
		IArrayObject<IArrayObject<IArrayObjectPrimitive<T>>>* array1d = new(ctx)  ArrayObject<IArrayObject<IArrayObjectPrimitive<T>>>(d1, d1, ctx);

		for(int i = 0; i < d1; i++){
			IArrayObject<IArrayObjectPrimitive<T>>* array2d = allocatep(ctx, d2, d3);

			array1d->set(array2d, i, ctx);
		}

		return array1d;
	}

};

} /* namespace alinous */

#endif /* BASELIB_ARRAYALLOCATOR_H_ */
