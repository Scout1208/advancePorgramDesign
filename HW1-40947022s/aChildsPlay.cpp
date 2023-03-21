//
// Created by 李承彧 on 2023/3/11.
//
#include "Robot.h"
#include "Maze.h"
#include <iostream>

using namespace std;
int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    long long n;
    Maze m;
    vector<vector<block> >maze;
    maze = m.initMaze(w,h);
    cin >> n; cin.ignore();
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        m.constructMazeByLine(line,i,maze);
    }
    //複雜度O(wh)
    //m.printMaze(maze);
    Robot robot = Robot(0,0);
    pair<int,int> location = robot.findRobotLocationInMaze(maze);
    //複雜度O(wh)
    robot = Robot(location.first,location.second);
    int curr_step = 0;
    int curr_max = 0;
    int pre_max = 0;
    int loop = 0;
    int remainStep = 0;
    while (n>0){
        pre_max =m.getMaxValue(maze);
        if(!robot.detectObstacle(maze,robot,m)){
            robot.walkOneStep(robot);
            m.increaseVisit(maze,robot.getRobotPosition(robot).first,robot.getRobotPosition(robot).second);
            curr_step+=1;
            n-=1;
        } else{
            robot.turnRight(robot);
        }
        curr_max = m.getMaxValue(maze);
        if(curr_step > 150&& curr_max>pre_max)
        {
            break;
        }
    }
    if(n!=0)
    {
        unordered_map<int,int> mostMap = m.getMostMap(maze);
        loop = robot.getLoopNumber(mostMap,m.getMostValue(mostMap),m.getMaxValue(maze));
//        cout<<m.getMaxValue(maze)<<' '<<m.getMostValue(mostMap)<<endl;
//        cout<<loop<<endl;
        remainStep = robot.getLoopStep(n,loop);
//        cout<<"remain"<<remainStep<<endl;
        while (remainStep>0)
        {
            if(!robot.detectObstacle(maze,robot,m)){
                robot.walkOneStep(robot);
                remainStep-=1;
            } else{
                robot.turnRight(robot);
            }
        }
    }
//    m.printMaze(maze);
    pair<int,int>result = robot.getRobotPosition(robot);
    cout<<result.first<<' '<<result.second<<endl;
}