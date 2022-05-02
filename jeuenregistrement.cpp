#include "jeuenregistrement.h"

#include <QVariant>
#include <QDebug>

/**
 * @brief Constructeur de la classe
 * @param chaineSql: QString requête SQL a exécuter
 * Permet de ce placer sur le premier enregistrement
 */

JeuEnregistrement::JeuEnregistrement()
{
}

JeuEnregistrement::JeuEnregistrement(QString chaineSql):QSqlQuery (chaineSql)
{
    //Ouvre la requête et place sur le premier enregistrement
    first();
}

/**
 * @brief JeuEnregistrement::suivant
 * Permet de passer à l'enregistrement suivant
 */

void JeuEnregistrement::suivant()
{
    next();
}

/**
 * @brief JeuEnregistrement::fin
 * Vérifie si on a exécuté l'ensemble des requête SQL
 * @return Bool renvoie un booléen pour confirmer la fin de l'ecture des resultats de la requête SQL
 */

bool JeuEnregistrement::fin()
{
    return isValid();
}

/**
 * @brief JeuEnregistrement::getValeur
 * @param nomChamp: QString nom de l'élément du résultat de la requête SQL à traiter
 * @return QString renvoie le nom de l'élément du résultat de la requête SQL
 */

QVariant JeuEnregistrement::getValeur(QString nomChamp)
{
    return value(nomChamp);
}

/**
 * @brief JeuEnregistrement::fermer
 * Permet de fermer la requête SQL
 * @warning Méthode présente dans le sujet d'examen que nous n'avons pas traité (donc ne fonctionne pas)
 */

void JeuEnregistrement::fermer()
{
    //fermeture de la requête
    //nothing to do
}
