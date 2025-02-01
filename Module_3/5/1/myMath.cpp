float sum(float a, float b)
{ return a + b; }

float substr(float a, float b)
{ return a - b; }

float multiply(float a, float b)
{ return a * b; }

float divide(float a, float b)
{ return a / b; }

float pow(float a, float b)
{
    if (b == 0) {return 1;}
    else 
    {
        a *= pow(a, b - 1);
        return a;
    }
}

