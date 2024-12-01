#pragma once
#include "pch.h"


template <class T>
class Stack
{
private:
	T* tab;
	int capacityMax;
	int sommet;
public:
	Stack(); //constructeur
	bool isEmpty();
	bool isFull();
	void empiler(T val); //fonction empiler
	T depiler(); //fonction depiler
	void afficherStack();
};




//------------------------------------------------------------
template<class T>
inline Stack<T>::Stack(): capacityMax(3),sommet(-1)
{
//initialisation de tableau
	this->tab = new T[3]; 
}



//------------------------------------------------------------
template<class T>
inline bool Stack<T>::isEmpty()
{
	return this->sommet==-1;
}



//------------------------------------------------------------
template<class T>
inline bool Stack<T>::isFull()
{
	return this->sommet == this->capacityMax-1;
}



//------------------------------------------------------------
template<class T>
inline void Stack<T>::empiler(T val)
{
try
{
	if (this->isFull())
		throw FullException(" la pile est pleine !");
}
catch (FullException& e)
{
	cout << e.what() << endl;
	//on peut gerer le probleme ( on fait le resize)
	T* tab_temp = new T[capacityMax];
	this->capacityMax *=2;
	cout << " la nouvelle capacity est " << this->capacityMax << endl;
	//creer une nouvelle pile avec la nouvelle taille
	T* newPile = new T[capacityMax];
	//on initialiser letableau temp
	for (int i = 0;i <= sommet;i++)
	{
		tab_temp[i] = this->tab[i];
	}
	// on recopie vers la nouvelle pile
	for (int i = 0;i <= sommet;i++)
	{
		newPile[i] = tab_temp[i];
	}
	//on supprime le tableau temporaire
	delete[] tab_temp;
	delete[] this->tab; //on le vide
	this->tab = newPile;
}
//puis on fait l'empilement ici
this->tab[++sommet] = val;
}


//------------------------------------------------------------
template<class T>
inline T Stack<T>::depiler()
{

try 
{
	if (this->isEmpty())
		throw EmptyException(" la pile est vide ! on peut pas depiler");
	else // on depile
	{
		T obj = this->tab[this->sommet];
		this->sommet--;
		return obj;
	}
}
catch (EmptyException& e)
{
	cout << e.what() << endl;
}
}


//------------------------------------------------------------
template<class T>
inline void Stack<T>::afficherStack()
{
//si la pile est vide on lance exception
try
{
	if (this->isEmpty())
		throw EmptyException(" la pile est vide ! rien a afficher");
	else
	{
		cout << "\n\n ### affichage de la pile ###" << endl;
		cout << " Sommet|";
		for (int i = this->sommet;i >= 0;i--)
			cout <<  this->tab[i]<< "|";
		cout << "Base " << endl;
	}
}
catch (EmptyException& e)
{
	cout << e.what() << endl;
}
}
