#include "fenetreresultat.h"
#include "ui_fenetreresultat.h"
#include "QLabel"
#include <array>

resultat getCandidatsMaxVotes(const resultat& rslt);

fenetreResultat::fenetreResultat(int nbr_electeur, const resultat& rslt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreResultat),
    rslt(rslt),
    nbr_electeur(nbr_electeur)
{
    ui->setupUi(this);

    for(auto elt : rslt){
        QString qstr = QString::fromStdString( elt[0] ) + ": " + QString::fromStdString( elt[1] ) + " votes.";
        QLabel* Lbl = new QLabel( qstr, this );
        ui->resultat_layout->addWidget(Lbl);
    }

    int nbr_vote_blanc = stoi( rslt [rslt.size() - 1] [1] );
    int nbr_vote_total = nbr_vote_blanc;

    for(size_t i = 0; i < (rslt.size() - 1); ++i){
        nbr_vote_total += stoi( rslt[i][1] );
        if( stoi(rslt[i][1]) > ((nbr_electeur - nbr_vote_blanc) / 2) ){
            QString strGagnant = "MABROUK!! "+QString::fromStdString( rslt[i][0] ) + " a gagne les elections!";

            ui->resultats_label->setText( strGagnant );
        }
    }

    if(nbr_vote_total == nbr_electeur || rslt.size()==2){
        resultat gagnants = getCandidatsMaxVotes(rslt);
        QString strGagnants;
        if( gagnants.size() > 1){
            strGagnants = "MABROUK!! Les gagnants sont: ";
            for(size_t i=0; i<gagnants.size(); ++i){
                if(i == 0){
                    strGagnants.append( QString::fromStdString( gagnants[i][0] ) );
                }
                else{
                    strGagnants.append( QString::fromStdString( " et " + gagnants[i][0] ) );
                }
            }
            strGagnants.append( "!" );

        }else if( gagnants.size() == 1){
            strGagnants = "MABROUK!! Le gagnant par defaut est: ";
            strGagnants.append( QString::fromStdString( gagnants[0][0] ) );
            strGagnants.append( "!" );}

        if(nbr_vote_total==nbr_vote_blanc){
            strGagnants="Personne n'a gagner les elections";
        }
         ui->resultats_label->setText( strGagnants );
    }

}

fenetreResultat::~fenetreResultat()
{
    delete ui;
}

resultat getCandidatsMaxVotes(const resultat& rslt){
    resultat gagnants = {};
    gagnants.push_back( rslt[0] );

    for(size_t i = 1; i < (rslt.size() - 1); ++i){
        if( stoi(rslt[i][1]) > stoi(gagnants[0][1]) ){
            gagnants.clear();
            gagnants.push_back( rslt[i] );
        }else if( stoi(rslt[i][1]) == stoi(gagnants[0][1]) ){
            gagnants.push_back( rslt[i] );
        }
    }
    return gagnants;
}
