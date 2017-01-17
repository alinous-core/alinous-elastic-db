#include "includes.h"


namespace alinous {namespace compile {namespace expression {





constexpr const int IDomSegment::TYPE_NORMAL;
constexpr const int IDomSegment::TYPE_INDEX;
bool IDomSegment::__init_done = __init_static_variables();
bool IDomSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDomSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDomSegment::~IDomSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDomSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
IDomSegment* IDomSegment::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int type = fetcher->fetchInt(ctx);
	IDomSegment* seg = nullptr;
	switch(type) {
	case TYPE_NORMAL:
		seg = (new(ctx) DomNameSegment(ctx));
		break ;
	case TYPE_INDEX:
		seg = (new(ctx) DomIndexSegment(ctx));
		break ;
	default:
		return nullptr;
		break;
	}
	seg->fromFileEntry(fetcher, ctx);
	return seg;
}
}}}

