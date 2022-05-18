//
// Created by alireza on 17/05/22.
//

#include "../include/Utilities.h"

namespace dose {

    void checkColumnConsistency(const VectorDouble2D &vec2d, const int default_cols) {

        for (auto column: vec2d) {
            if (column.size() != default_cols) {
                throw InvalidProblemSize("inconsistent dataset, each row must have same number of columns");
            }
        }
    }

    void dose::checkVec2Mat(const VectorDouble2D &vec2d) {
        int rows = vec2d.size();
        int cols = vec2d.front().size();
        assert((rows > 0) && (cols > 0) && (rows >= cols));
        checkColumnConsistency(vec2d, cols);

    }
}