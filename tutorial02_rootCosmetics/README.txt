When compiled and run, rootTree.cc will generate a ROOT tree containing two branches,
then output this tree to a root file.

When run (ideally in batch mode) through ROOT, tree_reader.cxx will read the output root file,
iterate through its branches, and plot the data contained within on a two-dimensional
histogram.

This histogram will then be variously customized and output as both a pdf and a png file.
