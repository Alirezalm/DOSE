//
// Created by alireza on 17/05/22.
//

#include "../include/DOSE.h"
#include "../include/Utilities.h"

namespace dose {


    DOSE::DOSE(const VectorDouble2D &pdataSet,
               const VectorDouble &pdataRes,
               ProblemType ptype,
               SettingsPtr settings) : pdataSet(pdataSet),
                                       pdataRes(pdataRes),
                                       ptype(ptype),
                                       settings(settings) {
        validateData();
        toEigen();


    }

    DOSE::DOSE(const VectorDouble2D &pdataSet,
               const VectorDouble &pdataRes,
               ProblemType ptype) : pdataSet(pdataSet),
                                    pdataRes(pdataRes),
                                    ptype(ptype) {
        validateData();
        toEigen();

        settings = std::make_shared<RHADMMSettings>();  //default settings
    }

    DOSE::DOSE(const VectorDouble2D &pdataSet,
               const VectorDouble &pdataRes) : pdataSet(pdataSet),
                                               pdataRes(pdataRes) {
        validateData();
        toEigen();

        settings = std::make_shared<RHADMMSettings>();  //default settings
        ptype = ProblemType::LogisticRegression;    // default problem type
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


}