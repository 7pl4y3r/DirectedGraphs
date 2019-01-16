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

		Graph *first;
		int n;

		DynaGraph(int numOfVertexes)
		{
			n = numOfVertexes;
			if (n < 2)
				n = 0;
		}


		void readGraph()
		{

			if (n > 0) {

			first = 0;
			first = new Graph;
			
			first->id = '1';
			first->next = 0;

			std::cout << "Vertex 1 id is 1!\n";
			std::cout << "Reading first->ancestors\n";
			readList(first->ancestors);

			std::cout << "Reading first->successors\n";
			readList(first->successors);

			Graph *last = first;
			for (int i = 1; i < n; i++) {
			
				Graph *g = new Graph;
				g->id = (char) i;
				g->next = 0;

				std::cout << "vertex " << i + 1 << " id is " << i + 1 << '\n';
				std::cout << "Reading ancestors\n";
				readList(g->ancestors);

				std::cout << "Reading successors\n";
				readList(g->successors);

				last->next = g;
				last = g;
			}
			}
		}

		void readList(List *&first)
		{
			
			int len;
			std::cout << "Number of elements in list.. ";
			std::cin >> len;
			
			if (len > 0) {

			first = 0;
			first = new List;
			first->next = 0;

			std::cout << "first->id.. ";
			std::cin >> first->id;

			List *last = first;
			for (int i = 1; i < len; i++) {
			
				List *mList = new List;
				mList->next = 0;
				
				std::cout << "mList->id.. ";
				std::cin >> mList->id;

				last->next = mList;
				last = mList;
			}
			}
		}
	
		int listSize(List *first)
		{
			int c = 0;
			for (List *p = first; p; p = p->next)
				c++;
			
			return c;
		}
	
		void printDegrees()
		{
			for (Graph *p = first; p; p = p->next) {
				
				std::cout << "Node " << p->id << " degree is " << listSize(p->ancestors) + listSize(p->successors);
			}	
		}

		void printList(List *first)
		{
			for (List *p = first; p; p = p ->next)
				std::cout << p->id << ' ';

			std::cout << '\n';
		}

		void printGraph()
		{
			for (Graph *p = first; p; p = p->next) {
				
				std::cout << p->id << '\n';
				std::cout << "The ancestors are:\n";
				printList(p->ancestors);

				std::cout << "The successors are:\n";
				printList(p->successors);
			
				std::cout << "\n\n\n";
			}
		
			std::cout << '\n';
		}
};
