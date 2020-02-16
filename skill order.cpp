#include <iostream>
#include <algorithm>
using namespace std;
struct skill{
    int s;
    int p;
};
int comp(skill x, skill y){
    return x.s<y.s;
}
int main() {
	// your code goes here
	int t, i, it;
	skill s1[3], s2[3], s3[3];
	cin>>t;
	
	while(t>0){
		t--;
	    for(i=0; i<3; i++){
	        cin>>s1[i].s>>s2[i].s>>s3[i].s;
	        s1[i].p = s2[i].p = s3[i].p = i;
	    }
	  sort(s1, s1 + 3, comp);
	  sort(s2, s2 + 3, comp);
	  sort(s3, s3 + 3, comp);
	  it=0;
//	  for(auto z:s1)
//	  	cout<<z.p<<" ";
//	cout<<endl;
//	  for(auto z:s2)
//	  	cout<<z.p<<" ";
//	cout<<endl;
//	  for(auto z:s3)
//	  	cout<<z.p<<" ";
	  for(i=0; i<3; i++){
	      if(s1[i].p ==s2[i].p || s1[i].s ==s2[i].s && s2[i].p== s3[i].p || s2[i].s ==s3[i].s){
	        it = 1;
		  }
	      else{
	        it= 0;
	        break;
	       }
	  }
	  if(it==0){
	    cout<<"no"<<endl;
	    continue;
	  }
	  for(i=0; i<2; i++){
	      it = s1[i+1].s - s1[i].s + s2[i+1].s - s2[i].s + s3[i+1].s - s3[i].s;
	      if(it==0){
	        cout<<"no"<<endl;
	        break;
	      }
	  }
	  if(it!=0)
	  	cout<<"yes"<<endl;
	}
	return 0;
}
