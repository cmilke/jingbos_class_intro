void tree_reader() {
    //create a Two Dimensional Histogram on which to plot our data
    int num_x_bins = 50;
    int num_y_bins = 50;
    float xmin = 0.0;
    float xmax = 10.0;
    float ymin = 3.0;
    float ymax = 20.0;
    TH2F* heat_map = new TH2F("heat", "A Two Dimensional Histogram Example", num_x_bins, xmin, xmax, num_y_bins, ymin, ymax);


    //Load data from generated root file
    TFile root_file("tree_example.root", "read");
    TTree* example_tree = (TTree*) root_file.Get("treeID"); 

    float x_data, y_data;
    example_tree->SetBranchAddress("data1", &x_data); 
    example_tree->SetBranchAddress("data2", &y_data); 

    //loop through branches of tree and fill 2D Histogram with data
    int number_of_entries = example_tree->GetEntries();
    for (int entry = 0; entry < number_of_entries; entry++) {
        example_tree->GetEntry(entry);
        heat_map->Fill(x_data,y_data);
    }

    //Draw 2D histogram with colored bins (col)
    //and a scale for the color (z) axis
    heat_map->Draw("colz");
}
