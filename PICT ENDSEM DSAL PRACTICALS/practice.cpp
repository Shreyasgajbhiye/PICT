#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* next;
    int dest;
};
class Graph{
    public:
    node** adjList;
    string * places;
    int count;

    int getIndex(string str){
        for(int i=0;i<count;i++){
            if(places[i] == str) return i;
        }
        return -1;
    }
    Graph(){
        cout << "ENter the number of nodes : " << endl;
        cin >> count;

        adjList = new node*[count];
        places = new string[count];

        for(int i=0;i<count;i++){
            adjList[i] = NULL;
        }
        for(int i=0;i<count;i++){
           cout << "Enter the place for " << i+1 << endl;
           cin>> this->places[i];
        }

        for(int i=0;i<count;i++){
            int j=0;
            int cnt;
            cout << "Enter the adjacency for " << places[i] << endl;
            cin >> cnt;

            while(j<cnt){
                string str;
                cout << "Enter for places : " << endl;
                cin >> str;

                int index = getIndex(str);

                node* n = new node;
                n->dest = index;

                node* ptr = adjList[i];
                n->next  = ptr;
                adjList[i] = n;
                
                j++;
            }
        }
    }

    void display(){
        for(int i=0;i<count;i++){
            string str;
            str = places[i];
            cout << str << " -> ";

            node* ptr = adjList[i];
            while(ptr != NULL){
                cout << places[ptr->dest] << " ";
                ptr = ptr->next;
            }

            cout << "-> NULL" << endl;
        }

    }

    void bfs(int src){
        bool *visited = new bool[count];
        for(int i=0;i<count;i++){
            visited[i] = false;
        }
        visited[src] = true;
        deque<int> dq;

        dq.push_back(src);
        while(!dq.empty()){
            int curr = dq.front();
            dq.pop_front();

            cout << places[curr] << " ";
            visited[curr] = true;

            node* ptr = adjList[curr];
            while(ptr != NULL){
                int neigh = ptr->dest;
                if(!visited[neigh]){
                    visited[neigh] = true;
                    dq.push_back(neigh);
                }
                ptr= ptr->next;
            }
        }
         cout << endl;

    }
};
int main()
{
    Graph *g = new Graph;
    g->display();
    g->bfs(2);
    return 0;
}