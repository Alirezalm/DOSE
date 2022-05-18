//
// Created by alireza on 17/05/22.
//

#include "../include/Utilities.h"

namespace dose::utilities {


    void checkColumnConsistency(const VectorDouble2D &vec2d, const int default_cols) noexcept {

        for (auto column: vec2d) {
            if (column.size() != default_cols) {
                throw InvalidProblemSize("inconsistent dataset, each row must have same number of columns");
            }
        }
    }

    void checkVec2Mat(const VectorDouble2D &vec2d) noexcept {
        int rows = vec2d.size();
        int cols = vec2d.front().size();
        assert((rows > 0) && (cols > 0) && (rows >= cols));
        checkColumnConsistency(vec2d, cols);

    }

    inline void checkVec2Vec(const VectorDouble &vec1d, const int default_row) noexcept {
        assert(vec1d.size() == default_row);
    }


}