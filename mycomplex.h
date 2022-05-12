/*!
    @file
    @brief Çàãîëîâî÷íûé ôàéë êëàññà Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
    @brief Êëàññ êîìïëåêñíîãî ÷èñëà
*/
class Complex
{
    /*!
        @brief Äåéñòâèòåëüíàÿ ñîñòàâëÿþùàÿ
    */
        double Re;
    /*!
        @brief Ìíèìàÿ ñîñòàâëÿþùàÿ
    */
        double Im;
    public:
        Complex ( double aRe = 0, double aIm = 0 );
        Complex ( const Complex& );
        ~Complex ();
        void set ( double aRe, double aIm = 0 );
        operator double ();
        double abs ();
        //Ïåðåîïðåäåëåíèå îïåðàòîðîâ  ñäâèãà
        friend istream& operator >> ( istream& , Complex& );
        friend ostream& operator << ( ostream&, Complex& );
        //Ïåðåîïðåäåëåíèå îïåðàòîðîâ  ñëîæåíèÿ
        Complex operator+ ( const Complex& );
        Complex operator+ ( const double& );
        friend Complex operator+ ( const double&, const Complex& );
        //Ïåðåîïðåäåëåíèå îïåðàòîðîâ  âû÷èòàíèÿ
        Complex operator- ( const Complex& );
        Complex operator- ( const double& );
        friend Complex operator- ( const double&, const Complex& );
        //Ïåðåîïðåäåëåíèå îïåðàòîðîâ  óìíîæåíèÿ
        Complex operator* ( const Complex& );
        Complex operator* ( const double& );
        friend Complex operator* ( const double&, const Complex& );
        //Ïåðåîïðåäåëåíèå îïåðàòîðîâ  äåëåíèÿ
        Complex operator/ ( const double& );
        //Ïåðåîïðåäåëåíèå îïåðàòîðîâ  ïðèñâàèâàíèÿ êîìïëåêñíûõ ÷èñåë
        Complex& operator+= ( const Complex& );
        Complex& operator-= ( const Complex& );
        Complex& operator*= ( const Complex& );
        Complex& operator= ( const Complex& );
        //Ïåðåîïðåäåëåíèå îïåðàòîðîâ  ïðèñâàèâàíèÿ âåùåñòâåííûõ ÷èñåë
        Complex& operator+= ( const double& );
        Complex& operator-= ( const double& );
        Complex& operator*= ( const double& );
        Complex& operator/= ( const double& );
        Complex& operator= ( const double& );
};
#endif
