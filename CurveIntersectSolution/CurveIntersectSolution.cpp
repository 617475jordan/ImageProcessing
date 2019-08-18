#include "CurveIntersectSolution.h"

CurveIntersectSolution::CurveIntersectSolution()
{
}

CurveIntersectSolution::~CurveIntersectSolution()
{

}

bool CurveIntersectSolution::UnivariateQuadraticSolution(unsigned char& number, double coefficient[], unsigned char& m_iEquationSolutionNum, double result[])
{
	if (number >= 3 && coefficient[3] != 0)
	{
		double a = coefficient[3];
		double b = coefficient[2];
		double c = coefficient[1];
		double delta = pow(b, 2) - 4 * a*c;
		if (delta < 0)
		{
			return false;
		}
		else if (delta == 0)
		{
			result[0] = result[1] = (-b) / (2 * a);
			m_iEquationSolutionNum = 1;
			return true;
		}
		else if (delta > 0)
		{
			double m_InvSqrt = sqrt(delta);
			result[0] = (-b + m_InvSqrt) / (2 * a);
			result[1] = (-b - m_InvSqrt) / (2 * a);
			m_iEquationSolutionNum = 2;
			return true;
		}
	}
	else
	{
		bool m_bFlag = false;
		m_bFlag = OneYuanOneTimeSolution(number, coefficient, m_iEquationSolutionNum, result);
		return m_bFlag;
	}
	return false;
}

bool CurveIntersectSolution::OneYuanOneTimeSolution(unsigned char& number, double coefficient[], unsigned char &m_iEquationSolutionNum, double result[])
{
	if (number >= 2 && coefficient[2] != 0)
	{
		result[0] = (-coefficient[1] / coefficient[2]);
		m_iEquationSolutionNum = 1;
		return true;
	}

	return false;
}

double CurveIntersectSolution::sum(std::vector<double> Vnum, int n)
{
	double dsum = 0;
	for (int i = 0; i < n; i++)
	{
		dsum += Vnum[i];
	}
	return dsum;
}

double CurveIntersectSolution::MutilSum(std::vector<position3d> m_position3d, int n)
{
	double dMultiSum = 0;
	for (int i = 0; i < n; i++)
	{
		dMultiSum += m_position3d[i].x*m_position3d[i].y;
	}
	return dMultiSum;
}

double CurveIntersectSolution::RelatePow(std::vector<position3d> m_position3d, int n, int ex)
{
	double ReSum = 0;
	for (int i = 0; i < n; i++)
	{
		ReSum += pow(m_position3d[i].x, ex);
	}
	return ReSum;
}



double CurveIntersectSolution::RelateMutiXY(std::vector<position3d> m_position3d, int n, int ex)
{
	double dReMultiSum = 0;
	for (int i = 0; i < n; i++)
	{
		dReMultiSum += pow(m_position3d[i].x, ex)*m_position3d[i].y;
	}
	return dReMultiSum;
}

void CurveIntersectSolution::EMatrix(std::vector<position3d> m_position3d, int n, int ex, double coefficient[])
{
	for (int i = 1; i <= ex; i++)
	{
		for (int j = 1; j <= ex; j++)
		{
			Em[i][j] = RelatePow(m_position3d, n, i + j - 2);
		}
		Em[i][ex + 1] = RelateMutiXY(m_position3d, n, i - 1);
	}
	Em[1][1] = n;
	CalEquation(ex, coefficient);
}

void CurveIntersectSolution::CalEquation(int exp, double coefficient[])
{
	for (int k = 1; k < exp; k++) //消元过程
	{
		for (int i = k + 1; i < exp + 1; i++)
		{
			double p1 = 0;

			if (Em[k][k] != 0)
				p1 = Em[i][k] / Em[k][k];

			for (int j = k; j < exp + 2; j++)
				Em[i][j] = Em[i][j] - Em[k][j] * p1;
		}
	}
	coefficient[exp] = Em[exp][exp + 1] / Em[exp][exp];
	for (int l = exp - 1; l >= 1; l--)   //回代求解
		coefficient[l] = (Em[l][exp + 1] - F(coefficient, l + 1, exp)) / Em[l][l];
}

double CurveIntersectSolution::F(double c[], int l, int m)
{
	double sum = 0;
	for (int i = l; i <= m; i++)
		sum += Em[l - 1][i] * c[i];
	return sum;
}

