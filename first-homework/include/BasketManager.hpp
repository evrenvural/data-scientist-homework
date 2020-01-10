#ifndef BASKET_MANAGER_HPP
#define BASKET_MANAGER_HPP

#include "Basket.hpp"
#include "Ball.hpp"

#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>	/* time */

using namespace std;

	class BasketManager{
		private:
			Basket** basket;
			Ball** ball;
			int ARRAY_LENGTHS;
			
		public:
			BasketManager(int);
			~BasketManager();
			void print();
			void putBallsIntoBaskets();
			void clearBallsFromBaskets();
			void changeBaskets(int,int);
			void changeBalls(int, int);
			void shortBasketsInReverse();
			void shortBallsInReverse();
			bool IsBasketsEmpty();
	};
	
#endif
