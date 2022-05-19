//
// Created by alireza on 17/05/22.
//

#include "../include/Utilities.h"

namespace dose::utilities {


    void checkColumnConsistency(const VectorDouble2D &vec2d, const int default_cols) noexcept {

        for (auto column: vec2d) {
            if (column.size() != default_cols) {
                throw InvalidProblemSize("inconsistent dataset, each row must have same number of columns");
            } else{
// TODO fixed compiler warning
            }
        }
    }

    void checkVec2Mat(const VectorDouble2D &vec2d) noexcept {
        int rows = vec2d.size();
        int cols = vec2d.front().size();
        assert((rows > 0) && (cols > 0) && (rows >= cols));
        checkColumnConsistency(vec2d, cols);

    }

    void checkVec2Vec(const VectorDouble &vec1d, const int default_row) noexcept {
        assert(vec1d.size() == default_row);
    }

    void vec2Vec(const VectorDouble &std_vec, Vec &eigen_vec) {
        int rows = std_vec.size();
        assert(eigen_vec.size() == rows);
        for (int i = 0; i < rows; ++i) {
            eigen_vec[i] = std_vec[i];
        }
    }

    void mat2Mat(const VectorDouble2D &std_mat, Mat &eigen_mat) {
        int rows = std_mat.size();
        int cols = std_mat.front().size();
        assert((eigen_mat.rows() == rows) && (eigen_mat.cols() == cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                eigen_mat(i, j) = std_mat[i][j];
            }
        }
    }


}