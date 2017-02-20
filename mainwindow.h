#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ajoutNumero(double numero);
    QString  calcul(QString nb1,QString op1,QString nb2);
    void  operateur(QString op1);
private slots:


    void on_textBrowser_textChanged();
    void on_touche0_clicked();
    void on_touche1_clicked();
    void on_touche2_clicked();
    void on_touche3_clicked();
    void on_touche4_clicked();
    void on_touche5_clicked();
    void on_touche6_clicked();
    void on_touche7_clicked();
    void on_touche8_clicked();
    void on_touche9_clicked();
    void on_touchePlus_clicked();
    void on_toucheVirgule_clicked();
    void on_toucheDivise_clicked();
    void on_toucheMoins_clicked();
    void on_toucheEgal_clicked();

    void on_toucheFois_clicked();

    void on_toucheClear_clicked();

    void on_radioButton_toggled(bool checked);

    void on_actionQuitter_triggered();

    void on_actionCopier_triggered();

    void on_actionColler_triggered();

    void on_actionQuit_triggered();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    QString nombre1;
    QString nombre2;
    QString operateur1;
    QString operateur2;
    double preced;
    QString resultat;
    double valeur;
    bool nextCalcul;
    QString lastOp;
    QString nombre3;
};

#endif // MAINWINDOW_H
