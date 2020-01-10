#ifndef BASKET_HPP
#define BASKET_HPP

using namespace std;

#include <string>
#include "Ball.hpp"
#include <iostream>
#include <Windows.h>

	class Basket{
		private:
			int color;
			Ball *ball;
			bool isEmpty;
			HANDLE hConsole;
			
			void setColor(int);
			int getColor();

		public:
			Basket(int);
			~Basket();
			void setBall(Ball*);
			void print(Basket*);
			void empty();
			bool IsEmpty();
	};
	
#endif
