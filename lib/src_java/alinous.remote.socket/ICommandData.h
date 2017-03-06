#ifndef ALINOUS_REMOTE_SOCKET_ICOMMANDDATA_H_
#define ALINOUS_REMOTE_SOCKET_ICOMMANDDATA_H_
namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace dom {
class NetworkAlinousVariableFactory;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace socket {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dom::NetworkAlinousVariableFactory;
using ::alinous::runtime::dom::VariableException;



class ICommandData : public virtual IObject {
public:
	ICommandData(const ICommandData& base) = default;
public:
	ICommandData(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ICommandData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int __IdentifierVariable{1};
	constexpr static const int __VariantValue{2};
	constexpr static const int __DocumentVariable{3};
	constexpr static const int __DomArray{4};
	constexpr static const int __DomVariable{5};
	constexpr static const int __BigDecimalVariable{6};
	constexpr static const int __BoolVariable{7};
	constexpr static const int __ByteVariable{8};
	constexpr static const int __CharVariable{9};
	constexpr static const int __DoubleVariable{10};
	constexpr static const int __FloatVariable{11};
	constexpr static const int __IntegerVariable{12};
	constexpr static const int __LongVariable{13};
	constexpr static const int __ShortVariable{14};
	constexpr static const int __StringVariable{15};
	constexpr static const int __TimestampVariable{16};
	constexpr static const int __TimeVariable{17};
	constexpr static const int __TypedVariableArray{18};
	constexpr static const int __AlinousClassVariable{19};
	constexpr static const int __AlinousName{1000};
	constexpr static const int __AlinousSrc{1001};
	constexpr static const int __CheckDefinition{1002};
	constexpr static const int __ColumnTypeDescriptor{1003};
	constexpr static const int __DdlColumnDescriptor{1004};
	constexpr static const int __AlinousClass{1005};
	constexpr static const int __AlinousFunction{1006};
	constexpr static const int __ClassExtends{1007};
	constexpr static const int __ClassImplements{1008};
	constexpr static const int __ClassMemberModifiers{1009};
	constexpr static const int __FunctionArgumentDefine{1010};
	constexpr static const int __FunctionArgumentsListDefine{1011};
	constexpr static const int __ClassMemberVariable{1012};
	constexpr static const int __ClassMethodFunction{1013};
	constexpr static const int __ReturnValueDefinition{1014};
	constexpr static const int __ThrowsDefine{1015};
	constexpr static const int __DomIndexSegment{1016};
	constexpr static const int __DomNameSegment{1017};
	constexpr static const int __AndExpression{1018};
	constexpr static const int __ConditionalAndExpression{1019};
	constexpr static const int __ConditionalOrExpression{1020};
	constexpr static const int __ExclusiveOrExpression{1021};
	constexpr static const int __InclusiveOrExpression{1022};
	constexpr static const int __EqualityExpression{1023};
	constexpr static const int __InstanceOfExpression{1024};
	constexpr static const int __RelationalExpression{1026};
	constexpr static const int __AdditiveExpression{1027};
	constexpr static const int __MultiplicativeExpression{1028};
	constexpr static const int __ShiftExpression{1029};
	constexpr static const int __AllocationExpression{1030};
	constexpr static const int __BitReverseExpression{1031};
	constexpr static const int __BooleanSubExpression{1032};
	constexpr static const int __CastExpression{1033};
	constexpr static const int __ConditionalExpression{1034};
	constexpr static const int __ExpStreamCast{1035};
	constexpr static const int __ExpStreamParenthesis{1036};
	constexpr static const int __ExpStreamSegment{1037};
	constexpr static const int __FunctionArguments{1038};
	constexpr static const int __FunctionCallExpression{1039};
	constexpr static const int __Literal{1040};
	constexpr static const int __BooleanLiteral{1041};
	constexpr static const int __NullLiteral{1042};
	constexpr static const int __ParenthesisExpression{1043};
	constexpr static const int __PreDecrementExpression{1044};
	constexpr static const int __PreIncrementExpression{1045};
	constexpr static const int __SubExpression{1046};
	constexpr static const int __UnaryExpression{1047};
	constexpr static const int __DomVariableDescriptor{1048};
	constexpr static const int __ExpressionStream{1049};
	constexpr static const int __SQLAdditiveExpression{1050};
	constexpr static const int __SQLMultiplicativeExpression{1051};
	constexpr static const int __SQLSubqueryExpression{1052};
	constexpr static const int __SQLColumnIdentifier{1053};
	constexpr static const int __SQLLiteral{1054};
	constexpr static const int __SQLParenthesisExpression{1055};
	constexpr static const int __InsertValues{1056};
	constexpr static const int __SQLAndExpression{1057};
	constexpr static const int __SQLOrExpression{1058};
	constexpr static const int __SQLBooleanLiteral{1059};
	constexpr static const int __SQLBoolSubExpression{1060};
	constexpr static const int __SQLEqualityExpression{1061};
	constexpr static const int __SQLInExpression{1062};
	constexpr static const int __SQLIsNullExpression{1063};
	constexpr static const int __SQLJoinCondition{1064};
	constexpr static const int __SQLLikeExpression{1065};
	constexpr static const int __SQLNotExpression{1066};
	constexpr static const int __SQLRelationalExpression{1067};
	constexpr static const int __SQLSubExpression{1068};
	constexpr static const int __SQLExpressionList{1069};
	constexpr static const int __SQLExpressionListAll{1070};
	constexpr static const int __SQLExpressionStream{1071};
	constexpr static const int __SQLFrom{1072};
	constexpr static const int __SQLGroupBy{1073};
	constexpr static const int __UpdateSet{1074};
	constexpr static const int __IncludePreprocessor{1075};
	constexpr static const int __AssignmentStatement{1076};
	constexpr static const int __BreakStatement{1077};
	constexpr static const int __CaseStatement{1078};
	constexpr static const int __DefaultStatement{1079};
	constexpr static const int __CatchBlock{1080};
	constexpr static const int __ContinueStatement{1081};
	constexpr static const int __DoWhileStatement{1082};
	constexpr static const int __ExpressionStatement{1083};
	constexpr static const int __FinallyBlock{1084};
	constexpr static const int __ForStatement{1085};
	constexpr static const int __ForUpdatePart{1086};
	constexpr static const int __IfStatement{1087};
	constexpr static const int __LabeledStatement{1088};
	constexpr static const int __ReturnStatement{1089};
	constexpr static const int __StatementBlock{1090};
	constexpr static const int __StatementList{1091};
	constexpr static const int __SwitchCasePart{1092};
	constexpr static const int __SwitchStatement{1093};
	constexpr static const int __ThrowStatement{1094};
	constexpr static const int __TryBlock{1095};
	constexpr static const int __TypedVariableDeclare{1096};
	constexpr static const int __WhileStatement{1097};
	constexpr static const int __BeginStatement{1098};
	constexpr static const int __CommitStatement{1099};
	constexpr static const int __CreateIndexStatement{1100};
	constexpr static const int __CreateTableStatement{1101};
	constexpr static const int __DeleteStatement{1102};
	constexpr static const int __DropIndexStatement{1103};
	constexpr static const int __DropTableStatement{1104};
	constexpr static const int __InsertStatement{1105};
	constexpr static const int __RollbackStatement{1106};
	constexpr static const int __UpdateStatement{1107};
	constexpr static const int __InnerJoin{1108};
	constexpr static const int __CrossJoin{1109};
	constexpr static const int __RightJoin{1110};
	constexpr static const int __NaturalJoin{1111};
	constexpr static const int __DomVariableJoinTarget{1112};
	constexpr static const int __JoinSubQueryTarget{1113};
	constexpr static const int __TableJoinTarget{1114};
	constexpr static const int __WrappedJoinTarget{1115};
	constexpr static const int __SelectStatement{1116};
	constexpr static const int __TableList{1117};
	constexpr static const int __PrimaryKeys{1118};
	constexpr static const int __SQLLimitOffset{1119};
	constexpr static const int __SQLWhere{1120};
	constexpr static const int __Unique{1121};
	constexpr static const int __AlinousModule{1122};
	constexpr static const int __NotExpression{1123};
	constexpr static const int __AlinousModulePackage{1124};
	constexpr static const int __VirtualTable{1125};
	constexpr static const int __LeftJoin{1126};
	constexpr static const int __ShardKeys{1127};
	constexpr static const int __SubShardKeys{1128};
public:
	virtual void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) = 0;
	virtual void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_ICOMMANDDATA_H_ */
