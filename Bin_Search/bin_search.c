int bin_search(int *a, int target, int first, int last)
{
    int mid = first + (last - first)/2;
    for (; first <= last; mid = first + (last - first)/2)
    {
        if (target == a[mid])
        {
            return mid;
        }
        else if (target < a[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return -1;
}