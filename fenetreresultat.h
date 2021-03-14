#ifndef FENETRERESULTAT_H
#define FENETRERESULTAT_H

#include <QDialog>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef vector<array<string,2>> resultat;

namespace Ui {
class fenetreResultat;
}

class fenetreResultat : public QDialog
{
    Q_OBJECT

public:
    fenetreResultat( int nbr_electeur, const resultat& rslt, QWidget *parent = nullptr);
    ~fenetreResultat();

    resultat getResultat() { return rslt; }

private:
    Ui::fenetreResultat *ui;

    resultat rslt;
    int nbr_electeur;
};

#endif // FENETRERESULTAT_H
