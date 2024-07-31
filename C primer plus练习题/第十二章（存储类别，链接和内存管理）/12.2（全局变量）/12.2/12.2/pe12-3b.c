#include "pe12-3a.h"

int main() {
	int mode;
	int n;
	printf("Enter 0 for metric mode, 1 for US mode:");
	scanf("%d", &mode);
	while (mode >= 0) {
		n = mode;
		int flag=set_mode(mode);
		if (!flag) {  //公制
			
			double Kilomet = get_info1(flag);//公里数
			double Fuel = get_info2(flag);//油耗
			show_info(Fuel, Kilomet,flag);

		}
		else {
			double miles = get_info1(flag);//英里
			double gallons = get_info2(flag);//油耗
			show_info(miles, gallons ,flag);

		}
		printf("Enter 0 for metric mode, 1 for US mode (-1 to quit):");
		scanf("%d", &mode);
		if (mode > 1) {
			mode = n;
			if (mode == 1)
				printf("Invalid mode specified. Mode %d(US) used\n", mode);
			else
				printf("Invalid mode specified. Mode %d(metric) used\n", mode);
		}
			
	}
	printf("Done.\n");
	return 0;
}