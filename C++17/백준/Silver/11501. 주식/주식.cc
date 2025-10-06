#include <stdio.h>
int graph[1000001];
int main() {
    int T,i,N,m;
    long rev;
    scanf("%d",&T);
    while(i++ < T) {
        scanf("%d",&N);
        for(int j = 0; j < N; j++)
            scanf("%d",&graph[j]);
        
        m = graph[N-1],rev = 0;
        
        for(int j = N-2; j >= 0; j--)
            if (m > graph[j])
                rev += m - graph[j];
            else
                m = graph[j];
        printf("%ld\n",rev);
    }

        return 0;   
    }