#include <iostream>

class List {

	public:

		int n;

		List(int len)
		{
			n = len;
		}

		struct SimpleList {
		
			char id;
			SimpleList *next;
		};

		SimpleList *first;

		void readList()
		{

			if (n > 0) {

			first = 0;
			first = new SimpleList;
			first->next = 0;

			std::cout << "SimpleList id = ";
			std::cin >> first->id;

			SimpleList *last = first;
			for (int i = 1; i < n; i++) {
			
				SimpleList *p = new SimpleList;
				p->next = 0;

				std::cout << "SimpleList id = ";
				std::cin >> p->id;

				last->next = p;
				last = p;	
			}
		    }
		}
	
		void printList()
		{
			for (SimpleList *p = first; p; p = p->next) 
				std::cout << p->id << ' ';
		
			std::cout << '\n';
		}
};
