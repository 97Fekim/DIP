#include "header.h"

int main()
{
	Mat A;
	A = imread("lenna.jpg", IMREAD_COLOR);

	Rect r(20, 20, 100, 100);
	Mat D = A(r);					// ��ü D�� (10,10) �������� 100 x 100 ũ���� �κп����� ��Ÿ����.
	//Mat D = A(r).clone();			// D�� �����ϸ� A�� �ٲ��. �����ϰ� �ֱ� ������. �׷��� clone�� �ٿ���� ������ų �� �ִ�.

	imshow("full", A);
	D = Scalar(0, 0, 0);			// ���ɿ����� ��� ȭ�Ұ� (0,0,0)�� �ȴ�.
	imshow("black roi", A);
	waitKey(0);
	return 0;

}
