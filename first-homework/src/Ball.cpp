/**
* @file BasketAndBalls
* @description Sepetlerin içine top koyulabilen ve sepetlerin değişik özelliklerini kullanabileceğiniz bir oyundur.
* @course Veri Yapıları - 2/B Grubu
* @assignment Birinci Ödev
* @date 25/10/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include "Ball.hpp"

Ball::Ball(){
	value = (rand() % 26) + 65;
}
Ball::~Ball(){
	cout << "Top nesnesi heap alanindan silindi."<<endl;
}
char Ball::getValue(){
	return value;
}