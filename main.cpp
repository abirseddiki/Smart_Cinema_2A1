#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion C;
    bool test = C.createConnexion();
    MainWindow w;

    if (test)
    {
        w.show();
        //qDebug() <<"Connexion reussite";
        QMessageBox::information(nullptr, QObject::tr("database is open") ,
                     QObject::tr("connection succsseful.\n" "Click cancel to exit"), QMessageBox::Cancel);
    }
    else
    {
        //qDebug() <<"Erreur de connexion";
        QMessageBox::critical(nullptr, QObject::tr("database is not open") ,
                     QObject::tr("connection failed.\n" "Click cancel to exit"), QMessageBox::Cancel);
    }



    return a.exec();
}
