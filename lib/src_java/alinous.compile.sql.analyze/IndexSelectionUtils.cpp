#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/IndexSelectionUtils.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool IndexSelectionUtils::__init_done = __init_static_variables();
bool IndexSelectionUtils::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexSelectionUtils", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexSelectionUtils::IndexSelectionUtils(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IndexSelectionUtils::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IndexSelectionUtils::~IndexSelectionUtils() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexSelectionUtils::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
ScanTableIndexMetadata* IndexSelectionUtils::getMinimumColumnIndexMetadata(ArrayList<ScanTableIndexMetadata>* abindexes, ThreadContext* ctx) throw() 
{
	int diff = -1;
	ScanTableIndexMetadata* bestindex = nullptr;
	int maxLoop = abindexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIndexMetadata* indexMeta = abindexes->get(i, ctx);
		int indexSize = indexMeta->getColumns(ctx)->size(ctx);
		if(diff < 0 || indexSize < diff)
		{
			bestindex = indexMeta;
			diff = indexSize;
		}
	}
	return bestindex;
}
ScanTableIndexMetadata* IndexSelectionUtils::selectIndex(ArrayList<ScanTableColumnIdentifier>* columnIdentifiers, ArrayList<ScanTableIndexMetadata>* abindexes, ThreadContext* ctx) throw() 
{
	int diff = -1;
	ScanTableIndexMetadata* bestindex = nullptr;
	int maxLoop = abindexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIndexMetadata* indexMeta = abindexes->get(i, ctx);
		int indexSize = indexMeta->getColumns(ctx)->size(ctx);
		if(indexSize == columnIdentifiers->size(ctx))
		{
			return indexMeta;
		}
		int currentDiff = indexMeta->getColumns(ctx)->size(ctx) - indexSize;
		if(diff < 0 || currentDiff < diff)
		{
			bestindex = indexMeta;
			diff = currentDiff;
		}
	}
	return bestindex;
}
void IndexSelectionUtils::__cleanUp(ThreadContext* ctx){
}
}}}}

