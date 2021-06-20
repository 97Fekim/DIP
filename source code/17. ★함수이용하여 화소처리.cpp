#include "header.h"

int main()
{
	Mat img = imread("lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img);

	Mat oimage;
	img.convertTo(oimage, -1, 1, 30); // -1�� rType, 1�� alpha, 30�� beta�̴�.
	// ����������, oimage(x,y) = saturate_cast<rType>(alpha(*input)(x,y)+beta)�� �ȴ�.
	// �����ϰ� ���ĸ� ���ؼ� ��Ÿ�� ���Ѵ� ��� ���̴�.

	imshow("New Image", oimage);
	waitKey(0);
	return 0;

}