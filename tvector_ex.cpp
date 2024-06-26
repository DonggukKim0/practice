void tvector_ex()
{
    TVector3 v(1, 2, 3);
    cout<<v.X()<<" "<<v.Y()<<" "<<v.Z()<<endl;

    cout<<"/************Vector****************/"<<endl;
    //Magnitude
    double magnitude = v.Mag();
    double magnitude1 = v.Mag2();
    double perp = v.Perp();
    double theta = v.Theta();
    double phi = v.Phi();
    cout<<magnitude<<endl;
    cout<<magnitude1<<endl;
    cout<<perp<<endl;
    cout<<theta<<endl;
    cout<<phi<<endl;
    v.Print(); // magnitude, theta, phi
    v.SetMag(37);
    v.SetPerp(20);
    v.SetPhi(0.9);
    v.SetTheta(0.5);
    v.Print();
    cout<<"/************UnitVector****************/"<<endl;

    //UnitVector
    TVector3 unitVector = v.Unit();
    cout<<unitVector.X()<<" "<<unitVector.Y()<<" "<<unitVector.Z()<<endl;
    double magnitude2 = unitVector.Mag2();
    cout<<magnitude2<<endl;



    // TMatrixD mat(2, 3);;

    // mat(0, 0) = 1;
    // mat(0, 1) = 2;
    // mat(0, 2) = 3;
    // mat(1, 0) = 4;
    // mat(1, 1) = 5;
    // mat(1, 2) = 6;

    // for(auto i = 0; i < mat.GetNrows(); i++)
    // {
    //     for(auto j = 0; j < mat.GetNcols(); j++)
    //     {
    //         cout<<mat(i, j)<<" ";
    //     }
    //     cout<<endl;
    // }

}