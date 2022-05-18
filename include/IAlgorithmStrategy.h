//
// Created by alireza on 18/05/22.
//

#ifndef DOSE_IALGORITHMSTRATEGY_H
#define DOSE_IALGORITHMSTRATEGY_H

#include "types.h"

namespace dose {
    class IAlgorithmStrategy {
    public:
        virtual ~IAlgorithmStrategy() = default;

        virtual void solve(const VectorDouble &binvar) = 0;

    protected:
        SolutionPtr solution;
        Mat A;
        Mat b;
        int rank;
        int maxNodes;
        double M;
        SettingsPtr settings;
        ProblemType problemType;

    };
}


#endif //DOSE_IALGORITHMSTRATEGY_H
