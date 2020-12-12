#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recette.h"
#include "filedownloader.h"
#include "utilisationrecette.h"

#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonValue>
#include <QJsonArray>
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //On créer la fenêtre de départ avec le bouton ouvrir
    ui->setupUi(this);
    QPushButton *Ouvrir = new QPushButton("&Charger", this);
    ui->horizontalLayout->addWidget(Ouvrir);

    //Quand on click sur le bouton ouvrir on lance la procédure pour choisir et traiter un fichier Json
    connect(Ouvrir, SIGNAL(clicked()), this, SLOT(chargerFichier()));
    //Quand le signalAffichageRecette est appellé on lance le slot affichageRecette pour afficher la recette
    connect(this, SIGNAL(signalAffichageRecette()), this, SLOT(affichageRecette()));

}

void MainWindow::chargerFichier()
{

    //Saisie du fichier en .json
    QString NomFichier = QFileDialog::getOpenFileName(this, tr("Ouvrir Fichier Recette"), "", tr("Fichier Json (*.json);;All Files (*)"));

    //test, le fichier est-il vide ?
    if (NomFichier.isEmpty())
        return;
    else
    {
        QFile fichier(NomFichier);
        //test, le fichier s'ouvre t'il ?
        if (!fichier.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this ,tr("Impossible d'ouvrir le fichier"),fichier.errorString());
            return;
        }
        else
        {
            QTextStream file_text(&fichier);
            QString json_string = file_text.readAll();
            fichier.close();

            //une fois valide on instance l'utilisationrecette qui créera la recette depuis le json
            NvRecette = new utilisationRecette(json_string);
            //et on affiche la nouvelle fenêtre par ce signal
            emit signalAffichageRecette();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete NvRecette;
}


void MainWindow::affichageRecette()
{
    //On créer la deuxième fenêtre
    ui2.setupUi(this);

    //On affiche toutes les infos avec la recette importé
    ui2.labelNom->setText(NvRecette->GetRecette()->getNom());
    ui2.labelDesc->setText(NvRecette->GetRecette()->getDescription());
    ui2.labelTempsTotale->setText(NvRecette->GetRecette()->getTempsTotal());
    ui2.labelTempsCuisson->setText(NvRecette->GetRecette()->getTempsCuisson());
    ui2.labelMotsCles->setText(NvRecette->GetRecette()->getMotCle());

    QString temp;
    for (size_t x=0; x< (NvRecette->GetRecette()->getSizeIngredient()) ; x++) {
        temp.append(NvRecette->GetRecette()->getIngredient(x));
        temp += "<br>";
    }
    ui2.labelIngredient->setText(temp);

    //On y intègre aussi l'url de l'image et on l'affiche par le connect
    QUrl imageUrl(NvRecette->GetRecette()->getImage());
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (afficherImage()));
}

void MainWindow::afficherImage()
{
    labelImage = new QLabel(this);
    QPixmap buttonImage;
    //on donne l'image au label
    buttonImage.loadFromData(m_pImgCtrl->downloadedData());
    labelImage->setPixmap(buttonImage);
    ui2.layoutImage->addWidget(labelImage);
    labelImage->setPixmap(buttonImage.scaled(350,350,Qt::KeepAspectRatio));
}
