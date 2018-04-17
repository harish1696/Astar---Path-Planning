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