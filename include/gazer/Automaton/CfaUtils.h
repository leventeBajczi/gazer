//==-------------------------------------------------------------*- C++ -*--==//
//
// Copyright 2019 Contributors to the Gazer project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//===----------------------------------------------------------------------===//
#ifndef GAZER_AUTOMATON_CFAUTILS_H
#define GAZER_AUTOMATON_CFAUTILS_H

#include "gazer/Automaton/Cfa.h"

#include <llvm/ADT/DenseSet.h>

namespace gazer
{

class ExprBuilder;

/// Class for calculating verification path conditions.
class PathConditionCalculator
{
public:
    PathConditionCalculator(
        const std::vector<Location*>& topo,
        ExprBuilder& builder,
        std::function<size_t(Location*)> index,
        std::function<ExprPtr(CallTransition*)> calls,
        std::function<void(Location*, Variable*, ExprPtr)> preds = nullptr
    );

public:
    ExprPtr encode(Location* source, Location* target);

private:
    void insertPredecessor(Location* location, Variable* variable, ExprPtr expr);

private:
    const std::vector<Location*>& mTopo;
    ExprBuilder& mExprBuilder;
    std::function<size_t(Location*)> mIndex;
    std::function<ExprPtr(CallTransition*)> mCalls;
    std::function<void(Location*, Variable*, ExprPtr)> mPredecessors;
    unsigned mPredIdx = 0;
};

/// Returns the lowest common dominator of each transition in \p targets.
///
/// \param targets A set of target locations.
/// \param topo Topological sort of automaton locations.
/// \param topoIdx A function which returns the index of a location in the topological sort.
/// \param start The start node, which must dominate all target locations. Defaults to the
///     entry location if empty.
Location* findLowestCommonDominator(
    const std::vector<Transition*>& targets,
    const std::vector<Location*>& topo,
    std::function<size_t(Location*)> index,
    Location* start = nullptr
);

/// Returns the highest common post-dominator of each transition in \p targets.
Location* findHighestCommonPostDominator(
    const std::vector<Transition*>& targets,
    const std::vector<Location*>& topo,
    std::function<size_t(Location*)> index,
    Location* start
);

}

#endif
