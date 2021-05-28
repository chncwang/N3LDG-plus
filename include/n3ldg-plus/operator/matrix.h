#ifndef N3LDG_PLUS_MATRX_NODE_H
#define N3LDG_PLUS_MATRX_NODE_H

#include "n3ldg-plus/computation-graph/graph.h"

namespace n3ldg_plus {

BatchedNode *tranMatrixMulMatrix(BatchedNode &a, BatchedNode &b, int input_row,
        bool use_lower_triangle_mask = false);

/// Matrix multiplication. \f$A B\f$ (if *transpose_a* is false) or \f$A^T B\f$ (if *transpose_a* is true).
///
/// No matter *transpose_a* is true or false, the shapes of *A* and *B* are determined by *b_row*.
/// In particular, N3LDG++ supports transposing A in *matmul* for cache friendliness.
///
/// **No matter transpose_a is true or false, the operators with equal row of A will be executed in batch.**
/// For example, \f$K^T Q\f$ and \f$VA\f$ of the Transformer in the same mini-batch will be executed in batch.
/// \param A Matrix A whose row number is A.size() / b_row and column number is b_row.
/// \param B Matrix B whose row number is b_row and column number is B.size() / b_row.
/// \param b_row The row number of matrix B.
/// \param transpose_a Whether to transpose A before matrix multiplication. *The default value is false*.
/// \param use_lower_triangular_mask Whether to apply a lower triangular mask of -inf to the result matrix. Note that do not set it to true when *transpose_a* is false. *The default value is false*.
/// \return The result matrix. No matter transpose_a is true or false, its size is A.size() / b_row * B.size() / b_row.
Node *matmul(Node &A, Node &B, int b_row, bool transpose_a = false,
        bool use_lower_triangular_mask = false);

BatchedNode *matrixMulMatrix(BatchedNode &a, BatchedNode &b, int k);

}
#endif
