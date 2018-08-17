#ifndef _GAZER_CORE_VARIABLE_H
#define _GAZER_CORE_VARIABLE_H

#include "gazer/Core/Expr.h"

#include <string>
#include <memory>

// TODO: Move this header into Expr or ExprTypes?

namespace gazer
{

class VarRefExpr;

class Variable final
{
public:
    Variable(std::string name, const Type& type);

    Variable(const Variable&) = delete;
    Variable& operator=(const Variable&) = delete;

    const Type& getType() const { return mType; }
    std::string getName() const { return mName; }
    std::shared_ptr<VarRefExpr> getRefExpr() const { return mExpr; }

private:
    std::string mName;
    const Type& mType;
    std::shared_ptr<VarRefExpr> mExpr;
};

class VarRefExpr final : public Expr
{
    friend class Variable;
private:
    VarRefExpr(const Variable& variable)
        : Expr(Expr::VarRef, variable.getType()), mVariable(variable)
    {}

public:
    const Variable& getVariable() const { return mVariable; }

    virtual void print(llvm::raw_ostream& os) const override;

    static bool classof(const Expr* expr) {
        return expr->getKind() == Expr::VarRef;
    }

private:
    const Variable& mVariable;
};


}

#endif
