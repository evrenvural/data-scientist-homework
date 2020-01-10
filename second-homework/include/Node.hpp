/**
* @file LinkedList Project
* @description Text dosyasındaki kelimeleri okuyup bu kelimeleri en az maliyetle saklar.
* @course Veri Yapıları - 2/B Grubu
* @assignment İkinci Ödev
* @date 19/11/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP

#include "Node.hpp"
#include <iostream>

	template <typename T>
	class Node{
		public:
			Node<T> *prev, *next;
			T data;
			int position;
			
			Node(const T&);
			~Node();
	};
	
#endif