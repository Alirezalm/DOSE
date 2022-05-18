//
// Created by alireza on 18/05/22.
//

#include "../include/LogRegStrategy.h"
#include "../include/DistEngine.h"

namespace dose {

    LogRegStrategy::LogRegStrategy(const Mat &A,
                                   const Vec &b,
                                   const int &rank,
                                   const int &maxNodes,
                                   const double &M,
                                   const SettingsPtr settings, const ProblemType &problemType) {
        this->A = A;
        this->b = b;
        this->rank = rank;
        this->maxNodes = maxNodes;
        this->M = M;
        this->settings = settings;
    }

    LogRegStrategy::~LogRegStrategy() = default;

    void LogRegStrategy::solve(const Vec &binvar) {

        solution = runRHADMM(A, b, rank, maxNodes, M, binvar, settings, problemType);

    }


}
