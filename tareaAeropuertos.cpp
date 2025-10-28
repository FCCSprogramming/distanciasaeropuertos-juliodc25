/* 
 Matriz distancia entre aeropuertos

 implemente un programa en c++ que:

 1.Lea el numero de aeropuertos
 2.Crea una matriz dinamica de distancias de tamaño nxn de tipo double
 3.llenar la matriz con valores aleatorios entre 100 y 1500 km
 4.Muestre la matriz
 5.Calcular el promedio de las distancias 
 6.Mostrar el aeropuerto con la menor distancia promedio hacia los demás
 7.Implemente una funcion liberarMatriz()

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void llenarMatriz(double **arr,int n){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         if(i==j){
            arr[i][j]=0;
         }else{   
         arr[i][j]= 100+(rand()% 1500);
        }
        }
     }
}

double promedio(double **arr,int n){
       double prom=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           prom+=arr[i][j]; 
        }
       }
       prom=prom/(n*n);
       return prom;       
}
void mostrarMatriz(double **arr,int n){
    cout<<"      ";
    for(int i=0;i<n;i++){
        cout<<i+1<<"    ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" ";
        for(int j=0;j<n;j++){
            cout<<setw(4)<<arr[i][j]<<" ";
        }
        cout<<endl;   
    }
}
void menorDistanciaPromedio(double **arr,int n){
     double promedioMenor=1000000;
     int aeropuertoMenor;
     for(int i=0;i<n;i++){
        double suma=0;
        for(int j=0;j<n;j++){
            suma += arr[i][j];
        }
        suma=suma/n;
        if(suma<promedioMenor){
            promedioMenor=suma;
            aeropuertoMenor=i+1;
        }
     }
     cout<<"El aeropuerto "<<aeropuertoMenor<<" tiene la menor distancia promedio: "<<promedioMenor<<endl;
}
void liberarMatriz(double **arr,int n){
    // liberar cada fila
    for(int i=0;i<n;i++){
        delete [] arr[i];
    }
    // liberar el arreglo de punteros
    delete [] arr;
    cout<<"--Matriz liberada--"<<endl;
}

int main(){
    int n;
    cout<<"Ingrese el numero de aeropuertos: ";
    cin>>n;
    double **distancia= new double*[n];
    for(int i=0;i<n;i++){
        distancia[i]=new double[n];
    }
    
    srand(time(0));
    llenarMatriz(distancia,n);
    mostrarMatriz(distancia,n);
    double prom1=promedio(distancia,n);
    cout<<"Promedio de distancias: "<<prom1<<endl;
    menorDistanciaPromedio(distancia,n);
    liberarMatriz(distancia,n);
    

    return 0;
}