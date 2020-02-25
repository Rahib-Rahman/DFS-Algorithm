#include<bits/stdc++.h>
#define mxn 10000

using namespace std;

vector< int > graph[mxn];
int start_node, goal_node, parent_node[mxn];
bool visited[mxn];

int getParentNode(int node)
{
    return parent_node[node];
}

void path(int current_node)
{
    if(current_node == start_node)
    {
        printf("%d",current_node);
        return;
    }
    path(getParentNode(current_node));
    printf("->%d",current_node);
}

bool DFS(int current_node)
{
    if(current_node == goal_node)
        return true;
    visited[current_node] = true;
    int number_of_children = graph[current_node].size();
    for(int i=0; i<number_of_children; i++)
    {
        int child_node = graph[current_node][i];
        if(!visited[ child_node ])
        {
            parent_node[child_node] = current_node;
            if(DFS(child_node))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    freopen("DFS_input.txt","r", stdin);

    int number_of_nodes, number_of_edges, edge_start, edge_end;
    printf("Enter the number of Nodes : ");
    scanf("%d",&number_of_nodes);
    printf("Enter the number of Edges : ");
    scanf("%d",&number_of_edges);
    printf("Enter the Edges : \n");

    for(int i=1; i<=number_of_edges; i++)
    {
        scanf("%d %d",&edge_start ,&edge_end);
        graph[edge_start].push_back(edge_end);
        graph[edge_end].push_back(edge_start);
    }

    printf("\nEnter start node : ");
    scanf("%d",&start_node);
    printf("Enter goal node : ");
    scanf("%d",&goal_node);

    printf("\nUsing DFS");
    if(DFS(start_node))
    {
        printf("\npath from start to goal node : ");
        path(goal_node);
        printf("\n");
    }
    else
    {
        printf("\nThere is no path from start to goal node.\n");
    }
    return 0;
}
