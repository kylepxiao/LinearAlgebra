#include "Matrix.h"

Matrix::Matrix()
{
    //ctor
}

Matrix::~Matrix()
{
    //dtor
}


void Matrix::fillmat(int mat)
{
    int r, c;
    string str_r, str_c, str_temp;
    double temp;
    std::vector<double> tempvector;
    cout<<"What are the dimensions of the matrix? State the number of rows and columns respectively (enter number of rows as 1 for a vector)."<<endl;
    cout << "rows: ";
    cin>>str_r;
    r = (int) atoi(str_r.c_str());
    if(r > 0){
        cout << "columns: ";
        cin>>str_c;
        c = (int) atoi(str_c.c_str());
        if(c > 0){
            cout<<"Enter in the values from left to right, top to bottom."<<endl;
            if (mat == 1)
            {
                A.clear();
                for (int i=0; i<r; i++)
                {
                    tempvector.clear();
                    for (int k=0; k<c; k++)
                    {
                        cout << "A" << i+1 << "," << k+1 << "= ";
                        cin>>str_temp;
                        if(str_temp == "exit"){
                            return;
                        }
                        temp = (double) stod(str_temp.c_str());
                        tempvector.push_back(temp);
                    }
                    A.push_back(tempvector);
                }
            }
            else if (mat == 2)
            {
                B.clear();
                for (int i=0; i<r; i++)
                {
                    tempvector.clear();
                    for (int k=0; k<c; k++)
                    {
                        cout << "A" << i+1 << "," << k+1 << "= ";
                        cin>>str_temp;
                        if(str_temp == "exit"){
                            return;
                        }
                        temp = (double) stod(str_temp.c_str());
                        tempvector.push_back(temp);
                    }
                    B.push_back(tempvector);
                }
            }
            else if (mat == 3)
            {
                C.clear();
                for (int i=0; i<r; i++)
                {
                    tempvector.clear();
                    for (int k=0; k<c; k++)
                    {
                        cout << "A" << i+1 << "," << k+1 << "= ";
                        cin>>str_temp;
                        if(str_temp == "exit"){
                            return;
                        }
                        temp = (double) stod(str_temp.c_str());
                        tempvector.push_back(temp);
                    }
                    C.push_back(tempvector);
                }
            }
            else
            {
                cerr<<"Matrix not valid."<<endl;
            }
        }
    }
}

std::vector< std::vector<double> > Matrix::round(int num)
{
    std::vector< std::vector<double> > mat = Matrix::setmat(num);
    for (unsigned int i=0; i<mat.size(); i++)
    {
        for (unsigned int k=0; k<mat[i].size(); k++)
        {
            mat[i][k] = floor(mat[i][k]*100+0.5)/100;
        }
    }
    return mat;
}

std::vector< std::vector<double> > Matrix::round(std::vector< std::vector<double> > mat)
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

int Matrix::matconverter(std::vector< std::vector<double> > mat)
{
    if (mat==A)
    {
        return 1;
    }
    else if (mat==B)
    {
        return 2;
    }
    else if (mat==C)
    {
        return 3;
    }
    else if (mat==ans)
    {
        return 4;
    }
    else
    {
        cerr<<"Cannot convert matrix"<<endl;
        return 0;
    }
}

void Matrix::printans(std::vector< std::vector<double> > mat)
{
    for (unsigned int k=0; k<mat.size(); k++)
    {
        cout<<endl;
        for (unsigned int i=0; i<mat[k].size(); i++)
        {
            cout<<mat[k][i];
            cout<<" ";
        }
    }
    cout<<endl<<endl;
}

void Matrix::printcoeff(std::vector< std::vector<double> > mat)
{
    for (unsigned int k=0; k<mat.size(); k++)
    {
        cout<<endl;
        for (unsigned int i=0; i<mat[k].size(); i++)
        {
            cout<< "Var" << k+1 <<": " <<mat[k][i];
        }
    }
    cout<<endl<<endl;
}

void Matrix::printmat(int mat)
{
    Matrix::printans(Matrix::setmat(mat));
}


std::vector< std::vector<double> > Matrix::setmat(int mat)
{
    if (mat==1)
    {
        return A;
    }
    if (mat==2)
    {
        return B;
    }
    if (mat==3)
    {
        return C;
    }
    if (mat==4)
    {
        return ans;
    }
    else
    {
        cerr<<"Could not set Matrix."<<endl;
        std::vector< std::vector<double> > vec;
        return vec;
    }
}

