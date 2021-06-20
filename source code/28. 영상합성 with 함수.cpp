#include "header.h"

//int main()
//{
//	double alpha, beta;
//	Mat src1, src2, dst;
//
//	src1 = imread("dog.jpg");
//	src2 = imread("fekim.jpg");
//	cout << "���İ��� �Է��ϼ���[0.0 - 1.0] : ";
//	cin >> alpha;
//	beta = (1.0 - alpha);
//
//	addWeighted(src1, alpha, src2, beta, 0.0, dst);
//	imshow("Original image1", src1);
//	imshow("Original image2", src2);
//	imshow("�����ռ�", dst);
//
//	dst = src1 + src2;
//	imshow("just add", dst);
//	waitKey(0);
//
//	return 0;
//
//}

/* ���� */
int main()
{
	double alpha, beta;
	Mat src1, src2, dst;

	src1 = imread("dog.jpg");
	src2 = imread("fekim.jpg");

	alpha = 0.99;

	for (; alpha > 0.01; alpha -= 0.01)
	{
		beta = 1 - alpha;
		addWeighted(src1, beta, src2, alpha, 0.0, dst);
		imshow("fade...", dst);
		waitKey(100);
	}

	return 0;

}