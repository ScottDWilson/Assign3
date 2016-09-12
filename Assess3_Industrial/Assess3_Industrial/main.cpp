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
  char surf_type[5] = "SURF";
  char sift_type[5] = "SIFT";
  char orb_type[5] = "ORB";

	cv::Mat my_image;

	my_image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

	if (!my_image.cv::Mat::data)                              // Check for invalid input
	{
		std::cout << "Image could not be found" << std::endl;
		return -1;
	}
  cv::Mat out_surf_im = my_image.cv::Mat::clone();
  cv::Mat out_sift_im = my_image.cv::Mat::clone();
  cv::Mat out_orb_im = my_image.cv::Mat::clone();

  int Hessian = 400;

  std::vector<double> surf_output(2);
  surf_output = scottindustrial::MySurfProcess(Hessian, my_image, out_surf_im);
  scottindustrial::printFeatureResult(surf_output, surf_type);
  cv::imshow("SURF Features", out_surf_im);

  std::vector<double> sift_output(2);
  sift_output = scottindustrial::MySiftProcess(Hessian, my_image, out_sift_im);
  scottindustrial::printFeatureResult(sift_output, sift_type);
  cv::imshow("SIFT Features", out_sift_im);

  std::vector<double> orb_output(2);
  orb_output = scottindustrial::MyOrbProcess(Hessian, my_image, out_orb_im);
  scottindustrial::printFeatureResult(orb_output, orb_type);
  cv::imshow("ORB Features", out_orb_im);

	cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);  // Create a window for display.
	cv::imshow("Original Image", my_image);                 // Show our image inside it.

	cv::waitKey(0);                                      // Wait for a keystroke in the window
	return 0;
}
