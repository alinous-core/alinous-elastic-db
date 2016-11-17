#include "includes.h"


namespace alinous {namespace html {namespace xpath {namespace match {





bool MatchCursor::__init_done = __init_static_variables();
bool MatchCursor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MatchCursor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MatchCursor::MatchCursor(DomNode* baseObj, ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), baseObj(nullptr), ptr(nullptr), last_ptr(nullptr), stopNode(nullptr)
{
	__GC_MV(this, &(this->baseObj), baseObj, DomNode);
}
void MatchCursor::__construct_impl(DomNode* baseObj, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->baseObj), baseObj, DomNode);
}
 MatchCursor::~MatchCursor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MatchCursor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MatchCursor", L"~MatchCursor");
	__e_obj1.add(this->baseObj, this);
	baseObj = nullptr;
	__e_obj1.add(this->ptr, this);
	ptr = nullptr;
	__e_obj1.add(this->last_ptr, this);
	last_ptr = nullptr;
	__e_obj1.add(this->stopNode, this);
	stopNode = nullptr;
	if(!prepare){
		return;
	}
}
void MatchCursor::gotoParent(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->ptr), this->ptr->getParent(ctx), DomNode);
}
IXpathElement::ScanPolicy MatchCursor::getScanPolicy(ThreadContext* ctx) throw() 
{
	return scanPolicy;
}
void MatchCursor::setScanPolicy(IXpathElement::ScanPolicy scanPolicy, ThreadContext* ctx) throw() 
{
	this->scanPolicy = scanPolicy;
	setupFirstPtr(ctx);
}
void MatchCursor::caluculateStopNode(ThreadContext* ctx) throw() 
{
	if(this->ptr == nullptr)
	{
		return;
	}
	DomNode* grandNode = this->ptr->getParent(ctx)->getParent(ctx);
	if(grandNode == nullptr)
	{
		return;
	}
	DomNode* parent = this->ptr->getParent(ctx);
	int index = grandNode->getChildNodeIndexOf(parent, ctx) + 1;
	__GC_MV(this, &(this->stopNode), grandNode->getChildNodeAt(index, ctx), DomNode);
}
void MatchCursor::caluculateScanPolicy(IXpathElement::ScanPolicy scanPolicy, ThreadContext* ctx)
{
	this->scanPolicy = scanPolicy;
	setupFirstPtr(ctx);
}
DomNode* MatchCursor::getNext(ThreadContext* ctx) throw() 
{
	switch(this->scanPolicy) {
	case IXpathElement::ScanPolicy::scan_all_inherited_children:
		return scanAllInheritedChildren(ctx);
	case IXpathElement::ScanPolicy::scan_this_only:
		return scanThis(ctx);
	case IXpathElement::ScanPolicy::scan_children:
		return scanChildren(ctx);
	default:
		break ;
	}
	return nullptr;
}
void MatchCursor::setupFirstPtr(ThreadContext* ctx) throw() 
{
	DomNode* current = this->baseObj;
	if(this->ptr != nullptr)
	{
		current = this->ptr;
	}
	switch(this->scanPolicy) {
	case IXpathElement::ScanPolicy::scan_all_inherited_children:
	case IXpathElement::ScanPolicy::scan_children:
		__GC_MV(this, &(this->ptr), current->getChildNodeAt(0, ctx), DomNode);
		break ;
	case IXpathElement::ScanPolicy::scan_this_only:
		__GC_MV(this, &(this->ptr), current, DomNode);
		break ;
	default:
		break ;
	}
}
DomNode* MatchCursor::scanAllInheritedChildren(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->last_ptr), this->ptr, DomNode);
	if(this->ptr != nullptr)
	{
		__GC_MV(this, &(this->ptr), this->ptr->getNextNode(ctx), DomNode);
	}
	if(this->stopNode != nullptr && this->ptr == this->stopNode)
	{
		__GC_MV(this, &(this->ptr), nullptr, DomNode);
	}
	return this->last_ptr;
}
DomNode* MatchCursor::scanChildren(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->last_ptr), this->ptr, DomNode);
	int index = this->baseObj->getChildNodeIndexOf(this->ptr, ctx);
	if(index < 0)
	{
		__GC_MV(this, &(this->ptr), nullptr, DomNode);
		return this->last_ptr;
	}
	index ++ ;
	__GC_MV(this, &(this->ptr), this->baseObj->getChildNodeAt(index, ctx), DomNode);
	return this->last_ptr;
}
DomNode* MatchCursor::scanThis(ThreadContext* ctx) throw() 
{
	if(this->last_ptr == nullptr)
	{
		__GC_MV(this, &(this->last_ptr), this->ptr, DomNode);
		return this->ptr;
	}
	return nullptr;
}
}}}}

