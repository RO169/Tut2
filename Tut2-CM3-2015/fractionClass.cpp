#include<iostream>
using namespace std;


class Fraction                                       //fraction class
{
private:
	//fraction	
	int numerator,
		denominator;

public:
	//default constructor
	Fraction()
	{
		numerator = 1;
		denominator = 1;
	}
	//remove possibility of division by 0
	Fraction(int n, int d)
	{
		numerator = n;

		if (d == 0)
		{
			cerr << "Division by 0 is not allowed\n\n" << endl;
			system("Pause");
			exit(0);
		}
		else
		{
			denominator = d;
		}
	}
	//functions
	int add(Fraction f1, Fraction f2)
	{
		int num, den, ans;
		num = (f1.numerator*f2.denominator) + (f2.numerator*f1.denominator);
		den = f1.denominator*f2.denominator;
		ans = print(num, den);
		return ans;
	}

	int subtract(Fraction f1, Fraction f2)
	{                                              //subtraction is addition of the negative of the 2nd fraction
		int num, den, ans;
		num = (f1.numerator*f2.denominator) - (f2.numerator*f1.denominator);
		den = f1.denominator*f2.denominator;
		ans = print(num, den);
		return ans;
	}

	int multiply(Fraction f1, Fraction f2)
	{
		int num, den, ans;
		num = f1.numerator*f2.numerator;
		den = f1.denominator*f2.denominator;
		ans = print(num, den);
		return ans;
	}

	int divide(Fraction f1, Fraction f2)
	{                                             //division is the 1st fraction multiplied by the inverse of the 2nd fraction
		int num, den, ans;
		num = f1.numerator*f2.denominator;
		den = f1.denominator*f2.numerator;
		ans = print(num, den);
		return ans;
	}
	//simplification function	
	int print(int n, int d)
	{
		int in = 0;

		if (n > d)                               //check if possible to have a mixed number
		{
			in = n / d;
			n %= d;
		}

		for (int i = 1; i <= n; i++)            //simplify fraction by searching for GCD
		{
			if (n%i == 0 && d%i == 0)
			{
				n /= i;
				d /= i;
			}
		}

		if (in > 0)                             //check if we are displaying a mixed number or a fraction
		{
			cout << "\n\nThe result is: " << in;
			if (n > 0)                         //check if we can display a whole number only, eg. 1 instead 1 of 1 and 0/2
			{
				cout << " and " << n << "/" << d << "\n\n\n\n";
			}
		}
		else
		{
			cout << "\n\nThe result is: " << n << "/" << d << "\n\n\n\n";
		}

		return 0;
	}

};


int main()
{
	int n1, d1, n2, d2, op;

	cout << "Please enter the first fraction: Numerator <Enter> Denominator <Enter>" << endl;
	cin >> n1 >> d1;
	cout << "\n\nPlease enter the second fraction: Numerator <Enter> Denominator <Enter>" << endl;
	cin >> n2 >> d2;

	Fraction f1(n1, d1);
	Fraction f2(n2, d2);
	Fraction answer;

	cout << "\n\nPlease enter the number of the operation you would like to perform on these fractions:\n" << endl;
	cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division" << endl;
	cin >> op;

	switch (op)
	{
	case 1:
		answer.add(f1, f2);
		break;
	case 2:
		answer.subtract(f1, f2);
		break;
	case 3:
		answer.multiply(f1, f2);
		break;
	case 4:
		answer.divide(f1, f2);
		break;
	default:
		cerr << "You entered an invalid operation\n\n";
		system("pause");
		exit(0);
		break;
	}


	system("Pause");
	return 0;
}

