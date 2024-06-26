void fitting_ex() 
{
    TH1F *histogram = new TH1F("histogram", "Gaussian Distribution", 100, -10, 10);
    histogram -> FillRandom("gaus", 10000);

    TCanvas *canvas = new TCanvas("canvas", "Canvas", 800, 600);

    histogram -> Draw();

    TF1 *fitFunction = new TF1("fitFunction", "gaus", -10, 10);
    fitFunction -> SetParameters(1, 0, 50);

    histogram -> Fit("fitFunction", "R");

    double mean = fitFunction -> GetParameter(1);
    double sigma = fitFunction -> GetParameter(2);

    fitFunction -> Draw("same");
}