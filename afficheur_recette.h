#ifndef AFFICHEUR_RECETTE_H
#define AFFICHEUR_RECETTE_H

#include <QMainWindow>

namespace Ui {
class Afficheur_Recette;
}

class Afficheur_Recette : public QMainWindow
{
    Q_OBJECT

public:
    explicit Afficheur_Recette(QWidget *parent = nullptr);
    ~Afficheur_Recette();

private:

};

#endif // AFFICHEUR_RECETTE_H
