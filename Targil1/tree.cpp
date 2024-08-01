#include "tree.h"

Node* Tree::search(Node* p, string val, Node*& parent)
{
	if (p->content == val)
	{
		parent = p;
		return p;

	}
	list<Node*> res = p->responses;
	for (std::list<Node*>::iterator it = res.begin(); it != res.end(); ++it)
	{
		Node* result = search((*it), val, p);
		if (result != NULL)
		{
			parent = p;
			return result;
		}
	}
	return NULL;

}

bool Tree::searchAndPrintPath(Node* p, string val)
{
	if (p->content == val)
	{
		cout << p->content;
		list<Node*> res1 = p->responses;
		for (std::list<Node*>::iterator it = res1.begin(); it != res1.end(); ++it) {
			cout << (*it)->content;
		}
		return true;
	}
	list<Node*> res = p->responses;
	for (std::list<Node*>::iterator it = res.begin(); it != res.end(); ++it)
	{
		bool isFound = searchAndPrintPath((*it), val);
		if (isFound)
		{

			cout << "=>" << p->content;
			return true;
		}
	}
	return false;

}

void Tree::addRoot(string newval)
{
	Node::Node(newval);
}

bool Tree::addSon(string fatherdiscussion, string newresponse)
{
	Node* q = root;
	if (search(root, fatherdiscussion, q) == NULL)
		return false;
	Node* answer = new Node(newresponse);
	//ValidAnswer* v = new ValidAnswer(newanswer, t);
	//list<ValidAnswer*>::iterator it;

	if (q->responses.empty())
	{
		q->isLeaf = false;
		q->responses.push_front(answer);
		/*q->answersList.front()->ans = newresponse;
		q->answersList.front()->son.
		return true;
		}
		q->responses.push_back(answer);
		//q->answersList.push_front(v);
		q->isLeaf = false;
		return true;*/
	}
}

bool Tree::printSubTree(Node* curr, string val)
{
	searchAndPrintPath(curr, val);
}

bool Tree::deleteSubTree(string val)
{
	
}
/*void removeSonValue(string v)
{

}*/
//---------------------------------------------------------------------------------

treeList::~treeList()
{
	list<Tree*> res1 = treeList::trees;
	for (std::list<Tree*>::iterator it = res1.begin(); it != res1.end(); ++it)
	{
		(*it)->deleteAllSubTree((*it)->root);
	}
	res1.clear();
	treeList::trees = res1;
}

void treeList::addNewTree(string s)
{
	Tree* t;
	t->addRoot(s);
	treeList::trees.insert(trees.end(), t);
}

void treeList::deleteTree(Tree* tr)
{
	//list<Tree*> res1 = treeList::trees;
	for (std::list<Tree*>::iterator it = treeList::trees.begin(); it != treeList::trees.end(); ++it)
	{
		if(tr == (*it))
			(*it)->deleteAllSubTree((*it)->root);
	}
}

void treeList::searchAndPrint(string val)
{

}

bool treeList::addResponse(string rt, string prnt, string res)
{
	for (std::list<Tree*>::iterator it = treeList::trees.begin(); it != treeList::trees.end(); ++it)
	{
		if ((*it)->root->content == rt)
		{
			(*it)->addSon(prnt, res);
		}		
	}
}

bool treeList::delResponse(string rt, string res)
{
	for (std::list<Tree*>::iterator it = treeList::trees.begin(); it != treeList::trees.end(); ++it)
	{
		if ((*it)->root->content == rt)
		{
			(*it)->deleteSubTree(res);
		}
	}
}

void treeList::printTree(string rt)
{
	for (std::list<Tree*>::iterator it = treeList::trees.begin(); it != treeList::trees.end(); ++it)
	{
		if ((*it)->root->content == rt)
		{
			print(rt);
		}
	}

}

void treeList::printAllTrees()
{
	for (std::list<Tree*>::iterator it = treeList::trees.begin(); it != treeList::trees.end(); ++it)
	{
			print((*it)->root->content);
	}

}








