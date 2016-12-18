#include <iostream>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>

using namespace cv;
using namespace std;

int main() {
    Mat img = cvLoadImage("/home/kb1prb13/LOCAL/IG_1-14/V/Image/Group/Histogramm/lena.png");
    cvtColor(img, img, CV_RGB2GRAY );
    Mat res = img.clone();
    double normal[256], q[256], user[256], pix[256], s[256], s_[256], q_[256], temp[256];
    int raz = 256, pos1 = 0, pos2 = 0, b = 0, l = 0, con = 0;;

    for (int x = 0; x < 256; x++)   normal [x] = 0;
    for (int x = 0; x < img.rows; x++)  for(int y = 0; y < img.cols; y++)   normal[(img.at<uchar>(x,y))]+=1;

    return 0;
}