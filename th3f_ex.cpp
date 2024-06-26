void th3f_ex() 
{
    TH3F *histogram = new TH3F("histogram", "3D Histogram example", 100, -5, 5, 100, -5, 5, 100, -5, 5);

    TRandom3 randGen;
    for(int i = 0; i<10000; i++)
    {
        double x = randGen.Gaus(0, 1);
        double y = randGen.Gaus(0, 1);
        double z = randGen.Gaus(0, 1);
        histogram -> Fill(x, y, z);
    }

    TCanvas *canvas = new TCanvas("canvas", "3D Histogram example", 800, 600);

    histogram -> Draw("BOX1");

    histogram -> GetXaxis() -> SetTitle("X");
    histogram -> GetYaxis() -> SetTitle("Y");
    histogram -> GetZaxis() -> SetTitle("Z");
    

}