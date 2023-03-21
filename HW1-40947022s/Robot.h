//
// Created by 李承彧 on 2023/3/10.
//

#ifndef ADVANCED_PROGRAM_DESIGN_ROBOT_H
#define ADVANCED_PROGRAM_DESIGN_ROBOT_H
#include <utility>
#include "Maze.h"
using namespace std;

class Robot {
private:
    int x_position;
    int y_position;
    int face;
public:
    Robot(int x,int y):face(0),x_position(x),y_position(y){}
    Robot(int f,int x,int y):face(f),x_position(x),y_position(x){}
    void walkOneStep(Robot &robot);//走面向方向一步
    int getLoopStep(long long n,int loop)const;//找重複繞圈完後剩下的步數
    void turnRight(Robot &robot);//向右轉
    int getLoopNumber(unordered_map<int,int> &mostMap,int mostValue,int maxValue)const;//找重複部分所需步數
    int detectObstacle(vector<vector<block>> &maze,Robot robot,Maze m);//偵測面向方向的下一步是否為障礙物
    pair<int,int>getRobotPosition(Robot robot)const;//取得Robot當前位置
    pair<int,int> findRobotLocationInMaze(vector<vector<block> > &maze)const;//尋找Robot的初始位置
};


#endif //ADVANCED_PROGRAM_DESIGN_ROBOT_H
