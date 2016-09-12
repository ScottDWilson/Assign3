//license boilerplate

#ifndef ASSESS3INDUSTRIAL_ASSESS3INDUSTRIAL_SCOTTHEADER_H_
#define ASSESS3INDUSTRIAL_ASSESS3INDUSTRIAL_SCOTTHEADER_H_

//includes
#include <opencv2/opencv.hpp>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace scottindustrial {

  //Function Prototype
  int MySurfProcess(const int minHessian,const cv::Mat& input, cv::Mat& output);

} //namespace scottindustrial

#endif //ASSESS3INDUSTRIAL_ASSESS3INDUSTRIAL_SCOTTHEADER_H_
