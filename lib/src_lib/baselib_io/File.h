/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_FILE_H_
#define SYSTEM_FILE_H_

namespace com {namespace google {namespace re2j {
class Pattern;
}}}


namespace java{ namespace io {



class File : public virtual IObject {
public:
	File(UnicodeString* pathname, ThreadContext* ctx);
	virtual ~File();

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	bool canExecute(ThreadContext* ctx){
		return true;
	}
	bool canRead(ThreadContext* ctx){
		return true;
	}

	bool equals(File *obj, ThreadContext* ctx);
	bool exists(ThreadContext* ctx);

	File* getAbsoluteFile(ThreadContext* ctx);
	UnicodeString* getAbsolutePath(ThreadContext* ctx);
private:
	UnicodeString* __getAbsolutePath(ThreadContext* ctx);
public:
	File* getCanonicalFile(ThreadContext* ctx)
	{
		return getAbsoluteFile(ctx);
	}
	UnicodeString* getName(ThreadContext* ctx)
	{
		return 0;
	}
	UnicodeString* getParent(ThreadContext* ctx)
	{
		return 0;
	}
	String* getPath(ThreadContext* ctx)
	{
		return this->pathSeparator;
	}

	bool isAbsolute(ThreadContext* ctx)
	{
		return this->path->startsWith(this->pathSeparator, ctx);
	}
	bool isDirectory(ThreadContext* ctx);
	bool isFile(ThreadContext* ctx);
	bool isHidden(ThreadContext* ctx);
	int length(ThreadContext* ctx);
	ArrayObject<UnicodeString>* list(ThreadContext* ctx);
	ArrayObject<File>* listFiles(ThreadContext* ctx);
	bool mkdirs(ThreadContext* ctx);
	bool _delete(ThreadContext* ctx) {
		return deleteFile(ctx);
	}
	bool deleteFile(ThreadContext* ctx);

	bool renameTo(File* dest, ThreadContext* ctx);

	bool setLastModified(long long time)
	{
		return true;
	}
	long long lastModified(ThreadContext* ctx);


	IArrayObject<UnicodeString>* split(UnicodeString* path, ThreadContext* ctx);
private:
	UnicodeString *pathSeparator;
	UnicodeString *path;
	SysMutex pathMutex;

public:
	static UnicodeString* regexSep;
	static UnicodeString* regexSep2;
	static UnicodeString* DOT;
	static UnicodeString* DDOT;

	static UnicodeString* separator;

	static com::google::re2j::Pattern* sepPattern;

	static bool __init_done;
	static bool __init_static_variables();
	static void __cleanUp(ThreadContext* ctx);
};

}} /* namespace alinous */

#endif /* SYSTEM_FILE_H_ */
