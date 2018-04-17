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
  Node.push_back({x, y, 0, 0, 0});
  NodeInfo.push_back({0, 0, 0});
  pQueue.push_back({0, 0, 0});
  nodeNumber = 1;
  freq = 2;
  r = 0.038;
  L = 0.354;
  dist2pixel = 0.017;
  curr_x = 0;
  curr_y = 0;
  curr_theta = 0;
}

Nodes::~Nodes() {}

bool Nodes::action1(double x, double y, double theta) {
  int vl = 5;
  int vr = 5;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false;
}

bool Nodes::action2(double x, double y, double theta) {
  int vl = 10;
  int vr = 10;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false;
}

bool Nodes::action3(double x, double y, double theta) {
  int vl = 10;
  int vr = 0;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false;
}

bool Nodes::action4(double x, double y, double theta) {
  int vl = 0;
  int vr = 10;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false;
}

bool Nodes::action5(double x, double y, double theta) {
  int vl = 10;
  int vr = 5;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false;
}

bool Nodes::action6(double x, double y, double theta) {
  int vl = 5;
  int vr = 10;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false;
}

bool Nodes::action7(double x, double y, double theta) {
  int vl = 5;
  int vr = 0;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false; 
}

bool Nodes::action8(double x, double y, double theta) {
  int vl = 0;
  int vr = 5;
  double vel_mps = ((vl + vr) / 2) * r;
  curr_theta = theta + ((vr - vl) / L) * r; 
  curr_x = x + (double)(vel_mps / (freq * dist2pixel)) * sin(theta);  
  curr_y = y + (double)(vel_mps / (freq * dist2pixel)) * cos(theta);
  bool poss;
  if (x >= 0 && y >= 0 && x < 584 && y < 637)
  	return poss = map.isObstacle(round(x), round(y), round(curr_x), round(curr_y));
  else
  	return poss = false;
}

std::vector<double> Nodes::getxytheta() {
  return {curr_x, curr_y, curr_theta};
}

void Nodes::addNode(int x, int y, int vl, int vr, double angle, int parent, double cost, double heuristic) {
  std::vector<double> temp1 = {(double)(x), (double)(y)};
  std::vector<double> temp2 = {(double)nodeNumber, (double)parent, cost};
  Node.push_back({(double)(x), (double)(y), angle, vl, vr});
  NodeInfo.push_back({(double)nodeNumber, (double)parent, cost});
  pQueue.push_back({(double)nodeNumber, (double)parent, cost + heuristic});
  nodeNumber += 1;
}

int Nodes::isNew(int x, int y, double angle) {
  vec_size length = Node.size();
  for (int i = 0; i < length; i++) {
  	if(Node[i][0] == x && Node[i][1] == y && Node[i][2] == angle) {
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
  int node = pQueue[0][0];
  while(node > 0) {
    Path.push_back({Node[node][0], Node[node][1]});
    pathVelocity.push_back({Node[node][3], Node[node][4]});
    node = NodeInfo[node][1];  
  }
  Path.push_back({Node[0][0], Node[0][1]});
  pathVelocity.push_back({Node[0][3], Node[0][4]});
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

void Nodes::storeVelocity() {
  vec_size length = pathVelocity.size();
  std::ofstream output;
  output.open("PathVelocity.csv");
  for (int i = length - 1; i >= 0; i--) {
    std::cout << pathVelocity[i][0] << " " << pathVelocity[i][1] << std::endl;
    output << pathVelocity[i][0] << "," << pathVelocity[i][1] << std::endl;
  }
}

double Nodes::costToGo(double x, double y, std::vector<int> goal) {
  double distance = (double)sqrt((pow(goal[0] - x, 2)) + (pow(goal[1] - y, 2)));
  return distance;    
}

double Nodes::costToCome(std::vector<double> pos, double x, double y) {
  double distance = (double)sqrt((pow(pos[0] - x, 2)) + (pow(pos[1] - y, 2)));
  return distance;
}

void Nodes::sortQueue() {
  std::sort(pQueue.begin(), pQueue.end(), sortCriteria);
}
