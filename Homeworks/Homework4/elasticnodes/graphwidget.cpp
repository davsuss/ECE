/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include "graphwidget.h"
#include "edge.h"
#include "node.h"
#include "orgate.h"
#include "andgate.h"
#include "truegate.h"
#include "falsegate.h"
#include <QtGui>

#include <math.h>

//! [0]
GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    m_tBox = new QLineEdit(parent);
    m_tBox->move(-200,-200);
    scene->addWidget(m_tBox);

    //Testing Adding nodes
   addNode(andG,"testGate");

    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(400, 400);
    setWindowTitle(tr("A5: Gates and GUI"));

//! [0]



}


//! [3]
void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Return:
    {
        //Reading in From the Textbox.
        break;
    }
    default:
        QGraphicsView::keyPressEvent(event);
    }
}
//! [3]



//! [6]
void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
	painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
	painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersect(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

#if !defined(Q_OS_SYMBIAN) && !defined(Q_WS_MAEMO_5)
    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Type Commands into the textbox to manipulate the circuit"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
#endif
}
//! [6]

void GraphWidget::addNode(NodeShape type, QString Name)
{
    Node *newNode = new Node(this);
    gatePtrType newGate;

    switch(type){
    case andG:
        newGate = new andGate(parent());
        break;
    case orG:
        newGate = new orGate(parent());
        break;
    case falseG:
        newGate = new falseGate(parent());
        break;
    case trueG:
        newGate = new trueGate(parent());
        break;
    }
    newNode->setObjectName(Name);
    newGate->init(Name);

    //Connect Output Changed Signal
  //  QObject::connect(newGate,SIGNAL(outputChanged()),newNode,SLOT(Node::GateOuputChanged()));
    scene()->addItem(newNode);
   //Add to List
    m_nodes.insert(Name,newNode);
    m_circuit.insert(Name,newGate);

}
void GraphWidget::connect(QString destGate, QString sourceGate)
{

//Connect the Two Gates together.
    m_circuit[destGate]->setInput(m_circuit[sourceGate]);
//Connect the Two Nodes together.
    QObject::connect(m_nodes[sourceGate],SIGNAL(destroyed()),m_nodes[destGate],SLOT(NodeDestroyed()));

    m_nodes[destGate]->addEdge(m_nodes[sourceGate]);



}

void GraphWidget::destroy(QString gateDestroyed)
{
  gatePtrType temp =  m_circuit[gateDestroyed];
  m_circuit.remove(gateDestroyed);
  delete temp;

  Node * tempNode = m_nodes[gateDestroyed];
  m_nodes.remove(gateDestroyed);
  delete tempNode;


}

void GraphWidget::shuffle()
{
    foreach (QGraphicsItem *item, scene()->items()) {
        if (qgraphicsitem_cast<Node *>(item))
            item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
    }
}

void GraphWidget::zoomIn()
{
   // scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
   // scaleView(1 / qreal(1.2));
}
