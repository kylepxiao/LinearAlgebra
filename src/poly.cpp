#include "poly.h"

poly::poly()
{
    std::vector<double> vec;
    coord.push_back(vec);
    coord.push_back(vec);
}

poly::~poly()
{
    //dtor
}

void poly::getpoints()
{
    coord[0].clear();
    coord[1].clear();
    const char* space = " ";
    bool run = true;
    double num1, num2;
    int pos;
    std::string ans, constans, str_degree;
    std::string str1, str2;
    cout<<"Enter the degree for which you would like to solve."<<endl;
    cin>>str_degree;
    degree = (int) atoi(str_degree.c_str());
    if(degree > 0) {
        cout<<"Enter the points. Put a space in between each value, and press enter twice to terminate."<<endl;
        std::getline(std::cin, ans);
        while(run)
        {
            std::getline(std::cin, ans);
            constans = ans;
            if (ans.empty())
            {
                run = false;
            }
            else
            {
                if(ans.find(" ") != std::string::npos){
                    for (unsigned int i=0; i<ans.size(); i++)
                    {
                        if (ans[i] == *space)
                        {
                            pos = i;
                            i=ans.size();
                        }
                    }
                    str1 = ans.erase(pos, ans.size()-pos);
                    ans = constans;
                    str2 = ans.erase(0, (pos+1));
                    num1 = atof(str1.c_str());
                    num2 = atof(str2.c_str());
                    coord[0].push_back(num1);
                    coord[1].push_back(num2);
                }
            }
        }
    }
}

std::vector< std::vector<double> > poly::round(std::vector< std::vector<double> > mat)
{
    for (unsigned int i=0; i<mat.size(); i++)
    {
        for (unsigned int k=0; k<mat[i].size(); k++)
        {
            mat[i][k] = floor(mat[i][k]*100+0.5)/100;
        }
    }
    return mat;
}

void poly::printvec(std::vector<double> vec)
{
    for (unsigned int k=0; k<vec.size(); k++)
    {
        cout<<vec[k]<<" ";
    }
    cout<<endl;
}

double poly::dot(std::vector< double > vec1, std::vector< double > vec2)
{
    double num = 0;
    if (!(vec1.size()==vec2.size()))
    {
        cerr<<"Vectors cannot be dot multiplied."<<endl;
        return num;
    }
    for (unsigned int i=0; i<vec1.size(); i++)
    {
        num = num+(vec1[i]*vec2[i]);
    }
    return num;
}

std::vector< std::vector<double> > poly::mult(std::vector< std::vector<double> > mat1, std::vector< std::vector<double> > mat2)
{
    std::vector<double> vec1, vec2;
    std::vector< std::vector<double> > tempmat1;
    if (!(mat1[0].size()==mat2.size()))
    {
        cerr<<"Matrix can not be multiplied"<<endl;
        std::vector< std::vector<double> > vec;
        return vec;
    }
    for (unsigned int i=0; i<mat1.size(); i++)
    {
        vec2.clear();
        for (unsigned int k=0; k<mat2[0].size(); k++)
        {
            vec1.clear();
            for (unsigned int j=0; j<mat2.size(); j++)
            {
                vec1.push_back(mat2[j][k]);
            }
            vec2.push_back(poly::dot(mat1[i], vec1));
        }
        tempmat1.push_back(vec2);
    }
    return tempmat1;
}

double poly::det(std::vector< std::vector<double> > mat)
{
    double tempdet, findet, posval, total=0;
    std::vector< std::vector<double> > tempmat;
    if (!(mat.size()==mat[0].size()))
    {
        cerr<<"Cannot find determinant."<<endl;
        return 0;
    }

    for (unsigned int i=0; i<mat[0].size(); i++)
    {
        posval = mat[0][i];
        tempmat = mat;
        if (mat.size() == 2)
        {
            tempdet = (tempmat[0][0]*tempmat[1][1])-(tempmat[0][1]*tempmat[1][0]);
            return tempdet;
        }
        else
        {
            for (unsigned int k=0; k<mat.size(); k++)
                {
                    tempmat[k].erase(tempmat[k].begin()+i);
                }
            tempmat.erase(tempmat.begin());
            findet = posval*poly::det(tempmat);
            if ((i%2==1))
            {
                findet *= -1;
            }
            total+= findet;
        }
    }
    return total;
}

