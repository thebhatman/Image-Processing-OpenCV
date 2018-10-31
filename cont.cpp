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

		Mat b=a.clone();
		GaussianBlur(b,b,Size(7,7),1.5,1.5);
		Canny(b,b,75,100);

		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;

		findContours(b,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));

		Mat c(b.rows,b.cols,CV_8UC3,Scalar(0,0,0));

		while(waitKey(40)!=27)
		{
		for(int i=0;i<contours.size();i++)
		{
			Scalar color=Scalar(rand()%256,rand()%256,rand()%256);
			drawContours(c,contours,i,color,1,4,hierarchy);
		}

		imshow("Contours",c);
		//imshow("Image",b);
		}

	return 0;

}