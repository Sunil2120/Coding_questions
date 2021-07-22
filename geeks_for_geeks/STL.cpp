

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>


using namespace std;



int main()
{
	vector<int> A = {12,4,2,1};
	cout << A[2] << endl;
	sort(A.begin(),A.end());//sorting O(nlogn)
	//binary search

	bool present = binary_search(A.begin(),A.end(),12);//true

	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);

	//1,2,4,12,100,100,100,100,123
	//log(n)
	auto index = lower_bound(A.begin(),A.end(),100);// first element >=  
	auto index2 = upper_bound(A.begin(),A.end(),100);// gives element which is strictly greater >  
	cout << *index << " " << *index2 << endl;
	cout << index-A.begin() << " " << index2-A.begin() << endl;//get the indices


	bool compare(int a,int b)
	{
		if( a > b)
		{
			return true;
		}
		return false;
	}
	//sort in decreasing order
	sort(A.begin(),A.end(),compare);


	//set maintains internally ascending order, no duplicates
	set<int> s;
	s.insert(10);
	s.insert(8);
	s.insert(1);
	for(auto x: s)
	{
		cout << *x << endl;
	}
	//1,8,10
	// insertion time O(logn)
	// erasing time O(logn)

	auto it = s.find(10);
	if(it!=s.end())//present
	else // not present

	auto it2 = s.lower_bound(10);>=
	auto it3 = s.upper_bound(20);>

	//log(n)
	s.erase(10);// element
	s.remove(it2);//iterator

	//map
	map<int,int> A;
	A[1]=100;
	A[10]=1039;

	//logN

	A.erase(key);
	A.find(key)!=A.end();// present
	




	






	return 0;
}