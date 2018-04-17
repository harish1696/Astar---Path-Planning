#include <iostream>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Map.hpp"

using namespace cv;

Map::Map() {	
  for (int i = 0; i < 637; i++) {
    std::vector<int > temp;
    for (int j = 0; j < 584; j++) {
      temp.push_back(0);   	
    }
    cSpace.push_back(temp);
  }
}

Map::~Map() {}

void Map::createMap(cv::Mat &map1) {
  cv::Mat dst = cv::Mat(map1.rows, map1.cols, CV_8UC1);
  cv::flip(map1, dst, 0);
  map1 = dst;
  for (int row = 0; row < map1.rows; row++) {
    for (int col = 0; col < map1.cols; col++) {
      if(map1.at<uchar>(row, col) == 0)
        cSpace[row][col] = 1;
      else
        cSpace[row][col] = 0;
    }
  }   
}

bool Map::isObstacle(int x, int y, int x_new, int y_new) {
  bool positive_x = (x < x_new) ? true : false;
  bool positive_y = (y < y_new) ? true : false;
  if (positive_x && positive_y) {
    for (int j = 0; j < y_new - y; j++) {
      for (int i = 0; i < x_new - x; i++) { 
        if (cSpace[y + j][x + i] == 1)
          return false;
      }
    }
  }
  if (positive_x && !positive_y) {
    for (int j = 0; j < y - y_new; j++) {
      for (int i = 0; i < x_new - x; i++) { 
        if (cSpace[y - j][x + i] == 1)
          return false;
      }
    }
  } 
  if (!positive_x && positive_y) {
    for (int j = 0; j < y_new - y; j++) {
      for (int i = 0; i < x - x_new; i++) { 
        if (cSpace[y + j][x - i] == 1)
          return false;
      }
    }
  }
  if (!positive_x && positive_y) {
    for (int j = 0; j < y - y_new; j++) {
      for (int i = 0; i < x - x_new; i++) { 
        if (cSpace[y - j][x - i] == 1)
          return false;
      }
    }
  }
  return true;         	
}

void Map::displayMap(cv::Mat &map1, int key) {
    cv::Mat dst = cv::Mat(map1.rows, map1.cols, CV_8UC1);
    cv::flip(map1, dst, 0);
    namedWindow("Display window",WINDOW_NORMAL);
    imshow( "Display window", dst);
    waitKey(key);
}