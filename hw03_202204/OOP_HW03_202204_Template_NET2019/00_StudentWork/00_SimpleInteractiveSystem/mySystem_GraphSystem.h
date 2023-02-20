//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
//
// Prof. Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/04/25
//
//
// Add your own functions if necessary
//
#ifndef __MY_GRAPH_SYSTEM_H_
#define __MY_GRAPH_SYSTEM_H_
#include "../headers.h"
#include <string>
#include "../primitives/vector3d.h"
#include <vector>
#include "base_class.h"
#include "graph_basics.h"

using std::vector;

class Param {
public:
    static int GRAPH_MAX_NUM_NODES;
    static int GRAPH_MAX_NUM_EDGES;
};



class GRAPH_SYSTEM : public BASE_SYSTEM {

protected:
    void drawNodes_Indirect() const;
    void drawEdges_Indirect() const;
    void drawSelectedNode_Indirect() const;
    //
    GRAPH_NODE* GRAPH_SYSTEM::findNearestNode(double x, double z, double& cur_distance2) const;
    //GRAPH_NODE* findNearestNode(double x, double y, double& cur_distance2) const;
    void deleteNode(int nodeID);
    void deleteSelectedNode();
    //
    void createNet_Circular(int n, int num_layers);
    void createNet_Square(int n, int num_layers);
    void createNet_RadialCircular(int n);
    void createRandomGraph_DoubleCircles(int n);
    //
    // Implement your own stuff
    void initMemory();
    //int getFreeNode();
    //int getFreeEdge();

    void deleteEdge(int edgeID);
    void removeEdgeFromNode(const GRAPH_EDGE* e, int nodeID);
    void deleteEdgesOfNode(int nodeID);
    int getFreeNode();
    int getFreeEdge();
    //GRAPH_NODE* getFreeNode();
    //GRAPH_EDGE* getFreeEdge();
    //
public:
    GRAPH_SYSTEM();
    void update();
    void stopAutoNodeDeletion();
    void reset();
    void askForInput();
    void clickAt(double x, double z);
    void handleKeyPressedEvent(unsigned char key);
    void handlePassiveMouseEvent(double x, double y);
    void draw() const;
    void moveTo(double x, double y);
    int addNode(float x, float y, float z, float r = 1.0);
    int addEdge(int nodeID_0, int nodeID_1);
    bool isSelectedNode() const;
    void getInfoOfSelectedPoint(double& r, vector3& p) const;
    //
    void createDefaultGraph();
    //
    int getNumOfEdges() const;
    vector3 getNodePositionOfEdge(int edgeIndex, int nodeIndex) const;

    int getNumOfNodes() const;
    void getNodeInfo(int nodeIndex, double& r, vector3& p) const;
protected:
    //
    // Implement your own stuff
    //
    int mMaxNumNodes;
    int mMaxNumEdges;
    int mNumPoints_DC;

    GRAPH_NODE* mNodeArr_Pool;
    GRAPH_EDGE* mEdgeArr_Pool;
    //
    int* mActiveNodeArr;
    int mCurNumOfActiveNodes;
    int* mActiveEdgeArr;
    int mCurNumOfActiveEdges;
    //
    int* mFreeNodeArr;
    int* mFreeEdgeArr;
    int mCurNumOfFreeNodes;
    int mCurNumOfFreeEdges;
    //
    GRAPH_NODE* mSelectedNode;
    GRAPH_NODE* mPassiveSelectedNode;
    //
    bool mFlgAutoNodeDeletion;
};

#endif