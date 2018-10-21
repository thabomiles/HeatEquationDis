#include <iostream>
#include <cmath>
#include "heatEquation.hpp"
#include <vector>
#include <array>
#include <math.h>

int main(int argc, char* argv[])
{

double T = 1.0;

    //n is the number of elements i.e. 1 less than the number of nodes
int n = 10;

int m = 100;

double h = pow( n, -1);

double M_PI = 2*acos(0);

double a = pow(M_PI,-2);

std::vector<double> initialSpaceNodes = {0};
std::vector<double> initialTimeNodes = {0};
std::vector<double> initialSpaceMesh;
std::vector<double> initialTimeMesh;


for(int i=1; i<=n; i++)
    {
        initialSpaceNodes.push_back( i*h );
        initialTimeNodes.push_back( i*(T/m) );
        initialSpaceMesh.push_back( initialSpaceNodes.at(i)- initialSpaceNodes.at(i-1) );
        initialTimeMesh.push_back( initialTimeNodes.at(i)- initialTimeNodes.at(i-1) );
    }

std::vector<double> MassDiagonal;
std::vector<double> MassLowerDiag;
std::vector<double> MassUpperDiag;

std::vector<double> StiffnessDiagonal;
std::vector<double> StiffnessLowerDiag;
std::vector<double> StiffnessUpperDiag;

HeatEquation heat;

heat.BuildStiffnessMatrix(n, a, initialSpaceMesh, StiffnessDiagonal, StiffnessLowerDiag, StiffnessUpperDiag);
heat.BuildMassMatrix(n, initialSpaceMesh, MassDiagonal, MassLowerDiag, MassUpperDiag);

std::vector<double> Diagonal;
std::vector<double> LowerDiag;
std::vector<double> UpperDiag;
std::vector<double> f;
std::vector<double> x;
std::vector<double> AnalyticSolution;
std::vector<double> PreviousSolution;

x.assign( n-1, 0 );

for (int i = 0; i<n-1; i++)
{
    Diagonal.push_back( MassDiagonal.at(i) + initialTimeMesh.at(i)*StiffnessDiagonal.at(i) );
    UpperDiag.push_back( MassUpperDiag.at(i) + initialTimeMesh.at(i)*StiffnessUpperDiag.at(i) );
    LowerDiag.push_back( MassLowerDiag.at(i) + initialTimeMesh.at(i)*StiffnessLowerDiag.at(i) );

//        actually the analytic solution at next time step
    AnalyticSolution.push_back(exp(initialTimeNodes.at(1))*6*
                               sin(M_PI*initialSpaceNodes.at(i+1)));
    PreviousSolution.push_back(6*sin(M_PI*initialSpaceNodes.at(i+1)));

}



heat.MatrixVectorMultiplier(n-1, MassDiagonal, MassLowerDiag, MassUpperDiag, PreviousSolution, f);


heat.TridiagonalMatrixSolver(n-1, Diagonal, LowerDiag, UpperDiag, f, x);

        for (auto j: x)
            std::cout << j << ' ';

        std::cout << " \n";


        for (auto j: AnalyticSolution)
            std::cout << j << ' ';
        std::cout << " \n";



}

