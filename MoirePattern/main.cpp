#include<iostream>
#include<opencv2/opencv.hpp>
#include<cmath>
#include"MoirePatternSimulation.h"

#define WIDTH 800
#define LENGTH 800
#define STEP_NUM 512
#define MISS_COL cv::Vec3b(255, 255, 255)
#define SAMPLE_COL cv::Vec3b(0, 0, 255)

int main(int argc, char** argv)
{
	cv::Mat img(WIDTH, LENGTH, CV_8UC3, cv::Scalar(0, 0, 0));
		
	SimulationModel sm;
	sm.stepNumMax = STEP_NUM; 
	sm.stepSize = 1.0 / STEP_NUM; //assume the cube size is (1, 1, 1)
	sm.ParametersUpdate(0.2 / 255, 0.03 / 255, 0.05); // to change the parameters in the simulation model
	
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			double y = (double)(i - (double)WIDTH / 2) / WIDTH;
			double x = (double)(j - (double)LENGTH / 2) / LENGTH;
			if (sm.IsSample(sqrt(x * x + y * y)))
			{
				img.at<cv::Vec3b>(i, j) = SAMPLE_COL;
			}
			else
			{
				img.at<cv::Vec3b>(i, j) = MISS_COL;
			}
		}
	}

	cv::imshow("output", img);
	cv::waitKey();

	return 0;
}