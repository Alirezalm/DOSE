//
// Created by alireza on 21/05/22.
//
#include "../include/DOSE.h"

void TestLogReg(int argc, char *argv[]) {

    MPI_Init(&argc, &argv);
    int rank, maxNodes;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get MPI rank
    MPI_Comm_size(MPI_COMM_WORLD, &maxNodes); // get MPI size
    dose::VectorDouble a;
    dose::VectorDouble2D b;
    if (rank == 0) {
        a = {0, 0, 1, 1, 0};
        b = {
                {0.11, 0.22, 0.31},
                {0.54, 0.13, 0.52},
                {0.65, 0.11, 0.65},
                {0.51, 0.21, 0.56},
                {0.85, 0.17, 0.53},
        };

    } else if (rank == 1) {
        a = {0, 0, 1, 1, 1};
        b = {
                {0.85, 0.13, 0.65},
                {0.54, 0.77, 0.98},
                {0.23, 0.76, 0.45},
                {0.42, 0.4,  0.8},
                {0.45, 0.35, 0.75},
        };
    } else if (rank == 2) {
        a = {1, 0, 0, 1, 0};
        b = {
                {0.85, 0.13, 0.65},
                {0.54, 0.77, 0.98},
                {0.23, 0.76, 0.45},
                {0.42, 0.4,  0.8},
                {0.45, 0.35, 0.75},
        };
    } else if (rank == 3) {
        a = {1, 1, 1, 1, 0};
        b = {
                {0.85, 0.13, 0.65},
                {0.54, 0.77, 0.98},
                {0.23, 0.76, 0.45},
                {0.42, 0.4,  0.8},
                {0.45, 0.35, 0.75},
        };
    };

    double M = 10.0;
    dose::VectorDouble binvec = {0.0, 0.0, 1.0};
    dose::SettingsPtr settings = std::make_shared<dose::RHADMMSettings>();
    settings->rho = std::stod(argv[1]);
    settings->adaptive = true;
    settings->maxIter = 5000;
    settings->eps = 1e-12;
    auto *solver = new dose::DOSE(b, a, dose::LinearRegression, settings, rank, maxNodes, M);
    solver->solve(binvec);
    MPI_Finalize();
}