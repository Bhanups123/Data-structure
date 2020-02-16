#include<iostream>
#include<set>
using namespace std;
int main(){
	set<pair<set<int>, int> > s;
	set<int> sb;
	sb.insert(3);
	sb.insert(2);
	auto a = make_pair(sb, 1);
	s.insert(a);
	//
	set<int> sb1;
	sb1.insert(2);
	sb1.insert(4);
//	pair<int , int> p1;
	auto p1 = make_pair(sb1, 3);
	s.insert(p1);
	
	for(auto at:s)
		cout<<(at).second;
}
