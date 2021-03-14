#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fenetreadmin.h"
#include "fenetreelection.h"
#include "fenetreresultat.h"
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
#include <iostream>
#include <array>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


bool inVector(const string& s, const vector<string>& v);
size_t getIndex(const string& s, const vector<string>& v);

void MainWindow::on_connect_button_clicked()
{
    if( (ui->id_entry->text()).toStdString()=="admin" && ((ui->mdp_entry->text()).toStdString())=="admin" ){
        hide();

        fenetreAdmin fA(this);
        fA.setModal(true);
        fA.exec();
        if(fA.getModifie() == true){
            candidats = fA.getCandidats();
            mdps = fA.getMdps();
            rslt = fA.getRslt_initial();
            nbr_electeur = fA.getNbr_electeur();

        }

        ui->id_entry->setText("");
        ui->mdp_entry->setText("");
        show();

    }else if( (ui->id_entry->text()).toStdString()=="electeur" && inVector( (ui->mdp_entry->text()).toStdString() , mdps) ){
        if(candidats.size()>1){
            hide();
            size_t index;
            index = getIndex( (ui->mdp_entry->text()) .toStdString() , mdps);
            mdps.erase(mdps.begin() + index);

            fenetreElection fE(candidats, this);
            fE.setModal(true);
            fE.exec();

            ui->mdp_entry->setText("");

            string candidat_choisi = fE.getCandidat_choisi();
            for(auto& elt : rslt){
                if(elt[0] == candidat_choisi){
                    elt[1] = to_string ( stoi(elt[1]) + 1 );
                }
            }

            show();
        }else{
            QMessageBox::warning(this, "Erreur", "Election impossible. (Pas de candidats)" );
        }
    }else{
        QMessageBox::warning(this, "Erreur", "Mauvais parametres de connexion!" );
    }
}


bool inVector(const string& s, const vector<string>& v){
    for(size_t i=0; i<v.size(); ++i){
        if( s == v[i] ){
            return true;
        }
    }
    return false;
}

size_t getIndex(const string& s, const vector<string>& v){
    for(size_t i=0; i<v.size(); ++i){
        if( s == v[i] ){
            return i;
        }
    }
}

void MainWindow::on_resultat_Button_clicked()
{
    if(candidats.size()>1){
        fenetreResultat fR(this->nbr_electeur, this->rslt, this);
        fR.setModal(true);
        fR.exec();

    }else{
        QMessageBox::warning(this, "Erreur", "Pas d'election en cours!" );
    }


}
