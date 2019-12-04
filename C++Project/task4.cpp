#include"task4.h"

Quadratic::Quadratic(string s) : Equation(s){};

void Quadratic::setCoefficients()
{
    string s1 = this->getEquation();

	s1 = s1.substr(1, s1.size() - 4);

	int p = 0;

	if( s1.find("x^2") != string::npos )
	{
		p = s1.find("x^2");

		if( p == 0)
		{
			a = 1;
			s1 = s1.substr(3, s1.size() - 3);
		}
		else if( p == 1 && ((s1.at(0) == '+') || (s1.at(0) == '-')))
		{
			char c1 = s1.at(0);

			if(c1 == '+')
			{
				a = 1;
				s1 = s1.substr(4, s1.size() - 4);
			}
			if(c1 == '-')
			{
				a = -1;
				s1 = s1.substr(4, s1.size() - 4);
			}
		}
		else
		{
			this->quadratic = s1.substr(0, p);
			char c1 = this->quadratic.at(0);

			if(c1 == '-')
			{
				if( s1.substr(1, 3) == "x^2")
				{
					a = -1;
					s1 = s1.substr(p + 3, s1.size() - p - 3);
				}
				else
				{
					a = stof(this->quadratic.substr(1, p - 1)) * (-1);
					s1 = s1.substr(p + 3, s1.size() - p - 3);
				}
			}
			else if( c1 == '+')
			{
				a = stof(this->quadratic.substr(1, p - 1));
				s1 = s1.substr(p + 3, s1.size() - p - 3);
			}
			else
			{
				a = stof(this->quadratic);
				s1 = s1.substr(p + 3, s1.size() - p - 3);
			}
		}
		
	}
	else
	{
		a = 0;
	}

	
	if(s1.find("x") != string::npos)
	{
		p = s1.find("x");

		if( p == 0 )
		{
			b = 1;
			s1 = s1.substr(1, s1.size() - 1);
		}
		else if( p == 1 && ((s1.at(0) == '+') || (s1.at(0) == '-')))
		{
			char c1 = s1.at(0);

			if(c1 == '+')
			{
				b = 1;
				s1 = s1.substr(2, s1.size() - 2);
			}
			if(c1 == '-')
			{
				b = -1;
				s1 = s1.substr(2, s1.size() - 2);
			}
		}
		else
		{
			this->linear = s1.substr(0, p);
			char c1 = s1.at(0);

			if(c1 == '-')
			{
				if( s1.at(1) == 'x')
				{
					b = -1;
					s1 = s1.substr(p + 1, s1.size() - p - 1);
				}
				else
				{
					b = stof(this->linear.substr(1, p - 1)) * (-1);
					s1 = s1.substr(p + 1, s1.size() - p - 1);
				}
			}
			else if( c1 == '+')
			{
				b = stof(this->linear.substr(1, p - 1));
				s1 = s1.substr(p + 1, s1.size() - p - 1);
			}
			else
			{
				b = stof(this->linear);
				s1 = s1.substr(p + 1, s1.size() - p - 1);
			}
		}
	}
	else
	{
		b = 0;
	}

	c = stof(s1);
}


void Quadratic::solve()
{
	setCoefficients();
	if(a == 0)
	{
		x1 = -c/b;
		
		string a = "x=" + to_string(x1).substr(0, to_string(x1).size() - 2);
		//cout << "x=" << x1 << endl;
	}
	else
	{
		float D = (pow(this->b, 2) - 4*(this->a)*(this->c));
		//cout << "D = " << D << endl;
		if(D<0)
		{
			cout << "No solution" << endl;
		}
		else
		{
			x1 = (-this->b + pow(D, 0.5))/(2*this->a)*(1.0);

			x2 = (-this->b - pow(D, 0.5))/(2*this->a)*(1.0);
		}
	}
}
void Quadratic::print(){
    cout<<*this;
}

ostream& operator<<(ostream& os, const Quadratic& eq)
{
    os<< "x=" << fixed<<setprecision(4)<<eq.x1 << ";x=" <<fixed<<setprecision(4)<< eq.x2 << endl;
    return os;
}	