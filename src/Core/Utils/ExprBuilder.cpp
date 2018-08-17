#include "gazer/Core/Utils/ExprBuilder.h"
#include "gazer/Core/ExprTypes.h"
#include "gazer/Core/LiteralExpr.h"

#include <llvm/ADT/APInt.h>

using namespace gazer;

namespace
{

class DefaultExprBuilder : public ExprBuilder
{
public:
    DefaultExprBuilder()
        : ExprBuilder()
    {}

    ExprPtr Not(const ExprPtr& op) override {
        return NotExpr::Create(op);
    }
    ExprPtr ZExt(const ExprPtr& op, const IntType& type) override {
        return ZExtExpr::Create(op, type);
    }
    ExprPtr SExt(const ExprPtr& op, const IntType& type) override {
        return SExtExpr::Create(op, type);
    }
    ExprPtr Trunc(const ExprPtr& op, const IntType& type) override {
        return ExtractExpr::Create(op, 0, type.getWidth());
    }
    ExprPtr Extract(const ExprPtr& op, unsigned offset, unsigned width) override {
        return ExtractExpr::Create(op, offset, width);
    }
    ExprPtr PtrCast(const ExprPtr& op, const PointerType& type) override {
        return PtrCastExpr::Create(op, type);
    }

    ExprPtr Add(const ExprPtr& left, const ExprPtr& right) override {
        return AddExpr::Create(left, right);
    }
    ExprPtr Sub(const ExprPtr& left, const ExprPtr& right) override {
        return SubExpr::Create(left, right);
    }
    ExprPtr Mul(const ExprPtr& left, const ExprPtr& right) override {
        return MulExpr::Create(left, right);
    }
    ExprPtr Div(const ExprPtr& left, const ExprPtr& right) override {
        return DivExpr::Create(left, right);
    }
    ExprPtr Shl(const ExprPtr& left, const ExprPtr& right) override {
        return ShlExpr::Create(left, right);
    }
    ExprPtr LShr(const ExprPtr& left, const ExprPtr& right) override {
        return LShrExpr::Create(left, right);
    }
    ExprPtr AShr(const ExprPtr& left, const ExprPtr& right) override {
        return AShrExpr::Create(left, right);
    }
    ExprPtr BAnd(const ExprPtr& left, const ExprPtr& right) override {
        return BAndExpr::Create(left, right);
    }
    ExprPtr BOr(const ExprPtr& left, const ExprPtr& right) override {
        return BOrExpr::Create(left, right);
    }
    ExprPtr BXor(const ExprPtr& left, const ExprPtr& right) override {
        return BXorExpr::Create(left, right);
    }

    ExprPtr And(const ExprVector& vector) override {
        return AndExpr::Create(vector.begin(), vector.end());
    }
    ExprPtr Or(const ExprVector& vector) override {
        return OrExpr::Create(vector.begin(), vector.end());
    }
    ExprPtr Xor(const ExprPtr& left, const ExprPtr& right) override {
        return XorExpr::Create(left, right);
    }

    ExprPtr Eq(const ExprPtr& left, const ExprPtr& right) override {
        return EqExpr::Create(left, right);
    }
    ExprPtr NotEq(const ExprPtr& left, const ExprPtr& right) override {
        return NotEqExpr::Create(left, right);
    }

    ExprPtr SLt(const ExprPtr& left, const ExprPtr& right) override {
        return SLtExpr::Create(left, right);
    }
    ExprPtr SLtEq(const ExprPtr& left, const ExprPtr& right) override {
        return SLtEqExpr::Create(left, right);
    }
    ExprPtr SGt(const ExprPtr& left, const ExprPtr& right) override {
        return SGtExpr::Create(left, right);
    }
    ExprPtr SGtEq(const ExprPtr& left, const ExprPtr& right) override {
        return SGtEqExpr::Create(left, right);
    }

    ExprPtr ULt(const ExprPtr& left, const ExprPtr& right) override {
        return ULtExpr::Create(left, right);
    }
    ExprPtr ULtEq(const ExprPtr& left, const ExprPtr& right) override {
        return ULtEqExpr::Create(left, right);
    }
    ExprPtr UGt(const ExprPtr& left, const ExprPtr& right) override {
        return UGtExpr::Create(left, right);
    }
    ExprPtr UGtEq(const ExprPtr& left, const ExprPtr& right) override {
        return UGtEqExpr::Create(left, right);
    }

    ExprPtr Select(const ExprPtr& condition, const ExprPtr& then, const ExprPtr& elze) override {
        return SelectExpr::Create(condition, then, elze);
    }
};

} // end anonymous namespace

std::unique_ptr<ExprBuilder> gazer::CreateExprBuilder() {
    return std::unique_ptr<ExprBuilder>(new DefaultExprBuilder());
}
