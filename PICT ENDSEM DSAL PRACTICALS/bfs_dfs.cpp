#include "iostream"
#include "stack"
#include "deque"
#define INF 1e9
using namespace std;

class Node
{
private:
    int dest;
    Node *next;

    friend class Graph;

public:
};

class Graph
{
private:
    string *places;
    Node **adjList;
    int count;

public:
    int getIndex(string str)
    {
        int i = 0;

        while (i < count)
        {
            if (this->places[i] == str)
                return i;

            i++;
        }

        return -1;
    }
    Graph()
    {
        cout << "Enter No. of Nodes in Graph : ";
        cin >> this->count;

        places = new string[count];
        adjList = new Node *[count];

        for (int i = 0; i < this->count; i++)
        {
            adjList[i] = NULL;
        }

        for (int i = 0; i < this->count; i++)
        {
            cout << "Enter Name of Place " << i + 1 << " : ";
            cin >> this->places[i];
        }

        for (int i = 0; i < this->count; i++)
        {
            int adjCnt = 0;
            cout << "Enter No. of Places Adjacent to " << this->places[i] << " : ";
            cin >> adjCnt;

            int j = 0;

            while (j < adjCnt)
            {
                string adjPlc = "";

                cout << "Enter Place " << j + 1 << " : ";
                cin >> adjPlc;

                int index = getIndex(adjPlc);

                if (index == -1)
                    continue;

                Node *n = new Node();
                n->dest = index;

                Node *ptr = adjList[i];

                n->next = ptr;
                adjList[i] = n;

                j++;
            }
        }
    }

    void display()
    {
        cout << "Adjacency List Representation of the Graph : " << endl;

        for (int i = 0; i < count; i++)
        {
            Node *ptr = this->adjList[i];
            string str = places[i];

            cout << str << " -> ";

            while (ptr != NULL)
            {
                cout << this->places[ptr->dest] << " ";
                ptr = ptr->next;
            }

            cout << "-> NULL" << endl;
        }
    }

    void bfs(int src)
    {
        bool *visited = new bool[this->count];

        for (int i = 0; i < this->count; i++)
            visited[i] = false;

        visited[src] = true;

        deque<int> dq;
        dq.push_back(src);
        while (!dq.empty())
        {
            int curr = dq.front();
            dq.pop_front();

            cout << places[curr] << " ";
            visited[curr] = true;

            Node *ptr = adjList[curr];

            while (ptr != NULL)
            {
                int neighbour = ptr->dest;
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    dq.push_back(neighbour);
                }
                ptr = ptr->next;
            }

            cout << endl;
        }
    }
    void dfs(int src)
    {
        bool *visited = new bool[this->count];

        for (int i = 0; i < this->count; i++)
            visited[i] = false;

        visited[src] = true;

        stack<int> st;
        st.push(src);
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();

            cout << places[curr] << " ";
            visited[curr] = true;

            Node *ptr = adjList[curr];
            while (ptr != NULL)
            {
                int neighbour = ptr->dest;
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    st.push(neighbour);
                }

                ptr = ptr->next;
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph *g = new Graph();
    g->display();

    int ch = 0;

    while (true)
    {
        cout << "!. Display Graph" << endl;
        cout << "2. BFS Traversal" << endl;
        cout << "3. DFS Traversal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            g->display();
        }
        break;
        case 2:
        {
            string src;
            cout << "Enter Start Node : ";
            cin >> src;

            g->bfs(g->getIndex(src));
        }
        break;
        case 3:
        {
            string src;
            cout << "Enter Start Node : ";
            cin >> src;

            g->dfs(g->getIndex(src));
        }
        break;
        case 4:
        {
            return 0;
        }
        break;
        default:
            cout << "Please Enter Valid Input !!" << endl;
        }
    }

    return 0;
}