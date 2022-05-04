#ifndef METHODS_FOR_HALFINTERVAL_H_INCLUDED
#define METHODS_FOR_HALFINTERVAL_H_INCLUDED

double functionValue(double num)
{
    double value;

    value = 0;
    /*value += (1/10000000)*pow(num,2);
    value -= (2/10000)*num;
    value -= 250000;
    */
    value += 5*sin(1/20*num);

    return value;
}

double searchRoot(double start, double end, double eps)
{
    double x;
    double tmp;

    while( (end-start) > 2*eps){

        x = (start+end)/2;
        tmp = functionValue(start)*functionValue(x);
        if( tmp < 0 ){
            end = x;
        }else
        {
            start = x;
        }

    }

    x = (start+end)/2;

    return x;
}


#endif // METHODS_FOR_HALFINTERVAL_H_INCLUDED
