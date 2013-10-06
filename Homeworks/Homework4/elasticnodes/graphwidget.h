#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QtGui/QGraphicsView>
#include "gate.h"
#include "node.h"
#include <QLineEdit>

class Node;

//! [0]
class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = 0);

    // Create node and gate add to appropriate Qmap with the Name as the key.
    // connect the new gate's outputChaged signal to node's outputChaged slot
    // type will notify the method as to what type of gate is being created (to set m_shape of the new Node)
    void addNode(NodeShape type, QString Name);
    // Read in destGate and sourceGate, call add edge on destage by passing in sourceGate as a parameter
    // also connect sourceNode's destroyed signal to destNode's NodeDestroyed() slot
    void connect(QString destGate, QString sourceGate);
    // Read in gateName, delete Node from m_nodes, and delete gate from m_circuit
    void destroy(QString gateDestroyed);
    // returns pointer to gate with name as key
    gatePtrType getGate(QString key) const;
    // returns pointer to node with name as key
    Node *getNode(QString key) const;

public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event); // return key will trigger a read fromt he m_tBox
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    QMap<QString, Edge *> m_edges; // all edges in the scene, edges with the same destNode will have the same key
    QMap<QString, Node *> m_nodes; // all nodes in the scene
    QMap<QString, gatePtrType> m_circuit; // all gates created
    QGraphicsScene *m_scene; // scene
    QLineEdit *m_tBox; // text box for user input
    QObject m_parent; // parent under which all objects will be created
};
//! [0]

#endif
