void correlation_ex()
{
    const int nPoints = 1000;
    Double_t x[nPoints], y[nPoints];
    TRandom3 randGen;
    for (int i = 0; i < nPoints; ++i) {
        // x[i] = randGen.Gaus(50, 5);  // 평균 0, 표준편차 1의 가우시안 분포
        // //y[i] = 2 * x[i] + randGen.Gaus(0, 0.5);  // y는 x에 선형적으로 종속되며 약간의 노이즈 추가
        // y[i] = randGen.Gaus(50, 5);

        x[i] = randGen.Gaus(172, 10);
        y[i] = randGen.Gaus(163, 7); 
    }

    // TH2F 생성
    TH2F *histogram = new TH2F("histogram", "Correlation Example", 200, 0, 200, 200, 0, 200);
    for (int i = 0; i < nPoints; ++i) {
        histogram->Fill(x[i], y[i]);
    }

    // 캔버스 생성 및 히스토그램 그리기
    TCanvas *canvas = new TCanvas("canvas", "Correlation Example", 800, 600);
    histogram->Draw("COLZ");  // "COLZ"는 색깔로 히트맵을 그리라는 의미

    // 히스토그램에 대한 표시 설정
    histogram->SetTitle("Correlation Example");
    histogram->GetXaxis()->SetTitle("male height (cm)");
    histogram->GetYaxis()->SetTitle("female height (cm)");

    // 캔버스 표시
    //canvas->Draw();
}
