#ifndef PASSERELLE_H
#define PASSERELLE_H

#include <QVector>
#include <QVariant>

#include "produit.h"
#include "variete.h"
#include "jeuenregistrement.h"
#include "rayon.h"


class Passerelle
{
public:
    static QVector<Produit> chargerLesProduits(int idVariete, int idProducteur, QString semaine);
    static QVector<Variete> chargerLesVarietes(int idRayon,int idProducteur, QString semaine);
    static QVector<Rayon> chargerLesRayons(int idProducteur, QString semaine);

};

#endif // PASSERELLE_H
