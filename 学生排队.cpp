 #include <stdio.h>
#define N 1000
int a[N+1];   
int find(int sno)
{
    int i;
    for(i = 1; a[i] != sno; i++)
        ;
    return i;
}
 
int main(void)
{
    int n, m, p, q, i, j;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
        a[i] = i;
 
    // 模拟移动过程
    for(i=1; i<=m; i++) {
        scanf("%d%d", &p, &q);
 
        int pos = find(p);
        if(q > 0) {
            for(j=pos; j<pos+q; j++)
               a[j] = a[j + 1];
            a[pos + q] = p;
        } else {
            for(j=pos; j>pos+q; j--)
               a[j] = a[j - 1];
            a[pos + q] = p;
        }
    }
   
    for(i=1; i<=n; i++)
        printf(" %d", a[i]);
    printf("\n");
 
    return 0;
} 

