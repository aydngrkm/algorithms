#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Number of vertices in the graph (You can change this value)
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    int min_dist = INT_MAX, vertex = -1;

    for (int i = 0; i < V; ++i) {
        if (sptSet[i] == false && dist[i] < min_dist) {
            min_dist = dist[i];
            vertex = i;
        }
    }

    return vertex;
}
 
// A utility function to print the constructed distance
// array
void printSolutionMatrix(int matrix[V][V])
{
    int i, j;
    printf ("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t\n") ;
    printf ("\t--\t--\t--\t--\t--\t--\t--\t--\t--\t\n") ;
    for ( i = 0; i < V ; i ++) 
    {
        printf ("%d|\t", i + 1);
        for (j = 0; j < V ; j ++) 
        {
            if (matrix[i][j] == INT_MAX)
            printf ("INF\t") ;
            else if (matrix[i][j] == 0)
            printf ("-\t") ;
            else
            printf ("%d\t", matrix[i][j]);
        }
        printf ("\n") ;
    }
    printf ("\n") ;
}
 
// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
// returns cost matrix

void dijkstra_helper(int graph[V][V], int source, int cost[V][V])
{
    int dist[V]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i
    
    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        cost[source][i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[source] = 0;
    cost[source][source] = 0;

    //TODO: Calculate the cost matrix
    for (int count = 0; count < V-1; ++count)
    {
        int vertex = minDistance(dist, sptSet);
        sptSet[vertex] = true;

        for (int i = 0; i < V; ++i) {
            if (graph[vertex][i] != 0 && sptSet[i] == false && dist[vertex] != INT_MAX) {
                int curr_dist = dist[vertex] + graph[vertex][i];
                if (curr_dist < dist[i]) {
                    dist[i] = curr_dist;
                    cost[source][i] = curr_dist;
                }
            }   
        }
    }
}

int dijkstra(int graph[V][V], int source , int dest) {
    int cost[V][V];

    for (int src = 0; src < V; ++src) {
        dijkstra_helper(graph, src, cost);
    }

    printf ("(Cost Matrix):\n") ;
    printSolutionMatrix(cost) ;
    
    return cost[source-1][dest-1];
}

int main() 
{
    printf ("\nCities:\n") ;

    char cities[V][11] = { "Gaziantep", "Adana", "Izmir", "Eskisehir", "Ankara", "Antalya", "Trabzon", "Kars", "Istanbul"};

    for ( int i = 0; i < V ; i ++)
        printf ( "%d.%s\n" , i + 1 , cities[i]);

    int graph1[V][V] = {    { 0 ,10 ,0 ,0 ,0 ,0 ,0 ,40 ,0 } ,
                            { 10 ,0 ,10 ,0 ,0 ,0 ,0 ,0 ,30 } ,
                            { 0 ,10 ,0 ,20 ,100 ,0 ,0 ,0 ,100 } ,
                            { 0 ,0 ,20 ,0 ,30 ,0 ,0 ,0 ,0 } ,
                            { 0 ,0 ,100 ,30 ,0 ,50 ,0 ,0 ,30 } ,
                            { 0 ,0 ,0 ,0 ,50 ,0 ,0 ,0 ,50 } ,
                            { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,30 ,70 } ,
                            { 40 ,0 ,0 ,0 ,0 ,0 ,30 ,0 ,20 } ,
                            { 0 ,30 ,100 ,0 ,30 ,50 ,70 ,20 ,0 } };



    int graph2[V][V] = {    { 0 ,20 ,0 ,0 ,0 ,0 ,0 ,20 ,0 } ,
                            { 20 ,0 ,40 ,0 ,0 ,0 ,0 ,0 ,30 } ,
                            { 0 ,40 ,0 ,30 ,100 ,0 ,0 ,0 ,15 } ,
                            { 0 ,0 ,30 ,0 ,10 ,0 ,0 ,0 ,0 } ,
                            { 0 ,0 ,100 ,10 ,0 ,30 ,0 ,0 ,20 } ,
                            { 0 ,0 ,0 ,0 ,30 ,0 ,0 ,0 ,50 } ,
                            { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,60 ,60 } ,
                            { 20 ,0 ,0 ,0 ,0 ,0 ,60 ,0 ,20 } ,
                            { 0 ,30 ,15 ,0 ,20 ,50 ,60 ,20 ,0 } };


    int src = 0 , dst = 0;
    char * token;
    int values[50];
    char input[30];
    int i = 0;
    printf ("\nFrom and To? (Please enter the city code): ");
    scanf ("%s" , &input) ;
    token = strtok(input, "-");

    while (token != NULL) {
        // Convert the token to an integer and store it in the values array
        values[i] = atoi(token);
        // Move to the next token
        token = strtok(NULL, "-");
        i++;
    }

    src = values[0];
    dst = values[1];

    printf ("\n1st option ") ;
    int cost1 = dijkstra(graph1, src, dst) ;
    printf ("\n2nd option ") ;
    int cost2 = dijkstra(graph2, src, dst) ;


    if ( cost1 < cost2 )
        printf ("The best option for the flight %s-%s is the first one (%d < %d)\n" , cities[src - 1], cities[dst - 1] , cost1, cost2);

    else if ( cost1 == cost2 )
        printf ("They offer the same price for the flight %s-%s (%d), choose one of them\n", cities[src - 1], cities[dst - 1], cost1);

    else
        printf ("The best option for the flight %s-%s is the second one (%d < %d)\n", cities[src - 1], cities[dst - 1], cost2, cost1);


    return 0;

}