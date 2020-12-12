#include "afficheur_recette.h"
#include "ui_afficheur_recette.h"
#include <QPixmap>

Afficheur_Recette::Afficheur_Recette(QWidget *parent) :
    QMainWindow(parent),
    ui2(new Ui::Afficheur_Recette)
{
    ui2->setupUi(this);
    ui2->labelImage->setPixmap(QPixmap("https:\/\/static.750g.com\/images\/600-600\/7b88d90630c62991df12b34c692aff0d\/sucre-vanille-express.jpg")
}

Afficheur_Recette::~Afficheur_Recette()
{
    delete ui2;
}

