#pragma once

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Map {
public:	
	Map();
	~Map();
	void createMap(cv::Mat &map1);
	bool isObstacle(int x, int y, int x_new, int y_new);
	void displayMap(cv::Mat &map1, int key = 0);	

private:
	std::vector<std::vector<int> > cSpace;
    std::vector<int>  x1, y1, x2, y2;
    std::vector<float> m1, m2, c1, c2;
};