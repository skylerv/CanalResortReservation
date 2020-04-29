#ifndef RESORTRESERVATION_H
#define RESORTRESERVATION_H

#include <QMainWindow>

#include "reservationdetails.h"

namespace Ui {
class resortreservation;
}

class resortreservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit resortreservation(QWidget *parent = nullptr);
    ~resortreservation();

private slots:

    void on_nextButton_clicked();

    void on_backButton_clicked();

    void on_standardQueenRadio_clicked();

    void on_atriumQueenRadio_clicked();

    void on_standardKingRadio_clicked();

    void on_atriumKingRadio_clicked();

    void on_payButton_clicked();

    void on_reservationNameInput_editingFinished();

    void on_visaCard_clicked();

    void on_masterCard_clicked();

    void on_exitButton_clicked();

    void on_discoverCard_clicked();

    void on_americanExpress_clicked();

    void on_checkIn_userDateChanged(const QDate &date);

    void on_adultSpinBox_editingFinished();

    void on_childrenSpinBox_editingFinished();

    void on_checkBox_clicked(bool checked);


    void on_creditCardInput_textChanged(const QString &arg1);

    void on_checkIn_dateChanged(const QDate &date);


    void on_checkOut_editingFinished();

private:
    Ui::resortreservation *ui;

    reservationdetails *reservationDetails;

    QPixmap imageAtriumKing;
    QPixmap imageAtriumQueen;
    QPixmap imageStandardKing;
    QPixmap imageStandardQueen;


    const int STANDARD_KING_COST = 290;
    const int ATRIUM_KING_COST = 350;
    const int STANDARD_QUEEN_COST = 284;
    const int ATRIUM_QUEEN_COST = 325;
    const double TAX = 0.15;
    const double PARKING_COST = 12.75;


    void loadImage();
};

#endif // RESORTRESERVATION_H
