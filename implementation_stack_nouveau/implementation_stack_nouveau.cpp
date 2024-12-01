// implementation_stack_nouveau.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "pch.h"
#include "Stack.cpp"
#include "EmptyException.cpp"
#include "FullException.cpp"

int main()
{
    Stack<int> maPile;
    maPile.empiler(1);
    maPile.empiler(2);
    maPile.empiler(3);
    maPile.empiler(4);
    //affichage
    maPile.afficherStack();
    //depiler
    maPile.depiler();
    maPile.depiler();
    maPile.depiler();
    maPile.depiler();
    maPile.depiler();
}
