
#include "test01.h"




using namespace std;

class test1 {



public:
	int test1arr(int* alist) {
		auto mysum = 0;
		auto len1 = sizeof(*alist);
		auto len2 = sizeof(alist[0]);

		auto len = len1 / len2;
		for (auto i = 0; i < len; i++) {
			mysum = mysum + alist[i];

		}

		return mysum;
	}


	int test1vec(vector<int>* vlist) {
		auto mysum = 0;



		for (auto a : *vlist) {
			mysum = mysum + a;

		}

		return mysum;
	}

	template <class T>
	void  print_v(vector<T>* vl) {
		for (auto v : *vl) {
			cout << v << " ";

		};
		cout << endl;
	}
private:
	int maxpop(vector<int>* vl) {
		int mymax = vl->at(0);
		auto imax = 0;

		for (auto i = 0; i < vl->size(); i++)
			if (vl->at(i) > mymax) {
				mymax = vl->at(i);
				imax = i;
			};

		vl->erase(vl->begin() + imax);
		return mymax;

	}

	int minpop(vector<int>* vl) {
		int mymin = vl->at(0);
		auto imin = 0;

		for (auto i = 0; i < vl->size(); i++)
			if (vl->at(i) < mymin) {
				mymin = vl->at(i);
				imin = i;
			};

		vl->erase(vl->begin() + imin);
		return mymin;

	}

	int triplets(vector<int>* vl) {

		auto npos = 0;
		auto nneg = 0;
		auto nv = vl->size();
		for (auto v : *vl) {
			if (v >= 0) {
				npos++;
			}
			else {
				nneg++;
			};
		}

		//copy vector
		auto vlc2 = *vl;
		auto vlc = &vlc2;
		auto a1 = this->maxpop(vl);
		auto a2 = this->maxpop(vl);
		auto a3 = this->maxpop(vl);

		auto b1 = this->minpop(vlc);
		auto b2 = this->minpop(vlc);

		if (nv == npos || nv == nneg) {
			auto xx = a1 * a2 * a3;
			return xx;

		}
		else if (nneg >= 2) {


			auto xx = a1 * a2 * a3;
			auto yy = a1 * b1 * b2;
			return max(xx, yy);



		};
		return 0;

	};

private:
#define IMAX_NAME 20
	struct elm_t {
		char name[IMAX_NAME + 1];
		vector<int>* val_lst;
	};
public:
	void template_test() {
		auto i_lst = new vector<int>{ 0 ,2};
		auto c_lst = new vector<char>{ 'a','b' };
		auto f_lst = new vector<float>{ 0.1, 0.2};
		auto s_lst = new vector<string>{ "aa","bb" };

		this->print_v(i_lst);
		this->print_v(f_lst);
		this->print_v(c_lst);
		this->print_v(s_lst);


	}
	void triplets_test() {
		int p;
		auto elm_lst = new list<elm_t*>;
		elm_t* elm;

		//todo read from json

		elm = new (elm_t);
		memset(elm->name, 0, sizeof(elm->name));
		strncpy(elm->name, "all pos", IMAX_NAME);
		elm->val_lst = new vector<int>{ 1, 2, 3, 4, 5 };
		elm_lst->push_back(elm);

		elm = new (elm_t);
		memset(elm->name, 0, sizeof(elm->name));
		strncpy(elm->name, "all neg", IMAX_NAME);
		elm->val_lst = new vector<int>{ -1, -2, -3, -4, -5 };
		elm_lst->push_back(elm);

		elm = new (elm_t);
		memset(elm->name, 0, sizeof(elm->name));
		strncpy(elm->name, "mix", IMAX_NAME);
		elm->val_lst = new vector<int>{ -1, -2, -3, 2,3 };
		elm_lst->push_back(elm);


		for (auto elm : *elm_lst) {
			cout << elm->name << ":";
			this->print_v(elm->val_lst);
			p = this->triplets(elm->val_lst);
			cout << p << endl;
		}


		for (auto elm : *elm_lst) {
			delete(elm->val_lst);
		};
		delete(elm_lst);


	}
};

int main()
{
	//int alist[] = { 1,2,3 ,4,5 };
	//auto* vlist = new vector<int>{ 1, 2, 3, 4, 5 };


	//cout << "Hello test." << endl;



	//	//auto res = ptest1->test1arr(alist);
	//	//cout << "res from array " << res << endl;
	//	//auto resv = ptest1->test1vec(vlist);
	//	//cout << "res from vector " << resv << endl;

		//auto a1 = ptest1->maxpop(vlist);
		//cout << " maxpop" << a1 << endl;
		//ptest1->print_v(vlist);

	test1* ptest1 = new test1();
	ptest1->triplets_test();
	ptest1->template_test();
	return 0;
}