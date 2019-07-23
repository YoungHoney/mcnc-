
#include <stdio.h>
#define theta0 0 
#define n 0.000001

double f_x(double x, double theta1,double theta2,double theta3) {  // 3차함수모양으로 가정
	return theta0 + (theta1 * x)+(theta2*x*x)+(theta3*x*x*x);
}

double f_theta1(double* px, double* py, double theta1,double theta2,double theta3) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 9; i++) {
		sum += (f_x(px[i], theta1,theta2,theta3) - py[i]) *px[i];
	}
	return sum;
}


double f_theta2(double* px, double* py, double theta1, double theta2, double theta3) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 9; i++) {
		sum += (f_x(px[i], theta1, theta2, theta3) - py[i]) *px[i]*px[i];
	}
	return sum;
}

double f_theta3(double* px, double* py, double theta1, double theta2, double theta3) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 9; i++) {
		sum += (f_x(px[i], theta1, theta2, theta3) - py[i]) * px[i]*px[i]*px[i];
	}
	return sum;
}


int main() {

	double px[9] = {0,1,2,3,4,5,6,7,8};
	double py[9] = {7370,7380,7320,6860,6520,6630,6790,6840,7030};

	double theta1 = 0.01;
	double theta2 = 0.01;
	double theta3 = 0.01;

	double temp1 = 0;
	double temp2 = 0;
	double temp3 = 0;

	int i = 0;
	

	for (i = 0;; i++) {
		temp1 = theta1 - n * f_theta1(px, py, theta1,theta2,theta3);
		temp2 = theta2 - n * f_theta2(px, py, theta1, theta2,theta3);
		temp3 = theta3 - n * f_theta3(px, py, theta1, theta2, theta3);

		theta1 = temp1;
		theta2 = temp2;
		theta3 = temp3;
		printf("i:%dtheta1:%lf  theta2:%lf, theta3:%lf \n",i, theta1,theta2,theta3);

	}

}