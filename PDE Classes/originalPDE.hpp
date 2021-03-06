#ifndef originalPDEHEADERREF
#define originalPDEHEADERREF
#include <cmath>
#include <math.h>
#include <vector>
#include <array>
#include "SpaceMesh.hpp"
#include "TimeMesh.hpp"
#include "TriDiagMatrix.hpp"
#include "MassMatrix.hpp"
#include "StiffnessMatrix.hpp"
#include "APDE.hpp"

class originalPDE: public APDE
{
    public:
        friend class GeneralHeat;
        double ContinuousAnalyticSolution( double x, double t );
        double AnalyticGradientWRTx( double x, double t );
        double FirstBoundary( double t );
        double SecondBoundary( double t );
        void InitialCondition ( SpaceMesh& a_mesh, std::vector<double>& first_U );
        originalPDE();

    protected:

};

#endif // originalPDEHEADERREF
