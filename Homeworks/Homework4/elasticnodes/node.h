#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>
#include <gate.h>

class Edge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

// represents the shape of the node (depends on what type of gate this is)
enum NodeShape{andG, orG, trueG, falseG};
// reprsents the color of the node (depends of the output of the gate this node represents)
enum NodeColor{trueOut,falseOut, undefined};

//! [0]
class Node : public QGraphicsObject
{
public:
    Node(GraphWidget *graphWidget);

    // create a new edge (only called on destNodes)
    void addEdge(Node *Source);
    // returns true if edgeList contains an edge with the sourceNode as source
    bool hasEdge(Node *source) const;
    // remove an edge = needed if a node is destroyed
    void removeEdge(Node *Source);
    // sets the shape, paints draws a different shape depending on what this variable is
    void setShape(NodeShape shape);
    // returns the shape
    NodeShape getShape();
    // sets the color, paints draws a different color depending on what this variable is
    void setColor(NodeColor color);
    //Returns the current color of the node
    NodeColor getColor();

    // will delete all edges in the edgelist
    ~Node();

    enum { Type = UserType + 1 };
    int type() const { return Type; }

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
    // Should be called when the gate output changes
    // calls setColor to change the color according to the new output of the gate
    void GateOuputChanged();

    // Should be called when a node connected to this node is destroyed
    // this method will basically remove unnecessary edges
    void NodeDestroyed();
private:
    QPointF newPos;
    GraphWidget *graph;

    QList<Edge *> edgeList;
    NodeShape m_shape;
    NodeColor m_color;
};
//! [0]

#endif
