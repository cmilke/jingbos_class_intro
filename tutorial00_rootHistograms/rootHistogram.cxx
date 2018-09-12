void rootHistogram() {
    //Initialize an empty one-dimensional histogram which stores floating point (double) values
    int number_of_bins = 100;
    float maximum_x_value = 5;
    float minumum_x_value = 0;
    TH1F* simple_histogram = new TH1F("simpleHistogramID","Simple Histogram Title", number_of_bins, minumum_x_value, maximum_x_value);

    //Fill the histogram with a bunch of values
    int number_of_inputs = 1000;
    for (int counter = 0; counter < number_of_inputs; counter++) {
        float data_point = std::pow(counter/500.0, 2); //create some meaningless data to plot
        simple_histogram->Fill(data_point);
    }

    //Display the histogram
    simple_histogram->Draw();
}
