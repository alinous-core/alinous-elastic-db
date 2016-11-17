/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ARRAYALLOCATOR_H_
#define BASELIB_ARRAYALLOCATOR_H_

namespace alinous {

template <typename T>
class ArrayAllocator {
public:
	inline static IArrayObject<T>* allocate(ThreadContext* ctx, int d1) throw() {
		//T** ar = new T*[d1]{};

		IArrayObject<T>* array1d = new(ctx) ArrayObject<T>(d1, d1, ctx);

		return array1d;
	}
	inline static IArrayObject<IArrayObject<T>>* allocate(ThreadContext* ctx, int d1, int d2) throw() {
		//IArrayObject<T>** ar = new(ctx)  IArrayObject<T>*[d1]{};
		IArrayObject<IArrayObject<T>>* array1d = new(ctx)  ArrayObject<IArrayObject<T>>(d1, d1, ctx);

		for(int i = 0; i < d1; i++){
			IArrayObject<T>* array2d = allocate(ctx, d2);
			array1d->set(array2d, i, ctx);

		}

		return array1d;
	}

	inline static IArrayObject<IArrayObject<IArrayObject<T>>>* allocate(ThreadContext* ctx, int d1, int d2, int d3) throw() {
		//IArrayObject<IArrayObject<T>>** ar = new(ctx)  IArrayObject<IArrayObject<T>>*[d1]{};
		IArrayObject<IArrayObject<IArrayObject<T>>>* array1d = new(ctx)  ArrayObject<IArrayObject<IArrayObject<T>>>(d1, d1, ctx);

		for(int i = 0; i < d1; i++){
			IArrayObject<IArrayObject<T>>* array2d = allocate(ctx, d2, d3);

			array1d->set(array2d, i, ctx);
		}

		return array1d;
	}
};

} /* namespace alinous */

#endif /* BASELIB_ARRAYALLOCATOR_H_ */
