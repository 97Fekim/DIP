#include "header.h"

int main()
{
	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("fekim.jpg");
	Mat oimage = Mat::zeros(image.size(), image.type());	// ��� ȭ�Ҹ� ���������� �ʱ�ȭ��.
	cout << "���İ��� �Է��ϼ��� : [1.0 - 3.0]";
	cin >> alpha;
	cout << "��Ÿ���� �Է��ϼ��� : [0 - 300]";
	cin >> beta;

	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			for(int c = 0; c < 3; c++)
			oimage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);	// <Vec3b>�� �÷������̹Ƿ� BRG�� ���Ѵ�. �� �÷��� �����Ϸ��� Vec3b�� ����� �Ѵ�.
																											// (y,c)[c] ���� y�� ��, x�� ��, c�� B,R,G�� ���Ѵ�. 
		}

	}
	imshow("Original Image", image);
	imshow("New Image", oimage);

	waitKey(0);
	
	return 0;
}