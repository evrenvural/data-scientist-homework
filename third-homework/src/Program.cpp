/**
* @file BinarySearchTree Project
* @description Text dosyasındaki sayıları okuyup bu sayıları İkili Arama Ağacı'na yerleştirir.
* @course Veri Yapıları - 2/B Grubu
* @assignment Üçüncü Ödev
* @date 09/12/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "BinarySearchTree.cpp"
#include <fstream>

using namespace std;

int main(){
	BinarySearchTree<int> *firstTree = new BinarySearchTree<int>();
	BinarySearchTree<int> *secondTree = new BinarySearchTree<int>();
	int firstTreeScore = 0;
	int secondTreeScore = 0;
	int round = 0;
	
	
	ifstream firstFile, secondFile;
	string firstWord, secondWord;
	int firstNumber, secondNumber;
	
	// Open Files
	firstFile.open("benim.txt");
	secondFile.open("rakip.txt");
	
	if(firstFile.is_open() && secondFile.is_open()){
		while(firstFile >> firstWord && secondFile >> secondWord){
			
			// converting to int from string for firstTree
			istringstream firstIss (firstWord);
			firstIss >> firstNumber;
			// converting to int from string for secondTree
			istringstream secondIss (secondWord);
			secondIss >> secondNumber;
			
			// adding to the firstTree
			firstTree->add(firstNumber);
			// adding to the secondTree
			secondTree->add(secondNumber);
			
		}
		
		firstFile.close();
		secondFile.close();	
	}
		
	// Game Board
	while(firstTreeScore < 5 && secondTreeScore < 5 && round < 20){
		system("CLS");
				
		cout << "Benim Agac Postorder :" << endl;
		firstTree->printAll();
		cout << endl << "Benim Agac Toplam Soy Sayisi : " << firstTree->getChildsCount() << endl;
		cout << "-------------------------" << endl << endl;
			
		cout << "Rakip Agac Postorder :" << endl;
		secondTree->printAll();
		cout << endl << "Rakip Agac Toplam Soy Sayisi : " << secondTree->getChildsCount() << endl;
		cout << "-------------------------" << endl << endl;
				
		// Victory
		if(firstTree->getChildsCount() < secondTree->getChildsCount()){
			int treeMaxValue = secondTree->getMaxValue();
			int treeRoot = firstTree->getRoot();
			
			firstTree->remove(firstTree->getRoot());
			secondTree->remove(secondTree->getMaxValue());
			firstTree->add(treeMaxValue);
			secondTree->add(treeRoot);
				
			firstTreeScore++;
			
			cout << endl;
			cout << "-- TEBRIKLER TURU KAZANDINIZ --" << endl << endl;
		}
		// Defeat
		else if(firstTree->getChildsCount() > secondTree->getChildsCount()){
			int treeMaxValue = firstTree->getMaxValue();
			int treeRoot = secondTree->getRoot();
			
			secondTree->remove(secondTree->getRoot());
			firstTree->remove(firstTree->getMaxValue());
			secondTree->add(treeMaxValue);
			firstTree->add(treeRoot);
				
			secondTreeScore++;
			
			cout << endl;
			cout << "-- BU TURU KAYBETTINIZ --" << endl << endl;
		}
		// Draw
		else{
			int firstTreeRoot = firstTree->getRoot();
			int secondTreeRoot = secondTree->getRoot();
				
			firstTree->remove(firstTreeRoot);
			secondTree->remove(secondTreeRoot);
			firstTree->add(secondTreeRoot);
			secondTree->add(firstTreeRoot);
		
			cout << endl;
			cout << "--BERABERE--" << endl << endl;
		}
			
		cout << "SKOR" << endl;
		cout << "Benim : " << firstTreeScore << endl;
		cout << "Rakip : " << secondTreeScore << endl << endl;
			
		round++;	
		cin.get();
	}
	
	system("CLS");
	
	if(firstTreeScore > secondTreeScore){
		cout << "TEBRIKLER OYUNU KAZANDINIZ" << endl << endl;	
	}
	else if(firstTreeScore < secondTreeScore){
		cout << "OYUNU KAYBETTINIZ" << endl << endl;
	}
	else{
		cout << "BERABERE" << endl << endl;
	}
	
	delete firstTree;
	delete secondTree;
		
	cin.get();
		
}
