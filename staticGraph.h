#include <iostream>

class StaticGraph {

	public:

		static void printDegrees(int m[6][6], int n)
		{
			for (int i = 1; i <= n; i++)
				std::cout << "Node " << i << " degree is " << getInDegree(i, m, n) + getOutDegree(i, m, n) << '\n';	
		}

		static void printDegrees2(int m[6][6], int n)
		{
			for (int i = 1; i <= n; i++) {
				std::cout << "Node " << i << '\n';
				std::cout << "in degree " << getInDegree2(i, m, n) << '\n';
				std::cout << "out degree " << getOutDegree(i, m, n) << '\n';
			}	
			std::cout << '\n';
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

		static int getInDegree2(int i, int m[6][6], int n)
		{
			int s = 0;
			for (int k = 1; k <= n; k++) {
				if (m[i][k] == 1)
					s += m[i][k];
			}
			return s;
		}

		static int getOutDegree2(int i, int m[6][6], int n)
		{
			int s = 0;
			for (int k = 1; k <= n; k++) {
				if (m[i][k] == -1)
					s += m[i][k];
			}
			return s;
		}

};
