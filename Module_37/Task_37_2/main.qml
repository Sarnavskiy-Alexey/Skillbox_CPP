import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

Window {
    id: _window
    width: 640
    height: 480
    minimumWidth: 450
    minimumHeight: 400
    visible: true
    title: qsTr("My Single VideoPlayer")
    color: "#ffffff"

    Column {
        id: _column
        spacing: 20

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id: _rectVideo
            width: _window.width - 40
            height: _window.height - (_progbar.height + 50 + 20)
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -(_progbar.height + _buttons.height + 20) / 2 + 10
            MediaPlayer {
                id: _video
                source: "qrc:img/sample_960x400_ocean_with_audio.avi"
                videoOutput: _videoOut
                onStopped: {
                    _window.color = "#ffffff"
                    _rectVideo.color = "#ffffff"
                }
                onPaused: {
                    _window.color = "#ffffff"
                    _rectVideo.color = "#ffffff"
                }
                onPlaying: {
                    _window.color = "#000000"
                    _rectVideo.color = "#000000"
                }
            }
            VideoOutput {
                id: _videoOut
                anchors.fill: parent
            }
        }

        ProgressBar {
            id: _progbar
            width: 330
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: _window.height / 2 - (parent.spacing + height + 30)
            value: _video.position / _video.duration
        }

        Row {
            id: _buttons
            height: 50
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: _window.height / 2 - 30
            Button {
                text: "▶"
                font.pointSize: 18
                width: 50
                height: 50
                onClicked: {
                    _video.play()
                }
            }

            Button {
                text: "⏸️"
                font.pointSize: 18
                width: 50
                height: 50
                onClicked: {
                    _video.pause()
                }
            }

            Button {
                text: "⏹"
                font.pointSize: 18
                width: 50
                height: 50
                onClicked: {
                    _video.stop()
                }
            }

            Button {
                text: "⏪️"
                font.pointSize: 18
                width: 50
                height: 50
                onClicked: {
                    _video.seek(_video.position - 10000)
                }
            }

            Button {
                text: "⏩️"
                font.pointSize: 18
                width: 50
                height: 50
                onClicked: {
                    _video.seek(_video.position + 10000)
                }
            }
        }
    }
}
