#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/Node.h"
#include "alinous.system.config.remote/Nodes.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool Nodes::__init_done = __init_static_variables();
bool Nodes::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Nodes", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Nodes::Nodes(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), list(GCUtils<List<Node> >::ins(this, (new(ctx) ArrayList<Node>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void Nodes::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Nodes::~Nodes() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Nodes::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Nodes", L"~Nodes");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void Nodes::addNode(Node* node, ThreadContext* ctx) throw() 
{
	this->list->add(node, ctx);
}
List<Node>* Nodes::getList(ThreadContext* ctx) throw() 
{
	return list;
}
Nodes* Nodes::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, String* alinousHome, ThreadContext* ctx)
{
	Nodes* ref = (new(ctx) Nodes(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1014(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* cnd = it->next(ctx);
		DomNode* dom = cnd->getCandidateDom(ctx);
		Node* node = Node::parseInstance(dom, document, matcher, alinousHome, ctx);
		ref->addNode(node, ctx);
	}
	return ref;
}
void Nodes::__cleanUp(ThreadContext* ctx){
}
}}}}

