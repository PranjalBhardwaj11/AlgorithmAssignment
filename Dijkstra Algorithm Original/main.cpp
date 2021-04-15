//
//  Original.cpp
//  Dijkstra Algorithm
//
//  Created by Pranjal Bhardwaj on 12/04/21.
//

#include<iostream>
using namespace std;

int minimumDist(int dist[], bool Tset[]){
    int min=INT_MAX,index = 0;
    for(int i=0;i<8;i++){
        if(Tset[i] == false && dist[i] <= min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int graph[8][8],int src){
    int dist[8];
    bool Tset[8];
    for(int i = 0;i < 8;i++){
        dist[i] = INT_MAX;
        Tset[i] = false;
    }
    dist[src] = 0;
    for(int i = 0; i<8; i++){
        int m = minimumDist(dist,Tset);
        Tset[m] = true;
        for(int i = 0;i < 8; i++){
            if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
                dist[i]=dist[m]+graph[m][i];
        }
    }
    cout<<"Vertex\t\tDistance from source"<<endl;
    for(int i = 0; i<8; i++){
        char str=65+i;
        cout<<str<<"\t\t\t"<<dist[i]<<endl;
    }
}

int main(){
    cout << "Original Algorithm" << endl;
    int graph[8][8]={
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, -3, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, -5},
        {2, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 1, 0, 0, 2},
        {0, 0, 0, 0, 1, 0, 0, 0}};
    Dijkstra(graph,0);
    return 0;
}
