import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true

    property int keyIndex: 0
    property string masterKey: ""
    property string currentKey: ""
    property string currentText: ""
    property string tempText: ""

    Rectangle{
        color: 'red'
        width: 10
        height: 10
        radius: 5
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 2
        visible: timer.running
    }

    Timer{
        id: timer
        repeat: false
        interval: 1000
        onTriggered: {
            masterKey = '';
            keyIndex = 0;
            currentText = tempText;
        }
    }

    Item {
        anchors.fill: parent
        focus: true
        Keys.onPressed: {
            timer.restart();
            var keyData = {
                '1' : ['1'],
                '2' : ['2','a','b','c'],
                '3' : ['3','d','e','f'],
                '4' : ['4','g','h','i'],
                '5' : ['5','j','k','l'],
                '6' : ['6','m','n','o'],
                '7' : ['7','p','q','r','s'],
                '8' : ['8','t','u','v'],
                '9' : ['9','w','x','y','z'],
                '0' : ['0'],

            };

            if(masterKey != '' && timer.running){
                var keys = keyData[masterKey];
                if(!keys){
                    return;
                }
                keyIndex++;
                if(keyIndex > keys.length - 1)
                    keyIndex = 0;
                currentKey = keys[keyIndex];
            } else {
                currentKey = masterKey = Keypad.dataSerialString;
            }

            temText = currentText;
            temText += currentKey;
            display.text = temText;

        }
    }
    /*
    Connections{
        target: Keypad
        onDataSerialStringChanged:{
            timer.restart();
            var keyData = {
                '1' : ['1'],
                '2' : ['2','a','b','c'],
                '3' : ['3','d','e','f'],
                '4' : ['4','g','h','i'],
                '5' : ['5','j','k','l'],
                '6' : ['6','m','n','o'],
                '7' : ['7','p','q','r','s'],
                '8' : ['8','t','u','v'],
                '9' : ['9','w','x','y','z'],
                '0' : ['0'],

            };

            if(masterKey != '' && timer.running){
                var keys = keyData[masterKey];
                if(!keys){
                    return;
                }
                keyIndex++;
                if(keyIndex > keys.length - 1)
                    keyIndex = 0;
                currentKey = keys[keyIndex];
            } else {
                currentKey = masterKey = Keypad.dataSerialString;
            }

            tempText = currentText;
            tempText += currentKey;
            display.text = tempText;
        }
    }*/

    Text {
        id: display
        //text: Keypad.dataSerialString
        anchors.centerIn: parent
    }
}
