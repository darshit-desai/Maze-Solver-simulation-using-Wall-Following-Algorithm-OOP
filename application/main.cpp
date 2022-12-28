/**
 * @file main.cpp
 * @author Darshit Desai (darshit@umd.edu) , Vamshi Kalavagunta (vamshik@umd.edu) , Vinay Bukka(vinay06@umd.edu)
 * @brief This is the main class which is built in the Simulator and used to call all other classes
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include "algorithm/algorithm.h"
#include "simulator/simulator.h"

int main(int argc, char* argv[])
{
    // // colorize and add text for the start position of the robot.
    Simulator::setColor(0, 0, 'R');
    Simulator::setText(0, 0, "START");
    //Creation of object named test for class Algorithm.
    rwa2group21::Algorithm test;
    std::cerr << "--- wall following ---" << std::endl;
    test.run(argv[1]);
}
