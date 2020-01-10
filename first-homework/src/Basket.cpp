/**
* @file BasketAndBalls
* @description Sepetlerin içine top koyulabilen ve sepetlerin değişik özelliklerini kullanabileceğiniz bir oyundur.
* @course Veri Yapıları - 2/B Grubu
* @assignment Birinci Ödev
* @date 25/10/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include "Basket.hpp"

Basket::Basket(int _color){
	isEmpty = true;
	setColor(_color);
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}
Basket::~Basket(){
	cout << "Kova nesnesi heap alanindan silindi."<<endl;
}

void Basket::setColor(int _color){
	color = _color;
}
int Basket::getColor(){
	return color;
}
void Basket::setBall(Ball* _ball){
	ball = _ball;
	isEmpty = false;
}
void Basket::empty(){
	isEmpty = true;
}
bool Basket::IsEmpty() {
	return isEmpty;
}
void Basket::print(Basket* address){
	SetConsoleTextAttribute(hConsole, getColor());
	
	cout<<"   .|."<<endl;
	cout<<"  .   ."<<endl;
	cout<<" .     ."<<endl;
	cout<<" #     #"<<endl;
	cout<<" #  ";
	isEmpty ? cout << '-' : cout << ball->getValue(); 
	cout<<"  #"<<endl;
	cout<<" #     #"<<endl;
	cout<<" #######"<<endl<<endl;
	
	cout<<"Kova Adresi: " << address << endl;
	cout<<"Topun Adresi: "; 
	isEmpty ? cout << "NULL" : cout << ball;
	cout << endl << endl;
	
	SetConsoleTextAttribute(hConsole, 7);
}