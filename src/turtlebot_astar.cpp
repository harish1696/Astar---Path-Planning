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
  Mat map1 = imread("../2dmap/turtlebot_cmap.png", CV_LOAD_IMAGE_GRAYSCALE);
  int x, y, parent, prev;
  double theta = 0;
  std::vector<int> start = {200, 100};
  std::vector<int> goal = {200, 500};
  x = start[0];
  y = start[1];
  Nodes nodes(map1, x, y);
  std::cout << "Start: (" << x << ", " << y << ")" << std::endl;
  std::cout << "Goal: (" << goal[0] << ", " << goal[1] << ")" << std::endl;
  parent = 0;
  bool success;
  bool flag = false;
  clock_t t1, t2;
  t1 = clock();
  while(!flag) {
    // action 1 - v_left = 5mps and v_right = 5mps
    success = nodes.action1(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);
      if (New == 0) {
        nodes.addNode(round(pos[0]), round(pos[1]), 5, 5, pos[2], parent, cost, heuristic);
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
    // action 2 - v_left = 10mps and v_right = 10mps
    success = nodes.action2(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);;
      if (New == 0) {  
        nodes.addNode(round(pos[0]), round(pos[1]), 10, 10, pos[2], parent, cost, heuristic);
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
    // action 3 - v_left = 10mps and v_right = 0mps
    success = nodes.action3(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);;
      if (New == 0) {
        nodes.addNode(round(pos[0]), round(pos[1]), 10, 0, pos[2], parent, cost, heuristic);
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
    // action 4 - v_left = 0mps and v_right = 10mps
    success = nodes.action4(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);;
      if (New == 0) { 
        nodes.addNode(round(pos[0]), round(pos[1]), 0, 10, pos[2], parent, cost, heuristic);
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
    // action 5 - v_left = 10mps and v_right = 5mps
    success = nodes.action5(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);;
      if (New == 0) { 
        nodes.addNode(round(pos[0]), round(pos[1]), 10, 5, pos[2], parent, cost, heuristic);
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
    // action 6 - v_left = 5mps and v_right = 10mps
    success = nodes.action6(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);;
      if (New == 0) {  
        nodes.addNode(round(pos[0]), round(pos[1]), 5, 10, pos[2], parent, cost, heuristic);
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
    // action 3 - v_left = 5mps and v_right = 0mps
    success = nodes.action7(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);;
      if (New == 0) {  
        nodes.addNode(round(pos[0]), round(pos[1]), 5, 0, pos[2], parent, cost, heuristic);
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
    // action 3 - v_left = 0mps and v_right = 5mps
    success = nodes.action8(x, y, theta);
    if (success) {
      std::vector<double> pos = nodes.getxytheta();
      int New = nodes.isNew(round(pos[0]), round(pos[1]), pos[2]);
      double heuristic = nodes.costToGo(pos[0], pos[1], goal);
      double cost = nodes.NodeInfo[parent][2] + nodes.costToCome(pos, x, y);;
      if (New == 0) {
        nodes.addNode(round(pos[0]), round(pos[1]), 0, 5, pos[2], parent, cost, heuristic);
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
    // deleting the current from priority queue
    nodes.pQueue.erase(nodes.pQueue.begin());
    // sorting the priority queue to choose the next action
    nodes.sortQueue();
    parent = nodes.pQueue[0][0];
    if (nodes.Node[parent][0] == goal[0] && nodes.Node[parent][1] == goal[1]) flag = true;
    x = nodes.Node[parent][0];
    y = nodes.Node[parent][1];
    theta = nodes.Node[parent][2];
  }
  nodes.optPath();
  nodes.storeVelocity();
  t2 = clock();
  float diff = float(t2) - float(t1);
  float seconds = diff / CLOCKS_PER_SEC;
  std::cout << seconds << std::endl;
  nodes.drawPath(map1);
  return 0;
}