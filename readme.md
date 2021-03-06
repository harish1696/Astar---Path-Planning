# A* Path Planning

## Overview
The module is capable of finding a path between two given points in a given 2d map using Astar algorithm. The 2d map is obtained by getting a gmap from the given rrlab.sdf file and then converting that to an .png file. The .png file is processed using OpenCv to obtain a C-Space map with 1's as obstacles and 0's as free space. Also, the known radius of the bot is used to pad 1's to the obstacles so that the robot can be considered a point robot. 

## Installing Dependencies
```
sudo apt-get install build-essential checkinstall cmake pkg-config yasm gfortran git
sudo apt-get install libjpeg8-dev libjasper-dev libpng12-dev
# If you are using Ubuntu 14.04
sudo apt-get install libtiff4-dev
# If you are using Ubuntu 16.04
sudo apt-get install libtiff5-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev
sudo apt-get install libxine2-dev libv4l-dev
sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
sudo apt-get install libqt4-dev libgtk2.0-dev libtbb-dev
sudo apt-get install libatlas-base-dev
sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev
sudo apt-get install libvorbis-dev libxvidcore-dev
sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev
sudo apt-get install x264 v4l-utils
```
Download and Compile OpenCV
```
git clone https://github.com/opencv/opencv.git
cd opencv 
git checkout 3.3.0 
cd ..
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 3.3.0
cd ..
cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D INSTALL_C_EXAMPLES=ON \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D WITH_QT=ON \
      -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      -D BUILD_EXAMPLES=ON ..
# find out number of CPU cores in your machine
nproc
# substitute 4 by output of nproc
make -j4
sudo make install
sudo sh -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
```

## How to build
```
git clone --recursive https://github.com/harish1696/Astar---Path-Planning
cd <path to repository>
mkdir build
cd build
cmake ..
make
```

## How to run demo
```
cd <path to repository>
cd build
./getPath
```

## Known Issues
The path planner is sometimes unable to find a path between 2 given points since the actions chosen move greater than 1 pixel in both x and y direction. But this can be solved by increasing the frequency which reduces the step size/resolution making it easier for it to find the path.