#include "header.h"

int main()
{
	Mat src;
	src = imread("lenna.jpg",IMREAD_GRAYSCALE);
	imshow("������", src);
	Mat dst;

	src.convertTo(dst, CV_32F);

	dst.convertTo(src, CV_8UC1);
	imshow("����� ����", src);

	waitKey(0);
	return 0;

}