#include <bits/stdc++.h>
using namespace std;

class Fraction{
    int numerator;
    int denominator;

    public:

    Fraction(){};

    Fraction(int n,int d){
        if(d==0){
            cout << "Fraction is not set.Provide data again" << endl;
        }
        else{
            if(n<0 and d<0){
                n=-n;
                d=-d;
            }
            int gcd=__gcd(n,d);
            numerator=n/gcd;
            denominator=d/gcd;
        }
    }
    

    void set(int n,int d){
        if(d==0){
            cout << "Fraction is not set.Provide data again" << endl;
        }
        else{
            if(n<0 and d<0){
                n=-n;
                d=-d;
            }
            int gcd=__gcd(n,d);
            numerator=n/gcd;
            denominator=d/gcd;
        }
    }
    void setNum(int n){
        numerator=n;
    }
    void setDen(int d){
        denominator=d;
    }
    int getNum(){
        return numerator;
    }
    int getDen(){
        return denominator;
    }

    Fraction &operator=(const Fraction &f){
        
        int n=f.numerator;
        int d=f.denominator;
        if(d==0){
            cout << "Fraction is not set.Provide data again" << endl;
        }
        else{
            if(n<0 and d<0){
                n=-n;
                d=-d;
            }
            int gcd=__gcd(n,d);
            n=n/gcd;
            d=d/gcd;
            numerator=n;
            denominator=d;
            
            
            
        }
        return* this;
    }

    //adding two fraction objects
    Fraction operator+(Fraction ob){
        Fraction temp;
        int gcd=__gcd(ob.denominator,denominator);
        int lcm=(ob.denominator*denominator)/gcd;
        int n=(lcm/ob.denominator)*ob.numerator+(lcm/denominator)*numerator;
        int d=lcm;
        temp.numerator=n;
        temp.denominator=d;
        temp=temp;
        
        return temp;
        
    }

    //making Fraction obj from floating point number
    Fraction makeFraction(float num){
        Fraction temp;
        int d=1;
        while(num!=(int)num){
              d*=10;
              num*=10;
        }
        temp.numerator=(int)num;
        temp.denominator=d;
        return temp;
    }

    // Fraction obj+float
    Fraction operator+(float val){
        
        Fraction temp=makeFraction(val);
       
        Fraction ob=temp+(*this);
        ob=ob;
        return ob;
        
    }

    // float+Fraction obj
    friend Fraction operator+(float num,Fraction obj);

    // subtraction of two fraction obj
    Fraction operator-(Fraction ob){
         Fraction temp;
         int gcd=__gcd(ob.denominator,denominator);
        int lcm=(ob.denominator*denominator)/gcd;
        int n=(lcm/denominator)*numerator-(lcm/ob.denominator)*ob.numerator;
        int d=lcm;
        temp.numerator=n;
        temp.denominator=d;
        temp=temp;
        return temp;
    }

    // subtraction Fraction-float
    Fraction operator-(float val){
        
        Fraction temp=makeFraction(val);
        temp=temp;
        Fraction ob=(*this)-temp;
        ob=ob;
        return ob;
        
    }

    //subtraction float-Fraction
    friend Fraction operator-(float num,Fraction obj);

    //Multiplication fraction*fraction
    Fraction operator*(Fraction ob){
        Fraction temp;
        temp.numerator=numerator*ob.numerator;
        temp.denominator=denominator*ob.denominator;
        temp=temp;
        return temp;
    }

    //Multiplication fraction*float;
    Fraction operator*(float num){
        Fraction temp=makeFraction(num);
        Fraction ob=(*this)*temp;
        ob=ob;
        return ob;
    }

    //Multiplication float*fraction
    friend Fraction operator*(float num,Fraction obj);

    //Division fraction/fraction
    Fraction operator/(Fraction obj){
        Fraction temp;
        temp.numerator=numerator*obj.denominator;
        temp.denominator=denominator*obj.numerator;
        temp=temp;
        return temp;
    }

    //Division fraction/float
    Fraction operator/(float num){
        Fraction temp=makeFraction(num);
        Fraction ob=(*this)/temp;
        ob=ob;
        return ob;
    }

