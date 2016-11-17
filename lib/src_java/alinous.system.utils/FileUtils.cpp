#include "includes.h"


namespace alinous {namespace system {namespace utils {





bool FileUtils::__init_done = __init_static_variables();
bool FileUtils::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileUtils", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileUtils::~FileUtils() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileUtils::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* FileUtils::removeLastSegments(String* formattedpath, int count, ThreadContext* ctx) throw() 
{
	Stack<String>* stack = (new(ctx) Stack<String>(ctx));
	IArrayObject<String>* elements = formattedpath->split(ConstStr::getCNST_STR_984(), ctx);
	int maxLoop = elements->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* str = elements->get(i);
		if(str->length(ctx) == 0 || str->equals(ConstStr::getCNST_STR_947(), ctx))
		{
			continue;
		}
		stack->push(str, ctx);
	}
	for(int i = 0; i != count; ++i)
	{
		stack->pop(ctx);
	}
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<String>* it = stack->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* el = it->next(ctx);
		buff->append(ConstStr::getCNST_STR_984(), ctx)->append(el, ctx);
	}
	return buff->toString(ctx);
}
String* FileUtils::formatAfterAbsolutePath(String* path, ThreadContext* ctx) throw() 
{
	path = path->replace(L'/', File::separator->charAt(0, ctx), ctx);
	Stack<String>* stack = (new(ctx) Stack<String>(ctx));
	IArrayObject<String>* elements = path->split(ConstStr::getCNST_STR_984(), ctx);
	int maxLoop = elements->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* str = elements->get(i);
		if(str->length(ctx) == 0 || str->equals(ConstStr::getCNST_STR_947(), ctx))
		{
			continue;
		}
		if(str->equals(ConstStr::getCNST_STR_1180(), ctx))
		{
			stack->pop(ctx);
			continue;
		}
		stack->push(str, ctx);
	}
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	maxLoop = stack->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* str = stack->get(i, ctx);
		if(str->indexOf(ConstStr::getCNST_STR_381(), ctx) < 0)
		{
			buff->append(ConstStr::getCNST_STR_984(), ctx);
		}
		buff->append(str, ctx);
	}
	return buff->toString(ctx);
}
void FileUtils::removeAll(File* file, ThreadContext* ctx) throw() 
{
	if(file->isDirectory(ctx))
	{
		IArrayObject<File>* files = file->listFiles(ctx);
		for(int i = 0; i != files->length; ++i)
		{
			removeAll(files->get(i), ctx);
		}
	}
	file->_delete(ctx);
}
String* FileUtils::readAllText(String* srcPath, String* encode, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	File* file = (new(ctx) File(srcPath, ctx));
	FileInputStream* fStream = nullptr;
	InputStreamReader* reader = nullptr;
	{
		try
		{
			fStream = (new(ctx) FileInputStream(file, ctx));
			reader = (new(ctx) InputStreamReader(fStream, encode, ctx));
			IArrayObjectPrimitive<wchar_t>* readBuffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 1024);
			int n = 1;
			while(n > 0)
			{
				n = reader->read(readBuffer, 0, readBuffer->length, ctx);
				if(n > 0)
				{
					buff->append(readBuffer, 0, n, ctx);
				}
			}
		}
		catch(Throwable* e)
		{
			if(reader != nullptr)
			{
				{
					try
					{
						reader->close(ctx);
					}
					catch(IOException* e2)
					{
						e2->printStackTrace(ctx);
					}
				}
			}
			if(fStream != nullptr)
			{
				{
					try
					{
						fStream->close(ctx);
					}
					catch(IOException* e2)
					{
						e2->printStackTrace(ctx);
					}
				}
			}
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	if(reader != nullptr)
	{
		{
			try
			{
				reader->close(ctx);
			}
			catch(IOException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	if(fStream != nullptr)
	{
		{
			try
			{
				fStream->close(ctx);
			}
			catch(IOException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	return buff->toString(ctx);
}
}}}

