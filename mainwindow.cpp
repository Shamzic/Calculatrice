#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QClipboard>
#include "MaFenetre.h"
#include <QApplication>
#include <QWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    nombre1(""),
    nombre2(""),
    operateur1(""),
    operateur2(""),
    preced(0),
    resultat(""),
    valeur(0),
    nextCalcul(false),
    lastOp(""),
    nombre3("")
{
    ui->setupUi(this);
    setWindowTitle("Calculatrice");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textBrowser_textChanged()
{
    cout<<resultat.toStdString();
}

void  MainWindow::ajoutNumero(double numero)
{
    if(operateur1=="" && operateur2=="")
    {
        nombre1+=QString::number(numero);
        ui->afficheur->setText(nombre1);
        nombre2="";
    }
    else if(operateur1!="" && operateur2=="")
    {
        nombre2+=QString::number(numero);
        ui->afficheur->setText(nombre2);
    }
    else if(operateur1!="" && operateur2=="=")
    {
        nombre2="";
        nombre1=QString::number(preced);
        nombre2=QString::number(numero);
        ui->afficheur->setText(nombre2);
        operateur2="";
    }
    else if(operateur1=="" && operateur2=="=")
   {
       nombre2="";
       operateur2="";
       nombre1=QString::number(numero);
       ui->afficheur->setText(nombre1);
   }
    else if(operateur1!="" && operateur2!="=" && operateur2!="" && nombre2!="")
   {
        qDebug() << "Concat nb3";
        nombre3+=QString::number(numero);
        ui->afficheur->setText(nombre3);
   }

    resultat+=QString::number(numero);
}

QString MainWindow::calcul(QString nb1,QString op1,QString nb2)
{
    QString res="";
    if(op1=="+")
    {
        double valeur=nb1.toDouble()+nb2.toDouble();
        res= QString::number(valeur);
    }
    if(op1=="-")
    {
        double valeur=nb1.toDouble()-nb2.toDouble();
        res= QString::number(valeur);
    }
    if(op1=="*")
    {
        double valeur=nb1.toDouble()*nb2.toDouble();
        res= QString::number(valeur);
    }
    if(op1=="/")
    {

        if (nb2.toDouble()!=0)
        {
            double valeur=nb1.toDouble()/nb2.toDouble();
            res = QString::number(valeur);
        }
        else
        {
            res ="ERROR DIVISION BY 0";
        }
    }
    return res;
}


void  MainWindow::operateur(QString op1)
{
    if(nombre2=="")
        operateur1=op1;
    else if(operateur2=="=")
    {
        operateur1=op1;
        nombre1=QString::number(preced);
        nombre2="";
        nombre3="";
    }
    else if(nombre2!="" && nombre3=="")
    {
        if((operateur1=="*")||(operateur1=="/"))
        {
            resultat = calcul(nombre1,operateur1,nombre2);
            valeur = resultat.toDouble();
            qDebug() << "Calcul : "<<nombre1 << operateur1<<nombre2<<"="<<valeur<<endl;
            nombre1=resultat;
            lastOp=operateur1;
            operateur1=op1;
            resultat="";
            preced = valeur;
            nombre2="";
        }
        else
        {
            operateur2=op1;
        }
    }
    else if(nombre2!="" && nombre3!="")
    {
        if((operateur2=="*")||(operateur2=="/"))
        {
            resultat = calcul(nombre2,operateur2,nombre3);
            valeur = resultat.toDouble();
             qDebug() << "Calcul2 badaboum: "<<nombre2 << operateur2<<nombre3<<"="<<valeur<<endl;
            lastOp=operateur2;
            nombre2=nombre3;

            QString resultat2 = calcul(nombre1,operateur1,resultat);
            valeur = resultat2.toDouble();
            qDebug() << "Calcul1 : "<<nombre1<< operateur1<<resultat<<"="<<valeur<<endl;

            preced = valeur;
            nombre3="";
            resultat=resultat2;
            operateur2="=";
            operateur1=op1;
        }
        else
        {
            resultat = calcul(nombre1,operateur1,nombre2);
            valeur = resultat.toDouble();
            qDebug() << "Calcul1 zbra: "<<nombre1 << operateur1<<nombre2<<"="<<valeur<<endl;

            nombre1=resultat;
            resultat="";
            preced = valeur;

            resultat = calcul(nombre1,operateur2,nombre3);
            valeur = resultat.toDouble();
            qDebug() << "Calcul1 : "<<nombre1 << operateur2<<nombre3<<"="<<valeur<<endl;

            lastOp=operateur2;
            preced = valeur;
            resultat="";

            nombre2=nombre3;
            nombre3="";
        }
    }
}


//BOUTON TOUCHE N°1
void MainWindow::on_touche1_clicked()
{
    ajoutNumero(1);
}

// BOUTON "TOUCHE N°2"
void MainWindow::on_touche2_clicked()
{
   ajoutNumero(2);
}

// BOUTON "TOUCHE N°3"
void MainWindow::on_touche3_clicked()
{
    ajoutNumero(3);
}

// BOUTON "TOUCHE N°4"
void MainWindow::on_touche4_clicked()
{
    ajoutNumero(4);
}

// BOUTON "TOUCHE N°5"
void MainWindow::on_touche5_clicked()
{
   ajoutNumero(5);
}

// BOUTON "TOUCHE N°6"
void MainWindow::on_touche6_clicked()
{
    ajoutNumero(6);
}

// BOUTON "TOUCHE N°7"
void MainWindow::on_touche7_clicked()
{
    ajoutNumero(7);
}

// BOUTON "TOUCHE N°8"
void MainWindow::on_touche8_clicked()
{
   ajoutNumero(8);
}

// BOUTON "TOUCHE N°9"
void MainWindow::on_touche9_clicked()
{
  ajoutNumero(9);
}

// BOUTON "TOUCHE N°0"
void MainWindow::on_touche0_clicked()
{
    ajoutNumero(0);
}

void MainWindow::on_toucheVirgule_clicked()
{
    if(operateur1=="")
    {
        nombre1+=".";
        ui->afficheur->setText(nombre1);
    }
    else if(operateur1!="" && operateur2=="")
    {
        nombre2+=".";
        ui->afficheur->setText(nombre2);
    }
    else if(operateur1!="" && operateur2!="=" && operateur2!="" && nombre2!="")
    {
        nombre3+=".";
        ui->afficheur->setText(nombre3);
    }
//    resultat+=".";
    //ui->afficheur->setText(resultat);
}


/* -------------------------- */
/* ----- OPERATIONS --------- */
/* -------------------------- */


// BOUTON "+"
void MainWindow::on_touchePlus_clicked()
{
    operateur("+");
}

void MainWindow::on_toucheDivise_clicked()
{
    operateur("/");
}

void MainWindow::on_toucheMoins_clicked()
{
    operateur("-");
}


void MainWindow::on_toucheFois_clicked()
{
    operateur("*");
}

// BOUTON "="
void MainWindow::on_toucheEgal_clicked()
{
    if(operateur2=="")
    {
        resultat = calcul(nombre1,operateur1,nombre2);
        valeur = resultat.toDouble();
        qDebug() << "Calcul oups: "<<nombre1 << operateur1<<nombre2<<"="<<valeur<<endl;
        ui->afficheur->setText(resultat);
        //nombre1="";
        lastOp=operateur1;
        operateur1="";
        operateur2="=";
        resultat="";
        preced = valeur;

    }
    else if(operateur2=="=")
    {
        QString nbpreced = QString::number(preced);
        resultat = calcul(nbpreced,lastOp,nombre2);
        valeur = resultat.toDouble();
        qDebug() << "Calcul yolo: "<<preced<<lastOp<<nombre2<<"="<<valeur<<endl;
        ui->afficheur->setText(resultat);
        nombre1=QString::number(valeur);
        operateur1="";
        resultat="";
        preced = valeur;
    }
    else if(nombre2!="" && nombre3!="" )
    {
        resultat = calcul(nombre2,operateur2,nombre3);
        valeur = resultat.toDouble();
         qDebug() << "Calcul2 bim: "<<nombre2 << operateur2<<nombre3<<"="<<valeur<<endl;
        lastOp=operateur2;
        nombre2=nombre3;

        QString resultat2 = calcul(nombre1,operateur1,resultat);
        valeur = resultat2.toDouble();
        qDebug() << "Calcul1 : "<<nombre1<< operateur1<<resultat<<"="<<valeur<<endl;

        preced = valeur;
        nombre3="";
        resultat=resultat2;
        operateur2="=";
        ui->afficheur->setText(resultat);
    }

}

void MainWindow::on_toucheClear_clicked()
{
    operateur1 ="";
    operateur2="";
    nombre1="";
    nombre2="";
    nombre3="";
    resultat="";
    preced=0;
    ui->afficheur->setText("0");
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    operateur1 ="";
    operateur2="";
    nombre1="";
    nombre2="";
    nombre3="";
    resultat="";
    preced=0;

    int i, n = ui->gridLayout_2->count();
    for (i=0;i<n;i++) {
    QObject::connect(qobject_cast<QObject *>(ui->gridLayout_2->itemAt(i)->widget()),SIGNAL(clicked()),this,SLOT(digitClicked()));
    }
    QList<QPushButton *> liste = ui->centralWidget->findChildren<QPushButton *>();
    if(checked)
    {
        ui->afficheur->setText("CALCULATRICE ETEINTE");
            foreach (QPushButton * p, liste ){
                p->setDisabled(true);
            }
    }
    else
    {
        ui->afficheur->setText("BONJOUR !");
        foreach (QPushButton * p, liste ){
            p->setEnabled(true);
        }
    }
}


void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopier_triggered()
{
    qApp->clipboard()->setText(ui->afficheur->text());
}

void MainWindow::on_actionColler_triggered()
{
    QClipboard *pressePapiers = QApplication::clipboard();
    QString textePressePapiers = pressePapiers->text();
    ui->afficheur->setText(textePressePapiers);
}

void MainWindow::on_actionQuit_triggered()
{
    QString texte = "Bievenue sur la calculatrice du futur.\n";
    QString texte2 = "\nElle a été réalisée par Simon Hamery dans le cadre de l'UE \"Interfaces Homme-Machines\".";
    QString texte3 = "\nLes règles de priorités de calcul sont utilisées. Exemple : 1+2*3-1=6";
    texte+=texte2;
    texte+=texte3;
    QMessageBox::information(this, "A propos", texte);
}

void MainWindow::on_pushButton_15_clicked()
{
    if(operateur1=="")
    {
        nombre1="-"+nombre1;
        ui->afficheur->setText(nombre1);
    }
    else if(operateur1!="" && operateur2=="")
    {
        nombre2="-"+nombre2;
        ui->afficheur->setText(nombre2);
    }
    else if(operateur1!="" && operateur2!="=" && operateur2!="" && nombre2!="")
    {
        nombre3="-"+nombre3;
        ui->afficheur->setText(nombre3);
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    if(operateur1=="")
    {
        nombre1.remove(nombre1.size()-1, 1);
        ui->afficheur->setText(nombre1);
    }
    else if(operateur1!="" && operateur2=="")
    {
        nombre2.remove(nombre2.size()-1, 1);
        ui->afficheur->setText(nombre2);
    }
    else if(operateur1!="" && operateur2!="=" && operateur2!="" && nombre2!="")
    {
        nombre3.remove(nombre3.size()-1, 1);
        ui->afficheur->setText(nombre3);
    }
}
