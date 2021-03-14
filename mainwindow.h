#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
using namespace std;

typedef vector<array<string,2>> resultat;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    vector<string> getCandidats() const{ return candidats; }


private slots:
    void on_connect_button_clicked();

    void on_resultat_Button_clicked();

private:
    Ui::MainWindow *ui;

    vector<string> candidats;
    vector<string> mdps;
    resultat rslt;
    int nbr_electeur;

};
#endif // MAINWINDOW_H
