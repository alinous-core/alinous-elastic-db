/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_RELEASER_H_
#define BASELIB_RELEASER_H_

namespace alinous {

class Releaser {
public:
	inline Releaser(std::function<void(void)> lm){
		this->func = lm;
	}
	inline ~Releaser(){
		this->func();
	}

	std::function<void (void)> func;

};

} /* namespace alinous */

#endif /* BASELIB_RELEASER_H_ */
