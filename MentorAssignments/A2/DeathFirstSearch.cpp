#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Graph
{ // mycode
    vector<vector<int>> mapping;
    queue<int> travel;
    vector<bool> isVisited;
    vector<int> gateways;
    Graph(int n)
    {
        vector<int> row(n, 0);
        for (size_t i = 0; i < n; i++)
        {
            mapping.push_back(row);
            isVisited.push_back(false);
        }
    };
    void addLink(int n1, int n2)
    {
        mapping[n1][n2] = 1;
        mapping[n2][n1] = 1;
    };
    void removeLink(int n1, int n2)
    {
        mapping[n1][n2] = 0;
        mapping[n2][n1] = 0;
        cout << n1 << ' ' << n2 << endl;
    };
    void fillQ(vector<int> copyOfGateways)
    {
        while (!copyOfGateways.empty())
        {
            int currentGateway = copyOfGateways.back();
            travel.push(currentGateway);
            isVisited[currentGateway] = true;
            for (size_t j = 0; j < mapping[currentGateway].size(); j++)
            {
                if (mapping[currentGateway][j] ==1 && !isVisited[j])
                {
                    travel.push(j);
                    isVisited[j] = true;
                }
            }
            copyOfGateways.pop_back();
        }
    }
    void BFS_one_healing(int virus)
    {
        bool endOfTurn{false};
        for (size_t i = 0; i < gateways.size(); i++)
        {
            if (isLink(virus, gateways[i]))
            {
                endOfTurn = true;
                removeLink(virus, gateways[i]);
                break;
            }
        }

        if (!endOfTurn)
        {
            int current = travel.front();
            for (size_t i = 0; i < mapping[current].size(); i++)
            {
                if (i == (mapping[current].size() - 1))
                {
                    travel.pop();
                }
                if (isLink(current, i))
                {
                    removeLink(current, i);
                    break;
                }
            }
        }
    };
    bool isLink(int n1, int n2)
    {
        return mapping[n1][n2];
    }
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
vector<Graph> mapping;
int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e;
    cin.ignore();
    Graph g(n); // my code
    for (int i = 0; i < l; i++)
    {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2;
        cin.ignore();
        g.addLink(n1, n2); // my code
    }

    
    for (int i = 0; i < e; i++)
    {
        int ei; // the index of a gateway node
        cin >> ei;
        cin.ignore();
        g.gateways.push_back(ei);
    }
    g.fillQ(g.gateways); //my code
    // game loop
    while (1)
    {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si;
        cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        g.BFS_one_healing(si);
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        // cout << "0 1" << endl;
    }
}
