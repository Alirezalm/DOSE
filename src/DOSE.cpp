//
// Created by alireza on 17/05/22.
//

#include "../include/DOSE.h"
#include "../include/Utilities.h"
#include "../include/LinRegStrategy.h"
#include "../include/LogRegStrategy.h"

namespace dose {


    DOSE::DOSE(const VectorDouble2D &pdataSet, const VectorDouble &pdataRes, ProblemType ptype, SettingsPtr settings,
               int &rank, int &totalNodes) : pdataSet(pdataSet),
                                             pdataRes(pdataRes),
                                             ptype(ptype),
                                             settings(settings),
                                             rank(rank),
                                             totalNodes(totalNodes) {
        validateData();
        toEigen();


    }

    DOSE::DOSE(const VectorDouble2D &pdataSet, const VectorDouble &pdataRes, ProblemType ptype, int &rank,
               int &totalNodes) : pdataSet(pdataSet),
                                  pdataRes(pdataRes),
                                  ptype(ptype),
                                  rank(rank),
                                  totalNodes(totalNodes) {
        validateData();
        toEigen();

        settings = std::make_shared<RHADMMSettings>();  //default settings
    }

    DOSE::DOSE(const VectorDouble2D &pdataSet, const VectorDouble &pdataRes, int &rank,
               int &totalNodes) : pdataSet(pdataSet),
                                  pdataRes(pdataRes),
                                  rank(rank),
                                  totalNodes(totalNodes) {
        validateData();
        toEigen();

        settings = std::make_shared<RHADMMSettings>();  //default settings
        ptype = ProblemType::LogisticRegression;    // default problem type
    }

    void DOSE::toEigen() {
        pdataSetMat.setZero(rows, cols);
        pdataResVec.setZero(rows, 1);
        utilities::vec2Vec(pdataRes, pdataResVec);
        utilities::mat2Mat(pdataSet, pdataSetMat);

    }

    void DOSE::validateData() {
        utilities::checkVec2Mat(pdataSet);
        rows = pdataSet.size();
        cols = pdataSet.front().size();
        utilities::checkVec2Vec(pdataRes, rows);
    }

    void DOSE::solve(const VectorDouble &binvec) {
        Vec binvecEigen(cols, 1);
        utilities::vec2Vec(binvec, binvecEigen);
        AlgorithmPtr algorithm;
        switch (ptype) {
            case ProblemType::LinearRegression:
                algorithm = std::make_shared<LinRegStrategy>(pdataSetMat, pdataResVec, rank, totalNodes, M, settings);
                algorithm->solve(binvecEigen);
            case ProblemType::LogisticRegression:
                algorithm = std::make_shared<LogRegStrategy>(pdataSetMat, pdataResVec, rank, totalNodes, M, settings);
                algorithm->solve(binvecEigen);
        }
    }

    double DOSE::getTotalObjval() const {
        return totalObjval;
    }

    double DOSE::getLocalObjval() const {
        return localObjval;
    }

    const VectorDouble &DOSE::getSolution() const {
        return solution;
    }

    SolverStatue DOSE::getStatus() const {
        return status;
    }

    void DOSE::setPdataSet(const VectorDouble2D &pdataSetNew) {
        DOSE::pdataSet = pdataSetNew;
    }

    void DOSE::setPdataRes(const VectorDouble &pdataResNew) {
        DOSE::pdataRes = pdataResNew;
    }

    void DOSE::setPtype(ProblemType ptypeNew) {
        DOSE::ptype = ptypeNew;
    }

    void DOSE::setSettings(const SettingsPtr settingsNew) {
        DOSE::settings = settingsNew;
    }


}