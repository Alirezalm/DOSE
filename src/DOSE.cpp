//
// Created by alireza on 17/05/22.
//

#include "../include/DOSE.h"
#include "../include/Utilities.h"

namespace dose {


    DOSE::DOSE(const VectorDouble2D &pdataSet,
               const VectorDouble &pdataRes,
               ProblemType ptype,
               const RHADMMSettings &settings) : pdataSet(pdataSet),
                                                 pdataRes(pdataRes),
                                                 ptype(ptype),
                                                 settings(settings) {
        validateData();


    }

    DOSE::DOSE(const VectorDouble2D &pdataSet,
               const VectorDouble &pdataRes,
               ProblemType ptype) : pdataSet(pdataSet),
                                    pdataRes(pdataRes),
                                    ptype(ptype) {
        validateData();
    }

    DOSE::DOSE(const VectorDouble2D &pdataSet,
               const VectorDouble &pdataRes) : pdataSet(pdataSet),
                                               pdataRes(pdataRes) {
        validateData()

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

    void DOSE::setPdataSet(const VectorDouble2D &pdataSet) {
        DOSE::pdataSet = pdataSet;
    }

    void DOSE::setPdataRes(const VectorDouble &pdataRes) {
        DOSE::pdataRes = pdataRes;
    }

    void DOSE::setPtype(ProblemType ptype) {
        DOSE::ptype = ptype;
    }

    void DOSE::setSettings(const RHADMMSettings &settings) {
        DOSE::settings = settings;
    }

    void DOSE::toEigen() {

    }

    void DOSE::validateData() {
        utilities::checkVec2Mat(pdataSet);
        rows = pdataSet.size();
        cols = pdataSet.front().size();
        utilities::checkVec2Vec(pdataRes, rows);
    }


}