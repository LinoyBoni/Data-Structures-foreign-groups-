/*#pragma once

#include "NodeDt.h"

class tree
{
public:
	NodeDt* root;


	tree() { root = NULL; };
	~tree();
	NodeDt* search(string value) {
		if (!search(root, value, root))
			cout << "Value not found" << endl;
	};
	void addRoot(string newVal)
	{
		delete root;
		root = new NodeDt(newVal);

	};
	bool addSon(string fatherquestion, string newanswer);

private:
	NodeDt* search(NodeDt* root1, string value, NodeDt*& parent);
};

tree::tree()
{
}

tree::~tree()
{
}*/