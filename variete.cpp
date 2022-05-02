#include "variete.h"
#include <QDebug>

Variete::Variete()
{
    //Constructeur vide
}

Variete::Variete(int numVariete, QString leNomVariete, QVector<Produit> sesProduits)
{
    numeroVariete=numVariete;
    nomVariete=leNomVariete;
    lesProduits=sesProduits;
}

QString Variete::versChaine()
{
    QString resultat;

    resultat +="<center><style>h3 {color:#3182eb;}</style><h3>Variété : "+nomVariete+"</h3></center><br>";

    for(int i=0;i<lesProduits.size(); i++) {
        resultat+=lesProduits[i].versChaine();
    }
    return resultat;
}

