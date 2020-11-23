#include "film.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QStringListModel>

film::film()
{
    this->id = 0;
    nom = "";
    genre = "";
    description = "";
    duree = "";
    date_sortie = QDate::currentDate();
}

film::film(int id, QString nom, QString genre, QString description, QString duree, QDate date_sortie)
{
    this->id = id;
    this->nom = nom;
    this->genre = genre;
    this->description = description;
    this->duree = duree;
    this->date_sortie = date_sortie;
}

bool film::ajouter()
{
    QSqlQuery query;
    query.prepare("Insert into film (id, nom, genre,description, duree, date_sortie)"
                  "Values(:id, :nom, :genre, :description, :duree, :date_sortie)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":genre", genre);
    query.bindValue(":description", description);
    query.bindValue(":duree", duree);
    query.bindValue(":date_sortie", date_sortie);
    return query.exec();

}

QSqlQueryModel * film::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from film");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Genre"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Durée"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de sortie"));

    return model;
}

bool film::modifier(int id, QString nom, QString genre, QString description, QString duree, QDate date_sortie)
{
    QSqlQuery query;
    query.prepare("UPDATE film SET id= :id,nom= :nom,genre=:genre,description = :description,"
                  "duree=:duree,date_sortie = :date_sortie WHERE id = :id");
      query.bindValue(":id", id);
      query.bindValue(":nom",nom );
      query.bindValue(":genre", genre);
      query.bindValue(":description", description);
      query.bindValue(":duree", duree);
      query.bindValue(":date_sortie", date_sortie);

    return query.exec();
}


bool film::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE from film where id = :id");
    query.bindValue(":id", res);
    return query.exec();
}

