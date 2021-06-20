#include "header.h"


// ���콺 �̺�Ʈ�� �߻��ϸ� ȣ��Ǵ� �ݹ� �Լ��̴�.
void onMouse(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)		// ���콺 ���ʹ�ư�� ������
	{
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 100, Scalar(0, 255, 0), 10);
		putText(img, "face!", Point(x+20, y + 100), FONT_HERSHEY_PLAIN, 2.0, 255, 2);
		imshow("src", img);				// ������ ����Ǹ� �ٽ� ǥ���Ѵ�.
	}
	else if (event == EVENT_RBUTTONDOWN) {}
	else if (event == EVENT_MBUTTONDOWN) {}
	else if (event == EVENT_MOUSEMOVE) {
	}
}

int main()
{
	Mat src = imread("ksc.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "������ ���� �� ����" << endl; }
	imshow("src", src);

	setMouseCallback("src", onMouse, &src);
	waitKey(0);
	return 0;

}
