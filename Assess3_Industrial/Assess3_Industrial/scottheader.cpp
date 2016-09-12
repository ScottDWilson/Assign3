#include "scottheader.h"

// Function to perform SURF Feature Detection Processing. Takes minimum Hessian value as input, the input Mat image, and a Mat image to store the output.
// Returns an integer of number of keypoints in the input image. Keypoint locations illustrated on output image
// Example of Use
// surf_key_values = MySurfProcess(400, my_image, my_out_image);
int scottindustrial::MySurfProcess(const int minHessian, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHessian);

  std::vector<cv::KeyPoint> keypoints;
  //input.copyTo(output);
  detector->detect(input, keypoints);
  cv::Mat img_keypoints_1;
  drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT); //img_keypoints_1

  return  keypoints.size();
}

int scottindustrial::MySiftProcess(const int minHessian, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SIFT> detector = cv::xfeatures2d::SIFT::create(minHessian); //int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma);
  std::vector<cv::KeyPoint> keypoints;
  detector->detect(input, keypoints);
  drawKeypoints(input, keypoints, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
  return keypoints.size();
}