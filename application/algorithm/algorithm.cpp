#include <cstdlib>
#include <iostream>
#include <array>
#include <vector>
#include "algorithm.h"
#include "../simulator/simulator.h"
#include <algorithm>
#include "../robot/robot.h"

void rwa2group21::Algorithm::generate_goal()
{
    std::vector<int> v{0,15};
    std::srand(time(0));
    if((std::rand() % 2) ==0){
        goal.first= std::rand()%15;
        if(goal.first==0 || goal.first==15){
            goal.second= std::rand()%15;
        }
        else{
            int index =  std::rand()%2;
            goal.second = v[index];
        }
    } else {
        goal.second= std::rand()%15;
        if(goal.second==0 || goal.second==15){
            goal.first = std::rand()%15;
        }
        else{
            int index =  std::rand()%2;
            goal.first = v[index];
        }
    }
    Simulator::setColor(goal.first,goal.second,'r');
    Simulator::setText(goal.first, goal.second, "G");
    //Printing the Goal coordinates to simulator output.
    std::cerr << "x goal="<<goal.first<<"  y goal= "<<goal.second<< std::endl;
}

void rwa2group21::Algorithm::follow_wall_left()
{
    while (robot->robot_get_x() != goal.first || robot->robot_get_y() != goal.second){
        //flag variables are used to check the all directions of walls to see if there is any
        // wall present. If wall is present, the wall is set by calling appropriate method.
        bool flag1 = Simulator::wallRight();
        bool flag2 = Simulator::wallFront();
        bool flag3 = Simulator::wallLeft();
        if (flag3==false) {
            if (flag1==true){
                set_right_wall();
            }
            if (flag2==true){
                set_front_wall();
            }
            robot->turn_left();
            std::cerr << "--- turn left ---" << std::endl;
            robot->move_forward();
        }
        else if (flag2==false) {
            set_left_wall();
            if(flag1==true){
                set_right_wall();
            }
            robot->move_forward();
        }
        else if (flag1==false){
            set_left_wall();
            set_front_wall();
            robot->turn_right();
            std::cerr << "--- turn right ---" << std::endl;
            robot->move_forward();
        }
        else{
            set_left_wall();
            set_front_wall();
            set_right_wall();
            robot->turn_left();
            std::cerr << "--- turn left ---" << std::endl;
            robot->turn_left();
            std::cerr << "--- turn left ---" << std::endl;
            robot->move_forward();
        }
        traceback_coordinate_elimination();
    }
    bool goal_flag1 = Simulator::wallRight();
    bool goal_flag2 = Simulator::wallFront();
    bool goal_flag3 = Simulator::wallLeft();
    if (goal_flag3==false) {
        if (goal_flag1==true){
                set_right_wall();
            }
        if (goal_flag2==true){
                set_front_wall();
            }        
    }
    else if(goal_flag2==false) {
            set_left_wall();
            if(goal_flag1==true){
                set_right_wall();
            }
    }
    else if (goal_flag1==false){
            set_left_wall();
            set_front_wall();
    }
    else{
            set_right_wall();
            set_front_wall();
            set_left_wall();
    }   
}

void rwa2group21::Algorithm::follow_wall_right()
{
    while(robot->robot_get_x()!=goal.first || robot->robot_get_y()!=goal.second){
        bool flag1 = Simulator::wallRight();
        bool flag2 = Simulator::wallFront();
        bool flag3 = Simulator::wallLeft();
        if (flag1==false) {
            if(flag2==true){
                set_front_wall();
            }
            if(flag3==true){
                set_left_wall();
            }            
            std::cerr << "No Wall On right" <<std::endl;
            robot->turn_right();
            std::cerr << "--- turn right ---" << std::endl;
            robot->move_forward();
        }
        else if(flag2==false) {
            set_right_wall();
            if(flag3==true){
                set_left_wall();
            }
            robot->move_forward();
        }
        else if (flag3==false){
            set_right_wall();
            set_front_wall();
            robot->turn_left();
            std::cerr << "--- turn left ---" << std::endl;
            robot->move_forward();
        }
        else{
            set_right_wall();
            set_front_wall();
            set_left_wall();
            robot->turn_right();
            std::cerr << "--- turn right ---" << std::endl;
            robot->turn_right();
            std::cerr << "--- turn right ---" << std::endl;
            robot->move_forward();
        }
        traceback_coordinate_elimination();
    }
    bool goal_flag1 = Simulator::wallRight();
    bool goal_flag2 = Simulator::wallFront();
    bool goal_flag3 = Simulator::wallLeft();
    if (goal_flag1==false) {
            if(goal_flag2==true){
                set_front_wall();
            }
            if(goal_flag3==true){
                set_left_wall();
            } 
    }
    else if(goal_flag2==false) {
            set_right_wall();
            if(goal_flag3==true){
                set_left_wall();
            }
    }
    else if (goal_flag3==false){
            set_right_wall();
            set_front_wall();
    }
    else{
            set_right_wall();
            set_front_wall();
            set_left_wall();
    }    
}

