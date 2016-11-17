/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_DEBUG_GC_DEBUG_H_
#define BASELIB_DEBUG_GC_DEBUG_H_


#ifdef __TRACE_NEW
#include <bfd.h>
#include <libgen.h>

extern bfd *abfd;
extern asymbol **symbols;
extern int nsymbols;
extern int dotrace;

inline void __init_trace_new(const char* prog){
	 abfd = bfd_openr(prog, NULL);
	 bfd_check_format(abfd, bfd_object);

	 int size = bfd_get_symtab_upper_bound(abfd);
	 symbols = (asymbol**)malloc(size);
	 nsymbols = bfd_canonicalize_symtab(abfd, symbols);
}

inline void __destroy_trace_new(){
	bfd_close(abfd);
	free(symbols);
}

#endif


namespace alinous {

#ifdef __DEBUG__
void showDebugIObject(IObject * ptr, bool stackTrace);
#endif

}

#endif /* BASELIB_DEBUG_GC_DEBUG_H_ */
