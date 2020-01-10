/**
* @file BasketAndBalls
* @description Sepetlerin içine top koyulabilen ve sepetlerin değişik özelliklerini kullanabileceğiniz bir oyundur.
* @course Veri Yapıları - 2/B Grubu
* @assignment Birinci Ödev
* @date 25/10/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include "BasketManager.hpp"
#include "Basket.cpp"
#include "Ball.cpp"

BasketManager::BasketManager(int _arrayLengths){
	srand(time(NULL)); // For random
	
	ARRAY_LENGTHS = _arrayLengths;
	basket = new Basket*[ARRAY_LENGTHS];
	ball = new Ball*[ARRAY_LENGTHS];
	
	// Init basket
	for(int i=0; i<ARRAY_LENGTHS; i++){
		basket[i] = new Basket(i+1);
	}
	
	// Init balls
	for(int i=0; i<ARRAY_LENGTHS; i++){
		ball[i] = new Ball();
	}
}
BasketManager::~BasketManager(){
	for(int i=0; i<ARRAY_LENGTHS; i++){
		delete ball[i];
		delete basket[i];
	}
	delete[] ball;
	delete[] basket;
	
	cout << "Sepet Yoneticisi nesnesi heap alanindan silindi.";
}

void BasketManager::print(){
	for(int i=0; i<ARRAY_LENGTHS; i++){
			cout << (i+1) <<". Kova"<<endl<<endl;
			basket[i]->print(basket[i]);
	}
}
void BasketManager::putBallsIntoBaskets(){
	for(int i=0; i<ARRAY_LENGTHS; i++){
		basket[i]->setBall(ball[i]);
	}
}
void BasketManager::clearBallsFromBaskets(){
	for(int i=0; i<ARRAY_LENGTHS; i++){
		basket[i]->empty();
	}
}
void BasketManager::changeBaskets(int firstBasket, int secondBasket){
	Basket* temp = basket[firstBasket - 1];
	basket[firstBasket - 1] = basket[secondBasket - 1];
	basket[secondBasket - 1] = temp;
}
void BasketManager::changeBalls(int firstBall, int secondBall){
	Ball* temp2 = ball[firstBall - 1];
	ball[firstBall - 1] = ball[secondBall - 1];
	ball[secondBall - 1] = temp2;
				
	putBallsIntoBaskets();
}
void BasketManager::shortBasketsInReverse(){
		int j = (ARRAY_LENGTHS-1);
		for(int i=0; i<ARRAY_LENGTHS / 2; i++){
			Basket* temp = basket[i];
			basket[i] = basket[j];
			basket[j] = temp;
			j--;
		}
}
void BasketManager::shortBallsInReverse(){
	int j = (ARRAY_LENGTHS-1);
	for(int i=0; i<ARRAY_LENGTHS / 2; i++){
		Ball* temp = ball[i];
		ball[i] = ball[j];
		ball[j] = temp;
		j--;
	}
					
	putBallsIntoBaskets();
}
bool BasketManager::IsBasketsEmpty(){
	return basket[0]->IsEmpty();
}