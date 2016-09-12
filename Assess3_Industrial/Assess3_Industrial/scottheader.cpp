//license boilerplate

#include "scottheader.h"
#include <ctime>

// Function to perform SURF Feature Detection Processing. Takes minimum Hessian value as input, the input Mat image, and a Mat image to store the output.
// Returns an integer of number of keypoints in the input image. Keypoint locations illustrated on output image
// Example of Use
// surf_key_values = MySurfProcess(400, my_image, my_out_image);
std::vector<double> scottindustrial::MySurfProcess(const int minHessian, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHessian);
  double time1, time2, time_taken = 0;
  std::vector<double> output_vector(2);
  std::vector<cv::KeyPoint> keypoints;

  //Calculating the time taken for the detect function to run
  time1 = (double)cv::getTickCount();
  detector->detect(input, keypoints);
  time2 = (double)cv::getTickCount();
  time_taken = (time2 - time1) / cv::getTickFrequency();

  drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT); //img_keypoints_1
  
  int number_keypoints = keypoints.size();
  output_vector[0] = number_keypoints;
  output_vector[1] = time_taken;
  return  output_vector;
}

std::vector<double> scottindustrial::MySiftProcess(const int minHessian, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SIFT> detector = cv::xfeatures2d::SIFT::create(minHessian); //int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma);
  double time1, time2, time_taken = 0;
  std::vector<double> output_vector(2);
  std::vector<cv::KeyPoint> keypoints;
  double frequency = cv::getTickFrequency();

  //Calculating the time taken for the detect function to run
  time1 = (double)cv::getTickCount();
  detector->detect(input, keypoints);
  time2 = (double)cv::getTickCount();
  time_taken = (time2 - time1) / (cv::getTickFrequency());

  drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
  
  int number_keypoints = keypoints.size();
  output_vector[0] = number_keypoints;
  output_vector[1] = time_taken;
  return  output_vector;
}

std::vector<double> scottindustrial::MyOrbProcess(const int minHessian, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::ORB> detector = cv::ORB::create(minHessian); //int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma);
  double time1, time2, time_taken = 0;
  std::vector<double> output_vector(2);
  std::vector<cv::KeyPoint> keypoints;
  double frequency = cv::getTickFrequency();

  //Calculating the time taken for the detect function to run
  time1 = (double)cv::getTickCount();
  detector->detect(input, keypoints);
  time2 = (double)cv::getTickCount();
  time_taken = (time2 - time1) / (cv::getTickFrequency());

  drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);

  int number_keypoints = keypoints.size();
  output_vector[0] = number_keypoints;
  output_vector[1] = time_taken;
  return  output_vector;
}

void scottindustrial::printFeatureResult(const std::vector<double> input_vector, const char* detector_type) {
  std::cout << detector_type << " Feature Detection" << std::endl;
  std::cout << "Features Detected: " << input_vector[0] << std::endl;
  std::cout << "Time Taken: " << input_vector[1] << std::endl;
}