#include "resortreservation.h"
#include "ui_resortreservation.h"
#include "reservationdetails.h"

#include <QMessageBox>

resortreservation::resortreservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::resortreservation)
{
    ui->setupUi(this);

    reservationDetails = new reservationdetails();

    loadImage();

    ui->atriumKingPicture->setPixmap(imageAtriumKing);
    ui->atriumQueenPicture->setPixmap(imageAtriumQueen);
    ui->standardKingPicture->setPixmap(imageStandardKing);
    ui->standardQueenPicture->setPixmap(imageStandardQueen);





    ui->checkIn->setDate(QDate::currentDate());
    ui->checkOut->setDate(QDate::currentDate());
    ui->checkIn->setMinimumDate(QDate::currentDate());
    ui->checkOut->setMinimumDate(QDate::currentDate());

    ui->parkingTextBrowser->setText("N/A");
    ui->parkingOutput->setText("No");





}

resortreservation::~resortreservation()
{
    delete ui;
}

void resortreservation::loadImage()
{
    QString atrium1King = "atrium1king.jpg";
    QString atrium2Queen = "atrium2queen.jpg";
    QString standard1King = "standard1king.jpg";
    QString standard2Queen = "standard2queen.jpg";

    if (imageAtriumKing.load(atrium1King))
    {
        imageAtriumKing = imageAtriumKing.scaled(ui->atriumKingPicture->size(), Qt::KeepAspectRatio);
    }
    if (imageAtriumQueen.load(atrium2Queen))
    {
        imageAtriumQueen = imageAtriumQueen.scaled(ui->atriumQueenPicture->size(), Qt::KeepAspectRatio);
    }
    if (imageStandardKing.load(standard1King))
    {
        imageStandardKing = imageStandardKing.scaled(ui->standardKingPicture->size(), Qt::KeepAspectRatio);
    }
    if (imageStandardQueen.load(standard2Queen))
    {
        imageStandardQueen = imageStandardQueen.scaled(ui->standardQueenPicture->size(), Qt::KeepAspectRatio);
    }
}

void resortreservation::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    double finalCost = reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));
}

void resortreservation::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void resortreservation::on_standardQueenRadio_clicked()
{
    ui->adultSpinBox->setMaximum(4);
    ui->childrenSpinBox->setMaximum(3);

    QString roomTypeName = "Standard, 2 Queen";
    ui->roomTextOutput->setText(roomTypeName);

    ui->roomPictureLabel->setPixmap(imageStandardQueen);

    RoomType roomType = STANDARD_QUEEN;
    reservationDetails->setRoomType(roomType);

    ui->roomPriceTextBrowswer->setText("$" + QString::number(STANDARD_QUEEN_COST));

    double totalTax = STANDARD_QUEEN_COST * TAX;

    ui->taxTextBrowser->setText("$" + QString::number(totalTax));

    double finalCost = reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));
}

void resortreservation::on_atriumQueenRadio_clicked()
{
    ui->adultSpinBox->setMaximum(4);
    ui->childrenSpinBox->setMaximum(3);

    QString roomTypeName = "Atrium, 2 Queen";
    ui->roomTextOutput->setText(roomTypeName);

    ui->roomPictureLabel->setPixmap(imageAtriumQueen);

    RoomType roomType = ATRIUM_QUEEN;
    reservationDetails->setRoomType(roomType);

    ui->roomPriceTextBrowswer->setText("$" + QString::number(ATRIUM_QUEEN_COST));

    double totalTax = ATRIUM_QUEEN_COST * TAX;

     ui->taxTextBrowser->setText("$" + QString::number(totalTax));

    double finalCost = reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));

}


void resortreservation::on_standardKingRadio_clicked()
{
    ui->adultSpinBox->setMaximum(3);
    ui->childrenSpinBox->setMaximum(2);

    QString roomTypeName = "Standard, 1 King";
    ui->roomTextOutput->setText(roomTypeName);

    ui->roomPictureLabel->setPixmap(imageStandardKing);

    RoomType roomType = STANDARD_KING;
    reservationDetails->setRoomType(roomType);

    ui->roomPriceTextBrowswer->setText("$" + QString::number(STANDARD_KING_COST));

    double totalTax = STANDARD_KING_COST * TAX;

     ui->taxTextBrowser->setText("$" + QString::number(totalTax));

    double finalCost = reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));

}


