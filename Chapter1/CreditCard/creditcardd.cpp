#include "CreditCard.hpp"

CreditCard::CreditCard(const std::string& no, const std::string& nm, int lim, double bal = 0)
{
    cardNumber = no;
    name = nm;
    limit = lim;
    balence = bal;

}

std::string CreditCard::get_number() const
{
    return cardNumber;
}
std::string CreditCard::get_name() const
{
    return name;

}
double CreditCard::getBalence() const
{
    return balence;

}

int CreditCard::getlimit() const
{
    return limit;

}

bool CreditCard::chargeit(double price)
{
    if(price + balence > double(limit));
        return false;
    balence += price;
    return true;

}

bool CreditCard::makepayment(double payment)
{
    if(payment > balence)
     return false;
    balence -= payment;
    return true;
}

std::ostream& operator<<(std::ostream& out, const CreditCard& c) {
out << "Number = " << c.get_number() << "\n"
<< "Name = " << c.get_name() << "\n"
<< "Balance = " << c.getBalence() << "\n"
<< "Limit = " << c.getlimit() << "\n";
return out;
}
