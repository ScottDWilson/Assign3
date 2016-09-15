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

/*******************************************************
* This file contains the function definitions for
* scottindustrial::mySurfProcess()
* scottindustrial::mySiftProcess()
* scottindustrial::myOrbProcess()
* scottindustrial::printFeatureResult()
*******************************************************/

#include "scottheader.h"

// Function to perform SURF Feature Detection Processing. Takes minimum Hessian value as input (minimum number of features), the input Mat image, and a Mat image to store the output.
// Returns an integer of number of keypoints in the input image. Keypoint locations are illustrated on output image
// Example of Use
// surf_key_values = MySurfProcess(400, my_image, my_out_image);
std::vector<double> scottindustrial::mySurfProcess(const int min_features, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(min_features);
  double time1, time2, time_taken = 0;
  std::vector<double> output_vector(2);
  std::vector<cv::KeyPoint> keypoints;

  //Calculating the time taken for the detect function to run
  time1 = (double)cv::getTickCount();
  detector->cv::Feature2D::detect(input, keypoints);
  time2 = (double)cv::getTickCount();
  time_taken = (time2 - time1) / cv::getTickFrequency();

  //Marks location of keypoints on output Mat object with circles. 
  cv::drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT); //img_keypoints_1
  
  int number_keypoints = keypoints.size();
  output_vector[0] = number_keypoints;
  output_vector[1] = time_taken;
  return  output_vector;
}

// Function to perform SIFT Feature Detection Processing. Takes minimum Hessian value as input (minimum number of features), the input Mat image, and a Mat image to store the output.
// Returns an integer of number of keypoints in the input image. Keypoint locations are illustrated on output image
// Example of Use
// sift_key_values = MySiftProcess(400, my_image, my_out_image);
std::vector<double> scottindustrial::mySiftProcess(const int min_features, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SIFT> detector = cv::xfeatures2d::SIFT::create(min_features); //int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma);
  double time1, time2, time_taken = 0;
  std::vector<double> output_vector(2);
  std::vector<cv::KeyPoint> keypoints;
  double frequency = cv::getTickFrequency();

  //Calculating the time taken for the detect function to run
  time1 = (double)cv::getTickCount();
  detector->cv::Feature2D::detect(input, keypoints);
  time2 = (double)cv::getTickCount();
  time_taken = (time2 - time1) / (cv::getTickFrequency());

  cv::drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
  
  int number_keypoints = keypoints.size();
  output_vector[0] = number_keypoints;
  output_vector[1] = time_taken;
  return  output_vector;
}

// Function to perform ORB Feature Detection Processing. Takes minimum Hessian value as input (minimum number of features), the input Mat image, and a Mat image to store the output.
// Returns an integer of number of keypoints in the input image. Keypoint locations are illustrated on output image
// Example of Use
// orb_key_values = MyOrbProcess(400, my_image, my_out_image);
std::vector<double> scottindustrial::myOrbProcess(const int min_features, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::ORB> detector = cv::ORB::create(min_features); //int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma);
  double time1, time2, time_taken = 0;
  std::vector<double> output_vector(2);
  std::vector<cv::KeyPoint> keypoints;
  double frequency = cv::getTickFrequency();

  //Calculating the time taken for the detect function to run
  time1 = (double)cv::getTickCount();
  detector->cv::Feature2D::detect(input, keypoints);
  time2 = (double)cv::getTickCount();
  time_taken = (time2 - time1) / (cv::getTickFrequency());

  cv::drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);

  int number_keypoints = keypoints.size();
  output_vector[0] = number_keypoints;
  output_vector[1] = time_taken;
  return  output_vector;
}

// Function to display feature detection performance results. 
// Displays the type of feature detection used, the number of features detected, and the time taken for the feature detection
// Example of Use
// scottindustrial::printFeatureResult(vector containing performance results, type of feature detection);
void scottindustrial::printFeatureResult(const std::vector<double> performance_vector, const char* detector_type) {
  std::cout << detector_type << " Feature Detection" << std::endl;
  std::cout << "Features Detected: " << performance_vector[0] << std::endl;
  std::cout << "Time Taken: " << performance_vector[1] << std::endl;
}