void resortreservation::on_atriumKingRadio_clicked()
{
    ui->adultSpinBox->setMaximum(3);
    ui->childrenSpinBox->setMaximum(2);

    QString roomTypeName = "Atrium, 1 King";
    ui->roomTextOutput->setText(roomTypeName);

    ui->roomPictureLabel->setPixmap(imageAtriumKing);

    RoomType roomType = ATRIUM_KING;
    reservationDetails->setRoomType(roomType);

    ui->roomPriceTextBrowswer->setText("$" + QString::number(ATRIUM_KING_COST));

    double totalTax = ATRIUM_KING_COST * TAX;

     ui->taxTextBrowser->setText("$" + QString::number(totalTax));

    double finalCost = reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));

}


void resortreservation::on_payButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Transaction processed");
    msgBox.setWindowTitle("Confirmation");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(2);

    double finalCost = reservationDetails->calculateCost();
    ui->totalAmountOutput->setText("$" + QString::number(finalCost));


}

void resortreservation::on_reservationNameInput_editingFinished()
{
    QString reservationName = ui->reservationNameInput->text();
    reservationDetails->setReservationName(reservationName);
    ui->reservationNameOutput->setText(reservationName);

}

void resortreservation::on_visaCard_clicked()
{
    ui->creditCardInput->setInputMask("4999-9999-9999-9999;0");
    ui->creditCardInput->clear();
}

void resortreservation::on_masterCard_clicked()
{
    ui->creditCardInput->setInputMask("5999-9999-9999-9999;0");
    ui->creditCardInput->clear();
}

void resortreservation::on_discoverCard_clicked()
{
    ui->creditCardInput->setInputMask("6999-9999-9999-9999;0");
    ui->creditCardInput->clear();
}


void resortreservation::on_americanExpress_clicked()
{
    ui->creditCardInput->setInputMask("3999-999999-99999;0");
    ui->creditCardInput->clear();
}

void resortreservation::on_exitButton_clicked()
{
    QApplication::quit();
}


void resortreservation::on_checkIn_userDateChanged(const QDate &date)
{
    QDate newMinimum = date;
    ui->checkOut->setMinimumDate(newMinimum);
}

void resortreservation::on_adultSpinBox_editingFinished()
{
    int adultGuests = ui->adultSpinBox->value();
    reservationDetails->setNumberOfAdults(adultGuests);
    ui->numberOfAdults->setText(QString::number(adultGuests));

    double finalCost =  reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));
}

void resortreservation::on_childrenSpinBox_editingFinished()
{
    int childGuests = ui->childrenSpinBox->value();
    reservationDetails->setNumberOfChildren(childGuests);
    ui->numberOfChildren->setText(QString::number(childGuests));

    double finalCost =  reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));
}


void resortreservation::on_checkBox_clicked(bool checked)
{
    reservationDetails->setParking(checked);
    ui->parkingOutput->setText("Yes");

    int numberOfNights = reservationDetails->getNumberOfNights();
    double totalParkingCost = PARKING_COST * numberOfNights;

    ui->parkingTextBrowser->setText("$" + QString::number(totalParkingCost));

    double finalCost =  reservationDetails->calculateCost();
    ui->totalTextBrowser->setText("$" + QString::number(finalCost));
}

void resortreservation::on_creditCardInput_textChanged(const QString &arg1)
{
    QString creditCard = arg1;
    ui->creditCardOutput->setText(creditCard.right(4));
}

void resortreservation::on_checkIn_dateChanged(const QDate &date)
{
    QDate firstDayOfStay = date;
    int month = firstDayOfStay.month();
    int day = firstDayOfStay.day();
    int year = firstDayOfStay.year();
    ui->firstDayOfStayOutput->setText(QString::number(month) + "/" + QString::number(day) + "/" + QString::number(year));
}

void resortreservation::on_checkOut_editingFinished()
{
    QDate currentDateData = ui->checkIn->date();
    int firstDay = currentDateData.day();
    reservationDetails->setFirstDayOfStay(QString::number(firstDay));
    QDate currentDateDataTwo = ui->checkOut->date();
    int lastDay = currentDateDataTwo.day();
    reservationDetails->setLastDayOfStay(QString::number(lastDay));

    int numberOfNights = lastDay - firstDay;
    reservationDetails->setNumberOfNights(numberOfNights);
    ui->numberOfNightsOutput->setText(QString::number(numberOfNights));

    int resortFee = 15;
    int resortFeeTotal = resortFee * numberOfNights;

    ui->resortFeeTextBrowser->setText("$" + QString::number(resortFeeTotal));
    reservationDetails->setResortFeeTotal(resortFeeTotal);
}
