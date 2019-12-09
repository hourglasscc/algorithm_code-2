#include<iostream>
using namespace std;

const int maxn =105;
int p[maxn];/*�����ά��*/
int m[maxn][maxn];/*����ֵ�����ٳ˷�����*/
int s[maxn][maxn];/*�Ͽ���λ��*/
int n;/*p�ĳ���*/
 
void matrixChain(){ /*��������ֵ*/
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
{/*�����ż������,��1~n-1*/
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
        trackBack(1,n);/*�����������ż������*/
        cout<<m[1][n];
    return 0;
}

