#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.server/AlinousCoreServer.h"
#include "alinous/AlinousMain.h"

namespace alinous {



constexpr EnumBase __AlinousMain__ArgumentState::__DEFAULT_NULL;
constexpr EnumBase __AlinousMain__ArgumentState::NORMAL_ARG;
constexpr EnumBase __AlinousMain__ArgumentState::ALINOUS_HOME;
constexpr EnumBase __AlinousMain__ArgumentState::DEBUG_PORT;


String* AlinousMain::ARG_ALINOUS_HOME = ConstStr::getCNST_STR_947();
String* AlinousMain::ARG_DEBUG_PORT = ConstStr::getCNST_STR_948();
bool AlinousMain::__init_done = __init_static_variables();
bool AlinousMain::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousMain", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousMain::AlinousMain(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void AlinousMain::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousMain::~AlinousMain() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousMain::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void AlinousMain::main(IArrayObject<String>* args, ThreadContext* ctx) throw() 
{
	{
		try
		{
			doMain(args, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
void AlinousMain::doMain(IArrayObject<String>* args, ThreadContext* ctx)
{
	AlinousMain::ArgumentState state = ArgumentState::NORMAL_ARG;
	String* alinousHome = nullptr;
	int debugPort = -1;
	int maxLoop = args->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* arg = args->get(i);
		switch(state) {
		case AlinousMain::ArgumentState::ALINOUS_HOME:
			alinousHome = arg;
			state = ArgumentState::NORMAL_ARG;
			break ;
		case AlinousMain::ArgumentState::DEBUG_PORT:
			debugPort = Integer::parseInt(arg, ctx);
			state = ArgumentState::NORMAL_ARG;
			break ;
		case AlinousMain::ArgumentState::NORMAL_ARG:
		default:
			state = getNextState(arg, state, ctx);
			if(state == ArgumentState::NORMAL_ARG)
			{
			}
			break ;
		}
	}
	System::out->println(ConstStr::getCNST_STR_945()->clone(ctx)->append(alinousHome, ctx), ctx);
	System::out->println(ConstStr::getCNST_STR_946()->clone(ctx)->append(debugPort, ctx), ctx);
	launchAlinous(alinousHome, debugPort, ctx);
}
void AlinousMain::launchAlinous(String* alinousHome, int debugPort, ThreadContext* ctx)
{
	bool debug = debugPort != -1;
	AlinousCoreServer* server = (new(ctx) AlinousCoreServer(alinousHome, debug, debugPort, ctx));
	server->startHttpServer(3, ctx);
	AlinousDebug::scanf(ctx);
	server->dispose(ctx);
}
AlinousMain::ArgumentState AlinousMain::getNextState(String* arg, AlinousMain::ArgumentState state, ThreadContext* ctx) throw() 
{
	if(arg->equals(ARG_ALINOUS_HOME, ctx))
	{
		return ArgumentState::ALINOUS_HOME;
	}
	if(arg->equals(ARG_DEBUG_PORT, ctx))
	{
		return ArgumentState::DEBUG_PORT;
	}
	return state;
}
void AlinousMain::__cleanUp(ThreadContext* ctx){
}
}

