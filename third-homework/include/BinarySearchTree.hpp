/**
* @file BinarySearchTree Project
* @description Text dosyasındaki sayıları okuyup bu sayıları İkili Arama Ağacı'na yerleştirir.
* @course Veri Yapıları - 2/B Grubu
* @assignment Üçüncü Ödev
* @date 09/12/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

using namespace std;

#include "Node.hpp"
#include <iostream>

template <typename T>
	class BinarySearchTree{
		private:
			Node<T> *root;
			Node<T> *insert(const T&, Node<T>*);
			Node<T> *findMax(Node<T>*);
			Node<T> *remove(const int&, Node<T>*);
			Node<T> *makeEmpty(Node<T>*);
			void printWithPostorder(Node<T> *); 
			void calculateChildCountWithPostorder(Node<T> *, int&); 
			void addChildCountsToNodesWithPostorder(Node<T> *);
			void calculateAllOfNodesChildCount(Node<T>*, int&);
		public:
			BinarySearchTree();
			~BinarySearchTree();
			
			void add(const T&);
			void printAll();
			int getChildsCount();
			int getMaxValue();
			void remove(const int &);
			T getRoot();
	};
	
#endif