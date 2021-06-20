#include "header.h"


/*  ����ġ�� �ο��� ��հ� ���͸� �߾��� ����ġ�� ���� ����,
	�־������� ����ġ�� ��������.	  */
int main()
{
	Mat src = imread("lenna.jpg", 1);
	Mat dst;
	imshow("src", src);

	for (int i = 1; i < 61; i = i + 2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		imshow("dst", dst);

		waitKey(500);			// 500ms���� ������ �������.
	}

	return 0;
}