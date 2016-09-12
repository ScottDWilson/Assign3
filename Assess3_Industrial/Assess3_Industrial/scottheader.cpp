#include "scottheader.h"

// Function to perform SURF Feature Detection Processing. Takes minimum Hessian value as input, the input Mat image, and a Mat image to store the output.
// Returns an integer of number of keypoints in the input image. Keypoint locations illustrated on output image
// Example of Use
// surf_key_values = MySurfProcess(400, my_image, my_out_image);
int scottindustrial::MySurfProcess(const int minHessian, const cv::Mat& input, cv::Mat& output) {
  cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHessian);

  std::vector<cv::KeyPoint> keypoints_1, keypoints_2;
  //input.copyTo(output);
  detector->detect(input, keypoints_1);
  cv::Mat img_keypoints_1;
  drawKeypoints(input, keypoints_1, output, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT); //img_keypoints_1

  return  keypoints_1.size();
}

