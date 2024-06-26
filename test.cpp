void test(){

TF1 * f1 = new TF1("f1","gaus",-10,10);    
f1->Draw();
        auto *legend = new TLegend(0,1,0,1);
        legend->AddEntry(f1,"test","l");
    legend->Draw("same");
}