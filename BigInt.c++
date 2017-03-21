// #include "BigInt.hpp"
// // #include <iostream>
// // using namespace std;


// // the member functions of the class
// // ----------------------------------->
// void BigInt::show()
// {
// 	cout << this->value;
// }

// BigInt BigInt::invert(BigInt mod)
// {
// 	BigInt *inv = new BigInt();
// 	if(!mpz_invert(inv->value, this->value, mod.value))
// 	{
// 		cout << "The inverse of this doesn't exist or another problem!" << endl;
// 		//return NULL;
// 	}

// 	return *inv; //??????
// }

// BigInt BigInt::bisqrt()
// {
// 	BigInt *sq = new BigInt();
// 	mpz_sqrt(sq->value,this->value);
// 	return *sq;
// }

// //	==============================================================
// //	===============	 BigInt left, BigInt right	==================
// //	==============================================================

// // +
// const BigInt operator+(const BigInt& left, const BigInt& right)
// {
// 	BigInt *rop = new BigInt();
// 	mpz_add(rop->value, left.value, right.value);

// 	return *rop;
// }

// // +=
// BigInt& operator+=(BigInt& left, const BigInt& right)
// {
// 	mpz_add(left.value, left.value, right.value);
// 	return left;
// }

// // - 
// const BigInt operator-(const BigInt& left, const BigInt& right)
// {
// 	BigInt *rop = new BigInt();
// 	mpz_sub(rop->value, left.value, right.value);

// 	return *rop;
// }

// // -=
// BigInt& operator-=(BigInt& left, const BigInt& right)
// {
// 	mpz_sub(left.value, left.value, right.value);
// 	return left;
// }

// // *
// const BigInt& operator*(const BigInt& left, const BigInt& right)
// {
// 	BigInt *rop = new BigInt();
// 	mpz_mul(rop->value, left.value, right.value);

// 	return *rop;
// }

// // *=
// BigInt& operator*=(BigInt& left, const BigInt& right)
// {
// 	mpz_mul(left.value, left.value, right.value);
// 	return left;
// }

// // /
// const BigInt& operator/(const BigInt& left, const BigInt& right)
// {
// 	BigInt *q = new BigInt();
// 	mpz_tdiv_q(q->value, left.value, right.value);

// 	return *q;
// }

// // /=
// BigInt& operator/=(BigInt& left, const BigInt& right)
// {
// 	mpz_tdiv_q(left.value, left.value, right.value);
// 	return left;
// }

// // %
// const BigInt& operator%(const BigInt& left, const BigInt& right)
// {
// 	BigInt *r = new BigInt();
// 	mpz_tdiv_r(r->value, left.value, right.value);

// 	return *r;
// }

// // <
// bool operator<(const BigInt& left, const BigInt& right)
// {
// 	if(mpz_cmp(left.value, right.value) < 0)
// 		return true;
// 	else
// 		return false;
// }

// // >
// bool operator>(const BigInt& left, const BigInt& right)
// {
// 	if(mpz_cmp(left.value, right.value) > 0)
// 		return true;
// 	else
// 		return false;
// }

// // ==
// bool operator==(const BigInt& left, const BigInt& right)
// {
// 	if(mpz_cmp(left.value, right.value) == 0)
// 		return true;
// 	else
// 		return false;
// }

// //	====================================================================
// //	==============	BigInt left, signed_long_int right	================
// //	==============	signed_long_int left, BigInt right	================
// //	====================================================================

// // +
// const BigInt operator+(const BigInt& left, const unsigned long int& right)
// {
// 	BigInt *rop = new BigInt();
// 	mpz_add_ui(rop->value, left.value, right);

// 	return *rop;
// }

// // -
// const BigInt operator-(const BigInt& left, const unsigned long int& right)
// {
// 	BigInt *rop = new BigInt();
// 	mpz_sub_ui(rop->value, left.value, right);

// 	return *rop;
// }

// // *
// const BigInt& operator*(const unsigned long int& left, const BigInt& right)
// {
// 	BigInt *rop = new BigInt();
// 	mpz_mul_ui(rop->value, right.value, left);

// 	return *rop;
// }

// // /
// const BigInt& operator/(const BigInt& left, const unsigned long int& right)
// {
// 	BigInt *q = new BigInt();
// 	mpz_tdiv_q_ui(q->value, left.value, right);

// 	return *q;
// }

// // !=
// bool operator!=(const BigInt& left, const signed long int& right)
// {
// 	if(mpz_cmp_si(left.value, right) == 0)
// 		return false;
// 	else
// 		return true;
// }

// // <
// bool operator<(const BigInt& left, const signed long int& right)
// {
// 	if(mpz_cmp_si(left.value, right) < 0)
// 		return true;
// 	else
// 		return false;
// }

// // >
// bool operator>(const BigInt& left, const signed long int& right)
// {
// 	if(mpz_cmp_si(left.value, right) > 0)
// 		return true;
// 	else
// 		return false;
// }

// // %
// const BigInt& operator%(const BigInt& left, const unsigned long int& right)
// {
// 	BigInt *r = new BigInt();
// 	mpz_tdiv_r_ui(r->value, left.value, right);
	
// 	return *r;
// }

// int main()
// {
// 	BigInt a,b,c;

// 	a = "-7";
// 	b = "6";

// 	if(a != 14)
// 		cout << "hi" << endl;



// 	c = a / 2;

// 	c.show();
// 	cout << endl;

// 	return 0;
// }











