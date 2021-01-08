#include "test.h"

void  maxabssum1(vector<int>& a, int pos, int n, int& mymax, int& mysum) {


	if (pos == n) {
		//cout << mysum << " :" << mymax << endl;
		if (abs(mysum) < mymax) {
			mymax = abs(mysum);
			//cout << "selected " << mymax << endl;
		};
		return;
	}
	else {
		//try  with +
		mysum = mysum + a.at(pos);
		maxabssum1(a, pos + 1, n, mymax, mysum);
		mysum = mysum - a.at(pos);

		//try  with +
		mysum = mysum - a.at(pos);
		maxabssum1(a, pos + 1, n, mymax, mysum);
		mysum = mysum + a.at(pos);
	};

}

int maxabssum_recursion(vector<int>& a) {
	int n = (int) a.size();
	auto pos = 0;
	int mymax = 20000 * 100;
	int mysum = 0;
	maxabssum1(a, pos, n, mymax, mysum);
	return mymax;
}


#include <stack>
#include <list>
#include <vector>
#include <limits.h>

int maxabssum_stack(vector<int>& a) {
	int n =(int) a.size();
	if (n == 0) return 0;
	auto stk_sum = new stack<int>;
	auto stk_pos = new stack<int>;

	stk_sum->push(0);
	stk_pos->push(0);
	int sum;
	int pos;

	int  mymax = INT_MAX;

	while (!stk_pos->empty()) {

		pos = stk_pos->top();
		stk_pos->pop();

		sum = stk_sum->top();
		stk_sum->pop();

		auto sump = sum + a.at(pos);
		auto sumn = sum - a.at(pos);

		if (pos == n - 1) {
			if (abs(sump) < mymax) mymax = abs(sump);
			if (abs(sumn) < mymax) mymax = abs(sumn);

		}
		else {
			stk_pos->push(pos + 1);
			stk_sum->push(sump);
			stk_pos->push(pos + 1);
			stk_sum->push(sumn);

		}





	}

	return mymax;

};

void test_maxabssum_t :: run() {
	vector<int> a = { 1,5,2,-2,7 };
	auto res = maxabssum_stack(a);
	cout << res << endl;
}