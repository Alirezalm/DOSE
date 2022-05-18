//
// Created by alireza on 17/05/22.
//

#ifndef DOSE_UTILITIES_H
#define DOSE_UTILITIES_H

#include "types.h"
#include "Exceptions.h"

namespace dose ::utilities {


    void checkColumnConsistency(const VectorDouble2D &vec2d, const int default_cols) noexcept;

    void checkVec2Mat(const VectorDouble2D &vec2d) noexcept;

    inline void checkVec2Vec(const VectorDouble &vec1d, const int default_row) noexcept;

    void vec2Vec(const VectorDouble &std_vec,  Vec &eigen_vec);
    void mat2Mec(const VectorDouble2D &std_mat, Mat &eigen_mat);
}
#endif //DOSE_UTILITIES_H
