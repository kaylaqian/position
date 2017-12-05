#include <iostream>
#include "x.h"
#include "simulation.h"
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/filereadstream.h"

using namespace rapidjson;
int main() {
//    ifstream ifs("sanguo.json");
//    rapidjson::IStreamWrapper isw(ifs);
//    rapidjson::Document doc;
//    doc.ParseStream(isw);
    vector<Node*> nodes;
    vector<Edge> edges;
    FILE* fp = fopen("/Users/mengqing/CLionProjects/xy/sanguo.json", "r");
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);
    const rapidjson::Value& links = d["links"];
    const rapidjson::Value& vertices = d["nodes"];
    for (int i = 0; i < 77; i++) {
        nodes.push_back(new Node(i+1));
//        std::cout << "node.id\t" << nodes[i]->id<<std::endl;
//        std::cout << "node.x\t" << nodes[i]->x<<std::endl;
//        std::cout << "node.y\t" << nodes[i]->y<<std::endl;
    }
    for (int i = 0; i < links.Size(); i++) {
        const rapidjson::Value& object = links[i];
        int source = object["source"].GetInt();
        int target = object["target"].GetInt();
//        std::cout << "source = " << source << std::endl;
        edges.push_back(Edge(nodes[source], nodes[target]));
    }
    fclose(fp);

    std::cout << "|==================|" << std::endl;
    std::cout << "||rapidjson output||" << std::endl;
    std::cout << "|==================|" << std::endl;

    Simulation solution;
    solution.simulation(nodes, edges);

    Document document(rapidjson::kObjectType);
    Value vertices_result(rapidjson::kArrayType);
    Value edges_result(rapidjson::kArrayType);
    for (int i = 0; i<77; i++) {
        Value vertex(rapidjson::kObjectType);
        vertex.AddMember("id", rapidjson::Value(i).Move(), document.GetAllocator());
        vertex.AddMember("x", rapidjson::Value(nodes[i]->x).Move(), document.GetAllocator());
        vertex.AddMember("y", rapidjson::Value(nodes[i]->y).Move(), document.GetAllocator());
        vertices_result.PushBack(vertex, document.GetAllocator());
    }
    for (int i = 0; i<254; i++) {
        Value edge(rapidjson::kObjectType);
        edge.AddMember("source", Value(edges[i].source->id).Move(), document.GetAllocator());
        edge.AddMember("target", Value(edges[i].target->id).Move(), document.GetAllocator());
        edges_result.PushBack(edge, document.GetAllocator());
    }
    document.AddMember("vertices",  vertices_result, document.GetAllocator());
    document.AddMember("edges",  edges_result, document.GetAllocator());
    StringBuffer buffer;
    Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    std::cout << buffer.GetString() << std::endl;
    std::cout << "node.x\t" << nodes[70]->x<<std::endl;
    std::cout << "node.y\t" << nodes[70]->y<<std::endl;
    std::cout << "node.x\t" << nodes[60]->x<<std::endl;
    std::cout << "node.y\t" << nodes[60]->y<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}