double Matrix::dotproduct(int num1, int num2)
{
    double num = 0;
    std::vector< std::vector<double> > vec1 = Matrix::setmat(num1);
    std::vector< std::vector<double> > vec2 = Matrix::setmat(num2);
    if (!(vec1.size()==vec2.size()) || !(vec1.size()==1))
    {
        cerr<<"Vectors cannot be dot multiplied."<<endl;
        return num;
    }
    for (unsigned int i=0; i<vec1[0].size(); i++)
    {
        num = num+(vec1[0][i]*vec2[0][i]);
    }
    return num;
}

double Matrix::dot(std::vector< double > vec1, std::vector< double > vec2)
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

std::vector< std::vector<double> > Matrix::mult_const(double num1, int num2)
{
    std::vector<double> vec;
    std::vector< std::vector<double> > tempmat1, mat=Matrix::setmat(num2);
    if (mat.size() <= 0 || mat[0].size() <= 0)
    {
        cerr<<"Matrix can not be multiplied"<<endl;
        std::vector< std::vector<double> > vec;
        return vec;
    }
    for (unsigned int k=0; k<mat.size(); k++)
    {
        vec.clear();
        for (unsigned int j=0; j<mat[0].size(); j++)
        {
            vec.push_back(num1 * mat[k][j]);
        }
        tempmat1.push_back(vec);
    }
    return tempmat1;
}

std::vector< std::vector<double> > Matrix::add(int num1, int num2)
{
    std::vector<double> vec;
    std::vector< std::vector<double> > tempmat1, mat1=Matrix::setmat(num1), mat2=Matrix::setmat(num2);
    if (mat1.size() <= 0 || mat2.size() <= 0 || mat1[0].size() <= 0 || mat2[0].size() <= 0 || !(mat1.size()==mat2.size()) || !(mat1[0].size()==mat2[0].size()))
    {
        cerr<<"Matrix can not be added"<<endl;
        std::vector< std::vector<double> > vec;
        return vec;
    }
    for (unsigned int k=0; k<mat2[0].size(); k++)
    {
        vec.clear();
        for (unsigned int j=0; j<mat2.size(); j++)
        {
            vec.push_back(mat1[k][j] + mat2[k][j]);
        }
        tempmat1.push_back(vec);
    }
    return tempmat1;
}

std::vector< std::vector<double> > Matrix::sub(int num1, int num2)
{
    std::vector<double> vec;
    std::vector< std::vector<double> > tempmat1, mat1=Matrix::setmat(num1), mat2=Matrix::setmat(num2);
    if (mat1.size() <= 0 || mat2.size() <= 0 || mat1[0].size() <= 0 || mat2[0].size() <= 0 || !(mat1.size()==mat2.size()) || !(mat1[0].size()==mat2[0].size()))
    {
        cerr<<"Matrix can not be subtracted"<<endl;
        std::vector< std::vector<double> > vec;
        return vec;
    }
    for (unsigned int k=0; k<mat2[0].size(); k++)
    {
        vec.clear();
        for (unsigned int j=0; j<mat2.size(); j++)
        {
            vec.push_back(mat1[k][j] - mat2[k][j]);
        }
        tempmat1.push_back(vec);
    }
    return tempmat1;
}

std::vector< std::vector<double> > Matrix::mult(int num1, int num2)
{
    string yn;
    std::vector<double> vec1, vec2;
    std::vector< std::vector<double> > tempmat1, mat1=Matrix::setmat(num1), mat2=Matrix::setmat(num2);
    if (mat1.size() <= 0 || mat2.size() <= 0 || mat1[0].size() <= 0 || mat2[0].size() <= 0 || !(mat1[0].size()==mat2.size()))
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
            vec2.push_back(Matrix::dot(mat1[i], vec1));
        }
        tempmat1.push_back(vec2);
    }
    cout << "Would you like to round to avoid possible floating point error (yes/no)?\n";
    cin >> yn;
    if(yn == "yes"){
        tempmat1 = round(tempmat1);
    }else if(yn != "no" && yn != "exit"){
        cout << "Invalid Input: Defaulting to Yes\n";
        tempmat1 = round(tempmat1);
    }
    return tempmat1;
}

std::vector< std::vector<double> > Matrix::mult(std::vector< std::vector<double> > mat1, std::vector< std::vector<double> > mat2)
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
            vec2.push_back(Matrix::dot(mat1[i], vec1));
        }
        tempmat1.push_back(vec2);
    }
    return tempmat1;
}

