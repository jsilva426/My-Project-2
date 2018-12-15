#pragma once
//not finished
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include<functional>
using std::hash;

//calculate index of left child v[2*k+1]
//calc ind of rchild v[2*k +2]
//calc ind of root v[(k-1)/2


struct node
{

	string ID;
	string parentID;
	string rEvent;
	
	int leftInd;
	int rightInd;

	string LHASH;
	string RHASH;

	vector<string>LHIST,RHIST;

};

string hashID(string parent, string rawEvent)
{
	string id = rawEvent + parent;
	std::hash<string> hash_fn;
	size_t ID = hash_fn(id);
	int a = ID;
	string b = to_string(a).substr(0, 7);
	return b;

}

string ChildHash(string ID ,string parent, string rawE,string LHASH,string RHASH)
{
	string l = ID + parent + rawE + LHASH + RHASH;
	std::hash<string> hash_fn;
	size_t h = hash_fn(l);
	int a = h;
	string b = to_string(a).substr(0, 7);
	return b;

}
void rootNode(vector<struct node> &v1, string rawEvent)
{
	string id = rawEvent + "No Parent";
	string parId = "No Parent";
	std::hash<string> hash_fn;
	size_t ID = hash_fn(id);
	size_t par = hash_fn(parId);
	int a = ID;
	string b = to_string(a).substr(0, 7);
	a = par;
	string c = to_string(a).substr(0, 7);



	struct node root = { b,c,rawEvent,-1,-1 };
	v1.push_back(root);
}

void insert(vector<struct node> &tree, string rawEvent) // cannot seem to understand how once 2 nodes are created, how when a new node
{							// is created how the program fills the null node, how is this identified and selected
	for (int i = 0; i < tree.size(); i++)		//with an insert function?
	{
		if (rawEvent < tree[i].rEvent)
		{
			if(tree[i].LeftInd==-1)
			{
				
			struct node a = { hashID(tree[i].ID,rawEvent), tree[i].ID, rawEvent, -1, -1 };
			tree.push_back(a); tree[i].leftInd = i;
			struct node c= {hashID(tree[i].ID,NULL),tree[i].ID,NULL,-1,-1};
			tree.push_back(c);
			}

		}
		if (rawEvent>tree[i].rEvent)
		{
			if(tree[i].rightInd==-1)
			{


			struct node  b = { hashID(tree[i].ID,rawEvent), tree[i].ID, rawEvent, -1, -1 };
			tree.push_back(b); tree[i].rightInd = i;
			struct node d= {hashID(tree[i].ID,NULL),tree[i].ID,NULL,-1,-1};
			tree.push_back(d);
			}

		}
	}
}





void preOderTraversal(vector<struct node> tree, int index)
{
	cout << tree[index].rEvent<< endl;
	if (tree[index].leftInd != -1)
		preOderTraversal(tree, tree[index].leftInd);
	if (tree[index].rightInd != -1)
		preOderTraversal(tree, tree[index].rightInd);
}


