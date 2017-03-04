/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

#include "com.google.re2j/Pattern.h"

namespace java{ namespace io {

UnicodeString* File::regexSep = nullptr;
com::google::re2j::Pattern* File::sepPattern = nullptr;
UnicodeString* File::regexSep2 = nullptr;
UnicodeString* File::DOT = nullptr;
UnicodeString* File::DDOT = nullptr;
UnicodeString* File::separator = nullptr;

bool File::__init_done = __init_static_variables();
bool File::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();

	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomNameSegment", L"__init_static_variables");
		File::regexSep = new(ctx) UnicodeString(L"[/\\\\]", ctx);
		File::regexSep2 = new(ctx) UnicodeString(L"\\", ctx);
		File::DOT = new(ctx) UnicodeString(L".", ctx);
		File::DDOT = new(ctx) UnicodeString(L"..", ctx);
		File::separator = new(ctx) UnicodeString(L"/", ctx);

		__GC_INS(nullptr, File::regexSep, UnicodeString);
		__GC_INS(nullptr, File::regexSep2, UnicodeString);
		__GC_INS(nullptr, File::DOT, UnicodeString);
		__GC_INS(nullptr, File::DDOT, UnicodeString);
		__GC_INS(nullptr, File::separator, UnicodeString);
	}

	ctx->localGC();
	delete ctx;
	return true;
}

void File::__cleanUp(ThreadContext* ctx)
{
	__GC_DEC(nullptr, regexSep, UnicodeString);
	__GC_DEC(nullptr, regexSep2, UnicodeString);
	__GC_DEC(nullptr, DOT, UnicodeString);
	__GC_DEC(nullptr, DDOT, UnicodeString);
	__GC_DEC(nullptr, separator, UnicodeString);


	if(sepPattern != nullptr){
		__GC_DEC(nullptr, sepPattern, com::google::re2j::Pattern);
	}
}

IArrayObject<UnicodeString>* File::split(UnicodeString* path, ThreadContext* ctx){
	this->pathMutex.lock();

	if(File::sepPattern == nullptr){
		File::sepPattern = com::google::re2j::Pattern::compile(regexSep, ctx);
		__GC_INS(nullptr, File::sepPattern, com::google::re2j::Pattern);
	}

	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UnicodeString", L"split");
	IArrayObject<UnicodeString>* result = __GC_INS(nullptr, File::sepPattern->split(path, ctx), IArrayObject<UnicodeString>);
	__e_obj1.add(result,nullptr);

	this->pathMutex.unlock();

	return result;
}


File::File(UnicodeString* pathname, ThreadContext* ctx) : IObject(ctx){
	this->pathSeparator = __GC_INS(this, new UnicodeString(L"/", ctx), UnicodeString);
	this->path = __GC_INS(this, new UnicodeString(pathname, ctx), UnicodeString);

}
File::~File(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void File::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->path != nullptr){
		__GC_DEC(this, this->path, UnicodeString);
		this->path = nullptr;
		__GC_DEC(this, this->pathSeparator, UnicodeString);
		this->pathSeparator = nullptr;
	}
}

bool File::equals(File *obj, ThreadContext* ctx)
{
	UnicodeString* src = getAbsolutePath(ctx);
	UnicodeString* dest = obj->getAbsolutePath(ctx);

	bool ret = src->equals(dest, ctx);

	__GC_DEC(this, src, UnicodeString);
	__GC_DEC(this, dest, UnicodeString);

	return ret;
}

bool File::exists(ThreadContext* ctx)
{
	struct stat  st;
	char* src = path->toCString(ctx);

	int ret = stat(src, &st);

	delete [] src;

	return ret == 0;
}

File* File::getAbsoluteFile(ThreadContext* ctx)
{
	UnicodeString* realPath = getAbsolutePath(ctx);

	return new File(realPath, ctx);
}
UnicodeString* File::getAbsolutePath(ThreadContext* ctx)
{
	if(isAbsolute(ctx)){
		return this->path;
	}

	UnicodeString* retPath = __getAbsolutePath(ctx);
	if(retPath != nullptr){
		return retPath;
	}

	File* tmpFile = new File(new String(L".", ctx), ctx);
	retPath = tmpFile->__getAbsolutePath(ctx);


	IArrayObject<UnicodeString>* parts = split(this->path, ctx);
	IArrayObject<UnicodeString>* realParts = split(retPath, ctx);
	int const maxLoop = parts->length;
	for(int i = 0; i != maxLoop; ++i){
		UnicodeString* cseg = parts->get(i);

		if(cseg->isEmpty(ctx)){
			continue;
		}
		else if(cseg->equals(DOT, ctx)){
			continue;
		}
		else if(cseg->equals(DDOT, ctx)){
			int top = realParts->length - 1;
			realParts->remove(top, ctx);
		}
		else{
			realParts->append(cseg, ctx);
		}
	}

	retPath = new UnicodeString(ctx);
	int const finalLoop = realParts->length;
	for(int i = 0; i != finalLoop; ++i){
		UnicodeString* seg = realParts->get(i);

		if(seg->isEmpty(ctx)){
			continue;
		}

		retPath->append(this->pathSeparator, ctx);
		retPath->append(seg, ctx);

		//char* cstr = retPath->toCString(ctx);
		//int len = strlen(cstr);
		//::write(STDOUT_FILENO, cstr, len);
		//::write(STDOUT_FILENO, "\n", 1);
	}

	return retPath;
}

