#include "header.h"

int main()
{
	Mat img = imread("fekim.jpg");
	imshow("img", img);
	Mat roi(img, Rect(10, 10, 2, 2));

	cout << "���� �� = " << roi.cols << endl;
	cout << "���� �� = " << roi.rows << endl;
	cout << "roi = " << endl << roi << endl << endl;
	waitKey(0);

	return 0;

}