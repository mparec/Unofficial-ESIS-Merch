#include <iostream>
#include <string>
using namespace std;
int main(){
    int A[99][99],n,sum,m;
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>n;
    cout<<"Ingrese el numero de columnas de la matriz: ";
    cin>>m;
    sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Ingrese el valor de la posicion ["<<i<<"]["<<j<<"]: ";
            cin>>A[i][j];
            sum+=A[i][j];
        }
    }
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"La suma de los elementos de la matriz es: "<<sum<<endl;
    return 0;
}