void makefile_ex()
{
    TFile *file = new TFile("makefile.root", "recreate");
    
    const int num = 10000;
    TRandom3 randGen;

    TH1D *hist1 = new TH1D("Gaus", "Gaus", 100, 0, 100);
    for(int i = 0; i < num; i++)
    {
        double bin = randGen.Gaus(55.43, 6.52);
        hist1 -> Fill(bin);
    }

    TH1D *hist2 = new TH1D("Landau", "Landau", 100, 0, 100);
    for(int i = 0; i < num; i++)
    {
        double bin = randGen.Landau(45.46, 5.56);
        hist2 -> Fill(bin);
    }

    TH1D *hist3 = new TH1D("Poisson", "Poisson", 500, 0, 100);
    for(int i = 0; i < num; i++)
    {
        double bin = randGen.Poisson(34.50);
        hist3 -> Fill(bin);
    }

    file -> Write(); // 현재까지의 작업을 파일에 기록
    file -> Close(); // 파일을 안전하게 저장하고 닫음
}