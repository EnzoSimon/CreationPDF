#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>

class Produit
{
private:
    int numeroProduit,quantiteProduit;
    QString nomProduit, informationProduit,imageProduit;

public:
    Produit();
    Produit(int leNumProduit, QString leNomProduit, QString lesInformationsProduit,QString uneImageProduit, int uneQuantiteProduit);
    QString versChaine();
};

#endif // PRODUIT_H
