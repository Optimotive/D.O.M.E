
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

string getTimeStamp();

int main(void) {

	VideoCapture source (0);
	if (!source.isOpened()) {

		printf("Camera not found");
		return -1;
	}

	int source_width  = source.get(CV_CAP_PROP_FRAME_WIDTH);
	int source_height = source.get(CV_CAP_PROP_FRAME_HEIGHT);

	string filename = getTimeStamp() + ".avi";

	VideoWriter savefile(filename, CV_FOURCC('M', 'J', 'P', 'G'), 30, Size(source_width, source_height));

	for (;;) {

		Mat frame;
		source >> frame;
		savefile.write(frame);

		char c = (char)waitKey(33);
		if ( c == 27 ) break;
	}
	return 0;
}

string getTimeStamp() {

	time_t t = time(0);
	tm * now = localtime( &t );
	string ans = "";

	ans += (now->tm_year + 1900);
	ans += "-";
	ans += (now->tm_mon + 1);
	ans += "-";
	ans += now->tm_mday;

	return ans;
}
