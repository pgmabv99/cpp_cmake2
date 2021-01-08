#include "test.h"

void find_pair(vector <int>& a, int t) {

	map<int, int> difs = {};
	for (auto i : a) {
		int dif = t - i;
		int key = i;
		auto iter = difs.find(key);
		if (iter  != difs.end()) {
			auto i1 = iter->second;
			auto i2 = i;
			cout << "pair " << i1 << " " << i2 << endl;
			break;
		}
		else {
			//difs.insert(make_pair(dif, i));
			//difs.insert(dif, i);  this will be run time err
			//difs.insert(pair<int,int>(dif, i));
			difs[dif]=i;
		}

	}
}





void test_hrt_t::run() {
	vector <int> a = { 1,5 };
	int t = 6;
	find_pair(a, t);
}