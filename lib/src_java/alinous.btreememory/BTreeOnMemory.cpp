#include "includes.h"


namespace alinous {namespace btreememory {





bool BTreeOnMemory::__init_done = __init_static_variables();
bool BTreeOnMemory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeOnMemory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeOnMemory::BTreeOnMemory(int nodeCapacity, ThreadContext* ctx) throw()  : IObject(ctx), IBTree(ctx), rootNode(nullptr), nodeCapacity(0)
{
	this->nodeCapacity = nodeCapacity;
}
void BTreeOnMemory::__construct_impl(int nodeCapacity, ThreadContext* ctx) throw() 
{
	this->nodeCapacity = nodeCapacity;
}
 BTreeOnMemory::~BTreeOnMemory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeOnMemory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeOnMemory", L"~BTreeOnMemory");
	__e_obj1.add(this->rootNode, this);
	rootNode = nullptr;
	if(!prepare){
		return;
	}
}
IBTreeNode* BTreeOnMemory::getRootNode(ThreadContext* ctx)
{
	__builtin_prefetch(this->rootNode);
	return this->rootNode;
}
MemoryBTreeMachine* BTreeOnMemory::newMachine(ThreadContext* ctx)
{
	if(__builtin_expect(this->rootNode == nullptr, 0))
	{
		putRooNode(ctx);
	}
	IBTreeNode* rootObj = getRootNode(ctx);
	MemoryBTreeMachine* machine = (new(ctx) MemoryBTreeMachine(rootObj, this, ctx));
	return machine;
}
void BTreeOnMemory::putKey(IBTreeKey* key, MemoryBTreeMachine* machine, ThreadContext* ctx)
{
	if(__builtin_expect(this->rootNode == nullptr, 0))
	{
		putRooNode(ctx);
	}
	MBTreeLeafNode* newNode = (new(ctx) MBTreeLeafNode(key, ctx));
	machine->insertLeaf(newNode, ctx);
	machine->reset(ctx);
}
ArrayList<IBTreeValue>* BTreeOnMemory::getValues(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->rootNode == nullptr)
	{
		return nullptr;
	}
	MBTreeLeafNode* node = static_cast<MBTreeLeafNode*>(findByKey(key, ctx));
	if(node == nullptr)
	{
		return nullptr;
	}
	return node->getValues(ctx);
}
IBTreeNode* BTreeOnMemory::findByKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->rootNode == nullptr)
	{
		return nullptr;
	}
	IBTreeNode* node = this->getRootNode(ctx);
	while(!node->isHasLeaf(ctx))
	{
		node = node->getNodeAtInsertPosition(key, ctx);
	}
	IBTreeNode* leaf = node->getNodeAtInsertPosition(key, ctx);
	if(leaf == nullptr)
	{
		return nullptr;
	}
	if(leaf->getKey(ctx)->equals(key, ctx))
	{
		return leaf;
	}
	return nullptr;
}
void BTreeOnMemory::setRoot(IBTreeNode* newRoot, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->rootNode), newRoot, IBTreeNode);
}
int BTreeOnMemory::getNodeCapacity(ThreadContext* ctx) throw() 
{
	return nodeCapacity;
}
bool BTreeOnMemory::isEmpty(ThreadContext* ctx) throw() 
{
	return this->rootNode == nullptr;
}
void BTreeOnMemory::initTreeStorage(int nodeCapacity, int keyType, int valueType, long long capacity, long long BLOCK_SIZE, ThreadContext* ctx)
{
}
void BTreeOnMemory::open(ThreadContext* ctx)
{
}
void BTreeOnMemory::close(ThreadContext* ctx)
{
}
bool BTreeOnMemory::isOpened(ThreadContext* ctx) throw() 
{
	return true;
}
void BTreeOnMemory::putKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->rootNode == nullptr)
	{
		putRooNode(ctx);
	}
	MBTreeLeafNode* node = static_cast<MBTreeLeafNode*>(findByKey(key, ctx));
	if(node == nullptr)
	{
		node = internalPutKey(key, ctx);
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->contains(value, ctx))
	{
		values->remove(value, ctx);
	}
	values->add(value, ctx);
}
void BTreeOnMemory::putKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->rootNode == nullptr)
	{
		putRooNode(ctx);
	}
	MBTreeLeafNode* newNode = (new(ctx) MBTreeLeafNode(key, ctx));
	IBTreeNode* rootObj = getRootNode(ctx);
	MemoryBTreeMachine* machine = (new(ctx) MemoryBTreeMachine(rootObj, this, ctx));
	machine->insertLeaf(newNode, ctx);
	machine->destroy(ctx);
}
void BTreeOnMemory::appendKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->rootNode == nullptr)
	{
		putRooNode(ctx);
	}
	MBTreeLeafNode* node = static_cast<MBTreeLeafNode*>(findByKey(key, ctx));
	if(node == nullptr)
	{
		node = (new(ctx) MBTreeLeafNode(key, ctx));
		node->addLeafNode(node, ctx);
	}
	node->getValues(ctx)->add(value, ctx);
}
void BTreeOnMemory::putRooNode(ThreadContext* ctx)
{
	__GC_MV(this, &(this->rootNode), (new(ctx) MBTreeMaxLeafContainer(this->nodeCapacity, nullptr, ctx)), IBTreeNode);
}
MBTreeLeafNode* BTreeOnMemory::internalPutKey(IBTreeKey* key, ThreadContext* ctx)
{
	MBTreeLeafNode* newNode = (new(ctx) MBTreeLeafNode(key, ctx));
	IBTreeNode* rootObj = getRootNode(ctx);
	MemoryBTreeMachine* machine = (new(ctx) MemoryBTreeMachine(rootObj, this, ctx));
	machine->insertLeaf(newNode, ctx);
	machine->destroy(ctx);
	return newNode;
}
}}

