/**
* @file LinkedList Project
* @description Text dosyasındaki kelimeleri okuyup bu kelimeleri en az maliyetle saklar.
* @course Veri Yapıları - 2/B Grubu
* @assignment İkinci Ödev
* @date 19/11/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#ifndef LINKED_HPP
#define LINKED_HPP

using namespace std;

#include "Node.hpp"
#include <iostream>

template <typename T>
	class LinkedList{
		private:
			Node<T> *head, *tail;
			int size;
			int wordSize;
			
			bool isUnique(Node<T>*);
			int totalEarning();
			
		public:
			LinkedList();
			~LinkedList();
			int listLength();
			int wordLength();
			void printAll();
			void pushBack(const T&);
	};
	
#endif