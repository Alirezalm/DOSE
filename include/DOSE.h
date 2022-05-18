//
// Created by alireza on 17/05/22.
//

#ifndef DOSE_DOSE_H
#define DOSE_DOSE_H

#include "DistEngine.h"
#include "Exceptions.h"

namespace dose {

    class DOSE {
    public:
        DOSE(const VectorDouble2D &pdataSet, const VectorDouble &pdataRes, ProblemType ptype,
             SettingsPtr settings);

        DOSE(const VectorDouble2D &pdataSet, const VectorDouble &pdataRes, ProblemType ptype);

        DOSE(const VectorDouble2D &pdataSet, const VectorDouble &pdataRes);

        void setPdataSet(const VectorDouble2D &pdataSetNew);

        void setPdataRes(const VectorDouble &pdataResNew);

        void setPtype(ProblemType ptypeNew);

        void setSettings(const SettingsPtr settingsNew);

        double getTotalObjval() const;

        double getLocalObjval() const;

        const VectorDouble &getSolution() const;

        SolverStatue getStatus() const;

    private:
        VectorDouble2D pdataSet;
        VectorDouble pdataRes;
        ProblemType ptype;
        SettingsPtr settings;

        double totalObjval;
        double localObjval;
        VectorDouble solution;
        SolverStatue status;

        Mat pdataSetMat;
        Vec pdataResVec;

        int rows;
        int cols;

        void validateData();

        void toEigen();
    };

}


#endif //DOSE_DOSE_H
