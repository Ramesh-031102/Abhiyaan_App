// Assumed each row is sorted in increasing order.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int f = 0; 
void Binary_Search(int a[][MAX], int m, int n, int k, int h){  
    int l = 0, r = n-1, mid;
    while(l <= r){
        mid = (l + r)/ 2;
        if(a[h][mid] == k){
            f = 1;
            cout<<"True"<<endl;
            cout <<h<<" "<<mid<< endl;
            return;
        }
        if (a[h][mid] > k)
            r = mid - 1;
        if (a[h][mid] < k)
            l = mid + 1;
    }
}

void Element_Row(int a[][MAX],int m,int n,int k){
    int l = 0, r = m-1, mid;
    while(l <= r){
        mid = (l + r)/ 2;
        if (k == a[mid][0]){
            f = 1;
            cout<<"True"<<endl;
            cout<<mid<<" "<<0<< endl;
            return;
        }
        if (k == a[mid][n - 1]){
            f = 1;
            int c = m - 1;
            cout<<"True"<<endl;
            cout<<mid<<" "<<c<< endl;
            return;
        }
        if (k > a[mid][0] && k < a[mid][m - 1]){
            Binary_Search(a, m, n, k, mid);
            return;
        }
        if (k < a[mid][0])
            r = mid - 1;
        if (k > a[mid][m - 1])
            l = mid + 1;
    }
}

int main(){
    int m, n, k;
    cin>>m>>n>>k;
    int a[m][n];
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++)
            cin>>a[i][j];
    Element_Row(a, m, n, k);
    if(f == 0)
       cout<<"False"<<endl;
    return 0;
}

