#include "header.h"



int main()
{
	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Input image", src);
	int histogram[256] = { 0 };

	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histogram[(int)src.at<uchar>(y, x)]++;	
	// (y,x) �� (0,0) ~ (y,x) ���� ���µ�, src�� (y,x)�� ������ �ִ� 
	// ȭ���� ���� ������� 100�̴�. �׷� histogram[100]�� ���� 1 �����ϴ� ��.
	// ��� �� ����ؾ� �ɵ� >> src.at<uchar>(y,x) ,,

	//for (int count : histogram)	// for���� �ű��ϰ� ������ �� ���µ� ����� ����.
	//	cout << count << ",";
	int sum = 0;
	for (int i = 0; i < 256; ++i)
	{
		cout << "[" << i << "]" << " = " << histogram[i] << endl;
		sum += histogram[i];
	}

	waitKey(0);

	return 0;
}