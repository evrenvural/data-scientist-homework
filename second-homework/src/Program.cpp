/**
* @file LinkedList Project
* @description Text dosyasındaki kelimeleri okuyup bu kelimeleri en az maliyetle saklar.
* @course Veri Yapıları - 2/B Grubu
* @assignment İkinci Ödev
* @date 19/11/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <string>
#include "LinkedList.cpp"
#include <fstream>

using namespace std;

int main(){
	LinkedList<string> *list = new LinkedList<string>();
	
	ifstream file;
	file.open("icerik.txt");
	
	string word;
	
	if(file.is_open()){
		while(file >> word){
			list->pushBack(word);
		}
		file.close();
	}
	
	list->printAll();
	
	delete list;
	
	cin.get();
}
