#include "fenetreelection.h"
#include "ui_fenetreelection.h"
#include <QString>
#include <QRadioButton>
#include <QMessageBox>

fenetreElection::fenetreElection(const vector<string>& candidats, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreElection),
    candidats(candidats)
{
    ui->setupUi(this);

    for(auto elt : candidats){
        QString qstr = QString::fromStdString( elt );
        QRadioButton* Rbtn = new QRadioButton( qstr, this );
        ui->rdb_layout->addWidget(Rbtn);
        rdbs.push_back(Rbtn);
    }
}

fenetreElection::~fenetreElection()
{
    delete ui;
}

void fenetreElection::on_pushButton_clicked()
{
    if(this->RdbIsChecked (this->rdbs) ){
        QRadioButton* checkedRdb = this->getCheckedRdb (this->rdbs) ;
        candidat_choisi = ( checkedRdb->text() ).toStdString();

        if(checkedRdb != rdbs[rdbs.size()-1]){
           QString message_vote = QString::fromStdString( "Merci d'avoir vote a: " ) + checkedRdb->text() + QString::fromStdString( "\nVotre choix sera sauvegarde!" );
           QMessageBox::information(this, "Merci", message_vote);


        }else{
            QString message_vote = QString::fromStdString( "Vous avez " ) + checkedRdb->text() + QString::fromStdString( "\nVotre choix sera sauvegarde!" );
            QMessageBox::information(this, "Merci", message_vote);
        }

        this->close();
    }else{
        QMessageBox::warning(this, "Attention", "Il faut choisir un candidat!");
    }
}

bool fenetreElection::RdbIsChecked(vector<QRadioButton*> v) const{
    for(auto rdb : v){
        if(rdb->isChecked()){
            return true;
        }
    }
    return false;
}


QRadioButton* fenetreElection::getCheckedRdb(vector<QRadioButton *> v) const{
    for(auto rdb : v){
        if(rdb->isChecked()){
            return rdb;
        }
    }
}
