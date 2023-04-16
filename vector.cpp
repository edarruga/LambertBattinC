//
// Created by edarruga on 15/03/2023.
//

/* ------------------DOCUMENTACION--------------------------------
 *
 * -Variables:
 * v es un vector de double sobre el que se van a realizar las operaciones
 * n es un int que corresponde el tamaño del vector v
 *
 *
 */

#include <cmath>
#include "vector.h"


double norm(double v[], int n){
    double suma=0;
    if(n<=0){
        throw "Empty vector";
    }
    for(int i=0;i<n;i++){
        suma+=v[i]*v[i];
    }
    return (sqrt(suma));
}

double dot(double v1[], double v2[], int n){//  n es la dimensión de los dos vectores
    double producto_escalar = 0.0;
    if(n<=0){
        throw "Empty vector";
    }
    for(int i=0; i<n; i++){
        producto_escalar += v1[i] * v2[i];
    }

    return producto_escalar;
}

void cross(double v1[], double v2[], double result[]){

    result[0] = v1[1]*v2[2] - v1[2]*v2[1];
    result[1] = v1[2]*v2[0] - v1[0]*v2[2];
    result[2] = v1[0]*v2[1] - v1[1]*v2[0];

}
