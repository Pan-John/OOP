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
#include <iostream>
#include "mySystem_GraphSystem.h"
#include <time.h>

using namespace std;

int Param::GRAPH_MAX_NUM_NODES = 10000;
int Param::GRAPH_MAX_NUM_EDGES = 10000;

GRAPH_SYSTEM::GRAPH_SYSTEM()
{
    mFlgAutoNodeDeletion = false;
    initMemory();
    reset();
    createDefaultGraph();
}

void GRAPH_SYSTEM::initMemory()
{
    mMaxNumNodes = Param::GRAPH_MAX_NUM_NODES;
    mMaxNumEdges = Param::GRAPH_MAX_NUM_EDGES;

    mNodeArr_Pool = new GRAPH_NODE[mMaxNumNodes];
    mEdgeArr_Pool = new GRAPH_EDGE[mMaxNumEdges];

    mActiveNodeArr = new int[mMaxNumNodes];
    mActiveEdgeArr = new int[mMaxNumEdges];

    mFreeNodeArr = new int[mMaxNumNodes];
    mFreeEdgeArr = new int[mMaxNumEdges];
    //
    for (int i = 0; i < mMaxNumNodes; ++i) {
        mNodeArr_Pool[i].id = i;
    }
    for (int i = 0; i < mMaxNumEdges; ++i) {
        mEdgeArr_Pool[i].id = i;
    }
    //
}

void GRAPH_SYSTEM::reset()
{
    stopAutoNodeDeletion();

    //mNumPoints_DoubleCircles = 0;

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;

    mCurNumOfFreeNodes = mMaxNumNodes;
    mCurNumOfFreeEdges = mMaxNumEdges;

    for (int i = 0; i < mCurNumOfFreeNodes; ++i) {
        mFreeNodeArr[i] = i;
    }
    for (int i = 0; i < mCurNumOfFreeEdges; ++i) {
        mFreeEdgeArr[i] = i;
    }

    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
}

void GRAPH_SYSTEM::createDefaultGraph()
{
    reset();

    int n[3];
    n[0] = addNode(0.0, 0.0, 0.0);
    n[1] = addNode(5.0, 0.0, 0.0);
    n[2] = addNode(0.0, 0.0, 5.0);

    addEdge(n[0], n[1]);
    addEdge(n[1], n[2]);

}

