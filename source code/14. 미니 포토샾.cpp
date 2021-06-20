#include "header.h"

Mat img, roi;
int mx1, my1, mx2, my2, mx3, my3;
bool cropping = false;

// ���콺 �̺�Ʈ�� �߻��ϸ� ȣ��Ǵ� �ݹ��Լ�.
void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat temp;
	temp = img.clone();

	if (event == CV_EVENT_LBUTTONDOWN)			// ���콺�� Ŭ���ϸ� �� ���� ��ǥ�� ���
	{
		mx1 = x;
		my1 = y;
		cropping = true;	
	}
	
	else if (event == CV_EVENT_MOUSEMOVE)
	{
		if (cropping == true)
		{
			mx3 = x; my3 = y;
			line(temp,Point(mx1, my1),Point(mx3, my1),Scalar(0,255,0),1);
			line(temp,Point(mx1, my1),Point(mx1, my3),Scalar(0, 255, 0), 1);
			line(temp,Point(mx1, my3),Point(mx3, my3), Scalar(0, 255, 0), 1);
			line(temp,Point(mx3, my1),Point(mx3, my3), Scalar(0, 255, 0), 1);
			imshow("image", temp);
		}
	}

	else if (event == CV_EVENT_LBUTTONUP)		// ���콺�� ���� �� ���� ��ǥ�� ���
	{
		mx2 = x;
		my2 = y;
		cropping = false;

		/*if (((mx1 < mx2) && (my1 > my2)))
			rectangle(img, Rect(mx2, my1, mx1 - mx2, my2 - my1), Scalar(0, 255, 0), 2);
		else if(((mx1 > mx2) && (my1 < my2)))
			rectangle(img, Rect(mx2, my1, mx1 - mx2, my2 - my1), Scalar(0, 255, 0), 2);
		else*/
		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);

		imshow("image", img);// ������ ��ǥ�� ���������� �ϴ� �簢���� �׸���.
	}
	
}

int main()
{
	img = imread("lenna.jpg");
	imshow("image", img);
	Mat clone = img.clone();	// ���纻�� �����
	
	setMouseCallback("image", onMouse);

	while (1)
	{
		int key = waitKey(100);
		if (key == 'q')break;		// q������ ����
		else if (key == 'c')		// c�� ������ ���纻 ����.
		{
			/*if((mx1 < mx2) && (my1 < my2))
				roi = clone(Rect(Rect(mx2, my1, mx1 - mx2, my2 - my1)));
			else if((mx1 > mx2) && (my1 < my2))
				roi = clone(Rect(Rect(mx2, my1, mx1 - mx2, my2 - my1)));
			else*/
				roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
			imwrite("resut.jpg", roi);
		}
	}

	return 0;

}