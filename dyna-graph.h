#include <iostream>

class DynaGraph {

	public:

		struct List {
		
			char id;
			List *next;
		};

		struct Graph {
		
			char id;
			List *ancestors;
			List *successors;
			Graph *next;
		};



		static void readGraph(Graph *&first, int n)
		{
			first = 0;
			first = new Graph;
			first->id = '1';
			first->next = 0;

			std::cout << "Reading first->ancestors\n";
			readList(first->ancestors);

			std::cout << "Reading first->successors\n";
			readList(first->successors);

			Graph *last = first;
			for (int i = 2; i <= n; i++) {
			
				Graph *g = new Graph;
				g->id = (char) i;
				g->next = 0;
				readList(g->ancestors);
				readList(g->successors);

				last->next = g;
				last = g;
			}
		}

		static void readList(List *&first)
		{
			first = 0;
			
			first = new List;
			first->next = 0;

			std::cout << "first->id.. ";
			std::cin >> first->id;

			List *last = first;
			int n;
			std::cout << "Number of items in list";
			std::cin >> n;

			for (int i = 2; i <= n; i++) {
			
				List *mList = new List;
				mList->next = 0;
				std::cout << "mList->id.. ";
				std::cin >> mList->id;

				last = mList;
			}
		}

		static void printList(List *first)
		{
			for (List *p = first; p; p = p ->next)
				std::cout << p->id << ' ';

			std::cout << '\n';
		}

		static void printGraph(Graph *first)
		{
			for (Graph *p = first; p; p = p->next) {
				std::cout << p->id << ' ';
				std::cout << "The ancestors are:\n";
				printList(p->ancestors);

				std::cout << "The successors are:\n";
				printList(p->successors);
			}
		
			std::cout << '\n';
		}
};
