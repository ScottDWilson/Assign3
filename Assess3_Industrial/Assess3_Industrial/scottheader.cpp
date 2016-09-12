#include "scottheader.h"

void scottindustrial::MySurfProcess(const int minHessian, cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHessian);

  std::vector<cv::KeyPoint> keypoints_1, keypoints_2;
  //input.copyTo(output);
  detector->detect(input, keypoints_1);
  cv::Mat img_keypoints_1;
  drawKeypoints(input, keypoints_1, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT); //img_keypoints_1

 // return  keypoints_1.size();
}

