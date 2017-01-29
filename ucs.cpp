#include <iostream>
#include<bits/stdc++.h>
#include <ctype.h>
using namespace std;
typedef vector <int> vi;
typedef vector <long long> vill;

#define sc(a) scanf("%d",&a)
#define scll(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfll(a) printf("%I64d\n",a)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb(a) push_back(a)
#define fore(i,a,b) for(i=a;i<b;i++)
typedef pair<int,int> ii;
vector< pair < int, int > > adj[25];
bool visited[25];
int val=0;

    priority_queue<ii,vector<ii>, greater<ii> > Q;

//priority_queue < pair<int,int> > Q;
 int ucs(int s,int val){
    int i;
    Q.push(make_pair(0,s));
    while(!Q.empty()){
        pair<int,int> p=Q.top();
        Q.pop();
        if(visited[p.second]==true)
            continue;
        visited[p.second]=true;
        cout<<p.second<<" "<<val<<" " ;
        val+=p.first;
        cout<<p.first<<" "<<val<<"\n";

       fore(i,0,adj[p.second].size()){
        if(visited[adj[p.second][i].first]==false){
            Q.push(make_pair(adj[p.second][i].second,adj[p.second][i].first));

        }
    }

}
return val;
}

int main(){
int nodes, edges,i,c,k=0,pathcost;
string temp1,temp;



edges=23*3;

map < string, int > cities;
map < string, int >::iterator it;
fore(i,0,edges){
    cin>>temp;
    if(isalpha(temp[0])){

            it=cities.find(temp);
            if(it==cities.end()){
                cities[temp]=k;
                k++;
                cout<<"\n"<<k<<"\n";
            }
    }

}
edges=23;
fore(i,0,edges){
cin>>temp;
cin>>temp1;
cin>>pathcost;
adj[cities[temp]].push_back(std::make_pair(cities[temp1],pathcost));
adj[cities[temp1]].push_back(std::make_pair(cities[temp],pathcost));

}

nodes=20;


fore(i,0,nodes){
visited[i]=false;
}
val=0;
val=ucs(0,0);


cout<<"uniform cost search complete";
cout<<"\ncost="<<val;
return 0;
}
/*
Arad Zerind 75
Arad Timisoara 118
Arad Sibiu 140
Zerind Oradea 71
Oradea Sibiu 151
Timisoara Lugoj 111
Lugoj Mehadia 70
Mehadia Drobeta 75
Drobeta Craiova 120
Craiova RimnicuVilcea 146
Craiova Pitesti 138
Sibiu Fagaras 99
Sibiu RimnicuVilcea 80
RimnicuVilcea Pitesti 97
Fagaras Bucharest 211
Pitesti Bucharest 101
Bucharest Urziceni 85
Bucharest Giurgiu 90
Urziceni Vaslui 142
Vaslui Iasi 92
Iasi Neamt 87
Urziceni Hirsova 98
Hirsova Eforie 86*/
