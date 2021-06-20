#include "header.h"

// // ������׷� ��� ������Ÿ��.
//void drawHist1(int histogram[]);
//void drawHist2(int histogram[]);
void printHist(Mat src, const char * w_name)
{
	vector<Mat> bgr_planes;			// b,g,r �� ���� �ϳ� ����, 
	split(src, bgr_planes);			// src�� b,g,r ���� �ɰ� bgr_planes�� 3���� ����ũ�� ����.
	int histSize = 256;				// 256���� ������ ���� ����
	float range[] = { 0, 256 };		// 
	const float* histRange = { range };	//	����� ��¥ �𸣰ڴ�.
	bool uniform = true, accumulate = false;	// 
	Mat b_hist, g_hist, r_hist;		// ������׷��� ���� �� ��,��,�� �� ����ũ ����

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);	// b_hist �� ������׷��� ����.
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	int hist_w = 512;
	int hist_h = 400;											// ���� ���� ����		
	int bin_w = cvRound((double)hist_w / histSize);				// ������ ������ ũ�� ����
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));	// ������׷� ��� �� â ����

	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());		// ȭ���� �Ѿ�� �ʰ� ����ȭ
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 0; i < 255; i++)
	{
		line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - b_hist.at<float>(i)), Scalar(255, 0, 0));
		line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - g_hist.at<float>(i)), Scalar(0, 255, 0));		// ������׷� ���
		line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - r_hist.at<float>(i)), Scalar(0, 0, 255));
	}

	imshow(w_name, histImage);
}

int main()
{
	Mat src = imread("ksc1.jpg", IMREAD_COLOR);
	if (src.empty())return-1;

	vector<Mat> bgr_planes;
	split(src, bgr_planes);


	for (Mat plane : bgr_planes)
		equalizeHist(plane, plane);
		
	Mat dst;
	merge(bgr_planes, dst);

	imshow("img_src", src);
	imshow("img_dst", dst);

	printHist(src, "hist_src");
	printHist(dst, "hist_dst");


	/*Mat dst;

	equalizeHist(src, dst);
	imshow("����", src);
	imshow("��Ȱȭ", dst);*/

	/*int histogram_src[256] = { 0 };
	int histogram_dst[256] = { 0 };

	
	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histogram_src[(int)src.at<uchar>(y, x)]++;

	for (int y = 0; y < dst.rows; y++)
		for (int x = 0; x < dst.cols; x++)
			histogram_dst[(int)dst.at<uchar>(y, x)]++;

	drawHist1(histogram_src);
	drawHist2(histogram_dst);*/


	waitKey(0);
	return 0;
}




// //������׷� ��� �ٵ�
//void drawHist1(int histogram[])
//{
//	int hist_w = 512;
//	int hist_h = 400;
//	int bin_w = cvRound((double)hist_w / 256);	// �ݿø��ϴ� �Լ�.
//
//	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));	// 512 x 400 �� 8bit 3ä��, ������� �̹��� �ϳ� ����.
//
//	int max = histogram[0];
//	for (int i = 0; i < 255; i++)
//	{
//		if (max < histogram[i])				// ������׷��� �ִ��� ã�´�.
//			max = histogram[i];
//	}
//
//	for (int i = 0; i < 255; i++)
//	{
//		histogram[i] = floor(((double)histogram[i] / max) * histImage.rows);	// ������׷��� ���� hist_h���� Ŀ�� �ʰ��ϴ� �� ����, �� 0~255������ ����ȭ
//	}
//
//	for (int i = 0; i < 255; i++)
//	{
//		line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - histogram[i]), Scalar(0, 0, 255));	// å 161p ����
//	}
//
//	imshow("histogram1", histImage);
//}
//
//void drawHist2(int histogram[])
//{
//	int hist_w = 512;
//	int hist_h = 400;
//	int bin_w = cvRound((double)hist_w / 256);	// �ݿø��ϴ� �Լ�.
//
//	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));	// 512 x 400 �� 8bit 3ä��, ������� �̹��� �ϳ� ����.
//
//	int max = histogram[0];
//	for (int i = 0; i < 255; i++)
//	{
//		if (max < histogram[i])				// ������׷��� �ִ��� ã�´�.
//			max = histogram[i];
//	}
//
//	for (int i = 0; i < 255; i++)
//	{
//		histogram[i] = floor(((double)histogram[i] / max) * histImage.rows);	// ������׷��� ���� hist_h���� Ŀ�� �ʰ��ϴ� �� ����, �� 0~255������ ����ȭ
//	}
//
//	for (int i = 0; i < 255; i++)
//	{
//		line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - histogram[i]), Scalar(0, 0, 255));	// å 161p ����
//	}
//
//	imshow("histogram2", histImage);
//}