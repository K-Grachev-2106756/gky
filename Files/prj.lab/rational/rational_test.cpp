#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <rational/rational.h>
//#include <iostream>
//#include <sstream>
//#include <string>

TEST_CASE("[rational] - Rational ctor") {
	CHECK((Rational(0, 4) == Rational(0, 1)));
	CHECK((Rational(2, 4) == Rational(1, 2)));
	CHECK((Rational(2, -4) == Rational(-1, 2)));
	CHECK((Rational(-2, 4) == Rational(-1, 2)));
	CHECK((Rational(-2,-4) == Rational(1, 2)));
	CHECK((Rational(5, 5) == Rational(1, 1)));
	CHECK((Rational(2) == Rational(2, 1)));
	CHECK((Rational() == Rational(0, 1)));

}
TEST_CASE("[rational] - Rational denominator==zero") 
{
	CHECK_THROWS(Rational(10,0));
	CHECK_THROWS(Rational(1, 10) / 0);
	CHECK_THROWS(Rational(1, 10) / Rational(0, 10));

}
TEST_CASE("[rational] - bool functions")
{
	CHECK((Rational(1, 4) < Rational(1, 4)) == FALSE);
	CHECK((Rational(1, 4) < Rational(1, 1))==TRUE);
	CHECK((Rational(1, 1) < Rational(1, 4)) == FALSE);

	CHECK((Rational(1, 4) > Rational(1, 4)) == FALSE);
	CHECK((Rational(1, 4) > Rational(1, 1)) == FALSE);
	CHECK((Rational(1, 1) > Rational(1, 4)) == TRUE);

	CHECK((Rational(1, 4) <= Rational(1, 4)) == TRUE);
	CHECK((Rational(1, 4) <= Rational(1, 1)) == TRUE);
	CHECK((Rational(1, 1) <= Rational(1, 4)) == FALSE);

	CHECK((Rational(1, 4) >= Rational(1, 4)) == TRUE);
	CHECK((Rational(1, 4) >= Rational(1, 1)) == FALSE);
	CHECK((Rational(1, 1) >= Rational(1, 4)) == TRUE);

	CHECK((Rational(1, 1) == Rational(1, 4)) == FALSE);
	CHECK((Rational(1, 4) == Rational(1, 4)) == TRUE);
	CHECK((Rational(1, 4) == Rational(1, 40)) == FALSE);

	CHECK((Rational(1, 1) != Rational(1, 4)) == TRUE);
	CHECK((Rational(1, 4) != Rational(1, 4)) == FALSE);
}

TEST_CASE("[rational] - arifm")
{
	CHECK((Rational(5, 5) + Rational(2,3) == Rational(5, 3)));
	CHECK(((Rational(5, 5) + 2) == Rational(3,1)));
	CHECK(((Rational(5, 5) += Rational(-2, 3)) == Rational(1, 3)));
	
	CHECK((Rational(2, 5) - Rational(2, -3) == Rational(16, 15)));
	CHECK(((Rational(-2, 3) - 2) == Rational(-8, 3)));
	CHECK(((Rational(-3, 2) -= Rational(-3, 2)) == Rational(0, 1)));

	CHECK((Rational(2, 5) * Rational(5, 2) == Rational(1, 1)));
	CHECK(((Rational(-4, 3) * 2) == Rational(-8, 3)));
	CHECK(((Rational(-3, 2) *= Rational(-3, 2)) == Rational(9, 4)));

	CHECK((Rational(2, 5) / Rational(2, -3) == Rational(-3, 5)));
	CHECK(((Rational(-2, 3) / (-2)) == Rational(1, 3)));
	CHECK(((Rational(7, 2) /= Rational(2, 7)) == Rational(49, 4)));
	
	CHECK(((Rational(2)++) == Rational(3, 1)));
	CHECK(((Rational(2)--) == Rational(1)));
	CHECK(((-Rational(2)) == Rational(-2,1)));

}
TEST_CASE("[rational] - input")
{
	Rational z;
	std::string exFALSEPLUS[5] = { " 4 / 5 ", "4 /5","4/ 5"," 4 /5","4 / 5 " };

	for (int i = 0; i < 5; i++)
	{
		z = (0, 1);
		std::istringstream istrm(exFALSEPLUS[i]);
		istrm >> z;
		CHECK((z != Rational(4, 5)));
		istrm.clear();
	}

	std::string exTRUEPLUS[4] = {" 2/4 ","2/4", "2/4 " , " 2/4" };
	for (int i = 0; i < 4; i++)
	{
		z = (0, 1);
		std::istringstream istrm(exTRUEPLUS[i]);
		istrm >> z;
		CHECK((z == Rational(1, 2)));
		istrm.clear();
	}

	std::string exFALSEMINUS[2] = { "- 2/2","2/-2" };
	for (int i = 0; i < 2; i++)
	{
		z = (0, 1);
		std::istringstream istrm(exFALSEMINUS[i]);
		istrm >> z;
		CHECK((z != Rational(-1, 1)));
		istrm.clear();
	}
	std::string exTRUEMINUS[4] = { " -2/4 ", "-2/4 "," -2/4","-2/4"};
	for (int i = 0; i < 4; i++)
	{
		z = (0, 1);
		std::istringstream istrm(exTRUEMINUS[i]);
		istrm >> z;
		CHECK((z == Rational(-1, 2)));
		istrm.clear();
	}
	
}
//questions for " -2/4", "2/4", " 2/4", "-2/4"

//int main()
//{
//	/*using namespace std;
//	string ex[6] = {"123/2"," -2/4.63",  " 3/-4 ", " 0/1 0/23 ", " 1/0 ", " 2 " };
//	for (int i = 0; i < 6; i++)
//	{
//		Rational z;
//
//		istringstream istrm(ex[i]);
//		istrm >> z;
//		if (istrm.good())
//		{
//			cout << "Test "<<i+1<<" == success : ";
//			cout << z << endl;
//		}
//		else
//		{
//			cout << "Test " << i + 1 << " == error : "<<ex[i]<<" "<<z<<endl;
//		}
//	}*/
//	Rational z,x,c;
//	std::cin >> z>>x>>c;
//	std::cout << z<<"\n"<<x<<"\n" << c;
//}

