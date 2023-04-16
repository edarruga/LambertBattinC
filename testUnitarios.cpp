//
// Created by edarruga on 15/03/2023.
//
#include <iostream>
#include <cmath>
#include "vector.h"
#include "seebatt.h"
#include "seebattk.h"
#include "lambertbattin.h"


using namespace std;

int main(){
    double v0[] ={0,0,0};
    double v1[] ={1,1,1};
    double v2[]={1, 3, 5, 7};
    double v3[] ={0,1,5,9};
    double v4[] ={1.4,3.06,0.8681};
    double v5[] ={15.1265,2.56,19.512};
    double v6[]={20000000.0, 20000000.0, 0};
    double v7[]={-20000000.0, 10000000.0, 0};
    double result[]={0,0,0};
    double result2[]={0,0,0};
    double tof = 1.0 * 86400;
    //-------------Test (norm)---------------------
    cout<<"-Test norm():"<<endl;

    if(fabs(norm(v1,3) - sqrt(3.0)) < pow(10,-12)){
        cout<<"Test norm() 1: passed"<<endl;
    }else{
        cout<<"Test norm() 1: failed"<<endl;
    }
    if(fabs(norm(v2,4) - 9.16515138991168) < pow(10,-12)){
        cout<<"Test norm() 2: passed"<<endl;
    }else{
        cout<<"Test norm() 2: failed"<<endl;
    }
    //-------------Test (dot)---------------------
    cout<<" "<<endl;
    cout<<"-Test dot():"<<endl;
    if(fabs(dot(v0,v1,3) - 0.0000000000001) < pow(10,-12)){
        cout<<"Test dot() 1: passed"<<endl;
    }else{
        cout<<"Test dot() 1: failed"<<endl;
    }
    if(fabs(dot(v1,v1,3) - 3.000000000000) < pow(10,-12)){

        cout<<"Test dot() 2: passed"<<endl;
    }else{
        cout<<"Test dot() 2: failed"<<endl;
    }
    if(fabs(dot(v2,v3,4) - 91.000000000000) < pow(10,-12)){

        cout<<"Test dot() 3: passed"<<endl;
    }else{
        cout<<"Test dot() 3: failed"<<endl;
    }
    if(fabs(dot(v4,v5,3) -45.949067200000) < pow(10,-12)){

        cout<<"Test dot() 4: passed"<<endl;
    }else{
        cout<<"Test dot() 4: failed"<<endl;
    }


    //-------------Test (cross)---------------------
    cout<<" "<<endl;
    cout<<"-Test cross():"<<endl;

    cross(v0,v1,result);
    if(fabs( result[0]-0.0000000000001) < pow(10,-12) && fabs( result[1]-0.0000000000001) < pow(10,-12) && fabs( result[2]-0.0000000000001) < pow(10,-12)){

        cout<<"Test cross() 1: passed"<<endl;
    }else{
        cout<<"Test cross() 1: failed"<<endl;
    }
    cross(v1,v1,result);
    if(fabs( result[0]-0.0000000000001) < pow(10,-12) && fabs( result[1]-0.0000000000001) < pow(10,-12) && fabs( result[2]-0.0000000000001) < pow(10,-12)){

        cout<<"Test cross() 2: passed"<<endl;
    }else{
        cout<<"Test cross() 2: failed"<<endl;
    }
    cross(v4,v5,result);
    if(fabs( result[0]-57.484384000000) < pow(10,-12) && fabs( result[1]+14.185485349999) < pow(10,-12) && fabs( result[2]+42.703090000000) < pow(10,-12)){

        cout<<"Test cross() 3: passed"<<endl;
    }else{
        cout<<"Test cross() 3: failed"<<endl;
    }

    //-------------Test (seebatt)---------------------
    cout<<" "<<endl;
    cout<<"-Test seebatt():"<<endl;

    if(fabs(seebatt(0.0)-5.0)<pow(10,-12)){
        cout<<"Test seebatt() 1: passed"<<endl;
    }else{
        cout<<"Test seebatt() 1: failed"<<endl;
    }
    if(fabs(seebatt(3.76982021737918)-8.03007718341174)<pow(10,-12)){
        cout<<"Test seebatt() 2: passed"<<endl;
    }else{
        cout<<"Test seebatt() 2: failed"<<endl;
    }
    if(fabs(seebatt(1.0)-6.06251330587321)<pow(10,-12)){
        cout<<"Test seebatt() 3: passed"<<endl;
    }else{
        cout<<"Test seebatt() 3: failed"<<endl;
    }
    //-------------Test (seebattk)---------------------
    cout<<" "<<endl;
    cout<<"-Test seebattk():"<<endl;

    if(fabs(seebattk(1.31002860149908)-0.279155336940309)<pow(10,-12)){
        cout<<"Test seebattk() 1: passed"<<endl;
    }else{
        cout<<"Test seebattk() 1: failed"<<endl;
    }
    if(fabs(seebattk( 0.477827195339357)-0.311296872378305)<pow(10,-12)){
        cout<<"Test seebattk() 2: passed"<<endl;
    }else{
        cout<<"Test seebattk() 2: failed"<<endl;
    }
    if(fabs(seebattk(0.397021642907571)-0.31481645256144)<pow(10,-12)){
        cout<<"Test seebattk() 3: passed"<<endl;
    }else{
        cout<<"Test seebattk() 3: failed"<<endl;
    }

    //-------------Test (lambertbattin)---------------------
    cout<<" "<<endl;
    cout<<"-Test lambertbattin():"<<endl;
    lambertbattin(v6, v7, "retro", tof,result,result2);
    if(fabs( result[0]-4144.30717367665)<pow(10,-10) && fabs( result[1]+1571.15318557575 )<pow(10,-10) && fabs( result[2]-0.000000000000 )<pow(10,-10)
    && fabs( result2[0]-3223.39508300486 )<pow(10,-10) && fabs( result2[1]-4103.76281774997 )<pow(10,-10) && fabs( result2[2]-0.000000000000 )<pow(10,-10)){
        cout<<"Test lambertbattin() 1: passed"<<endl;
    }else{
        cout<<"Test lambertbattin() 1: failed"<<endl;
    }
    tof = 1.0 * 87;
    lambertbattin(v6, v7, "retro", tof,result,result2);
    if(fabs( result[0]-36462.9068984019)<pow(10,-7) && fabs( result[1]-1037.84465211199 )<pow(10,-7) && fabs( result[2]-0.000000000000 )<pow(10,-7)
       && fabs( result2[0]-33609.6797847572 )<pow(10,-7) && fabs( result2[1]-18620.2223539113 )<pow(10,-7) && fabs( result2[2]-0.000000000000 )<pow(10,-7)){
        cout<<"Test lambertbattin() 2: passed"<<endl;
    }else{
        cout<<"Test lambertbattin() 2: failed"<<endl;
    }


    return 0;
}

