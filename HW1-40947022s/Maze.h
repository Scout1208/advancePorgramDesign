//
// Created by 李承彧 on 2023/3/10.
//

#ifndef ADVANCED_PROGRAM_DESIGN_MAZE_H
#define ADVANCED_PROGRAM_DESIGN_MAZE_H
#include <vector>
#include <string>
#include <unordered_map>
static constexpr int space = 0;//空格
static constexpr int obstacle = 1;//障礙物
static constexpr int robotLocation = -1;//起始位置
static constexpr int wall = 1;//牆壁
using namespace std;
class block{
public:
    int x_position;
    int y_position;
    int type;//格子類型：空格、障礙物、牆壁、起始位置
    int visited;//走訪次數
    block(int x,int y,int type,int visited):x_position(x),y_position(y),type(type),visited(visited){}
    block():x_position(0),y_position(0),type(0),visited(0){}
};
class Maze:private block{
private:
    int wide;
    int height;
public:
  void constructMazeByLine(string line ,int numberOfLine,vector <vector<block> >& maze);//讀入input資訊創建Maze
  vector<vector<block> > initMaze(int wide,int height);//初始化Maze
  int getBlockType(vector< vector<block> > &maze,int robot_x,int robot_y) const;//取得Maze中某位置的格子類型
  void printMaze(vector< vector<block> > &maze) const;//印出Maze
  void increaseVisit(vector <vector<block>> &maze, int robot_x, int robot_y);//增加Maze某格的走訪次數
  int getMaxValue(vector <vector<block>> &maze)const;//取得Maze中的最大值
  int getMostValue(unordered_map<int,int> &mostMap)const;//取得Maze中出現最多次的值
  unordered_map<int,int> getMostMap(vector<vector<block> > &maze)const;//取得key是數值，value是數值出現次數的map
};


#endif //ADVANCED_PROGRAM_DESIGN_MAZE_H
