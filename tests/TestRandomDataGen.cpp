//
// Created by alireza on 21/05/22.
//
#include "../include/RandomDataGenerator.h"
#include "../include/Utilities.h"

void TestRandomData() {
    int m = 5, n = 2;
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
    std::cout << b << std::endl;
}
