#include <opencv2\opencv.hpp>
//include cv library
//Description: open camera, created three camera views, created trackbars

using namespace cv;
using namespace std;

int main() {

	//matrix. image is composed of a matrix
	Mat image, imgHSV, mask;

	//hue,saturation and value
	int hmin = 0, smin = 110, vmin = 13;
	int hmax = 19, smax = 240, vmax = 245;

	//Creates a trackbar
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Value Min", "Trackbars", &vmin, 255);
	createTrackbar("Value Max", "Trackbars", &vmax, 255);


	namedWindow("Display window");
	VideoCapture cap(0);

	//checks if camera is open 
	if (!cap.isOpened()) {
		cout << "cannot open camera";
	}

	//infinite loop used to constantly layer a frame 
	while (true) {

		cap >> image;

		//Camera view
		imshow("Display window", image);

		//function call converts an input image from the BGR color space to the HSV color space
		cvtColor(image, imgHSV, COLOR_BGR2HSV);

		//simple container class representing color values 
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		//function that isolates objects of intrest in image based on color
		inRange(imgHSV, lower, upper, mask);

		//Camera view with HSV
		imshow("HSV Image", imgHSV);

		//Camera view that include filters to find a color
		imshow("mask", mask);

		//Wait for a keystoke to move on the next frame. Integer is milisecond 
		waitKey(25);


	}

	return 0;

}