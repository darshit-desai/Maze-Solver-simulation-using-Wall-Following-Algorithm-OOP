/**
 * @file robot.h
 * @author Darshit Desai (darshit@umd.edu) , Vamshi Kalavagunta (vamshik@umd.edu) , Vinay Bukka(vinay06@umd.edu)
 * @brief This class is used to drive the robot based on its position and orientation.
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#ifndef __ROBOT_H__
#define __ROBOT_H__

namespace rwa2group21 {
class Robot {
public:
    /**
     * @brief Executes when turn left method is called from algorithm class and 
     * updates m_position and m_direction accordingly. Calls the turn_left of Simulator class
     * to turn the robot 90 degrees in CCW
     */
    void turn_left();
    /**
     * @brief when turn right method is called from algorithm class and 
     * updates m_position and m_direction accordingly. Calls the turn_right of Simulator class
     * to turn the robot 90 degrees in CW
     */
    void turn_right();
    /**
     * @brief when turn move forward method is called from algorithm class and 
     * updates m_position and m_direction accordingly. Calls the move_forward of Simulator class
     * to move robot one cell forward. This method is called after robot turning left and right as well.
     */
    void move_forward();
    /**
     * @brief Getter to return current position of robot along y direction
     * 
     * @return int , a value from 0-15 denoting robot's y position
     */
    int robot_get_y () { return m_position.second; }
    /**
     * @brief Getter to return current position of robot along x direction
     * 
     * @return int , a value from 0-15 denoting robot's x position
     */
    int robot_get_x () { return m_position.first; }
    /**
     * @brief Getter to return the current direction of the robot in 
     * the cell
     * @return char , any of the values ['n','s','e','w']
     */
    char robot_get_direction () { return m_direction; }
    std::vector<std::pair<int, int>> v5;    // A vector v5 is used to append and track position of the robot along with its movement.
    /**
     * @brief A constructor created with member initalisation list
     * with default intial values for position, direction
     * 
     */
    Robot(): m_position{0,0},m_direction{'n'},v5{std::pair{0,0}} {
    }
private:
    std::pair<int, int> m_position; // Used to store current position along x and y.
    char m_direction; //Used to store current direction of the robot.
};
} // namespace rwa2group21

#endif