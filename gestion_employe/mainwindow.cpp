#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_employe->setModel(tmp_employe.afficher());
    ui->tableView_employe->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_employe->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ae_pushButton_clicked()
{
    QString NOM = ui->lineEdit_NE->text();
    QString PRENOM = ui->lineEdit_PE->text();
    int CIN = ui->lineEdit_CinE->text().toInt();
    int POSTE = ui->lineEdit_PosteE->text().toInt();
    QString MAIL = ui->lineEdit_mailE->text();
    Employe Employe(NOM, PRENOM, CIN, POSTE, MAIL);

    bool test = Employe.ajouter();
    if (test)
    {
        ui->tableView_employe->setModel(tmp_employe.afficher());

    }
    else {
        QMessageBox::warning(this, "Erreur lors de l ajout du employé", "Veuillez remplir tous les champs à nouveau");
    }

}

void MainWindow::on_se_pushButton_clicked()
{
    QItemSelectionModel* select = ui->tableView_employe->selectionModel();

    QString NOM = select->selectedRows(0).value(0).data().toString();

    if (tmp_employe.supprimer(NOM))
    {
        ui->tableView_employe->setModel(tmp_employe.afficher());
        ui->statusbar->showMessage("employé supprimé");
    }
}

void MainWindow::on_mail_pushButton_clicked()
{

}

void MainWindow::on_stat_pushButton_clicked()
{

}

void MainWindow::on_pushButton_modifierE_clicked()
{
    if (ui->pushButton_modifierE->isChecked())
    {
        // ui->pushButton_modifier->setDisabled(true);
        ui->pushButton_modifierE->setText("Modifiable");
        QSqlTableModel* tableModel = new QSqlTableModel();
        tableModel->setTable("EMPLOYE");
        tableModel->select();
        ui->tableView_employe->setModel(tableModel);
    }
    else
    {
        ui->pushButton_modifierE->setText("Modifier");
        ui->tableView_employe->setModel(tmp_employe.afficher());

    }
}


void MainWindow::on_ap_pushButton_clicked()
{
    QString NOM = ui->lineEdit_Np->text();
    int ID = ui->lineEdit_id_P->text().toInt();
    int NBRH = ui->lineEdit_nbr_H->text().toInt();
    int SALAIRE = ui->lineEdit_salaire->text().toInt();
    poste poste(NOM, ID, NBRH, SALAIRE);

    bool test = poste.ajouter();
    if (test)
    {
        ui->tableView_poste->setModel(tmp_poste.afficher());

    }
    else {
        QMessageBox::warning(this, "Erreur lors de l ajout du poste", "Veuillez remplir tous les champs à nouveau");
    }
}

void MainWindow::on_mp_pushButton_clicked()
{
    if (ui->mp_pushButton->isChecked())
    {
        // ui->pushButton_modifier->setDisabled(true);
        ui->mp_pushButton->setText("Modifiable");
        QSqlTableModel* tableModel = new QSqlTableModel();
        tableModel->setTable("POSTE");
        tableModel->select();
        ui->tableView_poste->setModel(tableModel);
    }
    else
    {
        ui->mp_pushButton->setText("Modifier");
        ui->tableView_poste->setModel(tmp_poste.afficher());

    }
}
