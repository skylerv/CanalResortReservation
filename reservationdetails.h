#ifndef RESERVATIONDETAILS_H
#define RESERVATIONDETAILS_H

#include <QObject>

enum RoomType { STANDARD_QUEEN, STANDARD_KING, ATRIUM_QUEEN, ATRIUM_KING };

class reservationdetails
{
private:
    QString reservationName;
    RoomType roomType;
    QString firstDayOfStay;
    QString lastDayOfStay;
    int numberOfNights;
    int numberOfAdults;
    int numberOfChildren;
    int resortFeeTotal;
    bool parking;

    const int STANDARD_KING_COST = 290;
    const int ATRIUM_KING_COST = 350;
    const int STANDARD_QUEEN_COST = 284;
    const int ATRIUM_QUEEN_COST = 325;
    const double PARKING_COST = 12.75;
    const double TAX = 0.15;

public:
    reservationdetails();

    double calculateCost();

    //getters and setters
    QString getReservationName() const;
    void setReservationName(const QString &value);
    RoomType getRoomType() const;
    void setRoomType(const RoomType &value);
    QString getFirstDayOfStay() const;
    void setFirstDayOfStay(const QString &value);
    int getNumberOfNights() const;
    void setNumberOfNights(int value);
    int getNumberOfAdults() const;
    void setNumberOfAdults(int value);
    int getNumberOfChildren() const;
    void setNumberOfChildren(int value);
    bool getParking() const;
    void setParking(bool value);
    QString getLastDayOfStay() const;
    void setLastDayOfStay(const QString &value);
    int getResortFeeTotal() const;
    void setResortFeeTotal(int value);
};

#endif // RESERVATIONDETAILS_H
