#include <iostream>
#include <cmath>
#include "heatEquation.hpp"
#include <vector>
#include <array>
#include <math.h>

int main(int argc, char* argv[])
{

double T = 4.0;

int n = 4;

int m = 4;

double h = pow( n, -1);

std::cout << h << ' ';

double M_PI = 2*acos(0);

double a = pow(M_PI,-2);

std::vector<double> initialSpaceNodes = {0};
std::vector<double> initialTimeNodes = {0};
std::vector<double> initialSpaceMesh;


for(int i=1; i<=n; i++)
    {
        initialSpaceNodes.push_back( i*h );
        initialTimeNodes.push_back( i*(T/m) );
        initialSpaceMesh.push_back( initialSpaceNodes.at(i)- initialSpaceNodes.at(i-1) );
    }

        for (auto i: initialSpaceNodes)
            std::cout << i << ' ';




std::vector<double> MassDiagonal = {(initialSpaceMesh.at(0)*pow(3,-1))};
std::vector<double> MassLowerDiag = {0};
std::vector<double> MassUpperDiag = {(initialSpaceMesh.at(0)*pow(6,-1))};

for(int i=1; i<n-1; i++)
    {
        MassDiagonal.push_back( (initialSpaceMesh.at(i-1)+initialSpaceMesh.at(i))*pow(3,-1) );
        MassLowerDiag.push_back( initialSpaceMesh.at(i-1)*pow(3,-1) );
        MassUpperDiag.push_back( initialSpaceMesh.at(i))*pow(3,-1) );
    }

MassDiagonal.push_back( initialSpaceMesh.at(n-1)*pow(3,-1)) );
MassLowerDiag.push_back( initialSpaceMesh.at(n-1)*pow(3,-1) );
MassUpperDiag.push_back( 0 );

std::vector<double> StiffnessDiagonal;
std::vector<double> StiffnessLowerDiag;
std::vector<double> StiffnessUpperDiag;



std::vector<double> Diagonal;
std::vector<double> LowerDiag;
std::vector<double> UpperDiag;
std::vector<double> f;
std::vector<double> x;


HeatEquation heat;

f.assign( n, 1 );
Diagonal.assign( n, 3 );
UpperDiag.assign( n, 1);
UpperDiag.at( n-1 ) = 0;
LowerDiag.assign( n, 1 );
LowerDiag.at( 0 ) = 0;
x.assign( n, 0 );

heat.MatrixVectorMultiplier( n, Diagonal, LowerDiag, UpperDiag, f, x);


}

