#ifndef N3LDG_PLUS_SUB_H
#define N3LDG_PLUS_SUB_H

#include "n3ldg-plus/computation-graph/graph.h"

namespace n3ldg_plus {

/// \ingroup operator
/// Subtract an input tensor by another. \f$[a_0-b_0, a_1-b_1, ..., a_n-b_n]\f$.
///
/// **All sub operators will be executed in batch.**
/// \param a Its size should be equal to b.size().
/// \param b Its size should be equal to a.size().
/// \return The result tensor. Its size is equal to both a.size() and b.size().
Node *sub(Node &a, Node &b);

}

#endif
