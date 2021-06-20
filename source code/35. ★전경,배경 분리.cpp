#include "header.h"


/*   ������׷� ����Լ� ������Ÿ��   */
void drawHist(const char* name, int histogram[]);

int main()
{

	Mat src, dst;

	src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Image", src);
	if (src.empty())return -1;

	Mat threshold_image;
	// 100���� ������0, 100���� ũ�� 255,, ������ param�� CV_THRESSH_BINARY | CV_THRESH_OTSU�� �ٲٸ� ���� ����ȭ ����.
	// OTSU�� ������ 100�� ���� ���ǹ�,, �Ӱ찪�� �˾Ƽ� ã����
	threshold(src, threshold_image, 100, 255, THRESH_BINARY|CV_THRESH_OTSU);
	imshow("Threshold Image", threshold_image);



	/*     ������׷��� ����ϴ� �κ�     */

	int histogram_image[256] = { 0 };
	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histogram_image[(int)src.at<uchar>(y, x)]++;
	drawHist("image",histogram_image);



	int histogram_new_image[256] = { 0 };
	for (int y = 0; y < threshold_image.rows; y++)
		for (int x = 0; x < threshold_image.cols; x++)
			histogram_new_image[(int)threshold_image.at<uchar>(y, x)]++;
	drawHist("new image",histogram_new_image);



	waitKey(0);

	return 0;

}

/*     ������׷� ����Լ�     */
void drawHist(const char* name, int histogram[])
{
	int hist_w = 780;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);	// �ݿø��ϴ� �Լ�.

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));	// 512 x 400 �� 8bit 3ä��, ������� �̹��� �ϳ� ����.

	int max = histogram[0];
	for (int i = 0; i < 256; i++)
	{
		if (max < histogram[i])				// ������׷��� �ִ��� ã�´�.
			max = histogram[i];
	}

	for (int i = 0; i < 256; i++)
	{
		histogram[i] = floor(((double)histogram[i] / max) * histImage.rows);	// ������׷��� ���� hist_h���� Ŀ�� �ʰ��ϴ� �� ����, �� 0~255������ ����ȭ
	}

	for (int i = 0; i < 256; i++)
	{
		line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - histogram[i]), Scalar(0, 0, 0));	// å 161p ����
	}

	imshow(name, histImage);
}