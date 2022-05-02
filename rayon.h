#ifndef RAYON_H
#define RAYON_H

#include <QVector>

#include "variete.h"

class Rayon
{
private:
    int numRayon;
    QString nomRayon;
    QVector<Variete> lesVarietes;

public:
    Rayon();
    Rayon(int leNumRayon,QString leNomRayon, QVector<Variete> sesVarietes);
    QString versChaine();
};

#endif // RAYON_H
