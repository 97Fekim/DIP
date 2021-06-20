#include "header.h"

int main()
{
	double alpha = 1.0;
	int beta = 0;

	Mat image = imread("fekim.jpg");
	Mat oimage;

	cout << "���İ��� �Է��ϼ���: [1.0 ~ 3.0]";
	cin >> alpha;
	cout << "��Ÿ���� �Է��ϼ���: [0 ~ 50]";
	cin >> beta;

	/* Mat �̶�� ��ü�ȿ� +������ ���ǵǾ� �ֱ� ������ ������ ���� 
	���� �׳� beta�� ���ָ� blue���п��� beta�� �߰��ǹǷ� Scalar�� �̿���
	������ �̿��ؾ� �Ѵ�. */
	oimage = image * alpha + Scalar(beta,beta,beta);		

	imshow("Original Image", image);
	imshow("New Image", oimage);

	waitKey(0);
	return 0;

}