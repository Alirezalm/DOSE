#include <iostream>
#include "include/DOSE.h"
#include "memory"

using namespace std;

int main(int argc, char *argv[]) {

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
    auto *solver = new dose::DOSE(b, a, dose::LogisticRegression, settings, rank, maxNodes, M);
    solver->solve(binvec);
    MPI_Finalize();
//    time_t start, end;
//    double avg;
//
//    MPI_Init(&argc, &argv);
//
//    int rank, maxNodes;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get MPI rank
//    MPI_Comm_size(MPI_COMM_WORLD, &maxNodes); // get MPI size
//    int m = 25000, n = 50;
//    Mat A(m, n);
//    Vec b(m, 1);
//    random_device r;
//    default_random_engine generator(r());
//    // default_random_engine generator;
//    lognormal_distribution<double> distribution(-1, 1);
//
//    int N = 1;
//    for (int l = 0; l < N; ++l) {
//        for (int j = 0; j < m; ++j) {
//            if (distribution(generator) <= 0.5) {
//                b[j] = 1.0;
//            } else {
//                b[j] = 0.0;
//            }
//            for (int k = 0; k < n; ++k) {
//                A(j, k) = distribution(generator);
//            }
//        }
//
//        for (int i = 0; i < n; ++i) {
//            A.col(i) = A.col(i) / A.col(i).norm();
//        }
//
//        Vec x = Mat::Random(n, 1);
//        Vec y = Mat::Random(n, 1) * 0.25;
//        Vec z = Mat::Random(n, 1) * -0.83;
//        Vec bin(n, 1);
//        bin.setOnes();
//        double M = 1;
//        auto settings = RHADMMSettings{}; // fixes with settings pointer
//        settings.eps = 1e-8;
////        double rho = atof(argv[1]);
//        settings.rho = 1.0;
//        settings.maxIter = 5000.0;
//        settings.adaptive = true;
//        settings.verbose = true;
//
//        start = clock();
//
//        RHADMMSolution sol = runRHADMM(A, b, rank, maxNodes, M, bin, settings, LogisticRegression);
//
//        end = clock();
//        sleep(3);
//        start = clock();
//        b.setRandom();
//        b = b / b.norm();
//        sol = runRHADMM(A, b, rank, maxNodes, M, bin, settings, LinearRegression);
//        end = clock();
//        double used = (double) (end - start) / CLOCKS_PER_SEC;
//        if (rank == 0) std::cout << "elapsed time: " << used << "seconds" << std::endl;
//        avg += used;
//    }
//    if (rank == 0) std::cout << "avg: " << avg / N << std::endl;

    return 0;
}