void GRAPH_SYSTEM::createNet_Circular(int n, int num_layers)// 12 3
{
    reset();

    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 15.;// O
    float offset_z = 15.;

    vector<int> id;
    id.resize(n * (num_layers + 1));//total
    for (int j = 0; j < num_layers + 1; j++) {
        for (int i = 0; i < n; i++) {
            float x, z;
            float cr = r + d * j;
            float a = i / (float)n * 2.0 * 3.14;// change to radian--> (360/n)*(3.14/180)*i
            x = cr * cos(a);//cos 0 = 1
            z = cr * sin(a);
            int index = i + j * n;
            id[index] = addNode(offset_x + x, 0.0, offset_z + z);//from 15,15 inverse clockwise
        }
        if (j < num_layers)//add edge to same layer
            for (int i = 0; i < n; i++) {
                int k0, k1;
                k0 = i + j * n;
                k1 = (i + 1) % n + j * n;

                addEdge(id[k0], id[k1]);
            }
    }
    for (int j = 0; j < num_layers; j++) {// from in to out
        for (int i = 0; i < n; ++i) {
            int k0, k1;
            k0 = i + n * j;
            k1 = i + n * (j + 1);
            addEdge(id[k0], id[k1]);
        }
    }

}
void GRAPH_SYSTEM::createNet_Square(int n, int num_layers)
{
    reset();

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 5.;
    float offset_z = 5.;

    vector<int> id;
    int total = num_layers * num_layers;//total square
    id.resize(total);
    for (int j = 0; j < num_layers; j++) {
        for (int i = 0; i < num_layers; i++) {
            float x, z;
            x = i * dx;
            z = j * dz;
            int index = i + j * num_layers;//from R2L from U2D
            id[index] = addNode(offset_x + x, 0.0, offset_z + z);
        }
    }
    for (int j = 0; j < num_layers; j++) {//from R2L
        for (int i = 0; i < num_layers - 1; i++) {// to avoid the last of a layer link to the first of next layer
            int k0, k1;
            k0 = i + num_layers * j;
            k1 = k0 + 1;
            addEdge(id[k0], id[k1]);
        }
    }

    for (int j = 0; j < num_layers - 1; j++) {//from U2D
        for (int i = 0; i < num_layers; i++) {
            int k0, k1;
            k0 = i + num_layers * j;
            k1 = k0 + num_layers;
            addEdge(id[k0], id[k1]);
        }
    }

    int half = num_layers / 2 - n / 2;//nodes and edges to delete
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            int layer = num_layers / 2;
            int k = half * num_layers + j * num_layers + half + i;
            deleteNode(id[k]);
            deleteEdgesOfNode(id[k]);
        }
    }
}
void GRAPH_SYSTEM::createNet_RadialCircular(int n) {

    reset();

    float offset_x = 15.0;
    float offset_z = 15.0;

    float r = 15; // radius

    vector<int> id;
    id.resize(n + 1);
    id[0] = addNode(offset_x, 0.0, offset_z);// O
    for (int i = 0; i < n; i++) {
        float x, z;
        float a = i / (float)n * 2.0 * 3.14;
        x = r * cos(a);
        z = r * sin(a);
        int index = i + 1;
        id[index] = addNode(offset_x + x, 0.0, offset_z + z);
    }

    for (int i = 0; i < n; i++) {
        int k0, k1;
        k0 = 0;
        k1 = i + 1;
        addEdge(id[k0], id[k1]);
    }


}
void GRAPH_SYSTEM::createRandomGraph_DoubleCircles(int n)
{
    reset();
    // can't link to >4
    float r = 15; // radius
    float d = 10; // layer distance
    float offset_x = 15.;
    float offset_z = 15.;

    vector<int> id;
    id.resize(n * 2);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            float x, z;
            float cr = r + d * j;
            float a = i / (float)n * 2.0 * 3.14;
            x = cr * cos(a);
            z = cr * sin(a);
            int index = i + j * n;
            id[index] = addNode(offset_x + x, 0.0, offset_z + z);
        }
    }

    for (int i = 0; i < n; i++) {
        int k0 = i;
        int tmp_k1 = (k0 + (rand() % 3) * (2 * (rand() % 2) - 1)) % n;
        if (tmp_k1 < 0) tmp_k1 = (n - 1) + tmp_k1;
        int k1 = tmp_k1 + n;
        //int k = (int)sqrt(n) - 2;
        //if (k <= 0) k = 0;
        //int random = rand() % k ;// e.g. 25--> 0~3 24-->0~2
        //int q = rand() % 2;
        //int k1 = k0 + n + q * random + (1 - q) * (n - random);
        addEdge(id[k0], id[k1]);
    }
}

int GRAPH_SYSTEM::getFreeNode() {
    GRAPH_NODE* node = nullptr;
    int id = -1;
    if (mCurNumOfFreeNodes <= 0)return id;
    mCurNumOfFreeNodes--;
    id = mFreeNodeArr[mCurNumOfFreeNodes];

    mNodeArr_Pool[id].dynamicID = mCurNumOfActiveNodes;

    mActiveNodeArr[mCurNumOfActiveNodes] = id;
    mCurNumOfActiveNodes++;

    return id;
}
int GRAPH_SYSTEM::getFreeEdge() {
    GRAPH_EDGE* edge = nullptr;
    int id = -1;
    if (mCurNumOfFreeEdges <= 0)return id;
    mCurNumOfFreeEdges--;
    id = mFreeEdgeArr[mCurNumOfFreeEdges];

    mEdgeArr_Pool[id].dynamicID = mCurNumOfActiveEdges;

    mActiveEdgeArr[mCurNumOfActiveEdges] = id;
    mCurNumOfActiveEdges++;


    return id;
}
int GRAPH_SYSTEM::addNode(float x, float y, float z, float r)
{
    //
    // Implement your own stuff
    // 
    int id = getFreeNode();
    if (id < 0) return id;
    GRAPH_NODE* node = &mNodeArr_Pool[id];
    node->edgeID.clear();
    node->p.x = x;
    node->p.y = y;
    node->p.z = z;
    node->r = r;

    return id;
}
int GRAPH_SYSTEM::addEdge(int nodeID_0, int nodeID_1)
{
    //
    // Implement your own stuff
    //  
    int id = getFreeEdge();
    if (id < 0) return id;
    GRAPH_EDGE* edge = &mEdgeArr_Pool[id];
    edge->id = id;
    edge->nodeID[0] = nodeID_0;//actual id
    edge->nodeID[1] = nodeID_1;

    GRAPH_NODE* node;
    node = &mNodeArr_Pool[nodeID_0];
    node->edgeID.push_back(id);

    node = &mNodeArr_Pool[nodeID_1];
    node->edgeID.push_back(id);

    return id;
}

