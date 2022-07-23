#include "Model.hpp"

void Model::setPosition(double inputX, double inputY, double inputTheta){  
   modelX = inputX;
   modelY = inputY;
   modelTetha = inputTheta;

}
void Model::setVelocity(double inputX, double inputY, double inputTheta) {
    modelvX = inputX;
    modelvY = inputY;
    modelvTetha = inputTheta;
}

void Model::updateModel() {
    //-- Movement Part
    double globalVX = modelvX * cos(modelTetha) + modelvY * sin(-modelTetha);
    double globalVY = modelvY * cos(-modelTetha) + modelvX * sin(modelTetha);
    modelX = modelX - globalVX * refreshRate;
    modelY = modelY - globalVY * refreshRate;
    //-- Rotation Part
    modelTetha += modelvTetha * refreshRate;

}


double Model::accessTheta(){
    return modelTetha;
}

double Model::accessX(){
    return modelX;
}

double  Model::accessY(){
    return modelY;
}

double Model::accessvX(){
    return modelvX;
}

double Model::accessvY(){
    return modelvY;
}

double Model::accessvTetha(){
   return  modelvTetha;
}