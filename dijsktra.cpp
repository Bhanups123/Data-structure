#include<iostream>
#include<set>
#include<vector>
#include<climits>
using namespace std;
bool min_vertex(int v, int *cost, bool *visited){
    int min_index=-1;
    int min = 999;
    for(int i=0;i<v;i++){
        if(!visited[i] and cost[i]<min){
            min = cost[i];
            min_index=i;
        }

    }
    return min_index;
}
void dijkstra(int n, int s, vector< vector<int>> v, int* min_cost){
	int i, j, min_ver, dist;
	bool visited[n];
	for(i=0; i<n; i++){
		visited[i] = false;
		min_cost[i] = INT_MAX;
	}
	min_cost[s] = 0;
	for(i =0; i<n-1; i++){
		min_ver = min_vertex(n, min_cost, visited);
		visited[min_ver] = true;
		for(j = 0; j<n; j++){
			if(v[min_ver][j]!=0 and visited[j] == false){
				dist = min_cost[min_ver] + v[min_ver][j];
				if(dist<min_cost[j])
					min_cost[j] = dist;
			}
		}
	}
}

void roadsInHackerland(int n, vector<vector<int>> roads) {

    int sum = 0, min_cost[n], j;
    set<pair<set<int>, int> > s;
    set<int> sb;
    for(int i = 0; i<n; i++){
        dijkstra(n, i, roads, min_cost);
        for(j = 0; j<n; j++){
            if(i!=j){
                sb.insert(i);
                sb.insert(j);
                s.insert(make_pair(sb, min_cost[j]));
                sb.clear();
            }
        }
    }
//    auto x = s.begin();
    cout<<s.size()<<endl;
//    
   for(auto x:s)
      cout<< x.second <<" ";
   cout<<endl;
 //   string asd = "101010";
    //atol(sum, asd, 2);
   // return asd;
}
int main(){
	int n, e, i, a, b, cost;
	
	cout<<"enter no. of vertex and edges"<<endl;
	cin>>n>>e;
	
	vector< vector<int> > v(n, vector<int> (n,0));
	int min_cost[n];
	
	cout<<"u v cost"<<endl;
	for(i = 0; i<e; i++){
		cin>>a>>b>>cost;
		v[a][b] = cost;
		v[b][a] = cost;
	}
//	dijkstra(n, 0, v, min_cost);
	roadsInHackerland(n, v);
//	for(i =0; i<n; i++)
//		cout<<min_cost[i]<<" ";
}
