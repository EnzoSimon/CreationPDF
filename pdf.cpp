#include "pdf.h"

#include <QTextBrowser>
#include <QPdfWriter>
#include <QDebug>


PDF::PDF(QWidget* parent):QTextBrowser(parent)
{

}

void PDF::ecrireText(QString leTexte)
{
    //Ecrit le texte
    setHtml(toHtml()+"<p>"+leTexte+"</p>");
}

void PDF::chargerImage(QString chemin)
{
    //Ecrit l'image
    setHtml(toHtml()+"<img src="+chemin+"\"/>");
}

void PDF::fermer()
{
    //Ferme le PDF en l'enregistrant
    QPdfWriter* printer = new QPdfWriter(nomDoc);
    printer -> newPage();
    printer -> setTitle("CircuitCourt : Catalogue des produits");
    //printer -> setPageSize(QPdfWriter::A4);
    print(printer);
}

void PDF::setName(QString nomDocument)
{
    nomDoc = nomDocument;
}
