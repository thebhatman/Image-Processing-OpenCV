#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <vector>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <limits>

using namespace cv;
using namespace std;

Mat img = imread("torch.jpg", 1);

void Callbackfunc(int Event, int y, int x, int flags, void* userdata)
{
	if (Event == EVENT_LBUTTONDOWN)
	{
		printf("B=%d\n", img.at<Vec3b>(x, y)[0]);
		printf("G=%d\n", img.at<Vec3b>(x, y)[1]);
		printf("R=%d\n", img.at<Vec3b>(x, y)[2]);
		printf("(i,j) = (%d,%d)\n\n",x,y);
		

	}
}

void Callbackfunc2(int Event, int y, int x, int flags, void* userdata)
{
	if (Event == EVENT_LBUTTONDOWN)
	{
		printf("%d\n",img.at<uchar>(x,y));
		printf("(i,j) = (%d,%d)\n\n",x,y);
		

	}
}



int main()
{
	
    namedWindow("original", WINDOW_AUTOSIZE);

    //cvtColor(img,img,CV_BGR2GRAY);

	imshow("original", img);
	setMouseCallback("original", Callbackfunc, NULL);

	waitKey(0);
}