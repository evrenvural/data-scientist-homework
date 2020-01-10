/**
* @file LinkedList Project
* @description Text dosyasındaki kelimeleri okuyup bu kelimeleri en az maliyetle saklar.
* @course Veri Yapıları - 2/B Grubu
* @assignment İkinci Ödev
* @date 19/11/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include "LinkedList.hpp"
#include "Node.cpp"

template <typename T>
LinkedList<T>::LinkedList(){
	head = NULL;
	tail = NULL;
	size = 0;
	wordSize = 0;
}
template <typename T>
LinkedList<T>::~LinkedList(){
	Node<T> *temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
		delete temp->prev;
	}
	delete temp;
	cout << "LinkedList nesnesi heap alanindan silindi."<<endl;
}
template <typename T>
int LinkedList<T>::listLength(){
	return size;
}
template <typename T>
int LinkedList<T>::wordLength(){
	return wordSize;
}

template <typename T>
void LinkedList<T>::printAll() {
	Node<T> *temp = head;
	while(temp != NULL){
		cout << temp->data << " - " << temp->position << " |-> ";
		temp = temp->next;
	}
	cout << endl << "Toplam Kazanc : " << totalEarning() << " Byte" << endl <<endl;
}

template <typename T>
int LinkedList<T>::totalEarning() {
	Node<T> *temp = head;
	
	const int ARRAYS_LENGTH = listLength() - wordLength();
	string words[ARRAYS_LENGTH];
	string positions[ARRAYS_LENGTH];
	int arraysIndex = 0;
	int earning = 0;
	
	// fill arrays
	while(temp != NULL){
		// if word is empty
		if(temp->data == ""){
			int index = 0;
			int position = temp->position;
			Node<T> *temp2 = temp;
			
			positions[arraysIndex] = to_string(position);
			
			while(index < temp->position){
				temp2 = temp2->prev;
				index++;
			}
			
			words[arraysIndex] = temp2->data;
			arraysIndex++;
		}
		temp = temp->next;
	}
	
	// count earning
		// words
	for(int i=0; i<ARRAYS_LENGTH; i++){
		for(int j=0; j<words[i].length(); j++){
			earning++;
		}
	}
		// positions
	for(int i=0; i<ARRAYS_LENGTH; i++){
		for(int j=0; j<positions[i].length(); j++){
			earning--;
		}
	}
	
	return earning;
}

template <typename T>
bool LinkedList<T>::isUnique(Node<T> *newItem) {
	
	Node<T> *temp = head;
	int index = 0;
	do {
        if( newItem->data == temp->data){
			newItem->position = listLength() - index;
			return false;
		}
		temp = temp->next;
		index++;
    }
    while(temp != NULL);
	
	return true;
	
}

template <typename T>
void LinkedList<T>::pushBack(const T &data) {
	Node<T> *newItem = new Node<T>(data);
	if (head == NULL) {
		head = newItem;
		tail = newItem;
		wordSize++;
	}
	else {
		if(!isUnique(newItem)){
			newItem->data = "";
		}
		else{
			wordSize++;
		}
		
		tail->next = newItem;
		newItem->prev = tail;
		tail = newItem;
	}
		
	size++;
}