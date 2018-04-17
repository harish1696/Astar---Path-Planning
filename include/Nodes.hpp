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


#pragma once

#include <iostream>
#include <vector>
#include "Map.hpp"

typedef std::vector<int>::size_type vec_size;

class Nodes {
  public:    
	Nodes();
    explicit Nodes(cv::Mat &img, int x, int y);
	~Nodes();
    bool action1(double x, double y, double theta);
    bool action2(double x, double y, double theta);
    bool action3(double x, double y, double theta);
    bool action4(double x, double y, double theta);
    bool action5(double x, double y, double theta);
    bool action6(double x, double y, double theta);
    bool action7(double x, double y, double theta);
    bool action8(double x, double y, double theta);
    std::vector<double> getxytheta();
    void addNode(int x, int y, int vl, int vr, double angle, int parent, double cost, double heuristic);
    int isNew(int x, int y, double angle);
    int findIndex(int New);
    void optPath();
    void drawPath(cv::Mat &img);
    double costToGo(double x, double y, std::vector<int> goal);
    double costToCome(std::vector<double> pos, double x, double y);
    void sortQueue();
    void storeVelocity();

    Map map;
	std::vector<std::vector<double>> Node;
    std::vector<std::vector<double>> pQueue;
	std::vector<std::vector<double>> NodeInfo;
    std::vector<std::vector<int>> Path;
    std::vector<std::vector<int>> pathVelocity;
   private:
    int nodeNumber, freq;
    double r, L, dist2pixel, curr_theta, curr_x, curr_y;
};