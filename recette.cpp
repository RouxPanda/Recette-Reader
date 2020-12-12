#include "recette.h"
/*
Recette::Recette(QString _nom, QString _description, QString _mot_cle, QPixmap _image, int _tempsCuisson, int _tempsTotal)
    :nom(_nom), description(_description), mot_cle(_mot_cle), image(_image), tempsCuisson(_tempsCuisson), tempsTotal(_tempsTotal)
{
    instructions = new QString[500];
    ingredient = new QString[500];
}
*/

Recette::Recette()
{}

Recette::~Recette()
{}

//Accesseurs
QString Recette::getNom() const
{
    return nom;
}

QString Recette::getDescription() const
{
    return description;
}

QString Recette::getMotCle() const
{
    return mot_cle;
}

QString Recette::getInstructions(int i) const
{
    return instructions[i];
}

QString Recette::getIngredient(int i) const
{
    return ingredient[i];
}


QString Recette::getImage() const
{
    return image;
}

QString Recette::getTempsCuisson() const
{
    return tempsCuisson;
}

QString Recette::getTempsTotal() const
{
    return tempsTotal;
}

size_t Recette::getSizeInstructions() const
{
    return instructions.size();
}

size_t Recette::getSizeIngredient() const
{
    return ingredient.size();
}


//Mutateurs
void Recette::setNom(const QString& v)
{
    nom = v;
}

void Recette::setDescription(const QString& v)
{
    description = v;
}

void Recette::setMotCle(const QString& v)
{
    mot_cle = v;
}

void Recette::setIngredient(const QString& v)
{
    ingredient.push_back(v);
}

void Recette::setInstructions(const QString& v)
{
    instructions.push_back(v);
}

void Recette::setImage(const QString& v)
{
    image = v;
}

void Recette::setTempsCuisson(const QString& v)
{
    tempsCuisson = v;
}

void Recette::setTempsTotal(const QString& v)
{
    tempsTotal = v;
}
