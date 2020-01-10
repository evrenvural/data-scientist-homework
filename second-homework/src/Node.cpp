/**
* @file LinkedList Project
* @description Text dosyasındaki kelimeleri okuyup bu kelimeleri en az maliyetle saklar.
* @course Veri Yapıları - 2/B Grubu
* @assignment İkinci Ödev
* @date 19/11/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include "Node.hpp"
template <typename T>
Node<T>::Node(const T &data){
	this->data = data;
	this->prev = NULL;
	this->next = NULL;
	position = 0;
}
template <typename T>
Node<T>::~Node(){
	cout <<"Node nesnesi heap alanindan silindi."<<endl;
}