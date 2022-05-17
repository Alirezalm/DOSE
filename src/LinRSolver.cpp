//
// Created by alireza on 16/05/22.
//

#include "LinRSolver.h"
namespace DOSE {
    Vec solveLinR(const Mat &A,
                  const Vec &b,
                  Vec &x,
                  Vec &y,
                  Vec &z,
                  double &rho,
                  const Vec &binVec,
                  const double &M) {
        const Ind n = x.size();
        Mat I(n, n);
        I.setIdentity();
        Mat Q = 0.5 * (A.transpose() * A + rho * I);
        Vec q = -A.transpose() * b + y - rho * z;
//        double d = 0.5 * b.dot(b) - y.dot(z) + 0.5 * rho * z.dot(z);
        ConjugateGradient<Mat> cg(Q);
        x = cg.solve(-q);
        projectLinR(x, binVec, M);
        return x;
    }

    void projectLinR(Vec &x, const Vec &binVec, const double &M) {
        x = (M * binVec).cwiseMin((-M * binVec).cwiseMax(x));
    }
}