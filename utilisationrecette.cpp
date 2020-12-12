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
#include <QIODevice>

utilisationRecette::utilisationRecette(QString json_string)
{
    QByteArray json_bytes = json_string.toLocal8Bit();

    auto json_doc = QJsonDocument::fromJson(json_bytes);
    QJsonObject recetteJson = json_doc.object();

    recette.setNom((recetteJson.value("name")).toString());
    recette.setDescription(recetteJson.value("description").toString());
    recette.setMotCle(recetteJson.value("keywords").toString());
    recette.setTempsCuisson(recetteJson.value("cookTime").toString());
    recette.setTempsTotal(recetteJson.value("totalTime").toString());
    recette.setImage(recetteJson.value("image").toString());

    QJsonValue val = recetteJson.value("recipeIngredient");
    QJsonArray valArray = val.toArray();
    QString temp;
    for (auto value: valArray)
    {
        qDebug() << "ingredient " << value.toString();
        temp = value.toString();
        recette.setIngredient(temp);
    }

    val = recetteJson.value("recipeInstructions");
    valArray = val.toArray();
    for (auto value: valArray)
    {
        qDebug() << "instruction " << value.toString();
        temp = value.toString();
        recette.setInstructions(temp);
    }
/*
    QJsonValue ins = recetteJson.value("recipeInstructions");
    size_t i=0;
    QJsonArray valArrayIns = ins.toArray();
    qDebug() << ins.isArray();
    for (auto value: valArrayIns)
    {
        recette.setIngredient(value.toString(),i);
        i+=1;
    }

    QJsonValue ing = recetteJson.value("recipeIngredient");
    i=0;
    QJsonArray valArrayIng = ing.toArray();

    for (auto value: valArrayIng)
    {
        recette.setIngredient(value.toString(),i);
        i+=1;
    }*/

    qDebug() << "Nom " << recette.getNom();
    qDebug() << "Description : " << recette.getDescription();
    qDebug() << "key " << recette.getMotCle();
    qDebug() << "cookTime : " << recette.getTempsCuisson();
    qDebug() << "cookTotal : " << recette.getTempsTotal();
    qDebug() << recette.getSizeIngredient();
    qDebug() << recette.getSizeInstructions();
    for (size_t w=0; w<recette.getSizeInstructions(); w++) {
        qDebug() << "Instructions : " << recette.getInstructions(w);
    }
    for (size_t x=0; x<recette.getSizeIngredient(); x++) {
        qDebug() << "Ingredient : " << recette.getIngredient(x);
    }

}

utilisationRecette::~utilisationRecette()
{}

void utilisationRecette::creation()
{

    /*
        qDebug() << "Nom " << (recetteJson.value("name")).toString();
        qDebug() << "Description : " << (recetteJson.value("description")).toString();
        QJsonValue val = recetteJson.value("recipeIngredient");
        //qDebug() << val.isArray();

        QJsonArray valArray = val.toArray();
        for (auto value: valArray)
            qDebug() << "ingredient " << value.toString();

        val = recetteJson.value("recipeInstructions");
        valArray = val.toArray();
        for (auto value: valArray)
            qDebug() << "instruction " << value.toString();

        qDebug() << "Total time : " << (recetteJson.value("totalTime")).toString();
        qDebug() << "URL : " << (recetteJson.value("url")).toString();*/
}



