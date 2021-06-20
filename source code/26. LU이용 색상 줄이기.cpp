#include "header.h"

int main()
{
	Mat img1 = imread("lenna.jpg", IMREAD_GRAYSCALE);
	imshow("������", img1);

	Mat table(1, 256, CV_8U);

	uchar* p = table.ptr();
	for (int i = 0; i < 256; ++i)	// LUT�� �� table�� 0~256�� �ƴ�, 0~100 : 0, 100~200 : 1, 200~ : 2 �� �ִ´�. �� 0000....100.100.100....200.200.200...
		p[i] = (i / 100) * 100;

	Mat img2;
	LUT(img1, table, img2);

	imshow("������", img2);

	waitKey(0);
	return 0;
}