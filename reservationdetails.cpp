#include "reservationdetails.h"

QString reservationdetails::getReservationName() const
{
    return reservationName;
}

void reservationdetails::setReservationName(const QString &value)
{
    reservationName = value;
}

RoomType reservationdetails::getRoomType() const
{
    return roomType;
}

void reservationdetails::setRoomType(const RoomType &value)
{
    roomType = value;
}

QString reservationdetails::getFirstDayOfStay() const
{
    return firstDayOfStay;
}

void reservationdetails::setFirstDayOfStay(const QString &value)
{
    firstDayOfStay = value;
}

int reservationdetails::getNumberOfNights() const
{
    return numberOfNights;
}

void reservationdetails::setNumberOfNights(int value)
{
    numberOfNights = value;
}

int reservationdetails::getNumberOfAdults() const
{
    return numberOfAdults;
}

void reservationdetails::setNumberOfAdults(int value)
{
    numberOfAdults = value;
}

int reservationdetails::getNumberOfChildren() const
{
    return numberOfChildren;
}

void reservationdetails::setNumberOfChildren(int value)
{
    numberOfChildren = value;
}

bool reservationdetails::getParking() const
{
    return parking;
}

void reservationdetails::setParking(bool value)
{
    parking = value;
}

QString reservationdetails::getLastDayOfStay() const
{
    return lastDayOfStay;
}

void reservationdetails::setLastDayOfStay(const QString &value)
{
    lastDayOfStay = value;
}

int reservationdetails::getResortFeeTotal() const
{
    return resortFeeTotal;
}

void reservationdetails::setResortFeeTotal(int value)
{
    resortFeeTotal = value;
}

reservationdetails::reservationdetails()
{

}

double reservationdetails::calculateCost()
{
    double currentRate = 0;
    double resortTotal = resortFeeTotal;

    switch (roomType) {
    case STANDARD_QUEEN:
        currentRate = STANDARD_QUEEN_COST + (TAX * STANDARD_QUEEN_COST);
        break;
    case STANDARD_KING:
        currentRate = STANDARD_KING_COST + (TAX * STANDARD_KING_COST);
        break;
    case ATRIUM_KING:
        currentRate = ATRIUM_KING_COST + (TAX * ATRIUM_KING_COST);
        break;
    case ATRIUM_QUEEN:
        currentRate = ATRIUM_QUEEN_COST + (TAX * ATRIUM_QUEEN_COST);
        break;
    }

    if (parking == true)
    {
        currentRate += (PARKING_COST * numberOfNights);
    }

    currentRate += resortTotal;






    return currentRate;
}


