#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include "poste.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>
#include <QSqlTableModel>
#include <QDebug>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ae_pushButton_clicked();

    void on_se_pushButton_clicked();

    void on_mail_pushButton_clicked();

    void on_stat_pushButton_clicked();

    void on_pushButton_modifierE_clicked();

    void on_ap_pushButton_clicked();

    void on_mp_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Employe tmp_employe;
    poste tmp_poste;

};
#endif // MAINWINDOW_H
