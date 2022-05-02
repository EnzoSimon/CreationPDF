#ifndef VARIETE_H
#define VARIETE_H

#include <QVector>
#include "produit.h"


class Variete
{
private:
    QString nomVariete;
    int numeroVariete;
    QVector<Produit> lesProduits;

public:
    Variete();
    Variete(int numVariete, QString leNomVariete, QVector<Produit> sesProduits);
    QString versChaine();
};

#endif // VARIETE_H
