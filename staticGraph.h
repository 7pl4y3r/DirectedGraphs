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
		static void printNeighbors(int m[6][6], int n, int i, int M)
		{
			int s[20] = pred(m, n, i), p[20] = suc(m, n, i);
			for (int j = 1; j <= n; j++) {
				if (j != i && (s[j] == 1 || p[j] == 1))
					std::cout << j << ' ';
			}
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
	
		static int pred[20](int m[6][6], int n, int i, int M)
		{
			int v[20];
			for (int i = 0; i < 20; i++)
				v[i] = 0;
			
			for (int k = 1; k <= M; k++) {
				if (m[i][k] == 1) {
					for (int j = 1; j <= n; j++) {
						if (j != i && m[j][k] == -1)
							p[j] = 1;		
					}
				}
			}
			return v;
		}
	
	static int pred[20](int m[6][6], int n, int i, int M)
		{
			int v[20];
			for (int i = 0; i < 20; i++)
				v[i] = 0;
			
			for (int k = 1; k <= M; k++) {
				if (m[i][k] == -1) {
					for (int j = 1; j <= n; j++) {
						if (j != i && m[j][k] == 1)
							p[j] = 1;		
					}
				}
			}
			return v;
		}

};
