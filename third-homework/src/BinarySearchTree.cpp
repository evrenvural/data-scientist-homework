/**
* @file BinarySearchTree Project
* @description Text dosyasındaki sayıları okuyup bu sayıları İkili Arama Ağacı'na yerleştirir.
* @course Veri Yapıları - 2/B Grubu
* @assignment Üçüncü Ödev
* @date 09/12/2019
* @author Evren VURAL - evren.vural@ogr.sakarya.edu.tr
*/

#include "BinarySearchTree.hpp"
#include "Node.cpp"

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}
template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	
	this->root = makeEmpty(this->root);
	
	cout << "BinarySearchTree nesnesi heap alanindan silindi."<<endl;
}
// PRIVATE
template <typename T>
Node<T> *BinarySearchTree<T>::insert(const T &data, Node<T> *root){
	if (root == NULL)
		root = new Node<T>(data);
	else if (data < root->data)
		root->left = insert(data, root->left);
	else if (data > root->data)
		root->right = insert(data, root->right);
	else if (data == root->data)
		root->left = insert(data, root->left);
	
	return root;
}
template <typename T>
void BinarySearchTree<T>::printWithPostorder(Node<T> *root){
	if (root == NULL) 
        return; 
  
    // first recur on left subtree 
    printWithPostorder(root->left); 
  
    // then recur on right subtree 
    printWithPostorder(root->right); 
  
    // now deal with the node 
    cout << "<" << root->data << "," << root->childCount << "> ";
}
template <typename T>
void BinarySearchTree<T>::calculateChildCountWithPostorder(Node<T> *root, int &counter){
	if (root == NULL) 
        return; 
	counter++;
  
    // first recur on left subtree 
    calculateChildCountWithPostorder(root->left, counter); 
  
    // then recur on right subtree 
    calculateChildCountWithPostorder(root->right, counter);
}
template <typename T>
void BinarySearchTree<T>::addChildCountsToNodesWithPostorder(Node<T> *root){
	if (root == NULL) 
        return;
  
    // first recur on left subtree 
    addChildCountsToNodesWithPostorder(root->left); 
  
    // then recur on right subtree 
    addChildCountsToNodesWithPostorder(root->right);
	
	// now deal with the node
	int counter = 0;
	calculateChildCountWithPostorder(root, counter);
	// calculateChildCountWithPostorder calculated (result + 1) 
	root->childCount = counter - 1;
}
template <typename T>
void BinarySearchTree<T>::calculateAllOfNodesChildCount(Node<T> *root, int &counter){
	if (root == NULL) 
        return; 
  
    // first recur on left subtree 
    calculateAllOfNodesChildCount(root->left, counter); 
  
    // then recur on right subtree 
    calculateAllOfNodesChildCount(root->right, counter); 
  
    // now deal with the node 
    counter+=root->childCount;
}
template <typename T>
Node<T> *BinarySearchTree<T>::findMax(Node<T> *root) {
    if(root == NULL)
		return NULL;
    else if(root->right == NULL)
        return root;
    else
        return findMax(root->right);
}
template <typename T>
Node<T> *BinarySearchTree<T>::remove(const int &data, Node<T>* root) {
    Node<T> *temp;
    if(root == NULL)
		return NULL;
    else if(data < root->data)
		root->left = remove(data, root->left);
    else if(data > root->data)
		root->right = remove(data, root->right);
    else if(root->left && root->right)
    {
		temp = findMax(root->left);
        root->data = temp->data;
        root->left = remove(root->data, root->left);
    }
    else
    {
		temp = root;
        if(root->left == NULL)
			root = root->right;
        else if(root->right == NULL)
			root = root->left;
			delete temp;
        }
        return root;
}
template <typename T>
Node<T> *BinarySearchTree<T>::makeEmpty(Node<T> *root){
	if(root == NULL)
            return NULL;
	else {
		makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }
    return NULL;
}

//PUBLIC
template <typename T>
void BinarySearchTree<T>::add(const T &data){
	this->root = insert(data, this->root);
	addChildCountsToNodesWithPostorder(this->root);
}
template <typename T>
void BinarySearchTree<T>::printAll(){
	printWithPostorder(this->root);
}
template <typename T>
int BinarySearchTree<T>::getChildsCount(){
	int counter = 0;
	calculateAllOfNodesChildCount(this->root, counter);
	
	return counter;
}
template <typename T>
int BinarySearchTree<T>::getMaxValue(){
	Node<T> *maxNode = findMax(this->root);
	
	return maxNode->data;
}
template <typename T>
void BinarySearchTree<T>::remove(const int &data){
	this->root = remove(data, this->root);
}
template <typename T>
T BinarySearchTree<T>::getRoot(){
	return this->root->data;
}