std::vector< std::vector<double> > poly::invert(std::vector< std::vector<double> > mat)
{
    double vecratio, divideratio;
    int iterate = 0;
    std::vector< std::vector<double> > ident;
    std::vector<double> tempvec, origvec, identvec, origdent, subvector;
    if (!(mat.size()==mat[0].size()))
    {
        cerr<<"Cannot invert matrix."<<endl;
        return ident;
    }
    else if (poly::det(mat)==0)
    {
        cerr<<"Matrix inversion undefined."<<endl;
        return ident;
    }
    for (unsigned int i=0; i<mat.size(); i++)
    {
        tempvec.clear();
        for (unsigned int k=0; k<mat[0].size(); k++)
        {
            if (i==k)
            {
                tempvec.push_back(1);
            }
            else
            {
                tempvec.push_back(0);
            }
        }
        ident.push_back(tempvec);
    }

    for (unsigned int i=0; i<mat.size(); i++)
    {
        tempvec.clear();
        iterate = 1;
        origvec = mat[i];
        origdent = ident[i];
        while (mat[i][i]==0)
        {
            tempvec = mat[i+iterate];
            identvec = ident[i+iterate];
            mat[i] = tempvec;
            ident[i] = identvec;
            mat[i+iterate] = origvec;
            ident[i+iterate] = origdent;
            iterate++;
        }
        divideratio = mat[i][i];
        for (unsigned int k=0; k<mat[0].size(); k++)
        {
            mat[i][k] = mat[i][k]/divideratio;
            ident[i][k] = ident[i][k]/divideratio;
        }
        for (unsigned int j=0; j<mat.size(); j++)
        {
            if (!(j==i))
            {
                tempvec.clear();
                vecratio = mat[j][i];
                for (unsigned int l=0; l<mat[0].size(); l++)
                {
                    mat[j][l] -= vecratio*mat[i][l];
                    ident[j][l] -= vecratio*ident[i][l];
                }
            }
        }
    }
    return ident;
}


//interpolation loop


std::vector< std::vector<double> > poly::interpolate()
{
    double sum;
    std::vector<double> xysums, vec;
    std::vector< std::vector<double> > coeff, constval, tempval, ansmat;
    for (int i=0; i<(degree+1); i++)
    {
        xysums.clear();
        sum = 0;
        for (unsigned int k=0; k<coord[0].size(); k++)
        {
            sum = sum + ((pow(coord[0][k], i)*coord[1][k]));
        }
        xysums.push_back(sum);
        constval.push_back(xysums);
    }
    std::reverse(constval.begin(), constval.end());


    for (int i=0; i<degree+1; i++)//the current variable differentiated
    {
        vec.clear();
        for (int k=0; k<degree+1; k++)//the current term
        {
            sum = 0;
            for (unsigned int j=0; j<coord[0].size(); j++)//the current iteration in the sum
            {
                sum = sum + pow(coord[0][j], ((degree-i)+(degree-k)));//highest-low
            }
            vec.push_back(sum);
        }

        coeff.push_back(vec);
    }

    tempval = poly::invert(coeff);

    if (tempval != ansmat)
    {
        ansmat = poly::mult(poly::invert(coeff), constval);
    }
    else
    {
        cerr<<"The data given is insufficient."<<endl;
    }
    return ansmat;
}

void poly::printans(std::vector< std::vector<double> > mat)
{
    cout << "Y = ";
    for (unsigned int k=0; k<mat.size(); k++)
    {
        for (unsigned int i=0; i<mat[k].size(); i++)
        {
            if(mat[k][i] != 0){
                if(k > 0){
                    if(mat[k][i] < 0){
                        cout << " - ";
                    }else{
                        cout << " + ";
                    }
                }else{
                    if(mat[k][i] < 0){
                        cout << "-";
                    }
                }
                if(mat[k][i] == 1){
                    cout << "X^" << mat.size()-1-k;
                }else if(mat.size()-1-k == 0){
                    cout << abs(mat[k][i]);
                }else if(mat.size()-1-k == 1){
                    cout << abs(mat[k][i]) << "X";
                }else{
                    cout << abs(mat[k][i]) << "X^" << mat.size()-1-k;
                }
            }
        }
    }
    cout<<endl;
}

void poly::solveQuad(){
    string str_ans;
    double a, b, c, re, im;
    cout << "Enter the coefficients of the quadratic equation in standard form\n";
    cout << "A=";
    cin >> str_ans;
    if(str_ans == "exit"){
        return;
    }
    a = (double) atoi(str_ans.c_str());
    if(a == 0){
        cerr << "Invalid Quadratic\n";
        return;
    }
    cout << "B=";
    cin >> str_ans;
    if(str_ans == "exit"){
        return;
    }
    b = (double) atoi(str_ans.c_str());
    cout << "C=";
    cin >> str_ans;
    if(str_ans == "exit"){
        return;
    }
    c = (double) atoi(str_ans.c_str());
    im = b*b - 4*a*c;
    re = -b / (2*a);
    if(im < 0){
        im = sqrt(-im) / (2*a);
        cout << "Root1: " << re << " + " << im << "i\n";
        cout << "Root2: " << re << " - " << im << "i\n";
    }else if(im == 0){
        cout << "Root: " << re << "\n";
    }else{
        im = sqrt(im) / (2*a);
        cout << "Root1: " << re + im << "\n";
        cout << "Root2: " << re - im << "\n";
    }
}
