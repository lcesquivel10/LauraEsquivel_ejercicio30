#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){
 
  const int NX = 100;
  const double B = 0.05;
  const double Vel = 1;
  const double Dx = 1./NX;
  const double Dt = B*Dx/Vel;
  const double Tf = 0.1;
  const int Nt = int(Tf/Dt);
    
  ////
    
    
  ofstream Archivo("Archivo.dat");
    
  ///
  double x,x0;
  double U[NX+1];
  double U0[NX+1];
    
  //Inicializar U
    
  for(int i = 0; i < NX+1; i++){
    U[i]=0.;
    U0[i]=0.;
  }
    
    
  //Condicion inicial
    
  for(int i = 0; i < NX+1; i++){
    x0 = 0.;
    x = x0 + i*Dx;
    U0[i] = sin(2*6.4*x);
  }
    
  //Paso temporal
    
  int i = 0;
  int j = 0;
  double U01;
  double U02;
  double U03;
    
  while(j < Nt+1){
    while(i <= NX-1){
      Archivo << U0[i] << endl;
      U01 = -(B/4.)*(U0[i+2]*U0[i+2]-U0[i]*U0[i]);
      U02 = (U0[i+2]+U0[i+1])*(U0[i+2]*U0[i+2] - U0[i+1]*U0[i+1]);
      U03 = (U0[i+1]+U0[i])*(U0[i+1]*U0[i+1] - U0[i]*U0[i]);
      U[i+1]=U0[i+1] + U01 + (B*B/8.)*(U02 - U03);
      U[0]=0;
      U[NX-1]=0;
      U0[i]=U[i];
      i = i + 1;
    }
    i = 0;
    j = j + 1;
  }
  return 0;
}
