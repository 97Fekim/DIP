#include"header.h"


// ������ ������� ������Ѻ��Ҵ�.
int main() 
{
	Mat src = imread("ksc.jpg", IMREAD_COLOR);
	
	Mat gray;

	cvtColor(src, gray,COLOR_BGR2GRAY);

	imshow("gray", gray);

	while (1)
	{
		int key = waitKeyEx();		// Ű���� ����Ű�� 2424832�� ����, Ű���� ������Ű�� 2555904�� ����
		cout << key << " ";	
		if (key == 'q')break;
		else if (key == 2424832)	// ����Ű�� ������ ��⸦ 50����.
			gray -= 50;				
		else if (key == 2555904)	// ������Ű�� ������ ��⸦ 50����
			gray += 50;
		imshow("gray", gray);
	}

	return 0;
}