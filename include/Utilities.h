//
// Created by alireza on 17/05/22.
//

#ifndef DOSE_UTILITIES_H
#define DOSE_UTILITIES_H

#include "types.h"
#include "Exceptions.h"

namespace dose {
    void checkColumnConsistency(const VectorDouble2D &vec2d);

    void checkVec2Mat(const VectorDouble2D &vec2d);
}
#endif //DOSE_UTILITIES_H
