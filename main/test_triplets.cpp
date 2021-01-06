#include "util.h"
#include "test.h"

class triplets_t
{
public:
	int run(vector<int>* vl) {

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

};


#define IMAX_NAME 20
struct elm_t {
	char name[IMAX_NAME + 1];
	vector<int>* val_lst;
};

typedef list<elm_t*> elm_lst_t;

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

//private part
struct test_tripletsi_t {
	triplets_t* triplets_p;
};


test_triplets_t::test_triplets_t() {
	cout << "derive construct class test_triplets " << endl;
	//hidden private
	pi = (void*) new test_tripletsi_t;
	auto test_tripletsi_p = (test_tripletsi_t*)pi;
	test_tripletsi_p->triplets_p = new triplets_t();

}
test_triplets_t::~test_triplets_t() {
	cout << "derive destruct class test_triplets " << endl;
	auto test_tripletsi_p = (test_tripletsi_t*)pi;
	delete(test_tripletsi_p->triplets_p);
}
void test_triplets_t::run() {
	cout << "derive run  class test_triplets " << endl;
	auto test_tripletsi_p = (test_tripletsi_t*)pi;
	int p;

	auto str = get_file();
	auto elm_lst = get_json(str);
	if (elm_lst == nullptr) {
		return;
	}

	cout << "---running test" << endl;
	for (auto elm : *elm_lst) {
		cout << elm->name << ":";
		util::print_v(elm->val_lst);
		p = test_tripletsi_p->triplets_p->run(elm->val_lst);
		cout << p << endl;
	}

	for (auto elm : *elm_lst) {
		delete(elm->val_lst);
	};
	delete(elm_lst);
}
