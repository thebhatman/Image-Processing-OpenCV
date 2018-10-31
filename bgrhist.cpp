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
	Mat a=imread("joker.jpg",1);
	int i,j;

	int bpx[256],gpx[256],rpx[256];

	for(i=0;i<256;i++)
		bpx[i]=0;

	for(i=0;i<256;i++)
		gpx[i]=0;

	for(i=0;i<256;i++)
		rpx[i]=0;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			bpx[a.at<Vec3b>(i,j)[0]]++;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			gpx[a.at<Vec3b>(i,j)[1]]++;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			rpx[a.at<Vec3b>(i,j)[2]]++;


	int bmax=bpx[0];
	for(i=0;i<256;i++)
		if(bpx[i]>bmax) bmax=bpx[i];

	Mat b(bmax/15,512,CV_8UC3,Scalar(0,0,0));

	for(j=0;j<255;j+=2)
		for(i=bmax/15-1;i>=(bmax-bpx[j])/15;i--)
			{b.at<Vec3b>(i,j)[0]=255; b.at<Vec3b>(i,j+1)[0]=255;}

	int gmax=gpx[0];
	for(i=0;i<256;i++)
		if(gpx[i]>gmax) gmax=gpx[i];

	Mat g(gmax/20,512,CV_8UC3,Scalar(0,0,0));

	for(j=0;j<255;j+=2)
		for(i=gmax/20-1;i>=(gmax-gpx[j])/20;i--)
			{g.at<Vec3b>(i,j)[1]=255; g.at<Vec3b>(i,j+1)[1]=255;}

	int rmax=rpx[0];
	for(i=0;i<256;i++)
		if(rpx[i]>rmax) rmax=rpx[i];

	Mat r(rmax/30,512,CV_8UC3,Scalar(0,0,0));

	for(j=0;j<255;j+=2)
		for(i=rmax/30-1;i>=(rmax-rpx[j])/30;i--)
			{r.at<Vec3b>(i,j)[2]=255; r.at<Vec3b>(i,j+1)[2]=255;}

	imshow("Image",a);
	imshow("Blue",b);
	imshow("Green",g);
	imshow("Red",r);
	waitKey(0);

	return 0;

}
