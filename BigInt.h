// ============================================================================
// 
//                           C++ Class Interface over GNU MP
// 
//                               Author's github: teramil 
//
// ============================================================================


#ifndef _BIGINT_HPP
#define _BIGINT_HPP

#include <iostream>

#include <gmp.h>


class BigInt
{

public:
	BigInt();
	BigInt(const BigInt& bigInt);
	BigInt(const char * value);
	BigInt(const char * value, int base);
	~BigInt();

	BigInt& operator=(const BigInt& right);
  BigInt& operator=(const char * value);

  friend const BigInt  operator + (const BigInt& left, const BigInt& right);
  friend const BigInt  operator - (const BigInt& left, const BigInt& right);
	friend const BigInt& operator * (const BigInt& left, const BigInt& right);
	friend const BigInt& operator / (const BigInt& left, const BigInt& right);

	friend BigInt& operator /= (BigInt& left, const BigInt& right);
	friend BigInt& operator *= (BigInt& left, const BigInt& right);
	friend BigInt& operator -= (BigInt& left, const BigInt& right);
	friend BigInt& operator += (BigInt& left, const BigInt& right);

	friend const BigInt& operator % (const BigInt& left, const BigInt& right);	

	friend const BigInt  operator + (const BigInt& left, const unsigned long int& right);
	friend const BigInt  operator - (const BigInt& left, const unsigned long int& right);
	friend const BigInt& operator * (const unsigned long int& left, const BigInt& right);
	friend const BigInt& operator / (const BigInt& left, const unsigned long int& right);
	friend const BigInt& operator % (const BigInt& left, const unsigned long int& right);

	friend bool operator < (const BigInt& left, const BigInt& right);
	friend bool operator > (const BigInt& left, const BigInt& right);
	friend bool operator == (const BigInt& left, const BigInt& right);

	friend bool operator != (const BigInt& left, const signed long int& right);
	friend bool operator < (const BigInt& left, const signed long int& right);
	friend bool operator > (const BigInt& left, const signed long int& right);

	char * getStringValue(int base);
	int setStringValue(char * string, int base);

	BigInt invert(BigInt modulo);
	BigInt bisqrt();

	friend const BigInt operator-(const BigInt& op);

private:
	mpz_t value_;

};


BigInt::BigInt() 
{ 
	mpz_init(value_); 
}

BigInt::BigInt(const BigInt& bigInt) 
{
	mpz_init(value_);
  mpz_set(value_, bigInt.value_);
}

BigInt::BigInt(const char * value) 
{
	mpz_init_set_str(value_, value, 10);
}

BigInt::BigInt(const char * value, int b) 
{
	mpz_init_set_str(value_, value, b);
}

BigInt::~BigInt()
{
	mpz_clear(value_);
}

BigInt& BigInt::operator=(const BigInt& right)
{
  if (this == &right) {
    return *this;
  }
  mpz_set(value_, right.value_);
 	return *this;
}

BigInt& BigInt::operator=(const char * str)
{
	mpz_set_str(value_,str,10);
	return *this;
}

char * BigInt::getStringValue(int base)
{
	char * str = new char [2];
	return	mpz_get_str(str,base,this->value_);
}

int BigInt::setStringValue(char * string, int base)
{
	return mpz_set_str(this->value_,string,base);
}

BigInt BigInt::invert(BigInt mod)
{
	BigInt *inv = new BigInt();
	if(!mpz_invert(inv->value_, this->value_, mod.value_))
	{
		std::cout << "The inverse of " << mpz_get_str(NULL, 10, this->value_) <<
					 " doesn't exist or another problem!" << std::endl;
	}
	return *inv;
}

BigInt BigInt::bisqrt()
{
	BigInt *sq = new BigInt();
	mpz_sqrt(sq->value_,this->value_);
	return *sq;
}

const BigInt operator-(const BigInt& op)
{
	BigInt *rop = new BigInt();
	mpz_neg(rop->value_, op.value_);

	return *rop;
}

const BigInt operator+(const BigInt& left, const BigInt& right)
{
	BigInt *rop = new BigInt();
	mpz_add(rop->value_, left.value_, right.value_);

	return *rop;
}

BigInt& operator+=(BigInt& left, const BigInt& right)
{
	mpz_add(left.value_, left.value_, right.value_);
	return left;
}

const BigInt operator-(const BigInt& left, const BigInt& right)
{
	BigInt *rop = new BigInt();
	mpz_sub(rop->value_, left.value_, right.value_);

	return *rop;
}

BigInt& operator-=(BigInt& left, const BigInt& right)
{
	mpz_sub(left.value_, left.value_, right.value_);
	return left;
}

const BigInt& operator*(const BigInt& left, const BigInt& right)
{
	BigInt *rop = new BigInt();
	mpz_mul(rop->value_, left.value_, right.value_);

	return *rop;
}

BigInt& operator*=(BigInt& left, const BigInt& right)
{
	mpz_mul(left.value_, left.value_, right.value_);
	return left;
}

const BigInt& operator/(const BigInt& left, const BigInt& right)
{
	BigInt *q = new BigInt();
	mpz_tdiv_q(q->value_, left.value_, right.value_);

	return *q;
}

BigInt& operator/=(BigInt& left, const BigInt& right)
{
	mpz_tdiv_q(left.value_, left.value_, right.value_);
	return left;
}

const BigInt& operator%(const BigInt& left, const BigInt& right)
{
	BigInt *r = new BigInt();
	mpz_tdiv_r(r->value_, left.value_, right.value_);

	return *r;
}

bool operator<(const BigInt& left, const BigInt& right)
{
	if(mpz_cmp(left.value_, right.value_) < 0)
		return true;
	else
		return false;
}

bool operator>(const BigInt& left, const BigInt& right)
{
	if(mpz_cmp(left.value_, right.value_) > 0)
		return true;
	else
		return false;
}

bool operator==(const BigInt& left, const BigInt& right)
{
	if(mpz_cmp(left.value_, right.value_) == 0)
		return true;
	else
		return false;
}

const BigInt operator+(const BigInt& left, const unsigned long int& right)
{
	BigInt *rop = new BigInt();
	mpz_add_ui(rop->value_, left.value_, right);

	return *rop;
}

const BigInt operator-(const BigInt& left, const unsigned long int& right)
{
	BigInt *rop = new BigInt();
	mpz_sub_ui(rop->value_, left.value_, right);

	return *rop;
}

const BigInt& operator*(const unsigned long int& left, const BigInt& right)
{
	BigInt *rop = new BigInt();
	mpz_mul_ui(rop->value_, right.value_, left);

	return *rop;
}

const BigInt& operator/(const BigInt& left, const unsigned long int& right)
{
	BigInt *q = new BigInt();
	mpz_tdiv_q_ui(q->value_, left.value_, right);

	return *q;
}

bool operator!=(const BigInt& left, const signed long int& right)
{
	if(mpz_cmp_si(left.value_, right) == 0)
		return false;
	else
		return true;
}

bool operator<(const BigInt& left, const signed long int& right)
{
	if(mpz_cmp_si(left.value_, right) < 0)
		return true;
	else
		return false;
}

bool operator>(const BigInt& left, const signed long int& right)
{
	if(mpz_cmp_si(left.value_, right) > 0)
		return true;
	else
		return false;
}

const BigInt& operator%(const BigInt& left, const unsigned long int& right)
{
	BigInt *r = new BigInt();
	mpz_tdiv_r_ui(r->value_, left.value_, right);
	
	return *r;
}


#endif //