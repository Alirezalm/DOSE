#include <iostream>
#include "include/DOSE.h"

using namespace std;

int main(int argc, char *argv[]) {

    MPI_Init(&argc, &argv);
    dose::VectorDouble a = {0, 0, 1, 1, 0};
    dose::VectorDouble2D b = {
            {0.11, 0.22, 0.31},
            {0.54, 0.13, 0.52},
            {0.65, 0.11, 0.65},
            {0.51, 0.21, 0.56},
            {0.85, 0.17, 0.53},

    };
    double M = 10.0;
    dose::VectorDouble binvec = {1, 0, 1};
    int rank = 0, total = 1;
    auto *solver = new dose::DOSE(b, a, dose::LogisticRegression, rank, total, M);
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