/*
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
    // �̹��� �б�
    Mat image = imread("97_00_00.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // ����ȭ
    Mat binaryImage;
    threshold(image, binaryImage, 128, 255, THRESH_BINARY);
    Mat element = getStructuringElement(MORPH_RECT, Size(40, 40));
    /*
    // �ݱ� ����(Closing)
    Mat closedImage;
    
    morphologyEx(binaryImage, closedImage, MORPH_CLOSE, element);

    // ���� ����(Opening)
    Mat openedImage;
    morphologyEx(binaryImage, openedImage, MORPH_OPEN, element);
    /*
    // 500x500 ������� ��������
    Mat resized500x500;
    resize(closedImage, resized500x500, Size(500, 500));
    /*
    // ���������� 100x100 ������� ��������
    Mat finalImage;
    resize(resized500x500, finalImage, Size(100, 100));
    // ��� �̹��� ����
    imwrite("output.jpg", openedImage);
    // ��� �̹��� �����ֱ�
    imshow("Final Image", openedImage);
    waitKey(0);

    return 0;
}
*/