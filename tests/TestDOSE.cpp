//
// Created by alireza on 21/05/22.
//
#include <iostream>
#include "../include/DOSE.h"
#include "memory"
#include "../include/RandomDataGenerator.h"
#include "ctime"
#include "iomanip"

void TestDoce(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    // define data and problem type
//    int m = 5, n = 2;
    int m = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);
    int type = std::stoi(argv[3]);
    dose::ProblemType ptype;
    switch (type) {
        case 0:
            ptype = dose::LinearRegression;
            break;
        case 1:
            ptype = dose::LogisticRegression;
            break;
    }
    auto *problem_generator = new dose::RandomDataGenerator(m, n, ptype);

    problem_generator->generate();
    auto asv = problem_generator->getDataSet();
    auto bsv = problem_generator->getResponse();

    double M = 5;

    // Nodes Information
    int rank;
    int totalNodes;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &totalNodes);

    // call dose public interface
    auto settings = std::make_shared<dose::RHADMMSettings>();
    auto *solver = new dose::DOSE(asv, bsv, ptype, settings, rank, totalNodes, M);
    auto binvec = problem_generator->getRandomInteger(n);

    // timing info
    time_t start, end;
    start = clock();
    solver->solve(binvec);

    end = clock();
    double used = (double) (end - start) / CLOCKS_PER_SEC;
    if (rank == 0) std::cout << std::fixed << std::setprecision(10) << used << " seconds" << std::endl;
    MPI_Finalize();


}