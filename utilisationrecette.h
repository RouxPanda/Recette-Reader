#ifndef UTILISATIONRECETTE_H
#define UTILISATIONRECETTE_H

#include <QObject>
#include <QFile>

#include "recette.h"

/*!
 * \brief Classe faisant le pont entre Recette et MainWindow
 *
 *  Pour le tye MVC, cette classe peut être qualifié de "Controleur"
 *  permettant de controler le stockage de la recette et de pourvoir l'affichage ensuite
 */
class utilisationRecette: public QObject
{
    Q_OBJECT
private:
    Recette recette;
public:
    /*!
     * \brief Constructeurs de la classe utilisationRecette
     *
     * Constructeurs qui va lire le fichier Json en paramètre pour construire une instance de la classe Recette avec les données du fichier.
     * \param  <json_string> {Ensemble du fichier Json en String}
     */
    utilisationRecette(QString);
    /*!
     * \brief Destructeur de la classe utilisationRecette
     *
     */
    ~utilisationRecette();

    inline Recette * GetRecette(){ return &recette; }

signals :
    void signalAffichageRecette();
    void signalCreation();

public slots:
    void creation();
};

#endif // UTILISATIONRECETTE_H
