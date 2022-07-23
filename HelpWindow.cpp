#include "HelpWindow.hpp"

//---------------------------------
//--| Help Window Configuration |--
//---------------------------------
//-- Help Window Size
double helpWindowWidth = fieldLength / 1.3;
double helpWindowLength = fieldWidth / 2;
//-- Activity Circle Colors and Attributes
int activityStateValue = 0;
int stopStateValue = 0;
int counter = 0;
int state = 1;
//-- Help Window Background Color Config
int windowColorBlue = 20;
int windowColorGreen = 20;
int windowColorRed = 20;
//-- Help Window Font Size
double helpWindowFontSize;
//-- Help Window Text Colors
int helpWindowTextBlue = 255 ;
int helpWindowTextGreen = 255;
int helpWindowTextRed = 0;

//-- Constructor to Set Default Values
HelpWindow::HelpWindow() {
    Scale = modelScale * 12;
    if (Scale >= 2500){
        helpWindowFontSize = 1.4;
    } else if (Scale > 1550 && Scale < 2500) {
        helpWindowFontSize = 0.9;
    } else {
        helpWindowFontSize = 0.5;
    }
    //-- Config Display Values
    state = 1;
    counter = 0;
    fadingSpeed = 1;
    activeValue = 0;
    stoppedValue = 0;
    fadingFluency = 2;
    // positionW = 0.0625;
    // positionS = 0.1250;
    // positionD = 0.1875;
    // positionA = 0.2500;
    // positionP = 0.3125;
    // positionC = 0.3750;
    // positionM = 0.4375;
    // positionR = 0.5000;
    // positionQ = 0.5625;
    // positionText = 0.0625;
    // positionError = 0.7500;
    // positionStatus = 0.1200;
    // positionStatusCircle = 0.6875;
    // positionUpdateSpeed = 0.8125;
    // statusCircleSize = modelScale / 15;
    keySize = helpWindowLength * modelScale / 8;
    keyLineSize = lineSize * 1.5;
    keyPaddingLength = helpWindowLength * modelScale / 20;
    keyPaddingWidth = helpWindowWidth * modelScale / 20;
    keyPositionX = helpWindowLength * modelScale * 0.09;
    keyPositionY = helpWindowWidth * modelScale * 0.1;
}

//-- Makes Help Window
void HelpWindow::updateHelpWindow(bool value) {
    //-- Set Active/Deactive Value
    active = value;
    //-- Creates Help Window
    helpWin = Mat(helpWindowWidth * modelScale, helpWindowLength * modelScale, CV_8UC3, Scalar(10,10,10));
    //-- Definition of Points and Strings
    //- Key I :
    string keyI = "I";
    string infoI = "Increase Velocity in X Axis";
    Point keyI1(keyPositionX + + keyPaddingLength +(keySize) * 2, keyPositionY - (keySize + keyPaddingLength));
    Point keyI2(keyPositionX + keySize + keyPaddingLength + (keySize) * 2, keyPositionY + keySize - (keySize + keyPaddingLength));
    rectangle(helpWin, keyI1, keyI2, Scalar(0,255,0), keyLineSize, 8, 0);
    //- Key H :
    string keyH = "H";
    string infoH = "Increase Velocity in Y Axis";
    Point keyH1(keyPositionX, keyPositionY);
    Point keyH2(keyPositionX + keySize, keyPositionY + keySize);
    rectangle(helpWin, keyH1, keyH2, Scalar(255,255,0), keyLineSize, 8, 0);
    //- Key J :
    string keyJ = "J";
    string infoJ = "Decrease Rotation Velocity";
    Point keyJ1(keyPositionX + (keySize + keyPaddingLength) * 1, keyPositionY);
    Point keyJ2(keyPositionX + keySize + (keySize + keyPaddingLength) * 1, keyPositionY + keySize);
    rectangle(helpWin, keyJ1, keyJ2, Scalar(255,255,0), keyLineSize, 8, 0);
    //- Key K :
    string keyK = "K";
    string infoK = "Stops Agent";
    Point keyK1(keyPositionX + (keySize + keyPaddingLength) * 2, keyPositionY);
    Point keyK2(keyPositionX + keySize + (keySize + keyPaddingLength) * 2, keyPositionY + keySize);
    rectangle(helpWin, keyK1, keyK2, Scalar(255,255,0), keyLineSize, 8, 0);
    //- Key L :
    string keyL = "L";
    string infoL = "Increase Rotation Velocity";
    Point keyL1(keyPositionX + (keySize + keyPaddingLength) * 3, keyPositionY);
    Point keyL2(keyPositionX + keySize + (keySize + keyPaddingLength) * 3, keyPositionY + keySize);
    rectangle(helpWin, keyL1, keyL2, Scalar(255,255,0), keyLineSize, 8, 0);
    //- Key semicolon :
    string keysemicolon = "semicolon";
    string infosemicolon = "Decrease Velocity in Y Axis";
    Point keysemicolon1(keyPositionX + (keySize + keyPaddingLength) * 4, keyPositionY);
    Point keysemicolon2(keyPositionX + keySize + (keySize + keyPaddingLength) * 4, keyPositionY + keySize);
    rectangle(helpWin, keysemicolon1, keysemicolon2, Scalar(255,255,0), keyLineSize, 8, 0);
    imshow("Help Window", helpWin);
}

//-- Update Status of Speed Change (Movement and Rotation)
void HelpWindow::updateStatus(int option, double velocity) {
    if (option == 1) {
        speedStatus = "X Axis Velocity Changed to: " + to_string(velocity);
    } else if (option == 2) {
        speedStatus = "Y Axis Velocity Changed to" + to_string(velocity);
    } else if(option == 3) {
        speedStatus = "Rotation Velocity Changed to" + to_string(velocity);
    } else {
        speedStatus = "";
    }
}

//-- Update Help Window Border Error
void HelpWindow::updateError(string err) {
    error = err;
}

//-- Reset Error Data
void HelpWindow::resetError()
{
    error = " ";
}

//-- Fader Function for Activity Circle
int HelpWindow::Fader() {
    int temp1 = activeValue;
    int temp2 = stoppedValue;
    if (active == true) {
        status = "Active";
        stoppedValue = 0;
        activeValue = activeValue + state * fadingFluency;
        if (counter % fadingSpeed == 0) {
            if (activeValue > 255) {
                state = -1;
            } else if (activeValue < 0) {
                state = 1;
                activeValue = temp1;
            }
        } else if (counter > 100) {
            counter = 0;
        }
    } else {
        status = "Stopped";
        activeValue = 0;
        stoppedValue = stoppedValue + state * fadingFluency;
        if (counter % fadingSpeed == 0) {
            if (stoppedValue > 255) {
                state = -1;
            } else if (stoppedValue < 0) {
                state = 1;
                stoppedValue = temp2;
            }
        } else if (counter > 100) {
            counter = 0;
        }
    }
    counter++;
    return activeValue;
}