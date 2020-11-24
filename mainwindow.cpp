#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "film.h"
#include <QMessageBox>
#include <QDate>
#include <QString>
#include <QDateEdit>
#include <QModelIndex>
#include <QSqlQuery>
#include <QSqlTableModel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_films->setModel(tmpFilm.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString genre = ui->lineEdit_genre->text();
    QString description = ui->lineEdit_descrip->text();
    QString duree = ui->lineEdit_duree->text();
    QDate date_sortie = ui->dateEdit_ds->date();
    film f(id, nom, genre, description, duree, date_sortie);
    if (id!=0 && id>0)
    {
        bool test = f.ajouter();
        if(test)
        {
            ui->tableView_films->setModel(tmpFilm.afficher());
            QMessageBox::information(nullptr, QObject::tr("Ajout film") ,
                     QObject::tr("Film ajouté avec succès.\n" "Click cancel to exit"), QMessageBox::Cancel);
        }
    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajout film") ,
                     QObject::tr("Ajout échoué.\n" "Click cancel to exit"), QMessageBox::Cancel);
        }
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>())
    {
    widget->clear();
    }
}


void MainWindow::on_tableView_films_activated(const QModelIndex &index)
{
    QString id = ui->tableView_films->model()->data(index).toString();
    QSqlQuery query;
    query.prepare(" select * from film where id = '"+id+"'");
    if(query.exec())
    {
        while (query.next())
        {
            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_nom->setText(query.value(1).toString());
            ui->lineEdit_genre->setText(query.value(2).toString());
            ui->lineEdit_descrip->setText(query.value(3).toString());
            ui->lineEdit_duree->setText(query.value(4).toString());
           // ui->dateEdit_ds->setDate(query.value(5));
        }
    }
    ui->tableView_films->setStyleSheet("QTableView { selection-color: black; selection-background-color: orange; }");

}



void MainWindow::on_pushButton_update_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString genre = ui->lineEdit_genre->text();
    QString description = ui->lineEdit_descrip->text();
    QString duree = ui->lineEdit_duree->text();
    QDate date_sortie = ui->dateEdit_ds->date();
    bool test = tmpFilm.modifier(id, nom, genre, description, duree, date_sortie);
    if (test)
    {
           ui->tableView_films->setModel(tmpFilm.afficher());
           QMessageBox::information(nullptr, QObject::tr("Modification film") ,
                QObject::tr("Film modifié avec succès.\n" "Click cancel to exit"), QMessageBox::Cancel);
    }
    else
    {
            QMessageBox::critical(nullptr, QObject::tr("Modification film") ,
                QObject::tr("Modification échoué.\n" "Click cancel to exit"), QMessageBox::Cancel);
    }
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>())
    {
             widget->clear();
    }
}


void MainWindow::on_pushButton_suppFilm_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test = tmpFilm.supprimer(id);
    if (test)
    {
        ui->tableView_films->setModel(tmpFilm.afficher());
        QMessageBox::information(nullptr, QObject::tr("Suppression film") ,
                     QObject::tr("Film supprimé avec succès.\n" "Click cancel to exit"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Suppresion film") ,
                     QObject::tr("Suppression échoué.\n" "Click cancel to exit"), QMessageBox::Cancel);
    }
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