void GRAPH_SYSTEM::askForInput()
{
    cout << "GRAPH_SYSTEM" << endl;
    cout << "Key usage:" << endl;
    cout << "1: create a default graph" << endl;
    cout << "2: create a graph with 10x10 nodes. Connect the consecutive nodes horizontally" << endl;
    cout << "3: create a graph with 10x10 nodes. Connect the consecutive nodes vertically" << endl;
    cout << "4: create a graph with 10x10 nodes. Create 10 randomly generated edges" << endl;
    cout << "5: create a graph with 10x10 nodes. Create 10 randomly generated edges attached at a random node" << endl;
    cout << "Delete (0): delete a node and all the edges attached at it" << endl;
    cout << "Spacebar: unselect the selected node" << endl;
    cout << " " << endl;
    cout << "Use the mouse to select nodes and add edges" << endl;
    cout << "Click the left button to select/unselect or create an edge" << endl;
    cout << " " << endl;
    cout << "A selected node is highlighted as red." << endl;

}

GRAPH_NODE* GRAPH_SYSTEM::findNearestNode(double x, double z, double& cur_distance2) const
{
    GRAPH_NODE* n = 0;
    cur_distance2 = -1.0;
    for (int i = 0; i < mCurNumOfActiveNodes; ++i) {
        int id = mActiveNodeArr[i];
        const GRAPH_NODE* cn = &mNodeArr_Pool[id];
        double dx = cn->p.x - x;
        double dz = cn->p.z - z;
        double d2 = dx * dx + dz * dz;
        if (cur_distance2 < 0.0 || d2 < cur_distance2) {
            cur_distance2 = d2;
            n = (GRAPH_NODE*)cn;
        }

    }
    return n;
}

void GRAPH_SYSTEM::moveTo(double x, double y)
{
    if (!mSelectedNode) return;
    mSelectedNode->p.x = x;
    mSelectedNode->p.z = y;
}

void GRAPH_SYSTEM::clickAt(double x, double z)
{
    double cur_d2;
    GRAPH_NODE* n = findNearestNode(x, z, cur_d2);
    if (n == 0) {
        mSelectedNode = 0;
        return;
    }
    if (cur_d2 > n->r * n->r) {
        mSelectedNode = 0;
        return;

    }
    if (mSelectedNode == n) {
        mSelectedNode = 0;
        return;
    }
    if (mSelectedNode != 0) {
        addEdge(mSelectedNode->id, n->id);
        mSelectedNode = 0;
        return;
    }
    mSelectedNode = n;
}

void GRAPH_SYSTEM::deleteEdge(int edgeID)
{
    GRAPH_EDGE* e = &mEdgeArr_Pool[edgeID];
    int dynamicID = e->dynamicID;
    if (dynamicID + 1 == mCurNumOfActiveEdges) {
        --mCurNumOfActiveEdges; // last edge
    }
    else {
        --mCurNumOfActiveEdges;
        int src_id = mActiveEdgeArr[mCurNumOfActiveEdges];
        mActiveEdgeArr[e->dynamicID] = src_id;
        mEdgeArr_Pool[src_id].dynamicID = e->dynamicID;
    }

    mFreeEdgeArr[mCurNumOfFreeEdges] = e->id;
    ++mCurNumOfFreeEdges;
    //

}

void GRAPH_SYSTEM::removeEdgeFromNode(const GRAPH_EDGE* e, int nodeID)
{
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    int j = 0;
    for (int i = 0; i < n->edgeID.size(); i++) {
        if (n->edgeID[i] == e->id) {
        }
        else {
            n->edgeID[j++] = n->edgeID[i];
        }
    }
    n->edgeID.resize(j);
}

void GRAPH_SYSTEM::deleteEdgesOfNode(int nodeID)
{
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    for (int i = 0; i < n->edgeID.size(); i++) {
        deleteEdge(n->edgeID[i]);
        GRAPH_EDGE* e = &mEdgeArr_Pool[n->edgeID[i]];
        int src_nodeID = e->nodeID[0];
        if (e->nodeID[0] == nodeID) {
            src_nodeID = e->nodeID[1];
        }
        removeEdgeFromNode(e, src_nodeID);
    }
}

