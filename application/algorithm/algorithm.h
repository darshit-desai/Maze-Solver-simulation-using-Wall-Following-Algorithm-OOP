/**
 * @file algorithm.h
 * @author Darshit Desai (darshit@umd.edu) , Vamshi Kalavagunta (vamshik@umd.edu) , Vinay Bukka(vinay06@umd.edu)
 * @brief This file contains the implementation details for algorithm class.
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__
#include <iostream>
#include <array>
#include <memory>
#include <vector>
#include "../robot/robot.h"

namespace rwa2group21 {
/**
* @brief This class implements the search algorithm using a Left hand approach or right hand approach
*/
class Algorithm {
    public:
    /**
     * @brief This method is called from the main file, after which the whole methods of bot
     * traversing around maze is called sequentially.     
     * @param algo , This parameter is used to store the value of algorithm to be followed in the build of Simulator.
     */
    void run(std::string algo);
    /**
     * @brief This method is internally called from the run method to highlight all the 
     * outer walls of any maze selected before moving the bot. 
     */
    void init_outer_walls();
    /**
     * @brief left handed wall algorithm is executed using methods of robot class
     * by recording and evaluating current position and orientation. This is called
     * from run method of algorithm as well.
     */
    void follow_wall_left();
    /**
     * @brief right handed wall algorithm is executed using methods of robot class
     * by recording and evaluating current position and orientation.This is called from
     * run method of algorithm class as well .
     */
    void follow_wall_right();
    /**
     * @brief generating a random goal every time using srand and rand function and 
     * is done during the start of the program.
     */
    void generate_goal();
    /**
     * @brief Setting the right wall of a cell whenever the bot in that 
     * particular cell finds a wall on the right when it is moving in the maze.
     */
    void set_right_wall();
    /**
     * @brief Setting the left wall of a cell whenever the bot in that 
     * particular cell finds a wall on the left when it is moving in the maze.
     */
    void set_left_wall();
    /**
     * @brief Setting the front wall of a cell whenever the bot in that 
     * particular cell finds a wall on the front when it is moving in the maze.
     */
    void set_front_wall();
    /**
     * @brief Function is responsible for elimination of deadend coordinates during
     * forward movement of the robot
     * 
     */
    void traceback_coordinate_elimination();  
    /**
     * @brief Function for tracing back robot movement using coordinates generated
     * from coordinate elimination function
     * 
     */
    void traceback_robot_movement();
    /**
     * @brief Creating a constructor using member initalisation list and default values.
     * Intialised the instance of robot class using unique pointer.
     */
    Algorithm() : robot (std::make_unique<Robot>()), m_maze_height{16} , m_maze_width{16},goal{0,0}{
    }
     private:
        std::unique_ptr<Robot> robot; // Creating a unique pointer object robot of class Robot to access the methods
        std::pair<int, int> goal; //Initialsing goal with (0,0) then overriding it with random goal value generated. 
        int m_maze_height; //Setting the maze height to 16.
        int m_maze_width; //Setting the maze width to 16.
    
};
} // namespace rwa2group21
#endif