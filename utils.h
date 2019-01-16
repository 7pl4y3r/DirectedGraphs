#include <iostream>
#include <fstream>

class Utils {

	public:

		static void readMatrixFromFile(int m[6][6], int &n)
		{
			std::ifstream in("matrix.txt");

			in >> n;
			for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				in >> m[i][j];

			in.close();
		}

		static void readMatrixFromFile2(int m[6][6], int &n)
		{
			std::ifstream in("matrix2.txt");

			in >> n;
			for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				in >> m[i][j];

			in.close();
		}

		static void printMatrix(int m[6][6], int n)
		{
			for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				std::cout << m[i][j] << ' ';
			
			std::cout << '\n';
			}
			
			std::cout << '\n';
		}

};
