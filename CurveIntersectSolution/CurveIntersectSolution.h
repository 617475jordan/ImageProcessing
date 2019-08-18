#pragma once
#include <vector>
#include <iostream>
using namespace std;
//曲线相交求解
struct position3d
{
	double x=0;
	double y=0;
	double z=0;
};
class CurveIntersectSolution
{
public:
	
	CurveIntersectSolution();
	~CurveIntersectSolution();
	bool UnivariateQuadraticSolution(unsigned char& number, double coefficient[], unsigned char& m_iEquationSolutionNum, double result[]);
	bool OneYuanOneTimeSolution(unsigned char& number, double coefficient[], unsigned char &m_iEquationSolutionNum, double result[]);
	void EMatrix(std::vector<position3d> m_position3d, int n, int ex, double coefficient[]);
private:
	double sum(std::vector<double> Vnum, int n);
	double MutilSum(std::vector<position3d> m_position3d, int n);
	double RelatePow(std::vector<position3d> m_position3d, int n, int ex);
	double RelateMutiXY(std::vector<position3d> m_position3d, int n, int ex);
	
	void CalEquation(int exp, double coefficient[]);
	double F(double c[], int l, int m);
private:
	double Em[6][4];
};

