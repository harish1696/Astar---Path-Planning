/**
 *  MIT License
 *  
 *  Copyright (c) 2018 Harish Sampathkumar
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include "Nodes.hpp"
#include "Map.hpp"

bool sortCriteria(std::vector<double> &node1, std::vector<double> &node2) {
  if (node1[2] < node2[2]) return true;
  else return false;
}

Nodes::Nodes(cv::Mat &img, int x, int y) {
  map.createMap(img);
  Node.push_back({x, y});
  NodeInfo.push_back({0, 0, 0});
  pQueue.push_back({0, 0, 0});
  nodeNumber = 1;
}

Nodes::~Nodes() {}

bool Nodes::moveUp(int x, int y) {
  y = y + 1;
  bool poss;
  if (y < 150)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false;
}

bool Nodes::moveDown(int x, int y) {
  y = y - 1;
  bool poss;
  if (y >= 0)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false;
}

bool Nodes::moveLeft(int x, int y) {
  x = x - 1;
  bool poss;
  if (x >= 0)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false;
}

bool Nodes::moveRight(int x, int y) {
  x = x + 1;
  bool poss;
  if (x < 250)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false;
}

bool Nodes::moveUpLeft(int x, int y) {
  x = x - 1;
  y = y	+ 1;
  bool poss;
  if (x >= 0 && y < 150)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false;
}

bool Nodes::moveUpRight(int x, int y) {
  x = x + 1;
  y = y	+ 1;
  bool poss;
  if (x < 250 && y < 150)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false;
}

bool Nodes::moveDownLeft(int x, int y) {
  x = x - 1;
  y = y	- 1;
  bool poss;
  if (x >= 0 && y >= 0)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false; 
}

bool Nodes::moveDownRight(int x, int y) {
  x = x + 1;
  y = y	- 1;
  bool poss;
  if (x < 250 && y >= 0)
  	return poss = map.isObstacle(x, y);
  else
  	return poss = false;
}

void Nodes::addNode(int x, int y, int parent, double cost) {
  std::vector<int> temp1 = {x, y};
  std::vector<double> temp2 = {(double)nodeNumber, (double)parent, cost};
  Node.push_back(temp1);
  NodeInfo.push_back(temp2);
}

void Nodes::addNode(int x, int y, int parent, double cost, double heuristic) {
  std::vector<double> temp2 = {(double)nodeNumber, (double)parent, cost + heuristic};
  pQueue.push_back(temp2);
  nodeNumber += 1;
}

int Nodes::isNew(int x, int y) {
  vec_size length = Node.size();	
  for (int i = 0; i < length; i++) {
  	if(Node[i][0] == x && Node[i][1] == y) {
      return i + 1;
  	}
  }
  return 0; 
}

int Nodes::findIndex(int New) {
  vec_size length = pQueue.size();
  for (int i = 0; i < length; i++) {
    if(pQueue[i][0] == New)
      return i + 1;
  }
  return 0;  
}

void Nodes::optPath() {
  std::vector<int> temp;
  // vec_size node = Node.size() - 1;
  int node = pQueue[0][0];
  while(node > 0) {
    temp = {Node[node][0], Node[node][1]};
    Path.push_back(temp);
    node = NodeInfo[node][1];  
  }
  temp = {Node[0][0], Node[0][1]};
  Path.push_back(temp);
}

void Nodes::drawPath(cv::Mat &img) {
  vec_size length = Path.size();
  cv::Point pt1, pt2;
  for (int i = 0; i < length - 1; i++) {
    pt1.x = Path[i][0];
    pt1.y = Path[i][1];
    pt2.x = Path[i+1][0];
    pt2.y = Path[i+1][1];
    cv::line(img, pt1, pt2, cv::Scalar(128), 1, 8, 0);
  }
  map.displayMap(img);
}

void Nodes::showtraversal(cv::Mat &img, int x, int y) {
  vec_size length = Node.size() - 1;
  cv::Point pt1, pt2;
  if (x < 250 && y < 150) {
    pt1.x = x;
    pt1.y = y;
    pt2.x = pt1.x + 1;
    pt2.y = pt1.y + 1;
    cv::line(img, pt1, pt2, cv::Scalar(180), 1, 8, 0);
    map.displayMap(img, 1);
  }  
}

double Nodes::costToGo(int x, int y, std::vector<int> goal) {
  double distance = (double)sqrt((pow(goal[0] - x, 2)) + (pow(goal[1] - y, 2)));
  return distance;    
}

void Nodes::sortQueue() {
  std::sort(pQueue.begin(), pQueue.end(), sortCriteria);
}

