#include "pe12-3a.h"
//选择计算的油耗模式

int  set_mode(int n) {
	
	
	if (n) {
		return 1;//美式
	}
	else
		return 0;//公式
}

//void get_info(void) {
//	if (!flag) {
//		printf("Enter distance traveled in kilometers:");
//		scanf("%lf", &Kilomet);
//		
//		printf("Enter fule consumed in liters:");
//		scanf("%lf", &Fuel);
//	}
//	else {
//		printf("Enter traveled in mile:");
//		scanf("%lf", &miles);
//		
//		printf("Enter fule consumed in gallons:");
//		scanf("%lf", &gallons);
//	}
//}

//输入油耗
double get_info2(int flag){
	if (flag) { //漂亮国制
		double gallons = 0.0;
		printf("Enter fule consumed in gallons:");
		scanf("%lf", &gallons);
		return gallons;
	}
	else {
		double fuel = 0.0;
		printf("Enter fule consumed in liters:");
		scanf("%lf", &fuel);
		return fuel;
	}
}

//输入里程
double get_info1(int flag) {
	if (flag) { //漂亮国制
		double miles;
		printf("Enter traveled in mile:");
		scanf("%lf", &miles);
		return miles;
	}
	else {
		double Kilomet;
		printf("Enter distance traveled in kilometers:");
		scanf("%lf", &Kilomet);
		return Kilomet;
	}
}


//输入百公里油耗
void  show_info(double num1, double num2,int flag) {
	double fule;
	if (!flag) {
		fule = num1 / num2 * 100.0;
		printf("Fuel consumption is %.2f liters per 100 km\n",fule);
	}
	else {
		fule = num1 / num2;
		printf("Fuel consumption in %.1f miles per gallon\n", fule);
	}
}