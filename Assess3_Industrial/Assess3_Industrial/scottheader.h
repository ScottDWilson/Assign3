/*******************************************************
* Copyright (C) 2016 Scott Wilson - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
*
* This file is part of Industrial Systems Assessment 3 - Feature Detection comparison.
*
* Industrial Systems Assessment 3 - Feature Detection comparison can not be copied and/or distributed without the express
* permission of Scott Wilson
* Written by Scott Wilson <scottywilson42@gmail.com>, September 2016
*******************************************************/

#ifndef ASSESS3INDUSTRIAL_ASSESS3INDUSTRIAL_SCOTTHEADER_H_
#define ASSESS3INDUSTRIAL_ASSESS3INDUSTRIAL_SCOTTHEADER_H_

//includes
#include <opencv2/opencv.hpp>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

namespace scottindustrial {

  //@Breif Performs SURF feature detection on an image. Returns vector of number of keypoints [0] and time taken to detect [1]. Also draws keypoints on output Mat object
  //@Param minHessian Hessian value for detecting features. Number of best features to maintain
  //@Param Input source image
  //@Param Output image with key features illustrated
  std::vector<double> MySurfProcess(const int minHessian,const cv::Mat& input, cv::Mat& output);

  //@Breif Performs SIFT feature detection on an image. Returns vector of number of keypoints [0] and time taken to detect [1]. Also draws keypoints on output Mat object
  //@Param minHessian Hessian value for detecting features. Number of best features to maintain
  //@Param Input source image
  //@Param Output image with key features illustrated
  std::vector<double> MySiftProcess(const int minHessian, const cv::Mat& input, cv::Mat& output);

  //@Breif Performs ORB feature detection on an image. Returns vector of number of keypoints [0] and time taken to detect [1]. Also draws keypoints on output Mat object
  //@Param minHessian Hessian value for detecting features. Number of best features to maintain
  //@Param Input source image
  //@Param Output image with key features illustrated
  std::vector<double> MyOrbProcess(const int minHessian, const cv::Mat& input, cv::Mat& output);

  //@Brief Prints Feature Detection results (number of features detected and time taken) to command line
  //@Param input_vector Vector of type double containing number of features detected and time taken from processing function
  //@Param detector_type String containing name of feature detector used
  void printFeatureResult(const std::vector<double> input_vector, const char* detector_type);
} //namespace scottindustrial

#endif //ASSESS3INDUSTRIAL_ASSESS3INDUSTRIAL_SCOTTHEADER_H_
