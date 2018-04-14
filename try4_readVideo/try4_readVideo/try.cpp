#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>
using namespace cv;

int main() {
	VideoCapture chaplin("chaplin.mp4");
	if (!chaplin.isOpened()) {
		std::cout << "fail to load video\n";
		return -1;
	}
	while (1) {
		Mat frame;
		chaplin >> frame;
		if (frame.empty()) break;
		imshow("Frame", frame);
		int pause = waitKey(25);
		if (pause == 27) break;
	}
	chaplin.release();
	destroyAllWindows();
	return 0;
}