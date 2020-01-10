/**
* @file BasketAndBalls
* @description Sepetlerin içine top koyulabilen ve sepetlerin değişik özelliklerini kullanabileceğiniz bir oyundur.
* @course Veri Yapıları - 2/B Grubu
* @assignment Birinci Ödev
* @date 25/10/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "BasketManager.cpp"

using namespace std;

int main(){
	// Init main
	system("CLS");
	int ARRAY_LENGTHS;
	int choice;
	cout << "Kova Sayisi = ";
	cin >> ARRAY_LENGTHS;
	system("CLS");
	
	BasketManager *basketManager = new BasketManager(ARRAY_LENGTHS);
	
	// MENU
	do {
		
		// Print basket array
		basketManager->print();
		
		// Print section menu
		cout << "[1] Toplari Yerlestir" << endl;
		cout << "[2] Toplari Yok Et" << endl;
		cout << "[3] Kova Degistir" << endl;
		cout << "[4] Top Degistir" << endl;
		cout << "[5] Kovalari Tersten Yerlestir" << endl;
		cout << "[6] Toplari Tersten Yerlestir" << endl;
		cout << "[7] Cikis" << endl << endl;
		cout << ">> "; cin >> choice;
		cout<<endl;
		
		// Sections
		switch(choice) {
			// Put balls into baskets
			case 1: {
				basketManager->putBallsIntoBaskets();
				break;
			}	
			// Clear balls from baskets
			case 2: {
				basketManager->clearBallsFromBaskets();
				break;
			}
			// Change baskets
			case 3: {
				int firstBasket, secondBasket;
				cout << "Hangi kova: "; cin >> firstBasket;
				cout<<endl;
				cout << "Hangi kova ile: "; cin >> secondBasket;
				cout << endl;
				
				basketManager->changeBaskets(firstBasket, secondBasket);

				break;
			}
			// Change balls
			case 4: {	
				if(!basketManager->IsBasketsEmpty()){
					int firstBall, secondBall;
					cout << "Hangi top ile: "; cin >> firstBall;
					cout << endl;
					cout << "Hangi top ile: "; cin >> secondBall;
					cout << endl;
					
					basketManager->changeBalls(firstBall, secondBall);
				}
				else {
					cout << "Lutfen once sepetlerin icini doldurun." << endl <<endl;
					system( "pause" );
					cout << endl;
				}
				break;
			}
			// Sort the baskets in reverse
			case 5: {
				basketManager->shortBasketsInReverse();
				break;
			}
			// Sort the balls in reverse
			case 6: {
				if(!basketManager->IsBasketsEmpty()){
					basketManager->shortBallsInReverse();
				}
				else{
					cout << "Lutfen, [1] secenegi ile once sepetlerin icini doldurun." << endl <<endl;
					system( "pause" );
					cout << endl;
				}
				break;
			}
		}
	}
	while(choice != 7);
	
	// Clear the heap
	delete basketManager;
	
} 
