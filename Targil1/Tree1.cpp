/*#include <iostream>
#include <list>
#include <string>
#include "tree.h"
#include "NodeDt.h"
using namespace std;

NodeDt* tree::search(NodeDt* p, string val, NodeDt*& parent)
{
	if (p->content == val)
	{
		parent = p;
		return p;

	}
	list<NodeDt*> res = p->responses;
	for (std::list<NodeDt*>::iterator it = res.begin(); it != res.end(); ++it)
	{
		NodeDt* result = search((*it), val, p);
		if (result != NULL)
		{
			parent = p;
			return result;
		}
	}
	return NULL;

}


bool tree::addSon(string fatherquestion, string newanswer)
{
	NodeDt* q = root;
	if (search(root, fatherquestion, q) == NULL)
		return false;
	NodeDt* answer = new NodeDt(newanswer);
	//ValidAnswer* v = new ValidAnswer(newanswer, t);
	//list<ValidAnswer*>::iterator it;

	if (q->responses.empty())
	{
		q->isLeaf = false;
		q->responses.push_front(answer);
		/*q->answersList.front()->ans = newanswer;
		q->answersList.front()->son.
		return true;
	}
	q->responses.push_back(answer);
	//q->answersList.push_front(v);
	q->isLeaf = false;
	return true;
}
//-------------------------------------------------------
treeList::treeList()
{
	
}

~treeList()
{

}

void deleteTree(Tree*)
{

}
*/