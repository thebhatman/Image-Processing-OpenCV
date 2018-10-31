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
Mat a = imread("dice.png",0);
Mat b = a.clone();
GaussianBlur(b,b,Size(7,7),1.5,1.5);
Canny(b,b,150,100);
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
findContours(b,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
int cont_id,i,j,k;
for(cont_id=0;cont_id<contours.size();cont_id++)
{
	double length = arcLength(contours[cont_id],1);
	cout<<length<<endl;
	Scalar color=Scalar(255,0,0);
	double area = contourArea(contours[cont_id],0);
	cout<<area<<endl;
}
namedWindow("Image",WINDOW_NORMAL);
namedWindow("Img",WINDOW_NORMAL);
imshow("Image",a);
imshow("Img",b);
while(waitKey(0)!=27){}
return 0;
}
		


