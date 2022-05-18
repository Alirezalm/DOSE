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

}
#endif //DOSE_UTILITIES_H
