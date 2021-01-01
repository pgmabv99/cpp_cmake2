#include "util.h"
#include "test02_thr.h"


using namespace rapidjson;



class test01 {

private:
	util utilp= util();

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

	void test_arr_vec() {
		int alist[] = { 1,2,3 ,4,5 };
		auto* vlist = new vector<int>{ 1, 2, 3, 4, 5 };

		cout << "Hello test." << endl;
		auto res = this->test1arr(alist);
		cout << "res from array " << res << endl;
		auto resv = this->test1vec(vlist);
		cout << "res from vector " << resv << endl;

	}

private:
#define IMAX_NAME 20
	struct elm_t {
		char name[IMAX_NAME + 1];
		vector<int>* val_lst;
	};

	typedef list<elm_t*> elm_lst_t;
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



public:
	elm_lst_t* get_json(string str) {

		elm_lst_t* elm_lst = nullptr;

		Document d;
		d.Parse(str.c_str());

		auto root = "elm_lst";
		if (!d.HasMember(root)) {
			cout << "missing object. exit" << endl;
			return elm_lst;

		}
		const Value& elmjs_lst = d[root];

		//copy elm list from json

		elm_lst = new elm_lst_t;

		for (auto& elmjs : elmjs_lst.GetArray()) {
			//cout << elmjs["name"].GetString() << endl;

			auto elm = new elm_t;
			elm->val_lst = new vector<int>;
			strncpy(elm->name, elmjs["name"].GetString(), IMAX_NAME);

			const Value& valjs_lst = elmjs["val_lst"];
			for (auto& valjs : valjs_lst.GetArray()) {
				//cout << valjs.GetInt() << endl;
				elm->val_lst->push_back(valjs.GetInt());

			}
			elm_lst->push_back(elm);
		}

		return elm_lst;

	}


	//to do relatvie file 
	string  get_file() {
		ifstream file1;
		string line1;
		string res;
		/*string filename1 = "conf.json";*/
		string filename1 = "C:\\Users\\alexe\\source\\repos\\pgmabv99\\cpp_cmake2\\main\\conf.json";
		file1.open(filename1, ios::in);
		if (file1.is_open()) {
			while (getline(file1, line1)) {
				res = res + line1;
			};
			file1.close();
		}
		else {
			cout << "err reading file" << endl;
		};
		return res;

	}
public:
	void template_test() {
		auto i_lst = new vector<int>{ 0 ,2 };
		auto c_lst = new vector<char>{ 'a','b' };
		auto f_lst = new vector<float>{ 0.1, 0.2 };
		auto s_lst = new vector<string>{ "aa","bb" };

		util::print_v(i_lst);
		util::print_v(f_lst);
		util::print_v(c_lst);
		util::print_v(s_lst);


	}
	void triplets_test() {
		int p;

		auto str = this->get_file();
		auto elm_lst = this->get_json(str);
		if (elm_lst == nullptr) {
			return;
		}

		cout << "---running test" << endl;
		for (auto elm : *elm_lst) {
			cout << elm->name << ":";
			util::print_v(elm->val_lst);
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
	//todo
	//cout << "current path " << util::get_current_dir() << endl;
	//test01* ptest1 = new test01();
	//ptest1->triplets_test();
	//ptest1->template_test();

	auto pt = new test02_thr();
	pt->test02_thr_run();
	return 0;
}