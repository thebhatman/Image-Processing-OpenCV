#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    Mat a=imread("joker.jpg",1);

    VideoCapture cap("videoplayback"); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        //cvtColor(frame, edges, CV_BGR2GRAY);
        //GaussianBlur(edges, edges, Size(3,3), 1.5, 1.5);
        //Canny(edges, edges,15, 50);
        imshow("edges", frame);
        waitKey(10);
        imshow("edges",a);
        int flag=waitKey(10);
        if(flag==27) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}