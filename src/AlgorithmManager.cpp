//
// Created by alireza on 18/05/22.
//

#include "../include/AlgorithmManager.h"

namespace dose {

    AlgorithmManager::AlgorithmManager(const AlgorithmPtr solutionAlgorithm) : solutionAlgorithm(solutionAlgorithm) {}

    void AlgorithmManager::setAlgorithmStrategy(AlgorithmPtr algorithm) {
        solutionAlgorithm = algorithm;
    }

    void AlgorithmManager::runAlgorithm(Mat &binvec) {
        solutionAlgorithm->solve(binvec);
    }

    AlgorithmManager::~AlgorithmManager() = default;
}