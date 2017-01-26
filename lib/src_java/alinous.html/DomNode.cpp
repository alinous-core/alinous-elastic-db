#include "includes.h"


namespace alinous {namespace html {





bool DomNode::__init_done = __init_static_variables();
bool DomNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomNode::DomNode(String* name, ThreadContext* ctx) throw()  : IObject(ctx), IDomObject(ctx), attributes(GCUtils<ArrayList<Attribute> >::ins(this, (new(ctx) ArrayList<Attribute>(ctx)), ctx, __FILEW__, __LINE__, L"")), children(GCUtils<ArrayList<IDomObject> >::ins(this, (new(ctx) ArrayList<IDomObject>(ctx)), ctx, __FILEW__, __LINE__, L"")), childNodes(GCUtils<ArrayList<DomNode> >::ins(this, (new(ctx) ArrayList<DomNode>(ctx)), ctx, __FILEW__, __LINE__, L"")), name(nullptr), parent(nullptr), singleEnd(0), xmlHeader(0)
{
	__GC_MV(this, &(this->name), name, String);
}
void DomNode::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
 DomNode::~DomNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomNode", L"~DomNode");
	__e_obj1.add(this->attributes, this);
	attributes = nullptr;
	__e_obj1.add(this->children, this);
	children = nullptr;
	__e_obj1.add(this->childNodes, this);
	childNodes = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	if(!prepare){
		return;
	}
}
void DomNode::removeElement(IDomObject* element, ThreadContext* ctx) throw() 
{
	this->childNodes->remove(static_cast<DomNode*>(element), ctx);
	this->children->remove(element, ctx);
}
int DomNode::getNumChildElement(ThreadContext* ctx) throw() 
{
	return this->children->size(ctx);
}
IDomObject* DomNode::getChildElementAt(int index, ThreadContext* ctx) throw() 
{
	if(index >= children->size(ctx))
	{
		return nullptr;
	}
	return children->get(index, ctx);
}
int DomNode::getChildElementIndexOf(IDomObject* element, ThreadContext* ctx) throw() 
{
	if(!this->children->contains(element, ctx))
	{
		return -1;
	}
	return this->children->indexOf(element, ctx);
}
DomNode* DomNode::getChildNodeAt(int index, ThreadContext* ctx) throw() 
{
	if(index >= childNodes->size(ctx))
	{
		return nullptr;
	}
	return childNodes->get(index, ctx);
}
int DomNode::getChildNodeIndexOf(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!this->childNodes->contains(node, ctx))
	{
		return -1;
	}
	return this->childNodes->indexOf(node, ctx);
}
int DomNode::getNumChildern(ThreadContext* ctx) throw() 
{
	return this->childNodes->size(ctx);
}
IDomObject* DomNode::getNextSibilingElement(ThreadContext* ctx) throw() 
{
	if(this->parent == nullptr)
	{
		return nullptr;
	}
	int index = this->parent->children->indexOf(this, ctx);
	if(index >= (this->parent->children->size(ctx) - 1))
	{
		return this->parent->getNextSibilingElement(ctx);
	}
	index ++ ;
	return this->parent->children->get(index, ctx);
}
IDomObject* DomNode::getNextElement(ThreadContext* ctx) throw() 
{
	if(this->children->isEmpty(ctx))
	{
		return getNextSibilingElement(ctx);
	}
	return this->children->get(0, ctx);
}
DomNode* DomNode::getNextSibilingNode(ThreadContext* ctx) throw() 
{
	if(this->parent == nullptr)
	{
		return nullptr;
	}
	int index = this->parent->childNodes->indexOf(this, ctx);
	if(index >= (this->parent->childNodes->size(ctx) - 1))
	{
		return this->parent->getNextSibilingNode(ctx);
	}
	index ++ ;
	return this->parent->childNodes->get(index, ctx);
}
DomNode* DomNode::getNextNode(ThreadContext* ctx) throw() 
{
	if(this->childNodes->isEmpty(ctx))
	{
		return getNextSibilingNode(ctx);
	}
	return this->childNodes->get(0, ctx);
}
void DomNode::clearChildren(ThreadContext* ctx) throw() 
{
	this->children->clear(ctx);
	this->childNodes->clear(ctx);
}
void DomNode::clearAttributes(ThreadContext* ctx) throw() 
{
	this->attributes->clear(ctx);
}
void DomNode::addAttribute(String* key, String* value, ThreadContext* ctx) throw() 
{
	Attribute* a = (new(ctx) Attribute(ctx));
	a->setName(key, ctx);
	a->setValue(value, ctx);
	this->attributes->add(a, ctx);
}
void DomNode::handleUnclosed(ThreadContext* ctx) throw() 
{
	int index = this->parent->children->indexOf(this, ctx) + 1;
	int indexNode = this->parent->childNodes->indexOf(this, ctx) + 1;
	while(!this->children->isEmpty(ctx))
	{
		IDomObject* d = this->children->get(this->children->size(ctx) - 1, ctx);
		this->children->remove(d, ctx);
		this->childNodes->remove(static_cast<DomNode*>(d), ctx);
		d->setParent(this->parent, ctx);
		this->parent->children->add(index, d, ctx);
		if((dynamic_cast<DomNode*>(d) != 0))
		{
			this->parent->childNodes->add(indexNode, static_cast<DomNode*>(d), ctx);
		}
	}
	this->singleEnd = true;
}
void DomNode::addChild(IDomObject* element, ThreadContext* ctx) throw() 
{
	element->setParent(this, ctx);
	this->children->add(element, ctx);
	if((dynamic_cast<DomNode*>(element) != 0))
	{
		this->childNodes->add(static_cast<DomNode*>(element), ctx);
	}
}
void DomNode::addAttribute(Attribute* attr, ThreadContext* ctx) throw() 
{
	attr->setParent(this, ctx);
	this->attributes->add(attr, ctx);
}
IVariableValue* DomNode::getAttributeValue(String* name, ThreadContext* ctx) throw() 
{
	Iterator<Attribute>* it = this->attributes->iterator(ctx);
	while(it->hasNext(ctx))
	{
		Attribute* at = it->next(ctx);
		if(at->getName(ctx)->equals(name, ctx))
		{
			return (new(ctx) StringValue(at->getValue(ctx), ctx));
		}
	}
	return nullptr;
}
DomNode* DomNode::getParent(ThreadContext* ctx) throw() 
{
	return parent;
}
void DomNode::setParent(DomNode* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, DomNode);
}
String* DomNode::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void DomNode::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
bool DomNode::isSingleEnd(ThreadContext* ctx) throw() 
{
	return singleEnd;
}
void DomNode::setSingleEnd(bool singleEnd, ThreadContext* ctx) throw() 
{
	if(this->name->equals(ConstStr::getCNST_STR_1748(), ctx) && singleEnd)
	{
		throw (new(ctx) RuntimeException(ConstStr::getCNST_STR_1749(), ctx));
	}
	this->singleEnd = singleEnd;
}
IArrayObject<Attribute>* DomNode::getAttributes(ThreadContext* ctx) throw() 
{
	IArrayObject<Attribute>* attrs = this->attributes->toArray(ArrayAllocator<Attribute>::allocate(ctx, this->attributes->size(ctx)), ctx);
	return attrs;
}
void DomNode::setAttributes(IArrayObject<Attribute>* attributes, ThreadContext* ctx) throw() 
{
	this->attributes->clear(ctx);
	for(int i = 0; i < attributes->length; i ++ )
	{
		this->attributes->add(attributes->get(i), ctx);
	}
}
bool DomNode::isXmlHeader(ThreadContext* ctx) throw() 
{
	return xmlHeader;
}
void DomNode::setXmlHeader(bool xmlHeader, ThreadContext* ctx) throw() 
{
	this->xmlHeader = xmlHeader;
}
String* DomNode::getPathString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->parent != nullptr)
	{
		buff->append(this->parent->getPathString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_1007(), ctx);
	buff->append(this->name, ctx);
	return buff->toString(ctx);
}
String* DomNode::getInnerHtml(ThreadContext* ctx) throw() 
{
	if(this->singleEnd)
	{
		return nullptr;
	}
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<IDomObject>* childrenIt = this->children->iterator(ctx);
	while(childrenIt->hasNext(ctx))
	{
		buff->append(childrenIt->next(ctx)->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
String* DomNode::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->singleEnd)
	{
		buff->append(ConstStr::getCNST_STR_1010(), ctx);
		buff->append(this->name, ctx);
		Iterator<Attribute>* it = this->attributes->iterator(ctx);
		while(it->hasNext(ctx))
		{
			Attribute* attr = it->next(ctx);
			buff->append(ConstStr::getCNST_STR_380(), ctx);
			buff->append(attr->toString(ctx), ctx);
		}
		if(this->xmlHeader)
		{
			buff->append(ConstStr::getCNST_STR_82(), ctx);
		}
				else 
		{
			buff->append(ConstStr::getCNST_STR_1750(), ctx);
		}
	}
		else 
	{
		buff->append(ConstStr::getCNST_STR_1010(), ctx);
		buff->append(this->name, ctx);
		Iterator<Attribute>* it = this->attributes->iterator(ctx);
		while(it->hasNext(ctx))
		{
			Attribute* attr = it->next(ctx);
			buff->append(ConstStr::getCNST_STR_380(), ctx);
			buff->append(attr->toString(ctx), ctx);
		}
		buff->append(ConstStr::getCNST_STR_82(), ctx);
		Iterator<IDomObject>* childrenIt = this->children->iterator(ctx);
		while(childrenIt->hasNext(ctx))
		{
			buff->append(childrenIt->next(ctx)->toString(ctx), ctx);
		}
		buff->append(ConstStr::getCNST_STR_1751(), ctx);
		buff->append(this->name, ctx);
		buff->append(ConstStr::getCNST_STR_82(), ctx);
	}
	return buff->toString(ctx);
}
int DomNode::getType(ThreadContext* ctx) throw() 
{
	return IDomObject::TYPE_DOM_NODE;
}
}}

