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
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Map.hpp"

using namespace cv;

Map::Map() {	
  for (int i = 0; i < 150; i++) {
    std::vector<int > temp;
    for (int j = 0; j < 250; j++) {
      temp.push_back(0);   	
    }
    cSpace.push_back(temp);
  }
  x1 = {120,158, 168, 145, 120};
  y1 = {55, 51, 14, 14, 55};
  x2 = {158, 165, 188, 168, 158};
  y2 = {51, 89, 51, 14, 51};
  findMnC();
}

Map::~Map() {}

void Map::createMap(cv::Mat &map1) {
  for (int x = 0; x < 250; x++) {
    for (int y = 0; y < 150; y++) {
      if (x > 55 && x < 105 && y < 113 && y > 67) {
        cSpace[y][x] = 1;          
      }
      if (pow(x-180, 2) + pow(y-120, 2) - pow(15, 2) < 0) {
        cSpace[y][x] = 1;   
      }
      if (y - m1[0]*x - c1[0] < 0 && y - m1[1]*x - c1[1] < 0 &&
      	  y - m1[2]*x - c1[2] > 0 && y - m1[3]*x - c1[3] > 0) {
      	cSpace[y][x] = 1;
      }
      if (y - m2[0]*x - c2[0] < 0 && y - m2[1]*x - c2[1] < 0 &&
      	  y - m2[2]*x - c2[2] > 0 && y - m2[3]*x - c2[3] > 0) {
      	cSpace[y][x] = 1;
      }  
    }
  }
  for (int row = 0; row < map1.rows; row++) {
    for (int col = 0; col < map1.cols; col++) {
      if(cSpace[row][col] == 1)
        map1.at<uchar>(row,col) = 0;
      else
        map1.at<uchar>(row,col) = 255;
    }
  }   
}

bool Map::isObstacle(int x, int y) {
    if (cSpace[y][x] == 1)
      return false;
    else
      return true;  	
}

void Map::findMnC() {
   for(int i = 0; i < 4; i++) {
     float slope1 = (float)(y1[i] - y1[i+1]) / (x1[i] - x1[i+1]);
     float slope2 = (float)(y2[i] - y2[i+1]) / (x2[i] - x2[i+1]);
     m1.push_back(slope1); 
     m2.push_back(slope2);
     float constant1 = (float)((y1[i] - m1[i]*x1[i]));
     float constant2 = (float)((y2[i] - m2[i]*x2[i]));  
     c1.push_back(constant1);
     c2.push_back(constant2);
   }
}

void Map::displayMap(cv::Mat &map1, int key) {
    cv::Mat dst = cv::Mat(map1.rows, map1.cols, CV_8UC1);
    cv::flip(map1, dst, 0);
    namedWindow("Display window",WINDOW_NORMAL);
    imshow( "Display window", dst);
    waitKey(key);
}