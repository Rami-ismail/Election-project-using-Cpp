#include "fenetreadmin.h"
#include "ui_fenetreadmin.h"
#include"fenetreresultat.h"
#include "ui_fenetreresultat.h"
#include <vector>
#include <cstdlib>
#include <string>
#include "mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <array>
using namespace std;


fenetreAdmin::fenetreAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreAdmin)
{
    ui->setupUi(this);
    modifie = false;
}

fenetreAdmin::~fenetreAdmin()
{
    delete ui;
}

vector<string> Split(const string& s, char c);

void fenetreAdmin::on_save_button_clicked()
{
    modifie = true;

    nbr_electeur = ( ui->nbrElect_spinBox->text() ).toInt();
    candidats = Split( ( ui->candidats_entry->text() ).toStdString(), ',');
    candidats.push_back("Voter blanc");

    rslt_initial = {};
    for( auto candidat : candidats){
        array<string,2> a;
        a[0] = candidat;
        a[1] = "0";
        rslt_initial.push_back(a);
    }


    mdps.clear();

    for(int i=0; i<nbr_electeur; ++i){
        int randomInt = rand()%1000000;
        mdps.push_back(to_string(randomInt));}

string info;
if(candidats.size()>=2){
    string strMdps;
    for(size_t i=0; i<mdps.size(); ++i){
        if(i == 0){
            strMdps.append(mdps[i]);
        }
        else{
            strMdps.append( ", " + mdps[i] );
        }
    }


    info =  "Les mots de passe que les electeurs peuvent utiliser sont:\n" + strMdps;
    cout << info << endl;
    QString Qinfo = QString::fromStdString(info);
    QMessageBox::information(this, "Mots de Passe", Qinfo);
    this->close();
}else{
    info =  "Il faut inserez les noms des candidats pour demarer les elections";
    QString Qinfo = QString::fromStdString(info);
    QMessageBox::information(this, "Erreur", Qinfo);
}
}


vector<string> Split(const string& s, char c){
    vector<string> v = {};
    string subStr = "";
    for( size_t i=0; i<s.size(); ++i){
        if(s[i] == c){
            v.push_back(subStr);
            subStr = "";

        }
        else{
            subStr += s[i];
        }
    }
    if (subStr != ""){
        v.push_back(subStr);
    }

    return v;
}
