#include "util.h"
#include "test.h"
#include <algorithm>

void print_a(int a[], int la) {

	for (auto i = 0; i < la; i++) {
		cout << a[i] << ",";

	}
	cout << endl;
}

int solution(int a[], int b[], int la, int lb) {

	sort(a, a + la);
	sort(b, b + lb);

	auto mymin = INT_MAX;
	auto ia = 0;
	auto ib = 0;

	while ((ia < la) && (ib < lb)) {
		auto dif = abs(a[ia] - b[ib]);
		
		if (dif < mymin) mymin = dif;
		if (dif == 0) break;
		if (a[ia] < b[ib]) {
			ia++;
		}
		else {
			ib++;
		}
	

	}
	return mymin;


}


void test_arr_dist_t::run() {

	int a[] = { 6,3,2 };
	int la = sizeof(a) / sizeof(a[0]);
	int b[] = { 17,14,15 };
	int lb = sizeof(b) / sizeof(b[0]);
	print_a(a, la);
	print_a(b, lb);


	auto mymin= solution(a, b, la, lb);
	cout << "min dif" << mymin << endl;

}
test_arr_dist_t::test_arr_dist_t() {

}
test_arr_dist_t ::~test_arr_dist_t() {

}