void GRAPH_SYSTEM::deleteNode(int nodeID) {
    if (mCurNumOfActiveNodes <= 0) return;
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    int dynamicID = n->dynamicID;
    if (dynamicID + 1 == mCurNumOfActiveNodes) {
        --mCurNumOfActiveNodes;
    }
    else {
        --mCurNumOfActiveNodes;
        int src_id = mActiveNodeArr[mCurNumOfActiveNodes];
        mActiveNodeArr[n->dynamicID] = src_id;
        mNodeArr_Pool[src_id].dynamicID = n->dynamicID;
    }

    mFreeNodeArr[mCurNumOfFreeNodes] = n->id;
    ++mCurNumOfFreeNodes;
}

void GRAPH_SYSTEM::deleteSelectedNode() {
    if (mSelectedNode == 0) return;
    deleteNode(mSelectedNode->id);
    deleteEdgesOfNode(mSelectedNode->id);
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

bool GRAPH_SYSTEM::isSelectedNode() const
{
    return mSelectedNode != 0;
}

void GRAPH_SYSTEM::getInfoOfSelectedPoint(double& r, vector3& p) const
{
    if (isSelectedNode() == false) return;
    r = mSelectedNode->r;
    p = mSelectedNode->p;

}

void GRAPH_SYSTEM::handleKeyPressedEvent(unsigned char key)
{

    switch (key) {
    case '0': // delete
        mFlgAutoNodeDeletion = false;
        deleteSelectedNode();
        break;
    case '1':
        mFlgAutoNodeDeletion = false;
        createDefaultGraph();
        mSelectedNode = 0;
        break;
    case '2':
        mFlgAutoNodeDeletion = false;
        createNet_Circular(12, 3);
        mSelectedNode = 0;

        break;
    case '3':
        mFlgAutoNodeDeletion = false;
        createNet_Square(3, 11);//you can modify this
        mSelectedNode = 0;

        break;
    case '4':
        mFlgAutoNodeDeletion = false;
        createNet_RadialCircular(24);
        mSelectedNode = 0;

        break;

    case '5':
        mNumPoints_DC = 24;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DC);
        mSelectedNode = 0;
        break;
    case '<':
        mNumPoints_DC--;
        if (mNumPoints_DC < 3)
            mNumPoints_DC = 3;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DC);
        mSelectedNode = 0;
        break;

    case '>':
        mNumPoints_DC++;
        if (mNumPoints_DC > 36)
            mNumPoints_DC = 36;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DC);
        mSelectedNode = 0;
        break;

    case ' ':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        break;
    case 'd'://g--->d
        mFlgAutoNodeDeletion = !mFlgAutoNodeDeletion;
        break;
    }
}

void GRAPH_SYSTEM::handlePassiveMouseEvent(double x, double z)
{
    double cur_d2;
    GRAPH_NODE* n = findNearestNode(x, z, cur_d2);
    if (n == 0) return;
    if (cur_d2 > n->r * n->r) {
        mPassiveSelectedNode = 0;
        return;
    }
    mPassiveSelectedNode = n;
}

int GRAPH_SYSTEM::getNumOfNodes() const
{
    return mCurNumOfActiveNodes;
}

void GRAPH_SYSTEM::getNodeInfo(int nodeIndex, double& r, vector3& p) const
{
    int nodeID = mActiveNodeArr[nodeIndex];
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    r = n->r;
    p = n->p;
}

int GRAPH_SYSTEM::getNumOfEdges() const
{
    return mCurNumOfActiveEdges;
}

vector3 GRAPH_SYSTEM::getNodePositionOfEdge(int edgeIndex, int nodeIndex) const
{

    vector3 p;
    //
    // Implement your own stuff
    // 
    int id = mActiveEdgeArr[edgeIndex];
    const GRAPH_EDGE* edge = &mEdgeArr_Pool[id];

    int node_id = edge->nodeID[nodeIndex];
    const GRAPH_NODE* node = &mNodeArr_Pool[node_id];

    p = node->p;

    return p;
}

void GRAPH_SYSTEM::stopAutoNodeDeletion()
{
    mFlgAutoNodeDeletion = false;
}

//
// For every frame, update( ) function is called.
//
// 
void GRAPH_SYSTEM::update()
{
    if (!mFlgAutoNodeDeletion) {

        return;
    }
    if (mCurNumOfActiveNodes <= 0) {
        mFlgAutoNodeDeletion = false;
        return;
    }
    Sleep(250);

    int nodeID = mActiveNodeArr[0];
    deleteNode(nodeID);

    deleteEdgesOfNode(nodeID);

    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}