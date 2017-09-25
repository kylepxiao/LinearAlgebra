#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#ifndef MATRIX_H
#define MATRIX_H
using namespace std;


class Matrix
{
    public:
        //functions
        Matrix();
        ~Matrix();
        int matconverter(std::vector< std::vector<double> >);
        void fillmat(int);
        void printans(std::vector< std::vector<double> >);
        void printcoeff(std::vector< std::vector<double> >);
        void printmat(int);
        void transpose(int);
        double dotproduct(int, int);
        double det(std::vector< std::vector<double> >);
        double dot(std::vector<double>, std::vector<double>);
        std::vector< std::vector<double> > round(int);
        std::vector< std::vector<double> > round(std::vector< std::vector<double> >);
        std::vector< std::vector<double> > cross(int, int);
        std::vector< std::vector<double> > invert(int);
        std::vector< std::vector<double> > invert(std::vector< std::vector<double> >);
        std::vector< std::vector<double> > transposeloop(int);
        std::vector< std::vector<double> > setmat(int);
        std::vector< std::vector<double> > add(int, int);
        std::vector< std::vector<double> > mult_const(double, int);
        std::vector< std::vector<double> > sub(int, int);
        std::vector< std::vector<double> > mult(int, int);
        std::vector< std::vector<double> > mult(std::vector< std::vector<double> >, std::vector< std::vector<double> >);
        void solve(void);
        //variables
        std::vector< std::vector<double> > A;
        std::vector< std::vector<double> > B;
        std::vector< std::vector<double> > C;
        std::vector< std::vector<double> > D;
        std::vector< std::vector<double> > E;
        std::vector< std::vector<double> > F;
        std::vector< std::vector<double> > ans;
};

#endif // MATRIX_H
