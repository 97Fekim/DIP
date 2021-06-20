#include "header.h"

Mat getGrad(Mat src)
{
	Mat grad;
	int scale = 1;
	int delta = 0;

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x,1);
	convertScaleAbs(grad_y, abs_grad_y,1);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	return grad;
}

int main()
{
	/*Mat grad;
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	int scale = 1;
	int delta = 0;*/
	
	Mat src1 = imread("small.jpg", IMREAD_GRAYSCALE);
	Mat src2 = imread("small_stretched.jpg", IMREAD_GRAYSCALE);
	Mat grad_1;
	Mat grad_2;
	//// ȭ���� x������ �׷����Ʈ �� ���, scale ~ ������param�� default,, 3�� 3x3�� �ǹ�
	//// ����ũ�� ȭ�Ұ� ������ �� overflow�� �����ϱ� ���� 16signed type�� �̿�.
	//Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	//Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);


	//convertScaleAbs(grad_x, abs_grad_x);		
	//convertScaleAbs(grad_y, abs_grad_y);
	//// ������ ����Ͽ��� 8��Ʈ ��ķ� ��ȯ��Ų��.


	//// �׷����Ʈ�� ũ�⸦ ���, 2�� ����� ����ġ ���� ����ϴ� �Լ�. ���� 0.5 x Gx + 0.5 x Gy �� ����� �Ѵ�. 0�����ִ°� �����̴�. �ڿ� ��������,,
	//addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	grad_1 = getGrad(src1);
	grad_2 = getGrad(src2);

	imshow("����", src1);
	imshow("��Ʈ��Ī�� ����", src2);

	imshow("������ ����", grad_1);
	imshow("��Ʈ��Ī�� ������ ����", grad_2);

	resize(src1, src1, Size(180, 180));
	resize(src2, src2, Size(180, 180));
	resize(grad_1, grad_1, Size(180, 180));
	resize(grad_2, grad_2, Size(180, 180));

	for (int y = 0; y < src1.rows; y++)
		for (int x = 0; x < src1.cols; x++)
		{
			src2.at<uchar>(y,x) += grad_1.at<uchar>(y, x);
		}

	

	imshow("Mask", src2);
	
	waitKey(0);
	return 0;
}