Hashing obj;
    int x;
    string B[]= {"Abhi",  "ABC",   "Sample", "Ganesh", "Pankaj", "Viraj",  "Shreyas", "PQR",    "Gopal"};
    int A[] = {14895496, 13238342, 25454435, 34439239, 12345676, 14321822, 547855625, 66746268, 76857335};
    for(int i=0;i<size-1;i++)
    {
                
        obj.insertWithReplacement(B[i],A[i]);
    }
    obj.display();
    cout << endl;
    x = obj.search(1);