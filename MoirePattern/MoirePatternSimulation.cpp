#include "MoirePatternSimulation.h"
#include <cmath>

void SimulationModel::ParametersUpdate(double l1, double T, double l2)
{
	this->l1 = l1;
	this->T = T;
	this->l2 = l2;
	L = l1 + T + l2;
}

bool SimulationModel::IsSample(double r)
{
	int i = 0;
	double depth = 0;
	double Lx = sqrt(r * r + L * L);
	while (depth <= l1 + T && i < stepNumMax)
	{
		double lx = i * stepSize;
		depth = L - (L / Lx * (Lx - lx));
		if (depth >= l1 && depth <= l1 + T)
		{
			return true;
		}

		i++;
	}

	return false;
}