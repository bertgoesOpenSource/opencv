// Example showing how to read and write images
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char** arg){
  //IplImage* Img = cvLoadImage(arg[1]);
  Mat Img = imread(arg[1]);
  /*
  cvNamedWindow("Example", CV_WINDOW_AUTOSIZE);
  cvShowImage("Example", Img);
  cvWaitKey(0);
  cvReleaseImage( &Img);
  cvDestroyWindow("Example");*/
  
  imshow("hello", Img);
  waitKey();
  
}
