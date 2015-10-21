#ifndef KEYPAD_H
#define KEYPAD_H

#include <QObject>

class KEYPAD : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dataSerialString READ dataSerialString NOTIFY dataSerialStringChanged)
    //Q_PROPERTY(QString dataSerialString WRITE setDataSerialString READ dataSerialString NOTIFY dataSerialStringChanged)

public:
    explicit KEYPAD(QObject *parent = 0);
    QString dataSerialString(){
        return dataSerial;
    }

    /*void setDataSerialString(const QString& str){
        if (str == dataSerialString()) {}
        dataSerial = str;
    }*/

    QByteArray dataSerial;

signals:
    void dataSerialStringChanged();

public slots:
    void serialRead();
    QByteArray convertData(QByteArray &data);
    int getState(QByteArray &state);

};

#endif // KEYPAD_H
