#include "keypad.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTimer>

QSerialPort serial;
QString port = "ttyUSB0";
QByteArray keypad_state = "state_number";

KEYPAD::KEYPAD(QObject *parent) : QObject(parent)
{
    serial.setPortName(port);

    if (serial.open(QIODevice::ReadOnly)) {
        serial.setBaudRate(QSerialPort::Baud9600);
        serial.setDataBits(QSerialPort::Data8);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);
        serial.setFlowControl(QSerialPort::NoFlowControl);
        qDebug() << "Serial Opened";

        connect(&serial,SIGNAL(readyRead()),this,SLOT(serialRead()));

    }else {
        serial.close();
        qDebug() << "Serial Closed";
    }
}

void KEYPAD::serialRead()
{
    // check timer active?
    // prevKey
    dataSerial = serial.readAll().toHex();
    dataSerial = convertData(dataSerial);
    qDebug() << "Data:" << dataSerial;
    emit dataSerialStringChanged();

}

QByteArray KEYPAD::convertData(QByteArray &data)
{
    if (data == "00") {
        data = "1";
    } else if (data == "01") {
        data = "2";
    } else if (data == "02") {
        data = "3";
    } else if (data == "05") {
        data = "4";
    } else if (data == "06") {
        data = "5";
    } else if (data == "07") {
        data = "6";
    } else if (data == "0a") {
        data = "7";
    } else if (data == "0b") {
        data = "8";
    } else if (data == "0c") {
        data = "9";
    } else if (data == "10") {
        data = "0";
    } else if (data == "0d") {
        data = "q";
    }

    return data;
}

int KEYPAD::getState(QByteArray &state)
{
    int result;
    if (state == "15") {
        //state = "state_1";
        result = 1;
    } else if (state == "18") {
        result = 2;;
    } else if (state == "0e") {
        result = 3;
    } else if (state == "16") {
        result = 4;
    } else {
        result = 1;
    }

    return result;
}

