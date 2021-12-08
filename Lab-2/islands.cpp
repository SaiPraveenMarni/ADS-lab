#include<stdio.h>
int parent[100];
int n;
int m;

int find(int x)
{
    if(x!=parent[x])
        return find(parent[x]);
    return parent[x];
}

void union_set(int e1,int e2)
{
    int root1=find(e1);
    int root2=find(e2);

    if(root1!=root2)
    {
        parent[root1]=parent[root2];
    }

}
void assign_array(int n)
{
    int size=n;
    for(int i=0;i<n;i++)
    {

        parent[i]=i;
    }
}
int count_island(int mat[n][m],int n,int m)
{
    int size=n*m;
    assign_array(size);
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<m;k++)
        {
            if(mat[j][k]==0)
                continue;
            if (j+1 < n && mat[j+1][k]==1)
                union_set(j*(m)+k, (j+1)*(m)+k);
            if (j-1 >= 0 && mat[j-1][k]==1)
                union_set(j*(m)+k, (j-1)*(m)+k);
            if (k+1 < m && mat[j][k+1]==1)
                union_set(j*(m)+k, (j)*(m)+k+1);
            if (k-1 >= 0 && mat[j][k-1]==1)
                union_set(j*(m)+k, (j)*(m)+k-1);
            if (j+1<n && k+1<m && mat[j+1][k+1]==1)
                union_set(j*(m)+k, (j+1)*(m)+k+1);
            if (j+1<n && k-1>=0 && mat[j+1][k-1]==1)
                union_set(j*m+k, (j+1)*(m)+k-1);
            if (j-1>=0 && k+1<m && mat[j-1][k+1]==1)
                union_set(j*m+k, (j-1)*m+k+1);
            if (j-1>=0 && k-1>=0 && mat[j-1][k-1]==1)
                union_set(j*m+k, (j-1)*m+k-1);
        }

    }
    int cnt[size];
    int number_of_islands=0;
    for(int i=0;i<size;i++)
    {
        cnt[i]=0;
    }
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<m;k++)
        {
            if(mat[j][k]==1)
            {
                int x=find(j*m+k);
                if(cnt[x]==0)
                {
                    number_of_islands++;
                    cnt[x]++;
                }
                else
                {
                    cnt[x]++;
                }
            }
        }
    }
    return number_of_islands;
}
int main()
{

    printf("Enter the dimensions of the matrix\n");
    scanf("%d",&n);
    scanf("%d",&m);
    int mat[n][m];
    printf("Enter the entries of the matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int ans=count_island(mat,n,m);
    printf("Number of islands are %d\n",ans);
}
