#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main()
{
	Mat a=imread("fruits.png",0);

	int i,j,low=15,high=50;

	namedWindow("Image",WINDOW_AUTOSIZE);
	createTrackbar("Low","Image",&low,500);
	createTrackbar("High","Image",&high,500);

	while(1)
	{
		Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
		GaussianBlur(a,b,Size(5,5),1.5,1.5);
		Canny(b,b,low,high);

		imshow("Image",b);
		int flag=waitKey(30);
		if(flag==27) break;
	}

	return 0;

}