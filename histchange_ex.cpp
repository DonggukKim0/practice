void histchange_ex() 
{
    const int numSamples = 100;
    const int numVariables = 10;
    double values[numVariables];
    TRandom randomGenerator;
    
    TCanvas *c1= new TCanvas("c1", "central window", 800, 600);

    TH1D *hist1 = new TH1D("hist1", "central limit theory", 100, 0, 100);
    for(int i=0; i<numSamples; i++)
    {
        for(int j=0; j<numVariables; j++)
            {
                values[j] = randomGenerator.Uniform(0,100);
            }

        double sum = 0;
        
        for(int j=0; j < numVariables; j++)
        {
            sum += values[j];
        }
        
        hist1 -> Fill(sum/numVariables);    
        hist1 -> Draw();
        c1 -> Update();

        // TString filename = Form("histogram_%03d.png", i);
        // c1 -> SaveAs(filename);

        gSystem->ProcessEvents();
        gSystem->Sleep(100);
        
    }
}