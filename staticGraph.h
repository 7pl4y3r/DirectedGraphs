#include <iostream>

class StaticGraph {

	public:

		static void printDegrees(int m[6][6], int n)
		{
			for (int i = 1; i <= n; i++)
				std::cout << "Node " << i << " degree is " << getInDegree(i, m, n) + getOutDegree(i, m, n) << '\n';	
		}



	private:

		static int getInDegree(int i, int m[6][6], int n)
		{
			int s = 0;
			for (int j = 1; j <= n; j++)
				s += m[j][i];

			return s;
		}

		static int getOutDegree(int i, int m[6][6], int n)
		{
			int s = 0;
			for (int j = 1; j <= n; j++)
				s += m[i][j];

			return s;
		}

};
