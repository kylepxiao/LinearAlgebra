//Created by Kyle Xiao
#include <iostream>
#include "poly.h"
#include "Matrix.h"

using namespace std;

int main()
{
    poly p;
    Matrix m;
    bool running = true;
    string userans, yn, mat1, mat2, str_factor;
    int num1 = 0, num2 = 0;
    double factor = 0;
    cout<<"I am a Matrix, Vector, Equation, and Interpolation Calculator"<<endl<<endl;
    cout<<"Enter a command to continue (? for help)"<<endl;
    while (running)
    {
        userans = "";
        cin>>userans;
        if (userans == "inter")
        {
            cout<<"\nI will solve for a polynomial of best fit given points and a degree\n"<<endl;
            p.getpoints();
            if(p.degree > 0){
                cout<<"Would you like to round to eliminate possible floating point error (yes/no)?"<<endl;
                cin>>yn;
                if (yn == "yes")
                {
                    cout<<"The Equation of Best Fit is:"<<endl;
                    p.printans(p.round(p.interpolate()));
                }
                else if (yn == "no")
                {
                    cout<<"The Equation of Best Fit is:"<<endl;
                    p.printans(p.interpolate());
                }else if (yn == "exit"){
                    //exit conditions
                }
                else
                {
                    cerr<<"Invalid answer; defaulting to yes."<<endl;
                    cout<<"The coefficients from highest to lowest are:"<<endl;
                    p.printans(p.round(p.interpolate()));
                }
            }
        }
        else if (userans == "solve")
        {
            m.solve();
        }
        else if(userans == "quad")
        {
            p.solveQuad();
        }
        else if (userans == "fill")
        {
            cout << "Which matrix would you like to edit (a, b, c, d, e, or f)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                if (mat1 == "a")
                {
                    m.fillmat(1);
                }
                else if (mat1 == "b")
                {
                    m.fillmat(2);
                }
                else if (mat1 == "c")
                {
                    m.fillmat(3);
                }
                else if (mat1 == "d")
                {
                    m.fillmat(4);
                }
                else if (mat1 == "e")
                {
                    m.fillmat(5);
                }
                else if (mat1 == "f")
                {
                    m.fillmat(6);
                }
                else
                {
                    cerr<<"Invalid matrix."<<endl;
                }
            }
        }

        else if(userans == "print")
        {
            cout << "Which matrix would you like to print (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                if (mat1 == "a")
                {
                m.printmat(1);
                }
                else if (mat1 == "b")
                {
                m.printmat(2);
                }
                else if (mat1 == "c")
                {
                m.printmat(3);
                }
                else if (mat1 == "d")
                {
                m.printmat(4);
                }
                else if (mat1 == "e")
                {
                m.printmat(5);
                }
                else if (mat1 == "f")
                {
                m.printmat(6);
                }
                else if (mat1 == "ans")
                {
                m.printans(m.ans);
                }
                else
                {
                    cerr<<"Invalid matrix."<<endl;
                }
            }
        }
        else if (userans == "mconst")
        {
            cout << "What is the factor you want to multiply by?\n";
            cin>>str_factor;
            if(str_factor != "exit"){
                cout << "What matrix would you like to multiply by(a, b, c, d, e, f, or ans)?\n";
                cin>>mat2;
                if(mat2 != "exit"){
                    //mat1
                    factor = (double) stod(str_factor.c_str());
                    //mat2
                    if (mat2 == "a")
                    {
                        num2 = 1;
                    }
                    else if(mat2 == "b")
                    {
                        num2 = 2;
                    }
                    else if(mat2 == "c")
                    {
                        num2 = 3;
                    }
                    else if(mat2 == "d")
                    {
                        num2 = 4;
                    }
                    else if(mat2 == "e")
                    {
                        num2 = 5;
                    }
                    else if(mat2 == "f")
                    {
                        num2 = 6;
                    }
                    else if(mat2 == "ans")
                    {
                        num2 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in second entry."<<endl;;
                    }
                    //calculation and print loop
                    if (num2!=0)
                    {
                        m.ans = m.mult_const(factor, num2);
                        m.printans(m.ans);
                    }
                }
            }
        }
        else if (userans == "add")
        {
            cout << "First matrix (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                cout << "Second matrix (a, b, c, d, e, f, or ans)?\n";
                cin>>mat2;
                if(mat2 != "exit"){
                    //mat1
                    if (mat1 == "a")
                    {
                        num1 = 1;
                    }
                    else if(mat1 == "b")
                    {
                        num1 = 2;
                    }
                    else if(mat1 == "c")
                    {
                        num1 = 3;
                    }
                    else if(mat1 == "d")
                    {
                        num1 = 4;
                    }
                    else if(mat1 == "e")
                    {
                        num1 = 5;
                    }
                    else if(mat1 == "f")
                    {
                        num1 = 6;
                    }
                    else if(mat1 == "ans")
                    {
                        num1 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in first entry."<<endl;
                    }

                    //mat2
                    if (mat2 == "a")
                    {
                        num2 = 1;
                    }
                    else if(mat2 == "b")
                    {
                        num2 = 2;
                    }
                    else if(mat2 == "c")
                    {
                        num2 = 3;
                    }
                    else if(mat2 == "d")
                    {
                        num2 = 4;
                    }
                    else if(mat2 == "e")
                    {
                        num2 = 5;
                    }
                    else if(mat2 == "f")
                    {
                        num2 = 6;
                    }
                    else if(mat2 == "ans")
                    {
                        num2 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in second entry."<<endl;;
                    }
                    //calculation and print loop
                    if (num1!=0 && num2!=0)
                    {
                        m.ans = m.add(num1, num2);
                        m.printans(m.ans);
                    }
                }
            }
        }
        else if (userans == "sub")
        {
            cout << "First matrix (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                cout << "Second matrix (a, b, c, d, e, f, or ans)?\n";
                cin>>mat2;
                if(mat2 != "exit"){
                    //mat1
                    if (mat1 == "a")
                    {
                        num1 = 1;
                    }
                    else if(mat1 == "b")
                    {
                        num1 = 2;
                    }
                    else if(mat1 == "c")
                    {
                        num1 = 3;
                    }
                    else if(mat1 == "d")
                    {
                        num1 = 4;
                    }
                    else if(mat1 == "e")
                    {
                        num1 = 5;
                    }
                    else if(mat1 == "f")
                    {
                        num1 = 6;
                    }
                    else if(mat1 == "ans")
                    {
                        num1 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in first entry."<<endl;
                    }

                    //mat2
                    if (mat2 == "a")
                    {
                        num2 = 1;
                    }
                    else if(mat2 == "b")
                    {
                        num2 = 2;
                    }
                    else if(mat2 == "c")
                    {
                        num2 = 3;
                    }
                    else if(mat2 == "d")
                    {
                        num2 = 4;
                    }
                    else if(mat2 == "e")
                    {
                        num2 = 5;
                    }
                    else if(mat2 == "f")
                    {
                        num2 = 6;
                    }
                    else if(mat2 == "ans")
                    {
                        num2 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in second entry."<<endl;;
                    }
                    //calculation and print loop
                    if (!(num1==0) && !(num2==0))
                    {
                        m.ans = m.sub(num1, num2);
                        m.printans(m.ans);
                    }
                }
            }
        }
        else if (userans == "mult")
        {
            cout << "First matrix (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                cout << "Second matrix (a, b, c, d, e, f, or ans)?\n";
                cin>>mat2;
                if(mat2 != "exit"){
                    //mat1
                    if (mat1 == "a")
                    {
                        num1 = 1;
                    }
                    else if(mat1 == "b")
                    {
                        num1 = 2;
                    }
                    else if(mat1 == "c")
                    {
                        num1 = 3;
                    }
                    else if(mat1 == "d")
                    {
                        num1 = 4;
                    }
                    else if(mat1 == "e")
                    {
                        num1 = 5;
                    }
                    else if(mat1 == "f")
                    {
                        num1 = 6;
                    }
                    else if(mat1 == "ans")
                    {
                        num1 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in first entry."<<endl;
                    }

                    //mat2
                    if (mat2 == "a")
                    {
                        num2 = 1;
                    }
                    else if(mat2 == "b")
                    {
                        num2 = 2;
                    }
                    else if(mat2 == "c")
                    {
                        num2 = 3;
                    }
                    else if(mat2 == "d")
                    {
                        num2 = 4;
                    }
                    else if(mat2 == "e")
                    {
                        num2 = 5;
                    }
                    else if(mat2 == "f")
                    {
                        num2 = 6;
                    }
                    else if(mat2 == "ans")
                    {
                        num2 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in second entry."<<endl;;
                    }
                    //calculation and print loop
                    if (!(num1==0) && !(num2==0))
                    {
                        m.ans = m.mult(num1, num2);
                        m.printans(m.ans);
                    }
                }
            }
        }

        else if (userans == "trans")
        {
            cout << "Which matrix would you like to transpose (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                if (mat1 == "a")
                {
                    m.ans = m.transposeloop(1);
                    m.printans(m.ans);
                }
                else if(mat1 == "b")
                {
                    m.ans = m.transposeloop(2);
                    m.printans(m.ans);
                }
                else if(mat1 == "c")
                {
                    m.ans = m.transposeloop(3);
                    m.printans(m.ans);
                }
                else if(mat1 == "d")
                {
                    m.ans = m.transposeloop(4);
                    m.printans(m.ans);
                }
                else if(mat1 == "e")
                {
                    m.ans = m.transposeloop(5);
                    m.printans(m.ans);
                }
                else if(mat1 == "f")
                {
                    m.ans = m.transposeloop(6);
                    m.printans(m.ans);
                }
                else if(mat1 == "ans")
                {
                    m.ans = m.transposeloop(7);
                    m.printans(m.ans);
                }
                else
                {
                    cerr<<"Invalid matrix."<<endl;;
                }
            }
        }

        else if (userans == "invert")
        {
            cout << "Which matrix would you like to invert (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                if (mat1 == "a")
                {
                    m.ans = m.invert(1);
                    m.printans(m.ans);
                }
                else if(mat1 == "b")
                {
                    m.ans = m.invert(2);
                    m.printans(m.ans);
                }
                else if(mat1 == "c")
                {
                    m.ans = m.invert(3);
                    m.printans(m.ans);
                }
                else if(mat1 == "d")
                {
                    m.ans = m.invert(4);
                    m.printans(m.ans);
                }
                else if(mat1 == "e")
                {
                    m.ans = m.invert(5);
                    m.printans(m.ans);
                }
                else if(mat1 == "f")
                {
                    m.ans = m.invert(6);
                    m.printans(m.ans);
                }
                else if(mat1 == "ans")
                {
                    m.ans = m.invert(7);
                    m.printans(m.ans);
                }
                else
                {
                    cerr<<"Invalid matrix."<<endl;
                }
            }
        }

        else if (userans == "det")
        {
            cout << "Which matrix would you like to find the determinant of (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                if (mat1 == "a")
                {
                    cout<<(m.det(m.setmat(1)))<<endl;
                }
                else if(mat1 == "b")
                {
                    cout<<(m.det(m.setmat(2)))<<endl;
                }
                else if(mat1 == "c")
                {
                    cout<<(m.det(m.setmat(3)))<<endl;
                }
                else if(mat1 == "d")
                {
                    cout<<(m.det(m.setmat(4)))<<endl;
                }
                else if(mat1 == "e")
                {
                    cout<<(m.det(m.setmat(5)))<<endl;
                }
                else if(mat1 == "f")
                {
                    cout<<(m.det(m.setmat(6)))<<endl;
                }
                else if(mat1 == "ans")
                {
                    cout<<(m.det(m.setmat(7)))<<endl;
                }
                else
                {
                    cerr<<"Invalid matrix."<<endl;;
                }
            }
        }


        else if (userans == "cross")
        {
            cout << "First matrix (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                cout << "Second matrix (a, b, c, d, e, f, or ans)?\n";
                cin>>mat2;
                if(mat2 != "exit"){
                    //mat1
                    if (mat1 == "a")
                    {
                        num1 = 1;
                    }
                    else if(mat1 == "b")
                    {
                        num1 = 2;
                    }
                    else if(mat1 == "c")
                    {
                        num1 = 3;
                    }
                    else if(mat1 == "d")
                    {
                        num1 = 4;
                    }
                    else if(mat1 == "e")
                    {
                        num1 = 5;
                    }
                    else if(mat1 == "f")
                    {
                        num1 = 6;
                    }
                    else if(mat1 == "ans")
                    {
                        num1 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in first entry."<<endl;
                    }

                    //mat2
                    if (mat2 == "a")
                    {
                        num2 = 1;
                    }
                    else if(mat2 == "b")
                    {
                        num2 = 2;
                    }
                    else if(mat2 == "c")
                    {
                        num2 = 3;
                    }
                    else if(mat2 == "d")
                    {
                        num2 = 4;
                    }
                    else if(mat2 == "e")
                    {
                        num2 = 5;
                    }
                    else if(mat2 == "f")
                    {
                        num2 = 6;
                    }
                    else if(mat2 == "ans")
                    {
                        num2 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid matrix in second entry."<<endl;;
                    }
                    //calculation and print loop
                    if (num1!=0 && num2!=0)
                    {
                        m.ans = m.cross(num1, num2);
                        m.printans(m.ans);
                    }
                }
            }
        }

        else if (userans == "dot")
        {
            cout << "First matrix (a, b, c, d, e, f, or ans)?\n";
            cin>>mat1;
            if(mat1 != "exit"){
                cout << "Second matrix (a, b, c, d, e, f, or ans)?\n";
                cin>>mat2;
                if(mat2 != "exit"){
                    //mat1
                    if (mat1 == "a")
                    {
                        num1 = 1;
                    }
                    else if(mat1 == "b")
                    {
                        num1 = 2;
                    }
                    else if(mat1 == "c")
                    {
                        num1 = 3;
                    }
                    else if(mat1 == "d")
                    {
                        num1 = 4;
                    }
                    else if(mat1 == "e")
                    {
                        num1 = 5;
                    }
                    else if(mat1 == "f")
                    {
                        num1 = 6;
                    }
                    else if(mat1 == "ans")
                    {
                        num1 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid vector in first entry."<<endl;
                    }

                    //mat2
                    if (mat2 == "a")
                    {
                        num2 = 1;
                    }
                    else if(mat2 == "b")
                    {
                        num2 = 2;
                    }
                    else if(mat2 == "c")
                    {
                        num2 = 3;
                    }
                    else if(mat2 == "d")
                    {
                        num2 = 4;
                    }
                    else if(mat2 == "e")
                    {
                        num2 = 5;
                    }
                    else if(mat2 == "f")
                    {
                        num2 = 6;
                    }
                    else if(mat2 == "ans")
                    {
                        num2 = 7;
                    }
                    else
                    {
                        cerr<<"Invalid vector in second entry."<<endl;;
                    }
                    //calculation and print loop
                    if (num1!=0 && num2!=0)
                    {
                        cout<<m.dotproduct(num1, num2)<<endl;
                    }
                }
            }
        }
        else if (userans == "ans")
        {
            m.printans(m.ans);
            cout << endl;
        }
        else if (userans == "?")
        {
            cout << "fill - input matrix and store in memory\n"
            <<"print - print a matrix in memory onto the screen\n"
            <<"add - add two matrices together\n"
            <<"sub - subtract one matrix from another\n"
            <<"mconst - multiply a matrix by a constant\n"
            <<"mult - multiply two matrices together\n"
            <<"trans - find the transpose of a matrix\n"
            <<"invert - find the inverse of a matrix\n"
            <<"det - find the determinant of a matrix\n"
            <<"cross - find the cross product of two 3D vectors\n"
            <<"dot - find the dot product of two vectors\n"
            <<"ans - matrix of last answer\n"
            <<"inter - statistical interpolation using method of least squares\n"
            <<"solve - solve a system of linear equations\n"
            <<"quad - solve a quadratic equation\n"
            <<"exit - cancel a command or exit from the program\n";
        }
        else if (userans == "exit")
        {
            running = false;
            return 0;
        }
        else
        {
            cerr<<"Invalid command."<<endl;
        }
        cout<<"Enter a command to continue"<<endl;
    }
}
