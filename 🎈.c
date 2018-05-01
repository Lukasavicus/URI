/* ***************************************************************************
 🎈 COMPETITION CODE HELPER 													🎈
 🎈 01/11/2017 																🎈
 🎈 LUCAS LUKASAVICUS SILVA													🎈
 🎈 lukasavicus at gmail dot com 											🎈
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
/* ======================================================================= */



/* ***************************** 🎈 TYPEDEF 🎈 ***************************** */
	typedef long long int lli;
	typedef unsigned long long int ulli;
	typedef signed long long int slli;
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
	/* --------------------------------------------------------------- */
	// Other Variables
	lli TC = 0; // Test cases var

/* ======================================================================= */



/* ***************************** 🎈 MACROS 🎈 ****************************** */
	#define DEBUG if(_DEBUG_)
	#define INF while(1)
	#define TC_LOOP scanf("%lld", &TC); while(TC--)
/* ======================================================================= */



/* ************************ 🎈 USEFULL FUNCTIONS 🎈 ************************ */
	lli mdc(const lli a, lli const b){
		if(!b)
			return a;
		return mdc(b, (a % b));
	}

	lli mmc(const lli a, lli const b){
		return ((a / mdc(a, b)) * b);
	}

	/* Talvez desnecessario as proximas 6 funcoes */
	int min_i(const int a, int const b);
	int max_i(const int a, int const b);
	int min_f(const float a, float const b);
	int max_f(const float a, float const b);
	int min_d(const double a, double const b);
	int max_d(const double a, double const b);

	//Cálculos de areas

	//Exponenciação Rapida

	//RSA e Cripto

	//ordenacao asc e desc; (compare)

	// ordenacao lexicografica asc e desc (compare)

/* ======================================================================= */



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