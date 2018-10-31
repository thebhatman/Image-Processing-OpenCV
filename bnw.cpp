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
	Mat a=imread("dvHEX.png",1);
	int i,j;
	
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			b.at<uchar>(i,j)=(a.at<Vec3b>(i,j)[0]*0.114)+(a.at<Vec3b>(i,j)[1]*0.587)+(a.at<Vec3b>(i,j)[2]*0.299);

	Mat c=imread("dvHEX.png",0);
	imshow("Image",b);
	imshow("Image2",c);
	waitKey(0);
	
	return 0;
}

