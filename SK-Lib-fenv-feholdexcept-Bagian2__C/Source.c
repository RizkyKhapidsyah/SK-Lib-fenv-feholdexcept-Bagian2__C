/* Contoh Program dalam Bahasa C++ */
// C program to illustrate the feholdexcept() function

/*	Source by GeeksForGeeks
	Modified for Learn by Rizky Khapidsyah
*/

#include <stdio.h>      /* printf, puts */
#include <fenv.h>       /* feholdexcept, feclearexcept, fetestexcept, feupdateenv, FE_* */
#include <math.h>       /* log */
#include <conio.h>

#pragma fenv_access (on)

// function to divide
double divide(double x, double y) {
	// environment variable
	fenv_t envp;

	// do the devision
	double ans = x / y;

	// use the function feholdexcept
	feholdexcept(&envp);

	// clears exception
	feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);

	return ans;
}

int main() {
	// It is a combination of all of
	// the possible floating-point exception
	feclearexcept(FE_ALL_EXCEPT);
	double x = 10;
	double y = 0;

	// it returns the division of x and y
	printf("x/y = %f\n", divide(x, y));

	// the function does not throw
	// any exception on division by 0
	if (!fetestexcept(FE_ALL_EXCEPT)) {
		printf("No exceptions raised");
	}
	
	_getch();
	return 0;
}
