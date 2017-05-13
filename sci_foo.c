/* ==================================================================== */
/* Template toolbox_skeleton */
/* Example detail in "API_scilab getting started" help page */
/* This file is released under the 3-clause BSD license. See COPYING-BSD. */
/* ==================================================================== */
#include "api_scilab.h"
#include "BOOL.h"
#include <localization.h>

/* ==================================================================== */
int sci_foo(char *fname, unsigned long fname_len)
{
    // Error management variable
    SciErr sciErr;

    ////////// Variables declaration //////////
    int m1 = 0, n1 = 0;
    int *piAddressVarOne = NULL;
    double *matrixOfDouble1 = NULL;
    double *newMatrixOfDouble = NULL;

    int m2 = 0, n2 = 0;
    int *piAddressVarTwo = NULL;
    double *matrixOfDouble2 = NULL;
    //int *newMatrixOfBoolean = NULL;
    int i = 0,j,k;


    ////////// Check the number of input and output arguments //////////
    /* --> [c, d] = foo(a, b) */
    /* check that we have only 2 input arguments */
    /* check that we have only 2 output argument */
    CheckInputArgument(pvApiCtx, 2, 2) ;
    CheckOutputArgument(pvApiCtx, 1, 1) ;


    ////////// Manage the first input argument (double) //////////
    /* get Address of inputs */
    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressVarOne);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }

    /* Check that the first input argument is a real matrix (and not complex) */
    if ( !isDoubleType(pvApiCtx, piAddressVarOne) ||  isVarComplex(pvApiCtx, piAddressVarOne) )
    {
        Scierror(999, _("%s: Wrong type for input argument #%d: A real matrix expected.\n"), fname, 1);
        return 0;
    }

    /* get matrix */
    sciErr = getMatrixOfDouble(pvApiCtx, piAddressVarOne, &m1, &n1, &matrixOfDouble1);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }

    ////////// Manage the second input argument (boolean) //////////

    /* get Address of inputs */
    sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddressVarTwo);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }

    if ( !isDoubleType(pvApiCtx, piAddressVarTwo) ||  isVarComplex(pvApiCtx, piAddressVarTwo)  )
    {
        Scierror(999, _("%s: Wrong type for input argument #%d: A real matrix expected.\n"), fname, 2);
        return 0;
    }

    /* get matrix */
    sciErr = getMatrixOfDouble(pvApiCtx, piAddressVarTwo, &m2, &n2, &matrixOfDouble2);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }

    ////////// Check the consistency of the two input arguments //////////

    if (n1!=m2)
    {
        Scierror(999, _("%s: Wrong size for input arguments: The no. of columns of first matrix should be equal to no. of rows of second matrix.\n"), fname, 1);
        return 0;
    }


    newMatrixOfDouble = (double*)malloc(sizeof(double) * m1 * n2);
    ////////// Application code //////////
    // Could be replaced by a call to a library

    for (i = 0; i < m1 ; i++)
    {
    	for(j=0;j<n2;j++){
    		newMatrixOfDouble[i+m1*j]=0.0;
    		for(k=0;k<n1;k++){
    			newMatrixOfDouble[i+m1*j]=newMatrixOfDouble[i+m1*j]+matrixOfDouble1[i+m1*k]*matrixOfDouble2[k+j*m2];
    			}
    	}
    }


    ////////// Create the output argument //////////

    /* Create the matrix as return of the function */
    sciErr = createMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 1, m1, n2, newMatrixOfDouble);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }

 

    ////////// Return the output argument to the Scilab engine //////////

    AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;

    ReturnArguments(pvApiCtx);

    return 0;
}
/* ==================================================================== */