    //Division float/fraction
    friend Fraction operator/(float num,Fraction ob);

    // fraction += fraction
    Fraction &operator+=(Fraction ob){
        int gcd=__gcd(ob.denominator,denominator);
        int lcm=(ob.denominator*denominator)/gcd;
        numerator=(lcm/ob.denominator)*ob.numerator+(lcm/denominator)*numerator;
        denominator=lcm;
        *this=*this;
        return *this;
    }

    //fraction -= fraction
    Fraction &operator-=(Fraction ob){
        int gcd=__gcd(ob.denominator,denominator);
        int lcm=(ob.denominator*denominator)/gcd;
        numerator=(lcm/denominator)*numerator-(lcm/ob.denominator)*ob.numerator;
        denominator=lcm;
        *this=*this;
        return *this;
    }
    
    // fraction *= fraction
    Fraction operator*=(Fraction ob){
        numerator*=ob.numerator;
        denominator*=ob.denominator;
        *this=*this;
        return *this;
    }

    // fraction /=fraction
    Fraction operator/=(Fraction ob){
        numerator*=ob.denominator;
        denominator*=ob.numerator;
        *this=*this;
        return *this;
    }
   
    friend ostream& operator<<(ostream& out,Fraction obj);
};

ostream& operator<<(ostream& out,Fraction obj){
     out << obj.numerator << "/" << obj.denominator;
     return out;
}

Fraction operator+(float num,Fraction obj){
    Fraction temp;
    Fraction ob=temp.makeFraction(num)+obj;
    ob=ob;
    return ob;
}

Fraction operator-(float num,Fraction obj){
    Fraction temp;
    Fraction ob=temp.makeFraction(num)-obj;
    ob=ob;
    return ob;
}
Fraction operator*(float num,Fraction obj){
    Fraction temp;
    Fraction ob=temp.makeFraction(num)*obj;
    ob=ob;
    return ob;
}
Fraction operator/(float num,Fraction obj){
    Fraction temp;
    Fraction ob=temp.makeFraction(num)/obj;
    ob=ob;
    return ob;
}


//SECOND CLASS : FractionVector

class FractionVector{
    public:
     Fraction *vector;
     int maxSize;
     int size;
 
     FractionVector(){
        vector=new Fraction[1];
        maxSize=1;
        size=0;
     }
     
     FractionVector(int maxSize){
          vector=new Fraction[maxSize];
          this->maxSize=maxSize;
          size=0;
     }
     FractionVector(const FractionVector &fv){
        
         vector=new Fraction[fv.maxSize];
         maxSize=fv.maxSize;
         size=fv.size;
         for(int i=0;i<size;i++){
            vector[i]=fv.vector[i];
         }
     }
     FractionVector& operator=(const FractionVector &fv){
         delete[] vector;
         vector=new Fraction[fv.maxSize];
         maxSize=fv.maxSize;
         size=fv.size;
         for(int i=0;i<size;i++){
            vector[i]=fv.vector[i];
         }
         return *this;
     }
     

     Fraction& operator[](int index){
        
        if(index>=size){
            
            size++;
        }
        return vector[index];
     }

     // fractionVector+fractionVector
     FractionVector operator+(FractionVector &fv){
        if(fv.size!=size){
            cout << "vector addition is not possible" << endl;
            exit(0);
        }
        FractionVector temp(fv);
        
        for(int i=0;i<size;i++){
            Fraction ob=this->vector[i]+fv.vector[i];
            temp.vector[i]=ob;

         }
         return temp;
        
       
     }
     //fractionVector-fractionVector
     FractionVector operator-(FractionVector &fv){
        if(fv.size!=size){
            cout << "vector addition is not possible" << endl;
            exit(0);
        }
        FractionVector temp(fv);
        
        for(int i=0;i<size;i++){
            Fraction ob=this->vector[i]-fv.vector[i];
            temp.vector[i]=ob;

         }
         return temp;
        
       
     }

