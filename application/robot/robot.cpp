#include <iostream>
#include <vector>
#include "robot.h"
#include "../simulator/simulator.h"

void rwa2group21::Robot::move_forward(){
    //If the direction of robot is north and it is moved forward, you will move 1 cell forward
    //along y-direction. Similar for all other directions when moving forward.
    if (m_direction=='n'){
        m_position.second+=1;
    }
    else if (m_direction== 's'){
        m_position.second-=1;
    }
    else if (m_direction == 'e'){
        m_position.first+=1;
    }
    else if (m_direction == 'w'){
        m_position.first-=1;
    }
    //Using vector to append the current position whenever move forward is called
    v5.push_back(std::make_pair(m_position.first, m_position.second));
    Simulator::setColor(m_position.first,m_position.second,'c');
    Simulator::moveForward();
}

void rwa2group21::Robot::turn_right(){
    //Whenever the robot is in north direction and has to take a right, the new direction 
    //of the robot becomes east. Same applies for other directions.
    if (m_direction== 'n'){
        m_direction='e';
    }
    else if (m_direction== 'e'){
        m_direction = 's';
    }
    else if (m_direction == 'w'){
        m_direction = 'n';
    }
    else if (m_direction== 's'){
        m_direction= 'w';
    }  
    Simulator::turnRight();
}

void rwa2group21::Robot::turn_left(){
    //Whenever the robot is in north direction and has to take a left, the new direction 
    //of the robot becomes west. Same applies for other directions.
    if (m_direction == 'n'){
        m_direction='w';
    }
    else if (m_direction== 'e'){
        m_direction = 'n';
    }
    else if (m_direction == 'w'){
        m_direction='s';
    }
    else if (m_direction == 's'){
        m_direction='e';
    }
    Simulator::turnLeft();
    
}