#include "passerelle.h"
#include <QDebug>



QVector<Produit> Passerelle::chargerLesProduits(int idVariete, int idProducteur, QString semaine)
{
    QVector<Produit> resultat;
    QString requete;

    requete = "SELECT DISTINCT Produit.numeroProduit,nomProduit,informationProduit,imageProduit,quantiteProduit "
              "FROM Produit "
              "INNER JOIN Produire ON Produit.numeroProduit=Produire.numeroProduit "
              "WHERE Produit.numeroVariete="+QString::number(idVariete)+" AND Produire.numeroProducteur="+QString::number(idProducteur)+" AND Produire.numeroSemaine="+semaine;
    qDebug()<<requete;

    JeuEnregistrement monJeu(requete);

    while(monJeu.fin()){
        int leId=monJeu.getValeur("numeroProduit").toInt();
        QString leNom=monJeu.getValeur("nomProduit").toString();
        QString lesInfos=monJeu.getValeur("informationProduit").toString();
        QString lImage=monJeu.getValeur("imageProduit").toString();
        int laQuantite=monJeu.getValeur("quantiteProduit").toInt();

        resultat.push_back(Produit(leId,leNom,lesInfos,lImage,laQuantite));

        monJeu.suivant();
    }
    return resultat;
}




QVector<Variete> Passerelle::chargerLesVarietes(int idRayon, int idProducteur, QString semaine)
{
    QVector<Variete> resultat;
    QString requete;

    requete = "SELECT DISTINCT Variete.numeroVariete,nomVariete "
              "FROM Variete "
              "INNER JOIN Produit ON Variete.numeroVariete=Produit.numeroVariete "
              "INNER JOIN Produire ON Produit.numeroProduit=Produire.numeroProduit "
              "WHERE Variete.numeroRayon="+QString::number(idRayon)+" AND Produire.numeroProducteur="+QString::number(idProducteur)+" AND Produire.numeroSemaine="+semaine;
    qDebug()<<requete;

    JeuEnregistrement monJeu(requete);

    while(monJeu.fin()){
        int leId=monJeu.getValeur("numeroVariete").toInt();
        QString leNom=monJeu.getValeur("nomVariete").toString();

        QVector<Produit> lesProduits;
        lesProduits=chargerLesProduits(leId,idProducteur,semaine);

        resultat.push_back(Variete(leId,leNom,lesProduits));

        monJeu.suivant();
    }
    return resultat;
}

QVector<Rayon> Passerelle::chargerLesRayons(int idProducteur, QString semaine)
{
    QVector<Rayon> resultat;
    QString requete;

    requete = "SELECT DISTINCT Rayon.numeroRayon,nomRayon,informationProduit,imageProduit,quantiteProduit "
              "FROM Rayon "
              "INNER JOIN Variete ON Rayon.numeroRayon=Variete.numeroRayon "
              "INNER JOIN Produit ON Variete.numeroVariete=Produit.numeroVariete "
              "INNER JOIN Produire ON Produit.numeroProduit=Produire.numeroProduit "
              "WHERE Produire.numeroProducteur="+QString::number(idProducteur)+" AND Produire.numeroSemaine="+semaine;
    qDebug()<<requete;

    JeuEnregistrement monJeu(requete);

    while(monJeu.fin()){
        int leId=monJeu.getValeur("numeroRayon").toInt();
        QString leNom=monJeu.getValeur("nomRayon").toString();

        QVector <Variete> lesVarietes;
        lesVarietes=chargerLesVarietes(leId, idProducteur, semaine);

        resultat.push_back(Rayon(leId,leNom,lesVarietes));

        monJeu.suivant();
    }
    return resultat;
}
