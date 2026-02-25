#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real - imag*c.imag,
						 real*c.imag + imag*c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double denom = c.real*c.real + c.imag*c.imag;
	return ComplexNumber ((real*c.real + imag*c.imag)/denom,
						  (imag*c.real - real*c.imag)/denom);;
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return (real == c.real && imag == c.imag);
}


ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c) {
    return ComplexNumber(s*c.real, s*c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c) {
    double denom = c.real*c.real + c.imag*c.imag;
    return ComplexNumber(
        (d*c.real)/denom,
        (-d*c.imag)/denom
    );
}

bool operator==(double d, const ComplexNumber &c) {
    return (c.real == d && c.imag == 0);
}

double ComplexNumber::abs(){
	double z = sqrt(real*real + imag*imag);
	return z;
}

double ComplexNumber::angle(){
	double theta = atan2(imag,real)*180.0 / M_PI;
	return theta;
}

ostream& operator<<(ostream &cout ,const ComplexNumber &c){
	if(c.real == 0 && c.imag == 0){
		cout << 0;
	}else if(c.real == 0){
		cout<<c.imag<<"i";
	}else if(c.imag == 0){
		cout<<c.real;
	}else {
		cout<<c.real;
		if(c.imag > 0){
			cout<<"+"<<c.imag<<"i";
		}else{
			cout<<c.imag<<"i";
		}
	}

	return cout;
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





