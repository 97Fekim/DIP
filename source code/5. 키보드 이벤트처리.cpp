#include "header.h"


// �����ڵ�
int main()
{
	Mat img;
	img = imread("ksc.jpg", IMREAD_COLOR);
	if (img.empty()) { cout << "������ ���� �� ����" << endl; }

	imshow("img", img);
	int x = 200;
	int y = 300;
	while (1)
	{
		int key = waitKey(100);		// 100ms ���� ����ڰ� Ű�� �����⸦ ��ٸ���.
		if (key == 'q')break;
		else if (key == 'a')
			x -= 10;
		else if (key == 'w')
			y -= 10;
		else if (key == 'd')
			x += 10;
		else if (key == 's')
			y += 10;
		circle(img, Point(x, y), 100, Scalar(0, 255, 0), 3);	//Ű�� ������ ���� ��ġ�� �������� 200�� ��� ���� �׸���.
		imshow("img", img);
	}

	return 0;
}


// �����ڵ� ���� (�� ������ �ʷϿ��� �ϳ��� �����ϰ�)
/*int main()
{
	Mat img;
	img = imread("dog.jpg", IMREAD_COLOR);
	if (img.empty()) { cout << "������ ���� �� ����" << endl; }

	imshow("img", img);
	int x = 300;
	int y = 300;
	while (1)
	{
		img = imread("dog.jpg", IMREAD_COLOR);
		int key = waitKey(100);		// 100ms ���� ����ڰ� Ű�� �����⸦ ��ٸ���.
		if (key == 'q')break;
		else if (key == 'a')
			x -= 10;
		else if (key == 'w')
			y -= 10;
		else if (key == 'd')
			x += 10;
		else if (key == 's')
			y += 10;
		circle(img, Point(x, y), 150, Scalar(0, 215, 0), 5);	//Ű�� ������ ���� ��ġ�� �������� 200�� ��� ���� �׸���.
		imshow("img", img);
	}

	return 0;
}*/