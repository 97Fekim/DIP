#include "header.h"


int main()
{
	Mat image = imread("void.bmp",IMREAD_GRAYSCALE); //Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));	// ����600, ����400�� �÷����� ���� �� �Լ����� ����,���� ���̴�.

	cvtColor(image,image,COLOR_GRAY2BGR);

	//line(image, Point(100, 50), Point(300, 300), Scalar(0, 0, 255) , 7);	// (�̹���,������,����,����,�β�) �������� : ������ ����, �������� ����, ������ BGR �������.
	rectangle(image, Point(610, 349), Point(720, 470), Scalar(0, 255, 0), 1);	// (�̹���,������,�����ʾƷ�,����,�β�) 
	//circle(image, Point(100, 300), 60, Scalar(255, 0, 0), 3);				// (�̹���, �߽�, ������, ����, �β� )
	//ellipse(image, Point(300, 350), Point(100, 60), 45, 130, 270, Scalar(255, 255, 255), 5);	// (�̹���, �߽�, ���������, ȸ������, ���۰���, ���ᰢ��, ����, �β�)

	imshow("�̸��̾�", image);

	waitKey(0);
	return 0;
}