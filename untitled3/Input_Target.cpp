#include "Input_Target.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void Input_from_file( long double *Input){
    ifstream in;
    in.open("C:\\Users\\serge\\CLionProjects\\untitled3\\Input.txt");
    for (int i = 0; i < 2; ++i){
        in >> (Input[i]);
    }
    in.close();
}

void Target_from_file(long double *Target){
    ifstream Targetinput;
    Targetinput.open("C:\\Users\\serge\\CLionProjects\\untitled3\\Target.txt");
    for (int i = 0; i < 2; ++i){
        Targetinput >> (Target[i]);
    }
    Targetinput.close();
}

void First_wesa_from_f(long double W[2][2]){
    ifstream Wesainput;
    Wesainput.open("C:\\Users\\serge\\CLionProjects\\untitled3\\Firstwesa.txt");
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j)
        {
            Wesainput >> W[i][j];
        }
    }
    Wesainput.close();
}

void Second_vesa_from_file(long double W1[2][2]){
    ifstream Wesa2_input;
    Wesa2_input.open("C:\\Users\\serge\\CLionProjects\\untitled3\\Secondwesa.txt");
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            Wesa2_input >> W1[i][j];
        }
    }
    Wesa2_input.close();
}

long double Sigmoid(long double X){
    long double Y;
    Y = 1 / (1 + exp(-X * 0.9));
    return Y;
}

long double Lineer(long double X){
   long double Y;
   Y = X* 0.7;
   return Y;
}