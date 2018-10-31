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
	Mat a=imread("joker.jpg",0);
	int i,j;

	int px[256];

	for(i=0;i<256;i++)
		px[i]=0;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			px[a.at<uchar>(i,j)]++;

	int max=px[0];
	for(i=0;i<256;i++)
		if(px[i]>max) max=px[i];

	Mat b(max/20,512,CV_8UC1,Scalar(255));

	for(j=0;j<255;j+=2)
		for(i=max/20-1;i>=(max-px[j])/20;i--)
			{b.at<uchar>(i,j)=0; b.at<uchar>(i,j+1)=0;}

	imshow("Image",a);
	imshow("Image2",b);
	waitKey(0);

	return 0;

}