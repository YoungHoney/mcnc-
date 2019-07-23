
#include <stdio.h>
#define n 0.00001

double f_x(double theta0, double theta1,double x1) {  //각 요소와 러닝타임이 이루는 관계가 일차함수라 가정
	return theta0 + (theta1 * x1);
}

double f_theta0(double* px, double* py, double theta0, double theta1) {   //각 요소가 러닝타임과 이루는 관계가 일차함수라면 각 요소에 대해 기울기를 구하고, 그 기울기의 크기가 중요도가 될거같은데 세타 0은 y절편? 같은 요소라 생각해서 메인함수에서 사용은 안함
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(px[i], theta0, theta1) - py[i]);
	}
	return sum; 
}        

double f_theta_age(double* px, double* py, double theta0, double theta1) { //각 요소에 대해 세타를 구하는 함수, 굳이 왜 나눠서 했냐면 아래에 있는 px에서 이차원배열로 하면 오류나서 걍 일차원배열로 하고 6*i+n형식으로 요소에 접근함
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(px[6*i], theta0, theta1) - py[i]) * px[6*i];
	}
	return sum;
}


double f_theta_wgt(double* px, double* py, double theta0, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(px[6*i+1], theta0, theta1) - py[i]) * px[6*i+1];
	}
	return sum;
}




double f_theta_oxygen(double* px, double* py, double theta0, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(px[6*i+2], theta0, theta1) - py[i]) * px[6*i+2];
	}
	return sum;
}


double f_theta_rstpulse(double* px, double* py, double theta0, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(px[6*i+3], theta0, theta1) - py[i]) * px[6*i+3];
	}
	return sum;
}
double f_theta_runpulse(double* px, double* py, double theta0, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(px[6*i+4], theta0, theta1) - py[i]) * px[6*i+4];
	}
	return sum;
}


double f_theta_maxpulse(double *px, double *py, double theta0, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(px[6*i+5], theta0, theta1) - py[i]) * px[6*i+5];
	}
	return sum;
}



int main() {



	double px1[] = { 44,89.47,44.61,62,178,182,
						40,75.07,45.31,62,185,185,
						44,85.84,54.3,45,156,168,
						42,68.15,59.57,40,166,172,
						38,	89.02,	49.87,	55,	178,	180,
						47,	77.45,	44.81,		58,	176,	176,
						40,	75.98,	45.68,	70,	176,	180,
						43,	81.19,	49.09,	64,	162	,170,
						44,81.42,	39.44,	63,	174,	176,
						38,	81.87,	60.06,		48,	170,	186,
						44,	73.03,	50.54,		45,	168,	168,
						45,	87.66,	37.39,		56,	186,	192,
						45,	66.45,	44.75,	51,	176	,176,
						47,	79.15,	47.27,		47,	162,164,
						54,	83.12,	51.86,		50,	166,	170,
						49,	81.42,	49.16,	44,	180,	185,
						51,	69.63,	40.84,		57,	168,	172,
						51,	77.91,	46.67,		48,	162,168,
						48,97.63,	46.77,		48,	162,	164,
						49,	73.37,	50.39,	67,	168,	168,
						57,	73.37,	39.41,		58,	174,	176,
						54,	79.38,	46.08,		62,	156,	165,
						52,76.32,	45.44,		48,	164,	166 };  //무의미한 노가다

	double py[23] = { 11.37,10.07,8.65,8.17,9.22,11.63,11.95,10.85,13.08,8.63,10.13,14.03,11.12,10.68,10.33,8.95,10.96,10.00,10.25,10.08,12.63,11.17,9.63 }; //무의미한 노가다2
	double theta0 = 1, theta_age = 40, theta_wgt = 70, theta_oxygen = 45, theta_rstpulse = 50, theta_runpulse = 165, theta_maxpulse = 160;  //대충 숫자 넣음
	double temp0 = 1, temp_age = 1, temp_wgt = 1, temp_oxygen = 1, temp_rstpulse = 1, temp_runpulse = 1, temp_maxpulse = 1; //대충 숫자 넣음 2
	int p=0;

	
	for (p = 0; p<1862; p++) {   //1861이후로 모두 고정
		//printf("p===%d", p);
		temp_age = theta_age - n * f_theta_age(px1, py, theta0, theta_age);
		temp_wgt = theta_wgt - n * f_theta_wgt(px1, py, theta0, theta_wgt);
		temp_oxygen = theta_oxygen - n * f_theta_oxygen(px1, py, theta0, theta_oxygen);
		temp_rstpulse = theta_rstpulse - n * f_theta_rstpulse(px1, py, theta0, theta_rstpulse);
		temp_runpulse = theta_runpulse - n * f_theta_runpulse(px1, py, theta0, theta_runpulse);
		temp_maxpulse = theta_maxpulse - n * f_theta_maxpulse(px1, py, theta0, theta_maxpulse);

		printf("age:%lf, wgt:%lf, oxygen:%lf, rstpulse:%lf, runpulse:%lf, maxpulse:%lf, p:%d \n", theta_age, theta_wgt, theta_oxygen, theta_rstpulse, theta_runpulse, theta_maxpulse, p);


		theta_age = temp_age;
		theta_wgt = temp_wgt;
		theta_oxygen = temp_oxygen;
		theta_rstpulse = temp_rstpulse;
		theta_runpulse = temp_runpulse;
		theta_maxpulse = temp_maxpulse;



	}
	printf("가장 중요한 요소는 maxpulse"); //크기비교함수는 생략  

}