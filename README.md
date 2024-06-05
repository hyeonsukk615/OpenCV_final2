#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
    // 이미지 읽기
    Mat image = imread("97_00_00.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // 이진화
    Mat binaryImage;
    threshold(image, binaryImage, 128, 255, THRESH_BINARY);
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));//40
    // 닫기 연산(Closing)
    Mat closedImage;
    
    morphologyEx(binaryImage, closedImage, MORPH_CLOSE, element);

    // 열린 연산(Opening)
    Mat openedImage;
    morphologyEx(binaryImage, openedImage, MORPH_OPEN, element);
    // 500x500 사이즈로 리사이즈
    Mat resized500x500;
    resize(closedImage, resized500x500, Size(500, 500));
    // 최종적으로 100x100 사이즈로 리사이즈
    Mat finalImage;
    resize(resized500x500, finalImage, Size(100, 100));
    // 결과 이미지 저장
    imwrite("output.jpg", openedImage);
    // 결과 이미지 보여주기
    imshow("Final Image", openedImage);
    waitKey(0);

    return 0;
}
이진화
열린 연산(Opening)
 닫기 연산(Closing)
500x500 사이즈로 리사이즈
최종적으로 100x100 사이즈로 리사이즈
일단 이진화 후에 열기연산 닫기연산 진행후에 진행해보려고 합니다.
숫자의 필기체에따른 이음 부분을 수정하려고합니다. 판병하기 위한 기본 절차
