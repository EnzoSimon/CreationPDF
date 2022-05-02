#include "produit.h"
#include <QDebug>


Produit::Produit()
{
    //constructeur vide
}

Produit::Produit(int leNumProduit, QString leNomProduit, QString lesInformationsProduit, QString uneImageProduit, int uneQuantiteProduit)
{
    numeroProduit = leNumProduit;
    quantiteProduit = uneQuantiteProduit;
    nomProduit = leNomProduit;
    informationProduit = lesInformationsProduit;
    imageProduit = uneImageProduit;
}

QString Produit::versChaine()
{
    QString resultat;
    resultat+="<center>";
    resultat+="<img src='"+imageProduit+"'><br>\r\n";
    resultat+="Nom du produit : "+nomProduit+"<br>\r\n";
    resultat+="Informations du produit : "+informationProduit+" <br>\r\n";
    resultat+="Quantité disponible : "+QString::number(quantiteProduit)+"</center><br>\r\n";
    return resultat;
}
