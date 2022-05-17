//
// Created by alireza on 16/05/22.
//

#ifndef DOSE_TYPES_H
#define DOSE_TYPES_H

#include "iostream"
#include <iomanip>
#include "chrono"
#include "memory"
#include "mpi/mpi.h"
#include <vector>
#include "../ThirdParty/Eigen/Dense"
#include "../ThirdParty/Eigen/IterativeLinearSolvers"

namespace dose {

    using namespace Eigen;
    using namespace std::chrono;
    using Scalar = typename Eigen::MatrixXd::Scalar;
    using Mat = Matrix<Scalar, Dynamic, Dynamic, RowMajor>;
    using Vec = Matrix<Scalar, Dynamic, 1, ColMajor>;
    using Ind = typename Mat::Index;
    using VectorDouble = std::vector<double>;
    using VectorDouble2D = std::vector<VectorDouble>;
    struct TruncatedNewTonSettings {
        int maxIter = 1000;
        double eps = 1e-5;
        bool verbose = false;
    };

    struct RHADMMSettings {
        double rho = 500.0;
        double maxIter = 1000;
        double eps = 1e-8;
        bool adaptive = true;
        bool verbose = false;
    };

    struct RHADMMInfo {
        int iter;
        double t;
        double dres;
        double total_f;
        double rho;
    };

    struct RHADMMSolution {
        Vec x;
        double local_f;
        double total_f;
        int status;
    };

    enum ProblemType {
        LinearRegression,
        LogisticRegression
    };

    enum class SolverStatue {
        OPTIMAL,
        SUBOPTIMAL,
        MAXITER,
        INFEASIBLE
    };


}
#endif //DOSE_TYPES_H
