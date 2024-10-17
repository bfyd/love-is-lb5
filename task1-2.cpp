#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100  



void generate_matrix(int n, float p, int adjacency_matrix[MAX_VERTICES][MAX_VERTICES]) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if ((float)rand() / RAND_MAX < p) {  
                adjacency_matrix[i][j] = 1;
                adjacency_matrix[j][i] = 1;  
            }
        }
    }
}


void print_matrix(int n, int adjacency_matrix[MAX_VERTICES][MAX_VERTICES]) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void counter_matrix(int n, int adjacency_matrix[MAX_VERTICES][MAX_VERTICES])
{
    int counter = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < i + 1;j++)
        {
            if (adjacency_matrix[i][j] == 1)
            {
                counter++;
            }
        }
    }
    printf("ribs: %i\npeaks: %i\n", counter, n);
}
int main() {
    int n; 
    float p; 
    int matrix[MAX_VERTICES][MAX_VERTICES];
    
    srand(time(NULL));

    
    printf("Input count of peaks (no more % d) : ", MAX_VERTICES);
    scanf("%d", &n);
    if (n > MAX_VERTICES) {
        printf("Count of peaks then max count.\n");
        return 1;
    }

    printf("Enter the probability of having an edge (0.0 to 1.0):");
    scanf("%f", &p);
    if (p < 0.0 || p > 1.0) {
        printf("The probability should be in the range from 0.0 to 1.0.\n");
        return 1;
    }

    
    generate_matrix(n, p, matrix);

   
    print_matrix(n, matrix);
    counter_matrix(n, matrix);
    return 0;
}
