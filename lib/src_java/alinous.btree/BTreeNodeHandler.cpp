#include "includes.h"


namespace alinous {namespace btree {





bool BTreeNodeHandler::__init_done = __init_static_variables();
bool BTreeNodeHandler::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeNodeHandler", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeNodeHandler::BTreeNodeHandler(IArrayObject<NodeRef>* nodes, int nodeUsed, int length, BTreeNodeLoader* loader, AbstractNode* theNode, ThreadContext* ctx) throw()  : IObject(ctx), nodes(nullptr), nodeUsed(0), length(0), loader(nullptr), theNode(nullptr), loaded(0), sorted(0), childLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
	__GC_MV(this, &(this->nodes), nodes, IArrayObject<NodeRef>);
	this->nodeUsed = nodeUsed;
	this->length = length;
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
	__GC_MV(this, &(this->theNode), static_cast<IBTreeNode*>(theNode), IBTreeNode);
	this->loaded = false;
	this->sorted = true;
}
void BTreeNodeHandler::__construct_impl(IArrayObject<NodeRef>* nodes, int nodeUsed, int length, BTreeNodeLoader* loader, AbstractNode* theNode, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->nodes), nodes, IArrayObject<NodeRef>);
	this->nodeUsed = nodeUsed;
	this->length = length;
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
	__GC_MV(this, &(this->theNode), static_cast<IBTreeNode*>(theNode), IBTreeNode);
	this->loaded = false;
	this->sorted = true;
}
 BTreeNodeHandler::~BTreeNodeHandler() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeNodeHandler::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeNodeHandler", L"~BTreeNodeHandler");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	__e_obj1.add(this->loader, this);
	loader = nullptr;
	__e_obj1.add(this->theNode, this);
	theNode = nullptr;
	__e_obj1.add(this->childLock, this);
	childLock = nullptr;
	if(!prepare){
		return;
	}
}
bool BTreeNodeHandler::putNode(IBTreeNode* btNode, bool ignoreOverflow, bool move, ThreadContext* ctx)
{
	NodeRef* newNode = (new(ctx) NodeRef(ctx));
	newNode->filePointer = btNode->getFilePointer(ctx);
	__GC_MV(newNode, &(newNode->node), btNode, IBTreeNode);
	int index = indexOfInsert(newNode, ctx);
	if(!ignoreOverflow && index == this->length)
	{
		return false;
	}
	for(int i = this->nodeUsed; i != index; i -- )
	{
		this->nodes->set(this->nodes->get(i - 1),i, ctx);
	}
	this->nodes->set(newNode,index, ctx);
	this->nodeUsed ++ ;
	if(!move)
	{
		btNode->use(ctx);
	}
	this->theNode->setNodeUsed(this->nodeUsed, ctx);
	return true;
}
IBTreeNode* BTreeNodeHandler::removeNode(IBTreeKey* key, ThreadContext* ctx)
{
	int index = indexOf(key, ctx);
	if(index < 0)
	{
		return nullptr;
	}
	IBTreeNode* node = this->nodes->get(index)->node;
	removeNode(index, 1, ctx);
	return node;
}
void BTreeNodeHandler::removeNode(int index, int count, ThreadContext* ctx)
{
	int copySize = this->nodeUsed - index - count;
	for(int i = 0; i != copySize; i ++ )
	{
		int src = i + index + count;
		this->nodes->set(this->nodes->get(src),i + index, ctx);
		this->nodes->set(nullptr,src, ctx);
	}
	this->nodeUsed = this->nodeUsed - count;
	this->theNode->setNodeUsed(this->nodeUsed, ctx);
}
void BTreeNodeHandler::load(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->childLock, ctx);
		if(this->loaded)
		{
			return;
		}
		int max = this->nodeUsed;
		for(int i = 0; i != max; ++i)
		{
			__GC_MV(nodes->get(i), &(this->nodes->get(i)->node), this->loader->loadBTreeNode(this->nodes->get(i)->filePointer, ctx), IBTreeNode);
		}
		this->loaded = true;
	}
}
void BTreeNodeHandler::unload(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->childLock, ctx);
		if(!this->loaded)
		{
			return;
		}
		int max = this->nodeUsed;
		for(int i = 0; i != max; ++i)
		{
			this->nodes->get(i)->node->endUse(ctx);
			__GC_MV(nodes->get(i), &(this->nodes->get(i)->node), nullptr, IBTreeNode);
		}
		this->loaded = false;
	}
}
int BTreeNodeHandler::nodeToGoDown(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	if(!sorted)
	{
		sort(ctx);
	}
	int begin = 0;
	int end = this->nodeUsed - 1;
	int mid = (begin + end) / 2;
	IArrayObject<NodeRef>* _root = this->nodes;
	while(begin <= end)
	{
		mid = (begin + end) / 2;
		if(_root->get(mid)->node->getKey(ctx)->compareTo(key, ctx) == 0)
		{
			return mid;
		}
				else 
		{
			if(_root->get(mid)->node->getKey(ctx)->compareTo(key, ctx) < 0)
			{
				begin = mid + 1;
			}
						else 
			{
				end = mid - 1;
			}
		}
	}
	if(end < 0)
	{
		return 0;
	}
	if(_root->get(end)->node->getKey(ctx)->compareTo(key, ctx) > 0)
	{
		return end;
	}
	if(begin >= this->nodeUsed)
	{
		return this->nodeUsed;
	}
	if(_root->get(begin)->node->getKey(ctx)->compareTo(key, ctx) > 0)
	{
		return begin;
	}
	return this->nodeUsed;
}
int BTreeNodeHandler::indexOf(NodeRef* value, ThreadContext* ctx) throw() 
{
	int begin = 0;
	int end = this->nodeUsed - 1;
	int mid = (begin + end) / 2;
	IArrayObject<NodeRef>* _root = this->nodes;
	while(begin <= end)
	{
		mid = (begin + end) / 2;
		if(_root->get(mid)->compareTo(value, ctx) == 0)
		{
			return mid;
		}
				else 
		{
			if(_root->get(mid)->compareTo(value, ctx) < 0)
			{
				begin = mid + 1;
			}
						else 
			{
				end = mid - 1;
			}
		}
	}
	return -1;
}
int BTreeNodeHandler::indexOf(IBTreeKey* value, ThreadContext* ctx) throw() 
{
	int begin = 0;
	int end = this->nodeUsed - 1;
	int mid = (begin + end) / 2;
	IArrayObject<NodeRef>* _root = this->nodes;
	while(begin <= end)
	{
		mid = (begin + end) / 2;
		if(_root->get(mid)->node->getKey(ctx)->compareTo(value, ctx) == 0)
		{
			return mid;
		}
				else 
		{
			if(_root->get(mid)->node->getKey(ctx)->compareTo(value, ctx) < 0)
			{
				begin = mid + 1;
			}
						else 
			{
				end = mid - 1;
			}
		}
	}
	return -1;
}
void BTreeNodeHandler::sort(ThreadContext* ctx) throw() 
{
	int length = this->nodeUsed;
	int middle = (length) / 2;
	for(int i = middle; i >= 0; i -- )
	{
		downheap(i, length - 1, ctx);
	}
	for(int i = length - 1; i > 0; i -- )
	{
		swap(0, i, ctx);
		downheap(0, i - 1, ctx);
	}
}
void BTreeNodeHandler::swap(int i, int j, ThreadContext* ctx) throw() 
{
	NodeRef* tmp = this->nodes->get(i);
	this->nodes->set(this->nodes->get(j),i, ctx);
	this->nodes->set(tmp,j, ctx);
}
void BTreeNodeHandler::setNodeUsed(int nodeUsed, ThreadContext* ctx) throw() 
{
	this->nodeUsed = nodeUsed;
}
bool BTreeNodeHandler::isLoaded(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->childLock, ctx);
		return loaded;
	}
}
int BTreeNodeHandler::indexOfInsert(NodeRef* value, ThreadContext* ctx) throw() 
{
	int begin = 0;
	int end = this->nodeUsed - 1;
	int mid = (begin + end) / 2;
	IArrayObject<NodeRef>* _root = this->nodes;
	while(begin <= end)
	{
		mid = (begin + end) / 2;
		if(_root->get(mid)->compareTo(value, ctx) == 0)
		{
			return mid;
		}
				else 
		{
			if(_root->get(mid)->compareTo(value, ctx) < 0)
			{
				begin = mid + 1;
			}
						else 
			{
				end = mid - 1;
			}
		}
	}
	if(end < 0)
	{
		return 0;
	}
	if(_root->get(end)->compareTo(value, ctx) > 0)
	{
		return end;
	}
	if(begin >= this->nodeUsed)
	{
		return this->nodeUsed;
	}
	if(_root->get(begin)->compareTo(value, ctx) > 0)
	{
		return begin;
	}
	return this->nodeUsed;
}
void BTreeNodeHandler::downheap(int rootDefault, int leaf, ThreadContext* ctx) throw() 
{
	int root = rootDefault;
	int left = (root + 1) * 2 - 1;
	;
	int right = left + 1;
	NodeRef* leafMax = 0;
	NodeRef* rootValue = nullptr;
	while(left <= leaf)
	{
		if(right <= leaf)
		{
			left = this->nodes->get(left)->compareTo(this->nodes->get(right), ctx) < 0 ? right : left;
		}
		leafMax = this->nodes->get(left);
		rootValue = this->nodes->get(root);
		if(leafMax->compareTo(rootValue, ctx) < 0)
		{
			return;
		}
		swap(root, left, ctx);
		root = left;
		left = (root + 1) * 2 - 1;
		right = left + 1;
	}
}
}}

