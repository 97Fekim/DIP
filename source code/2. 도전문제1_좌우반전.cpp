#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "������ ���� �� ����" << endl; }
	imshow("src",src);

	Mat dst;
	flip(src, dst, 1);		// src�� ������ �¿�������� dst�� �ִ´�.
	imshow("�����̸��ϻ�!", dst);


	waitKey(0);
	return 0;
}