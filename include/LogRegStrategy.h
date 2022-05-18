//
// Created by alireza on 18/05/22.
//

#ifndef DOSE_LOGREGSTRATEGY_H
#define DOSE_LOGREGSTRATEGY_H

#include "IAlgorithmStrategy.h"

namespace dose {
    class LogRegStrategy : public IAlgorithmStrategy {
    public:
        LogRegStrategy(const Mat &A,
                       const Vec &b,
                       const int &rank,
                       const int &maxNodes,
                       const double &M,
                       const SettingsPtr settings,
                       const ProblemType &problemType);

        ~LogRegStrategy() = default;

        void solve(const VectorDouble &binvar) override;

    };
}


#endif //DOSE_LOGREGSTRATEGY_H