std::vector< std::vector<double> > Matrix::transposeloop(int num)
{
    std::vector<double> vec;
    std::vector< std::vector<double> > tempmat;
    std::vector< std::vector<double> > mat = Matrix::setmat(num);
    for (unsigned int i=0; i<mat[0].size(); i++)
    {
        vec.clear();
        for (unsigned int k=0; k<mat.size(); k++)
        {
            vec.push_back(mat[k][i]);
        }
        tempmat.push_back(vec);
    }
    return tempmat;
}

std::vector< std::vector<double> > Matrix::cross(int num1, int num2)
{
    std::vector< std::vector<double> > vec1 = Matrix::setmat(num1);
    std::vector< std::vector<double> > vec2 = Matrix::setmat(num2);
    std::vector< double > vec;
    std::vector< std::vector<double> > mat;
    if (vec1.size()==1 && vec2.size()==1 && vec1[0].size()==3)
    {
        vec.push_back((vec1[0][1]*vec2[0][2])-(vec1[0][2]*vec2[0][1]));
        vec.push_back(-1*((vec1[0][0]*vec2[0][2])-(vec1[0][2]*vec2[0][0])));
        vec.push_back((vec1[0][0]*vec2[0][1])-(vec1[0][1]*vec2[0][0]));
        mat.push_back(vec);
    }
    else
    {
        cerr<<"Cannot find cross product of vectors."<<endl;
    }
    return mat;
}

std::vector< std::vector<double> > Matrix::invert(int num)
{
    double vecratio, divideratio;
    int iterate = 0;
    std::vector< std::vector<double> > mat = Matrix::setmat(num);
    std::vector< std::vector<double> > ident;
    std::vector<double> tempvec, origvec, identvec, origdent, subvector;
    if (!(mat.size()==mat[0].size()))
    {
        cerr<<"Cannot invert matrix."<<endl;
        return ident;
    }
    else if(mat.size() <= 1)
    {
        return mat;
    }
    else if (Matrix::det(mat)==0)
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

std::vector< std::vector<double> > Matrix::invert(std::vector< std::vector<double> > mat)
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
    else if(mat.size() <= 1)
    {
        return mat;
    }
    else if (Matrix::det(mat)==0)
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

double Matrix::det(std::vector< std::vector<double> > mat)
{
    double tempdet, findet, posval, total=0;
    std::vector< std::vector<double> > tempmat;
    if (mat.size() <= 0 || mat[0].size() <= 0 || !(mat.size()==mat[0].size()) || mat.size() == 0)
    {
        cerr<<"Cannot find determinant."<<endl;
        return 0;
    }else if(mat.size() == 1){
        return mat[0][0];
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
            findet = posval*Matrix::det(tempmat);
            if ((i%2==1))
            {
                findet *= -1;
            }
            total+= findet;
        }
    }
    return total;
}

void Matrix::solve(void)
{
    string str_num_vars, str_temp, yn;
    int num_vars;
    double temp;
    char c;
    std::vector< std::vector<double> > vars, constants, solution;
    std::vector<double> tempvector, constantvec;
    cout << "How many variables would you like to solve for?\n";
    cin >> str_num_vars;
    num_vars = (int) atoi(str_num_vars.c_str());
    if(num_vars > 0){
        cout << "Enter the coefficients of the variables in standard form\n";
        for (int i=0; i<num_vars; i++)
        {
            cout << "Equation " << i+1 << ":\n";
            tempvector.clear();
            for (int k=0; k<num_vars; k++)
            {
                c = (char) 'A'+k;
                cout << c << i+1 << "= ";
                cin>>str_temp;
                if(str_temp == "exit"){
                    return;
                }
                temp = (double) stod(str_temp.c_str());
                tempvector.push_back(temp);
            }
            cout << "Constant" << "= ";
            cin>>str_temp;
            if(str_temp == "exit"){
                return;
            }
            temp = (double) stod(str_temp.c_str());
            constantvec.clear();
            constantvec.push_back(temp);
            constants.push_back(constantvec);
            vars.push_back(tempvector);
        }
        if(det(vars) != 0){
            cout<<"Would you like to round to eliminate possible floating point error (yes/no)?"<<endl;
            cin>>yn;
            if (yn == "yes")
            {
                solution = mult(invert(vars), constants);
                printcoeff(round(solution));
            }
            else if (yn == "no")
            {
                solution = mult(invert(vars), constants);
                printcoeff(solution);
            }else if (yn == "exit"){
                return;
            }
            else
            {
                cerr<<"Invalid answer; defaulting to yes."<<endl;
                solution = mult(invert(vars), constants);
                printcoeff(solution);
            }
        }else{
            cout << "Equations are parallel\n";
        }
    }
}
