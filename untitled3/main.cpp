#include <iostream>
#include <fstream>
#include <cmath>
#include "Input_Target.h"


int main() {
    using namespace std;
    ofstream vesaof;
    ofstream vesaof1;

    const int Colvo_Neurons = 2;

    long double Input[Colvo_Neurons];
    Input_from_file(Input);
    for (int i = 0; i < Colvo_Neurons; ++i){
        cout << Input[i] << endl;
    }
    cout << endl;

    long double Target[Colvo_Neurons];
    Target_from_file(Target);
    for (int i = 0; i < Colvo_Neurons; ++i){
        cout << Target[i] << endl;
    }

    long double FirstWesa[Colvo_Neurons][Colvo_Neurons];
    First_wesa_from_f(FirstWesa);
    for (int i = 0; i < Colvo_Neurons; ++i){
        for (int j = 0; j < Colvo_Neurons; ++j){
            cout << FirstWesa[i][j] << endl;
        }
    }


    long double SecondWesa[Colvo_Neurons][Colvo_Neurons];
    Second_vesa_from_file(SecondWesa);
    for (int i = 0; i < Colvo_Neurons; ++i){
        for (int j = 0; j < Colvo_Neurons; ++j){
            cout << SecondWesa[i][j] << endl;
        }
    }

    long double Y0 = 0;
    long double Y1 = 0;

    long double answer0 = 0;
    long double answer1 = 0;

    bool status = true;
    int i = 0;
    while (status){
        long double S0 = Input[0] * FirstWesa[0][0] + Input[1] * FirstWesa[0][1];
        long double S1 = Input[0] * FirstWesa[1][0] + Input[1] * FirstWesa[1][1];

        Y0 = Sigmoid(S0);
        Y1 = Sigmoid(S1);

        long double S_for1_0 = Y0 * SecondWesa[0][0] + Y1 * SecondWesa[0][1];
        long double S_for1_1 = Y0 * SecondWesa[1][0] + Y1 * SecondWesa[1][1];

        answer0 = Lineer(S_for1_0);
        answer1 = Lineer(S_for1_1);

        long double E_for1_0 = (Target[0] - answer0) * answer0 * (1 - answer0);
        long double E_for1_1 = (Target[1] - answer1) * answer1 * (1 - answer1);

        long double E0 = Y0 * (1 - Y0) * (E_for1_0 * SecondWesa[0][0] + E_for1_1 * SecondWesa[1][0]);
        long double E1 = Y1 * (1 - Y1) * (E_for1_0 * SecondWesa[0][1] + E_for1_1 * SecondWesa[1][1]);

        FirstWesa[0][0] = FirstWesa[0][0] + 0.8 * E0 * Input[0];
        FirstWesa[0][1] = FirstWesa[0][1] + 0.8 * E0 * Input[1];

        FirstWesa[1][0] = FirstWesa[1][0] + 0.8 * E1 * Input[0];
        FirstWesa[1][1] = FirstWesa[1][1] + 0.8 * E1 * Input[1];

        SecondWesa[0][0] = SecondWesa[0][0] + 0.8 * E_for1_0 * Y0;
        SecondWesa[0][1] = SecondWesa[0][1] + 0.8 * E_for1_0 * Y1;

        SecondWesa[1][0] = SecondWesa[1][0] + 0.8 * E_for1_1 * Y0;
        SecondWesa[1][1] = SecondWesa[1][1] + 0.8 * E_for1_1 * Y1;


        long double Eror0 = Target[0] - answer0;
        long double Eror1 = Target[1] - answer1;

        double eror = pow(Eror0, 2.0) + pow(Eror1, 2.0);
        ++i;
        if ((eror <= 0.0001) || (i == 10000)){
            status = false;
            cout << "Number of epochs: " << i << endl;
        }
    }

    vesaof.open("C:\\Users\\serge\\CLionProjects\\untitled3\\Firstwesa.txt");
    for (int i = 0; i < Colvo_Neurons; ++i){
        for (int j = 0; j < Colvo_Neurons; ++j)
        {
            vesaof << FirstWesa[i][j] << endl;
        }
    }
    vesaof.close();

    cout << "First answer: " << answer0 << endl;
    cout << "Second answer: " << answer1 << endl;
}