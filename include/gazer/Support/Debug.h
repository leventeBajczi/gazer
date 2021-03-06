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
#ifndef GAZER_SUPPORT_DEBUG_H
#define GAZER_SUPPORT_DEBUG_H

namespace gazer
{
    extern bool IsDebugEnabled;
}

#ifndef NDEBUG

#define GAZER_DEBUG(X)                          \
    do {                                        \
        if (::gazer::IsDebugEnabled) {          \
            X;                                  \
        }                                       \
    } while (false);                            \

#else

#define GAZER_DEBUG(X) do { } while (false);    \

#endif // NDEBUG
#endif // GAZER_SUPPORT_DEBUG_H