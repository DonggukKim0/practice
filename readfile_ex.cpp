void readfile_ex()
{
    TFile *file1 = new TFile("output.root", "read");
    TH1D *hist1 = (TH1D*) file1 -> Get("hist3");

    TCanvas *can1 = new TCanvas("can1", "outputfile", 800, 600);

    hist1 -> Draw();
    hist1 -> SetFillColor(kBlue);
    hist1 -> SetLineColor(kRed);
}