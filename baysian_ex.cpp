namespace hist_value
{   
    int kTrigbegin = 0;
    const int kCanvasww = 800;
    const int kCanvaswh = 600;
    const int kXlow = 0;
    const int kXup = 100;
    const int kNbinsx = 100;
    const double kLegendx1 = 0.7;
    const double kLegendy1 = 0.5;
    const double kLegendx2 = 0.9;
    const double kLegendy2 = 0.7;
    double mean = 45.17;
    double sigma = 13.13;
}

using namespace hist_value;

enum Trig
{
    off,
    on,
    kTrigend = 100
};

void baysian_ex()
{
    auto *canvas1 = new TCanvas("canvas1", "bayesian", kCanvasww, kCanvaswh);
    auto *gaus_hist1 = new TH1D("gaus1", "gaushist", kNbinsx, kXlow, kXup);
    gaus_hist1 -> SetLineColor(kBlack);
    auto *gaus_hist2 = new TH1D("gaus2", "gaushist", kNbinsx, kXlow, kXup);
    // auto *gaus_hist3 = new TH1D("gaus3", "gaushist", kNbinsx, kXlow, kXup);
    // gaus_hist3 -> SetLineColor(kBlack);
    auto *legend = new TLegend(kLegendx1, kLegendy1, kLegendx2, kLegendy2);
    // legend -> AddEntry(gaus_hist1, "Likelihood (Red Line)", "l");
    // legend -> AddEntry(gaus_hist2, "Chi-square (Blue Line)", "l");

    TRandom3 randGen;

    for(auto i = kTrigbegin; i < kTrigend; i++)
    {
        cout<<"a"<<endl;
        double data = randGen.Gaus(mean, sigma);
        cout<<"b"<<endl;
        gaus_hist1 -> Fill(data);
        cout<<"c"<<endl;
        gaus_hist2 -> Fill(data);
        cout<<"d"<<endl;
        // gaus_hist1 -> SetLineColor(kBlack);

        // First fit (Likelihood)x
        if (true)
        {
            cout<<"A"<<endl;
            gaus_hist1->Fit("gaus", "LQ");
            cout<<"B"<<endl;
            TF1 *likelihood_fit = gaus_hist1->GetFunction("gaus"); // to change line color
            cout<<"C"<<endl;
            likelihood_fit->SetLineColor(kRed);
            cout<<"D"<<endl;

            cout<<"before if1 : "<<i<<endl;
            // if(i == 8)
            // {
            //     cout<<"BEFORE EXCUTE1 : "<<i<<endl;
            //     // legend -> AddEntry(gaus_hist1, "Likelihood (Red Line)", "l");
            //     legend -> AddEntry(likelihood_fit, "Likelihood (Red Line)", "l");
            //     cout<<"AFTER EXCUTE1 : "<<i<<endl;   
            // }
            cout<<"after if1 : "<<i<<endl;    
            //likelihood_fit -> Update();
        }
        
        // Second fit (chi-square)
        if (true)
        {
            gaus_hist2->Fit("gaus", "Q");
            TF1 *chi_square_fit = gaus_hist2->GetFunction("gaus"); // to change line color
            chi_square_fit->SetLineColor(kBlue);

            cout<<"before if2 : "<<i<<endl;
            // if(i == 8)
            // {
            //     cout<<"BEFORE EXCUTE2 : "<<i<<endl;
            //     // legend -> AddEntry(gaus_hist2, "Chi-square (Blue Line)", "l");
            //     legend -> AddEntry(chi_square_fit, "Chi_square (Blue Line)", "l");
            //     cout<<"AFTER EXCUTE2 : "<<i<<endl;
            // }
            cout<<"after if2 : "<<i<<endl;
            //chi_square_fit -> Update();
        }
        
        cout<<"E"<<endl;
        // gaus_hist3 -> Fill(data);
        // gaus_hist3 -> Draw("same");
        gaus_hist1 -> Draw("SAME");
        cout<<"F"<<endl;
        legend -> Draw();
        cout<<"G"<<endl;

        // TString filename = Form("histogram1_%03d.png", i);
        // canvas1 -> SaveAs(filename);

        
        canvas1 -> Update();
        cout<<"H"<<endl;
        gSystem -> ProcessEvents();
        cout<<"I"<<endl;

        // gSystem -> Sleep(100); // ms
    }    
    

    
}