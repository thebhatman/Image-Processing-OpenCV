#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace cv;
using namespace std;

int flag = 0;
int x_ini = 0, y_ini = 0;

void draw_line(Mat *my_image, int x, int y)
{
	if(flag == 0)
	{
		x_ini = x;
		y_ini = y;
		flag++;
	}
	Point2d temp;
	temp.x = y;
	temp.y = x;
	Point2d ini_temp;
	ini_temp.x = y_ini;
	ini_temp.y = x_ini;
	line(*my_image, ini_temp, temp, Scalar(0), 2,8,0);
	x_ini = x;
	y_ini = y;
}

int main()
{
	VideoCapture cap(0);
	if(!cap.isOpened())
		return -1;
	Mat temp,frame;
	cap>>temp;
	Mat my_image(temp.rows, temp.cols, CV_8UC1, Scalar(255));
	flag = 0;
	int count = 0;
	while(1)
	{
		cap>>temp;
		int i,j,k = 0,radius = 30, centrex = 0, centrey = 0;
		//Mat frame = temp.clone();
		cvtColor(temp, frame, COLOR_BGR2GRAY);

		for(i = 0; i < frame.rows; i++)
		{
			for(j = 0; j < frame.cols; j++)
			{
				//cout<<frame.at<uchar>(i,j)<<endl;
				//cout<<frame.at<Vec3b>(i,j)[0]<<" "<<frame.at<Vec3b>(i,j)[1]<<" "<<frame.at<Vec3b>(i,j)[2]<<endl;
				//if(frame.at<Vec3b>(i,j)[0] >= 240 && frame.at<Vec3b>(i,j)[1] >= 240 && frame.at<Vec3b>(i,j)[2] >= 240)
				if(frame.at<uchar>(i,j) >= 220)
				{
					//cout<<"Hi"<<endl;
					centrex += i;
					centrey += j;
					k++;
				}
			}
		}
		if(k!= 0)
		{
			centrex = centrex/k;
			centrey = centrey/k;
		}
		//cout<<centrex<<" "<<centrey<<endl;
		draw_line(&my_image, centrex, centrey);
		namedWindow("Video", WINDOW_NORMAL);
		imshow("Video", frame);

		namedWindow("Writing Board", WINDOW_NORMAL);
		imshow("Writing Board", my_image);
		int flag = waitKey(1);
		if(flag == 27)
			break;
	}
	return 0;
}