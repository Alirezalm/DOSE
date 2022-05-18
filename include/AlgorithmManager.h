//
// Created by alireza on 18/05/22.
//

#ifndef DOSE_ALGORITHMMANAGER_H
#define DOSE_ALGORITHMMANAGER_H

#include "LinRegStrategy.h"
#include "LogRegStrategy.h"

namespace dose {
    class AlgorithmManager {

    public:
        AlgorithmManager(const AlgorithmPtr solutionAlgorithm);

        ~AlgorithmManager();

        void setAlgorithmStrategy(AlgorithmPtr algorithm);

        void runAlgorithm(Mat &binvec);

    private:
        AlgorithmPtr solutionAlgorithm;

    };
}


#endif //DOSE_ALGORITHMMANAGER_H