     // FractionVector * fraction
     FractionVector &operator*(Fraction f){
         for(int i=0;i<size;i++){
            Fraction ob=vector[i]*f;
            vector[i]=ob;
         }
         return *this;
     }

     // fraction* FractionVector
     friend FractionVector &operator*(Fraction f,FractionVector &fv);

     //FractionVector/fraction
     FractionVector& operator/(Fraction f){
        for(int i=0;i<size;i++){
            vector[i]=vector[i]/f;
        }
        return *this;
     }
     // fraction/FractionVector
     friend FractionVector &operator/(Fraction f,FractionVector &fv);
     
     Fraction operator*(FractionVector &fv){
            if(fv.size!=size){
                cout << "Computing vector dot product is not possible" << endl;
                exit(0);
            }
            Fraction temp(1,1);
            for(int i=0;i<size;i++){
                Fraction ob=vector[i]*fv.vector[i];
                temp+=ob;
            }
            Fraction ob(1,1);
            temp=temp-ob;
            return temp;

     }

     Fraction value(){
       Fraction temp=vector[0]*vector[0];
       for(int i=1;i<size;i++){
            temp+=(vector[i]*vector[i]);
       }
       temp.setNum(sqrt(temp.getNum()));
       temp.setDen(sqrt(temp.getDen()));
       temp=temp;
       return temp;
     }
     
     
     friend ostream& operator<<(ostream& out,FractionVector &fv);


     ~FractionVector(){
        delete[] vector;
     }
     
};

ostream& operator<<(ostream& out,FractionVector &fv){
      for(int i=0;i<fv.size;i++){
            
            cout << fv.vector[i];
            cout << "  ";
         }
         return out;
}
FractionVector &operator*(Fraction f,FractionVector &fv){
        for(int i=0;i<fv.size;i++){
            fv.vector[i]=fv.vector[i]*f; 
        }
        return fv;
}
FractionVector &operator/(Fraction f,FractionVector &fv){
        for(int i=0;i<fv.size;i++){
            fv.vector[i]=f/fv.vector[i]; 
        }
        return fv;
}

// CLASS 3 : FRACTION MATRIX
class FractionMatrix{
    public:
    FractionVector *rows;
    FractionVector *columns;
    int row;
    int col;
    
    FractionMatrix(){};

    FractionMatrix(int mr,int mc){
        rows=new FractionVector[mr];
        row=mr;
        
        columns=new FractionVector[mc];
        col=mc;
        
    }
    //copy constructor
    FractionMatrix(const FractionMatrix &fm){
        
        rows=new FractionVector[fm.row];
        row=fm.row;
        
        for(int i=0;i<row;i++){
            rows[i]=fm.rows[i];
        }
        columns=new FractionVector[fm.col];
        col=fm.col;
        
        for(int i=0;i<col;i++){
            columns[i]=fm.columns[i];
        }

    }
    //copy assignment operator
    FractionMatrix &operator=(const FractionMatrix &mat){
        
        rows=new FractionVector[mat.row];
        columns=new FractionVector[mat.col];
        row=mat.row;
        col=mat.col;
        for(int i=0;i<row;i++){
            rows[i]=mat.rows[i];
        }
        for(int i=0;i<col;i++){
            columns[i]=mat.columns[i];
        }
        return *this;
    }

    // [] overloading
    FractionVector& operator[](int index){
        if(index>=row){
            cout << "Invalid access" << endl;
            exit(0);
        }
        return rows[index];
    }

    FractionVector getColumn(int index){
        if(index >= col ){
            cout << "Invalid access" << endl;
            exit(0);
        }
        return columns[index];
    }

