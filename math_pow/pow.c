int pow(int num, int n)
{
    if (1 == n)
        return num;
    if (0 == n)
        return 1;
    if ( n % 2)
        return pow(num * num, n/2) * num;
    else
        return pow(num * num, n/2);
}