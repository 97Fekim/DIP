#include "header.h"

int main()
{
	Mat image = imread("lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	int threshold_value = 37;
	threshold(image, dst, threshold_value, 255, THRESH_BINARY);

	imshow("������", image);
	imshow("���ο� ����", dst);

	Rect r(55, 50, 110, 110);
	Mat image2 = image(r).clone();
	Mat dst2;

	imshow("roi", image2);

	threshold(image2, dst2, threshold_value, 255, THRESH_BINARY);

	imshow("���ο� roi ����", dst2);
	waitKey(0);
	return 0;
}