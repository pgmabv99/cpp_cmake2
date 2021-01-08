#include "test.h"



// ------------tree class
class node_t {
public:
	node_t::node_t(string key);
	string key;
	vector<node_t*> children;

};

node_t::node_t(string key) {
	node_t::key = key;
}

//-------------node class
class tree_t {
public:


	tree_t::tree_t();
	enum class direction_t {
		BCK
		,FWD
	};
	void tree_t::trav(const direction_t direction);

private:
	node_t* root;

};




tree_t::tree_t() {
	auto a1 = new node_t("a1");
	tree_t::root = a1;

	auto b1 = new node_t("b1");
	a1->children.push_back(b1);

	auto b2 = new node_t("b2");
	a1->children.push_back(b2);

	auto c11 = new node_t("c11");
	b1->children.push_back(c11);

	auto c12 = new node_t("c12");
	b1->children.push_back(c11);

	b2->children.push_back(new node_t("c21"));
	b2->children.push_back(new node_t("c22"));
}

void tree_t::trav(direction_t direction) {

	stack<node_t*>* stk = new stack<node_t*>;
	stk->push(root);

	while (stk->size() > 0) {
		auto node = stk->top();
		stk->pop();
		cout << node->key << endl;
		switch (direction) {
		case tree_t::direction_t::BCK:
			for (auto t = node->children.begin(); t != node->children.end(); t++) {
				stk->push(*t);

			}
			break;
		case tree_t::direction_t::FWD:
			for (auto t = node->children.rbegin(); t != node->children.rend(); t++) {
				stk->push(*t);

			}
			break;
		}
	};

};


void test_tree_t::run() {
	auto tree_p = new tree_t();
	cout << "forward" << endl;
	tree_p->trav(tree_t::direction_t::FWD);

	cout << "back" << endl;
	tree_p->trav(tree_t::direction_t::BCK);

	delete(tree_p);

}