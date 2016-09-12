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

  //SURF Processing Function. Returns integer of number of keypoints 
  int MySurfProcess(const int minHessian,const cv::Mat& input, cv::Mat& output);

  //@Breif Performs SIFT feature detection on an image. Returns integer of number of keypoints and draw keypoints on output Mat object
  //@Param minHessian Hessian value for detecting features. Number of best features to maintain
  //@Param Input source image
  //@Param Output image with key features illustrated
  int MySiftProcess(const int minHessian, const cv::Mat& input, cv::Mat& output);

} //namespace scottindustrial

#endif //ASSESS3INDUSTRIAL_ASSESS3INDUSTRIAL_SCOTTHEADER_H_
