#ifndef WORLD_HPP
#define WORLD_HPP

//-- Includes Needed Files
#include "HelpWindow.hpp"
#include "Field.hpp"
#include "Robot.hpp"
#include "Model.hpp"

class World {
private:
    Field field;
    Robot robot;
    Model model;
    HelpWindow status;
    Mat realWorld;
    Mat ModelField;

public:
    World();
    int updateWindow();
    void create();
    void createModel();
    static void mouseAttacher(int ,int ,int ,int ,void *);
    void Mouse(int ,int ,int ,int);
};

#endif // WORLD_HPP
