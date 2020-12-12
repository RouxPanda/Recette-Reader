#ifndef RECETTE_H
#define RECETTE_H

#include <QString>
#include <QStringList>

/*!
 * \brief Classe type de la Recette
 *
 *  Ensemble des données du fichier json pour stocker la recette en entier
 */
class Recette
{
private:
    QString nom,
            description,
            mot_cle,
            tempsCuisson,
            tempsTotal,
            image;
    QStringList ingredient, instructions;

public:
//    Recette(QString _nom, QString _description, QString _mot_cle, QPixmap _image, int _tempsCuisson, int _tempsTotal);
    Recette();
    ~Recette();

    //Accesseurs
    QString getNom() const;
    QString getDescription() const;
    QString getMotCle() const;
    QString getImage() const;
    QString getTempsCuisson() const;
    QString getTempsTotal() const;
    QString getInstructions(int i) const;
    QString getIngredient(int i) const;

    size_t getSizeInstructions() const;
    size_t getSizeIngredient() const;

    //Mutateurs
    void setNom(const QString& v);
    void setDescription(const QString& v);
    void setMotCle(const QString& v);
    void setIngredient(const QString& v);
    void setInstructions(const QString& v);
    void setImage(const QString& v);
    void setTempsCuisson(const QString& v);
    void setTempsTotal(const QString& v);
};

#endif // RECETTE_H
