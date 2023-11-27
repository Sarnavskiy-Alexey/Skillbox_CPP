/* Задание 1. Создание приложения, позволяющего перемещать круг по холсту
 *  Что нужно сделать:
 *  Вспомните программу, которая перемещала круг от центра одного прямоугольника к центру другого.
 *  Можно взять её за основу, доработав следующее:
 *  При нажатии на левый квадрат круг перемещается на небольшое расстояние в сторону правого
 *  квадрата (без анимации).
 *  При достижении правого квадрата (его центра или любого края) круг возвращается в исходное
 *  положение (внутри левого квадрата) с любой анимацией на ваше усмотрение.
 *  При нажатии на правый квадрат круг возвращается в исходное положение (также с анимацией).
 *
 *  Что стоит учесть:
 *  Чтобы переместить круг, достаточно в обработчике onClicked написать ball.x += 30.
 *  Для создания анимации потребуется как минимум два состояния — исходное и промежуточное.
 *  Исходное состояние можно получить способом, который вы применяли на практике. Получение
 *  промежуточного состояния потребует некоторой хитрости: координата в нём будет накапливаться
 *  каждый раз, когда мы делаем x += 30. Чтобы избежать этого, можно написать код так:
 *
 *  State {
 *      name: "OtherState"
 *      PropertyChanges {
 *          target: ball
 *          x: ball.x
 *      }
 *  }
 *
 *  Переход будет только один — из промежуточного в исходное состояние:
 *  Transition {
 *      from: "OtherState"
 *      to: "InitialState"
 *      NumberAnimation {
 *          properties: "x,y"
 *          duration: 1000
 *          easing.type: Easing.OutBounce
 *      }
 *  }
 *
 *  Вам нужно проверять координату круга при каждом нажатии на квадрат:
 *  if(ball.x >= rightRectangle.x)
 *
 *  В одном случае вы увеличиваете координату и меняете состояние, а в другом — перемещаете круг
 *  в исходное положение (меняете состояние на исходное).
 *  Внутри квадратов хорошо бы разместить надписи «move» и «return» соответственно. Например,
 *  при помощи элементов Text:
 *  Text {
 *      id: name
 *      anchors.centerIn: parent
 *      text: "move"
 *  }
 *  Критерии оценки:
 *  - Приложение отображает одно окно, в котором есть два квадрата и круг.
 *  - При нажатии на левый квадрат круг перемещается в сторону правого квадрата на произвольное
 *    количество пикселей.
 *  - При нажатии на правый квадрат круг возвращается в исходное положение.
 *  - При достижении кругом любой стороны правого квадрата или его центра круг возвращается в
 *    исходное положение с анимацией. */

import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: main
    width: 640
    height: 480
    visible: true
    title: qsTr("Task 1 of Module 39")

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "InitialState"

        Rectangle {
            id: leftRect
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ball.x += 30
                    if (ball.x >= rightRect.x + 5) {
                        scene.state = "OtherState"
                        ball.x = leftRect.x + 5
                    } else {
                        scene.state = "InitialState"
                    }

                }
            }
        }

        Rectangle {
            id: rightRect
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    scene.state = "InitialState"
                    ball.x = leftRect.x + 5
                }
            }
        }

        Rectangle {
            id: ball
            color: "darkgreen"
            x: leftRect.x + 5
            y: leftRect.y + 5
            width: leftRect.width - 10
            height: rightRect.height - 10
            radius: width / 2
        }

        states: [
            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            },

            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }

        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"

                NumberAnimation {
                    property: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            },

            Transition {
                from: "InitialState"
                to: "OtherState"

                NumberAnimation {
                    property: "x,y"
                    duration: 1000
                    easing.type: Easing.InOutExpo
                }
            }
        ]
    }
}
