// complex.cpp
// Multiplying complex numbers
#include <iostream>	// contains the definition of cout, endl
#include <complex>	// contains the complex class definition

using namespace std; // cout, endl, complex are all part of this namespace

int main()
{
	using complexNum= complex<float>;
     int a,b,c=0;
	char propagation= 'y';
	while( propagation=='y')
	{

		cout<<"Enter  integers a,b and c: "<<endl;
		cin>>a>>b>>c;
		auto x1=complexNum{0, 0};
		auto x2=complexNum{0, 0};

		auto discriminant= ((b*b) -4*a*c);

		auto denomenator= complexNum{(2.0f*a), 0};
		x1=x1/denomenator;
		x2=x2/denomenator;

		if(discriminant==0)
		{
			cout<<"The root is: "<< x1.real()<<"+"<<x1.imag()<<"j" <<endl;
		}
		else
		{
			auto plusSign="+";
			auto plusSign2="+";
			if(x1.imag()<0)
			{
				plusSign="";
			}
			else if (x2.imag()<0)
			{
				plusSign2="";
			}

			if(discriminant<0)
		{
			discriminant = discriminant*-1;
			x1.real(-1*b);
			x1.imag(sqrt(discriminant));
			x2.real(-1*b);
			x2.imag(-1*sqrt(discriminant));


		}
		else
		{
			x1.real(-1*b+sqrt(discriminant));
		    x2.real(-1*b - sqrt(discriminant));

		}

	        cout<<"The roots are: "<< x1.real()<<plusSign<<x1.imag()<<"j" <<" or "<<x2.real()<<plusSign2<<x2.imag()<<"j" <<endl;
		}
	cout<<"Do you wish to do another calculation: Press y to continue or q to quit "<<endl;
	cin>>propagation;


	}


}




