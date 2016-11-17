#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace analyze {





constexpr const int JoinMatchExpression::NO_INDEX;
constexpr const int JoinMatchExpression::LEFT_INDEX;
constexpr const int JoinMatchExpression::RIGHT_INDEX;
constexpr const int JoinMatchExpression::BOTH_INDEX;
bool JoinMatchExpression::__init_done = __init_static_variables();
bool JoinMatchExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinMatchExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinMatchExpression::JoinMatchExpression(SQLEqualityExpression* exp, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw()  : IObject(ctx), exp(nullptr), leftMetadata(nullptr), rightMetadata(nullptr), leftColumn(nullptr), rightColumn(nullptr), leftIndex(nullptr), rightIndex(nullptr), indexStatus(0)
{
	__GC_MV(this, &(this->exp), exp, SQLEqualityExpression);
	__GC_MV(this, &(this->leftMetadata), leftMetadata, ScanTableMetadata);
	__GC_MV(this, &(this->rightMetadata), rightMetadata, ScanTableMetadata);
	this->indexStatus = 0;
}
void JoinMatchExpression::__construct_impl(SQLEqualityExpression* exp, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, SQLEqualityExpression);
	__GC_MV(this, &(this->leftMetadata), leftMetadata, ScanTableMetadata);
	__GC_MV(this, &(this->rightMetadata), rightMetadata, ScanTableMetadata);
	this->indexStatus = 0;
}
 JoinMatchExpression::~JoinMatchExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinMatchExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinMatchExpression", L"~JoinMatchExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->leftMetadata, this);
	leftMetadata = nullptr;
	__e_obj1.add(this->rightMetadata, this);
	rightMetadata = nullptr;
	__e_obj1.add(this->leftColumn, this);
	leftColumn = nullptr;
	__e_obj1.add(this->rightColumn, this);
	rightColumn = nullptr;
	__e_obj1.add(this->leftIndex, this);
	leftIndex = nullptr;
	__e_obj1.add(this->rightIndex, this);
	rightIndex = nullptr;
	if(!prepare){
		return;
	}
}
bool JoinMatchExpression::validate(ThreadContext* ctx) throw() 
{
	ISQLExpression* e = exp->getLeft(ctx);
	if(this->leftMetadata->hasTable(e, ctx))
	{
		__GC_MV(this, &(this->leftColumn), e->getColumns(ctx)->get(0, ctx), ScanTableColumnIdentifier);
		ArrayList<ScanTableColumnIdentifier>* columns = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
		columns->add(this->leftColumn, ctx);
		ArrayList<ScanTableIndexMetadata>* indexes = this->leftMetadata->getAbailableIndexes(this->leftColumn->getTable(ctx), columns, ctx);
		if(!indexes->isEmpty(ctx))
		{
			__GC_MV(this, &(this->leftIndex), indexes->get(0, ctx), ScanTableIndexMetadata);
		}
	}
	if(this->rightMetadata->hasTable(e, ctx))
	{
		__GC_MV(this, &(this->rightColumn), e->getColumns(ctx)->get(0, ctx), ScanTableColumnIdentifier);
		ArrayList<ScanTableColumnIdentifier>* columns = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
		columns->add(this->rightColumn, ctx);
		ArrayList<ScanTableIndexMetadata>* indexes = this->rightMetadata->getAbailableIndexes(this->rightColumn->getTable(ctx), columns, ctx);
		if(!indexes->isEmpty(ctx))
		{
			__GC_MV(this, &(this->rightIndex), indexes->get(0, ctx), ScanTableIndexMetadata);
		}
	}
	e = exp->getRight(ctx);
	if(this->leftColumn == nullptr && this->leftMetadata->hasTable(e, ctx))
	{
		__GC_MV(this, &(this->leftColumn), e->getColumns(ctx)->get(0, ctx), ScanTableColumnIdentifier);
		ArrayList<ScanTableColumnIdentifier>* columns = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
		columns->add(this->leftColumn, ctx);
		ArrayList<ScanTableIndexMetadata>* indexes = this->leftMetadata->getAbailableIndexes(this->leftColumn->getTable(ctx), columns, ctx);
		if(!indexes->isEmpty(ctx))
		{
			__GC_MV(this, &(this->leftIndex), indexes->get(0, ctx), ScanTableIndexMetadata);
		}
	}
	if(this->rightColumn == nullptr && this->rightMetadata->hasTable(e, ctx))
	{
		__GC_MV(this, &(this->rightColumn), e->getColumns(ctx)->get(0, ctx), ScanTableColumnIdentifier);
		ArrayList<ScanTableColumnIdentifier>* columns = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
		columns->add(this->rightColumn, ctx);
		ArrayList<ScanTableIndexMetadata>* indexes = this->rightMetadata->getAbailableIndexes(this->rightColumn->getTable(ctx), columns, ctx);
		if(!indexes->isEmpty(ctx))
		{
			__GC_MV(this, &(this->rightIndex), indexes->get(0, ctx), ScanTableIndexMetadata);
		}
	}
	if(this->leftColumn != nullptr && this->rightColumn != nullptr && !this->leftColumn->equals(this->rightColumn, ctx))
	{
		if(this->leftIndex == nullptr && this->rightIndex == nullptr)
		{
			this->indexStatus = NO_INDEX;
		}
				else 
		{
			if(this->leftIndex != nullptr && this->rightIndex == nullptr)
			{
				this->indexStatus = LEFT_INDEX;
			}
						else 
			{
				if(this->leftIndex == nullptr && this->rightIndex != nullptr)
				{
					this->indexStatus = RIGHT_INDEX;
				}
								else 
				{
					if(this->leftIndex != nullptr && this->rightIndex != nullptr)
					{
						this->indexStatus = BOTH_INDEX;
					}
				}
			}
		}
		return true;
	}
	return false;
}
SQLEqualityExpression* JoinMatchExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void JoinMatchExpression::setExp(SQLEqualityExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, SQLEqualityExpression);
}
ScanTableMetadata* JoinMatchExpression::getLeftMetadata(ThreadContext* ctx) throw() 
{
	return leftMetadata;
}
void JoinMatchExpression::setLeftMetadata(ScanTableMetadata* leftMetadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->leftMetadata), leftMetadata, ScanTableMetadata);
}
ScanTableMetadata* JoinMatchExpression::getRightMetadata(ThreadContext* ctx) throw() 
{
	return rightMetadata;
}
void JoinMatchExpression::setRightMetadata(ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->rightMetadata), rightMetadata, ScanTableMetadata);
}
int JoinMatchExpression::getIndexStatus(ThreadContext* ctx) throw() 
{
	return indexStatus;
}
ScanTableIndexMetadata* JoinMatchExpression::getLeftIndex(ThreadContext* ctx) throw() 
{
	return leftIndex;
}
ScanTableIndexMetadata* JoinMatchExpression::getRightIndex(ThreadContext* ctx) throw() 
{
	return rightIndex;
}
void JoinMatchExpression::setLeftIndex(ScanTableIndexMetadata* leftIndex, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->leftIndex), leftIndex, ScanTableIndexMetadata);
}
void JoinMatchExpression::setRightIndex(ScanTableIndexMetadata* rightIndex, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->rightIndex), rightIndex, ScanTableIndexMetadata);
}
ScanTableColumnIdentifier* JoinMatchExpression::getLeftColumn(ThreadContext* ctx) throw() 
{
	return leftColumn;
}
ScanTableColumnIdentifier* JoinMatchExpression::getRightColumn(ThreadContext* ctx) throw() 
{
	return rightColumn;
}
}}}}

