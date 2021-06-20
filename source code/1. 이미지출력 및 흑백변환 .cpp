#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.jpg", IMREAD_COLOR);	// src��� Mat ���� ���� �� lenna�̹����� �÷��� ����
	if (src.empty()) { cout << "������ ���� �� ����" << endl; }	// ������ ���� ��� �������
	imshow("�����̸��̴�", src);		// Mat��ü�� src�� ����� src ���� ��� ���� ""���� â�� �̸�

	Mat gray, edge, output;		// Mat ���� 3�� ����
	cvtColor(src, gray, CV_BGR2GRAY);	// src�� gray�� �ִµ� BGR�� ������� �����ؼ� �ִ´�.

	imshow("�����̸��̴�2", gray);	// ���
	imwrite("gray.jpg", gray);		// gray�� gray.jpg�� ����

	waitKey(0);
	return 0;
}
