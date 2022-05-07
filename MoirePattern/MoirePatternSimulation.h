#pragma once

class SimulationModel
{
public:
	double l1;
	double l2;
	double T;
	double stepSize;
	int stepNumMax;

private:
	double L;

public:
	void ParametersUpdate(double l1, double T, double l2);

	bool IsSample(double r);
};