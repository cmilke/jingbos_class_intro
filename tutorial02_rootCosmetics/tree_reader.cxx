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

    
    //Create a canvas on which to draw our histogram.
    //Note that if we did not create a canvas here,
    //then one would be automatically created with line below
    //"heat_map->Draw("colz");".
    //We explicitly construct the canvas here so that we can
    //refer to it later.
    double width = 1400;
    double height = 1000;
    TCanvas* canvas = new TCanvas("c1", "canvas", width, height);

    //Draw 2D histogram with colored bins (col)
    //and a scale for the color (z) axis
    heat_map->Draw("colz");


    /*Customize our heat map plot so it looks pretty*/

    //Create x and y labels, then center them
    heat_map->SetXTitle("Some Meaningless Data");
    heat_map->SetYTitle("More Meaningless Data");
    heat_map->GetXaxis()->CenterTitle();
    heat_map->GetYaxis()->CenterTitle();

    //Change the range of the axes.
    //Yes we could have just done this at the top...
    double x_axis_min = 0.0;
    double x_axis_max = 5.0;
    double y_axis_min = 0.0;
    double y_axis_max = 9.0;
    heat_map->GetXaxis()->SetRangeUser(x_axis_min,x_axis_max);
    heat_map->GetYaxis()->SetRangeUser(y_axis_min,y_axis_max);

    //Change color axis to logarithmic scale
    canvas->SetLogz(true);

    //Disable the annoying statistics box.
    //You might be wondering where this "gStyle"
    //variable came from. It is an object of type
    //"TStyle", and was automatically created by ROOT
    gStyle->SetOptStat(false);

    //Set palette for color-axis.
    //This "kBlueRedYellow" variable is an
    //enum, defined as part of the "TColor" class
    gStyle->SetPalette(kBlueRedYellow);


    //Update the canvas, then
    //save heat map to png and pdf.
    //Note that Update is usually run automatically
    //anytime you change something on the canvas.
    //I'm only running it manually because I'm paranoid.
    canvas->Update();
    canvas->SaveAs("heat_map.png");
    canvas->SaveAs("heat_map.pdf");
    
}