    // matrix addition
    FractionMatrix operator+(FractionMatrix &mat){
        if(row==mat.row and col==mat.col){
            FractionMatrix temp(row,col);
            
            for(int i=0;i<row;i++){
                temp.rows[i]=rows[i]+mat.rows[i];
            }
            for(int i=0;i<col;i++){
                 temp.columns[i]=columns[i]+mat.columns[i];
            }

            return temp;
        }
        else{
            cout << "Matrix addition is not possible" << endl;
            exit(0);
        }
    }
    FractionMatrix operator-(FractionMatrix &mat){
        if(row==mat.row and col==mat.col){
            FractionMatrix temp(row,col);
            
            
            for(int i=0;i<row;i++){
                temp.rows[i]=rows[i]-mat.rows[i];
            }
            for(int i=0;i<col;i++){
                 temp.columns[i]=columns[i]-mat.columns[i];
            }

            return temp;
            
        }
        else{
            cout << "Matrix addition is not possible" << endl;
            exit(0);
        }
    }

    //FractionMatrix*fraction
    FractionMatrix &operator*(Fraction f){
        for(int i=0;i<row;i++){
            FractionVector ob1=rows[i]*f;
            rows[i]=ob1;
        }
        for(int i=0;i<col;i++){
            FractionVector ob2=columns[i]*f;
            columns[i]=ob2;
        }
        return *this;
    }
    //fraction*Fraction matrix
    friend FractionMatrix &operator*(Fraction f,FractionMatrix& mat);


    // FractionMatirx/frac
    
    FractionMatrix &operator/(Fraction f){
        for(int i=0;i<row;i++){
            FractionVector ob1=rows[i]/f;
            rows[i]=ob1;
        }
        for(int i=0;i<col;i++){
            FractionVector ob2=columns[i]/f;
            columns[i]=ob2;
        }
        return *this;
    }

    // FractionMatrix& operator*(FractionMatrix &mat){
    //     if(col==mat.row){
             
    //     }
    //     else{
    //         cout << "Multiplication is not possible;" << endl;
    //     }
    // }

    // transpose of a matrix
    FractionMatrix transpose(FractionMatrix &matrix){
         FractionMatrix temp(matrix.col,matrix.row);
         for(int i=0;i<matrix.row;i++){
               temp.columns[i]=matrix.rows[i];
         }
         for(int i=0;i<matrix.col;i++){
            temp.rows[i]=matrix.columns[i];
         }
         cout << temp;
         return temp;
         
    }
    //printing matrix
    
    friend ostream& operator<<(ostream& out,FractionMatrix& matrix);

    // clearing the pointer
    ~FractionMatrix(){
        delete[] rows;
        delete[] columns;
    }
    
};

ostream& operator<<(ostream& out,FractionMatrix& matrix){
    for(int i=0;i<matrix.col;i++){
            for(int j=0;j<matrix.row;j++){
                cout << "[";
                cout << matrix.columns[i];
                cout << "],[";
                cout << matrix.rows[j];
                cout << "]";
                cout << "            ";
            }
            cout << endl;
        }
        return out;
}

FractionMatrix &operator*(Fraction f,FractionMatrix& mat){
    for(int i=0;i<mat.row;i++){
            FractionVector ob1=mat.rows[i]*f;
            mat.rows[i]=ob1;
        }
        for(int i=0;i<mat.col;i++){
            FractionVector ob2=mat.columns[i]*f;
            mat.columns[i]=ob2;
        }
    return mat;
}


