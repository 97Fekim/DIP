#include "header.h"

int main()
{
	Mat src;
	src = imread("lenna.jpg",IMREAD_GRAYSCALE);
	imshow("������", src);

	Mat dst;
	dst = 255 - src;
	imshow("����� ����", dst);

	waitKey(0);
	return 0;

}