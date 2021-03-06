#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/AbstractContainerStatement.h"
#include "alinous.html.xpath/XpathOrStatement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/XpathString.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/StringValue.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath/NumberValue.h"
#include "alinous.html.xpath/XpathFunctionArgument.h"
#include "alinous.html.xpath/IXpathFunction.h"
#include "alinous.html.xpath.function/First.h"
#include "alinous.html.xpath.function/Last.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/Xpath2Compare.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/XpathNotStatement.h"
#include "alinous.html.xpath/XpathAndStatement.h"
#include "alinous.html.xpath/XPathParser.h"

namespace alinous {namespace html {namespace xpath {





bool XpathContext::__init_done = __init_static_variables();
bool XpathContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathContext::XpathContext(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), filters(GCUtils<ArrayList<XpathFilter> >::ins(this, (new(ctx) ArrayList<XpathFilter>(ctx)), ctx, __FILEW__, __LINE__, L"")), location(nullptr), identifier(nullptr), index(nullptr), xpath(nullptr)
{
}
void XpathContext::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XpathContext::~XpathContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathContext", L"~XpathContext");
	__e_obj1.add(this->filters, this);
	filters = nullptr;
	__e_obj1.add(this->location, this);
	location = nullptr;
	__e_obj1.add(this->identifier, this);
	identifier = nullptr;
	__e_obj1.add(this->index, this);
	index = nullptr;
	__e_obj1.add(this->xpath, this);
	xpath = nullptr;
	if(!prepare){
		return;
	}
}
IXpathElement::ScanTarget XpathContext::getScanTarget(ThreadContext* ctx) throw() 
{
	if((dynamic_cast<AttributeIdentifier*>(this->identifier) != 0))
	{
		return ScanTarget::attribute;
	}
	return ScanTarget::node;
}
String* XpathContext::getAttributeName(ThreadContext* ctx) throw() 
{
	return (static_cast<AttributeIdentifier*>(this->identifier))->getId(ctx);
}
XpathFilter* XpathContext::getConditionFilter(ThreadContext* ctx) throw() 
{
	if(this->filters->size(ctx) > 0)
	{
		return this->filters->get(0, ctx);
	}
	return nullptr;
}
bool XpathContext::isFirstContext(ThreadContext* ctx) throw() 
{
	return this->xpath->getContexts(ctx)->get(0, ctx)->equals(this, ctx);
}
bool XpathContext::matchPath(DomNode* node, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<AttributeIdentifier*>(identifier) != 0))
	{
		return hasAttribute(static_cast<AttributeIdentifier*>(identifier), node, ctx);
	}
		else 
	{
		if((dynamic_cast<XpathIdentifier*>(identifier) != 0))
		{
			return matchIdentifier(static_cast<XpathIdentifier*>(identifier), node, ctx);
		}
	}
	return false;
}
void XpathContext::setupCurserLocationPolicy(MatchCursor* cursor, ThreadContext* ctx)
{
	if(isFirstContext(ctx) && this->location == nullptr)
	{
		setupRelationalScan(cursor, ctx);
		return;
	}
	if(this->location == nullptr)
	{
		cursor->caluculateScanPolicy(ScanPolicy::scan_all_inherited_children, ctx);
		if((dynamic_cast<AttributeIdentifier*>(this->identifier) != 0))
		{
			cursor->gotoParent(ctx);
		}
		cursor->caluculateStopNode(ctx);
		return;
	}
	this->location->setupLocation(cursor, ctx);
	if((dynamic_cast<AttributeIdentifier*>(this->identifier) != 0) && cursor->getScanPolicy(ctx) == ScanPolicy::scan_children)
	{
		cursor->setScanPolicy(ScanPolicy::scan_this_only, ctx);
		cursor->gotoParent(ctx);
	}
	cursor->caluculateStopNode(ctx);
}
IXpathElement* XpathContext::getIdentifier(ThreadContext* ctx) throw() 
{
	return identifier;
}
void XpathContext::setIdentifier(IXpathStatement* identifier, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->identifier), identifier, IXpathStatement);
}
XpathContextLocation* XpathContext::getLocation(ThreadContext* ctx) throw() 
{
	return location;
}
void XpathContext::setLocation(XpathContextLocation* location, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->location), location, XpathContextLocation);
}
void XpathContext::addFilter(XpathFilter* filter, ThreadContext* ctx) throw() 
{
	if(filter->isIndex(ctx))
	{
		setIndex(filter->getIndexStatement(ctx), ctx);
		return;
	}
	this->filters->add(filter, ctx);
}
IXpathStatement* XpathContext::getIndex(ThreadContext* ctx) throw() 
{
	return index;
}
void XpathContext::setIndex(IXpathStatement* index, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->index), index, IXpathStatement);
}
ArrayList<XpathFilter>* XpathContext::getFilters(ThreadContext* ctx) throw() 
{
	return filters;
}
String* XpathContext::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	if(this->location != nullptr)
	{
		buffer->append(this->location->toString(ctx), ctx);
	}
	if(this->identifier != nullptr)
	{
		buffer->append(this->identifier->toString(ctx), ctx);
	}
	Iterator<XpathFilter>* it = this->filters->iterator(ctx);
	while(it->hasNext(ctx))
	{
		XpathFilter* filter = it->next(ctx);
		buffer->append(filter->toString(ctx), ctx);
	}
	if(this->index != nullptr)
	{
		buffer->append(ConstStr::getCNST_STR_1036(), ctx);
		buffer->append(this->index->toString(ctx), ctx);
		buffer->append(ConstStr::getCNST_STR_564(), ctx);
	}
	return buffer->toString(ctx);
}
Xpath* XpathContext::getXpath(ThreadContext* ctx) throw() 
{
	return xpath;
}
void XpathContext::setXpath(Xpath* xpath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->xpath), xpath, Xpath);
}
bool XpathContext::matchIdentifier(XpathIdentifier* xpathId, DomNode* node, ThreadContext* ctx) throw() 
{
	String* id = xpathId->getId(ctx);
	if(id->equals(ConstStr::getCNST_STR_1042(), ctx))
	{
		return true;
	}
	return id->equals(node->getName(ctx), ctx);
}
bool XpathContext::hasAttribute(AttributeIdentifier* attrId, DomNode* node, ThreadContext* ctx) throw() 
{
	String* attrIdStr = attrId->getId(ctx);
	IArrayObject<Attribute>* nodeAttributes = node->getAttributes(ctx);
	if(attrIdStr->equals(ConstStr::getCNST_STR_1042(), ctx) && nodeAttributes->length > 0)
	{
		return true;
	}
		else 
	{
		if(attrIdStr->equals(ConstStr::getCNST_STR_1042(), ctx) && nodeAttributes->length == 0)
		{
			return false;
		}
	}
	IArrayObject<Attribute>* attrs = node->getAttributes(ctx);
	for(int i = 0; i < attrs->length; i ++ )
	{
		if(attrIdStr->equals(attrs->get(i)->getName(ctx), ctx))
		{
			return true;
		}
	}
	return false;
}
void XpathContext::setupRelationalScan(MatchCursor* cursor, ThreadContext* ctx)
{
	if((dynamic_cast<AttributeIdentifier*>(this->identifier) != 0))
	{
		cursor->setScanPolicy(ScanPolicy::scan_this_only, ctx);
		return;
	}
	cursor->caluculateScanPolicy(ScanPolicy::scan_all_inherited_children, ctx);
	cursor->caluculateStopNode(ctx);
}
void XpathContext::__cleanUp(ThreadContext* ctx){
}
}}}

