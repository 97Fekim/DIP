#include "header.h"

//int main()
//{
//	Mat LoadedImage = imread("lenna.jpg", IMREAD_COLOR);
//	imshow("Original Image", LoadedImage);
//
//	resize(LoadedImage, LoadedImage, Size(100, 100));
//	imshow("New image", LoadedImage);
//
//	waitKey(0);
//	return 0;
//}

// reshape�Լ��� å 101p ����.

int main(void)
{
	Mat img1 = imread("lenna.jpg");
	Mat img2 = imread("dog.jpg");
	imshow("Original Image", img1);

	img1.push_back(img2);			// ���� ȭ�Ҽ� ??? x !!! ���� ???�� ������ ��ġ�ؾ� ���� �� �ִ�.

	imshow("New Image", img1);
	waitKey(0);

	return 0;
}