#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int k, g, e, d, m, y;
char c;
struct PESEL
{
	int no [7]; //PESEL number
	int series [5]; //String of numbers
	//Related functions
	void dayF(int i) {
	if (i > 0 && i < 32) {
	no[5] = i%10;
	no[4] = (i - no[1])/10;
	} else e = -1;
	};
	void monthF(int i) {
	if (i > 0 && i < 13) {
		no[3] = i%10;
		no[2] = (i - no[3])/10 + k;
	} else e = -1;
	};
	void yearF(int i) {
		if (i > 1800 && i < 2301) {
			if (i > 1800 && i < 1901) k = 8;
			else if (i > 1900 && i < 2001) k = 0;
			else if (i > 2000 && i < 2101) k = 2;
			else if (i > 2100 && i < 2201) k = 4;
			else if (i > 2200 && i < 2301) k = 6;
			no[1] = i%10;
			no[0] = (i%100 - i%10)/10;
		}
		else e = -1;
	}
	void sF(char c) {
		switch(c) {
			case 'M': g = 1; break;
			case 'F': g = 0; break;
			default: e = -1; break;
		};
	};
	
};
int main() {
	int index = 1;
	PESEL numero;
	ofstream File;
	cout << "Hi! This programme calculates possible PESEL numbers for given dates of birth and genders." << endl;
	cout << "Please input the day of birth:";
	cin >> d;
	cout << "Thank you. Please input the month of birth:";
	cin >> m;
	cout << "Thank you. Please input the year of birth:";
	cin >> y;
	cout << "Thank you. Finally please input the gender of the person concerned. The results will be saved to a .txt file :)";
	cin >> c;
	numero.dayF(d);
	numero.yearF(y);
	numero.monthF(m);
	numero.sF(c);
	if (e == -1) {
	cout << "Sorry an error occured :(" << endl;
	}
	else {
	File.open("results.txt");
	for (int i = 0; i <= 99999; i++) {
		if (i < 10) {
			for (int j = 0; j <= 3; j++) numero.series[j] = 0;
			numero.series[4] = i;
		}
		else if (i < 100 && i >= 10) {
			for (int j = 0; j <= 2; j++) numero.series[j] = 0;
			numero.series[4] = i%10;
			numero.series[3] = (i - i%10)/10;
		}
		else if (i < 1000 && i >= 100) {
			for (int j = 0; j <= 1; j++) numero.series[j] = 0;
			numero.series[4] = i%10;
			numero.series[3] = (i%100 - i%10)/10;
			numero.series[2] = (i - i%100)/100;
		}
		else if (i < 10000 && i >= 1000) {
			numero.series[0] = 0;
			numero.series[4] = i%10;
			numero.series[3] = (i%100 - i%10)/10;
			numero.series[2] = (i%1000 - i%100)/100;
			numero.series[1] = (i - i%1000)/1000;
		}
		else if (i < 100000 && i >= 10000) {
			numero.series[4] = i%10;
			numero.series[3] = (i%100 - i%10)/10;
			numero.series[2] = (i%1000 - i%100)/100;
			numero.series[1] = (i%10000 - i%1000)/1000;
			numero.series[0] = (i - i%10000)/10000;
		};
		int S = numero.no[0] * 9 + numero.no[1] * 7 + numero.no[2] * 3 + numero.no[3] * 1 + numero.no[4] * 9 + numero.no[5] * 7 + numero.series[0] * 3 + numero.series[1] * 1 + numero.series[2] * 9 + numero.series[3] * 7;
		if (S%10 == numero.series[4] && numero.series[3]%2 == g) {
			File << index << ". ";
			for(int i = 0; i <= 5; i++) {
				File << numero.no[i];
			};
			for(int i = 0; i<= 4; i++) {
				File << numero.series[i];
			};
			File << "\n";
			index++;
		};
			 
	};
	File.close();
	};
	return 0;
}
