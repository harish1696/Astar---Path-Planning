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
    bool moveUp(int x, int y);
    bool moveDown(int x, int y);
    bool moveRight(int x, int y);
    bool moveLeft(int x, int y);
    bool moveUpLeft(int x, int y);
    bool moveUpRight(int x, int y);
    bool moveDownLeft(int x, int y);
    bool moveDownRight(int x, int y);
    void addNode(int x, int y, int parent, double cost);
    void addNode(int x, int y, int parent, double cost, double heuristic);
    int isNew(int x, int y);
    int findIndex(int New);
    void optPath();
    void drawPath(cv::Mat &img);
    void showtraversal(cv::Mat &img, int x, int y);
    double costToGo(int x, int y, std::vector<int> goal);
    void sortQueue();

    Map map;
	std::vector<std::vector<int>> Node;
    std::vector<std::vector<double>> pQueue;
	std::vector<std::vector<double>> NodeInfo;
    std::vector<std::vector<int>> Path;
   private:
    int nodeNumber;
};