void rwa2group21::Algorithm::init_outer_walls()
{
    for (int i=0 ; i<m_maze_height ; i++){
        for (int j=0 ; j<m_maze_width;j++){
            if(i==0 ){
                Simulator::setWall(i, j, 'w');
            }else if(i==15){
                Simulator::setWall(i, j, 'e');
            }else if(j==0){
                Simulator::setWall(i, j, 's');
            }else if(j==15){
                Simulator::setWall(i, j, 'n');
            }
        }
        
    }   
    Simulator::setWall(0, 0, 's');
    Simulator::setWall(0, 15, 'n');
    Simulator::setWall(15, 0, 's');
    Simulator::setWall(15, 15, 'n');
}

void rwa2group21::Algorithm::set_front_wall(){
    Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(),robot->robot_get_direction());
}
void rwa2group21::Algorithm::set_left_wall(){
    if (robot->robot_get_direction()=='n'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 'w');    
    }
    else if (robot->robot_get_direction()=='e'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 'n');    
    }
    else if (robot->robot_get_direction()=='s'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 'e');    
    }
    else if (robot->robot_get_direction()=='w'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 's');    
    }  
}
void rwa2group21::Algorithm::set_right_wall(){
    if (robot->robot_get_direction()=='n'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 'e');    
    }
    else if (robot->robot_get_direction()=='e'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 's');    
    }
    else if (robot->robot_get_direction()=='s'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 'w');    
    }
    else if (robot->robot_get_direction()=='w'){
        Simulator::setWall(robot->robot_get_x(), robot->robot_get_y(), 'n');    
    }  
}

void rwa2group21::Algorithm::run(std::string algo){
    //algo variable defines the type of algorithm you selected in build.

    //Generating the random goal
    generate_goal();
    //Initialising all the outer walls before movement of the robot starts.
    init_outer_walls();
    //Condition to execute either left or right wall follower algorithm.
    if (algo=="left"){
        follow_wall_left();
        traceback_robot_movement();
    }
    else if (algo=="right"){
        follow_wall_right();
        traceback_robot_movement();
    }
    else{
        std::cerr << "Invalid Command line argument Define 'right' or 'left' in build" << std::endl;
    }
}

void rwa2group21::Algorithm::traceback_coordinate_elimination(){
    size_t array_size = robot->v5.size();
    std::vector<std::pair<int, int> > temp;
    temp = robot->v5;
    int l{};
    for (size_t i = 1; i < array_size; i++)
    {
        int k=0;
        // int j=i-2;
        int j=0;
        // if (j>0){
        while (j!=i)
        {
            if (robot->v5.at(i).first==robot->v5.at(j).first && robot->v5.at(i).second==robot->v5.at(j).second ){
                k=i-j;
                l=k;
                break;
            }
            j++;
        }
    }
    while (l>0){
        robot->v5.pop_back();
        l--;
    }
    
    
    
}

void rwa2group21::Algorithm::traceback_robot_movement(){
    Simulator::clearAllColor();
    Simulator::clearAllText();
    Simulator::setColor(0,0,'R');
    Simulator::setText(robot->robot_get_x(),robot->robot_get_y(),"START");
    Simulator::setColor(0,0,'R');
    Simulator::setText(0,0,"G");
    robot->turn_right();
    robot->turn_right();
    //ret is used for making a copy of the vector which contains the path of the robot.
    std::vector<std::pair<int, int>> ret;
    ret = robot->v5;
    size_t array_size1 = ret.size();
    int i = array_size1-1;
    while ((robot->robot_get_x()!=0) || (robot->robot_get_y()!=0)){
        if ((ret.at(i).first==ret.at(i-1).first)&&(ret.at(i).second>ret.at(i-1).second))
        {
            if (robot->robot_get_direction()=='s'){
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='e'){
                robot->turn_right();
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='w'){
                robot->turn_left();
                robot->move_forward();
                i--;
            }
        }
        else if ((ret.at(i).first==ret.at(i-1).first)&&(ret.at(i).second<ret.at(i-1).second))
        {
            if (robot->robot_get_direction()=='n'){
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='e'){
                robot->turn_left();
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='w'){
                robot->turn_right();
                robot->move_forward();
                i--;
            }
        }
        else if ((ret.at(i).first<ret.at(i-1).first)&&(ret.at(i).second==ret.at(i-1).second))
        {
            if (robot->robot_get_direction()=='e'){
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='n'){
                robot->turn_right();
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='s'){
                robot->turn_left();
                robot->move_forward();
                i--;
            }
        }
        else if ((ret.at(i).first>ret.at(i-1).first)&&(ret.at(i).second==ret.at(i-1).second))
        {
            if (robot->robot_get_direction()=='w'){
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='n'){
                robot->turn_left();
                robot->move_forward();
                i--;
            }
            else if(robot->robot_get_direction()=='s'){
                robot->turn_right();
                robot->move_forward();
                i--;
            }
        }
    }
}
    
