/**
* @file BinarySearchTree Project
* @description Text dosyasındaki sayıları okuyup bu sayıları İkili Arama Ağacı'na yerleştirir.
* @course Veri Yapıları - 2/B Grubu
* @assignment Üçüncü Ödev
* @date 09/12/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include "Node.hpp"
template <typename T>
Node<T>::Node(const T &data){
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->childCount = 0;
}
template <typename T>
Node<T>::~Node(){
	cout << "Node nesnesi heap alanindan silindi." << endl;
}