/* ***************************************************************************
 🎈 COMPETITION CODE HELPER 													🎈
 🎈 01/11/2017 																🎈
 🎈 LUCAS LUKASAVICUS SILVA													🎈
 🎈 lukasavicus at gmail dot com 											🎈
 🎈 version: 1.0					 											🎈
 *************************************************************************** */

/*
	Referencias:
	Libs - http://www.cplusplus.com/reference/clibrary/
	Data Types - https://en.wikipedia.org/wiki/C_data_types
	Macros - 
*/

/* **************************** 🎈 LIBRARIES 🎈 **************************** */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <stdbool.h>

	#include <iostream>
	#include <sstream>
	#include <string>
	#include <algorithm>
	#include <vector>
	#include <iterator>

	using namespace std;
/* ======================================================================= */



/* ***************************** 🎈 TYPEDEF 🎈 ***************************** */
	typedef long long int lli;
	typedef unsigned long long int ulli;
	typedef signed long long int slli;

	//typedef map<string, int> msi;
	//typedef pair<string, int> psi;
	//typedef vector<string> vs;
	//typedef map<string,int> msi; (1861)
/* ======================================================================= */


/* ************************* 🎈 GLOBAL VARIABLES 🎈 ************************ */
	// Constants
	const bool _DEBUG_ = false;

	const int _10e1_ = 10;
	const int _10e2_ = 100;
	const int _10e3_ = 1000;
	const int _10e4_ = 10000;
	const int _10e5_ = 100000;
	const int _10e6_ = 1000000;

	const double PI = 3.1415;
	/* --------------------------------------------------------------- */
	// Other Variables
	lli TC = 0; // Test cases var
	const int _month_days_ [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* ======================================================================= */



/* ***************************** 🎈 MACROS 🎈 ****************************** */
	#define DEBUG if(_DEBUG_)
	#define INF while(1)
	#define TC_LOOP scanf("%lld", &TC); while(TC--)

	// Talvez já exista algo assim em bool.h
	#define TRUE 1
	#define FALSE 0
/* ======================================================================= */



/* ************************ 🎈 USEFULL FUNCTIONS 🎈 ************************ */

	// 'a' need tobe greater than 'b'
	lli mdc(const lli a, lli const b){
		if(!b)
			return a;
		return mdc(b, (a % b));
	}

	lli mmc(const lli a, lli const b){
		return ((a / mdc(a, b)) * b);
	}

	int min_i(const int a, int const b){
		return (a < b) ? a : b;
	}
	int max_i(const int a, int const b){
		return (a > b) ? a : b;
	}

	//split integer number into array of digits
	int * int2array(const int a){
		int arr[_10e6_];
		return arr;
	}

	//count how many digits an int have
	int int_digs(const int a){
		return 0;
	}
	// Acho q as duas funções fazem/deveriam fazer a mesma coisa
	int llog10(int n){
	  int r = 0;
	  n /= 10;
	  while(n != 0){
	    n /= 10;
	    r++;
	  }
	  return r;
	}

	//modulo abs (absolute)
	int mod(const int a){
		return (a > 0) ? (a) : (-a);
	}

	//modulo da diferença
	int mod_diff(const int a, const int b){
		return (a > b) ? (a - b) : (b - a);
	}

	// sum(n): (2^n)-1
	int sum(const int a){
		if(!a)
			return 0;
		return a + sum(a-1);
	}

	int fat(const int a){
		if(!a)
			return 1;
		return a + sum(a-1);
	}

	// conversão de decimal para hexadecimal - TODO
	void dec2hex(int n){ //void -> char []
		
		int r;
			
		if(n == 0)
			return ;

		r = n % 16;
		n /= 16;
			
		dec2hex(n);
		
		(r >= 10) ? printf("%c", 65+r-10) : printf("%d", r);

	}

	
	//bubble_sort -> how many swaps
	void bubble(int vet[], int size){
	    int i, j, aux;
	    for(i = 0; i < size; i++)
	        for(j = i + 1; j < size; j++)
	            if(vet[j] < vet[i]){
	                aux = vet[i];
	                vet[i] = vet[j];
	                vet[j] = aux;
	            }
	}

	int str2int(string str){
		//str = str.reverse();
		int n = 0;
		for(int i = 0; i < str.length(); i++)
			n + pow((str[i]-'0'),i);

		return n;
	}

	//Cálculos de areas

	//Exponenciação Rapida

	//RSA e Cripto

	//ordenacao asc e desc; (compare)

	// ordenacao lexicografica asc e desc (compare)

/* ======================================================================= */


/*


compose a integer number by the number that compose it


tratamento de saída: printf("A=%.4lf\n", r * r * pi);
1478
tratamento de entrada: scanf("^[%s\n]", s);

casting functions (toInt, toDouble)

Estruturas comuns

cálculo de área e perímetro de figuras geométricas

métricas de distância (euclidiana, manhattan)

algo para resolver 1018 de maneira genérica

date and time functions

string functions (isLetter, isNumeric, isVogal, isConsoant ...)

regex functions sub, match, search;

bin_search - 1025

bit to bit functions - 1026

exponenciação rápida

teste de primalidade

PAs,PGs

cálculo das raízes reais de uma função (quadrática, cúbica e etc.)

geo anal -> 1039

propriedades matemáticas como:
	Dadas 3 retas, elas formam um triangulo? (1045)
	Número perfeito: 1164

vetores constantes: [jan/jan/31, fev/feb/(28/29), mar/mar/30, ...]

Estatísticas de vetores (média, mediana, # positivos, # negativos, ...)

vectors high order funcs: map, reduce, filter
índice do maior/menor elemento

Analisar dps: [1082, 1218, 1716]

Funções específicas para números decimais, como:
int_part(db), decimal_part(db), format_when_int (função que quando o número não tem parte decimal imprime com "%.0lf" e quando tem imprime diferente, ex.: "%.1lf"): 1098

função de comparação para qsort

GRAFOS:

	numero de componentes conexas (maior do que um) - 
	AGM(Prim) - 1774
	BEP_IMPAR - 1979, 2131
	Tarjan - 2440
	

print " " for all elements except the last one
printf("%02d:%02d - ", h, m);

UnionSet/FindSet: 1152

log2int (1170): 

1607 <- Inclusive

Triangulo de pascal - 2232

hash_table;
vector<vector<int>>
vector

void printSpace(int t, int k){
  int i, n, m;
  m = log10(k);
  n = t;
  n++;
  n -= m;
  //printf("-%d-\n", n);
  for(i = 0; i < n; i++)
    printf(" ");
}

dados 3 lados verificar se forma um triangulo
int isTri(int a, int b, int c){
  return ((a+b > c) && a < c && b < c);
}

(
    isTri(a, b, c) || isTri(a, b, d) || isTri(a, c, b) || isTri(a, c, d) || isTri(a, d, b) || isTri(a, d, c) ||
                                        isTri(b, c, a) || isTri(b, c, d) || isTri(b, d, a) || isTri(b, d, c) ||
                                                                            isTri(c, d, a) || isTri(c, d, b)
  ) 
  ? printf("S\n") : printf("N\n");



1958:

int main(){
    double d;

    scanf("%lf", &d);
    char resp[1123];

    sprintf(resp, "%.4E\n", d);

    if((d >= 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000) && (resp[0] != '-'))
        printf("+");
    printf("%.4E\n", d);

    return 0;
}

2161
double fracao_periodica_aproximada(int denominador, int precisao){
	if(precisao == 0){
		return 0;
	}
	else if(precisao == 1){
		return 1 / (double)(denominador);
	}
	else{
		return 1 / (double)((double)(denominador) + fracao_periodica_aproximada(denominador, precisao-1));
	}
}


Convresão de decimal para romanos: 1960

*/


/* ****************************** 🎈 TIPS 🎈 ******************************* */
	/* Data Types and Format Specifier:
		char																%c
		signed char															%c (or %hhi for numerical output)
		unsigned char														%c (or %hhu for numerical output)
		short, short int, signed short, signed short int					%hi
		unsigned short, unsigned short int									%hu
		int, signed, signed int												%d or %i
		unsigned, unsigned int												%u
		long, long int, signed long, signed long int						%li
		unsigned long, unsigned long int									%lu
		long long, long long int, signed long long, signed long long int 	%lli
		unsigned long long, unsigned long long int							%llu
		float																%f %F for digital notation, or, %g %G, or, %e %E, %a %A for scientific notation
		double																%lf %lF, %lg  %lG, %le  %lE, %la %lA
		long double 														%Lf %LF, %Lg %LG, %Le %LE, %La %LA
	*/

	// Some very neet information can be found in here:
	// http://www.cplusplus.com/reference/cstdio/fscanf/
	// http://www.cplusplus.com/reference/cstdio/fprintf/

	/* Libraries and mainly items:
		stdio.h{
			Functions:

			Remove 		Remove file
			int remove ( const char * filename );

			Rename 		Rename file
			int rename ( const char * oldname, const char * newname );

			fflush		Flush stream
			int fflush ( FILE * stream );

			fopen		Open file
			FILE * fopen ( const char * filename, const char * mode );

			fclose		Close file
			int fclose ( FILE * stream );

			setbuf		Set stream buffer
			void setbuf ( FILE * stream, char * buffer );

			fprintf 	Write formatted data to stream
			int fprintf ( FILE * stream, const char * format, ... );

			fscanf		Read formatted data from stream
			int fscanf ( FILE * stream, const char * format, ... );


			printf 		Print formatted data to stdout
			int printf ( const char * format, ... );

			scanf 		Read formatted data from stdin
			int scanf ( const char * format, ... );

			sprintf		Write formatted data to string
			int sprintf ( char * str, const char * format, ... );

			sscanf		Read formatted data from string
			int sscanf ( const char * s, const char * format, ...);

			fgetc 		Get character from stream 
			int fgetc ( FILE * stream );

			fgets		Get string from stream 
			char * fgets ( char * str, int num, FILE * stream );

			fputc		Write character to stream
			int fputc ( int character, FILE * stream );

			fputs		Write string to stream 
			int fputs ( const char * str, FILE * stream );

			getc		Get character from stream 
			int getc ( FILE * stream );

			getchar		Get character from stdin 
			int getchar ( void );

			gets		Get string from stdin 
			char * gets ( char * str );

			putc		Write character to stream 
			int putc ( int character, FILE * stream );

			putchar		Write character to stdout 
			int putchar ( int character );

			puts		Write string to stdout
			int puts ( const char * str );

			ungetc		Unget character from stream 
			int ungetc ( int character, FILE * stream );
			
			
			Macros:
			EOF			End-of-File
			NULL		Null pointer

			Types:
			FILE 		Object containing information to control a stream
			size_t 		Unsigned integral type
		}

		stdlib.h{
			Functions:
			atof		Convert string to double
			double atof (const char* str);

			atoi		Convert string to integer
			int atoi (const char * str);

			atol		Convert string to long integer
			long int atol ( const char * str );

			atoll 		Convert string to long long integer
			long long int atoll ( const char * str ); ?

			strtod		Convert string to double
			double strtod (const char* str, char** endptr);

			strtof 		Convert string to float
			float strtof (const char* str, char** endptr);

			strtol		Convert string to long integer
			long int strtol (const char* str, char** endptr, int base);

			strtold 	Convert string to long double
			long double strtold (const char* str, char** endptr);

			strtoll 	Convert string to long long integer
			long long int strtoll (const char* str, char** endptr, int base);

			strtoul		Convert string to unsigned long integer
			unsigned long int strtoul (const char* str, char** endptr, int base);

			strtoull 	Convert string to unsigned long long integer
			unsigned long long int strtoull (const char* str, char** endptr, int base);

			rand		Generate random number
			int rand (void);

			srand		Initialize random number generator
			void srand (unsigned int seed);

			calloc		Allocate and zero-initialize array
			void* calloc (size_t num, size_t size);

			free		Deallocate memory block
			void free (void* ptr);

			malloc		Allocate memory block
			void* malloc (size_t size);

			realloc		Reallocate memory block
			void* realloc (void* ptr, size_t size);

			bsearch		Binary search in array
			void* bsearch (const void* key, const void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

			qsort		Sort elements of array
			void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
			
			abs			Absolute value
			int abs (int n);

			div			Integral division
			div_t div (int numer, int denom);

			labs		Absolute value
			long int labs (long int n);

			ldiv		Integral division
			ldiv_t ldiv (long int numer, long int denom);

			llabs 		Absolute value
			long long int llabs (long long int n);

			lldiv 		Integral division
			lldiv_t lldiv (long long int numer, long long int denom);
						
			Macros:
			EXIT_FAILURE	Failure termination code
			EXIT_SUCCESS	Success termination code
			MB_CUR_MAX		Maximum size of multibyte characters
			NULL			Null pointer
			RAND_MAX		Maximum value returned by rand

			Types:
			div_t			Structure returned by div
			ldiv_t			Structure returned by ldiv
			lldiv_t 		Structure returned by lldiv
			size_t			Unsigned integral type
		}

		string.h{
			Functions:
			memcpy		Copy block of memory
			void * memcpy ( void * destination, const void * source, size_t num );

			memmove		Move block of memory
			void * memmove ( void * destination, const void * source, size_t num );

			strcpy		Copy string
			char * strcpy ( char * destination, const char * source );

			strncpy		Copy characters from string
			char * strncpy ( char * destination, const char * source, size_t num );

			strcat		Concatenate strings
			char * strcat ( char * destination, const char * source );

			strncat		Append characters from string
			char * strncat ( char * destination, const char * source, size_t num );

			memcmp		Compare two blocks of memory
			int memcmp ( const void * ptr1, const void * ptr2, size_t num );

			strcmp		Compare two strings
			int strcmp ( const char * str1, const char * str2 );

			strcoll		Compare two strings using locale
			int strcoll ( const char * str1, const char * str2 );

			strncmp		Compare characters of two strings
			int strncmp ( const char * str1, const char * str2, size_t num );

			strxfrm		Transform string using locale
			size_t strxfrm ( char * destination, const char * source, size_t num );

			memchr		Locate character in block of memory
			const void * memchr ( const void * ptr, int value, size_t num );
		    void * memchr ( void * ptr, int value, size_t num );

			strchr		Locate first occurrence of character in string
			const char * strchr ( const char * str, int character );
      		char * strchr ( char * str, int character );

			strcspn		Get span until character in string
			size_t strcspn ( const char * str1, const char * str2 );
      		
			strpbrk		Locate characters in string
			const char * strpbrk ( const char * str1, const char * str2 );
      		char * strpbrk (       char * str1, const char * str2 );

			strrchr		Locate last occurrence of character in string
			const char * strrchr ( const char * str, int character );
      		char * strrchr ( char * str, int character );

			strspn		Get span of character set in string
			size_t strspn ( const char * str1, const char * str2 );

			strstr		Locate substring
			const char * strstr ( const char * str1, const char * str2 );
      		char * strstr ( char * str1, const char * str2 );

			strtok		Split string into tokens
			char * strtok ( char * str, const char * delimiters );

			memset		Fill block of memory
			void * memset ( void * ptr, int value, size_t num );

			strerror	Get pointer to error message string
			char * strerror ( int errnum );

			strlen		Get string length
			size_t strlen ( const char * str );

			Macros:
			NULL 		Null pointer

			Types:
			size_t 		Unsigned integral type
		}

		math.h{
			cos			Compute cosine
			sin			Compute sine
			tan			Compute tangent
			acos			Compute arc cosine
			asin			Compute arc sine
			atan			Compute arc tangent
			atan2			Compute arc tangent with two parameters
			
			Hyperbolic functions
			cosh			Compute hyperbolic cosine
			sinh			Compute hyperbolic sine
			tanh			Compute hyperbolic tangent
			acosh 			Compute area hyperbolic cosine
			asinh 			Compute area hyperbolic sine
			atanh 			Compute area hyperbolic tangent
			
			Exponential and logarithmic functions
			exp			Compute exponential function
			frexp			Get significand and exponent
			ldexp			Generate value from significand and exponent
			log			Compute natural logarithm
			log10			Compute common logarithm
			modf			Break into fractional and integral parts
			exp2 			Compute binary exponential function
			expm1 			Compute exponential minus one
			ilogb 			Integer binary logarithm
			log1p 			Compute logarithm plus one
			log2 			Compute binary logarithm
			logb 			Compute floating-point base logarithm
			scalbn 			Scale significand using floating-point base exponent
			scalbln 			Scale significand using floating-point base exponent (long)
			
			Power functions
			pow			Raise to power
			sqrt			Compute square root
			cbrt 			Compute cubic root
			hypot 			Compute hypotenuse
			
			Error and gamma functions
			erf 			Compute error function
			erfc 			Compute complementary error function
			tgamma 			Compute gamma function
			lgamma 			Compute log-gamma function
			
			Rounding and remainder functions
			ceil			Round up value
			floor			Round down value
			fmod			Compute remainder of division
			trunc 			Truncate value
			round 			Round to nearest
			lround 			Round to nearest and cast to long integer
			llround 			Round to nearest and cast to long long integer
			rint 			Round to integral value
			lrint 			Round and cast to long integer
			llrint 			Round and cast to long long integer
			nearbyint 			Round to nearby integral value
			remainder 			Compute remainder (IEC 60559)
			remquo 			Compute remainder and quotient
			
			Floating-point manipulation functions
			copysign 			Copy sign
			nan 			Generate quiet NaN
			nextafter 			Next representable value
			nexttoward 			Next representable value toward precise value
			
			Minimum, maximum, difference functions
			fdim 			Positive difference
			fmax 			Maximum value
			fmin 			Minimum value
			
			Other functions
			fabs			Compute absolute value
			abs			Compute absolute value
			fma 			Multiply-add
		}

		stdbool.h{
			
			// There isn't Functions or Macros or Types (?)
		}
	*/
/* ======================================================================= */