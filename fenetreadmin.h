#ifndef FENETREADMIN_H
#define FENETREADMIN_H

#include <QDialog>
#include <vector>
#include <string>
#include <array>
using namespace std;

typedef vector<array<string,2>> resultat;

namespace Ui {
class fenetreAdmin;
}

class fenetreAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit fenetreAdmin(QWidget *parent = nullptr);
    ~fenetreAdmin();

    vector<string> getCandidats() const{ return candidats; }
    vector<string> getMdps() const{ return mdps; }
    resultat getRslt_initial() const{ return rslt_initial; }
    bool getModifie() const{ return modifie; }
    int getNbr_electeur() const{ return nbr_electeur; }

private slots:

    void on_save_button_clicked();


private:
    Ui::fenetreAdmin *ui;

    vector<string> candidats;;
    vector<string> mdps;
    resultat rslt_initial;
    bool modifie;
    int nbr_electeur;

};

#endif // FENETREADMIN_H
