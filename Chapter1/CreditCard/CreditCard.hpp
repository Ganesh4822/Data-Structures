#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include<string>
#include<iostream>

class CreditCard
{
    private:
        std::string cardNumber;
        std::string name;
        int limit;
        double balence;
    
    public:
        CreditCard(const std::string& no, const std::string& nm, int lim, double bal = 0);

        std::string get_number() const;
        std::string get_name() const;
        double getBalence() const;
        int getlimit() const;

        bool chargeit(double price);
        bool makepayment(double payment);


};

std::ostream&  operator<<(std::ostream& os, const CreditCard& obj);

#endif

