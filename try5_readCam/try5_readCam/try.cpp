#include<opencv2\core.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\highgui.hpp>
#include<iostream>
using namespace cv;

int main() {
	VideoCapture cam(0);
	if (!cam.isOpened()) {
		std::cout << "fail to open cam\n";
		return -1;
	}
	int frame_width = cam.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = cam.get(CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("cam.avi", CV_FOURCC('D','I','V','X'), 30, Size(frame_width, frame_height));

	while (1) {
		Mat frame;
		cam >> frame;
		if (frame.empty()) break;
		video.write(frame);
		imshow("cam", frame);
		int k = waitKey(25);
		if (k == 27) break;
	}
	cam.release();
	video.release();
	destroyAllWindows();

	return 0;
}