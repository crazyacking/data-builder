/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-05-07-16.32
 */
#pragma once

#ifndef _FACTORY_H_
#include "mingw.h"



// function declaration
char rand_char();
long long rand_number();
string rand_string();
vector<long long> rand_num_array();
char rand_lowercase_letter();
char rand_uppercase_letter();




/*
generate a character randomly.
asc_low : start character
asc_high : end character
*/
char rand_char(char asc_low='a',char asc_high='z')
{
    unsigned long long mod=max(asc_low,asc_high)-min(asc_low,asc_high)+1;
    long long offset=rand()%mod;
    while(!(asc_low+offset>=asc_low && asc_low+offset<=asc_high))
    	offset=rand()%mod;
    return char(asc_low+offset);
}



/*
generate a number randomly.
low : start number
high : end number
*/
long long rand_number(long long low=INT_MIN,long long high=INT_MAX)
{
    unsigned long long mod=max(low,high)-min(low,high)+1;
    long long offset=rand()%mod;
    while(!(low+offset>=low && low+offset<=high))
    	offset=rand()%mod;
    return (long long)low+offset;
}



/*
generate a string randomly.
len : the length of string
asc_low : start character
asc_high : end character
*/
string rand_string(int len=0,int asc_low='a',int asc_high='z')
{
	char str[len+1];
	for(int i=0;i<len;++i)
		str[i]=rand_char(asc_low,asc_high);
	str[len]='\0';
	return string(str);
}





/*
generate a number array randomly.
len : the length of array
low : start number
high : end number
return type:vector<long long>
*/
vector<long long> rand_num_array(long long len=0,long long low=INT_MIN,long long high=INT_MAX)
{
	vector<long long> ret(len,0);
	for(int i=0;i<len;++i)
		ret[i]=rand_number(low,high);
	return ret;
}



char rand_lowercase_letter()
{
	return rand_char('a','z');
}

char rand_uppercase_letter()
{
	return rand_char('A','Z');
}


#endif // _FACTORY_H_
