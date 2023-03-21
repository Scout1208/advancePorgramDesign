//
// Created by 李承彧 on 2023/3/10.
//

#include "Maze.h"
#include <iostream>
using namespace std;
//comparator
auto byMaze = [](const block& a, const block& b){
    return a.visited < b.visited;
};
auto byMapValue = [](const pair<int,int>&a, const pair<int,int> &b){
    return a.second < b.second;
};
void Maze::constructMazeByLine(string line, int numberOfLine,vector<vector<block> >&maze) {
    int n = line.size();
    for (int i = 0; i < n; i++) {
        if(line[i] == '.'){
            maze[numberOfLine+1][i+1] = block(i,numberOfLine,space,0);
        }
        else if (line[i] == '#'){
            maze[numberOfLine+1][i+1] = block(i,numberOfLine,obstacle,0);
        }
        else{
            maze[numberOfLine+1][i+1] = block(i,numberOfLine,robotLocation,1);
        }
    }
}
vector<vector<block> > Maze::initMaze(int wide, int height) {
    vector<vector<block>  > maze;
    //+2是最外圍
    for (int i = 0; i < height+2; i++) {
        maze.push_back(vector<block>());
        for (int j = 0; j < wide+2; j++) {
            maze[i].push_back(block());
        }
    }
    for (int i = 0; i < height+2; i++) {
        for (int j = 0; j < wide+2; j++) {
            maze[i][j].type = wall;
            maze[i][j].visited = 0;
        }
    }
    return maze;
}
void Maze::printMaze(vector <vector<block>> &maze) const{
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
//            cout<<maze[i][j].x_position<<' '<<maze[i][j].y_position<<' '<<maze[i][j].type<<' '<<maze[i][j].visited<<'\t';
//            cout<<' '<<maze[i][j].visited;
        }
        cout<<endl;
    }
}

int Maze::getBlockType(vector <vector<block>> &maze, int robot_x, int robot_y) const{
    return maze[robot_y+1][robot_x+1].type;
}

void Maze::increaseVisit(vector <vector<block>> &maze, int robot_x, int robot_y) {
    maze[robot_y+1][robot_x+1].visited+=1;
}

int Maze::getMaxValue(vector <vector<block>> &maze) const{
    int tempMax = 0;
    for (int i = 0; i < maze.size(); i++) {
        auto maxBlock = max_element(maze[i].begin(),maze[i].end(),byMaze);//回傳大排到小的iterator
        if(maxBlock->visited> tempMax){
            tempMax = maxBlock->visited;
        }
    }
    return tempMax;
}

unordered_map<int,int> Maze::getMostMap(vector <vector<block>> &maze) const{
    unordered_map<int,int> most;
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            if(maze[i][j].visited!=0)
            {
                most[maze[i][j].visited]+=1;
            }
        }
    }
    return most;
}

int Maze::getMostValue(unordered_map<int, int> &mostMap) const{
    auto mostValue = max_element(mostMap.begin(),mostMap.end(),byMapValue);//回傳大排到小的iterator
    return mostValue->first;
}
