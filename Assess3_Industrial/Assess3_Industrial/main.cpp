//license boilerplate

#include "scottheader.h"

#include <opencv2/opencv.hpp>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
	  std::cout << " Error in input: Please load an Image" << std::endl;
	  return -1;
	}

	cv::Mat my_image;
  cv::Mat out_im;
	my_image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

	if (!my_image.cv::Mat::data)                              // Check for invalid input
	{
		std::cout << "Image could not be found" << std::endl;
		return -1;
	}
  my_image.cv::Mat::copyTo(out_im);

  int Hessian = 400;
  int surf_number_keyPoints = 0;

  surf_number_keyPoints = scottindustrial::MySurfProcess(Hessian, my_image, out_im);

  std::cout << surf_number_keyPoints << std::endl;

  cv::imshow("Features", out_im);

	cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);  // Create a window for display.
	cv::imshow("Original Image", my_image);                 // Show our image inside it.

	cv::waitKey(0);                                      // Wait for a keystroke in the window
	return 0;
}



//#include <stdio.h>
//#include <iostream>
//#include "opencv2/core.hpp"
//#include "opencv2/features2d.hpp"
//#include "opencv2/xfeatures2d.hpp"
//#include "opencv2/highgui.hpp"
//
//using namespace cv;
//using namespace cv::xfeatures2d;
//
//void readme();
//
///** @function main */
//int main(int argc, char** argv)
//{
//  if (argc != 3)
//  {
//    readme(); return -1;
//  }
//
//  Mat img_1 = imread(argv[1], IMREAD_GRAYSCALE);
//  Mat img_2 = imread(argv[2], IMREAD_GRAYSCALE);
//
//  if (!img_1.data || !img_2.data)
//  {
//    std::cout << " --(!) Error reading images " << std::endl; return -1;
//  }
//
//  //-- Step 1: Detect the keypoints using SURF Detector
//  int minHessian = 400;
//
//  Ptr<SURF> detector = SURF::create(minHessian);
//
//  std::vector<KeyPoint> keypoints_1, keypoints_2;
//
//  detector->detect(img_1, keypoints_1);
//  detector->detect(img_2, keypoints_2);
//
//  //-- Draw keypoints
//  Mat img_keypoints_1; Mat img_keypoints_2;
//
//  drawKeypoints(img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
//  drawKeypoints(img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
//
//  //-- Show detected (drawn) keypoints
//  imshow("Keypoints 1", img_keypoints_1);
//  imshow("Keypoints 2", img_keypoints_2);
//
//  waitKey(0);
//
//  return 0;
//}
//
///** @function readme */
//void readme()
//{
//  std::cout << " Usage: ./SURF_detector <img1> <img2>" << std::endl;
//}
