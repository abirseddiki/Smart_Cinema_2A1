#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "film.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVariant data(const QModelIndex &index, int role) const;
;

private slots:

    void on_ajouter_clicked();

    void on_tableView_films_activated(const QModelIndex &index);

    void on_pushButton_suppFilm_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::MainWindow *ui;
    film tmpFilm;
};
#endif // MAINWINDOW_H
