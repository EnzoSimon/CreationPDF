#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pdf.h"
#include "passerelle.h"
#include <QDebug>


MainWindow::MainWindow(char *idProducteur, char *laSemaine, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->idProducteur = idProducteur;
    this->semaine = laSemaine;
    brochurePDF();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::brochurePDF()
{
    ui->monPDF->setName("produits.pdf");
    QVector <Rayon> lesRayons;
    lesRayons= Passerelle::chargerLesRayons(idProducteur.toInt(),semaine);
    for(int compteur=0;compteur<lesRayons.size();compteur++) {
        Rayon unRayon=lesRayons.at(compteur);
        QString txt;
        txt=unRayon.versChaine();
        ui->monPDF->ecrireText(txt);
    }
    ui->monPDF->fermer();
}