int main(){
    Fraction obj(2,3),obj1(4,2);
    Fraction out;
    Fraction ob=obj+obj1;
    cout << ob << endl;
    
    Fraction ob1=ob+1.25;
    cout << ob1 << endl;
    Fraction ob2=1.25+ob1;
    cout << ob2 << endl;
    Fraction ob3=ob1-ob2;
    cout << ob3 << endl;
    Fraction ob4=ob3-1.25;
    cout << ob4 << endl;
    Fraction ob5=1.25-ob4;
    cout << ob5 << endl;
    Fraction ob6=ob5*ob4;
    cout << ob6<< endl;
    Fraction ob7=ob6*(-2.5);
    cout << ob7 << endl;
    Fraction ob8=1.5*ob7;
    cout << ob8 << endl;
    Fraction ob9=ob8/ob7;
    cout << ob9 << endl;
    Fraction ob10=ob9/2.5;
    cout << "ob10: ";
    cout << ob10 << endl;
    Fraction ob11=1.5/ob10;
    cout << "ob11: " ;
    cout << ob11 << endl;
    
    ob11+=ob10;
    cout << "updated (+=)ob11:";
    cout << ob11 << endl;
    ob11-=ob10;
    cout << "updated (-=)ob11: ";
    cout << ob11 << endl;
    ob11*=ob10;
    cout << "updated (*=)ob11:";
    cout << ob11 << endl;
    ob11/=ob10;
    cout << "updated (/=)ob11:";
    cout << ob11 << endl;

    cout << "class 2:------------------" << endl;
    FractionVector fv1(3);
    fv1[0]=ob1;
    fv1[1]=ob2;
    fv1[2]=ob3;
    
    
    cout << "Fraction vector 1: ";
    cout << fv1 << endl;
    
    FractionVector fv2(3);
    fv2[0]=ob4;
    fv2[1]=ob5;
    fv2[2]=ob6;

    cout << "Fraction vector 2: ";
    cout << fv2;
    cout << endl;

    FractionVector fv3 = fv2+fv1;
    cout << "summation of vector fv4=fv2+fv1: " ;
    cout << fv3 << endl;

    FractionVector fv4=fv1-fv2;
    cout << "subtraction of vector fv4=fv1-fv2: ";
    cout << fv4 << endl;

    fv4*ob;
    cout << "updated fv4*ob: ";
    cout << fv4 << endl;

    ob*fv4;
    cout << "updated ob*fv4: ";
    cout << fv4 << endl;

    fv4/ob;
    cout << "updated fv4/ob: ";
    cout << fv4 << endl;

    ob/fv4;
    cout << "updated ob/fv4: ";
    cout << fv4 << endl;

    Fraction ob12=fv1*fv2;
    cout << "Dot product--> Fraction ob12 = fv1.fv2: ";
    cout << ob12 << endl;

    Fraction ob13=fv4.value();
    cout << "Magnitude of fv4: ";
    cout << ob13 << endl;

    cout << "class 3 :->.........................." << endl;
    
    Fraction f1(1,2),f2(2,3),f3(4,2),f4(2,3),f5(3,4),f6(2,5);
    FractionVector fv5(3);
    fv5[0]=f1;
    fv5[1]=f2;
    fv5[2]=f3;
    FractionVector fv6(3);
    fv6[0]=f4;
    fv6[1]=f5;
    fv6[2]=f6;
    
    FractionMatrix matrix1(3,3);
    
    FractionMatrix matout;
    matrix1.rows[0]=fv1;
    
    matrix1.rows[1]=fv2;
    matrix1.rows[2]=fv3;

    matrix1.columns[0]=fv4;
    matrix1.columns[1]=fv5;
    matrix1.columns[2]=fv6;
    cout << "printing the stored matrix: " << endl;
    cout << matrix1;

    cout << "accessing the i'th row->j'th element: ";
    cout << matrix1[0][1];
    cout << endl;

    cout << "get column Fraction vector: ";
    FractionVector fvr=matrix1.getColumn(1);
    cout << fvr << endl;

    FractionMatrix matrix2(matrix1);
    FractionMatrix matrix3=matrix1+matrix2;
    cout << "Addition of matrix1+matrix2: "<< endl;
    cout << matrix3;

    FractionMatrix matrix0=matrix1-matrix2;
    cout << "Subtraction of matrix1-matrix2: " << endl;
    cout << matrix0;
    
    Fraction newFrac(1,2);
    cout << "Scalar multiplication -- matrix3*ob, matrix4= : " << endl;
    FractionMatrix matrix4(matrix1);
    
    matrix4*newFrac;

    

    cout << matrix4;

    Fraction frac(2,1);
    cout << "Scalar multiplication--frac*matrix4, matrix4= : " << endl << endl;
     FractionMatrix matrix5=frac*matrix4;
    cout << matrix5;

    cout << "Scalar Division -- matrix5/frac, matrix5= :" << endl << endl;
    matrix5/frac;
    cout << matrix5;

    cout << "Transpose of the matrix of matrix5: "<< endl;
    FractionMatrix matrix6;
    matrix6.transpose(matrix5);
    cout << matrix6;
    
}