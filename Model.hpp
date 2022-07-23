#ifndef MODEL_HPP
#define MODEL_HPP

#include "Configs.hpp"

class Model {
    private:
        double x;
        double y;
        double modelX;
        double modelY;
        double modelvX;
        double modelvY;
        double modelvTetha;
        double modelTetha;
        double theta;
    public:
        void   setPosition(double, double, double);
        void   setVelocity(double, double, double);
        void   updateModel();
        double accessX();
        double accessY();
        double accessvX();
        double accessvY();
        double accessvTetha();
        double accessTheta();



};

#endif // MODEL_HPP
