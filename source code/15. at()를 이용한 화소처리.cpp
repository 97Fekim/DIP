#include "header.h"
/* �����Լ����� ȭ��ó��*/
//int main()
//{
//	Mat img = imread("lenna.jpg", IMREAD_GRAYSCALE);
//	imshow("Original image", img);
//
//	for (int r = 0; r < img.rows; r++)
//		for (int c = 0; c < img.cols; ++c)
//			img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + 30);
//
//	imshow("New image", img);
//	waitKey(0);
//
//	return 0;
//
//}

// ȭ���� ���� ������ ������ at() �Լ��� ����Ͽ� ȭ���� �ڷ����� ��ǥ�� ���޹޴´�.
// ������ �̰�� �����÷ο찡 �Ͼ�� ������ ȭ���� �߻��Ѵ�.  
// �׷��� saturate_cast() �Լ��� ����Ѵ�. �� ��쿡�� 255�� ������ 255�� ������Ų��.
// ex) 
// uchar u1 = 257; >> u1 = �� �ȴ�.
// uchar u2 = saturate_cast<uchar>(257); >> u2 = 255 �� �ȴ�.


/* �Լ����Ǹ� �̿��� ��� ���� */
void brighten(Mat& img, int value)		// �Լ����� img�� �������� ��ü�� �ּҸ� ������ �ȴ�.
{
	for (int r = 0; r < img.rows; r++) 
	{
		for (int c = 0; c < img.cols; ++c)
			img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + value);
	}
}

void drawHist(int hist[], char mode)
{
	int hist_h = 400;	// ������׷� ������ ����
	Mat histimg(hist_h, 512, CV_8UC3, Scalar(255, 255, 255)); // �������

	Scalar color;	// ������׷� ����

	switch (mode)
	{
	case 'B':color = Scalar(255, 0, 0); break;
	case 'G':color = Scalar(0, 255, 0); break;
	case 'R':color = Scalar(0, 0, 255); break;
	case 'K':color = Scalar(0, 0, 0); break;
	}

	int max = -30;
	for (int i = 0; i < 256; i++)
		if (max < hist[i]) max = hist[i];

	for (int i = 0; i < 256; i++)
		hist[i] = floor(((double)hist[i] / max) * hist_h);

	for (int i = 0; i < 256; i++)
		line(histimg, Point(2 * i, hist_h), Point(2 * i, hist_h - hist[i]), color);

	switch (mode)
	{
	case 'B':imshow("Histogram Blue", histimg); break;
	case 'G':imshow("Histogram Green", histimg); break;
	case 'R':imshow("Histogram Red", histimg); break;
	case 'K':imshow("Histogram Gray_scale", histimg); break;
	}

}

int main()
{
	Mat img = imread("�̽�x.jpg", IMREAD_GRAYSCALE);
	imshow("����", img);

	for (int r = 0; r < img.rows; r++)
	{
		for (int c = 0; c < img.cols; ++c)
			if (img.at<uchar>(r, c) > 45)
				img.at<uchar>(r, c) = 255;
	}

	imwrite("to_ppt.bmp", img);

	int histogram[256] = { 0 };
	for (int y = 0; y < img.rows; y++)
		for (int x = 0; x < img.cols; x++)
			histogram[(int)img.at<uchar>(y, x)]++;		// ������׷��� ����Ѵ�.
	drawHist(histogram, 'K');

	imshow("����", img);

	waitKey(0);
	return 0;



}