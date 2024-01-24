#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	Mat img;
	VideoCapture cap(0);
	CascadeClassifier faceCascade;
	faceCascade.load("haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) {
		cout << "File Not Found";
		return -1;
	}
	if (!cap.isOpened()) {
		cout << "Error Opening Camera";
		return -1;
	}

	while (true) {
		vector<Rect> faces;
		cap >> img;

		faceCascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(20, 20));
		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
		}

		imshow("Window", img);

		waitKey(25);


	}

	return 0;

}