#include <iostream>
#include <string>
using namespace std;

class OrderTranslator
{
public:
	struct BinaryTree
	{
		char value;
		BinaryTree *lc, *rc;

		BinaryTree(char ch)
		{
			this->value = ch;
			this->lc = NULL;
			this->rc = NULL;
		}
	} *root;

	void TranslateByLastOrderAndInOrder(string lastOrder, string inOrder)
	{
		root = NULL;
		tblai(lastOrder, inOrder, root);
	}

    string GetFirstOrder()
    {
        getOrderTempString = "";
        firstOrder(root);
        return getOrderTempString;
    }

private:

	void tblai(string lastOrder, string inOrder, BinaryTree* &bt)
	{
		if(inOrder.length() == 1)
		{
			bt = new BinaryTree(inOrder[0]);
			return;
		}
		else if(inOrder.length() == 0)
		{
			bt = NULL;
			return;
		}

		char root = lastOrder[lastOrder.length()-1];
		int ind = inOrder.find(root);
		int right = ind - 1;
		bt = new BinaryTree(root);
		if(ind - 1 < 0) ;
		else tblai(substring(lastOrder, 0, right), substring(inOrder, 0, ind - 1), bt->lc);
		if(lastOrder.length() - 2 < right + 1 || inOrder.length() - 1 < ind + 1);
		else tblai(substring(lastOrder, right + 1, lastOrder.length() - 2), substring(inOrder, ind+1, inOrder.length()-1),bt->rc);
	}

	string substring(string str, int startIndex, int endIndex)
	{
		return str.substr(startIndex, endIndex - startIndex + 1);
	}

	string getOrderTempString;

    void firstOrder(BinaryTree *bt)
    {
        if (bt != NULL)
        {
            getOrderTempString += bt->value;
            firstOrder(bt->lc);
            firstOrder(bt->rc);
        }
    }

};

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	OrderTranslator ot;
	ot.TranslateByLastOrderAndInOrder(b, a);
	cout<<ot.GetFirstOrder();
	return 0;
}