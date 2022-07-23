#ifndef HELPWINDOW_HPP
#define HELPWINDOW_HPP

#include "Configs.hpp"

//-- Help Window Class
class HelpWindow {
    private:
        Mat helpWin;
        double Scale;
        double keySize;
        double keyLineSize;
        double keyPaddingLength;
        double keyPaddingWidth;
        double keyPositionX;
        double keyPositionY;
        double keyPressedValue;
        double keyFreeValue;




        string status;
        string error;
        string speedStatus;
        int activeValue;
        int stoppedValue;
        bool active;
        int state;
        int fadingFluency;
        int fadingSpeed;
        int counter;
        int statusCircleSize;
    public:
        void updateHelpWindow(bool);
        int activityCircle();
        HelpWindow();
        //-- Update Status of Changes
        void updateStatus(int, double);
        void updateError(string);
        int Fader();
        void resetError();
};

#endif // HELPWINDOW_HPP
