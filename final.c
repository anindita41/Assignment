#include <stdio.h>

int maximal_network_rank(int n, int cables[][2], int cable_num)
{
    int max_rank = 0;
    int rank[100] = {0};
    int connected[100][100] = {0};

    for (int i = 0; i < cable_num; i++)
    {
        int a = cables[i][0];
        int b = cables[i][1];
        rank[a]++;
        rank[b]++;
        connected[a][b] = 1;
        connected[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int curr_rank = rank[i] + rank[j];
            if (connected[i][j])
            {
                curr_rank--;
            }
            if (curr_rank > max_rank)
            {
                max_rank = curr_rank;
            }
        }
    }
    return max_rank;
}

int main() {
    int n, cables[50*101][2], cable_num;
    printf("Enter the number of labs present: ");
    scanf("%d",&n);
    printf("Enter the number of cables: ");
    scanf("%d",&cable_num);
    printf("Enter the connections:\n");
    for(int i=0;i<cable_num;i++)
        scanf("%d %d",&cables[i][0], &cables[i][1]);
    int max_rank = maximal_network_rank(n, cables, cable_num);
    printf("%d",max_rank);
    return 0;
}
