#include<iostream>
using namespace std;

const int maxn =105;
int p[maxn];/*矩阵的维数*/
int m[maxn][maxn];/*最优值，最少乘法次数*/
int s[maxn][maxn];/*断开的位置*/
int n;/*p的长度*/
 
void matrixChain(){ /*计算最优值*/
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;i++){
            int j=r+i-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;k++){
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j]){
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}
 
void trackBack(int i,int j)
{/*求最优计算次序,从1~n-1*/
    if(i==j) return;
    trackBack(i,s[i][j]);
    trackBack(s[i][j]+1,j);
    cout<<"Multiply A"<<i<<","<<s[i][j];
    cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}
 
int main()
{
    cin>>n;
        for(int i=0;i<=n;i++)
            cin>>p[i];
        matrixChain();
        trackBack(1,n);/*矩阵连乘最优计算次序*/
        cout<<m[1][n];
    return 0;
}

