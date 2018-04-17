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
#include <ctime>
#include <limits>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Map.hpp"
#include "Nodes.hpp"

using namespace cv;

int main(int argc, const char**argv) {
  Mat map1(150, 250, CV_8UC1, cv::Scalar(255));
  int x, y, parent, prev;
  std::vector<int> start = {4, 4};
  std::vector<int> goal = {200, 140};
  x = start[0];
  y = start[1];
  Nodes nodes(map1, x, y);
  std::cout << "Start: (" << x << ", " << y << ")" << std::endl;
  std::cout << "Goal: (" << goal[0] << ", " << goal[1] << ")" << std::endl;
  parent = 0;
  bool success;
  bool flag = false;
  double d = (double)sqrt(2);
  clock_t t1, t2;
  t1 = clock();
  while(!flag) {
    success = nodes.moveUp(x, y);
    if (success) {	
      int New = nodes.isNew(x, y + 1);
      double heuristic = nodes.costToGo(x, y + 1, goal);
      double cost = nodes.NodeInfo[parent][2] + 1;
      if (New == 0) {
        nodes.addNode(x, y + 1, parent, cost);
        nodes.addNode(x, y + 1, parent, cost, heuristic);
      } else { 
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }
    }
    success = nodes.moveRight(x, y);
    if (success) {	
      int New = nodes.isNew(x + 1, y);
      double heuristic = nodes.costToGo(x + 1, y, goal);
      double cost = nodes.NodeInfo[parent][2] + 1;
      if (New == 0) {  
        nodes.addNode(x + 1, y, parent, cost);
        nodes.addNode(x + 1, y, parent, cost, heuristic);
      } else {
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }    
    }
    success = nodes.moveDown(x, y);
    if (success) {
      int New = nodes.isNew(x, y - 1);
      double heuristic = nodes.costToGo(x, y - 1, goal);
      double cost = nodes.NodeInfo[parent][2] + 1;
      if (New == 0) {
        nodes.addNode(x, y - 1, parent, cost);
        nodes.addNode(x, y - 1, parent, cost, heuristic);
      } else {
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }   
    }
    success = nodes.moveLeft(x, y);
    if (success) {
      int New = nodes.isNew(x - 1, y);
      double heuristic = nodes.costToGo(x - 1, y, goal);
      double cost = nodes.NodeInfo[parent][2] + 1;
      if (New == 0) { 
        nodes.addNode(x - 1, y, parent, cost);
        nodes.addNode(x - 1, y, parent, cost, heuristic);
      } else {
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }   
    }
    success = nodes.moveUpLeft(x, y);
    if (success) {
      int New = nodes.isNew(x - 1, y + 1);
      double heuristic = nodes.costToGo(x - 1, y + 1, goal);
      double cost = nodes.NodeInfo[parent][2] + d;
      if (New == 0) { 
        nodes.addNode(x - 1, y + 1, parent, cost);
        nodes.addNode(x - 1, y + 1, parent, cost, heuristic);
      } else {
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }   
    }
    success = nodes.moveUpRight(x, y);
    if (success) {
      int New = nodes.isNew(x + 1, y + 1);
      double heuristic = nodes.costToGo(x + 1, y + 1, goal);
      double cost = nodes.NodeInfo[parent][2] + d;
      if (New == 0) {  
        nodes.addNode(x + 1, y + 1, parent, cost);
        nodes.addNode(x + 1, y + 1, parent, cost, heuristic);
      } else {
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }   
    }
    success = nodes.moveDownRight(x, y);
    if (success) {
      int New = nodes.isNew(x + 1, y - 1);
      double heuristic = nodes.costToGo(x + 1, y - 1, goal);
      double cost = nodes.NodeInfo[parent][2] + d;
      if (New == 0) {  
        nodes.addNode(x + 1, y - 1, parent, cost);
        nodes.addNode(x + 1, y - 1, parent, cost, heuristic);
      } else {
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }   
    }
    success = nodes.moveDownLeft(x, y);
    if (success) {
      int New = nodes.isNew(x - 1, y - 1);
      double heuristic = nodes.costToGo(x - 1, y - 1, goal);
      double cost = nodes.NodeInfo[parent][2] + d;
      if (New == 0) {
        nodes.addNode(x - 1, y - 1, parent, cost);
        nodes.addNode(x - 1, y - 1, parent, cost, heuristic);
      } else {
        int index = nodes.findIndex(New - 1);
        if (index != 0) {
          nodes.NodeInfo[New - 1][1] = (cost < nodes.NodeInfo[New - 1][2]) ? parent : nodes.NodeInfo[New - 1][1];
          nodes.NodeInfo[New - 1][2] = (cost < nodes.NodeInfo[New - 1][2]) ? cost : nodes.NodeInfo[New - 1][2];
          nodes.pQueue[index - 1][1] = nodes.NodeInfo[New - 1][1];
          nodes.pQueue[index - 1][2] = nodes.NodeInfo[New - 1][2] + heuristic;
        }  
      }  
    }
    nodes.pQueue.erase(nodes.pQueue.begin());
    nodes.sortQueue();
    int index = nodes.pQueue[0][0];
    //std::cout << "Next: " << index << std::endl;
    if (nodes.Node[index][0] == goal[0] && nodes.Node[index][1] == goal[1]) flag = true;
    parent = nodes.pQueue[0][0];
    x = nodes.Node[index][0];
    y = nodes.Node[index][1];
    // Uncomment the following line to visulaize each node visited
    //nodes.showtraversal(map1, x, y);
  }
  nodes.optPath();
  t2 = clock();
  float diff = float(t2) - float(t1);
  float seconds = diff / CLOCKS_PER_SEC;
  std::cout << seconds << std::endl;
  nodes.drawPath(map1);
  return 0;
}