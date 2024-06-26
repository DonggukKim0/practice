void ttree_ex()
{
    TFile *file1 = new TFile("file.root", "RECREATE");
    TTree *tree1 = new TTree("dg_tree", "tree title");

    int pid;
    tree1 -> Branch("particleID", &pid);

    double mom;
    tree1 -> Branch("momentum", &mom);

    pid = 1;
    mom = 5.192;
    tree1 -> Fill();

    pid = 1;
    mom = 3.004;
    tree1 -> Fill();

    pid = 2;
    mom = 12.559;
    tree1 -> Fill();

    tree1 -> Write();
    file1 -> Close();
}