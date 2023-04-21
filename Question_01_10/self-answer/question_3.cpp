#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

cv::Mat grayscale(cv::Mat img) {
  int width = img.cols;
  int height = img.rows;

	cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			out.at<uchar>(y, x) = 0.2126 * (float)img.at<cv::Vec3b>(y, x)[2] \
				+ 0.7152 * (float)img.at<cv::Vec3b>(y, x)[1] \
			  + 0.0722 * (float)img.at<cv::Vec3b>(y, x)[0];
		}
	}

	return out;
}

cv::Mat Binarize(cv::Mat gray, int th) {
	int width = gray.cols;
	int height = gray.rows;

	cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < height; x++) {
			if (gray.at<uchar>(y, x) > th) {
				out.at<uchar>(y, x) = 255;
			} else {
				out.at<uchar>(y, x) = 0;
			}
		}
	}

	return out;
}

int main(int argc, const char* argv[]) {
	cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

	cv::Mat gray = grayscale(img);
	cv::Mat out = Binarize(gray, 128);

  cv::imshow("sample", out);
  cv::waitKey(0);
  cv::destroyAllWindows();

	return 0;
}
