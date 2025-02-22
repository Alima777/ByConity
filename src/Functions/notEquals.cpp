#include <Functions/FunctionFactory.h>
#include <Functions/FunctionsComparison.h>


namespace DB
{

using FunctionNotEquals = FunctionComparison<NotEqualsOp, NameNotEquals>;
using FunctionBitNotEquals = FunctionComparison<NotEqualsOp, NameBitNotEquals, true>;

void registerFunctionNotEquals(FunctionFactory & factory)
{
    factory.registerFunction<FunctionNotEquals>();
    factory.registerFunction<FunctionBitNotEquals>();
}

template <>
ColumnPtr FunctionComparison<NotEqualsOp, NameNotEquals>::executeTupleImpl(
    const ColumnsWithTypeAndName & x, const ColumnsWithTypeAndName & y, size_t tuple_size, size_t input_rows_count) const
{
    return executeTupleEqualityImpl(
        FunctionFactory::instance().get("notEquals", context),
        FunctionFactory::instance().get("or", context),
        x, y, tuple_size, input_rows_count);
}

template <>
ColumnPtr FunctionComparison<NotEqualsOp, NameBitNotEquals, true>::executeTupleImpl(
    const ColumnsWithTypeAndName & x, const ColumnsWithTypeAndName & y, size_t tuple_size, size_t input_rows_count) const
{
    return executeTupleEqualityImpl(
        FunctionFactory::instance().get("notEquals", context),
        FunctionFactory::instance().get("or", context),
        x, y, tuple_size, input_rows_count);
}

}
