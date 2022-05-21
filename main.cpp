#include <iostream>
#include "include/DOSE.h"
#include "memory"
#include "include/RandomDataGenerator.h"
#include "include/Utilities.h"
using namespace std;

int main(int argc, char *argv[]) {

    int m = 10, n = 5;
    auto ptype = dose::LogisticRegression;
    auto *problem_generator = new dose::RandomDataGenerator(m, n, ptype);

    dose::Mat A(m, n);
    dose::Vec b(m, 1);

    problem_generator->generate();
    auto asv = problem_generator->getDataSet();
    auto bsv = problem_generator->getResponse();


    dose::utilities::vec2Vec(bsv, b);
    dose::utilities::mat2Mat(asv, A);

    std::cout << A << std::endl;
//    time_t start, end;
//    double avg;
//  0.154178   -1.77317   -1.13836  -0.917964   -1.16264
//-0.0160573   -2.77261   -1.17536  -0.992605   -1.71847
//  -1.06705   -3.01456  -0.250487   -1.20984   -1.63812
//  -1.05043   -1.45661  -0.670674 0.00203637   0.457728
// -0.433857  -0.671579   -0.86699   -2.94077  -0.764439
// -0.761355   -1.92716   -3.44502  -0.719236    -2.2604
//   -1.0017   -1.52302  -0.531642  -0.702384   -1.43202
//  -0.48558   -1.39536   -1.64821   0.646895   -1.67272
//  -1.77348   -2.10256   0.325432   0.111374   -2.04608
//  -1.33322   -1.28347   -2.09322   -1.49614    1.80344
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