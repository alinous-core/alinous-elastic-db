#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/DomTokenizer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html/DocType.h"
#include "alinous.html/DomComment.h"
#include "alinous.html/DomText.h"
#include "alinous.html/AlinousDomEventHandler.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/Test.h"

namespace alinous {namespace html {





bool Test::__init_done = __init_static_variables();
bool Test::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Test", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Test::Test(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Test::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Test::~Test() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Test::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void Test::main(IArrayObject<String>* args, ThreadContext* ctx) throw() 
{
	String* encode = ConstStr::getCNST_STR_1797();
	String* sourceHtml = readAllText(ConstStr::getCNST_STR_1798(), encode, ctx);
	AlinousDomReplacer* replacer = (new(ctx) AlinousDomReplacer(ctx));
	DomConverter* converter = (new(ctx) DomConverter(sourceHtml, replacer, ctx));
	converter->parse(ctx);
	DomDocument* document = replacer->getDocument(ctx);
	String* html = document->toString(ctx);
	System::out->println(html, ctx);
}
String* Test::readAllText(String* srcPath, String* encode, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	File* file = (new(ctx) File(srcPath, ctx));
	FileInputStream* fStream = nullptr;
	InputStreamReader* reader = nullptr;
	{
		std::function<void(void)> finallyLm2= [&]()
		{
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
		};
		Releaser finalyCaller2(finallyLm2);
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
		catch(FileNotFoundException* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return buff->toString(ctx);
}
void Test::__cleanUp(ThreadContext* ctx){
}
}}