UnicodeString* File::__getAbsolutePath(ThreadContext* ctx){
	const char* src = path->toCString(ctx);
	char* realp = realpath(src, nullptr);

	delete [] src;

	if(realp == nullptr){
		return nullptr;
	}

	UnicodeString* ret = new UnicodeString(realp, ctx);
	free(realp);

	return ret;
}

bool File::isDirectory(ThreadContext* ctx)
{
	struct stat  st;
	char* src = path->toCString(ctx);

	int ret = stat(src, &st);
	delete [] src;

	if(ret != 0){
		return false;
	}
	return (st.st_mode & S_IFMT) == S_IFDIR;
}
bool File::isFile(ThreadContext* ctx)
{
	struct stat  st;
	char* src = path->toCString(ctx);

	int ret = stat(src, &st);
	delete [] src;

	if(ret != 0){
		return false;
	}
	return (st.st_mode & S_IFMT) != S_IFDIR;
}
bool File::isHidden(ThreadContext* ctx)
{
	UnicodeString regex(".", ctx);
	return this->pathSeparator->startsWith(&regex, ctx);
}

int File::length(ThreadContext* ctx)
{
	struct stat  st;
	char* src = path->toCString(ctx);

	int ret = stat(src, &st);
	delete [] src;

	if(ret != 0){
		return false;
	}

	return st.st_size;
}

ArrayObject<UnicodeString>* File::list(ThreadContext* ctx)
{
	ArrayObject<UnicodeString>* array = new ArrayObject<UnicodeString>(ctx);
	const char *dirname = this->path->toCString(ctx);

	DIR* dp=opendir(dirname);
	delete dirname;

	if(dp == 0){
		return 0;
	}

	struct dirent* dent;
    do{
        dent = readdir(dp);
        if (dent!=0){
        	// std::cout << dent->d_name << std::endl;
        	UnicodeString *newPath = new UnicodeString(dent->d_name, ctx);
        	array->append(newPath, ctx);
        }
    }while(dent != 0);

    closedir(dp);

	return array;
}
ArrayObject<File>* File::listFiles(ThreadContext* ctx)
{
	ArrayObject<File>* array = new ArrayObject<File>(ctx);
	const char *dirname = this->path->toCString(ctx);

	DIR* dp=opendir(dirname);
	delete [] dirname;

	if(dp == 0){
		return 0;
	}

	struct dirent* dent;
    do{
        dent = readdir(dp);
        if (dent!=0){
        	// std::cout << dent->d_name << std::endl;
        	char* nm = dent->d_name;
        	if(::strcmp(nm, ".") == 0 || ::strcmp(nm, "..") == 0){
        		continue;
        	}

        	UnicodeString* base = this->getAbsolutePath(ctx);

        	UnicodeString *newPath = new UnicodeString(dent->d_name, ctx);

        	base->append(L'/', ctx)->append(newPath, ctx);

        	File *newFile = new File(base, ctx);

        	newPath = newFile->getAbsolutePath(ctx);
    		array->append(newFile, ctx);
        }
    }while(dent != nullptr);

    closedir(dp);

	return array;
}

bool File::mkdirs(ThreadContext* ctx)
{
	UnicodeString* src = getAbsolutePath(ctx);

	IArrayObject<UnicodeString>* parts = split(src, ctx);

	UnicodeString *path = new UnicodeString(512, ctx);
	int const maxLoop = parts->length;
	for(int i = 0; i != maxLoop; ++i){
		UnicodeString* seg = parts->get(i);

		if(seg->isEmpty(ctx)){
			continue;
		}
		if(seg->equals(DOT, ctx)){
			continue;
		}

		path->append(this->pathSeparator, ctx);
		path->append(seg, ctx);

		File* file = new File(path, ctx);

		bool ex = file->exists(ctx);
		if(!ex){
			char* dirPath = path->toCString(ctx);
			mkdir(dirPath, S_IRUSR | S_IWUSR | S_IXUSR |         /* rwx */
	                S_IRGRP | S_IWGRP | S_IXGRP |         /* rwx */
	                S_IROTH | S_IXOTH | S_IXOTH);

			delete [] dirPath;
		}
	}

	return true;
}

bool File::deleteFile(ThreadContext* ctx)
{
	const char *from = this->path->toCString(ctx);
	int ret = remove(from);

	delete [] from;

	return ret;
}

bool File::renameTo(File* dest, ThreadContext* ctx)
{
	char *from = this->path->toCString(ctx);
	char * to = dest->getAbsolutePath(ctx)->toCString(ctx);

	int ret = rename(from, to);

	delete [] from;
	delete [] to;

	return ret == 0;
}

long long File::lastModified(ThreadContext* ctx)
{
	struct stat  st;
	char* src = path->toCString(ctx);

	stat(src, &st);

	long long milli =  ((long long)st.st_mtim.tv_sec * 1000) + ((long long)st.st_mtim.tv_nsec / 1000000);

	delete [] src;

	return milli;
}

}}
