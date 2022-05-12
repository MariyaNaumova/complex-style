/*!
    @file
    @brief Ôàéë ñ îïèñàíèåì ìåòîäîâ êëàññà Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
    @brief Êîíñòðóêòîð êëàññà
    @param aRe Äåéñòâèòåëüíàÿ ñîñòàâëÿþùàÿ
    @param aIm Ìíèìàÿ ñîñòàâëÿþùàÿ
*/
Complex :: Complex ( double aRe, double aIm )
{
    Re = aRe;
    Im = aIm;
}

/*!
    @brief Êîíñòðóêòîð êëàññà
    @param aRval Êîìïëåêñíîå ÷èñëî
*/
Complex :: Complex ( const Complex & aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
}

/*!
    @brief Äåñòðóêòîð êëàññà
*/
Complex :: ~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

/*!
    @brief Êîíñòðóêòîð êëàññà Complex
    @param aRe Äåéñòâèòåëüíàÿ ñîñòàâëÿþùàÿ
    @param aIm Ìíèìàÿ ñîñòàâëÿþùàÿ
*/
void Complex :: set ( double aRe, double aIm )
{
    //ñåòòåð, óñòàíàâëèâàåò êîìïëåêñíîå ÷èñëî
    Re = aRe;
    Im = aIm;
}

/*!
    @brief Âîçðàùàåò ìîäóëü êîìïëåêñíîãî ÷èñëà
    @return Ìîäóëü êîìïëåêñíîãî ÷èñëà
*/
Complex :: operator double()
{
    return abs();
}

/*!
    @brief Âîçðàùàåò ìîäóëü êîìïëåêñíîãî ÷èñëà
    @return Ìîäóëü êîìïëåêñíîãî ÷èñëà
*/
double Complex :: abs()
{
    return sqrt ( Re * Re + Im * Im );
}

/*!
    @brief Îïåðàòîð ñëîæåíèÿ
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ñóììó êîìïëåêñíûõ ÷èñåë
*/
Complex Complex :: operator+ ( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/*!
    @brief Îïåðàòîð âû÷èòàíèÿ
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ðàçíîñòü êîìïëåêñíûõ ÷èñåë
*/
Complex Complex :: operator- ( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/*!
    @brief Îïåðàòîð ñëîæåíèÿ
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return Ñóììó êîìïëåêñíûõ ÷èñåë
*/
Complex Complex :: operator+ ( const double& aRval )
{
    Complex Result;
    Result.Re = Re + aRval;
    Result.Im = Im;
    return Result;
}

/*!
    @brief Îïåðàòîð âû÷èòàíèÿ
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return Ñóììó êîìïëåêñíûõ ÷èñåë
*/
Complex Complex :: operator- ( const  double& aRval )
{
    Complex Result ( *this );
    Result.Re = Re - aRval;
    return Result;
}

/*!
    @brief Îïåðàòîð óìíîæåíèÿ
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ïðîèçâåäåíèå êîìïëåêñíûõ ÷èñåë
*/
Complex Complex :: operator* ( const Complex & aRval )
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/*!
    @brief Îïåðàòîð óìíîæåíèÿ
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return Ïðîèçâåäåíèå êîìïëåêñíûõ ÷èñåë
*/
Complex Complex :: operator* ( const double& aRval )
{
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/*!
    @brief Îïåðàòîð äåëåíèÿ
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return ×àñòíîå êîìïëåêñíûõ ÷èñåë
*/
Complex Complex :: operator/ ( const double& aRval )
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/*!
    @brief Îïåðàòîð ñëîæåíèÿ ñ ïðèñâàèâàíèåì
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ñóììó êîìïëåêñíûõ ÷èñåë
*/
Complex& Complex :: operator+=  ( const Complex&  aRval )
{
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/*!
    @brief Îïåðàòîð âû÷èòàíèÿ ñ ïðèñâàèâàíèåì
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ðàçíîñòü êîìïëåêñíûõ ÷èñåë
*/
Complex& Complex :: operator-= ( const Complex& aRval )
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/*!
    @brief Îïåðàòîð óìíîæåíèÿ ñ ïðèñâàèâàíèåì
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ïðîèçâåäåíèå êîìïëåêñíûõ ÷èñåë
*/
Complex& Complex :: operator*= ( const Complex& aRval )
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/*!
    @brief Îïåðàòîð ñëîæåíèÿ ñ ïðèñâàèâàíèåì
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return Ñóììó êîìïëåêñíûõ ÷èñåë
*/
Complex& Complex :: operator+= ( const double& aRval )
{
    Re += aRval;
    return *this;
}

/*!
    @brief Îïåðàòîð âû÷èòàíèÿ ñ ïðèñâàèâàíèåì
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return Ðàçíîñòü êîìïëåêñíûõ ÷èñåë
*/
Complex& Complex :: operator-= ( const double& aRval )
{
    Re -= aRval;
    return *this;
}

/*!
    @brief Îïåðàòîð óìíîæåíèÿ ñ ïðèñâàèâàíèåì
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return Ïðîèçâåäåíèå êîìïëåêñíûõ ÷èñåë
*/
Complex& Complex :: operator*= ( const double& aRval )
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/*!
    @brief Îïåðàòîð äåëåíèÿ ñ ïðèñâàèâàíèåì
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return ×àñòíîå êîìïëåêñíûõ ÷èñåë
*/
Complex& Complex :: operator/= ( const double& aRval )
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/*!
    @brief Îïåðàòîð ïðèñâàèâàíèÿ
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ññûëêó íà îáúåêò
*/
Complex& Complex :: operator= ( const Complex& aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/*!
    @brief Îïåðàòîð ïðèñâàèâàíèÿ
    @param aRval Âåùåñòâåííîå ÷èñëî
    @return Ññûëêó íà îáúåêò
*/
Complex& Complex :: operator= ( const double& aRval )
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

/*!
    @brief Îïåðàòîð ñäâèãà âïðàâî
    @param stream Ïîòîê ââîäà
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return IO ïîòîê
*/
istream& operator >> ( istream& Stream, Complex& aRval )
{
    char tmp[256];
    Stream >> aRval.Re >> aRval.Im >> tmp;
    return Stream;
}

/*!
    @brief Îïåðàòîð ñäâèãà âïðàâî
    @param stream Ïîòîê âûâîäà
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return IO ïîòîê
*/
ostream& operator << ( ostream& Stream, Complex& aRval )
{
    Stream << aRval.Re;
    if ( !( aRval.Im < 0 ) )
        Stream << '+';
    Stream << aRval.Im << 'i';
    return Stream;
}

/*!
    @brief Îïåðàòîð ñëîæåíèÿ
    @param aLval Âåùåñòâåííîå ÷èñëî
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ñóììó ÷èñåë
*/
Complex operator+ ( const double& aLval, const Complex& aRval )
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/*!
    @brief Îïåðàòîð âû÷èòàíèÿ
    @param aLval Âåùåñòâåííîå ÷èñëî
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ðàçíîñòü ÷èñåë
*/
Complex operator- ( const double& aLval, const Complex& aRval )
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im =- aRval.Im;
    return Result;
}

/*!
    @brief Îïåðàòîð óìíîæåíèÿ
    @param aLval Âåùåñòâåííîå ÷èñëî
    @param aRval Êîìïëåêñíîå ÷èñëî
    @return Ïðîèçâåäåíèå ÷èñåë
*/
Complex operator* ( const double& aLval, const Complex& aRval)
{
    Complex Result;
    Result.Re = aLval * aRval.Re;
    Result.Im = aLval * aRval.Im;
    return Result;
}
