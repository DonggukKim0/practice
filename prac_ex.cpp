void prac_ex()
{
        // Open CSV file
        FILE* csvFile = fopen("output2.csv", "r");
        if (!csvFile) {
            cout<<"Error opening CSV file."<<endl;
            return;
        }
        
        // Ignore first row 
        char line[256];
        fgets(line, sizeof(line), csvFile);

        // int result1 = fscanf(csvFile, "%f, %f\n", &weight1, &height1);
        // cout<<result1<<endl;

        // Create a new ROOT file and TTree
        TFile* rootFile = new TFile("output3.root", "RECREATE");
        TTree* newTree = new TTree("newTree", "Tree from CSV");

        // Variables to store data from CSV
        float weight1, height1;

        // Add TBranch to the TTree
        TBranch* branchWeight = newTree->Branch("weight", &weight1, "weight/F");
        TBranch* branchHeight = newTree->Branch("height", &height1, "height/F");

        // Loop over CSV file and fill TTree
        for(int i = 0; i < 100; i++)
        {
            int result = fscanf(csvFile, "%f, %f\n", &weight1, &height1);
            //cout<<result<<endl;

        // Check if reading was successful
            if (result == 2) {
            // Fill TBranches with data
                branchWeight->Fill();
                //cout<<"Fill1"<<i<<endl;
                branchHeight->Fill();
                //cout<<"Fill2"<<i<<endl;
            } else if (result == EOF)
            {
                cout<<"End of file reached."<<endl;
            } else
            {
                cout<<"Error reading data."<<endl;
            }
        }

        // Close CSV file
        fclose(csvFile);

        // Write TTree to the ROOT file
        rootFile->Write();
        rootFile->Close();
}