#ifndef ALINOUS_COMPILE_ISTATEMENT_H_
#define ALINOUS_COMPILE_ISTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::analyse::SourceValidator;

class __IStatement__StatementType : public EnumBase {
public:
	__IStatement__StatementType() = default;
	constexpr __IStatement__StatementType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __IStatement__StatementType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  ASSIGN{1};
	static constexpr EnumBase  EXPRESSION{2};
	static constexpr EnumBase  RETURN{3};
	static constexpr EnumBase  BLOCK{4};
	static constexpr EnumBase  STMT_LIST{5};
	static constexpr EnumBase  TYPED_VARIABLE_DECLARE{6};
	static constexpr EnumBase  FOR_STATEMENT{7};
	static constexpr EnumBase  FOR_UPDATE_STATEMENT_PART{8};
	static constexpr EnumBase  IF_STATEMENT{9};
	static constexpr EnumBase  LABELED_STATEMENT{10};
	static constexpr EnumBase  WHILE_STATEMENT{11};
	static constexpr EnumBase  DO_WHILE_STATEMENT{12};
	static constexpr EnumBase  SWITCH_STATEMENT{13};
	static constexpr EnumBase  SWITCH_CASE_PART{14};
	static constexpr EnumBase  CASE_STATEMENT{15};
	static constexpr EnumBase  DEFAULT_STATEMENT{16};
	static constexpr EnumBase  BREAK_STATEMENT{17};
	static constexpr EnumBase  CONTINUE_STATEMENT{18};
	static constexpr EnumBase  TRY_STATEMENT{19};
	static constexpr EnumBase  CATCH_STATEMENT{20};
	static constexpr EnumBase  THROW_STATEMENT{21};
	static constexpr EnumBase  FINALLY_STATEMENT{22};
	static constexpr EnumBase  BEGIN{23};
	static constexpr EnumBase  COMMIT{24};
	static constexpr EnumBase  CREATE_TABLE{25};
	static constexpr EnumBase  DELETE{26};
	static constexpr EnumBase  DROP_TABLE{27};
	static constexpr EnumBase  INSERT{28};
	static constexpr EnumBase  ROLLBACK{29};
	static constexpr EnumBase  SELECT{30};
	static constexpr EnumBase  UPDATE{31};
	static constexpr EnumBase  CREATE_INDEX{32};
	static constexpr EnumBase  DROP_INDEX{33};
	static constexpr EnumBase  JOIN_PART{34};
};


class IStatement : public IAlinousElement, public IAlinousVisitorContainer {
public:
	class StatementType : public __IStatement__StatementType {
	public:
		StatementType() = default;constexpr StatementType(const EnumBase& base) :  __IStatement__StatementType(base) {};
	};
public:
	IStatement(const IStatement& base) = default;
public:
	IStatement(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IStatement::StatementType getType(ThreadContext* ctx) throw()  = 0;
	virtual void validate(SourceValidator* validator, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_COMPILE_ISTATEMENT_H_ */
