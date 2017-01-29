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

vector< pair < int, int > > adj[20];
map < int , string > city;
vector<int> parent(20,-1);
bool visited[20];
int val=0;

void dfs(int s, int g){
    int i;

    static int t=s;
    if(s==g){
        int j=0;
        vector <int> path;
        int x=s;
        while(x!=t){
            path.push_back(x);
            x=parent[x];
            }
        path.push_back(t);
        j=path.size()-1;
        cout<<"\n";
        while(j>0){
            cout<<city[path[j]]<<"->>";
            for(int k=0;k<adj[path[j]].size();k++){
                if(adj[path[j]][k].first==path[j-1]){
                    val+=adj[path[j]][k].second;

                    }
                }
        j--;
        }
        cout<<city[g];
        cout<<"\ncost="<<val;
        fore(i,0,20){
        visited[i]=true;
        }

    }




if(!visited[s]){
        visited[s]=true;


    fore(i,0,adj[s].size()){
        if(visited[adj[s][i].first]==false){
            parent[adj[s][i].first]=s;
            cout<<val<<" " ;

            dfs(adj[s][i].first,g);
            cout<<adj[s][i].second<<" "<<val<<"\n";

        }
    }

}

}


int main(){
freopen("input.txt","r",stdin);
int nodes, edges,i,c,k=0,pathcost;
string temp1,temp;



edges=23;

map < string, int > cities;
map < string, int >::iterator it;

fore(i,0,edges){
    cin>>temp;
    cin>>temp1;
    cin>>pathcost;



            it=cities.find(temp);
            if(it==cities.end()){
                cities[temp]=k;
                city[k]=temp;
                k++;
                cout<<"\n"<<k<<"\n";
            }
            it=cities.find(temp1);
            if(it==cities.end()){
                cities[temp1]=k;
                city[k]=temp1;
                k++;
                cout<<"\n"<<k<<"\n";
            }


            adj[cities[temp]].push_back(std::make_pair(cities[temp1],pathcost));
            adj[cities[temp1]].push_back(std::make_pair(cities[temp],pathcost));


}


nodes=k;

string source,goal;

cin>>source;
cin>>goal;
fore(i,0,nodes){
visited[i]=false;
}


dfs(cities[source],cities[goal]);


cout<<"\ndfs complete";
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
Hirsova Eforie 86
Arad
Bucharest*/
