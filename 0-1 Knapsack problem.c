#include<stdio.h>
struct woodType
{
char name[10][10];
int st,wt;
};
int max(int a, int b)
{
return (a > b)? a : b;
}
int knapSack(int m,struct woodType *p,int n)
{
int i, w;
int K[n+1][m+1];
for(i=0;i<=n;i++)
for(w = 0; w <= m; w++)
if(i==0 || w==0)
K[i][w] = 0;
else if(p[i-1].wt <= w)
K[i][w] = max(p[i-1].st + K[i-1][w-p[i-1].wt],K[i-1][w]);
else
K[i][w] = K[i-1][w];
printf("\n\n");
for(i=0;i<=n;i++) {
for(w=0;w<=m;w++)
printf("%-2d\t",K[i][w]);
printf("\n");
}
printf("\nSelecting : ");
i=n;w=m;
while(i>0 && w>0)
if(K[i][w] != K[i-1][w])
{
printf("%s ",p[i-1].name);
w = w-p[i-1].wt;
i--;
}
else
i--;
return K[n][m];
}
void main()
{
int i,j,n,m,maxStrength=0;
struct woodType p[100],temp;
printf("\nEnter maximum weight of Sofa : ");
scanf("%d",&m);
printf("\nEnter number of types of Wood : ");
scanf("%d",&n);
printf("\nTHE MAXIMUM WEIGHT OF SOFA IS %d KILOGRAMS AND THE TYPES OF WOODAVAILABLE ARE %d\n",m,n);

printf("\nEnter the name, total strength, maximum weight available of that wood : \n");
for(i=0;i<n;i++)
scanf("%s %d %d",p[i].name,&p[i].st,&p[i].wt);

for(i=0;i<n-1;i++)
for(j=0;j<n-1-i;j++)
if(p[j].wt < p[j+1].wt)
{
temp = p[j];
p[j] = p[j+1];
p[j+1] = temp;
}
maxStrength = knapSack(m,p,n);
printf("\nMaximum Strength we can get for making sofa is : %d lbf",maxStrength);
}
