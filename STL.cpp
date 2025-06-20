#include"STL.h"

void Disp(vector<int>& myv)
{
	vector<int>::iterator it;
	for (it = myv.begin(); it != myv.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
}

void myvsort()
{
	int a[] = { 2,1,5,4,3 };
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> myv(a, a + n);
	cout << "initial v:"; Disp(myv);
	sort(myv.begin(), myv.end(), less<int>());
	cout << "less sort v:"; Disp(myv);
	sort(myv.begin(), myv.end(), greater<int>());
	cout << "greater sort v:"; Disp(myv);

}

void disp(list<int>& lst)
{
	list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
	{
		printf("%d", *it);
	}

	printf("\n");
}



void try_string()
{
	string s1 = "", s2, s3 = "Bye";
	s1.append("Good morning");
	s2 = s1;
	int i = s2.find("morning");
	s2.replace(i, s2.length() - i, s3);

	string s4 = s1;
	reverse(s4.begin(), s4.begin() + 4);
}

