#ifndef FENETREELECTION_H
#define FENETREELECTION_H

#include <QDialog>
#include <vector>
#include <string>
#include <QRadioButton>
using namespace std;

namespace Ui {
class fenetreElection;
}

class fenetreElection : public QDialog
{
    Q_OBJECT

public:
    fenetreElection(const vector<string>& candidats, QWidget *parent = nullptr);
    ~fenetreElection();

    bool RdbIsChecked(vector<QRadioButton*> v) const;
    QRadioButton* getCheckedRdb(vector<QRadioButton*> v) const;
    string getCandidat_choisi() const{ return candidat_choisi; }

private slots:
    void on_pushButton_clicked();

private:
    Ui::fenetreElection *ui;
    vector<string> candidats;
    vector<QRadioButton*> rdbs;
    string candidat_choisi;

};

#endif // FENETREELECTION_H
