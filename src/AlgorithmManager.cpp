//
// Created by alireza on 18/05/22.
//

#include "../include/AlgorithmManager.h"

namespace dose {

    AlgorithmManager::AlgorithmManager() = default;

    void AlgorithmManager::setAlgorithmStrategy(AlgorithmPtr algorithm) {
        solutionAlgorithm = algorithm;
    }

    void AlgorithmManager::runAlgorithm(Vec &binvec) {
        solutionAlgorithm->solve(binvec);
    }

    AlgorithmManager::~AlgorithmManager() = default;
}