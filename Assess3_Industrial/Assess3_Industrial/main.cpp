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
  // Error check to ensure executable is run properly. 
  // Error is displayed if no image is loaded when program run
	if (argc != 2)
	{
	  std::cout << " Error in input: Please load an Image" << std::endl;
	  return -1;
	}
  // String variables to pass into 
  char surf_type[5] = "SURF";
  char sift_type[5] = "SIFT";
  char orb_type[5] = "ORB";

  // Variable to load image as Color Mat Object
	cv::Mat my_image;
	my_image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

  // Error displayed if the loaded image could not be found
	if (!my_image.cv::Mat::data)                              // Check for invalid input
	{
		std::cout << "Image could not be found" << std::endl;
		return -1;
	}
  // Creation of Mat Object Variables to store output feature detected images
  cv::Mat out_surf_im = my_image.cv::Mat::clone();
  cv::Mat out_sift_im = my_image.cv::Mat::clone();
  cv::Mat out_orb_im = my_image.cv::Mat::clone();

  // Creation of variable for minimum number of features to be detected
  int Hessian = 400;

  // Calculation of SURF Feature Detection performance
  std::vector<double> surf_output(2);  // Creation of vector to store feature detection performance results; number of features detected (1) and time taken (2)
  surf_output = scottindustrial::MySurfProcess(Hessian, my_image, out_surf_im);  // Perform SURF feature detection of loaded image. Returns the number of features detected and time taken. 
  scottindustrial::printFeatureResult(surf_output, surf_type);  //Display results from SURF feature detection. Display shows Type of Feature Detection, Number of features detected, and Time taken to detect features. 
  cv::imshow("SURF Features", out_surf_im);

  // Calculation of SIFT Feature Detection performance
  std::vector<double> sift_output(2);  // Creation of vector to store feature detection performance results; number of features detected (1) and time taken (2)
  sift_output = scottindustrial::MySiftProcess(Hessian, my_image, out_sift_im);
  scottindustrial::printFeatureResult(sift_output, sift_type);  //Display results from SIFT feature detection. Display shows Type of Feature Detection, Number of features detected, and Time taken to detect features. 
  cv::imshow("SIFT Features", out_sift_im);

  // Calculation of ORB Feature Detection performance
  std::vector<double> orb_output(2);  // Creation of vector to store feature detection performance results; number of features detected (1) and time taken (2)
  orb_output = scottindustrial::MyOrbProcess(Hessian, my_image, out_orb_im);
  scottindustrial::printFeatureResult(orb_output, orb_type);  //Display results from ORB feature detection. Display shows Type of Feature Detection, Number of features detected, and Time taken to detect features. 
  cv::imshow("ORB Features", out_orb_im);

  // Display original image for comparison
	cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);  // Create a window for display.
	cv::imshow("Original Image", my_image);                 // Show our image inside it.

	cv::waitKey(0);                                      // Wait for a keystroke in the window
	return 0;
}
