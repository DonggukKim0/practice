void makecsvfile_ex()
{
    TFile *file1 = new TFile("massenergy.root", "RECREATE");
    TTree *tree1 = new TTree("dg_tree", "mass and energy");

    float mass, energy;

    tree1 -> SetBranchAddress("mass", &mass);
    tree1 -> SetBranchAddress("energy", &energy);

    for(int i = 0; i < 1000; i++)
    {
        mass = randGen.Gaus(30.87, 5.67)
    }
}