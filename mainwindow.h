#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPushButton>
#include "ui_afficheur_recette.h"
#include "filedownloader.h"
#include "utilisationrecette.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
namespace Ui {class Afficheur_Recette;}
QT_END_NAMESPACE

/*!
 * \brief Classe affichant la fenêtre d'entrer de la recette
 *
 *  On y affiche une fenêtre et traite le fichier json reçu
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la fenêtre
     *
     *  Utilisation du UI pour une interface fait de façon graphique.
     */
    MainWindow(QWidget *parent = nullptr);

    /*!
     * \brief Destructeur de la fenêtre
     */
    ~MainWindow();


private:
    /*!
     * \brief Constructeur de la fenêtre par l'interface graphique pour la saisie du fichier json.
     */
    Ui::MainWindow *ui;
    /*!
     * \brief Constructeur de la fenêtre par l'interface graphique pour l'affichage de la recette.
     */
    Ui::Afficheur_Recette ui2;
    /*!
     * \brief Le bouton qui active la saisie de fichier.
     */
    QPushButton *Ouvrir;
    /*!
     * \brief Label pour l'image.
     */
    QLabel * labelImage;
    /*!
     * \brief instance d'une classe pour télécharger l'image depuis son lien.
     */
    FileDownloader * m_pImgCtrl;
    /*!
     * \brief Instance de la classe qui construit la recette.
     */
    utilisationRecette * NvRecette;

signals :
    void signalAffichageRecette();
public slots:
    /*!
     * \brief Slot activer par le bouton qui active la saisie et le traitement du fichier json
     */
    void chargerFichier();
    /*!
     * \brief Slot pour activer le processus d'affichage de la fenêtre recette
     */
    void affichageRecette();
    /*!
     * \brief Slot qui affichage une image
     */
    void afficherImage();
};
#endif // MAINWINDOW_H
