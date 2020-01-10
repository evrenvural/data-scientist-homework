/**
* @file BinarySearchTree Project
* @description Text dosyasındaki sayıları okuyup bu sayıları İkili Arama Ağacı'na yerleştirir.
* @course Veri Yapıları - 2/B Grubu
* @assignment Üçüncü Ödev
* @date 09/12/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP

#include "Node.hpp"
#include <iostream>

	template <typename T>
	class Node{
		public:
			Node<T> *left, *right;
			int childCount;
			T data;
			
			Node(const T&);
			~Node();
	};
	
#endif