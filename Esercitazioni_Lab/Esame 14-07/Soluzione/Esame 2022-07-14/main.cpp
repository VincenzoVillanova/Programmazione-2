#include <iostream>
using namespace std;

#include <fstream>
#include "film.h"
#include "lista.h"
#include "bst.h"

int main()
{
    List<Film> listaFilm;
    BST<Film> BSTFilm;
    ifstream file("film.txt");
    Film *aux;

    if (file.is_open())
    {
        string nome, anno, valutazione;
        int annoi, i = 0;
        double vald;

        while (!file.eof())
        {

            getline(file, nome, ';'); // leggi file e conserva in "nome" tutto quello che sta prima del ;
            getline(file, anno, ';');
            getline(file, valutazione, '\n');

            annoi = stoi(anno);
            vald = stod(valutazione);

            aux = new Film(nome, annoi, vald);

            listaFilm.insertTail(*aux);
        }
    }

    file.close();

    int dim = listaFilm.getSize();
    for (int i = 0; i < dim; i++)
    {
        *aux = listaFilm.getFilm();

        BSTFilm.insert(*aux);
    }

    BSTFilm.preorder();
}