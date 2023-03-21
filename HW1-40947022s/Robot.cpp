//
// Created by 李承彧 on 2023/3/10.
//

#include "Robot.h"
#include "Maze.h"
#include <iostream>
using namespace std;
void Robot::walkOneStep(Robot &robot){
    if(robot.face == 0){//north
        robot.y_position-=1;
    }
    else if (robot.face == 1){//east
       robot.x_position+=1;
    }
    else if(robot.face == 2){//south
        robot.y_position+=1;
    }
    else{//west
        robot.x_position-=1;
    }
}
int Robot::getLoopStep(long long n,int loop) const{
    int numberOfWalk = 0;
    numberOfWalk = n % loop;
    return numberOfWalk;
}
void Robot::turnRight(Robot& robot) {
    if(robot.face<3)
    {
        robot.face += 1;
    } else{
        robot.face = 0;
    }
}
int Robot::getLoopNumber(unordered_map<int, int> &mostMap,int mostValue,int maxValue) const{
    int sum = 0;
    for (int i = mostValue-1; i < maxValue+1; i++){//根據觀察，需要mostValue,mostValue-1 or mostValue,mostValue+1
        if(mostMap.count(i) != 0)
        {
            if(i>mostValue+1)//重複走兩次(交叉點)
            {
//                cout<<"sum"<<sum<<endl;
                sum+=1;
            }
            sum += mostMap[i];
        }
    }
    return sum;
}
int Robot::detectObstacle(vector <vector<block>> &maze, Robot robot, Maze m){
    walkOneStep(robot);
    if(m.getBlockType(maze,robot.x_position,robot.y_position) == obstacle)
    {
        return 1;
    } else
    {
        return 0;
    }
}
pair<int,int> Robot::findRobotLocationInMaze(vector<vector<block>> &maze) const{
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            if(maze[i][j].type == robotLocation){
//                maze[i][j].type = space;
                return make_pair(maze[i][j].x_position,maze[i][j].y_position);
            }
        }
    }
    return make_pair(-1,-1);
}
pair<int, int> Robot::getRobotPosition(Robot robot) const{
    return make_pair(robot.x_position,robot.y_position);
}

