/*
 * BinarySearchTree.h
 *
 *  Created on: Nov 2, 2018
 *      Author: erik
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* left;
	node<T>* right;
};
template <class T>
class BinarySearchTree{
	node<T>* root;
public:
	BinarySearchTree(){
		root = NULL;
	}
	void insert(T&);
	void printPreOrder();
	void printPostOrder();
	void printInOrder();
	T findMax(T&);
	T search(T&);
	void deleteNode(T&);
	/*
	bool search(T&);
	void deleteNode(T&);
	int height();

	T findMin();
	*/
private:
	void insert(node<T>*& p, T&);
	void printPreOrder(node<T>* p);
	void printPostOrder(node<T>* p);
	void printInOrder(node<T>* p);
	T findMax(node<T>* p, T& e);
	T search(node<T>*, T&);
	void deleteNode(node<T>*&, T&);

};

template <class T>
void BinarySearchTree<T>::deleteNode(T& item){
	deleteNode(root, item);
}
template <class T>
void BinarySearchTree<T>::deleteNode(node<T>*& p, T& item){
	if(p == NULL)
		return;
	if(item<p->data)
		deleteNode(p->left, item);
	else if(item>p->data)
		deleteNode(p->right, item);
	else{ //found node
		if(p->right!=NULL && p->left!=NULL){ //a node with two children
			T max = findMax(p->left, item);
			p->data = max;
			deleteNode(p->left, max);
		}else{
			node<T>* q = p;
			if(p->left!=NULL) //a node with only one left child
				p = p->left;
			if(p->right!=NULL) //a node with only one right child
				p = p->right;
			else
				p= NULL;
			delete q;
		}
	}

}

template <class T>
T BinarySearchTree<T>::search(T& item){
	return search(root, item);
}
template <class T>
T BinarySearchTree<T>::search(node<T>* p, T& item){
	if(p == NULL)
		return item;
	else if(item<p->data)
		return search(p->left, item);
	else if(item>p->data)
		return search(p->right, item);
	else
		return p->data;

}
template <class T>
T BinarySearchTree<T>::findMax(T& e){
	return findMax(root, e);
}
template<class T>
T BinarySearchTree<T>::findMax(node<T>* p, T& e){
	if(p==NULL){
		return e; //!!!
	}
	else if (p->right==NULL){
		return p->data;
	}
	else{
		return findMax(p->right, e);
	}
}

template <class T>
void BinarySearchTree<T>::printPreOrder(){
	printPreOrder(root);
}
template <class T>
void BinarySearchTree<T>::printPreOrder(node<T>* p){
	if(p!=NULL){
		cout<<p->data<<endl;
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}
template <class T>
void BinarySearchTree<T>::printInOrder(){
	printInOrder(root);
}
template <class T>
void BinarySearchTree<T>::printInOrder(node<T>* p){
	if(p!=NULL){
		printInOrder(p->left);
		cout<<p->data<<endl;
		printInOrder(p->right);
	}
}
template <class T>
void BinarySearchTree<T>::printPostOrder(){
	printPostOrder(root);
}
template <class T>
void BinarySearchTree<T>::printPostOrder(node<T>* p){
	if(p!=NULL){
		printPostOrder(p->left);
		printPostOrder(p->right);
		cout<<p->data<<endl;
	}
}
template<class T>
void BinarySearchTree<T>::insert(T& item){
	insert(root, item);
}
template<class T>
void BinarySearchTree<T>::insert(node<T>*& p, T& item){
	if(p==NULL){
		p = new node<T>;
		p -> data = item;
		p -> left = p-> right = NULL;
	}else if(item < p -> data){
		insert (p -> left, item);
	}else{
		insert (p-> right, item);
	}
}



#endif /* BINARYSEARCHTREE_H_ */
