#include <iostream>
#include <Complex/Complex.h>
#include <sstream>
#include <string>
using namespace std;


int main() 
{
	setlocale(LC_ALL, "rus");
	/*std::cout << "Com + Com = " << Complex(1.328 , 7.987 ) << " + " << Complex(2, 3) << " = " << Complex(1.328, 7.987) + Complex(2, 3) << '\n';
	std::cout << "Com += Com -> " << (Complex(1.328, 7.987) += Complex(2, 3)) << '\n' << '\n';
	std::cout << "Com + int = " << Complex(1, 5.456) << " + " << 2 << " = " << Complex(1, 5.456) + 2 << '\n';
	std::cout << "Com += int -> " << (Complex(1, 5.456) += 2)<< '\n' << '\n';

	std::cout << "Com - Com = " << Complex(-1.7787 , 2) << " - " << Complex(-1.7787, 4) << " = " << Complex(-1.7787, 2) - Complex(-1.7787, 4) << '\n';
	std::cout << "Com -= Com -> " << (Complex(-1.7787, 2) -= Complex(-1.7787, 4)) << '\n' << '\n';
	std::cout << "Com - int = " << Complex(2, 3) << " - " << 4 << " = " << Complex(2,3) - 4 << '\n';
	std::cout << "Com -= int -> " << (Complex(2,3) -= 4) << '\n' << '\n';

	std::cout << "Com * Com = " << Complex(5) << " * " << Complex(2) << " = " << Complex(5) * Complex(2) << '\n';
	std::cout << "Com *= Com -> " << (Complex(5) *= Complex(2)) << '\n' << '\n';
	std::cout << "Com * int = " << Complex(-1/5, 3) << " * " << 5 << " = " << Complex(-1/5, 3) * 5 << '\n';
	std::cout << "Com *= int -> " << (Complex(-1 / 5, 3) *= 5) << '\n' << '\n';

	std::cout << "Com / Com = " << Complex(1,1) << " / " << Complex(1,1) << " = " << Complex(1,1) / Complex(1,1) << '\n';
	std::cout << "Com /= Com -> " << (Complex(1,1) /= Complex(1,1)) << '\n' << '\n';
	std::cout << "Com / int = " << Complex(5,0) << " / " << 4 << " = " << Complex(5, 0) / 4 << '\n';
	std::cout << "Com /= int -> " << (Complex(5, 0) /=4) << '\n' << '\n';

	std::cout << "Com == Com ? -> " << Complex(1.45678 , 1.45678)<<" == ? "<< Complex(1.45678, 1.45678)<<" : " << (Complex(1.45678, 1.45678) == Complex(1.45678, 1.45678)) << '\n' << '\n';
	std::cout << "Com != Com ? -> " << Complex(1.45678, 1.45678) << " != ? " << Complex(1.45678, 1.45678) << " : " << (Complex(1.45678, 1.45678) != Complex(1.45678, 1.45678)) << '\n' << '\n';

	std::cout << "Com < Com ? -> " << Complex() << " == ? " << Complex(1.45678, 1.45678) << " : " << (Complex()< Complex(1.45678, 1.45678)) << '\n' << '\n';
	std::cout << "Com >= Com ? -> " << Complex() << " >= ? " << Complex(1.45678, 1.45678) << " : " << (Complex() >= Complex(1.45678, 1.45678)) << '\n' << '\n';
	std::cout << "Com > Com ? -> " << Complex(1,1) << " > ? " << Complex(0.45678, 1.45678) << " : " << (Complex(1,1) > Complex(0.45678, 1.45678)) << '\n' << '\n';
	std::cout << "Com <= Com ? -> " << Complex(1, 1) << " <= ? " << Complex(0.45678, 1.45678) << " : " << (Complex(1, 1) <= Complex(0.45678, 1.45678)) << '\n' << '\n';

	std::cout << (-(Complex(2, 2)));*/
	//string path = "MyFile.txt";
	//ofstream fout;
	//fout.open(path, ofstream::app);
	//if (!fout.is_open())
	//{
	//	cout << "1";
	//}
	//else
	//{
	//	cout << "2";
	//	fout.write((char*)&c, sizeof(Complex));
	//}
	//fout.close();
	//ifstream fin;
	//fin.open(path);
	//if (!fin.is_open())
	//{
	//	cout << "1";
	//}
	//else
	//{
	//	cout << "2";
	//	Complex d;
	//	while (fin.read((char*)&d, sizeof(Complex)))
	//	{
	//		cout << d;
	//	}
	//}
	//fin.close();

	string s = "{1,1.23} {1,2} {1.5442,7.424} {-0.453,0.987} {1;llfa}";
	istringstream istrm(s);
	Complex z;
	for (int i = 0; i < 5; i++)
	{
		istrm >> z;
		if (istrm.good())
		{
			cout << "Success";
			cout << z << endl;
		}
		else
		{
			cout << "Test "<<i+1 << " Error";
		}
	}
}
