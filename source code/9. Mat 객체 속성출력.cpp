#include "header.h"

int main()
{
	Mat img = imread("lenna.jpg");
	imshow("img", img);
	Mat gray;
	cvtColor(img, gray, CV_BGR2GRAY);

	cout << "���� �� = " << img.rows << endl;
	cout << "���� �� = " << img.cols << endl;
	cout << "����� ũ�� = " << img.size() << endl;
	cout << "��ü ȭ�� ���� = " << img.total() << endl;
	cout << "�� ȭ�� ũ�� = " << gray.elemSize() << endl;
	cout << "Ÿ�� = " << img.type() << endl;
	cout << "ä�� = " << img.channels() << endl;

	cout << img << endl;


	waitKey(0);
	return 0;
	

}