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
    
       for (int x = 0; x < 256; x++){
        normal [x]/=(img.cols*img.rows);
        q[x] = round((255*normal [x]));
//        cout<<x<<"-->"<<normal [x]<<"  s --> "<<q[x]<<endl;
    }

    for (int x = 0; x < 256; x++){
        if (x <= 28){
            user[x] = 0.05;
            pix[x] = 28;
        }else if (x>28 && x <= 56){
            user[x] = 0.1;
            pix[x] = 56;
        }else if (x>56 && x <= 84){
            user[x] = 1.0;
            pix[x] = 86;
        }else if (x>86 && x <= 112){
            user[x] = 0.8;
            pix[x] = 112;
        }else if (x>112 && x <= 140){
            user[x] = 0.75;
            pix[x] = 140;
        }else if (x>140 && x <= 168){
            user[x] = 0.4;
            pix[x] = 168;
        }else if (x>168 && x <= 196){
            user[x] = 0.03;
            pix[x] = 196;
        }else if (x>196&& x <= 224){
            user[x] = 0.05;
            pix[x] = 224;
        }else if (x>224 && x <= 255){
            user[x] = 0.02;
            pix[x] = 255;
        }
    }
    
    
    if (b==0){
            for(int z = 0; z <= l;z++)    if (q_[z] == s[pos2]);

            if (con == 0) {
                q_[l] = s[pos2];
                s_[l] = temp[pos1];
                l++;

                for (int z = x; z < 256; z++)   if (s[z] == s[x]) {
                                                    s_[l] = temp[pos1];
                                                    q_[l] = s[x];
                                                    l++;
                                                }
                temp[pos1] = -1;
            }
        }
    }
    
        for (int x = 0; x < res.rows; x++)  for (int z = 0; z < res.cols; z++)  for (int y = 0; y < l; y++)
                if (q[res.at<uchar>(x, z)] == s_[y])    res.at<uchar>(x, z) = (uchar) pix[y];

    namedWindow("Original",CV_WINDOW_AUTOSIZE);
    namedWindow("Result",CV_WINDOW_AUTOSIZE);
    imshow("Original", img);
    imshow("Result", res);
    waitKey(0);
    return 0;
}
