#include "rayon.h"
#include "jeuenregistrement.h"

#include <QVariant>
#include <QDebug>

Rayon::Rayon()
{
    //Constructeur vide
}

Rayon::Rayon(int leNumRayon, QString leNomRayon, QVector<Variete> sesVarietes)
{
    numRayon=leNumRayon;
    nomRayon=leNomRayon;
    lesVarietes=sesVarietes;
}

QString Rayon::versChaine()
{
    QString resultat;

    resultat +="<center><style>h1 {color:#ff401f;}</style><h1>Rayon "+nomRayon+"</h1></center><br>";

    for(int i=0;i<lesVarietes.size(); i++) {
        resultat+=lesVarietes[i].versChaine();
    }
    return resultat;
}
