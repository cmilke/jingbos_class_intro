//c++ libraries
#include <cmath> //so I can use pow

//ROOT libraries
#include "TFile.h"
#include "TTree.h"


int main() {
    TFile root_file("tree_example.root", "recreate");
    TTree example_tree("treeID","Example Tree Title");

    float data_variable1;
    float data_variable2;
    example_tree.Branch("data1", &data_variable1, "data1/F");
    example_tree.Branch("data2", &data_variable2, "data2/F");

    int number_of_inputs = 1000;
    for (int counter = 0; counter < number_of_inputs; counter++) {
        data_variable1 = std::pow(counter/500.0, 2); //create some meaningless data to plot
        data_variable2 = std::pow(counter/500.0, 3); //create some more meaningless data to plot
        example_tree.Fill();
    }

    example_tree.Write();
}
